// firstAMI.cpp : Defines the exported functions for the DLL application.
//

#include "ami.h"
#include <string>
#include <fstream>
#include <sstream>
#include "ffn.h"
#include <algorithm>
#include <cstdlib>

#include "AMIContainer.h"
#include "amiInterface.h"
#define CONVOLVE
//#define RECURSION

AMI_SETUP(amiFFN);


long AMI_Init(double *impulse_matrix,
	long row_size,
	long aggressors,
	double sample_interval,
	double bit_time,
	char **AMI_parameters_in,
	char **AMI_parameters_out,
	void **AMI_memory_handle,
	char **msg) {

	AMIContainer* ffnCont = new AMIContainer;
	ffnCont->eMessage.append("I am New AMI!\n");

	amiFFN.sqrtAlpha = std::sqrt(0.9);
	amiFFN.sqrt1mAlpha = std::sqrt(0.1);
	amiFFN.vj = new double[480000];
	
	

	
	amiFFN.preWave = new double[300];
	for (int i = 0; i < 300; i++) {
		amiFFN.preWave[i] = 1e-7;
	}
	
	amiFFN.lgfilters = new double[150 * 10];
	

	amiFFN.weights.weight = new double[100];
	amiFFN.weights.bias = new double[10];
	amiFFN.weights.c = new double[10];

	/*
	std::string vjFn = "F:\\Research\\ibis-AMI\\SourceCode\\data\\vjC++.txt";
	
	if (ffnCont->loadVj(vjFn, amiFFN.vj,48000)) {
		ffnCont->eMessage += "load vj success!\n";
	}
	else {
		ffnCont->eMessage += "load vj failed! \n";
	}
	*/
#ifdef CONVOLVE
	std::string lgFn = "F:\\Research\\ibis-AMI\\SourceCode\\data\\lgfilters.txt";
	if (ffnCont->loadLgfilter(lgFn, amiFFN.lgfilters,150)) {
		ffnCont->eMessage += "load filter success!\n";
	} 
	else {
		ffnCont->eMessage += "load filter failed! \n";
	}
#endif
	
	std::string wtFn = "F:\\Research\\ibis-AMI\\SourceCode\\data\\weight.txt";

	if (ffnCont->loadWeights(wtFn,amiFFN.weights)) {
		ffnCont->eMessage += "load weights success!\n";
	}
	else {
		ffnCont->eMessage += "load weights failed! \n";
	}

	*msg = (char*)ffnCont->eMessage.c_str();
	
	return 1;
}


long AMI_GetWave(double *wave,
				long wave_size,
				long aggressors,
				double *clock_times,
				char **AMI_parameters_out,
				void *AMI_memory) {

	AMIContainer* ffnCont = (AMIContainer*)AMI_memory;
	//std::string vjFn = "F:\\Research\\ibis-AMI\\SourceCode\\data\\vjC++.txt";
	//std::string waveFn = "F:\\Research\\ibis-AMI\\SourceCode\\data\\wave_new.txt";
	//ffnCont->saveVj(vjFn, amiFFN.vj, wave, wave_size, amiFFN.lgfilters, amiFFN.preWave);
	//ffnCont->saveWave(waveFn, wave, wave_size);
#ifdef CONVOLVE
	ffnCont->inference(amiFFN.vj, wave, wave_size,amiFFN.lgfilters, amiFFN.preWave, amiFFN.weights);
	amiFFN.getWaveCount += wave_size;
#endif

	//ffnCont->inferWithVj(amiFFN.vj, wave, wave_size, amiFFN.getWaveCount, amiFFN.weights);
#ifdef RECURSION
	ffnCont->inferbyrecur(amiFFN.vj, wave, wave_size, amiFFN.weights,amiFFN.sqrtAlpha, amiFFN.sqrt1mAlpha);
#endif

	return 1;
}
long AMI_Close(void *AMI_memory) {
	
	AMIContainer* ffnCont = (AMIContainer*)AMI_memory;

	delete[] amiFFN.vj;
	delete[] amiFFN.preWave;
	delete[] amiFFN.lgfilters;
	delete[] amiFFN.weights.weight;
	delete[] amiFFN.weights.bias;
	delete[] amiFFN.weights.c;
 	delete ffnCont;
	return 1;
}