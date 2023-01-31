#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include"tools.h"

using namespace std;
void Tool::CreateExpression(int a[], int s) {
	//auto
	string str = "";
	for (int i = s - 1; i > -1; i--)
	{

		if (a[i] != 0)
		{
			if (a[i] > 0 && str != "") {
				str += "+";
			}
			str += to_string(a[i]);
			if (0 != i) {
				str += "x";
				if (1 != i) {
					str += "^" + to_string(i);
				}
			}
		}
	}
	std::cout << str << endl;
}

int Tool::CalculateExpression(int a[], int x) {
	int ret1 = 0;
	int ret2 = 0;
	for (int i = MAX - 1; i >= 0; i--)
	{

		if (a[i] != 0 && i != 0)
		{

			ret1 += a[i] * (int)pow(x, i);

		}

	}

	ret2 = ret1 + a[0];

	return ret2;
}



bool Tool::outPut2File(string out_put) {
	ofstream ofs;
	ofs.open("output.txt", ios::out | ios::app);
	if (!ofs.is_open()) {
		return false;
	}
	ofs << out_put << endl;
	ofs.close();
	return true;
}

bool Tool::outPutE2File(string out_put) {
	ofstream ofs;
	ofs.open("expression.txt", ios::out | ios::app);
	ofs << out_put << endl;
	ofs.close();
	return true;
}


void Tool::stringTOnum(string s, int* data)
{
	bool temp = false;
	int pdata = 0;
	int ndata = 0;
	int m = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while ((s[i] >= '0') && (s[i] <= '9') || (s[i] == '-'))
		{
			temp = true;
			if (s[i] == '-')
			{
				i++;
				while ((s[i] >= '0') && (s[i] <= '9'))
				{
					ndata *= 10;
					ndata += -1 * (s[i] - '0');
					i++;
				}

			}
			else {
				pdata *= 10;
				pdata += (s[i] - '0');
				i++;

			}

		}

		if (temp)
		{
			data[m] = pdata + ndata;
			m++;
			pdata = 0;
			ndata = 0;
			temp = false;
		}
	}
}

int Tool::CalculatePower(int num1, int num2) {
	if (num1 < num2)
	{
		return 0;
	}

	if (num1 % num2 !=0)
	{
		return 0;
	}

	for (int i = 1;;i++)
	{
		num1 /= num2;
		if (num1==1)
		{
			return i;
		}
	}
}

//void Tool::FindOut(int data[], int num, int coef[], int index) {
//	auto cnt = 0;
//	int test[MAX]{data[0]};
//	if (data[0] != 0) {
//		cnt++;
//	}
//	vector<int[]> pool;
//	findOut(pool, num, data,  coef, test, 1, 1);
//}
//
//void Tool::findOut(vector<int[]> pools, int num, int data[], int coef[], int test[], int index, int cnt) {
//	if (index == MAX - 1) {
//		pools.push_back();
//		return;
//	}
//	for (int a = -9; a < 9; a++) {
//
//	}
//}
//
//bool test(int output[], int coef[]) {
//	for (int i = 0; i < )
//}