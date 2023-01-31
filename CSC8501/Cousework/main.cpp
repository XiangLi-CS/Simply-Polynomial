#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
#include "tools.h"
using namespace std;



int main(void) {
	Tool tool;
	int a[tool.MAX];
	int s, f, ret;

	int control = 0;
	cout << "Hello! What do you want to do? Type 1: Create algebraic expression yourself. Type 0: Derived an algebraic expression from output set" << endl;
	cin >> control;
	if (control == 1)
	{
		auto flag = 1;
		while (flag) {
			flag = 1;
			cout << "The regular algebraic expression in this program is Ax^4+Bx^3+Cx^2+Dx+E" << endl;
			cout << "Please type your coefficients for A B C D (-9~9)and your constant for E(-1000~1000)" << endl;

			for (int i = tool.MAX - 1; i > -1; i--)
			{
				cin >> a[i];
			}

			cout << "Your algebraic expression is:" << endl;
			tool.CreateExpression(a, tool.MAX);

			while (flag == 1)
			{
				cout << "Please select a range of Input numbers" << endl;
				cout << "Start number: " << endl;
				cin >> s;
				cout << "Finish number: " << endl;
				cin >> f;
				cout << "The output sets are:" << endl;
				string buff = "";
				for (int i = s; i <= f; i++)
				{
					ret = tool.CalculateExpression(a, i);
					//ternary operator
					buff = buff != "" ? buff + "," : buff;
					buff += to_string(ret);
				}

				cout << buff << endl;
				cout << endl;
				cout << "Do you want to save the output sets? Yes: type 1, No: type 0" << endl;
				cin >> flag;
				if (flag) {
					auto res = tool.outPut2File(buff);
					if (!res) {
						cout << "ERROR: output file failed" << endl;
						return 0;
					}
				}

				cout << "Close: type 0, New output: type 1, Create new expression: type 2" << endl;
				cin >> flag;
			}
		}
	}
	else {
		string name = "";
		cout << "Please type the name of the file" << endl;
		cin >> name;
		string Filename = name + ".txt";
		ifstream ifs(Filename, ios::in);			//Read file
		if (!ifs.is_open()) {
			cout << "ERROR: output file failed" << endl;
			return 0;
		}

		int* data = new int[tool.SIZE];
		string s;
		while (getline(ifs, s))
		{
			tool.stringTOnum(s, data);

			try {
			if (name == "A")
			{

				auto a = data[1];
				auto n = tool.CalculatePower(data[tool.X] / a, tool.X);
				
				cout << "The expression for set A is: " << endl;
			
				string f = to_string(a) + "x^" + to_string(n);
				cout << f << endl;
				auto expression = tool.outPutE2File(f);
				if (!expression) {
					throw 0;
					break;
				}
				cout << "The expression is saved" << endl;
				

			}

			if (name == "B")
			{
				int c = 0;
				if (data[0] != 0)
				{
					c = data[0];
				}

				auto a = data[1] + -1*c;
				auto n = tool.CalculatePower((data[tool.X] + -1 * c) / a, tool.X);
				cout << "The expression for set B is: " << endl;

				string f = to_string(a) + "x^" + to_string(n)+to_string(c);
				cout << f << endl;
				auto expression = tool.outPutE2File(f);
				if (!expression) {
					throw 0;
					break;
				}
				cout << "The expression is saved" << endl;
			}

			if (name == "C")
			{
				 
			}
			
			cout << endl;	
			}
			catch (int ret) {
				cout << "error" << endl;
				return 0;
			}
		}

		ifs.close();
		cin.get();

	}	

	return 0;
	
}