#pragma once
#include <string>
#include<vector>
using namespace std;

class Tool
{
public:
	const enum {
		MAX = 5,
		SIZE = 21,
		X = 2
	};

	void CreateExpression(int a[], int s);
	int CalculateExpression(int a[], int x);
	bool outPut2File(string out_put);
	void stringTOnum(string s, int* data);
	int CalculatePower(int num1, int num2);
	bool outPutE2File(string out_put);
	//void FindOut(int data[], int num, int coef[], int index);
	//void findOut(vector<int[]> pool, int num, int data[], int coef[], int test[], int index, int cnt);
};




