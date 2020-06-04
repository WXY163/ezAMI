#pragma once

#include <string>
#include <math.h>
#define AMI_SETUP(name) amiInterface name
struct lvffn {
	
	double *weight;
	double *bias;
	double *c;
	double d;
};

class amiInterface {
public:
	long row_size;
	long aggressors;
	double sample_interval;
	double bit_time;
	std::string message;
	lvffn weights;
	double *vj;
	//double vj0[10] = {-1.377328559299052957, 7.117816040102557196, 0.9247131760760509689, -4.001331477034733020, 2.928001634280805732, 1.266368774612318671, -2.548300844219336447, -2.235008666379282083, -0.1624591334577942803, 0.4414237881121918505 };
	double *lgfilters;
	double *preWave;
	unsigned long getWaveCount = 0;

	double sqrtAlpha;
	double sqrt1mAlpha;

};
