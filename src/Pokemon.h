#pragma once
#include <string>

enum GameMode { MENU, CLASSIC, MULTIPLAYER, ENDLESS, CAMPAIGN };
enum PID { BULBASAUR, CHARMANDER, SQUIRTLE, PIDGEY, RATTATA, SPEAROW, ODDISH };
enum Type { _, NORMAL, GRASS, FIRE, WATER, POISON, FLYING, GROUND };
enum MID { NONE, TACKLE, GROWL, SCRATCH, TAILWHIP, SANDATTACK, GUST, PECK, ABSORB, GROWTH };
enum Effect { PHYSICAL, SPECIAL, STATUS, DAMAGE };


class Move
{
	public:
		MID m_ID = NONE;
		Effect m_effect;
		Type m_type;
		const char* m_name;
		int m_PP, m_PPMax;
};


class Pokemon
{
	public:
		//Definitive Stats
		const char* p_name;
		PID p_ID;
		Type p_type1, p_type2;
		const char* p_type1Name;
		const char* p_type2Name;
		int p_level = 5;

		int p_numMoves = 2;
		Move p_move[5];

		//Variable Stats
		int p_HP, p_HPMax;
		int p_attack, p_attackMax, p_attackInitial;
		int p_defense, p_defenseMax, p_defenseInitial;
		int p_spAttack, p_spAttackMax, p_spAttackInitial;
		int p_spDefense, p_spDefenseMax, p_spDefenseInitial;
		int p_speed, p_speedMax, p_speedInitial;

		double p_accuracy = 1;
		double p_evasion = 1;

		int p_attackLevel = 0;
		int p_defenseLevel = 0;
		int p_spAttackLevel = 0;
		int p_spDefenseLevel = 0;
		int p_accuracyLevel = 0;
		int p_evasionLevel = 0;
		
		//Initialization
		void initPokemon(PID Name);
		void initMoves();

		//Moves
		void move1(Pokemon &pkmn, Pokemon &foe);
		void move2(Pokemon &pkmn, Pokemon &foe);
		void move3(Pokemon &pkmn, Pokemon &foe);
		void move4(Pokemon &pkmn, Pokemon &foe);

		void tackle(Pokemon &foe);
		void growl(Pokemon &foe);
		void scratch(Pokemon &foe);
		void tailWhip(Pokemon &foe);
		void sandAttack(Pokemon &foe);
		void gust(Pokemon &foe);
		void peck(Pokemon &foe);
		void absorb(Pokemon &foe);
		void growth(Pokemon &pkmn);

		//Dependencies
		void changeStat(Pokemon &target, const char* stat, int det);

		double stab(Type moveType);
		double typeDamage(Pokemon &foe, Type moveType);
		double modifier(Pokemon &foe, Type moveType);
		double damage(Pokemon &foe, int power, Type moveType, Effect moveEffect);

		void operator=(Pokemon pkmn);		//Update these whenever updating 
		bool operator==(Pokemon pkmn);		//Pokemon attributes

		void refresh();
};


/*
	~~~ADDING NEW POKEMON~~~
	-Add name to ID enum
	-Add stats to initPokemon()
	-Add option to selection screen


	~~~ADDING NEW MOVES~~~
	-Add name to Move enum
	-Add function to Moves.cpp
	-Add stats to initMoves()
	-Add name to inidividual move functions
*/