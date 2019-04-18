#ifndef createspells_h
#define createspells_h
#include "Spell.h"
#include <vector>

using std::vector;

//////////////////////////////////////////
//Fighter spells
//Spell flighter 2
//name = "Throw Shuriken"
//description = "A ranged attack that throws a damaging shuriken at an enemy character"
//effect = "Damage"
//target = 'e'
//value = 40
//accuracy = 1
//manaRequired = 15
//area = 1
//levelsRequired = 2
spell F2("Throw Shuriken", "A ranged attack that throws a damaging shuriken at an enemy character", "Damage", "e", 40, 1, 15, 1, 2);
//
//Spell  fighter 3
//name = "Slash"
//description = "A close range attack that uses a sword to attack three enemy characters"
//effect = "Damage"
//target = 'e'
//value = 40 3
//accuracy = 0.75
//manaRequired = 15
//area = 3
//levelsRequired = 3
spell F3("Slash", "A close range attack that uses a sword to attck three enemy characters", "Damage", "e", 40, 0.75, 20, 3, 3);
//
//Spell  fighter 4
//name = "Rampage"
//description = "Filled with the power of beasts the only thing on your mind is Destruction"
//effect = "Damage"
//target = 'e'
//value = 100
//accuracy = 0.60
//manaRequired = 30
//area = 3
//levelsRequired = 4
spell F4("Rampage", "Filled with the power of beasts the only thing on your mind is Destruction", "Damage", "e", 100, 0.60, 30, 3, 4);

spell* fighterSpells[3] = { &F2,&F3,&F4 };


////////////////////////////////////////////
//Mage spells
//Spell Mage 1
//name = "Fireball";
//description = "Land fireballs at the enemy";
//effect = "Damage";
//target = "e";
//int value = 50;
//accuracy = 0.7;
//manaRequired = 15;
//area = 1;
//levelsRequired = 1;
spell M1("Fireball", "Land fireballs at the enemy", "Damage", "e", 50, 0.7, 15, 1, 1);

//Spell Mage 2
//name = "Blizzard"
//description = "Cause a Storm and freeze the  2 enemies"
//effect = "Damage"
//target = 'e'
//value = 70
//accuracy = 0.9
// manarequired = 20
//area = 2
//levels required = 2
spell M2("Blizzard", "Cause a Storm and freeze the  2 enemies", "Damage", "e", 70, 0.9, 20, 2, 2);

//Spell Mage 3
//name = "Light of the Goddess"
//description = "Heals all allies in the party a little "
//effect = "Heal"
//target = 'ga'
//value = 50
//accuracy = 1
// manarequired = 30
//area = 0
//levels required = 3
spell M3("Light of the Goddess", "Heals all allies inthe party a little ", "Heal", "ga", 50, 1, 30, 0, 3);

//Spell  Mage 4
//name = "Earthquake"
//description = "Shake the Earth and give damage to 6 enemies"
//effect = "Damage"
//target = 'e'
//value = 80
//accuracy = .70
// manarequired = 30
//area = 6
//levels required = 4
spell M4("Earthquake", "Shake the Earth and give damage to 6 enemies", "Damage", "e", 80, .7, 30, 6, 4);

spell* mageSpells[4] = { &M1,&M2,&M3,&M4 };


////////////////////////////////////////////
//Rogue spells
//Spell Rouge 2
//name = "Barrier"
//description = "Increases the user's Defence by 100%"
//effect = " Defence Buff"
//target = 's'
//value = 1
//accuracy = 1
// manarequired = 30
//area = 1 
//levels required = 2
spell R2("Barrier", "Increases the user's defence by a 100%", "Buff Defence", "s", 1, 1, 30, 1, 2);

//Spell Rouge 3
//name = "foulplay"
//description = "Increases the user's damage by a 100%"
//effect = "Buff"
//target = 's'
//value = 1
//accuracy = 1
// manarequired = 30
//area = 1 
//levels required = 3
spell R3("Foulplay", "Increases the user's damage by a 100%", "Buff Damage", "s", 1, 1, 30, 1, 3);

spell* rogueSpells[2] = { &R2,&R3 };


////////////////////////////////////////////
//Bard spells
//Spell Bard 2
//name = "Simple Tune"
//description = "Increases the party's Defence by a 75%"
//effect = " Defence Buff"
//target = 'ga'
//value = .75
//accuracy = 1
// manarequired = 35
//area = 0
//levels required = 2
spell B2("Simple Tune", "Increases the party's Defence by a 75%", "Buff Defence", "ga", 1, .75, 30, 0, 2);

//Spell Bard 2
//name = "Rhythmic Beats"
//description = "Increases the party's Damage by a 75%"
//effect = "Buff Damage"
//target = 'ga'
//value = .75
//accuracy = 1
// manarequired = 35
//area = 0
//levels required = 3
spell B3("Rhythmic Beats", "Increases the party's Damage by a 75%", "Buff Damage", "ga", 1, .75, 30, 0, 3);

//Spell Bard 4
//name = "Angel Hum"
//description = "Heals all members in your party by alot"
//effect = "Heal"
//target = 'ga'
//value = 1
//accuracy = 1
// manarequired = 40
//area = 0
//levels required = 4
spell B4("Angel Hum", "Heals all members in your party by alot", "Heal", "ga", 1, 1, 100, 0, 4);

spell* bardSpells[3] = { &B2,&B3,&B4 };


spell** allSpells[4] = { fighterSpells,mageSpells,rogueSpells,bardSpells };

#endif