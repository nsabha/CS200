#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int getAttack()
{
	int randomNumber = rand() % 11;
	return randomNumber;
}

int getHealing()
{
	int randomNumber = rand() % 8;
	return randomNumber;
}

int getRandomValue()
{
	int randomNumber = rand() % 2;
	return randomNumber;

}

int getChoice(int minimum, int maximum)
{
	int choice;
	cin >> choice;

	while (choice > maximum || choice < minimum)
	{
		cout << "Invlaid Choice, Please try again!" << endl;
		cin >> choice;
	}
	return choice;
}

void displayMenu(int round, int playerHP, int enemyHP)
{
	cout << "ROUND " << round << endl;
	cout << "playerHP: " << playerHP << "         " << "enemyHP: " << enemyHP << endl;
	cout << endl;
	cout << "Choose Option: " << endl;
	cout << "1. Attack" << endl;
	cout << "2. Heal" << endl;
	cout << endl;
	cout << "What do you want to do? " << endl;
	cout << ">> ";
	
}

int main()
{
	srand(time(NULL)); 
	int round = 1;
	int playerHP = 100;
	int enemyHP = 100;
	bool done = false;

	while (!done)
	{
		displayMenu(round, playerHP, enemyHP);
		int choice = getChoice(1, 2); // player choice either attack or heal

		int option = getRandomValue();
		if (option == 0) // enemy's option
		{
			int getDamage = getAttack();
			playerHP = playerHP - getDamage;
			cout << "Enemy attacking " << getDamage << " points" <<  endl;
		}
		else if (option == 1)
		{
			int healPoints = getHealing();
			enemyHP = enemyHP + healPoints;
			cout << "Enemy healing " << healPoints << " points" << endl;
		}

		
		if (choice == 1) // player option
		{
			int getDamage = getAttack();
			enemyHP = enemyHP - getDamage;
			cout << "Player atatcking " << getDamage << " points" << endl;
		}
		else if (choice == 2)
		{
			int healPoints = getHealing();
			playerHP = playerHP + healPoints;
			cout << "player Healing " << healPoints << " points" << endl;
		}
		if (playerHP <= 0)// player/enemy status
		{
			done = true;
			cout << "You lost" << endl;
		}

		else if (enemyHP <= 0)
		{
			done = true;
			cout << "Enemy lost " << endl;
		}


		round++;  
	}
	if (playerHP = 0 && enemyHP > 0 )
	{
		cout << "YOU LOST!" << endl;
	}
	else if (enemyHP = 0 && playerHP > 0 )
	{
		cout << "YOU WIN!" << endl;
	}

	//if (playerHP < enemyHP )
	//{
	//	cout << "YOU LOST!" << endl;
	//}
	//else if (playerHP > enemyHP)
	//{
	//	cout << "YOU WIN!" << endl;
	//}
	//
return 0;
}