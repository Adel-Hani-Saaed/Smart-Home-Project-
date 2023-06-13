/*
 * Mapping_program.c
 *
 *  Created on: Mar 13, 2023
 *      Author: A-plus store
 */


#include "STD_TYPES.h"
#include "Mapping_interface.h"

s32 MAPPING_s32GetOutput (s32 Copy_s32InputMin ,s32 Copy_s32InputMax ,s32 Copy_s32OutputMin ,s32 Copy_s32OutputMax ,s32 Copy_s32InputValue )
{
	// Calculate the input range and output range spans
	s32 input_span = Copy_s32InputMax - Copy_s32InputMin;
	s32 output_span = Copy_s32OutputMax - Copy_s32OutputMin;

	// Calculate the input value's distance from the minimum input value
	s32 input_distance = Copy_s32InputValue - Copy_s32InputMin;

	// Calculate the proportion of the input range span that the input value represents
	f32 input_proportion = (f32)input_distance / (f32)input_span;

	// Calculate the output value by scaling the proportion to the output range span
	s32 output_value = Copy_s32OutputMin + (s32)(input_proportion * output_span);

	// Return the mapped output value
	return output_value;

}
