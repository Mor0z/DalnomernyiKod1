// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define CA_SEQ_LEN (511)
#define N_DWRD_SBF (10)

void codegen(int* ca, int prn);

int main() {
	int* ca = new int[CA_SEQ_LEN];
	codegen(ca, 12);
	free(ca);
}

void codegen(int* ca, int prn)
{
	int delay[] = {
		  5,   6,   7,   8,  17,  18, 139, 140, 141, 251,
		252, 254, 255, 256, 257, 258, 469, 470, 471, 472,
		473, 474, 509, 512, 513, 514, 515, 516, 859, 860,
		861, 862 };

	int g1[CA_SEQ_LEN], g2[CA_SEQ_LEN];
	int r1[N_DWRD_SBF], r2[N_DWRD_SBF];
	int c1, c2;
	int i, j;

	if (prn < 1 || prn>32)
		return;

	for (i = 0; i < N_DWRD_SBF; i++)
		r1[i] = r2[i] = -1;

	for (i = 0; i < CA_SEQ_LEN; i++)
	{
		g1[i] = r1[9];
		g2[i] = r2[9];
		c1 = r1[6] * r1[9];
		c2 = r2[2] * r2[6] * r2[8] * r2[9];

		for (j = 9; j > 0; j--)
		{
			r1[j] = r1[j - 1];
			r2[j] = r2[j - 1];
		}
		r1[0] = c1;
		r2[0] = c2;
	}

	for (i = 0, j = CA_SEQ_LEN - delay[prn - 1]; i < CA_SEQ_LEN; i++, j++)
		ca[i] = (1 - g1[i] * g2[j % CA_SEQ_LEN]) / 2;

	return;
}