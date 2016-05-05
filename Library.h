#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

struct Library

{
	bookItem book[80];
	int arraySize = 80;
	int bookCount = 0;

	void initLibrary()
	{
		fstream input("Library.txt");

		string library;

		input >> library;
		input >> library;
		input >> library;

		while (input >> book[bookCount].ID
			>> book[bookCount].Title
			>> book[bookCount].FName >> book[bookCount].MName >> book[bookCount].LName)
		{
			bookCount++;
		}

		cout << "VERIFY BOOKS" << endl;
		cout << endl;

		for (int i = 0; i < bookCount; i++)
		{
			cout << "Book " << i
				<< "\t ID: " << book[i].ID
				<< "\t TITLE: " << book[i].Title
				<< "\t Author: " << book[i].FName << " " << book[i].MName << " " << book[i].LName << endl;
		}

		input.close();
	}

	int getValidInput(int minimum, int maximum)
	{
		int x;
		cin >> x;

		while (x < minimum || x > maximum)
		{
			cout << "Invalid Option, try again " << endl;
			cin >> x;
		}
		return x;
	}

	int MainMenu()
	{
		cout << "LIBRARY SYSTEM ACCESS " << endl;
		cout << "1. Public Access " << endl;
		cout << "2. Admin Access " << endl;
		cout << "3. Exit" << endl;

		int choice = getValidInput(1, 3);

		return choice;
	}

	int AdminMenu()
	{
		

		cout << "1. Update book " << endl;
		cout << "2. Add book " << endl;
		cout << "3. Export database " << endl;
		
	int choice2 = getValidInput(1, 3);

		return choice2;
	}

	void runAdmin()
	{
		int option = AdminMenu();
		if (option == 1)
		{
			UpdateBook();
		}
		else if (option == 2)
		{
			AddBook();
		}
		else if (option == 3)
		{
			SaveLibrary();
		}
	}

	int PublicMenu()
	{
		cout << "1. Search by title " << endl;
		cout << "2. Search by author " << endl;
		cout << "3. Exit " << endl;

		int choice3 = getValidInput(1, 3);

		return choice3;
	}

	void runPublic()
	{
		int option2 = PublicMenu();

		if (option2 == 1)
		{
			SearchByTitle();
		}
		else if (option2 == 2)
		{
			SearchByAuthor();
		}
		else
		{
			true;
		}
	}

	void runMain()
	{
		int option = MainMenu();

		bool done = false;
		while (!done)
		{
			if (option == 1)
			{
				runPublic();
			}
			else if (option == 2)
			{
				runAdmin();
			}
			else
			{
				true;
			}
		}
	}

	void UpdateBook(int index)
	{


		string Title;
		string first, middle, last;

		cout << "Title: ";
		cin >> Title;
		cout << "Author first, middle, last names: ";
		cin >> first, middle, last;

		book[index].Title = Title;
		book[index].FName = first;
		book[index].MName = middle;
		book[index].LName = last;

	}

	void UpdateBook()
	{
		int bookNum = selectBook();
		UpdateBook(bookNum);
	}

	int selectBook()
	{
		int increment = 20;
		int pages = bookCount / increment;

		bool done = true;

		while (done)
		{
			for (int p = 0; p < pages; p++)
			{
				int first = p * increment;
				int last = p * increment + increment;

				for (int b = first; b < last; b++)
				{
					cout << "Book " << b
						<< "\t ID: " << book[b].ID
						<< "\t TITLE: " << book[b].Title
						<< "\t Author: " << book[b].FName << " " << book[b].MName << " " << book[b].LName << endl;
				}

				cout << "Enter any number to go to the next page " << endl;

				int option = getValidInput(first, last);

				return option;
			}
		}
	}

	void SaveLibrary()
	{
		ofstream output("library2.txt");

		output << "ID " << "\t TITLE " << "\t AUTHOR " << endl;

		for (int i = 0; i < bookCount; i++)
		{
			output << book[bookCount].ID;
			output << book[bookCount].Title;
			output << book[bookCount].FName << book[bookCount].MName << book[bookCount].LName;
		}
		output.close();
	}

	void AddBook()
	{
		if (bookCount >= arraySize)
		{
			cout << "Library is full already!" << endl;
		}
		else
		{
			UpdateBook(bookCount);
			book[bookCount].ID = book[bookCount - 1].ID + 1;
		}

		bookCount = bookCount + 1;
	}

	void SearchByTitle()
	{
		bool found = false;
		string title;
		cout << "Enter Title: ";
		cin >> title;

		for (int i = 0; i < arraySize; i++)
		{
			//book[t].Title;
			if (book[i].Title.find(title) == string::npos)
			{
				cout << book[bookCount].Title;
				cout << book[bookCount].FName;
				cout << book[bookCount].MName;
				cout << book[bookCount].LName;

				found = true;
		   }
		}

		if (!found)
		{
			cout << "NOT FOUND" << endl;
		}

	}

	void SearchByAuthor()
	{
		bool found = false;
		string word;
		cout << "Enter an author name: ";
		cin >> word;

		for (int a = 0; a < arraySize; a++)
		{
			

			if (book[a].LName.find(word) == string::npos)
			{

				cout << book[bookCount].Title;
				cout << book[bookCount].FName;
				cout << book[bookCount].MName;
				cout << book[bookCount].LName;
			}
		}

		if (!found)
		{
			cout << "NOT FOUND" << endl;
		}

	}

};