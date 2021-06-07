// Laba2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Students
{
	string FIO;
	int GroupNumber;
	int NumberInGroup;
	string Sex;
	int ratings[8];
	string FormEducation;
	string Date;
};

void List(vector<Students> assistant, int n, int i)
{
	setlocale(LC_ALL, "Russian");
	cout << "ФИО:" << assistant[i].FIO << "\n";
	cout << "Номер группы:" << assistant[i].GroupNumber << "\n";
	cout << "Номер в группе:" << assistant[i].NumberInGroup << "\n";
	cout << "Пол:" << assistant[i].Sex << "\n";
	cout << "Форма обучения:" << assistant[i].FormEducation << "\n";
	cout << "Оценки:";
	for (int j = 0; j < 8; j++) //ограничение количества оценок по условию
		cout << assistant[i].ratings[j] << " ";
	cout << "\n";
	cout << "Дата и время записи:" << assistant[i].Date << "\n\n";

}

void AllStudents(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int stud;
	cout << "Список всех студентов:\n\n";
	for (int i = 0; i < n; i++)
	{
		stud = i + 1;
		cout << "Студент " << stud << "\n\n";
		cout << "ФИО:" << assistant[i].FIO << "\n";
		cout << "Номер группы:" << assistant[i].GroupNumber << "\n";
		cout << "Номер в группе:" << assistant[i].NumberInGroup << "\n";
		cout << "Пол:" << assistant[i].Sex << "\n";
		cout << "Форма обучения:" << assistant[i].FormEducation << "\n";
		cout << "Оценки:";
		for (int j = 0; j < 8; j++)
			cout << assistant[i].ratings[j] << " ";
		cout << "\n";
		cout << "Дата и время записи:" << assistant[i].Date << "\n\n";
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}

void AddStudent(vector<Students>& assistant, int& n)
{
	setlocale(LC_ALL, "Russian");
	n++;
	assistant.resize(n);
	int i = n - 1;
	ofstream  add;
	add.open("students.txt", fstream::app);
	if (!add.is_open())
	{
		cout << "\nОшибка открытия файла";
	}
	else { //запись данных в структуру

		cout << "Введите фамилию, имя и отчество: ";
		cin.ignore();
		getline(cin, assistant[i].FIO);
		add << assistant[i].FIO << "\n";
		cout << "Введите номер группы: ";
		cin >> assistant[i].GroupNumber;
		add << assistant[i].GroupNumber << "\n";
		cout << "Введите номер в группе: ";
		cin >> assistant[i].NumberInGroup;
		add << assistant[i].NumberInGroup << "\n";
		cout << "Введите пол человека: ";
		cin.ignore();
		getline(cin, assistant[i].Sex);
		add << assistant[i].Sex << "\n";
		cout << "Введите форму обучения: ";
		getline(cin, assistant[i].FormEducation);
		add << assistant[i].FormEducation << "\n";
		for (int j = 0; j < 8; j++)
		{
			cout << "Введите оценки: ";
			cin >> assistant[i].ratings[j];
		}
		for (int j = 0; j < 8; j++)
			add << assistant[i].ratings[j] << " ";
		add << "\n";
		cout << "Введите дату и время записи: ";
		cin.ignore();
		getline(cin, assistant[i].Date);
		add << assistant[i].Date << "\n";

	}
	add.close();
	system("pause");
	system("cls");
}

void NewEntry(vector<Students>& assistant, int& n)

{
	setlocale(LC_ALL, "Russian");
	ofstream input;
	input.open("students.txt");
	if (!input.is_open())
	{
		cout << "\nОшибка открытия файла";
	}
	else {

		for (int i = 0; i < n; i++)
		{
			input << assistant[i].FIO << "\n";
			input << assistant[i].GroupNumber << "\n";
			input << assistant[i].NumberInGroup << "\n";
			input << assistant[i].Sex << "\n";
			input << assistant[i].FormEducation << "\n";
			for (int j = 0; j < 8; j++)
				input << assistant[i].ratings[j] << " ";
			input << "\n";
			input << assistant[i].Date << "\n";
		}
	}
	input.close();
}

void ChangingData(vector<Students>& assistant, int& n)
{
	setlocale(LC_ALL, "Russian");
	int i, shift;
	cout << "Введите номер студента от 1 до " << n << "\n";
	cout << "Вы ввели: ";
	cin >> i;
	i--;
	cout << "\nЧто нужно изменить\n\n";
	cout << "1 - фамилия, имя и отчество\n";
	cout << "2 - номер группы\n";
	cout << "3 - номер в группе\n";
	cout << "4 - пол\n";
	cout << "5 - форма обучения\n";
	cout << "6 - оценки\n";
	cout << "7 - дата и время записи\n";
	cout << "\nВы ввели: ";
	cin >> shift;
	cout << "\n";
	switch (shift)
	{
	case 1:
		cout << "Введите фамилию, имя и отчество: ";
		cin.ignore();
		getline(cin, assistant[i].FIO);
		break;
	case 2:
		cout << "Введите номер группы: ";
		cin >> assistant[i].GroupNumber;
		break;
	case 3:
		cout << "Введите номер в группе: ";
		cin >> assistant[i].NumberInGroup;
		break;
	case 4:
		cout << "Введите пол человека: ";
		cin.ignore();
		getline(cin, assistant[i].Sex);
		break;
	case 5:
		cout << "Введите форму обучения: ";
		cin.ignore();
		getline(cin, assistant[i].FormEducation);
		break;
	case 6:
		for (int j = 0; j < 8; j++)
		{
			cout << "Введите рейтинг: ";
			cin >> assistant[i].ratings[j];
		}
		break;
	case 7:
		cout << "Введите дату и время записи: ";
		cin.ignore();
		getline(cin, assistant[i].Date);
		break;
	}
	NewEntry(assistant, n);
	system("pause");
	system("cls");
}

void StudentsOfGroupN(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int entered, control = 0;
	cout << "Введите номер группы";
	cout << "\nВы ввели: ";
	cin >> entered; cout << "\n";
	for (int i = 0; i < n; i++)
	{
		if (assistant[i].GroupNumber == entered)
		{
			List(assistant, n, i);
			control = 1;
		}

	}
	if (control == 0)
		cout << "Такой группы нет";
	system("pause");
	system("cls");
}

void rating(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	double* rating = new double[n];
	double first = 0, second = 0, third = 0, dub = 0.0;
	int top1 = 0, top2 = 0, top3 = 0;
	for (int i = 0; i < n; i++) { //average grade
		for (int j = 0; j < 8; j++)
			dub += assistant[i].ratings[j];
		dub /= 8;
		rating[i] = dub;
		dub = 0;
	}
	for (int i = 0; i < n; i++) //top 1
	{
		if (rating[i] > first)
		{
			first = rating[i]; top1 = i;
		}
	}
	for (int i = 0; i < n; i++) //top 2
	{
		if (rating[i] > second && assistant[i].FIO != assistant[top1].FIO)
		{
			second = rating[i]; top2 = i;
		}
	}
	for (int i = 0; i < n; i++) //top 3
	{
		if (rating[i] > third && assistant[i].FIO != assistant[top1].FIO && assistant[i].FIO != assistant[top2].FIO)
		{
			third = rating[i]; top3 = i;
		}
	}
	cout << "Топ-1: " << first << "\n\n";
	List(assistant, n, top1);
	cout << "\n\nТоп-2: " << second << "\n\n";
	List(assistant, n, top2);
	cout << "\n\nТоп-3: " << third << "\n\n";
	List(assistant, n, top3);
	delete[] rating;
	system("pause");
	system("cls");
}

void QuantityMF(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int men = 0, women = 0;
	for (int i = 0; i < n; i++)
	{
		if (assistant[i].Sex == "F") women++;
		if (assistant[i].Sex == "M") men++;

	}
	cout << "\nКоличество женщин: " << women << "\n\n";
	cout << "Количество мужчин: " << men;
	cout << "\n\n\n";
	system("pause");
	system("cls");
}

void Scholarship(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int bb = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
			if (assistant[i].ratings[j] == 3 || assistant[i].ratings[j] == 2)
				bb = 1;
		if (assistant[i].FormEducation == "day" && bb == 0)
			sum++;
		bb = 0;
	}
	cout << "\n\nКоличество студентов со стипендией: " << sum << "\n\n\n";
	system("pause");
	system("cls");
}

void Task8(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int control = 0;
	cout << "Студенты, которые не получают стипендию:\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
			if (assistant[i].ratings[j] == 3 || assistant[i].ratings[j] == 2)
				control = 1;

		if (assistant[i].FormEducation == "evening" || control == 1)
		{
			List(assistant, n, i);
		}

		control = 0;
	}
	system("pause"); system("cls");
	cout << "Студенты с оценками 5 и 4:\n\n";
	int fives = 0, fours = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (assistant[i].ratings[j] == 2) control = 1;
			if (assistant[i].ratings[j] == 3) control = 1;
			if (assistant[i].ratings[j] == 5) fives++;
			if (assistant[i].ratings[j] == 4) fours++;
		}
		if (control == 0 && fives < 8 && fours > 0)
		{
			List(assistant, n, i);
		}
		fives = 0;
		control = 0;
	}
	system("pause"); system("cls");
	cout << "Отличники:\n\n";
	int excellent = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
			if (assistant[i].ratings[j] == 5) excellent++;

		if (excellent == 8)
		{
			List(assistant, n, i);
		}
		excellent = 0;
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}

void StudentsUnderNumberN(vector<Students> assistant, int n)
{
	setlocale(LC_ALL, "Russian");
	int number, control = 0;
	cout << "Введите номер студента в группе:";
	cin >> number; cout << "\n";
	for (int i = 0; i < n; i++)
	{
		if (assistant[i].NumberInGroup == number)
		{
			List(assistant, n, i);
			control = 1;
		}

	}

	if (control == 0) cout << "Такого номера нет";
	cout << "\n\n";
	system("pause");
	system("cls");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file;
	file.open("students.txt");
	int n = 0, menu_choice;
	while (!file.eof())
	{
		if (file.get() == '\n')
			n++;
	}
	n = n / 7;// количество студентов
	file.close();
	cout << "Количество студентов в списке: " << n << "\n\n";
	vector<Students>assistant(n);
	ifstream file2;
	file2.open("students.txt");
	if (!file2.is_open())
	{
		cout << "\nОшибка открытия файла";
	}
	else {

		for (int i = 0; i < n; i++)
		{
			getline(file2, assistant[i].FIO);
			file2 >> assistant[i].GroupNumber; file2.ignore();
			file2 >> assistant[i].NumberInGroup; file2.ignore();
			getline(file2, assistant[i].Sex);
			getline(file2, assistant[i].FormEducation);
			for (int j = 0; j < 8; j++)
			{
				file2 >> assistant[i].ratings[j];
			}
			file2.ignore(2);
			getline(file2, assistant[i].Date);

		}
	}
	file2.close();

	do
	{
		cout << "Введите цифру 0-9 для выбора задачи.\n\n";
		cout << "1)   Создание новой записи о студенте\n";
		cout << "2)   Внесение изменений в уже существующую запись\n";
		cout << "3)  Вывод всех данных о студентах\n";
		cout << "4)  Вывод информации обо всех студентах группы N\n";
		cout << "5)  Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию\n";
		cout << "6)  Вывод количества студентов мужского и женского пола\n";
		cout << "7)  Определение количества студентов, которые будут получать стипендию\n";
		cout << "8)  Вывод данных о студентах, которые: не получают стипендию, учатся только на хорошо и отлично, учатся только на отлично\n";
		cout << "9)  Вывод данных о студентах, имеющих номер в списке – k\n";
		cout << "0)  Выход\n\n";
		cout << "Задача: ";
		cin >> menu_choice;
		system("cls");
		switch (menu_choice)
		{
		case 1:
			AddStudent(assistant, n);
			break;

		case 2:
			ChangingData(assistant, n);
			break;

		case 3:
			AllStudents(assistant, n);
			break;

		case 4:
			StudentsOfGroupN(assistant, n);
			break;

		case 5:
			rating(assistant, n);
			break;

		case 6:
			QuantityMF(assistant, n);
			break;

		case 7:
			Scholarship(assistant, n);
			break;

		case 8:
			Task8(assistant, n);
			break;

		case 9:
			StudentsUnderNumberN(assistant, n);
			break;

		case 0:

			break;
		}

	} while (menu_choice != 0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
