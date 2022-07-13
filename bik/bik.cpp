// bik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include<windows.h>

using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}



string imagine_chislo()
{
	int arr[4];
	for (int i = 0; i < 4; )
	{
		int chislo = rand() % 10;

		bool bulo = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == chislo)
				bulo = true;

		}
		if (!bulo)
		{
			arr[i] = chislo;
			i++;
		}
	}
	string imagine_chislo;

	for (int i = 0; i < 4; i++)
	{
		imagine_chislo+=to_string(arr[i]);
	}

	return imagine_chislo;
}


bool is_normal(string to_check)
{
	bool is_normal = true;
		
	if (to_check.size()==4)
	{ 
		for (int i = 0; i < 4; i++)
		{
			
			char digit = to_check[i];
			if (!isdigit(digit)) {
				cout << "enter a numder" << endl;
				is_normal = false;
				break;
			}
			bool bulo = false;
			for (int j = 0; j < i; j++)
			{
				if (to_check[j] == digit)
					bulo = true;
			}
		
			if (bulo)
			{
				cout << "enter numder without dublicate digits" << endl;
				is_normal = false;
				break;
			}
			else i++;
		}
	}
	else
	{
		cout << "enter 4 digits in the number"<<endl;
		is_normal = false;
	}
	return is_normal;
}

void coloring(string number,string g_number) {
	for (int i = 0; i < number.length(); i++)
	{

		if (g_number[i] == number[i]) {
			SetColor(7, 2);
			cout << g_number[i];
		}

		else if (number.find(g_number[i]) != string::npos) {
			SetColor(7, 4);
			cout << g_number[i];
		}

		else {
			SetColor(7, 0);
			cout << g_number[i];
		}
		SetColor(7, 0);
	}
	cout << endl;
}

int main()
{
   srand(time(NULL));
   string number = imagine_chislo();
   cout << "number was imagined" << endl;
   //cout << number << endl;

   cout << "try to gues:";
   string g_number;
   
   do {

	do{

	   cin >> g_number;
	   

	} while (!is_normal(g_number));
	   
	coloring(number, g_number);
   } while (g_number != number);
   cout << "You gues!!! You win!!!";
}

