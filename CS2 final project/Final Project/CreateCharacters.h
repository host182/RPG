#ifndef createcharacter_h
#define createcharacter_h
#include "CreateSpells.h"
#include "CreateItems.h"
#include "Character.h"

/////////////////////////////////////
//non ally, hostile characters
// Hydra monster 
int aa[4] = { 2,2,2,2 };
vector<spell* > monsterSpell1(1, &M1);
vector<item*> monsterItem1(1, &red_potion);		////there are some consumables as items for characters, they should be a part of the enemy party once the party is formed
character hydra("Hydra", aa, monsterSpell1, monsterItem1, 0, 1);


//long monster name
int bb[4] = { 3,3,3,3 };
vector<spell* > monsterSpell2(1, &F2);
vector<item*> monsterItem2(1, &blue_potion);
character Long_name("Thing with a name so long that there is no possible way to print it in this program", bb, monsterSpell2, monsterItem2, 0, 1);

// Jabberwocky 
int cc[4] = { 4,4,4,4 };
vector<spell* > monsterSpell3(1, &M2);
vector<item*> monsterItem3(1, &Slimy_Armor);
character Jabberwocky("Jabberwocky ", cc, monsterSpell3, monsterItem3, 0, 1);

// Laywers 
int dd[4] = { 5,5,5,5 };
vector<spell* > monsterSpell4(1, &F3);
vector<item*> monsterItem4(1, &Gloves_of_bashing);
character Lawyers("Lawyers", dd, monsterSpell4, monsterItem4, 0, 1);

//squidzilla
int ee[4] = { 6,6,6,6 };
vector<spell* > monsterSpell5(1, &M3);
vector<item*> monsterItem5(1, &Helm_of_Helms);
character Squidzilla("Squidzilla", ee, monsterSpell5, monsterItem5, 0, 1);

// Crawling hand
int ff[4] = { 7,7,7,7 };
vector<spell* > monsterSpell6(1, &F4);
vector<item*> monsterItem6(1, &Staff_of_Infection);
character Crawling_Hand("Crawling Hand", ff, monsterSpell6, monsterItem6, 0, 1);

//Matthew Bell 
int gg[4] = { 8,8,8,8 };
spell* pointB4 = &B4;
item* ptr7 = &Dragon_Balls;
vector<spell* > monsterSpell7(1, pointB4);
vector<item*> monsterItem7(1, ptr7);
character Matt_bell("Matthew Bell", gg, monsterSpell7, monsterItem7, 0, 1);

// The Deadline for this project. 
int hh[4] = { 9,9,9,9 };
spell* pointM4 = &M4;
item* ptr8 = &red_potion;
vector<spell* > monsterSpell8(1, pointM4);
vector<item*> monsterItem8(1, ptr8);
character Deadline("The Deadline for this Project", hh, monsterSpell8, monsterItem8, 0, 1);




//////////////////////////////////////////////////////////////////////////////////
//allies
vector<spell*> noSpells;

//Grummle
int ii[4] = { 2,0,0,0 };
vector<item*> AllyItem1(1, &red_potion);
character Grummle("Grummle", ii, noSpells, AllyItem1, 1, 0);

//Blue Knight
int jj[4] = { 0,2,0,0 };
vector<item*> AllyItem2(1, &blue_potion);
character Blue_Knight("Blue Knight", jj, noSpells, AllyItem2, 1, 0);

//Jinyu
int kk[4] = { 0,0,2,0 };
vector<item*> AllyItem3(1, &red_potion);
character Jinyu("Jinyu", kk, noSpells, AllyItem3, 1, 0);

//Trogg 
int ll[4] = { 0,0,0,3 };
vector<item*> AllyItem4(1, &blue_potion);
character Trogg("Trogg", ll, noSpells, AllyItem4, 1, 0);

//Sayaadi
int mm[4] = { 4,0,0,0 };
vector<item*> AllyItem5(1, &red_potion);
character Sayaadi("Sayaadi", mm, noSpells, AllyItem5, 1, 0);

//Your Mother
int nn[4] = { 0,5,0,0 };
vector<item*> AllyItem6(1, &blue_potion);
character Your_Mother("Your Mother", nn, noSpells, AllyItem6, 1, 0);

//Murloc
int oo[4] = { 0,0,0,4 };
vector<item*> AllyItem7(1, &red_potion);
character Murloc("Murloc", oo, noSpells, AllyItem7, 1, 0);

//Mulan
int pp[4] = { 5,3,2,1 };
vector<item*> AllyItem8(1, &blue_potion);
character Mulan("Mulan", pp, noSpells, AllyItem8, 1, 0);

//Mogu
int qq[4] = { 0,8,0,0 };
vector<item*> AllyItem9(1, &red_potion);
character Mogu("Mogu", qq, noSpells, AllyItem9, 1, 0);

//Manid
int rr[4] = { 5,5,2,4 };
vector<item*> AllyItem10(1, &blue_potion);
character Manid("Manid", rr, noSpells, AllyItem10, 1, 0);

#endif