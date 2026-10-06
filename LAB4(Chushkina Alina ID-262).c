#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// Прототипы функций
void task1(void);
void task2(void);
void task3(void);

int main(void)
{
	// Настройка кириллицы
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int choice;
	do {
		printf("\n=== ПРАКТИКУМ ПО СИ - РАБОТА 4 ===\n");
		printf("1. Задание 1 (Ввод/вывод разных типов)\n");
		printf("2. Задание 2 (Преобразование типов)\n");
		printf("3. Задание 3 (Работа с трехзначным числом)\n");
		printf("0. Выход\n");
		printf("Выберите задание: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		}
	} while (choice != 0);

	return 0;
}

// Задание 1. Ввод и вывод разных типов
void task1(void)
{
	printf("\n--- ЗАДАНИЕ 1 ---\n");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("Инициализированные значения: c='%c', i=%d, f=%f, d=%e\n", c, i, f, d);

	printf("\nВведите новый символ, целое, float и double через пробел: ");
	scanf(" %c %d %f %lf", &c, &i, &f, &d);
	printf("Вы ввели: '%c', %d, %f, %e\n", c, i, f, d);

	// Задача 1а: Целая и дробная часть float
	printf("\nЗадача 1а: Число %f\n", f);
	printf("Целая часть: %d\n", (int)f);
	printf("Дробная часть: %f\n", f - (int)f);

	// Задача 1б: Коды символа
	printf("\nЗадача 1б: Символ '%c'\n", c);
	printf("Десятичный код: %d, Шестнадцатеричный код: %x\n", c, c);

	// Задача 1в: 1/i
	printf("\nЗадача 1в: Результат 1/%d = %f\n", i, 1.0 / i);
}

// Задание 2. Неявное и явное преобразование типов
void task2(void)
{
	printf("\n--- ЗАДАНИЕ 2 ---\n");
	int a = 11, b = 3;
	int x; float y; double z;

	// Неявное преобразование
	x = a / b; // Целочисленное деление -> 3
	y = a / b; // Деление (3) преобразуется в float -> 3.0
	z = a / b; // Деление (3) преобразуется в double -> 3.0

	printf("Неявное (a=11, b=3):\nx = %d, y = %f, z = %lf\n", x, y, z);
	printf("Пояснение: Результат a/b - целое число 3, которое затем записывается в float/double.\n");

	// Явное преобразование
	printf("\nЯвное преобразование типов (casting):\n");
	printf("(float)a / b = %f\n", (float)a / b);
	printf("a / (float)b = %f\n", a / (float)b);
	printf("(float)(a / b) = %f\n", (float)(a / b));
}

// Задание 3. Трехзначное число N
void task3(void)
{
	printf("\n--- ЗАДАНИЕ 3 ---\n");
	int n;
	printf("Введите трехзначное число N: ");
	scanf("%d", &n);

	if (n < 100 || n > 999) {
		printf("Ошибка: число не трехзначное!\n");
		return;
	}

	int last = n % 10; // Последняя цифра
	int middle = (n / 10) % 10; // Средняя цифра
	int first = n / 100; // Первая цифра
	int sum = first + middle + last;
	int reversed = last * 100 + middle * 10 + first;

	printf("Результаты для числа %d:\n", n);
	printf("Последняя цифра: %d, первая: %d, сумма цифр: %d, наоборот: %d\n",
		last, first, sum, reversed);
}