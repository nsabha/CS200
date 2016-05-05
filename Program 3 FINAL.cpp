#include <iostream>
#include <string> 
using namespace std;

void displayMainMenu()
{
	cout << "SCHOOL SYSTEM" << endl;
	cout << "1. Add class " << endl;
	cout << "2. Remove last class " << endl;
	cout << "3. Update class " << endl;
	cout << "4. View all classes " << endl;
	cout << "5. Exit " << endl;
	cout << endl;
}

int getUserInput(int minimum, int maximum)
{
	int choice;

	cout << "Enter an option >> ";
	cin >> choice;
	cout << endl;

	while (choice < minimum || choice > maximum)
	{
		cout << "Invalid choice. Try again " << endl;
		cin >> choice;
	}
	return choice;
}

void addClass(string classTitles[10], int classStudentCount[10], int& classCount)
{
	if (classCount < 10)
	{
		cout << "ADD CLASS " << endl;
		cout << "Enter class title: ";
		cin.ignore();
		getline(cin, classTitles[classCount]);
		cout << "Student count: ";
		cin >> classStudentCount[classCount];
		cout << "Class added " << endl;
		cout << endl;

		classCount++;
	}
	else
	{
		cout << "The Class list is already full!" << endl;
	}
}

void viewAllClasses(string classTitles[10], int classStudentCount[10], int& classCount)
{
	cout << "CLASS LIST " << endl;

	for (int i = 0; i < classCount; i++)
	{
		
		cout << i << ". \t" << classTitles[i] << ", Students: " << classStudentCount[i] << endl;
		cout << endl;
	}

}

void updateClass(string classTitles[10], int classStudentCount[10], int& classCount)
{
	int choice;


	// ask the user for which class to change
	cout << "CLASS LIST " << endl;
	cout << "UPDATE CLASS" << endl;
	cout << "Update which class? " << endl;
	cin >> choice;

	// ask the user for a new title
	cout << "New class title: ";
	cin.ignore();
	getline( cin, classTitles[choice]);

	// ask the user for new student count
	cout << "New student count: ";
	cin >> classStudentCount[choice];
	cout << "Class Updated " << endl;
	cout << endl;
}

void removeLastClass(string classTitles[10], int classStudentCount[10], int& classCount)
{
	if (classCount > 0)
	{
		cout << "REMOVE LAST CLASS: " << classTitles[classCount] << endl;
		cout << "Class removed" << endl;
		classTitles[classCount] = "";
		classStudentCount[classCount] = 0;
		cout << endl;
		classCount--;
	}
	else
	{
		cout << "The Class list is already empty!" << endl;
	}
}

void lineBreak()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
	}

	cout << endl;
}

int main()
{
	string classTitles[10];
	int classStudentCount[10];
	int classCount = 0;

	bool done = false;

	while (!done)
	{

		displayMainMenu();

		int choice = getUserInput(1, 5);

		if (choice == 5)
		{
			done = true;
		}
		else if (choice == 1)
		{
			addClass(classTitles, classStudentCount, classCount);
		}
		else if (choice == 2)
		{
			viewAllClasses(classTitles, classStudentCount, classCount);
			removeLastClass(classTitles, classStudentCount, classCount);

		}
		else if (choice == 3)
		{
			viewAllClasses(classTitles, classStudentCount, classCount);
			updateClass(classTitles, classStudentCount, classCount);
		}
		else if (choice == 4)
		{
			viewAllClasses(classTitles, classStudentCount, classCount);
			cout << endl;
		}

		lineBreak();
	}

	return 0;
}