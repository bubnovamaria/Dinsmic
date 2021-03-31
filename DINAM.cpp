﻿// DINAM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "windows.h"



typedef int(group)(int);
typedef char(name)(char*);
typedef HINSTANCE hModule;

int main() /// /Мейн
{
	HINSTANCE dll = LoadLibrary(L"BUBNOVADLL.dll"); ///получаем указатель на DLL
	{
		group* Group;
		name* Name;

		Group = (group*)GetProcAddress(dll, "Group"); ///GetProcAddress извлекает адрес экспортируемой функции или переменной из заданной динамически подключаемой библиотеки (DLL).


		Name = (name*)GetProcAddress(dll, "Name");
		char* n = (char*)malloc(20);
		Name(n);
		int grr = 666;
		std::cout << "Group is " << Group(grr) << "\n";
		std::cout << "Name is " << n << "\n";
	}
	return 0;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
