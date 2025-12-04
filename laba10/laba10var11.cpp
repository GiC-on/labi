// Лабораторная работа 10 вариант 11
// Чупов Максим ЭиН-2 1к.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream file;
	file.open("data.txt");

	if(!file.is_open())
	{
		file.clear();
		file.open("data.txt", std::ios::out);
		file.close();
		file.open("data.txt");
	}

	for(int i = 1; i <= 20; i++)
	{
		std::string place;
		std::string time;
		int tickets;
		std::cout << "Enter " << i <<" train data:\n";
		std::getline(std::cin, place);
		std::getline(std::cin, time);
		std::cin >> tickets;
		file << i << '|' << place << '|' << time << '|' << tickets << '\n';
	}

	file.close();

	return 0;
}