#include <iostream>
#include <string>
#include "Polish.h"


void main()
{
	Polish test;

	string expression;
	while (true)
	{
		cout << "Write your expression: \n";
		getline(cin, expression);
	
		test.Initialize(expression.c_str());
		
		if (test.Calculate())
		{
			cout << test.GetResult() << endl;
		}
		else
			cout << test.GetErrorDetails() << endl;

		cout << "----------------------------------" << endl;
	}
	/*expression = "(8+2*5)/(1+3*2-4)";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;


	expression = "3.5+2*5";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(3+2)*5";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(3+4*(5-2)-1)/2";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(3+2)/5 + (3+4*(5-2)-1)/2";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "16.8 / ((3+2)/5 + (3+4*(5-2)-1)/2)";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(64/32)+78-(20/4)+(2*(11-6))+45+2/2";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(3+5)^2-60-2^3";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "((3+2)/5 + (3+4*(5-2)-1)/2)^0.5";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "(8 + 11 - 2";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "8 + 11 - 2)";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "8 % 11 - 2)";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;

	expression = "8 * 11. - 2)";
	test.Initialize(expression);
	cout << expression << endl;
	if (test.Calculate())
	{
		cout << test.GetRPNExpression() << endl;
		cout << test.GetResult() << endl;
	}
	else
		cout << test.GetErrorDetails() << endl;

	cout << "----------------------------------" << endl;*/
}