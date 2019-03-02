#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
#include "Dependencies.h"

#define next system("pause"); system("cls")

using namespace std;

GameMode mode = MENU;
Pokemon pkmn, foe;
int det, det1, det2;

void ClassicMode();
void EndlessMode();
void CampaignMode();


int main()
{
	while (true)
	{
		while (true)
		{
			cout << "************************\n";
			cout << "POKEMON BATTLE SIMULATOR\n";
			cout << "************************\n\n";
			cout << "Choose a game mode:\n\n1.CLASSIC\n2.ENDLESS\n\n";
			cin >> det;
			system("cls");
			if (det == 0) exit(EXIT_SUCCESS);
			if (det == 1 || det == 2 || det == 9999) break;
		}

		switch (det)
		{
			case 1:
				mode = CLASSIC;
				ClassicMode();
				break;

			case 2:
				mode = ENDLESS;
				EndlessMode();
				break;

			case 9999:
				mode = CAMPAIGN;
				CampaignMode();
		}
	}
}

bool win(Pokemon foe)
{
	if (foe.p_HP <= 0)
	{
		cout << foe.p_name << " fainted!\n\n", next;
		return true;
	}
	return false;
}

//MENUS
int fight(Pokemon &foe)
{
	switch (pkmn.p_numMoves)
	{
		case 1:
			while (true)
			{
				logMove(pkmn, pkmn.p_move[1].m_name, 1);
				cout << "\n2.Info...\t\t3.Back\n\n";
				cin >> det;
				system("cls");
				if (det >= 1 && det <= 3) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 2:
					logMoveInfo(pkmn, pkmn.p_move[1]);
					next;
			}
			return 0;

		case 2:
			while (true)
			{
				logMove(pkmn, pkmn.p_move[1].m_name, 1, false);
				cout << "2." << pkmn.p_move[2].m_name << " (" << pkmn.p_move[2].m_PP << "/" << pkmn.p_move[2].m_PPMax << ")\n\n";
				cout << "3.Info...\t\t4.Back\n\n";
				cin >> det;
				system("cls");
				if (det >= 1 && det <= 4) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 3:
					logMoveInfo(pkmn, pkmn.p_move[1]);
					logMoveInfo(pkmn, pkmn.p_move[2]);
					next;
			}
			return 0;

		case 3:
			while (true)
			{
				logMove(pkmn, pkmn.p_move[1].m_name, 1, false);
				cout << "2." << pkmn.p_move[2].m_name << " (" << pkmn.p_move[2].m_PP << "/" << pkmn.p_move[2].m_PPMax << ")\n";
				logMove(pkmn, pkmn.p_move[3].m_name, 3); cout << endl;
				cout << "4.Info...\t\t5.Back\n\n";
				cin >> det;
				system("cls");
				if (det >= 1 && det <= 5) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 3:
					pkmn.move3(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 4:
					logMoveInfo(pkmn, pkmn.p_move[1]);
					logMoveInfo(pkmn, pkmn.p_move[2]);
					logMoveInfo(pkmn, pkmn.p_move[3]);
					next;
			}
			return 0;

		case 4:
			while (true)
			{
				logMove(pkmn, pkmn.p_move[1].m_name, 1, false);
				cout << "2." << pkmn.p_move[2].m_name << " (" << pkmn.p_move[2].m_PP << "/" << pkmn.p_move[2].m_PPMax << ")\n";
				logMove(pkmn, pkmn.p_move[3].m_name, 3, false);
				cout << "4." << pkmn.p_move[4].m_name << " (" << pkmn.p_move[4].m_PP << "/" << pkmn.p_move[4].m_PPMax << ")\n\n";
				cout << "5.Info...6.Back\n\n";
				cin >> det;
				system("cls");
				if (det >= 1 && det <= 6) break;
			}

			switch (det)
			{
				case 1:
					pkmn.move1(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 2:
					pkmn.move2(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 3:
					pkmn.move3(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 4:
					pkmn.move4(pkmn, foe);
					if (win(foe))
					{
						if (mode == ENDLESS)
							return 2;
						return-1;
					}
					return 1;

				case 5:
					logMoveInfo(pkmn, pkmn.p_move[1]);
					logMoveInfo(pkmn, pkmn.p_move[2]);
					logMoveInfo(pkmn, pkmn.p_move[3]);
					logMoveInfo(pkmn, pkmn.p_move[4]);
					next;
			}
			return 0;
	}
}

void stats()
{
	cout << pkmn.p_name << endl;
	if (pkmn.p_type2 == NONE) cout << pkmn.p_type1Name << endl;
	else cout << pkmn.p_type1Name << ", " << pkmn.p_type2Name << endl;
	cout << "Level: " << pkmn.p_level << endl;
	cout << "Health: " << pkmn.p_HP << endl;
	cout << "Attack: " << pkmn.p_attack << endl;
	cout << "Defense: " << pkmn.p_defense << endl;
	cout << "Sp. Atk: " << pkmn.p_spAttack << endl;
	cout << "Sp. Def: " << pkmn.p_spDefense << endl;
	cout << "Speed: " << pkmn.p_speed << "\n\n";
	next;
}

//ITEMS
bool potion()
{
	if (pkmn.p_potionNum <= 0)
	{
		cout << "Out of potions!\n\n", next;
		return false;
	}

	if (pkmn.p_HP == pkmn.p_HPMax)
	{
		cout << "HP is already full!\n\n", next;
		return false;
	}

	cout << "Used a potion!\n\n", next;
	pkmn.p_potionNum--;

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
		cout << "Out of ethers!\n\n", next;
		return false;
	}

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
				pkmn.p_etherNum--;
				
				if (pkmn.p_move[i].m_PP < pkmn.p_move[i].m_PPMax - 5)
					pkmn.p_move[i].m_PP += 10;
				else
					pkmn.p_move[i].m_PP = pkmn.p_move[i].m_PPMax;

				return true;
			}
		}
	}
}

bool XAttack()
{
	if (pkmn.p_XAttackNum <= 0)
	{
		cout << "Out of X Attacks!\n\n", next;
		return false;
	}

	cout << "Used an X Attack!\n\n", next;
	pkmn.p_XAttackNum--;

	if (pkmn.p_attackLevel >= 6)
	{
		cout << pkmn.p_name << " 's attack won't go any higher!\n\n", next;
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
		cout << "Out of X Defenses!\n\n", next;
		return false;
	}

	cout << "Used an X Defense!\n\n", next;
	pkmn.p_XDefenseNum--;

	if (pkmn.p_defenseLevel >= 6)
	{
		cout << pkmn.p_name << " 's defense won't go any higher!\n\n", next;
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
		cout << "4.X Defense (x" << pkmn.p_XDefenseNum << ")\n\n";
		cout << "5.Info...\n";
		cout << "6.Back\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= 6) break;
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
			cout << "Potion:    A spray-type medicine for treating wounds. It can be used to restore\n           20 HP to an injured Pokemon.\n\n";
			cout << "Ether:     This medicine can restore 10 PP to a single selected move that has been\n           learned by a Pokemon.\n\n";
			cout << "X Attack:  An item that sharply boosts the Attack stat of a Pokemon during battle.\n           It wears off once the Pokemon is withdrawn.\n\n";
			cout << "X Defense: An item that sharply boosts the Defense stat of a Pokemon during battle.\n           It wears off once the Pokemon is withdrawn.\n\n";
			next;
			return false;

		case 6:
			return false;
	}
}

//TURNS
int playerTurn(Pokemon &foe)
{
	while (true)
	{
		cout << "******************************\n";
		cout << "Using: "; logName(pkmn);
		cout << "Foe:   "; logName(foe);
		cout << "******************************\n\n";
		cout << "What will " << pkmn.p_name << " do?\n\n";
		cout << "1.Fight\t\t2.Bag\n3.Stats\t\t4.Run\n\n";

		cin >> det;
		system("cls");

		switch (det)
		{
			case 1:
				det = fight(foe);
				if (det == 1) return 1;
				if (det == -1) return -1;
				if (det == 2) return 2;
				break;

			case 2:
				if (bag())
					return 1;
				break;

			case 3:
				stats();
				break;

			case 4:
				if (mode != ENDLESS) 
					cout << "Got away safely!\n\n", next; 
				return -1;
		}
	}
}

int foeTurn(Pokemon &foe)
{
	srand(time(0));
	int prob = 1 + rand() % 20;

	switch (foe.p_numMoves)
	{
		case 1:
			foe.move1(foe, pkmn);
			break;

		case 2:
			if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS))
				if (prob < 11) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS)
				if (prob < 15) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE)
				if (prob < 7) foe.move1(foe, pkmn); else foe.move2(foe, pkmn);
			break;

		case 3:
			if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS))
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS)
				if (prob < 13) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 9) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE)
				if (prob < 5) foe.move1(foe, pkmn); else if (prob < 13) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE)
				if (prob < 9) foe.move1(foe, pkmn); else if (prob < 13) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS)
				if (prob < 9) foe.move1(foe, pkmn); else if (prob < 17) foe.move2(foe, pkmn); else foe.move3(foe, pkmn);
			break;

		case 4:
			if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS))
				if (prob < 6) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 16) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
				if (prob < 12) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 7) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 7) foe.move2(foe, pkmn); else if (prob < 10) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if ((foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE) ||
				(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS))
				if (prob < 6) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 16) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 15) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 13) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
				if (prob < 4) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 18) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
			else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
				if (prob < 8) foe.move1(foe, pkmn); else if (prob < 11) foe.move2(foe, pkmn); else if (prob < 14) foe.move3(foe, pkmn); else foe.move4(foe, pkmn);
	}

	if (pkmn.p_HP <= 0)
	{
		cout << pkmn.p_name << " fainted!\n\n", next;
		return 1;
	}

	return 0;
}

//GAME MODES
void ClassicMode()
{
	while (true)
	{
		cout << "************************\n";
		cout << "POKEMON BATTLE SIMULATOR\n";
		cout << "************************\n\n";
		cout << "What Pokemon will you use?\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
		cin >> det;
		system("cls");
		if (det == 1 || det == 2 || det == 3 || det == 9999) break;
	}

	srand(time(0));
	int prob = 1 + rand() % 2;

	switch (det)
	{
		case 1:
			pkmn.initPokemon(BULBASAUR);
			if (prob == 1) foe.initPokemon(CHARMANDER);
			else foe.initPokemon(SQUIRTLE);
			break;

		case 2:
			pkmn.initPokemon(CHARMANDER);
			if (prob == 1) foe.initPokemon(BULBASAUR);
			else foe.initPokemon(SQUIRTLE);
			break;

		case 3:
			pkmn.initPokemon(SQUIRTLE);
			if (prob == 1) foe.initPokemon(BULBASAUR);
			else foe.initPokemon(CHARMANDER);
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
		if (playerTurn(foe) == -1) break;
		if (foeTurn(foe)) break;
	}

	mode = MENU;
}

void EndlessMode()
{
	int count = 0;

	while (true)
	{
		cout << "************************\n";
		cout << "POKEMON BATTLE SIMULATOR\n";
		cout << "************************\n\n";
		cout << "What Pokemon will you use?\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
		cin >> det;
		system("cls");
		if (det == 1 || det == 2 || det == 3 || det == 9999) break;
	}

	switch (det)
	{
		case 1: pkmn.initPokemon(BULBASAUR); break;
		case 2: pkmn.initPokemon(CHARMANDER); break;
		case 3: pkmn.initPokemon(SQUIRTLE);
	}

	while (true)
	{
		srand(time(0));
		int prob = 1 + rand() % 3;

		switch (prob)
		{
			case 1: foe.initPokemon(BULBASAUR); break;
			case 2: foe.initPokemon(CHARMANDER); break;
			case 3: foe.initPokemon(SQUIRTLE); break;
		}

		cout << "Encountered a " << foe.p_name << "!\n\n", next;

		while (true)
		{
			det = playerTurn(foe);

			if (det == 2)
			{
				count++;
				break;
			}

			if (det == -1)
			{
				while (true)
				{
					cout << "Are you sure you want to quit?\n\n";
					cout << "1.Yes\n2.No\n\n";
					cin >> det1;
					system("cls");
					if (det1 == 1 || det1 == 2) break;
				}

				if (det1 == 1)
				{
					cout << "You defeated " << count << " Pokemon!\n\n", next;
					mode = MENU;
					return;
				}
			}

			if (det1 != 2 && foeTurn(foe))
			{
				cout << "You lost!\n\n", next;
				cout << "You defeated " << count << " Pokemon!\n\n", next;
				mode = MENU;
				return;
			}
		}
	}
}

void CampaignMode()
{
	Pokemon Pkmn[7], rival;

	while (true)
	{
		cout << "Choose your starting Pokemon:\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= 3) break;
	}

	switch (det)
	{
		case 1: Pkmn[1].initPokemon(BULBASAUR); rival.initPokemon(CHARMANDER); break;
		case 2: Pkmn[1].initPokemon(CHARMANDER); rival.initPokemon(SQUIRTLE); break;
		case 3: Pkmn[1].initPokemon(SQUIRTLE); rival.initPokemon(BULBASAUR);
	}

	pkmn = Pkmn[1];

	cout << "Your rival chose " << rival.p_name << "!\n\n", next;

	while (true)
	{
		if (playerTurn(rival) == -1) break;
		if (foeTurn(rival)) break;
	}
}