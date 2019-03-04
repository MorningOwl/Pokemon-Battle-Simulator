#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

#define next system("pause"); system("cls")

using namespace std;


bool Player::potion()
{
	if (pkmn.p_HP == pkmn.p_HPMax)
	{
		cout << "HP is already full!\n\n", next;
		return false;
	}

	cout << "Used a potion!\n\n", next;

	if (pkmn.p_HP < pkmn.p_HP - 20)
		pkmn.p_HP += 20;
	else
		pkmn.p_HP = pkmn.p_HPMax;

	return true;
}

bool Player::ether()
{
	int det;
	while (true)
	{
		cout << "Choose a move to use an ether on:\n\n";
		cout << "1." << pkmn.p_move[1].m_name << " (" << pkmn.p_move[1].m_PP << "/" << pkmn.p_move[1].m_PPMax << ")\t\t";
		cout << "2." << pkmn.p_move[2].m_name << " (" << pkmn.p_move[2].m_PP << "/" << pkmn.p_move[2].m_PPMax << ")\n\n";
		cout << "3.Back\n\n";
		cin >> det;
		system("cls");
		if (det == 3) return false;
		if (det == 1 || det == 2) break;
	}

	for (int i = 1; i <= pkmn.p_numMoves; i++)
	{
		if (det == i)
		{
			if (pkmn.p_move[i].m_PP == pkmn.p_move[i].m_PPMax)
			{
				cout << "PP is already full for that move!\n\n", next;
				return false;
			}

			else
			{
				cout << "Used an ether!\n\n", next;
				
				if (pkmn.p_move[i].m_PP < pkmn.p_move[i].m_PPMax - 5)
					pkmn.p_move[i].m_PP += 10;
				else
					pkmn.p_move[i].m_PP = pkmn.p_move[i].m_PPMax;

				return true;
			}
		}
	}
}

bool Player::XAttack()
{
	int det;
	cout << "Used an X Attack!\n\n", next;

	if (pkmn.p_attackLevel >= 6)
	{
		cout << pkmn.p_name << " 's attack won't go any higher!\n\n", next;
		return true;
	}

	det = (pkmn.p_attackLevel == 5) ? 1 : 2;
	pkmn.changeStat(pkmn, "attack", det);
	return true;
}

bool Player::XDefense()
{
	int det;
	cout << "Used an X Defense!\n\n", next;

	if (pkmn.p_defenseLevel >= 6)
	{
		cout << pkmn.p_name << " 's defense won't go any higher!\n\n", next;
		return true;
	}

	det = (pkmn.p_defenseLevel == 5) ? 1 : 2;
	pkmn.changeStat(pkmn, "defense", det);
	return true;
}

bool Player::pokeBall(Pokemon &foe)
{
	int det;
	cout << "Used a Poke Ball!\n\n", next;

	cout << "1..."; Sleep(1000); cout << "2..."; Sleep(1000); cout << "3..."; Sleep(1000);
	system("cls");
	cout << "Captured wild " << foe.p_name << "!\n\n", next;

	while (true)
	{
		cout << "Would you like to give a nickname to your new " << foe.p_name << "?\n\n";
		cout << "1.Yes\n2.No\n\n";
		cin >> det;
		system("cls");
		if (det == 1 || det == 2) break;
	}

	/*if (det == 1)
	{
		char name[20];

		while (true)
		{
			cout << "Enter nickname:\n\n";
			cin.ignore();
			cin.getline(name, 20);
			foe.p_name = name;
			cout << "\nIs this name correct?\n\n1.Yes\n2.No\n\n";
			cin >> det;
			system("cls");
			if (det == 1) break;
		}
	}*/

	this->numPkmn++;
	Pkmn[numPkmn] = foe;
	this->battleEnd = true;
	return true;
}