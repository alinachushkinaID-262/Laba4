#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Объявление функции (прототип)
int is_siren_on(int A, int B);

int main(void)
{
	int A, B;
	int alarm;

	printf("Enter sensor values A and B: ");
	scanf("%d %d", &A, &B);

	// Вызов функции проверки сирены
	alarm = is_siren_on(A, B);

	printf("Siren status = %d\n", alarm);

	return 0;
}

// Реализация функции
int is_siren_on(int A, int B)
{
	// Сирена включается (возвращает 1), если ровно одна лампа нечетная:
	// (A - нечетное И B - четное) ИЛИ (A - четное И B - нечетное)
	int condition = ((A % 2 != 0) && (B % 2 == 0)) ||
		((A % 2 == 0) && (B % 2 != 0));

	return condition;
}