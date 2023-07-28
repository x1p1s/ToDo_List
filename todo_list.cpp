#include "todo_list.h"
#include <Windows.h> 

TodoList::TodoList()
{
	filename = nullptr;
}

TodoList::TodoList(const char* filename)
{
	this->filename = filename;
}

TodoList::~TodoList()
{
	
}

void TodoList::read()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	fstream fs(filename, fstream::in);
	string line;

	list.clear();

	while (getline(fs, line))
	{
		if (line == "") continue;
		Item item(line);
		list.push_back(item);
	}

	fs.close();
}

void TodoList::display()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	cout << "Âארט הוכא: " << endl << endl;

	const int W = 40;
	cout << "   " << setw(W) << left << "ÑÏÈÑÎÊ" << "ÃÎÒÎÂÎ" << endl;
	cout << "   " << setw(W) << left << "----" << "----" << endl;
	for (int i = 0; i < list.size(); ++i)
		cout << i + 1 << ") " << setw(W) << left << list[i].text() << (list[i].is_done() ? "ÃÎÒÎÂÎ" : "") << endl;
}

void TodoList::create()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	bool is_finished = false;
	int count = 1;
	string task;

	list.clear();

	while (!is_finished)
	{
		cout << count << ": ";

		getline(cin, task);
		if (task == "") is_finished = true;

		Item item(task);
		list.push_back(item);
		count++;
	}
}

void TodoList::save()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	fstream fs(filename, fstream::out);

	for (Item item : list)
	{
		if (item.text().empty()) continue;
		fs << item.text() << " " << (item.is_done() ? "true" : "false") << endl;
	}

	fs.close();
}

int TodoList::get_count()
{
	return list.size();
}

void TodoList::add()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	int index = list.size();
	while (true)
	{

		cout << ++index << ": ";

		string task;
		getline(cin, task);
		if (task == "") break;

		Item item(task);
		list.push_back(item);
	}

	save();
}

void TodoList::clear()
{

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	list.clear();
	remove(filename);
}

void TodoList::check()
{
	cout << "Âûבונועו םמלונ הוכא ט םאזלטעו enter: ";

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	string choice;
	getline(cin, choice);

	if (choice.empty()) return;
	for (char c : choice) if (isalpha(c)) return;

	int index = stoi(choice) - 1;
	if (index > list.size()) return;
	list[index].done();

	save();
}