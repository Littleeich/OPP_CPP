#include "Polish.h"

Polish::Polish()
{
	fInputExpression = new char[255];
	strcpy_s(fInputExpression, 1, "");
	fOutputExpression = new char[255];
	strcpy_s(fOutputExpression, 1, "");
	fErrorInfo = new char[255];
	strcpy_s(fErrorInfo, 1, "");
	fBuffer = new char[255];
	strcpy_s(fBuffer, 1, "");
	fResult = 0;

	fOperations = new char[fOperationsCount];
	fOperations[0] = '+';
	fOperations[1] = '-';
	fOperations[2] = '*';
	fOperations[3] = '/';
	fOperations[4] = '^';
}

Polish::Polish(const Polish& other)
{
	throw "In the current version copying of this object is not implemented";
}

Polish::~Polish()
{
	delete[] fInputExpression;
	delete[] fOutputExpression;
	delete[] fBuffer;
	delete[] fErrorInfo;
}

void Polish::Initialize(const char* InputExpression)
{
	strcpy_s(fInputExpression, strlen(InputExpression) + 1, InputExpression);
	strcpy_s(fOutputExpression, 1, "");
	strcpy_s(fErrorInfo, 1, "");
	strcpy_s(fBuffer, 1, "");
	fResult = 0;
}

bool Polish::CreateRPNExpression()
{
	if (!strlen(fInputExpression))
	{
		strcpy_s(fErrorInfo, 35, "Input expression is not specified");
		return false;
	}

	bool result = true, symbol_correct = false;
	char curr_char = '\0', operator_in_stack = '\0';
	int index = -1, digit_index = -1;
	char* digit_buffer = new char[255];
	Mytemplstack<char>* stack = new Mytemplstack<char>;

	while (true)
	{
		index++;
		symbol_correct = false;

		curr_char = fInputExpression[index];

		if (IsDigit(curr_char))
		{
			digit_index++;
			digit_buffer[digit_index] = curr_char;
			symbol_correct = true;
		}
		else if (curr_char == '.' && digit_index >= 0 && IsDigit(fInputExpression[index + 1]))
		{
			digit_index++;
			digit_buffer[digit_index] = curr_char;
			symbol_correct = true;
		}
		else
		{
			if (digit_index >= 0)
			{
				digit_buffer[digit_index + 1] = '\0';
				AddDigitArrayToOutputExpression(digit_buffer);
				AddCharToOutputExpression('|');
				digit_index = -1;
			}
		}

		if (IsOperator(curr_char))
		{
			if (!strlen(fOutputExpression))
			{
				strcpy_s(fErrorInfo, 64, "Invalid expression: opertor cannot be used as the first symbol");
				result = false;
				break;
			}

			symbol_correct = true;

			if (stack->IsEmpty())
			{
				stack->Push(curr_char);
			}
			else
			{
				while (!stack->IsEmpty())
				{
					operator_in_stack = stack->Peek();

					if (GetOperatorPriority(operator_in_stack) >= GetOperatorPriority(curr_char))
					{
						AddCharToOutputExpression(operator_in_stack);
						stack->Pop();
					}
					else
					{
						break;
					}
				}

				stack->Push(curr_char);
			}
		}//operator

		if (curr_char == '(')
		{
			stack->Push(curr_char);
			symbol_correct = true;
		}

		if (curr_char == ')')// )
		{
			symbol_correct = true;
			bool bracket_found = false;

			while (!stack->IsEmpty())
			{
				operator_in_stack = stack->Pop();

				if (operator_in_stack == '(')
				{
					bracket_found = true;
					break;
				}
				else
				{
					AddCharToOutputExpression(operator_in_stack);
				}
			}

			if (!bracket_found)
			{
				strcpy_s(fErrorInfo, 64, "Invalid expression: brackets mismatch");
				result = false;
				break;
			}

		}

		if (curr_char == ' ')
			symbol_correct = true;

		if (curr_char == '\0')
			break;

		if (!symbol_correct)
		{
			strcpy_s(fErrorInfo, 45, "Invalid expression: unknown symbol is found");
			result = false;
			break;
		}
	}

	if (result)
	{
		while (!stack->IsEmpty())
		{
			operator_in_stack = stack->Pop();

			if (operator_in_stack == '(')
			{
				strcpy_s(fErrorInfo, 64, "Invalid expression: brackets mismatch");
				result = false;
				break;
			}
			else
			{
				AddCharToOutputExpression(operator_in_stack);
			}
		}
	}

	if (!result)
		strcpy_s(fOutputExpression, 1, "");

	delete stack;
	return result;
}

void Polish::AddDigitArrayToOutputExpression(char*& digit_buffer)
{
	int out_length = strlen(fOutputExpression);

	if (!out_length)
		strcpy_s(fOutputExpression, strlen(digit_buffer) + 1, digit_buffer);
	else
		strcat_s(fOutputExpression, out_length + strlen(digit_buffer) + 1, digit_buffer);

}

char* Polish::GetErrorDetails() const
{
	strcpy_s(fBuffer, strlen(fErrorInfo) + 1, fErrorInfo);
	return fBuffer;
}

bool Polish::IsDigit(char symbol)
{
	if (symbol >= 48 && symbol <= 57)
		return true;
	else
		return false;
}

bool Polish::IsOperator(char symbol)
{
	for (int i = 0; i < fOperationsCount; i++)
		if (symbol == fOperations[i])
			return true;

	return false;
}

int Polish::GetOperatorPriority(char operator_symb)
{
	if (operator_symb == '(' || operator_symb == ')')
		return 0;
	else if (operator_symb == '+' || operator_symb == '-')
		return 1;
	else if (operator_symb == '*' || operator_symb == '/')
		return 2;
	else if (operator_symb == '^')
		return 3;
}

void Polish::AddCharToOutputExpression(char symbol)
{
	int out_length = strlen(fOutputExpression);

	fOutputExpression[out_length] = symbol;
	fOutputExpression[out_length + 1] = '\0';
}

bool Polish::Calculate()
{
	if (!strlen(fOutputExpression))
	{
		if (!CreateRPNExpression())
			return false;
	}

	bool result = true;
	char curr_char = '\0';
	int index = -1, digit_index = -1;
	char* digit_buffer = new char[255];
	Mytemplstack<double>* stack = new Mytemplstack<double>;
	double temp_digit = 0;

	while (true)
	{
		index++;

		curr_char = fOutputExpression[index];

		if (IsDigit(curr_char))//0-9
		{
			digit_index++;
			digit_buffer[digit_index] = curr_char;
		}
		else if (curr_char == '.' && digit_index >= 0 && IsDigit(fInputExpression[index + 1]))
		{
			digit_index++;
			digit_buffer[digit_index] = curr_char;
		}
		else
		{
			if (digit_index >= 0)
			{
				digit_buffer[digit_index + 1] = '\0';
				temp_digit = atof(digit_buffer);
				stack->Push(temp_digit);
				digit_index = -1;
			}
		}

		if (IsOperator(curr_char))
		{
			if (stack->IsEmpty() || (stack->GetCount() < 2))
			{
				strcpy_s(fErrorInfo, 21, "Digit stack is empty");
				result = false;
				break;
			}

			ExecuteOperator(*stack, curr_char);
		}

		if (curr_char == '\0')
			break;

	}

	if (stack->IsEmpty() || (stack->GetCount() > 1))
	{
		strcpy_s(fErrorInfo, 12, "Stack error");
		result = false;
	}
	else
	{
		fResult = stack->Pop();
	}

	delete stack;
	return result;
}

void Polish::ExecuteOperator(Mytemplstack<double>& stack, char operator_symb)
{
	double operand1 = 0, operand2 = 0, result;

	operand2 = stack.Pop();
	operand1 = stack.Pop();

	if (operator_symb == '^')
		result = pow(operand1, operand2);
	else if (operator_symb == '*')
		result = operand1 * operand2;
	else if (operator_symb == '/')
		result = operand1 / operand2;
	else if (operator_symb == '+')
		result = operand1 + operand2;
	else if (operator_symb == '-')
		result = operand1 - operand2;

	stack.Push(result);
}