// DLLExecutable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
__declspec(dllimport) double OneParameter(double input);

int main()
{
	double dResult = OneParameter(25);
	printf("The return from One Parameter is %f\n", dResult);
	return 0;
}

