#include<iostream>
#include <time.h>
#include <stdlib.h>
#include "Function.h"
#include "Constant.h"
#include <iomanip>
#include <string>



using namespace std;


// Initialisation du tableau de lance
void IniBoardThrow(int myTab[][MAX_COLUMN])
{

	for (int i = 0; i < MAX_LINE; i++)
	{
		for (int j = 0; j < MAX_COLUMN; j++)
		{
			myTab[i][j] = 0;
		}
		myTab[i][0] = i + 1;
	}
}


//Affichage du tableau de lance
void DisplayBoardThrow(int myTab[][MAX_COLUMN])
{
	for (int i = 0; i < MAX_LINE; i++)
	{
		cout << "\nLancer #" << myTab[i][0];
		for (int j = 1; j < MAX_COLUMN; j++)
		{
			cout << " --- " << myTab[i][j];
		}
	}
}

//Initialisation du tableau de veouillage
void IniBoardLock(bool BoardLock[MAX_COLUMN])
{
	
	for (int j = 0; j < MAX_COLUMN; j++)
	{
		BoardLock[j] = false;
	}
}

//S'occupe du lancer de De avec la generation aleatoire.
void ThrowDice(int i, int  myTab[][MAX_COLUMN], bool BoardLock[MAX_COLUMN]){
	for (int j = 1; j < MAX_COLUMN; j++)
	{
		if (BoardLock[j] == false)
		{

			myTab[i][j] = rand() % 6 + 1;
		}
		else
		{
			myTab[i][j] = myTab[i - 1][j];
		}
	}

}

//S'occupe du systeme de lancer maximum par tour
void Starter(int myTab[][MAX_COLUMN], bool BoardLock[MAX_COLUMN])
{
	IniBoardThrow(myTab);
	for (int tour = 0; tour <= MAX_THROW; tour++)
	{
		ThrowDice(tour, myTab, BoardLock);
		DisplayBoardThrow(myTab);

	}
}

// Pour verrouiller le/les De
void DiceLock(int i, bool BoardLock[MAX_COLUMN])
{
	BoardLock[i] = !BoardLock [i];
}

//Affiche le tableau des scores
void DisplayBoard(int myScore[9])
{
	string numPoints[9] = { "AS","Two", "Three", "Four", "Five", "Six",
							"SubTotal", "Bonuses", "Total" };

	cout << "[Pointers]" << "\n\n";

	for (int i = 0; i < 9; i++)
	{
		cout << numPoints[i] << " : " << myScore[i] << "\n";
	}
	cout << endl;
}


//MAJ des points + Bonuse
void myPoints(int myTab[][MAX_COLUMN], int MyScore[9], int PointersChoice)
{
	
	DisplayBoard(MyScore);



	while (PointersChoice < 1 && PointersChoice > 6)
	{
		cout << " Les choix sont compris entre 1 et 6 ",
			cin >> PointersChoice;
	}

	while (MyScore[PointersChoice -1 ] != -1)
	{
		cout << " Le choix n'est pas valide, recommmencez! ",
			cin >> PointersChoice;
	}

	int myTotal(0);
	for (int i = 0; i < 5; i++)
	{
		if (myTab[2][i] == PointersChoice)
		{
			myTotal += myTab[2][i];
		}
	}

	MyScore[PointersChoice - 1] = myTotal;

	if (MyScore[6] >= 63 && MyScore[7] == 0)
	{
		cout << " Vous avez le droit a un bonus de 35 points ! ";

		MyScore[7] = 35;
	}
	MyScore[8] += MyScore[6] + MyScore[7];

	
}
