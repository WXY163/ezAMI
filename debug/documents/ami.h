#pragma once
#ifndef AMI_H
#define AMI_H
#define AMI_MODEL_EXPORT __declspec(dllexport)



extern "C" AMI_MODEL_EXPORT long AMI_Init(double *impulse_matrix,
											long row_size,
											long aggressors,
											double sample_interval,
											double bit_time,
											char **AMI_parameters_in,
											char **AMI_parameters_out,
											void **AMI_memory_handle,
											char **msg);

extern "C" AMI_MODEL_EXPORT long AMI_GetWave(double *wave,
											long wave_size,
											long aggressors,
											double *clock_times,
											char **AMI_parameters_out,
											void *AMI_memory);

extern "C" AMI_MODEL_EXPORT long AMI_Close(	void *AMI_memory);


#endif