#include <iostream>
#include "todo_list.h"
#include <Windows.h>

using namespace std;

int main(int argc, char const* argv[])
{

	setlocale(0, "ru");

	TodoList tasks("list.txt");

	while (true)
	{
		tasks.read();

		if (tasks.get_count() > 0)
		{
			tasks.display();
			cout << endl;

			cout << "1) Добавить дело" << endl;
			cout << "2) Удалить дело" << endl;
			cout << "3) Сделано" << endl;
			cout << "Выберете один из пунктов: ";

			string choice;
			getline(cin, choice);

			if (choice == "1")
			{
				tasks.add();
			}
			else if (choice == "2")
			{
				tasks.clear();
			}
			else if (choice == "3") 
			{
				tasks.check();
			}
			else
			{
				break;
			}

		}
		else
		{



			cout << "Создайте новое дело .." << endl;
			tasks.create();

			cout << endl;
			tasks.display();

			tasks.save();
		}
	}

	return 0;
}