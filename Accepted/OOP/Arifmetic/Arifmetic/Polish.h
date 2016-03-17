#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

//Operation priority table
//	+-	:: 1
//	*/	:: 2
//	^	:: 3


class Polish
{
	char* fInputExpression;
	char* fOutputExpression;
	char* fErrorInfo;
	char* fBuffer;
	char* fOperations;
	double fResult;
	int fOperationsCount = 5;
	int GetOperatorPriority(char);
	bool IsDigit(char);
	bool IsOperator(char);
	void AddDigitArrayToOutputExpression(char*&);
	void AddCharToOutputExpression(char);
	void ExecuteOperator(Mytemplstack<double>&, char);
public:
	Polish();
	~Polish();
	Polish(const Polish& other);
	void Initialize(const char* InputExpression);
	bool CreateRPNExpression();//Returns true if conversion is successful, otherwise false.
	char* GetRPNExpression() const;
	char* GetErrorDetails() const;
	bool Calculate(); //Returns true if conversion is successful, otherwise false.
	double GetResult(){ return fResult; };
};
