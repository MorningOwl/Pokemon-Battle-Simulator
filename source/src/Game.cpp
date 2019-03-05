#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Pokemon.h"
#include "Dependencies.h"
#include "Maps.h"

#define next system("pause"); system("cls")

using namespace std;

Player player(16, 30);
char key = 'x';

GameMode mode;
Pokemon foe;
Pokemon rival;

int det, det1, det2;

void ClassicMode();
void EndlessMode();
void CampaignTest();
void CampaignMode();


int main()
{
	while (true)
	{
		while (true)
		{
			mode = MENU;
			cout << "************************\n";
			cout << "POKEMON BATTLE SIMULATOR\n";
			cout << "************************\n\n";
			cout << "Choose a game mode:\n\n1.CLASSIC\n2.ENDLESS\n\n";
			cin >> det;
			system("cls");
			if (det == 0) exit(EXIT_SUCCESS);
			if (det == 1 || det == 2 || det == 9999 || det == 1111) break;
		}

		switch (det)
		{
		case 1:
			ClassicMode();
			break;

		case 2:
			EndlessMode();
			break;

		case 9999:
			mode = CAMPAIGN;
			CampaignTest();
			break;

		case 1111:
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
	bool temp;

	while (true)
	{
		for (int i = 1; i <= player.pkmn.p_numMoves; i++)
		{
			temp = (i % 2 == 0) ? true : false;
			logMove(player.pkmn, player.pkmn.p_move[i].m_name, i, temp);
		}

		if (player.pkmn.p_numMoves % 2 != 0) cout << endl;
		cout << endl << player.pkmn.p_numMoves + 1 << ".Info...\t\t";
		cout << player.pkmn.p_numMoves + 2 << ".Back\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= player.pkmn.p_numMoves + 2) break;
	}

	for (int i = 1; i <= player.pkmn.p_numMoves; i++)
		if (det == i)
		{
			player.pkmn.move(i, player.pkmn, foe);
			if (win(foe))
			{
				if (mode == ENDLESS)
					return 2;
				return-1;
			}
			return 1;
		}

	if (det == player.pkmn.p_numMoves + 1)
	{
		for (int i = 1; i <= player.pkmn.p_numMoves; i++)
			logMoveInfo(player.pkmn, player.pkmn.p_move[i]);
		next;
	}

	return 0;
}

bool bag()
{
	while (true)
	{
		for (int i = 1; i <= player.numItems; i++)
			cout << i << "." << player.bag[i].i_name << " (x" << player.bag[i].i_num << ")\n";

		cout << endl << player.numItems + 1 << ".Info...\n";
		cout << player.numItems + 2 << ".Back\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= player.numItems + 2) break;
	}

	for (int i = 1; i <= player.numItems; i++)
		if (det == i)
		{
			if (player.item(i, foe))
				return true;
			break;
		}

	if (det == player.numItems + 1)
	{
		for (int i = 1; i <= player.numItems; i++)
			player.logItemInfo(player.bag[i]);
		next;
	}

	return false;
}

void stats()
{
	cout << player.pkmn.p_name << endl;
	if (player.pkmn.p_type2 == NONE) cout << player.pkmn.p_type1Name << endl;
	else cout << player.pkmn.p_type1Name << ", " << player.pkmn.p_type2Name << endl;
	cout << "Level: " << player.pkmn.p_level << endl;
	cout << "Health: " << player.pkmn.p_HP << endl;
	cout << "Attack: " << player.pkmn.p_attack << endl;
	cout << "Defense: " << player.pkmn.p_defense << endl;
	cout << "Sp. Atk: " << player.pkmn.p_spAttack << endl;
	cout << "Sp. Def: " << player.pkmn.p_spDefense << endl;
	cout << "Speed: " << player.pkmn.p_speed << "\n\n";
	next;
}

bool switchPokemon()
{
	while (true)
	{
		for (int i = 1; i <= player.numPkmn; i++)
			cout << i << "." << player.Pkmn[i].p_name << endl;
		cout << endl << player.numPkmn + 1 << ".Back\n\n";
		cin >> det;
		system("cls");
		if (det == player.numPkmn + 1) return false;
		if (det >= 1 && det <= player.numPkmn) break;
	}

	player.Pkmn[0] = player.pkmn;
	player.pkmn = player.Pkmn[det];
	return true;
}

//TURNS
int playerTurn(Pokemon &foe)
{
	while (true)
	{
		cout << "******************************\n";
		cout << "Using: "; logName(player.pkmn);
		cout << "Foe:   "; logName(foe);
		cout << "******************************\n\n";
		cout << "What will " << player.pkmn.p_name << " do?\n\n";
		if (mode == CAMPAIGN) cout << "1.Fight\t\t2.Bag\n3.Pokemon\t4.Run\n\n";
		else cout << "1.Fight\t\t2.Bag\n3.Stats\t\t4.Run\n\n";

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
			if (mode == CAMPAIGN && switchPokemon()) return 1;
			else if (mode != CAMPAIGN) stats();
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
		foe.move(1, foe, player.pkmn);
		break;

	case 2:
		if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS))
			if (prob < 11) foe.move(1, foe, player.pkmn); else foe.move(2, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS)
			if (prob < 15) foe.move(1, foe, player.pkmn); else foe.move(2, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE)
			if (prob < 7) foe.move(1, foe, player.pkmn); else foe.move(2, foe, player.pkmn);
		break;

	case 3:
		if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS))
			if (prob < 8) foe.move(1, foe, player.pkmn); else if (prob < 15) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS)
			if (prob < 13) foe.move(1, foe, player.pkmn); else if (prob < 17) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS)
			if (prob < 5) foe.move(1, foe, player.pkmn); else if (prob < 17) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE)
			if (prob < 5) foe.move(1, foe, player.pkmn); else if (prob < 9) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE)
			if (prob < 5) foe.move(1, foe, player.pkmn); else if (prob < 13) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE)
			if (prob < 9) foe.move(1, foe, player.pkmn); else if (prob < 13) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS)
			if (prob < 9) foe.move(1, foe, player.pkmn); else if (prob < 17) foe.move(2, foe, player.pkmn); else foe.move(3, foe, player.pkmn);
		break;

	case 4:
		if ((foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS))
			if (prob < 6) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 16) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
			if (prob < 12) foe.move(1, foe, player.pkmn); else if (prob < 15) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 15) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 7) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 7) foe.move(2, foe, player.pkmn); else if (prob < 10) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if ((foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE) ||
			(foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS))
			if (prob < 6) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 16) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == STATUS)
			if (prob < 8) foe.move(1, foe, player.pkmn); else if (prob < 15) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == DAMAGE)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
			if (prob < 8) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 13) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == STATUS && foe.p_move[2].m_effect == DAMAGE && foe.p_move[3].m_effect == DAMAGE && foe.p_move[4].m_effect == STATUS)
			if (prob < 4) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 18) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
		else if (foe.p_move[1].m_effect == DAMAGE && foe.p_move[2].m_effect == STATUS && foe.p_move[3].m_effect == STATUS && foe.p_move[4].m_effect == DAMAGE)
			if (prob < 8) foe.move(1, foe, player.pkmn); else if (prob < 11) foe.move(2, foe, player.pkmn); else if (prob < 14) foe.move(3, foe, player.pkmn); else foe.move(4, foe, player.pkmn);
	}

	if (player.pkmn.p_HP <= 0)
	{
		cout << player.pkmn.p_name << " fainted!\n\n", next;
		return 1;
	}

	return 0;
}

//GAME MODES
void ClassicMode()
{
	mode = CLASSIC;
	player.initPlayer(mode);
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
		player.pkmn.initPokemon(BULBASAUR);
		if (prob == 1) foe.initPokemon(CHARMANDER);
		else foe.initPokemon(SQUIRTLE);
		break;

	case 2:
		player.pkmn.initPokemon(CHARMANDER);
		if (prob == 1) foe.initPokemon(BULBASAUR);
		else foe.initPokemon(SQUIRTLE);
		break;

	case 3:
		player.pkmn.initPokemon(SQUIRTLE);
		if (prob == 1) foe.initPokemon(BULBASAUR);
		else foe.initPokemon(CHARMANDER);
	}

	if (det == 9999)
	{
		while (true)
		{
			cout << "Choose your Pokemon:\n\n";
			cout << "1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n4.PIDGEY\n5.RATTATA\n6.SPEAROW\n7.ODDISH\n8.GEODUDE\n9.PIKACHU\n10.BIDOOF\n\n";
			cin >> det;
			system("cls");
			if (det >= 1 && det <= 10) break;
		}

		switch (det)
		{
		case 1: player.pkmn.initPokemon(BULBASAUR); break;
		case 2: player.pkmn.initPokemon(CHARMANDER); break;
		case 3: player.pkmn.initPokemon(SQUIRTLE); break;
		case 4: player.pkmn.initPokemon(PIDGEY); break;
		case 5: player.pkmn.initPokemon(RATTATA); break;
		case 6: player.pkmn.initPokemon(SPEAROW); break;
		case 7: player.pkmn.initPokemon(ODDISH); break;
		case 8: player.pkmn.initPokemon(GEODUDE); break;
		case 9: player.pkmn.initPokemon(PIKACHU); break;
		case 10: player.pkmn.initPokemon(BIDOOF); break;
		}

		while (true)
		{
			cout << "Choose your opponent:\n\n";
			cout << "1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n4.PIDGEY\n5.RATTATA\n6.SPEAROW\n7.ODDISH\n8.GEODUDE\n9.PIKACHU\n10.BIDOOF\n\n";
			cin >> det;
			system("cls");
			if (det >= 1 && det <= 10) break;
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
		case 8: foe.initPokemon(GEODUDE); break;
		case 9: foe.initPokemon(PIKACHU); break;
		case 10: foe.initPokemon(BIDOOF); break;
		}
	}

	while (true)
	{
		if (playerTurn(foe) == -1) break;
		if (foeTurn(foe)) break;
	}
}

void EndlessMode()
{
	mode = ENDLESS;
	player.initPlayer(mode);
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
	case 1: player.pkmn.initPokemon(BULBASAUR); break;
	case 2: player.pkmn.initPokemon(CHARMANDER); break;
	case 3: player.pkmn.initPokemon(SQUIRTLE);
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
					return;
				}
			}

			if (det1 != 2 && foeTurn(foe))
			{
				cout << "You lost!\n\n", next;
				cout << "You defeated " << count << " Pokemon!\n\n", next;
				return;
			}
		}
	}
}

void CampaignTest()
{
	while (true)
	{
		cout << "Choose your starting Pokemon:\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= 3) break;
	}

	switch (det)
	{
	case 1: player.Pkmn[1].initPokemon(BULBASAUR); rival.initPokemon(CHARMANDER); break;
	case 2: player.Pkmn[1].initPokemon(CHARMANDER); rival.initPokemon(SQUIRTLE); break;
	case 3: player.Pkmn[1].initPokemon(SQUIRTLE); rival.initPokemon(BULBASAUR);
	}

	player.pkmn = player.Pkmn[1];

	cout << "Your rival chose " << rival.p_name << "!\n\n", next;

	while (true)
	{
		if (playerTurn(rival) == -1) break;
		if (foeTurn(rival)) break;
	}

	player.pkmn.refresh();
	srand(time(0));

	for (int i = 0; i < 3; i++)
		while (true)
		{
			int prob = 1 + rand() % 4;
			switch (prob)
			{
			case 1:foe.initPokemon(PIDGEY); break;
			case 2:foe.initPokemon(RATTATA); break;
			case 3:foe.initPokemon(SPEAROW); break;
			case 4:foe.initPokemon(ODDISH); break;
			}

			cout << "Encountered a wild " << foe.p_name << "!\n\n", next;

			while (true)
			{
				if (playerTurn(foe) == -1) break;
				if (foeTurn(foe)) break;
			}
		}
}


//CAMPGIGN MODE

void displayMap();
void getUserInput();

void CheckForWildPokemon();
void WildPokemonBattle();


void CampaignMode()
{
	mode = CAMPAIGN;
	player.initPlayer(mode);

	while (true)
	{
		cout << "Choose your first Pokemon:\n\n1.BULBASAUR\n2.CHARMANDER\n3.SQUIRTLE\n\n";
		cin >> det;
		system("cls");
		if (det >= 1 && det <= 3) break;
	}

	switch (det)
	{
	case 1: player.pkmn.initPokemon(BULBASAUR); break;
	case 2: player.pkmn.initPokemon(CHARMANDER); break;
	case 3: player.pkmn.initPokemon(SQUIRTLE);
	}

	player.Pkmn[1] = player.pkmn;

	while (true)
	{
		displayMap();
		getUserInput();
	}
}


void displayMap()
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (player.y == y && player.x == x)
				cout << char(2);

			else if (map[y][x] == 1)
				cout << "_";

			else if (map[y][x] == 3)
				cout << "|";

			else if (map[y][x] == 4)
				cout << "#";

			else if (map[y][x] == 6)
				cout << "P";

			else if (map[y][x] == 0)
				cout << " ";
		}

		cout << endl;
	}
}

void getUserInput()
{
	cin >> key;
	system("cls");

	switch (key)
	{
	case 'w':
		if (map[player.y - 1][player.x] % 2 == 0)
			player.y--;
		break;

	case 's':
		if (map[player.y + 1][player.x] % 2 == 0)
			player.y++;
		break;


	case 'a':
		if (map[player.y][player.x - 1] % 2 == 0)
			player.x--;
		break;

	case 'd':
		if (map[player.y][player.x + 1] % 2 == 0)
			player.x++;
	}

	CheckForWildPokemon();

	if (map[player.y][player.x] == 6)
	{
		cout << "You found a potion!\n\n", next;
		for (int i = 1; i <= player.numItems; i++)
			if (player.bag[i].i_ID == POTION)
			{
				player.potions = true;
				break;
			}

		if (!player.potions)
		{
			player.numItems++;
			player.bag[player.numItems].i_ID = POTION;
			player.bag[player.numItems].i_name = "Potion";
			player.bag[player.numItems].i_num = 1;
			player.potions = true;
		}

		else
			for (int i = 1; i <= player.numItems; i++)
				if (player.bag[i].i_ID == POTION)
				{
					player.bag[i].i_num++;
					break;
				}
	}
}

void CheckForWildPokemon()
{
	srand(time(0));
	int prob = 1 + rand() % 4;

	if (map[player.y][player.x] == 4 && prob == 1)
		WildPokemonBattle();
}

void WildPokemonBattle()
{
	srand(time(0));
	int prob = 1 + rand() % 5;

	switch (prob)
	{
	case 1:foe.initPokemon(PIDGEY); break;
	case 2:foe.initPokemon(RATTATA); break;
	case 3:foe.initPokemon(GEODUDE); break;
	case 4:foe.initPokemon(PIKACHU); break;
	case 5:foe.initPokemon(BIDOOF); break;
	}

	cout << "Encountered a wild " << foe.p_name << "!\n\n", next;

	while (true)
	{
		if (playerTurn(foe) == -1) break;
		if (player.battleEnd) { player.battleEnd = false; break; }
		cout << "Wild ";
		if (foeTurn(foe)) break;
	}
}