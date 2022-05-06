#include<iostream>

using namespace std;

int OutOfRange(const char* str) {
	char s[20];
	int t, i;
	long res = 0;
	int len = strlen(str);

	try
	{
		t = 1;
		if (str[0] == '-')
			t = -1;
		i = len - 1;
		while (i >= 0)
		{
			if(str[i] == '-'){
				if (i == 0) break;
				else throw "Error!";
			}
			if (str[i] < '0') throw "Error!";
			if (str[i] > '9') throw "Error!";

			res = res + (str[i] - '0') * t;

			t *= 10;
			i--;
		}
		if (res > INT32_MAX)
			throw "Out of range";
		if (res < INT32_MIN)
			throw "Out of range";
		return res;
	}
	catch (const char * e)
	{
		cout << e << endl;
		return 0;
	}
}

void main() {
	int d;
	d = OutOfRange("228");
	cout << "d = 0" << d;
}