//This is the ami interface file. 

#include "ami.h"

long AMI_Init(
	double *impulse_matrix,
	long row_size,
	long aggressors,
	double sample_interval,
	double bit_time,
	char **AMI_parameters_in,
	char **AMI_parameters_out,
	void **AMI_memory_handle,
	char **msg) 
{
	
	return 1;
}

/**********************************************/
long AMI_GetWave( 
	double *wave,
	long wave_size,
	long aggressors,
	double *clock_times,
	char **AMI_parameters_out,
	void *AMI_memory) 
{

	return 1;
	
}

/**********************************************/
long AMI_Close( void *AMI_memory ) 
{
	
	return 1;
}