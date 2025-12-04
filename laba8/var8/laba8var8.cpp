// Лабораторная работа 8 вариант 8
// Чупов Максим ЭиН-2 1к.

#include <iostream>
#include <iomanip>
#include <cmath>

double Yx(double x)
{
	return 1.0 / (1.0 - x);
}

void print(double x, double eps)
{
	double yx = Yx(x);

	long long int iter = 1;	
	long long int k = 1;

	double sum = 1.0 / (1.0 + x);

	while(fabs(yx - sum) > eps)
	{
		k++;
		iter++;
		sum += pow(2, k-1) * pow(x, pow(2, k-1)-1) / (1.0 + pow(x, pow(2, k-1)));
	}

	std::cout   << std::setw(15) << x << "|" << std::setw(15) << yx << "|"
				<< std::setw(15) << sum << "|" << std::setw(5) << iter << "\n";
}

int main()
{
	double  a = -0.3,
			b = 0.4,
			h = 0.1,
			eps = 0.0001;

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