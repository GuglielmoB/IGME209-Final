// DLLProject.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"

__declspec(dllexport) double OneParameter(double input);

double OneParameter(double input) {
	printf("OneParamater said - You sent me %f\n", input);
	return input * 4.0;
}
