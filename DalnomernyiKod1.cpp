// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define CA_SEQ_LEN (511)
#define N_DWRD_SBF (10)



int main() {
	int HC1[10] = { -1, -1, 1, 1, -1, -1, 1, -1, -1, -1};
	int HC20[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int g1[1023] = { 0 };
	int g2[1023] = { 0 };
	int SaveBit;
	int result[1023];
	for (int i = 0; i <= 1022; i++)
	{
		g1[0] = HC1[9];
		SaveBit = HC1[2] * HC1[6] * HC1[8] * HC1[9];
		HC1[1] = HC1[0];
		HC1[9] = HC1[8];
		HC1[0] = SaveBit;

	}
	for (int i = 0; i <= 1022; i++)
	{
		g2[i] = HC20[9];
		SaveBit = HC20[6] * HC20[9];
		HC20[1] = HC20[0];
		HC20[9] = HC20[8];
		HC20[0] = SaveBit;

	}
	for (int i = 0; i < 1022;i++)
	{
		result[i] = g1[i] * g2[i];
	}
	std::cout << result;
	return 0;
}
