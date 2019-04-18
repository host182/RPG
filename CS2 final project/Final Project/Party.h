#ifndef party_h
#define party_h
#include "Character.h"
#include "Item.h"
#include "Spell.h"

using std::cin;

class party
{
private:
	vector<vector<item *> >partyItems;		//This is a mixture of stats items and consumables
	vector<character*> partyCharacter;
	vector<item*> emptyItems;
public:
	party() {}
	party(vector<vector<item*> > i, vector<character*> p);
	bool consumeItem(item* ITEM, character* ch);
	void dropItem(int i, int j, int number);
	bool grabItems(item* ITEM);
	bool addCharacter(character* c);
	void removeCharacter(character* c);
	vector<vector<item*> >getItem();
	vector<character*> getPartyCharacter();
	vector<item*> dropItemsAfterDeath();
};

#endif