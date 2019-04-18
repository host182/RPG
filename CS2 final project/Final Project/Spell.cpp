#include "Spell.h"

spell::spell(string n, string d, string e, string t, int v, double ac, int m, int a, int l)
{
	name = n, description = d, effect = e, value = v, manaRequired = m, area = a, spellLevel = l, target = t, accuracy = ac;
}

string spell::getEffect() { return effect; }

int spell::getValue() { return value; }
int spell::getMana() { return manaRequired; }
int spell::getArea() { return area; }
string spell::getName() { return name; }
string spell::getTarget() { return target; }
double spell::getAccuracy() { return accuracy; }
int spell::getSpellLevel() { return spellLevel; }

bool spell::useSpell(bool isAlly)
{
	if (isAlly)
	{
		if ("a" == target)
			return 1;
	}
	else
	{
		if ("e" == target)
			return 1;
	}
	return 0;
}

void spell::describeSpell()
{
	cout << name << endl << "Effect type: " << effect << endl << description << endl << "Effects : ";
	if (target == "a")
		cout << "allies";
	else if (target == "e")
		cout << "enemies";
	else if (target == "s")
		cout << "self";
	else if (target == "ga")
		cout << "all allies";
	else
		cout << "all enemies";
	cout << endl << effect << " : " << abs(value) << endl << "Area : " << area << endl << "Accuracy : " << accuracy << endl << "Mana required: " << manaRequired << endl;
}