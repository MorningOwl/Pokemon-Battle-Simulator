#pragma once

enum GameState { CLASSIC, MULTIPLAYER, ENDLESS, CAMPAIGN };
enum ID { BULBASAUR, CHARMANDER, SQUIRTLE, PIDGEY, RATTATA, SPEAROW, ODDISH };
enum Type { _, NORMAL, GRASS, FIRE, WATER, POISON, FLYING, GROUND };
enum Move { NONE, TACKLE, GROWL, SCRATCH, TAILWHIP, SANDATTACK, GUST, PECK, ABSORB, GROWTH };
enum Effect { PHYSICAL, STATUS };


class Pokemon
{
	public:
		const char* p_name;
		ID p_ID;
		Type p_type1, p_type2;
		const char* p_type1Name;
		const char* p_type2Name;
		int p_level = 5;

		int p_numMoves = 2;
		Move p_moveID[5];
		Effect p_moveEffect[5];
		Type p_moveType[5];
		const char* p_moveName[5];

		int p_movePP[5], p_movePPMax[5];

		int p_HP, p_HPMax;
		int p_attack, p_attackMax, p_attackInitial;
		int p_defense, p_defenseMax, p_defenseInitial;
		int p_speed, p_speedMax, p_speedInitial;

		double p_accuracy = 1;
		double p_evasion = 1;

		int p_attackLevel = 0;
		int p_defenseLevel = 0;
		int p_accuracyLevel = 0;
		int p_evasionLevel = 0;

		int p_potionNum = 1, p_etherNum = 1;
		int p_XAttackNum = 1, p_XDefenseNum = 1;

		void initPokemon(ID Name);
		void initMoves();

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

		void changeStat(Pokemon &target, const char* stat, int det);

		double stab(Type moveType);
		double typeDamage(Pokemon &foe, Type moveType);
		double modifier(Pokemon &foe, Type moveType);
		double damage(Pokemon &foe, int power, Type moveType);

		void logMove(const char* move, int num, bool nextLine = true);
		void logName();
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