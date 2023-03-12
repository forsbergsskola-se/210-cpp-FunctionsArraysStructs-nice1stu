#include <cstdio>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	std::vector<float> userInputArray;

	while (true)
	{
		cout << "Input a number you want to add to the list" << endl;
		cout << "Press [esc] when you are finished" << endl;
		
		int input = 0;
		char c = _getch();
		if (c == 27)
		{
			break;
		}
		else
		{
			cin >> input;
		}

		userInputArray.push_back(input);
	}
}