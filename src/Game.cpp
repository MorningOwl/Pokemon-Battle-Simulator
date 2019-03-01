#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"

#define next system("pause"); system("cls")

using namespace std;

Pokemon pkmn, foe;
int det;

int playerTurn();
int foeTurn();
int fight();
void stats();
bool bag();


int main()
{
	while (true)
	{
		while (true)
		{
			cout << "************************\n";
			cout << "POKEMON BATTLE SIMULATOR\n";
			cout << "************************\n\n";
			cout << "What Pokemon will you use?\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
			cin >> det;
			system("cls");
			if (det == 0) exit(EXIT_SUCCESS);
			if (det == 1 || det == 2 || det == 3 || det == 9999) break;
		}

		srand(time(0));
		int prob = 1 + rand() % 2;

		switch (det)
		{
			case 1: pkmn.initPokemon(BULBASAUR); if (prob == 1) foe.initPokemon(CHARMANDER); else foe.initPokemon(SQUIRTLE); break;
			case 2: pkmn.initPokemon(CHARMANDER); if (prob == 1) foe.initPokemon(BULBASAUR); else foe.initPokemon(SQUIRTLE); break;
			case 3: pkmn.initPokemon(SQUIRTLE); if (prob == 1) foe.initPokemon(BULBASAUR); else foe.initPokemon(CHARMANDER);
		}

		if (det == 9999)
		{
			while (true)
			{
				cout << "Choose your Pokemon:\n\n";
				cout << "1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n4.PIDGEY\n5.RATTATA\n6.SPEAROW\n7.ODDISH\n\n";
				cin >> det;
				system("cls");
				if (det > 0 && det < 8) break;
			}

			switch (det)
			{
				case 1: pkmn.initPokemon(BULBASAUR); break;
				case 2: pkmn.initPokemon(CHARMANDER); break;
				case 3: pkmn.initPokemon(SQUIRTLE); break;
				case 4: pkmn.initPokemon(PIDGEY); break;
				case 5: pkmn.initPokemon(RATTATA); break;
				case 6: pkmn.initPokemon(SPEAROW); break;
				case 7: pkmn.initPokemon(ODDISH); break;
			}

			while (true)
			{
				cout << "Choose your opponent:\n\n";
				cout << "1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n4.PIDGEY\n5.RATTATA\n6.SPEAROW\n7.ODDISH\n\n";
				cin >> det;
				system("cls");
				if (det > 0 && det < 8) break;
			}

			switch (det)
			{
				case 1: foe.initPokemon(BULBASAUR); break;
				case 2: foe.initPokemon(CHARMANDER); break;
				case 3: foe.initPokemon(SQUIRTLE); break;
				case 4: foe.initPokemon(PIDGEY); break;
				case 5: foe.initPokemon(RATTATA); break;
				case 6: foe.initPokemon(SPEAROW); break;
				case 7: foe.initPokemon(ODDISH); break;
			}
		}

		while (true)
		{
			if (playerTurn() == -1) break;
			if (foeTurn()) break;
		}
	}
}


int playerTurn()
{
	while (true)
	{
		cout << "******************************\n";
		cout << "Using: "; pkmn.logName();
		cout << "Foe:   "; foe.logName();
		cout << "******************************\n\n";
		cout << "What will " << pkmn.p_name << " do?\n\n";
		cout << "1.Fight\t\t2.Bag\n3.Stats\t\t4.Run\n\n";

		cin >> det;
		system("cls");

		switch (det)
		{
			case 1:
				det = fight();
				if (det == 1) return 1;
				if (det == -1) return -1;
				break;

			case 2:
				if (bag())
					return 1;
				break;

			case 3:
				stats();
				break;

			case 4:
				cout << "Got away safely!\n\n";
				next;
				return -1;
		}
	}
}

int foeTurn()
{
	srand(time(0));
	int prob = 1 + rand() % 20;

	switch (foe.p_numMoves)
	{
		case 1:
			foe.move1(foe, pkmn);
			break;

		case 2:
			if ((foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL) || (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS))
				if (prob < 11) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS)
				if (prob < 15) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL)
				if (prob < 7) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			break;

		case 3:
			if ((foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL) ||
				(foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS))
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS)
				if (prob < 13) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 9) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 13) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL)
				if (prob < 9) foe.move1(foe, pkmn); else if (prob < 13) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS)
				if (prob < 9) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			break;

		case 4:
			if ((foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == PHYSICAL) ||
				(foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == STATUS))
				if (prob < 6) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 16) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == STATUS)
				if (prob < 12) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 7) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == PHYSICAL)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 7) foe.move2(foe, pkmn); else if (prob < 10) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if ((foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == PHYSICAL) ||
				(foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == PHYSICAL) ||
				(foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == PHYSICAL) ||
				(foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == STATUS))
				if (prob < 6) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 16) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == STATUS)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == PHYSICAL)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == STATUS)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == PHYSICAL)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 13) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == STATUS && foe.p_moveEffect[2] == PHYSICAL && foe.p_moveEffect[3] == PHYSICAL && foe.p_moveEffect[4] == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_moveEffect[1] == PHYSICAL && foe.p_moveEffect[2] == STATUS && foe.p_moveEffect[3] == STATUS && foe.p_moveEffect[4] == PHYSICAL)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 14) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
	}

	if (pkmn.p_HP <= 0)
	{
		cout << pkmn.p_name << " fainted!\n\n";
		next;
		return 1;
	}

	return 0;
}

bool win()
{
	if (foe.p_HP <= 0)
	{
		cout << foe.p_name << " fainted!\n\n";
		next;
		return true;
	}
	return false;
}

int fight()
{
	switch (pkmn.p_numMoves)
	{
		case 1:
			while (true)
			{
				pkmn.logMove(pkmn.p_moveName[1], 1);
				cout << "\n2.Back\n\n";
				cin >> det;
				system("cls");
				if (det == 1 || det == 2) break;
			}

			if (det == 1)
			{
				pkmn.move1(pkmn, foe);
				if (win()) return -1;
				return 1;
			}

			return 0;

		case 2:
			while (true)
			{
				pkmn.logMove(pkmn.p_moveName[1], 1, false);
				cout << "2." << pkmn.p_moveName[2] << " (" << pkmn.p_movePP[2] << "/" << pkmn.p_movePPMax[2] << ")\n\n";
				cout << "3.Back\n\n";
				cin >> det;
				system("cls");
				if (det == 1 || det == 2 || det == 3) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 3:
					return 0;
			}

		case 3:
			while (true)
			{
				pkmn.logMove(pkmn.p_moveName[1], 1, false);
				cout << "2." << pkmn.p_moveName[2] << " (" << pkmn.p_movePP[2] << "/" << pkmn.p_movePPMax[2] << ")\n";
				pkmn.logMove(pkmn.p_moveName[3], 3); cout << endl;
				cout << "4.Back\n\n";
				cin >> det;
				system("cls");
				if (det == 1 || det == 2 || det == 3 || det == 4) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 3:
					pkmn.move3(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 4:
					return 0;
			}

		case 4:
			while (true)
			{
				pkmn.logMove(pkmn.p_moveName[1], 1, false);
				cout << "2." << pkmn.p_moveName[2] << " (" << pkmn.p_movePP[2] << "/" << pkmn.p_movePPMax[2] << ")\n";
				pkmn.logMove(pkmn.p_moveName[3], 3, false);
				cout << "4." << pkmn.p_moveName[4] << " (" << pkmn.p_movePP[4] << "/" << pkmn.p_movePPMax[4] << ")\n\n";
				cout << "5.Back\n\n";
				cin >> det;
				system("cls");
				if (det == 1 || det == 2 || det == 3 || det == 4 || det == 5) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 3:
					pkmn.move3(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 4:
					pkmn.move4(pkmn, foe);
					if (win()) return -1;
					return 1;

				case 5:
					return 0;
			}
	}
}

void stats()
{
	cout << pkmn.p_name << endl;
	if (pkmn.p_type2 == NONE) cout << pkmn.p_type1Name << endl;
	else cout << pkmn.p_type1Name << ", " << pkmn.p_type2Name << endl;
	cout << "Health: " << pkmn.p_HP << endl;
	cout << "Attack: " << pkmn.p_attack << endl;
	cout << "Defense: " << pkmn.p_defense << endl;
	cout << "Speed: " << pkmn.p_speed << "\n\n";
	next;
}

bool potion()
{
	if (pkmn.p_potionNum <= 0)
	{
		cout << "Out of potions!\n\n";
		next;
		return false;
	}

	if (pkmn.p_HP == pkmn.p_HPMax)
	{
		cout << "HP is already full!\n\n";
		next;
		return false;
	}

	cout << "Used a potion!\n\n";
	pkmn.p_potionNum--;
	next;

	if (pkmn.p_HP < pkmn.p_HP - 20)
		pkmn.p_HP += 20;
	else
		pkmn.p_HP = pkmn.p_HPMax;

	return true;
}

bool ether()
{
	if (pkmn.p_etherNum <= 0)
	{
		cout << "Out of ethers!\n\n";
		next;
		return false;
	}

	while (true)
	{
		cout << "Choose a move to use an ether on:\n\n";
		cout << "1." << pkmn.p_moveName[1] << " (" << pkmn.p_movePP[1] << "/" << pkmn.p_movePPMax[1] << ")\t\t";
		cout << "2." << pkmn.p_moveName[2] << " (" << pkmn.p_movePP[2] << "/" << pkmn.p_movePPMax[2] << ")\n\n";
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
			if (pkmn.p_movePP[i] == pkmn.p_movePPMax[i])
			{
				cout << "PP is already full for that move!\n\n";
				next;
				return false;
			}

			else
			{
				cout << "Used an ether!\n\n";
				pkmn.p_etherNum--;
				next;
				
				if (pkmn.p_movePP[i] < pkmn.p_movePPMax[i] - 5)
					pkmn.p_movePP[i] += 10;
				else
					pkmn.p_movePP[i] = pkmn.p_movePPMax[i];

				return true;
			}
		}
	}
}

bool XAttack()
{
	if (pkmn.p_XAttackNum <= 0)
	{
		cout << "Out of X Attacks!\n\n";
		next;
		return false;
	}

	cout << "Used an X Attack!\n\n";
		pkmn.p_XAttackNum--;
	next;

	if (pkmn.p_attackLevel >= 6)
	{
		cout << pkmn.p_name << " 's attack won't go any higher!\n\n";
		next;
		return true;
	}

	det = (pkmn.p_attackLevel == 5) ? 1 : 2;
	pkmn.changeStat(pkmn, "attack", det);
	return true;
}

bool XDefense()
{
	if (pkmn.p_XDefenseNum <= 0)
	{
		cout << "Out of X Defenses!\n\n";
		next;
		return false;
	}

	cout << "Used an X Defense!\n\n";
	pkmn.p_XDefenseNum--;
	next;

	if (pkmn.p_defenseLevel >= 6)
	{
		cout << pkmn.p_name << " 's defense won't go any higher!\n\n";
		next;
		return true;
	}

	det = (pkmn.p_defenseLevel == 5) ? 1 : 2;
	pkmn.changeStat(pkmn, "defense", det);
	return true;
}

bool bag()
{
	while (true)
	{
		cout << "1.Potion (x" << pkmn.p_potionNum << ")\n";
		cout << "2.Ether (x" << pkmn.p_etherNum << ")\n";
		cout << "3.X Attack (x" << pkmn.p_XAttackNum << ")\n";
		cout << "4.X Defense (x" << pkmn.p_XDefenseNum << ")\n";
		cout << "5.Back\n\n";
		cin >> det;
		system("cls");
		if (det == 1 || det == 2 || det == 3 || det == 4 || det == 5) break;
	}

	switch (det)
	{
		case 1:
			if (potion())
				return true;
			break;

		case 2:
			if (ether())
				return true;
			break;

		case 3:
			if (XAttack())
				return true;
			break;

		case 4:
			if (XDefense())
				return true;
			break;

		case 5:
			return false;
	}
}