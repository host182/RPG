#include "Item.h"


//functions for consumable
consumable::consumable(string n, string d, string e, double v)
{
	name = n, description = d, effect = e, value = v;
}

void consumable::describeMe()
{
	cout << name << endl << description << endl << effect << endl << effect << " : " << value << endl;
}

string consumable::getEffect() { return effect; }
double consumable::getValue() { return value; }

int* consumable::getItemStat()
{
	int a[7] = { 0,0,0,0,0,0,0 };
	return a;
}


//functions for statItem
statItem::statItem(string n, string d, int g[])
{
	name = n, description = d;
	for (int i = 0; i < 7; i++)
		gains[i] = g[i];
}

void statItem:: describeMe()
{
	cout << name << endl << description << endl;
	for (int i = 0; i < 7; i++)
		if (gains[i] != 0)
			cout << nameOFStats[i] << " +" << gains[i] << endl;
}

int* statItem::getItemStat()
{
	return gains;
}

string statItem::getEffect() { return ""; }
double statItem::getValue() { return 0; }