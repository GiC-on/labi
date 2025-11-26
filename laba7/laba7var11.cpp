// Лабораторная работа 7 вариант 11
// Чупов Максим ЭиН-2 1к.

/*
TO-DO LIST
 - check if FIOs aren't getting put to the char fio array
 - fix that program crashes after entering first student's FIO
 - make all other parts of the code 
*/

#include <iostream>

struct student
{
	char fio[40];
	char adress[15];
	int scores[3];
};


int main()
{
	std::setlocale(LC_ALL, "ru");

	int studCount;

	std::cout << "Enter students count: ";
	std::cin >> studCount;

	student* studs = new student[studCount];
	
	for(int i = 0; i < studCount; i++)
	{
		
		std::cout << "\nEnter " << i+1 << " student's FIO: ";
		std::cin >> studs[i].fio;

		std::cout << "Enter his/her adress: ";
		std::cin >> studs[i].adress;

		std::cout << "Enter his/her scores for 3 exams: ";
		std::cin >> studs[i].scores[0] >> studs[i].scores[1] >> studs[i].scores[2];
	}

	return 0;
}