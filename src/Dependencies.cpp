#include "Dependencies.h"
#include <iostream>
#include <string>

#define next system("pause"); system("cls")

using namespace std;


void logMove(Pokemon pkmn, const char* move, int num, bool nextLine)
{
	string space = "";
	
	for (int i = strlen(move); i <= 11; i++)
		space += " ";

	cout << num << "." << pkmn.p_move[num].m_name << " (" << pkmn.p_move[num].m_PP << "/" << pkmn.p_move[num].m_PPMax << ")" << space;
	if (nextLine) cout << "\n"; else cout << "\t";
}

void logName(Pokemon pkmn)
{
	string space = "";

	for (int i = strlen(pkmn.p_name); i < 17; i++)
		space += " ";

	cout << pkmn.p_name << space << pkmn.p_HP << "/" << pkmn.p_HPMax << endl;
}

void logMoveInfo(Pokemon pkmn, Move move)
{
	string space = "";
	int longest = 0;

	for (int i = 1; i <= pkmn.p_numMoves; i++)
		if (strlen(pkmn.p_move[i].m_name) > longest)
			longest = strlen(pkmn.p_move[i].m_name);

	for (int i = strlen(move.m_name); i < longest; i++)
		space += " ";

	cout << move.m_name << ": " << space;

	switch (move.m_ID)
	{
		case TACKLE:
			cout << "A physical attack in which the user charges and slams into the target\n        " << space << "with its whole body.\n\n";
			break;

		case GROWL:
			cout << "The user growls in an endearing way, making the opposing Pokemon less\n       " << space << "wary. This lowers their Attack stat.\n\n";
			break;

		case SCRATCH:
			cout << "Hard, pointed, sharp claws rake the target to inflict damage.\n\n";
			break;

		case TAILWHIP:
			cout << "The user wags its tail cutely, making the opposing Pokemon less wary\n           " << space << "and lowering their Defense stat.\n\n";
			break;

		case SANDATTACK:
			cout << "Sand is hurled in the target's face, reducing the target's accuracy.\n\n";
			break;

		case GUST:
			cout << "A gust of wind is whipped up by wings and launched at the target to\n      " << space << "inflict damage.\n\n";
			break;

		case PECK:
			cout << "The target is jabbed with a sharply pointed beak or horn.\n\n";
			break;

		case ABSORB:
			cout << "A nutrient-draining attack. The user's HP is restored by half the\n        " << space << "damage taken by the target.\n\n";
			break;

		case GROWTH:
			cout << "The user's body grows all at once, raising the Attack and Special\n        " << space << "Attack stats.\n\n";
			break;
	}
}