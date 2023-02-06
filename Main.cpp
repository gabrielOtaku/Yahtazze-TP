#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Function.h"
#include "Constant.h"
#include <iomanip>

using namespace std;



int main()
{
	srand(unsigned(time(NULL)));

	int myTab[3][6]{}, MyScore[9]{ -1, -1, -1, -1, -1, -1, 0, 0, 0 }, ThePointers;
	bool BoardLock[5]{};



	for (int i = 0; i < 6; i++) // Nombre de tours
	{
		IniBoardThrow(myTab);
		IniBoardLock(BoardLock);

		for (int j = 0; j < 3; j++) // nombre de lancer
		{
			ThrowDice(j, myTab, BoardLock);
			DisplayBoardThrow(myTab);


			int tour = j;
			int choix;

			do
			{


				cout << "\nEntrez un numero de d\x82 à conserver (1 a 5; 0 pour relancer) : ";
				cin >> choix;

				if (cin.fail()) // Si la valeur rentrer et une lettre
				{
					cout << " Entr\x82 non valide, veuillez entrer un chiffre. " << "\n";

					cin.clear();
					cin.ignore(256, '\n');
					choix = -1; // Cela evite que les valeurs ou lettres rentrer par erreur ne soit pas a 0
				}
				else if (choix >= 1 && choix <= 5)
				{
					if (BoardLock[choix] == false)
					{
						cout << "D\x82 #" << choix << " verrouill\x82.\n";
					}
					else
					{
						cout << "D\x82 #" << choix << " deverrouill\x82.\n";
					}
					DiceLock(choix, BoardLock); // Verrouille et Deverrouille les De selon le choix du joueur

				}



			} while (choix != 0);


		}
		cout << "\n" << " Quel num\x82ro voulez-vous pointez ? : ";

		while (!(cin >> ThePointers)) // Tant que la valeur n'appartient pas au tableau de pointage
		{
			cout << " D\x82ol\x82 ! Vous devenez donner un chiffre.";
			cin.clear();
			cin.ignore(256, '\n');

		}
		myPoints(myTab, MyScore, ThePointers);
		DisplayBoard(MyScore);

	}


	cout << "---------------" << "\n" << " Pointage final " << MyScore[8] << "\n" << "-------------------";


	return 0;

}


