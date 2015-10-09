#include <string>

using namespace std;

int upOrDown();

string epithet(int personNumber);

void dramaticPause();

//this is how you leave the game
void leaveGame();

void armyGainMoney(int team, int money);

void getSaveArmy(int team);

void getArmyPeopleSaves(int team);

void newArmy(int team);

void saveArmy(int team);

void getSave();

void savegame();

//Assigns the names of the prestiges
void assignPrestige(); 

void prestige();

void assignParagon(); 

void paragon();

void assignRenown();

void renown();

void levelUp();

void assignStartingMana();
	


//if someone wins, this will send the final information from the game to a text file
void infodump(); 

void moreRandom();

//Assigns the race names to each guy
void assignRace();

//Assigns birthright names
void assignBirthRight(); 

//Assigns the class names to each guy
void assignClass(); 

void arcaneSummonerManaStream(); 

//range 3 mana 15 turns 2
void mageProtectRanged();

//15 mana, blocks defense/2 for 2 rounds
void mageShield(); 

//the slow spell lasts 1 round 10 mana
void mageSlow(); 

void mageBlink(); 

//the haste spell lasts 2 rounds 5 mana
void mageHaste(); 

void mageIceTouch();

//fireball 2d4 with 1d4 splash + 50% to add attack
void mageFireBall(); 

void magePoison();

//range 7 damage: d4  mana:5  steals life
void mageLeech();

//mage minor missile spell 3d2 range 10
void mageMinorMissile(); 

//mage missile spell 5d2 range 7
void mageMissile();

//range 1  mana 5  raise burn by 1 to 3
void mageIgnite();

//range 1  mana 5  raise freeze by 1 to 3
void mageFreeze(); 

//range 1 mana 10 raise enchant by 1
void enchantWeaponOther(); 

//repulse pushes back all enemies that are within 2
void mageRepulse();

//random spell between freeze, ignite, fireball, and ice touch. mana 7
void forceOfNature();

//list of spells for the mage
void mageSpells();

void mageSpellsArcaneSummoner();

void mageSpellsWater();

void mageSpellsFire();

//opposite of poison, moves counter by d4,   mana: 8   range: 3
void druidHealingBalm();

void druidBearForm(); 

void druidWolfForm(); 

void druidHawkForm(); 

void druidSnakeForm(); 

void druidNormalForm(); 

//mana 5
void spellswordEnchantWeapon(); 

void necromancerBloodToMana();

void necromancerDeathChannel();

void earthQuake(); 

void warlockSpells();

void druidSpells(); 

void necromancerSpells(); 

void spellswordSpells(); 

void goblinMageSpells(); 

void goblinPriestHeal(); 

void goblinPriestSpells();

void clericLightningStrike();

//this is where the cleric heal spell is stored d8+4 and heals poison
void clericHeal();

//list of spells for the cleric
void clericSpells(); 

//this is where the priest heal spell is stored d6+2 mana 8
void priestHeal();

//list of spells for the priest and mounted pally
void priestSpells();

void acolyteCurse(); 

void acolyteBless();

void acolyteRevive(); 

void acolyteSpells(); 

void learnBirthrights(); 

void learnRaces(); 

//descriptions of the classes, and shows their base stats
void learnClasses(); 

//this is going to be the menu where player 1 can see their characters 
void menuFuncTeam1(); 

//this is going to be the menu where player 2 can see their characters
void menuFuncTeam2();

void spellDescriptions();

//this'll be where the rule book will go
void menuFuncRules();

void buyXP(int team); 

//the player 1 menu table of contents
void menuFuncPlayer1(); 

//the player 2 menu table of contents
void menuFuncPlayer2();

void miraculous();

void lichTransformation();

void checkDisengage();

void checkDefend();

void checkBloodlust();

void checkInspire();

//this checks if they get to charge
void checkCharge();

//this checks if they get to bullrush
void checkBullrush();

//checks if they are a spellsword with an enchanted weapon
void checkEnchantWeapon();

void poisonDamages();

void burnDamages();

void checkCrit();

void checkNewPoison();

void checkHold();

//colours might only work on linux
void mapInitialDisplay1();

//colours might only work in linux
void mapInitialDisplay2();


void showMapElevation();

void assignMapElevation();

void showMapRange();

//displays the map
void showMap();

//this'll make people move
void move();

//puts the people on the map 
void placement();

//This is what fills out the beginning character sheets
void fillStats();

void familiar();

void playerPlopper(int plopTeam1, int plopTeam2, int plopTeam3, int plopTeam4);

// this is the beginning character creation part 
void newGameFunc();

//the title page for the game 
void titleFunc();

void attack();

void dragonSpawnBreath();

void vampireDrain(); 

void Throw(); 

void bound();

void rage(); 

void berserkerSkills(); 

void cripple(); 

void backstab();

void daze();

void healingBalm();

void doubleShot();

void scoutSkills();

void aimedShot(); 

void piercingShot(); 

void archerSkills();

void pushBack(); 

void axeThrow(); 

void fighterSkills();

void paladinSmite();

void paladinSpells();
  
int teamKillXP(int team);
 
//checks if one team is all dead, then congratulates the winner, doles out gold,
bool checkWin();
     
//this is the turn function
void turn();

void updateGamePlayInTerminal();

int main(int argc, char** argv);


