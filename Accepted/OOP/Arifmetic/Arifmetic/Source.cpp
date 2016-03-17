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
	
}