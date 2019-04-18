#ifndef spell_h
#define spell_h
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class spell
{
private:
	string name;						//name of the spell
	string description;					//description of the spell
	string effect;						//Damage, Heal, Buff Damage or Buff Defence
	int value;							//value of the effect

	int manaRequired;					//mana required
	////////////////////////////////
	//for global spells, area = 0
	int area;							//number of characters that are effected 
	string target;						//target can be 'a' for allies, 'e' for enemies, 's' for self, 'ga' for all alies and 'ge' for all enemies
	double accuracy;
	int spellLevel;
public:
	spell(string n, string d, string e, string t, int v, double ac, int m, int a, int l);

	//since I haven't added the setters, we cannot individually change the variables after we make the spell
	string getEffect();
	int getValue();
	int getMana();
	int getArea();
	double getAccuracy();
	string getName();
	string getTarget();
	bool useSpell(bool isAlly);
	int getSpellLevel();

	void describeSpell();
};

#endif