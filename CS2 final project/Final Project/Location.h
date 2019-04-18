#ifndef location_h
#define location_h
#include "Party.h"

class location
{
private:
	int ID;
	string name;
	vector<character*> singleCharacters;
	vector<item*> itemsOnTheFloor;
	party* locationGuardians;
	vector<int> escapes;
	bool isVisited;
public:
	location(){}
	location(string n, int d,vector<character*> s, vector<item*> i, party* l, vector<int> e, bool v)
	{
		name = n, ID = d, singleCharacters = s, itemsOnTheFloor = i, locationGuardians = l, escapes = e, isVisited = v;
	}

	vector<character*> getLocationCharacters() { return singleCharacters; }
	vector<item*> getLocationItems() { return itemsOnTheFloor; }
	party* getGuardians() { return locationGuardians; }
	vector<int> getEscapes() { return escapes; }
	bool getVisits() { return isVisited; }
	void iWasHere() { isVisited = true; }

	void describeLocation()
	{
		cout << name << endl << "Number in the map : " << ID << endl << "Characters in this location : " << endl;
		for (int i = 0; i < singleCharacters.size(); i++)
			cout << "\t" << singleCharacters[i]->name << endl;
		cout << "Enemy party in this location has : " << endl;
		vector<character*> enemies = locationGuardians->getPartyCharacter();
		for (int i = 0; i < enemies.size(); i++)
			cout << enemies[i]->name << endl;
		for (int i = 0; i < escapes.size(); i++)
			cout << "Locations you can go to : " << escapes[i] << "  ";
		cout << endl;
	}
};

#endif