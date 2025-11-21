#include "Calculator.h"

Calculator::Calculator()
{
	std::cout << "My super duper awesome calculator";
}

Calculator::~Calculator()
{

}

void Calculator::Plus(float a, float b)
{
	std::cout << a + b;
}

void Calculator::Minus(float a, float b)
{
	std::cout << a - b;
}

void Calculator::Multiply(float a, float b)
{
	std::cout << a * b;
}

void Calculator::Divide(float a, float b)
{
	std::cout << a / b;
}

void Calculator::Modulus(int a, int b)
{
	std::cout << a % b;
}