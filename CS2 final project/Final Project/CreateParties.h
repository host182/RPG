#ifndef createparty_h
#define createparty_h
#include "CreateCharacters.h"
#include "Party.h"

party e1() {
	// party for loc 1
	vector<vector<item*> >partyItems1(3);
	partyItems1[1].push_back(&red_potion);
	partyItems1[1].push_back(&blue_potion);
	partyItems1[2].push_back(&Dragon_Balls);

	vector<character* > partyCharacters1(1);
	partyCharacters1[0] = &hydra;

	party enemy1(partyItems1, partyCharacters1);
	return enemy1;
}
party e2() {
	//party for loc 2
	vector<vector<item*> >partyItems2(2);
	partyItems2[1].push_back(&blue_potion);

	vector<character* > partyCharacters2;
	character* h1 = &hydra;

	partyCharacters2.push_back(h1);
	party enemy2(partyItems2, partyCharacters2);
	return enemy2;
}

party e3() {
	//party for loc 3 
	vector<item* > filler;
	vector<vector<item*> >partyItems3;
	item *sb = &strength_booster;
	for (int i = 0; i < 1; i++)
		partyItems3.push_back(filler);
	partyItems3[1].push_back(sb);
	vector<character* > partyCharacters3;
	character* LN = &Long_name;
	partyCharacters3.push_back(LN);
	party enemy3(partyItems3, partyCharacters3);
	return enemy3;
}
party e4() {
	// party for loc 4 
	vector<item* > filler;
	vector<vector<item*> >partyItems4;
	item *r2 = &red_potion;
	for (int i = 0; i < 1; i++)
		partyItems4.push_back(filler);
	partyItems4[1].push_back(r2);
	vector<character* > partyCharacters4;
	character* jab = &Jabberwocky;
	character* h3 = &hydra;
	partyCharacters4.push_back(jab);
	partyCharacters4.push_back(h3);
	party enemy4(partyItems4, partyCharacters4);
	return enemy4;
}
party e5() {
	/// party for loc 5 
	vector<item* > filler;
	vector<vector<item*> >partyItems5;
	item *d1 = &defence_booster;
	for (int i = 0; i < 1; i++)
		partyItems5.push_back(filler);
	partyItems5[1].push_back(d1);
	vector<character* > partyCharacters5;
	party enemy5(partyItems5, partyCharacters5);
	return enemy5;
}
party e6() {
	//party for loc 6 
	vector<item* > filler;
	vector<vector<item*> >partyItems6;
	item *sm = &Sneaky_Mask;
	for (int i = 0; i < 1; i++)
		partyItems6.push_back(filler);
	partyItems6[1].push_back(sm);
	vector<character* > partyCharacters6;
	character* jab = &Jabberwocky;
	character* Law1 = &Lawyers;
	partyCharacters6.push_back(jab);
	partyCharacters6.push_back(Law1);
	party enemy6(partyItems6, partyCharacters6);
	return enemy6;
}
party e7() {
	// party for loc 7 
	vector<item* > filler;
	vector<vector<item*> >partyItems7;
	item *sb2 = &strength_booster;
	for (int i = 0; i < 1; i++)
		partyItems7.push_back(filler);
	partyItems7[1].push_back(sb2);
	vector<character* > partyCharacters7;
	character* squid = &Squidzilla;
	partyCharacters7.push_back(squid);
	party enemy7(partyItems7, partyCharacters7);
	return enemy7;
}
party e8() {
	// party for loc 8 
	vector<item* > filler;
	vector<vector<item*> >partyItems8;
	item *db2 = &Dragon_Balls;
	for (int i = 0; i < 1; i++)
		partyItems8.push_back(filler);
	partyItems8[1].push_back(db2);
	vector<character* > partyCharacters8;
	character* LN2 = &Long_name;
	character* CH = &Crawling_Hand;
	partyCharacters8.push_back(LN2);
	partyCharacters8.push_back(CH);
	party enemy8(partyItems8, partyCharacters8);
	return enemy8;
}
party e9() {
	// party for loc 9 
	vector<item* > filler;
	vector<vector<item*> >partyItems9;
	item *db3 = &Dragon_Balls;
	for (int i = 0; i < 1; i++)
		partyItems9.push_back(filler);
	partyItems9[1].push_back(db3);
	vector<character* > partyCharacters9;
	character* dead = &Deadline;
	character* matt = &Matt_bell;
	partyCharacters9.push_back(dead);
	partyCharacters9.push_back(matt);
	party enemy9(partyItems9, partyCharacters9);
	return enemy9;
}

#endif