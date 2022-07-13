// bik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


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

int main()
{
   srand(time(NULL));
   /*for (int i = 0; i < 20; i++)
   {

	   string number = imagine_chislo();
	   
   }*/

   string number = imagine_chislo();
   cout << "number was imagined" << endl;
   

   cout << "try to gues:";
   string g_number;
   do{
	   cin >> g_number;
   } while (!is_normal(g_number));
   cout << g_number;
}
