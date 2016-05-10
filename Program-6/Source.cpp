#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Color
{
public:
	string color;
	int r, g, b;
};

struct Type
{
	string name;
};

struct Clothing
{
	string name;
	Color* ptrColor = NULL;
	Type* ptrType = NULL;
};

struct Outfit
{
	string name;
	Clothing* ptrHead = NULL;
	Clothing* ptrTop = NULL;
	Clothing* ptrBottom = NULL;
};

int main()
{
	Type alltype[3];
	alltype[0].name = "Head";
	alltype[1].name = "Top";
	alltype[2].name = "Bottom";

	Color allColor[8];
	allColor[0].color = "Red";
	allColor[1].color = "Green";
	allColor[2].color = "Blue";
	allColor[3].color = "Yellow";
	allColor[4].color = "Magenta";
	allColor[5].color = "Cyan";
	allColor[6].color = "White";
	allColor[7].color = "Black";

	Clothing allClothes[9];
	allClothes[0].name = "Baseball Cap";
	allClothes[1].name = "Top hat";
	allClothes[2].name = "Scarf ";
	allClothes[3].name = "T-shirt";
	allClothes[4].name = "Blouse";
	allClothes[5].name = "Button-up Shirt";
	allClothes[6].name = "Jeans";
	allClothes[7].name = "Skirt";
	allClothes[8].name = "Cargo Shorts";


	Outfit outfit;



	allClothes[0].ptrColor = &allColor[0];
	allClothes[0].ptrType = &alltype[0];
	allClothes[1].ptrColor = &allColor[1];
	allClothes[1].ptrType = &alltype[0];
	allClothes[2].ptrColor = &allColor[2];
	allClothes[2].ptrType = &alltype[0];
	allClothes[3].ptrColor = &allColor[3];
	allClothes[3].ptrType = &alltype[1];
	allClothes[4].ptrColor = &allColor[4];
	allClothes[4].ptrType = &alltype[1];
	allClothes[5].ptrColor = &allColor[5];
	allClothes[5].ptrType = &alltype[1];
	allClothes[6].ptrColor = &allColor[6];
	allClothes[6].ptrType = &alltype[2];
	allClothes[7].ptrColor = &allColor[7];
	allClothes[7].ptrType = &alltype[2];
	allClothes[8].ptrColor = &allColor[7];
	allClothes[8].ptrType = &alltype[2];

	bool programDone = false;
	while (!programDone)
	{

		bool done = false;
		while (!done)
		{
			for (int i = 0; i < 9; i++)
			{
				cout << (i) << ". " << allClothes[i].name << "\t" << allClothes[i].ptrColor->color << "\t" <<  allClothes[i].ptrType->name << endl;
			}

			int choice;
			cout << endl;
			cout << "Select items: " << endl;
			cout << "--------------------------------------------" << endl;
			cin >> choice;

			if (choice < 0 || choice > 8)
			{
				done = true;
			}
			else
			{
				if (allClothes[choice].ptrType->name == "Head")
				{
					outfit.ptrHead = &allClothes[choice];
				}
				else if (allClothes[choice].ptrType->name == "Top")
				{
					outfit.ptrTop = &allClothes[choice];
				}
				else if (allClothes[choice].ptrType->name == "Bottom")
				{
					outfit.ptrBottom = &allClothes[choice];
				}
			}
		}
		cout << "Enter a name for outfit.. ";
		cin >> outfit.name;

		//cout << outfit.ptrHead->name << "  " << outfit.ptrTop->name << "  " << outfit.ptrBottom->name << endl;

		ofstream output("outfit.txt");
		output << outfit.name << endl;

		if (outfit.ptrHead == NULL)
		{
			output << "HEAD: Nude";
		}
		else
		{
			output << outfit.ptrHead->name << "  " << outfit.ptrHead->ptrType->name << "  " << outfit.ptrHead->ptrColor->color << endl;
		}
		if (outfit.ptrTop == NULL)
		{
			output << "TOP: Nude";
		}
		else
		{
			output << outfit.ptrTop->name << "  " << outfit.ptrTop->ptrType->name << "  " << outfit.ptrTop->ptrColor->color << endl;
		}
		if (outfit.ptrBottom == NULL)
		{
			output << "BOTTOM: Nude";
		}
		else
		{
			output << outfit.ptrBottom->name << "  " << outfit.ptrBottom->ptrType->name << "  " << outfit.ptrBottom->ptrColor->color << endl;
		}

		output.close();

		char option;
		cout << endl;
		cout << "Would you like to create another outfit? Y/N";
		cout << endl;
		cin >> option;

		if (option == 'Y' || option == 'y')
		{
			programDone = false;
		}
		else if (option == 'N' || option == 'n')
		{
			programDone = true;
		}
	}

	return 0;
}