
#include "AMIContainer.h"


AMIContainer::AMIContainer()
{

	//getWaveCounter = 1;

}


AMIContainer::~AMIContainer()
{
	
}

void AMIContainer::saveFile(std::string fn, std::string info)
{
	std::ofstream waveFile;
	waveFile.open(fn, std::ios::app);
	if (waveFile.is_open())
	{
		waveFile << info << std::endl;

		waveFile.close();
	}
}

void AMIContainer::saveWave(std::string fn, double *wave, unsigned long wave_size)
{
	std::ofstream waveFile;
	waveFile.open(fn, std::ios::out | std::ios::app);
	if (waveFile.is_open())
	{
		for (unsigned int i = 0; i < wave_size; i++)
		{
			waveFile << std::to_string(wave[i]) << std::endl;
		}
		waveFile.close();
	}
}





bool AMIContainer::loadWeights(std::string weightDir, lvffn &weights) {
	std::ifstream inFile(weightDir);
	std::string temp;
	if (inFile.is_open())
	{
		std::string line;
		unsigned int row = 0;
		while (std::getline(inFile, line))
		{
			std::istringstream iss(line);
			unsigned int col = 0;
			if (row == 11)
			{
				while (iss >> temp)
				{
					weights.c[col] = std::stod(temp);
					col++;
					if (col == 10)
					{
						break;
					}
				}
				row++;
			}
			else if (row == 10)
			{
				while (iss >> temp)
				{
					weights.bias[col] = std::stod(temp);
					col++;
					if (col == 10)
					{
						break;
					}
				}
				row++;
			}
			else if (row == 12)
				break;
			else
			{
				while (iss >> temp)
				{
					weights.weight[row * 10 + col] = std::stod(temp);
					col++;
					if (col == 10)
					{
						break;
					}
				}
				row++;
			}
		}
		weights.d = 0.01421397;
		inFile.close();
		return true;
	}
	else {
		return false;
	}

}

bool AMIContainer::loadVj(std::string VjDir, double *vj, unsigned long limit) {
	std::ifstream inFile(VjDir);
	std::string temp;
	if (inFile.is_open())
	{
		std::string line;
		unsigned long row = 0; //total samples
		while (std::getline(inFile, line)) {
			std::istringstream iss(line);
			unsigned int col = 0;
			while (iss >> temp){
				vj[row*10 + col] = std::stod(temp);
				col++;
				if (col == 10) { // 10 is the number of funcations
					break;
				}
			}
			row++;
			if (row == limit) {
				break;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool AMIContainer::loadLgfilter(std::string lgfilterDir, double *lgfilter, unsigned long len) {
	std::ifstream inFile(lgfilterDir);
	std::string temp;
	if (inFile.is_open())
	{
		std::string line;
		unsigned long row = 0; //total samples
		while (std::getline(inFile, line)) {
			std::istringstream iss(line);
			unsigned int col = 0;
			while (iss >> temp) {
				lgfilter[row*len + col] = std::stod(temp);
				col++;
				if (col == len) { 
					break;
				}
			}
			row++;
			if (row == 10) {
				break;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void AMIContainer::inference(double *Vj, double *wave, unsigned long wave_size, double *lgfilter, double *preWave, lvffn weights) {
	double hlayer[10];
	std::memcpy(preWave + 150, wave, 150 * sizeof(double));
	
	for (unsigned long sampleN = 0; sampleN < wave_size; sampleN++)
	{
		for (int i = 0; i < 10; i++) {
			if (sampleN < 150) {
				Vj[sampleN * 10 +i] = convolve(preWave + sampleN, lgfilter + i * 150, 150);
			}
			else {
				Vj[sampleN * 10 + i] = convolve(wave + sampleN - 150, lgfilter + i * 150, 150);
			}

		}
	}
	std::memcpy(preWave, wave + wave_size - 150, 150 * sizeof(double));

	for (unsigned long sample = 0; sample < wave_size; sample++){
		double out = 0.0;
		for (unsigned int i = 0; i < 10; i++)
		{
			//unsigned long fetchVj = sampleN + progress;
			hlayer[i] = std::pow(forward(Vj+sample*10, weights.weight + i * 10, weights.bias[i]), 3.0);
			out += hlayer[i] * weights.c[i];
		}
		out += weights.d;
		wave[sample] = out;
	}

}
	
void AMIContainer::inferWithVj(double *Vj, double *wave, unsigned long wave_size, unsigned long progress, lvffn weights) {
	double hlayer[10];
	for (unsigned long sampleN = 0; sampleN < wave_size; sampleN++)
	{

	
			double out = 0.0;
			for (unsigned int i = 0; i < 10; i++)
			{
				unsigned long fetchVj = sampleN + progress;
				hlayer[i] = std::pow(forward(Vj + fetchVj*10, weights.weight + i * 10, weights.bias[i]), 3.0);
				out += hlayer[i] * weights.c[i];
			}
			out += weights.d;
			wave[sampleN] = out;

	}

}
inline double AMIContainer::forward(double *Vj, double *weight, double bias) {
	double sum = 0.0;

	for (unsigned int i = 0; i < 10; i++) {
		sum += Vj[i] * weight[i];
	}
	return sum + bias;
}

void AMIContainer::inferbyrecur(double* vj, double *wave, unsigned long wave_size, lvffn weights, double sqrtAlpha, double sqrt1mAlpha) {

		double hlayer[10];
		for (unsigned long sampleN = 0; sampleN < wave_size; sampleN++)
		{
			//calculate new vj
			calculateNewVj(wave[sampleN], vj, sqrtAlpha, sqrt1mAlpha);
			double out = 0.0;
			for (unsigned int i = 0; i < 10; i++)
			{
				hlayer[i] = std::pow(forward(vj, weights.weight + i * 10, weights.bias[i]), 3.0);
				out += hlayer[i] * weights.c[i];
			}
			out += weights.d;
			wave[sampleN] = out;
		}
}

void AMIContainer::calculateNewVj(double wave, double *oldVj, double sqrtAlpha , double sqrt1mAlpha) {
	double vj[10];
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			vj[i] = sqrtAlpha * oldVj[0] + sqrt1mAlpha * wave;
		}
		else {
			vj[i] = sqrtAlpha * (oldVj[i] + vj[i - 1]) - oldVj[i - 1];
		}
	std::memcpy(oldVj, vj, 10 * sizeof(double));
	}
}

inline double AMIContainer::convolve(double *wave, double *filter, unsigned int len) {
	double sum = 1e-6;
	for (unsigned int i = 0; i < len; i++) {
		sum += wave[i] * filter[i];
	}
	return sum;
}

void AMIContainer::saveVj(std::string fn, double *Vj, double *wave, unsigned long wave_size, double *lgfilter, double *preWave) {
	std::memcpy(preWave + 150, wave, 150 * sizeof(double));
	for (unsigned long sampleN = 0; sampleN < wave_size; sampleN++)
	{
		std::string vj = "";
		if (sampleN < 150) {
			for (int i = 0; i < 10; i++) {
				Vj[i] = convolve(preWave + sampleN, lgfilter + i * 150, 150);
				vj += std::to_string(Vj[i]);
				vj += " ";
			}

		}
		else {
			for (int i = 0; i < 10; i++) {
				Vj[i] = convolve(wave + sampleN - 150, lgfilter + i * 150, 150);
				vj += std::to_string(Vj[i]);
				vj += " ";
			}
		}
		saveFile(fn, vj);
		
	}
	std::memcpy(preWave, wave + wave_size - 150, 150 * sizeof(double));
}