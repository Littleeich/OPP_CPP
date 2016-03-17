#pragma once

template <class T>
class Mytemplstack
{
private:
	T* stack;
	int stack_size;
	int top;
	bool unique_items;
	void ResizeStack()
	{
		this->stack_size *= 2;

		T* new_stack = new T[this->stack_size];

		for (int i = 0; i < this->top; i++)
			new_stack[i] = stack[i];

		delete[] stack;
		stack = new_stack;
	}
	void ExceptionEmptyStack() const
	{
		if (IsEmpty())
			throw "Stack is empty";
	}
public:
	Mytemplstack(bool unique_items)
	{
		this->unique_items = unique_items;

		this->top = 0;
		this->stack_size = 10;
		this->stack = new T[this->stack_size];
	}
	Mytemplstack() : Mytemplstack(false){};
	Mytemplstack(Mytemplstack& other)
	{
		this->unique_items = other.HasUniqueItemsOnly();
		this->stack_size = other.GetSize();
		this->top = other.GetCount();
		this->stack = new T[this->stack_size];

		if (this->top)
		{
			auto temp = other.GetArray();

			for (int i = 0; i < this->top; i++)
				this->stack[i] = temp[i];

			delete[] temp;
		}
	}
	~Mytemplstack()
	{
		this->top = 0;
		delete[] this->stack;
		this->stack = nullptr;
	}
	bool IsEmpty() const { return (!top); };
	bool Push(T value)
	{
		if (unique_items && Contains(value))
			return false;

		if (top == stack_size)
			ResizeStack();

		stack[top++] = value;
	}
	void Clear() { this->top = 0; };
	T Pop()
	{
		ExceptionEmptyStack();
		return stack[--top];
	}
	int GetCount() const { return this->top; };
	int GetSize() const { return stack_size; };
	bool HasUniqueItemsOnly() { return unique_items; };
	T* GetArray() const
	{
		ExceptionEmptyStack();

		T* result = new T[this->top];

		for (int i = 0; i < this->top; i++)
			result[i] = this->stack[i];

		return result;
	}
	T Peek() const
	{
		ExceptionEmptyStack();
		return stack[top - 1];
	}
	bool Contains(T value) const
	{
		for (int i = 0; i < this->top; i++)
			if (this->stack[i] == value)
				return true;

		return false;
	}
};