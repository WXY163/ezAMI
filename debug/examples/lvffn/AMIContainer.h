#pragma once
#include "ffn.h"
#include <string>
#include <vector>
#include <fstream>
#include "amiInterface.h"

class AMIContainer
{
public:
	AMIContainer();
	~AMIContainer();
	//void loadFile(std::string fn);
	
	bool loadWeights(std::string weightDir, lvffn &weights);
	bool loadVj(std::string VjDir, double *vj, unsigned long limit);
	bool loadLgfilter(std::string lgfilterDir, double *lgfilter, unsigned long len);
	void inference(double *Vj, double *wave, unsigned long wave_size, double *lgfilter, double *preWave, lvffn weights);
	void inferWithVj(double *Vj, double *wave, unsigned long wave_size, unsigned long progress, lvffn weights);
	inline double forward(double *Vj, double *weight, double bias);
	void saveFile(std::string fn, std::string info);
	void saveWave(std::string fn, double *wave, unsigned long wave_size);
	void saveVj(std::string fn, double *Vj, double *wave, unsigned long wave_size, double *lgfilter, double *preWave);
	void inferbyrecur(double* vj0, double *wave, unsigned long wave_size, lvffn weights, double sqrtAlpha, double sqrt1mAlpha);
	void calculateNewVj(double wave, double *oldvj, double sqrtAlpha, double sqrt1mAlpha);
	inline double convolve(double* wave, double *filter, unsigned int len);

	std::string eMessage;
};

