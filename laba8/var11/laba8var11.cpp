// Лабораторная работа 8 вариант 11
// Чупов Максим ЭиН-2 1к.

#include <iostream>
#include <iomanip>
#include <cmath>

double Yx(double x)
{
	return (2.0 * x * sin(x) - 2.0 + cos(x)) / 4.0;
}

void print(double x, double eps)
{
	double yx = Yx(x);

	long long int iter = 1;	
	long long int k = 2;

	double sum = cos(2.0 * x) / 3.0;

	while(fabs(yx - sum) > eps)
	{
		sum += pow(-1, k) * cos(k * x) / (pow(k, 2) - 1);
		k++;
		iter++;
	}

	std::cout   << std::setw(15) << x << "|" << std::setw(15) << yx << "|"
				<< std::setw(15) << sum << "|" << std::setw(5) << iter << "\n";
}

int main()
{
	double  a = -1.0,
			b = 1.3,
			h = 0.1,
			eps = 0.00001;

	std::cout   << "from: " << a << " to: " << b << " step: " << h
				<< " accuracy: " << eps << "\n";
	std::cout   << std::setw(16) << "x     |" << std::setw(16) << "Y(x)     |"
				<< std::setw(16) << "S(x)     |" << std::setw(6) << " iter"
				<< "\n-----------------------------------------------------\n";

	for(double x = a; x < b+eps; x += h)
	{
		print(x, eps);
	}

	return 0;
}