#ifndef item_h
#define item_h
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class item {
public:
	string name;
	string description;


	virtual void describeMe() = 0;
	virtual string getEffect() = 0;
	virtual double getValue() = 0;
	virtual int* getItemStat() = 0;
};



class consumable : public item
{
private:
	string effect;							//effect should only be health, mana , damage or defence
	double value;							//value for defence, 0 < d <= 1, it determines the percent of damage blocked
public:
	consumable(string n, string d, string e, double v);

	void describeMe();

	string getEffect();
	double getValue();
	
	int* getItemStat();

};



class statItem :public item
{
private:
	int gains[7];
	string nameOFStats[7] = { "Constitution","Strength","Intelligence","Willpower","Charisma","Alacrity","Armor" };
public:
	statItem(string n, string d, int g[]);

	void describeMe();

	int* getItemStat();

	string getEffect();
	double getValue();
};

#endif