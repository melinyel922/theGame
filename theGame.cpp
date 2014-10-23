// Ben Gallogly
// May 11, 2014

//Today's date Ooctober 23, 2014

//receive from u of m with  	scp gall0478@lind40-40.cselabs.umn.edu:/home/gall0478/bdgameBest.cpp .
//send to u of m account with   scp bdgameBest.cpp gall0478@lind40-40.cselabs.umn.edu:.
//open u of m account with    	ssh gall0478@lind40-40.cselabs.umn.edu


//g++ -std=c++11 bdgameBest.cpp -o play


//adjust screen brightness with this
	//xrandr --output LVDS1 --brightness 0.6
	// (the 0.6 gets replaced with the value that you want)
	

//anydice.com is good for finding probablility
// https://www.gifbooster.com/wp-content/uploads/3143/goat-licking_67.gif
// http://24.media.tumblr.com/451b75b10b80860dc41b130a14629204/tumblr_mghsozrDeO1qdlh1io1_400.gif
// http://s3-ec.buzzfed.com/static/2014-08/25/18/enhanced/webdr10/anigif_enhanced-27625-1409006100-1.gif
// http://gifsoup.com/view/1223653/goat-licking-electric-fence.html
// https://i.chzbgr.com/maxW500/7046791424/hB52ED41E/
// telnet towel.blinkenlights.nl



//finish these things	
	//birthright descriptions
	//renown descriptions
	//paragon descriptions
	//using armies
		//saving them
			//rewriting old characters with the newer version, but not getting rid of characters that just weren't used that round.
		//more info on the overall army
			//0 using, 1money, 2maxpop, 3slot, 4number of battles won, 5battles lost, 6best winning streak, 7worst losing streak, 8characters lost
	//make ice touch a better format, have it use attack()
	//playtest paragons
	



//glitchy things
	//game exiting oddly, waits until end of round
	//if you enter the class description page, or the race descriptions page, it skips the race selection
	//range gets a little messed up for melee if on a hill, they can attack too far.
	//dramaticPause does it all at once, and then spews all the text rather than waiting
	//unleash infinite loops if it finishes off the last enemy
	
	





//possible ideas
	

	//armies can get to buy special abilities
		//buy them before a battle to use in the battle
		//maybe 10 regular abilities, and then special ones only if you have a person of a certain prestige in play
		//some that are only useable if you have a certain prestige in play
		//make some of them scaleable with the level of the prestige person being used
			//mass bless (your whole team starts blessed)
			//meteor strike (random damage throughout game)
			//poison cloud (chance for enemies to get poisoned)
			//firestorm (chance for enemies to get burned)
			//blizzard (chance for enemies to get frozen)
			//mana block (enemies don't regen mana at first)
			//slope (raises one end of the battlefield and lowers the other)
			//sharp weapons (everyone on your team attack+1)
			//randomly blink everyone once in a while
			//acid (weaker than poison, but damages armor)
			//mist (raises evasion by like 2)
			//thunderstorm (random lightening strikes, wind pushes people, arrows less accurate)
			//icy ground (move-1, chance to fall over)
	//add army medals or awards for certain things
		//teabagging, not losing a character in a 3 on 3, winning 100 games
	//add character medals or awards for certain things
		//instant kill, perfect strike (roll a 12v1), double kill, triple kill,
	//when you get one of the above medals, your army gets some bonus money as well
	//character permanant scarring from major damage
	


	//more cinematic deaths customized based on the killer
		//figure out their weapon
		//pick one of a few sentences that work with it, and have some verbs or something in there that can also change
		//change based on the attacker's health
		//change based on percent of total health the damage was
		//have a string that checks how each character dies, and in the hall of heroes put that line in
			//"Flynn the nimble crossbowman of conflagration sets aloft a bolt that shimmers in the air for a second before striking Drake the backstabbing assassin of vitriol"
	//add a respawning game option, first to 20 kills wins
		//would need an algorithm to prevent spawn camping
			//or when they spawn they get to do their move first 
		//show some kind of kd spread
		//show who killed who most
	//a stagger start where the next person only comes out after someone dies
	//character speed determines attack turns (maybe just attack order? )
	//spell to slow mana regen (or boost it)
	//make it so that if you put the wrong input in it will give an eror message and ask you to repeat it
		//or on the rangeDisplayMap have it display numbers for each range category
	//multiple choices for map sizes
	//map conditions
		//also, make maps a double array full of objects, instead of a 3d array
			//for movement for now, check your starting and ending tile, if either limit movement, then it will happen
			//if in water at start of turn, cut burn in half (check before doing burn damage
			//functions for tile class
				//isPassable
				//isPlayerHere
				//getCondition (water,mana boost, healing, thorns)
				//getConditionValue (water depth, boost amount, thorns damage)
				//getElevation
				//getGold
				//getItem (in the future maybe)
				//isBurnable?
			//have inheritence
				//trees would be a subclass
				//trees/bushes/walls would have health
		//some passable conditions
			//grassy->standard
			//lumpy grass->chance to stumble and lose 6 ap
			//rocky->move-1 attack-1 defense-1 evasion-2 (unless a dwarf)
			//smooth stone->(dwarf attack+1)
			//undergrowth->move-1 attack-1 defense-1 evasion-2 (unless an elf) (hobbits and dwarves gain +2 evasion)
			//shallow water->move-1
			//deep water->move-1 attack-2 evasion-5 defense-1
			
	
	//ability to hit certain body parts
		//make classes
		//injuries can lower stats
		//people can be left/right handed
		//when healed, can fix some of this (but on average, not all)
		//death blow incorporates the injured area
		//hitting an injured area does more
		//hitting armor does less
		//better accuracy raises chance to hit more vital areas
		//different chances to hit
			//fingers are hard to hit, as are ears, forearms are easy to hit
			//make sure to skip if missing
				//can't heal if missing
			//different damage needed to remove limbs vs ears
		//different effects if major damage is done
		//if an arm is removed, so is their hand and fingers
		
			
	
	
	
	//some kind of prestiges for each race
		//human
			//gains extra money for army every game (10% extra)
			//raise a stat point
		//wood elf
			//resist poison and move + 2
			//increase damage if an archer
		//high elf
			//resist debuffs (curse, slow, )
			//starting mana + 5
		//dark elf
			//dark sphere spell (can't fire out or in it, full round) 
			//gains double money for kills
		//hill dwarf
			//resist cold and poison
			//can't be double attacked
		//mountain dwarf
			//resist fire and poison
			//can't be moved by force or spell
		//halfling
			//gets healed extra by others
			//bonus money found on ground (50% bonus)
		//orc
			//health+10
			//defense+1 health+5
		//centaur
			//can't be charged against
			
	
	//siege machine
		//certain races can use better
		//give it piercing for full damage if ballista and high accuracy, give it splash at half damage if catapult and less accurate(possible burn damage?)
		//make the stats proportional based on average level of players
		
	//other skills
		//engineering
			//Xeach level increases cooldown decrement by 5
			//at level 1 increases move by 1, Xincreases range by 5
			//at level 2 Xincreases damage, Xdoubles accuracy
			//at level 3 Xcan use a contested siege machine
			//at level 4 Xincreases damage
			//at level 5 special bonus based on machine (flaming, bouncing, increase splash radius, etc)
	
	//inventory 
		//  make an object, each character has slots for the objects, such as dude[personNumber].setRightHand(foundWeapon) 
		//  the objects will have a stat saying where they can be equipped
		//  make an algorythm that generates them (maybe look in 'dark alliance' manual for modifiers like shoddy, steel, etc)
			//should include enchanted weapons, like fiery, or icy, or holy
		//  weapon stats look like "longsword +5/-3" meaning it raises the initial attack by 5, but will do 3 less damage
		//  weapon stats might be "name:steel longsword, attack:5, damage/-3, accuracy:-5"
		//  armor stats look like "breastplate -2/+3" meaning you have a higher chance to be hit, but will do less damage
		//  armor stats might be "name:steel breastplate, attack avoidance:-2, damage block:+3, evasion:-5"
		//  stats can include a die roll "falchion +3/1d4-1"
			//maybe the die roll ones are only for the enchanted ones
		//  include a stat that says type of enchantment damage, in case they have resistance
		//  somehow people can upgrade
		//  would need to give characters starting equipment
		//  need to make sure scouts/mages and stuff can't use full plate
		
		//  weapon and armor bonuses do not get multiplied by different bonuses
		

		

	
	//special skill that is only unlocked under certain conditions 
		//fighter- survive a perfect attack roll 10x
		//archer- hit target from 20 spaces or more 10x
		//priest- critical heal 3x
		//berserker- first kill of game 10x
		//knight- do charge damage 20x
		//scout- tumble 40x
		//mage- succesfully hitting with all magic missiles 5x
		//warlock- roll for a 3/2 regen 100x

	//possible future classes or prestiges
			//fighter prestige- gladiator
			//priest prestige- zealot
			//knight prestige- cavalier
			//
			
			//arcane archer
				//prestige for archer
				//flaming arrow
				//icy arrow
				//homing arrow
				//armor piercing arrow
			//monk
				//possibly make this a class, and have bard, trickster, and shadow dancer be the prestiges
				//high evade, low defense
				//can choose 1-4 attacks on a turn, with different amounts of damage.
					//ie: if atttack stat = 8 then: 1 attack @ 12, 2 attacks @ 6, 3 attacks @ 4, 4 attacks @ 3.
				//daze
				//tumble dodge
			//shadow dancer
				//high attack
				//high evade
				//really low defense
				//blinks (maybe a blink to random enemy?)
					//ability with cool down, not a spell
				//weak vs smite
				//chance to blink upon a death blow
			//bard
				//worse attack than monk
				//raise attacks
				//healing balm
				//speed boost
			//trickster
				//worse damage than monk
				//Daze
				//Blink
				//hologram-makes it look like in 5 places, randomly teleports between the existing holograms after their turn, so you don't know which is real
							//on beginning of turn it tells you which you are so that you may move and attack, other holograms randomly move one space
							//doesn't regen mana while doing this, a destroyed hologram takes 2 turns to come back
				
 			//steam punk
				//melee class
				//10 psi for range 10 attack
				//start with like 10 psi regen
				//instead of mana use built up steam pressure, lower max levels than the magic users
				//when hit by fire, raises psi, ice does the opposite
				//a team-mate's fireball would raise psi a lot more and does no damage
				//renowns
					//goggled-raises chance to hit a bunch (maybe change name to monocled, spectacled)
					//steamy-higher psi regen
				//prestiges
					//sky pirate
						//somewhat poorer melee
						//increases ranged damage
						//paragons
							//sniping
								//uses more steam on longer shots
								//1 psi for each square of range?
								//longer range = higher damage (extra 1/2 damage per square)
								//divide "sectionsAway" by 2 or something, makes it like 2x accurate
							//blunderbussing 
								//range of like 5
								//chooses how big of a blast to do 
									//1 shot->3 psi
									//2 shot->5 psi
									//3 shot->6 psi
									//any more is 2 psi per shot
								//the missed shots can hit neighbouring enemies
					//mech pilot
						//uses psi to move
							//like 5 psi to move on a turn
						//higher defense
						//high psi regen
						//can give psi to other steam punks
						//mortar fire-> aoe attack, range 7, regular damage
						//gattling gun-> fires 10 rounds very fast, 75% of full damage, 90% miss chance
						//tesla coil-> does 5 shocks on random enemies, range 5, 
						//can spend a full round fixing, next turn no problems
						//malfunctions
							//roll d20 every turn (line these up with best being highest)
								//leak, loses 5-20% of max psi
								//jammed piston, can't move
								//targetting jammed, only 1 target this turn
								//gun jammed, no long range this turn
								//targetting error, lower accuracy this turn
								//major leak detected early, going to lose all steam at end of turn
								//explosion, lose 5-10% health
								//surprisingly no problem
						//paragons
							//repairing
								//adds 25% to the malfunction roll
								//small chance to gain health when spending a round fixing
							//overclocking
								//subtracts 25% from malfunction roll
								//all stats are a little higher
								//small chance to gain health when spending a round fixing
					//swashbuckler
						//low defense
						//high evasion
						//purely a melee unit
						//lowest steam regen
						//tumble
						//steam jet-pack-> launches character a certain number of spaces
						//steam blast-> lowers enemy's chance to hit for a turn
						//grappling hook-> can pull an enemy in close
						//paragons
							//nobility
								//better evasion
								//5% more money at the end of each game
							//finesse
								//lower defense
								//better evasion
								//better chance to hit

			
		//possibles future races
			//troll 	-low defense, natural healing, chance to only have 6 ap on a turn
			//minotaur	-defense +1, attack +1, move +1, low evasion, low accuracy, low magic
			//gargoyle	-defense +2, move -1, magic resist, low evasion, chance to shatter if enemy has a perfect roll
			//angel		-defense -1, magic resist, good as priests, weak vs certain attacks
			//spectre	-defense -1, move +1, weak to magic, ignore terrain height change, 10% chance to not be affected by physical attacks?
	
	
	//class, renown, prestige, paragon, epitome?
	
	//Fighter -tomahawking  -overbearing
		//Brawler
			//++bullrushing- gets bullrush, like charge, but much less so
			//++vice grip- increase chance to hold enemy in place
				//Destroyer->very serious, swings in arcs to hit all adjacent enemies (less damage to secondary targets)
				//Brawlmaster->very joking, drink ale to restore health and raise attack for a turn 
		//Defender
			//++nullification-doesn't take bonus damage from magic
			//++fortification- increases power of the defend ability
				//Bastion->all allies get defended, but only half as much (attack-1, defense-2)
				//Bulwark->when attacked, hit the attacker with damage equal to 1/4 of defense (defense-2)
	//Archer  -accurate  -nimble
		//Crossbowman
			//++conflagration- regular attack apply burn
			//++dexterity- 1/4 chance to not use up Ap from reloading
				//Arbalist->stackable 1/2 chance to not use AP to reload (possibly lower some stats also)
				//Runic Bowyer->can choose to equip one of three types of bolts: piercing, exploding, fiery (lower stats also)
		//Longbowman
			//++precision- overall more accurate
			//++piercing- special attack ignores half of armour
				//Ramoth gilead->1% chance for a lucky insta-kill (lower stats)
				//Barrager->additional attack, for 4 total (lower accuracy stat)
	//Priest  -blessed  -miraculous
		//Cleric
			//++healing-heals slightly better
			//++compassion- "coup-de-grace" if enemy is below 10% health, insta kill attack
				//Blitzen-> lowers mana cost of lightning
				//Executioner->either adds "coup-de-grace" (insta kill if below 10%) or makes it so from 11-25% if they deal damage, insta-kill
		//Acolyte
			//++revival- the revive spell has a higher chance or working
			//++blessing- bless spell lasts longer
				//Jacoby->lower max health, mana regen +2
				//Melchizedek->bless hits all allies in range
		//Paladin
			//++holiness-extra mana at the beginning of the game
			//++righteousness-increase smite damage
				//Vindicator->raises attack for each dead ally
				//Rightous fist->for double mana, can roll an additional d12 on smite
	//Berserker  -raging  -sprinting
		//Battlerager
			//++aerobics-if moves twice in a turn, extra move rate
			//++grappling-special attack flips enemy over head, some damage, chance to stun (good for pulling a fighter off a mage)
				//Magerager->10% extra attack against magic users
				//Bladestorm->additional attack, for 4 total (accuracy stat - 15, attack stat - 2)
		//Thumper
			//++bounding-jumps
			//++bloodthirst- bloodlust builds faster
				//Stamford->gains 20% extra defense for each adjacent enemy, defense stat+2, 1% chance to be hit in balls and die
				//Visceral force->evasion + 20, accuracy - 15
	//Knight  -inspiring  -untouchable
		//Lancer
			//++reaching-longer lance (range 3 instead of 2)
			//++expeditedness- charge only needs 4 spaces instead of 5
				//Unstoppable force->if they kill an enemy, can immediately move
				//Exotic lancer->random mount before each battle: horse, wyrm, pegasus, gryphon, basilisk, dragon
		//Mounted paladin
			//++smiting-switch spell list to paladin instead of priest so they gain smite (maybe lower attack too)
			//++shielding-resist magic slightly (they'd be basically the only class with this)
				//Valkyrie->All attacks are holy, attack stat +1
				//Lionheart->adds inspiring range 8. if already inspiring, then increases inspire by d4. recieves double damage from poison
	//Scout  -backstabbing  -dazing
		//Mounted archer
			//++quick-shot- double attack, lower attack a little
			//++split-shot- special attack shoots two people at once (should improve)
				//Ghengis Khan->attack+3 if range 1
				//Chariot archer->accuracy +10
		//Assassin
			//++incapacitation- special attack slows enemy
			//++vitriol- regular attack poisons for 3 instead of 2
				//Boccos-> *WILD CARD*, during an allies turn, will attack an adjacent enemy if enemy is at <10% health
				//Deadly force-> ability to make the poison in an adjacent enemy do all its damage at once, defense-1
		//Ranger
			//++venom- regular attack poisons for 1 or 2
			//++herbs- can use healing balm once every few turns (no mana, like poison but for healing)
				//Blade of the forest-> increase melee attack, decrease ranged attack
				//Forest force->defense+3, double damage from fire
	//Mage  -rapid-fire  -mystic
		//Fire mage
			//++infernos- can cast "ignite" fiery version of poison
			//++repulsion- gains a pushback spell, and fireball does pushback
				//Infernal mage->can cast infernal fireball (more mana, more damage, weak to holy) weak to holy, 
				//Walking flame->ignites adjacent enemies +1 each turn
		//Water mage
			//+frost- can cast "freeze" icy version of poison 
			//+barriers- makes shield spell better
				//Ice mage->always has range protect on, 50% chance to freeze adjacent enemies each turn
				//Runic mage->can place runes, which are map conditions, both buffs and debuffs. Lose some stats. (some kind of synergy with runic bowyer and runic swordsman)
		//Arcane summoner
			//++unbridled power-chance for a mage missile to fire repeatedly erraticly at enemies (untill mana pool is empty, infinite range, random, less mana than normal)
			//++imbuing-expensive weapon enchanting spell (not as efficient as a spellsword)
				//Mana force->50% chance that a physical attack on them doesn't work, and arcane magic restores some mana proportional to damage done
					// (health stat lower, defense stat lower)
				//Archmage->either grants unbridled power, or if they already are, then gives them +50% of max mana pool when unleashing 
					//grant some other kind of spells possibly freeze/ignite,  (health stat lower, defense stat-2, attack stat-1)
	//Warlock  -earthshaking  -animalistic
		//Druid
			//++morphing- turns back into normal form for no mana
			//++nature- force of nature (random effect attack)
				//Mel->either grants animalistic, or turns the wolf into a bear (lower health stat, lower defense stat)
				//Beast->grants a few more forms (some will just be slight differences, such as dire wolf)
		//Necromancer
			//++resurrection-more starting health when revived in lich form
			//++malediction-regular attacks apply curse (curse lowers attack for a few turns)
				//Scourge->attacks do extra against clerics and any other divine spell user, but even weaker to holy
				//Blood necromancer->can use a team-mates health for blood to mana
		//Spellsword
			//++unleashing- higher chance to unleash all weapon enchantments at once
			//++enchanting- if a lvl 1 enchantment, reroll for a higher enchantment
				//Runic swordsman->every turn automatically add another enchantment (mana regen stat -3)
				//Adamantine golem-> (defense stat+5, health stat-25, move-1, evasion-5)
	//Steam punk  -goggled  --steamy
		//Sky pirate
			//Sniping-longer range, more accurate
			//Blunderbussing-multishot blast, chance for missed shots to do splash damage
				//Sky corsair->Improved melee
				//Aerial Privateer->Adds another shot to blunderbussing, or accuracy+1 and attack+1 to sniping
		//Mech pilot
			//Repairing-better malfunction roll
			//Overclocking-better stats, at cost of worse malfunction roll
				//Dreadnaught pilot->(attack+1 defense+1 steam regen+1 evasion-10), uses 8 psi to move instead of 5, worse malfunction roll
				//Mech scout->(attack-1 defense-1 evasion+5) uses 1 psi to move instead of 5
		//Swashbuckler
			//Nobility-better evasion and more money
			//Finesse-much better evasion, and better chance to hit
				//Landsknecht->(attack+2, accuracy-2, range=2)
				//Musketeer->regains a ranged attack, but with lower damage than their melee attack



		
		//current major changes
			
			//make poison, defended, spellcast, etc all part of the "Class" thing, should take super long, like hours
			//familiar is gonna get messed up because of the reorangizing of teams
				//maybe I will need to do the teams as all seperate arrays
				//^^probably not
				//gonna need to have it reassign every thing one space over if there is a familiar
					//move the last one first if team 1
			
			
			

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <math.h>
#include <unistd.h> //sleep
#include <fstream> //read and write files
#include <string> //strings and such
#include <sstream>


//mobileProblem
//#include "src/global.hpp"
//#include "src/factory.h"
#include "bdgameBestClass.hpp"

//mobileProblem
#include "astar.cpp"
#include "dude2.cpp"
#include "map.cpp"


using namespace std;

bool const FAST_START = false;

bool running = 1; //this says the game is on
int playerInfo[20][25]; //first dimension chooses person 0-player1 1-5-player1's team 6-player2 7-20-player2's-team
		       // second dimension 0class, 1attack, 2defense, 3health, 4move, 5range, 6Ap, 7mana, 8number, 9x.pos, 10y.pos, 11xp, 12maxHealth, 13maxMana, 14manaRegen, 15level, 16prestige, 17 race, 18 birthRight, 19 renown, 20 paragon, 21 starting mana, 22 miss chance, 23 evasion, 24 engineering
//!!!declared in global.hpp!!! 
//mobileProblem
int map[100][100][3];//first two dimensions, x and y coords, third dimension [0-person on it or not and who, 1-elevation, 2-map condition
mappy mainMap;
int worldSeed = 0;
int teamSize1 = 0;
int teamSize2 = 0;
dude dude[20];


string teamNames[5];
string winner, loser;
string names[20]; //names of players and characters 
string prestigeNames[20]; //if they prestige, they use these
string renownNames[20]; //if they are renowned, the use these
string paragonNames[20]; //if they are a paragon, they use these
string Class[20]; //class names
string race[20]; //stores the race names
string birthRight[20]; //stores birthright names
int userInput=0;
int range = 0;
int damage = 0;
int mapInitial = 0;
int turnCounter = 1;
int winningTeam = 0; //0=tie, 1=team 1,  2=team 2
int attackTimes[20];


int defended[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int charge[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bullrush[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int spellCast[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int moved[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int poison[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int burn[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int haste[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bless[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int enchantWeapon[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int shield[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int shieldTimer[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int hold[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int protectRangedTimer[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int druidForm[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int needToReload[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int lichForm[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int breathCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int healingBalmCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int drained[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int firstTurn[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int dazeCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int backstabCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int doubleShotCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int boundCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int crippleCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int pushBackCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int throwCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int axeThrowCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int aimedShotCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int piercingShotCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int earthQuakeCoolDown[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dazed[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int initialBlessed[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
bool throwingAxe = 0;
bool dazing = 0;
bool aimingShot = 0;
bool piercing = 0;
bool throwing = 0;
bool pushingBack = 0;
bool backstabbing = 0;
bool doubleShooting = 0;
int doubleShootingFirstTarget = 0;
bool crippling = 0;
int rageDamage = 0;
int smiteDamage = 0;
bool usingForceOfNature = 0;
bool freeMana = 0;
bool moving = 0;
bool attacking = 0;
bool usedSpecial = 0;

int army1[10]; //0:if being used, 1:money, 2:max population, 3:Which save file it is from, 4:wins, 5:losses, 6:ties, 7:win last game?, 8:win streak, 9:lose streak
string armyName1;

int army2[10]; //0:if being used, 1:money, 2:max population, 3:Which save file it is from, 4:wins, 5:losses, 6:ties, 7:win last game?, 8:win streak, 9:lose streak
string armyName2;


int moveGuy = 0, assignGuy = 0, defender = 0;; //to carry the person whose turn it is out of the attack function
								//and to carry the guy getting saved to the saves
								//and to carry who the defender is


//here are the original stats for each of the classes
const int fighter  [1][25] = {1,10,9 ,30,6 ,1 ,12,0 ,0,0,0,0,30,0 ,0,0,0,0,0,0,0,0 ,6 ,2,1};
const int archer   [1][25] = {2,9 ,6 ,30,7 ,20,12,0 ,0,0,0,0,30,0 ,0,0,0,0,0,0,0,0 ,9 ,6,1};
const int priest   [1][25] = {3,7 ,5 ,30,7 ,1 ,12,0 ,0,0,0,0,30,25,5,0,0,0,0,0,0,10,6 ,3,0};
const int berserker[1][25] = {4,15,4 ,40,7 ,1 ,12,0 ,0,0,0,0,40,0 ,0,0,0,0,0,0,0,0 ,10,5,-1};
const int knight   [1][25] = {5,9 ,8 ,30,11,1 ,12,0 ,0,0,0,0,30,0 ,0,0,0,0,0,0,0,0 ,4 ,2,0};
const int scout    [1][25] = {6,11,6 ,30,8 ,1 ,12,0 ,0,0,0,0,30,0 ,0,0,0,0,0,0,0,0 ,4 ,6,1};
const int mage     [1][25] = {7,3 ,5 ,30,5 ,5 ,12,0 ,0,0,0,0,30,25,7,0,0,0,0,0,0,10,5 ,4,0};
const int warlock  [1][25] = {8,6 ,6 ,30,5 ,8 ,12,5 ,0,0,0,0,30,15,6,0,0,0,0,0,0,5 ,5 ,3,0};

string fighterName =	{"Fighter"};
string archerName =		{"Archer"};
string priestName =		{"Priest"};
string berserkerName =	{"Berserker"};
string knightName =		{"Knight"};
string scoutName =		{"Scout"};
string mageName =		{"Mage"};
string warlockName =	{"Warlock"};

string p101 = "Brawler", p102 = "Defender", p201 = "Crossbowman", p202 = "Longbowman", p301 = "Cleric", p302 = "Acolyte", p303 = "Paladin";
string p401 = "Battlerager", p402 = "Thumper", p501 = "Lancer", p502 = "Mounted Paladin", p601 = "Mounted Archer", p602 = "Assassin", p603 = "Ranger";
string p701 = "Fire Mage", p702 = "Water Mage", p703 = "Arcane Summoner";
string p801 = "Druid", p802 = "Necromancer", p803 = "Spellsword";

string r101 = "Tomahawking "; string r102 = "Overbearing "; string r201 = "Accurate "; string r202 = "Nimble ";
string r301 = "Blessed "; string r302 = "Miraculous "; string r401 = "Raging "; string r402 = "Sprinting ";
string r501 = "Inspiring "; string r502 = "Untouchable "; string r601 = "Backstabbing "; string r602 = "Dazing ";
string r701 = "Rapid-fire "; string r702 = "Mystic "; string r801 = "Earthshaking "; string r802 = "Animalistic ";

string par1011 = "Bullrushing", par1012 = "Vice-Grip", par1021 = "Nullification", par1022 = "Fortification";
string par2011 = "Conflagration", par2012 = "Dexterity", par2021 = "Precision", par2022 = "Piercing";
string par3011 = "Healing", par3012 = "Compassion", par3021 = "Revival", par3022 = "Blessing", par3031 = "Holiness", par3032 = "Righteousness";
string par4011 = "Aerobics", par4012 = "Grappling", par4021 = "Bounding", par4022 = "Bloodthirst";
string par5011 = "Reaching", par5012 = "Expeditedness", par5021 = "Smiting", par5022 = "Shielding";
string par6011 = "Quick-Shot", par6012 = "Split-Shot", par6021 = "Incapacitation", par6022 = "Vitriol", par6031 = "Venom", par6032 = "Herbs";
string par7011 = "Infernos", par7012 = "Repulsion", par7021 = "Frost", par7022 = "Barriers", par7031 = "Unbridled-Power", par7032 = "Imbuing";
string par8011 = "Morphing", par8012 = "Nature", par8021 = "Resurrection", par8022 = "Malediction", par8031 = "Unleashing", par8032 = "Enchanting";

//npcs
const int wolf			[1][25] = {101,6 ,7 ,15,9 ,1 ,12,0 ,0,0,0,0,15,0 ,0,0,0,0,0,0,0,0 ,6,4,0};//goherenow, add evasion and miss chance
const int bear			[1][25] = {102,11,6 ,25,5 ,1 ,12,0 ,0,0,0,0,25,0 ,0,0,0,0,0,0,0,0 ,8,2,0};
const int goblinFighter	[1][25] = {103,6 ,10,15,5 ,1 ,12,0 ,0,0,0,0,15,0 ,0,0,0,0,0,0,0,0 ,6,2,0};
const int goblinArcher	[1][25] = {104,4 ,5 ,15,6 ,20,12,0 ,0,0,0,0,15,0 ,0,0,0,0,0,0,0,0 ,8,4,0};
const int stoneGolem	[1][25] = {105,8 ,12,15,4 ,1 ,12,0 ,0,0,0,0,15,0 ,0,0,0,0,0,0,0,0 ,4,0,0};
const int ironGolem		[1][25] = {106,10,12,10,4 ,1 ,12,0 ,0,0,0,0,10,0 ,0,0,0,0,0,0,0,0 ,4,0,0};
const int goblinMage	[1][25] = {107,2 ,5 ,15,4 ,5 ,12,0 ,0,0,0,0,15,15,3,0,0,0,0,0,0,0 ,4,0,0};
const int goblinPriest	[1][25] = {108,4 ,5 ,15,4 ,1 ,12,0 ,0,0,0,0,15,15,3,0,0,0,0,0,0,0 ,4,2,0};
const int giantRat		[1][25] = {109,5 ,5 ,15,5 ,1 ,12,0 ,0,0,0,0,15,0 ,0,0,0,0,0,0,0,0 ,4,5,0};
const int giantBeetle	[1][25] = {110,7 ,9 ,5 ,5 ,1 ,12,0 ,0,0,0,0,5 ,0 ,0,0,0,0,0,0,0,0 ,2,2,0};
const int giantAnt		[1][25] = {111,5 ,9 ,5 ,6 ,1 ,12,0 ,0,0,0,0,5 ,0 ,0,0,0,0,0,0,0,0 ,6,4,0};


int staggerStartSpread[3] = {0,0,0}; //how much they get spread out
int staggerStartBeginningPeople[3] = {0,0,0}; //on a stagger start, how many people to start with.
int staggerStartCounter[3] = {0,0,0}; //counts the stagger start for each team
int staggerStartPreCounter[3] = {0,0,0}; //counts until the second wave gets to come
int staggerStartPreSpread[3] = {0,0,0}; //shows how much the second wave is spread
bool moreDrama = 0; //pauses the game for a second at different points to increase drama.



string wolfName =			{"Wolf"};
string bearName =			{"Bear"};
string goblinFighterName =	{"Goblin fighter"};
string goblinArcherName =   {"Goblin archer"};
string stoneGolemName =		{"Stone golem"};
string ironGolemName =		{"Iron golem"};
string goblinMageName =		{"Goblin mage"};
string goblinPriestName = 	{"Goblin priest"};
string giantRatName =		{"Giant rat"};
string giantBeetleName =	{"Giant beetle"};
string giantAntName =		{"Giant ant"};

//this'll be where the dice rolls get determined
int rd2()  { int d2 = rand() % 2;}
int rd4()  { int d4 = rand() % 4 + 1; }
int rd6()  { int d6 = rand() % 6 + 1; }
int rd8()  { int d8 = rand() % 8 + 1; }
int rd10() { int d10 = rand() % 10 + 1; }
int rd12() { int d12 = rand() % 12 + 1; }
int rd20() { int d20 = rand() % 20 + 1; }
int rd100() { int d100 = rand() % 100 + 1; }

int moreRandomTeam1 = 0, moreRandomTeam2 = 0;
int upOrDown() {int upOrDown = rand() % 3 -1;}

string epithet(int personNumber) {
	string title;
	
	
	if (dude[personNumber].getPrestige() > 0) {
		title = dude[personNumber].getName() + " the " + dude[personNumber].getRenownName() + dude[personNumber].getPrestigeName();
	}
	else {
		title = dude[personNumber].getName() + " the " + dude[personNumber].getRenownName() + dude[personNumber].getCharacterClassName();
	}
	
	if (dude[personNumber].getParagon() > 0) {
		title = title + " of " + dude[personNumber].getParagonName();
	}
	
	return title;
}

string skillAdverbs(int level) {
	string adverbChoice;
	
	if (level < 0) {
		adverbChoice = "terribly";
	}
	else if (level == 0) {
		adverbChoice = "poorly";
	}
	else if (level == 1) {
		adverbChoice = "acceptably";
	}
	else if (level == 2) {
		adverbChoice = "somewhat skillfully";
	}
	else if (level == 3) {
		adverbChoice = "skillfully";
	}
	else if (level == 4) {
		adverbChoice = "adeptly";
	}
	else if (level >= 5) {
		adverbChoice = "masterfully";
	}
		
	
	return adverbChoice;
}

void dramaticPause() {
	if (moreDrama) {
		sleep(2);
	}
}

//colours might only work on linux
void mapInitialDisplay1(int whichCharacter) {
	cout << "\033[34;40m";
	if (whichCharacter == moveGuy) {
		cout << "\033[1;47m";//makes his background white
	}
	switch(mapInitial){
					case 1:
					cout << " F";
					break;
					case 2:
					cout << " A";
					break;
					case 3:
					cout << " P";
					break;
					case 4:
					cout << " B";
					break;
					case 5:
					cout << " K";
					break;
					case 6:
					cout << " S";
					break;
					case 7:
					cout << " M";
					break;
					case 8:
					cout << " W";
					break;
					case 101:
					cout << " w";
					break;
					case 102:
					cout << " b";
					break;
					case 103:
					cout << "Gf";
					break;
					case 104:
					cout << "Ga";
					break;
					case 105:
					cout << "sg";
					break;
					case 106:
					cout << "ig";
					break;
					case 107:
					cout << "Gm";
					break;
					case 108:
					cout << "Gp";
					break;
					case 109:
					cout << "gr";
					break;
					case 110:
					cout << "gb";
					break;
					case 111:
					cout << "ga";
					break;
	}
	
	cout << "\033[0;40m";
	return;
}

//colours might only work in linux
void mapInitialDisplay2(int whichCharacter) {
	cout << "\033[31;40m";
	if (whichCharacter == moveGuy) {
		cout << "\033[1;47m";//makes his background white
	}
	switch(mapInitial){
					case 1:
					cout << " F";
					break;
					case 2:
					cout << " A";
					break;
					case 3:
					cout << " P";
					break;
					case 4:
					cout << " B";
					break;
					case 5:
					cout << " K";
					break;
					case 6:
					cout << " S";
					break;
					case 7:
					cout << " M";
					break;
					case 8:
					cout << " W";
					break;
					case 101:
					cout << " w";
					break;
					case 102:
					cout << " b";
					break;
					case 103:
					cout << "Gf";
					break;
					case 104:
					cout << "Ga";
					break;
					case 105:
					cout << "sg";
					break;
					case 106:
					cout << "ig";
					break;
					case 107:
					cout << "Gm";
					break;
					case 108:
					cout << "Gp";
					break;
					case 109:
					cout << "gr";
					break;
					case 110:
					cout << "gb";
					break;
					case 111:
					cout << "ga";
					break;
	}
	
	cout << "\033[0;40m";
	return;
}


void showMapValues(string type) {
	int x=0, y=0;
	int valueHere = 0;
	int max, min;
	int range;
	
	if (type == "Elevation") {
		max = mainMap.getMaxElevation();
		min = mainMap.getMinElevation();
		range = max - min;
	}
	else if (type == "Divine") {
		max = mainMap.getMaxDivine();
		min = mainMap.getMinDivine();
		range = max - min;
	}
	else if (type == "Arcane") {
		max = mainMap.getMaxArcane();
		min = mainMap.getMinArcane();
		range = max - min;
	}
	
	for ( x = 0; x < 25; x++) {
		for ( y = 0; y <= 50; y++) {
			if (type == "Elevation") {
					valueHere = mainMap.getGridElevation(x,y);
			}
			if (type == "Divine") {
					valueHere = mainMap.getGridDivine(x,y);
			}
			if (type == "Arcane") {
					valueHere = mainMap.getGridArcane(x,y);
			}
			
				if (valueHere == max) {
					cout << "\033[1;36;40m";
				}
				else if (valueHere >= min + (range * 9 / 10)) {
					cout << "\033[35;40m";
				}
				else if (valueHere >= min + (range * 8 / 10)) {
					cout << "\033[1;35;40m";
				}
				else if (valueHere >= min + (range * 7 / 10)) {
					cout << "\033[34;40m";
				}
				else if (valueHere >= min + (range * 6 / 10)) {
					cout << "\033[1;34;40m";
				}
				else if (valueHere >= min + (range * 5 / 10)) {
					cout << "\033[33;40m";
				}
				else if (valueHere >= min + (range * 4 / 10)) {
					cout << "\033[1;33;40m";
				}
				else if (valueHere >= min + (range * 4 / 10)) {
					cout << "\033[32;40m";
				}
				else if (valueHere >= min + (range * 3 / 10)) {
					cout << "\033[1;32;40m";
				}
				else if (valueHere >= min + (range * 2 / 10)) {
					cout << "\033[31;40m";
				}
				else if (valueHere >= min) {
					cout << "\033[1;31;40m";
				}
				
			if (valueHere < 10 && valueHere >= 0) {
				cout << " " << valueHere;
			}
			else {
				cout << valueHere;
			}
			cout << "\033[0;40m";
		}
		cout << endl;
	}	
	
	return;
}

void showMapValuesMenu() {
	int userInput;
	cout << "What kind of map do you wish to see?\n";
	cout << "1:Elevation\n";
	cout << "2:Arcane energy\n";
	cout << "3:Divine energy\n";
	cin >> userInput;
	switch (userInput) {
		case 1:
		showMapValues("Elevation");
		break;
		case 2:
		showMapValues("Arcane");
		break;
		case 3:
		showMapValues("Divine");
		break;
	}
}

void showMapRange() {
	
	{
	int newXpos = 0, newYpos = 0, deltax = 0, deltay = 0;
	int x=0, y=0;
	int deltaxsquared=0;
	int deltaysquared=0;
	
	
		
		
			cout << "                       1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 5\n";
			cout << "   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n";
			for (newXpos=0; newXpos<25; newXpos++) {
				if(newXpos < 10){cout << " " << newXpos;} else {cout << newXpos;}
				for (newYpos=0; newYpos<50; newYpos++) {
					if (moving) {
						
						//finds distance in the x and y directions
						deltaxsquared=(dude[moveGuy].getXpos()-newXpos)*(dude[moveGuy].getXpos()-newXpos);
						deltaysquared=(dude[moveGuy].getYpos()-newYpos)*(dude[moveGuy].getYpos()-newYpos);
					
						//the next line squares the difference in elevation
						
						int elevationChangeSquared = (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) ) * (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) );
						//this line makes it negative if it should be, and makes it less of an impact
						if (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos())  < 0) {
							elevationChangeSquared = elevationChangeSquared * -1/2;
						}
						
						//if they are an archer with the nimble attribute who is moving
						if (elevationChangeSquared > 0 && dude[moveGuy].getRenown() == 202 && moving) {
							elevationChangeSquared = 0;
						}
						
						
						
						//mobileproblem
						//if ((map[newXpos][newYpos][0] == 0 && range * range >= deltaxsquared + deltaysquared + elevationChangeSquared) && !(range < 4 && deltaxsquared + deltaysquared > range * range)) {//if it is in their move rate
						
						int tempElevationMap[100][100];
						bool tempPassableMap[100][100];
						for(int y=0;y<100;y++) {
							for(int x=0;x<100;x++) {
								tempElevationMap[x][y] = mainMap.getGridElevation(x,y);
								tempPassableMap[x][y] = mainMap.getGridPassable(x,y);
							}
						}
						
						if (!(mainMap.getGridPassable(newXpos,newYpos)) || (range * range < deltaxsquared + deltaysquared + elevationChangeSquared)) {//if it is out of their range entirely or unpassable
							//displays a minus sign if you can't reach there
							//or the person's initial if they are in the way
							if (mainMap.getGridPlayer(newXpos,newYpos) > 0 ) {
								
								
								mapInitial = dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getCharacterClass();
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getTeam() == 1)
								{
									mapInitialDisplay1(mainMap.getGridPlayer(newXpos,newYpos));
								}
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos)].getTeam() == 2)
								{
									mapInitialDisplay2(mainMap.getGridPlayer(newXpos,newYpos));
								}
								
							}
							else { 
								int elevationHere = mainMap.getGridElevation(newXpos,newYpos);
								if (elevationHere == 21) {
								cout << "\033[1;37;1;46m";
								}
								else if (elevationHere > 18) {
									cout << "\033[1;37;45m";
								}
								else if (elevationHere > 16) {
									cout << "\033[1;37;1;45m";
								}
								else if (elevationHere > 14) {
									cout << "\033[1;37;44m";
								}
								else if (elevationHere > 12) {
									cout << "\033[1;37;1;44m";
								}
								else if (elevationHere > 10) {
									cout << "\033[1;37;43m";
								}
								else if (elevationHere > 8) {
									cout << "\033[1;37;1;43m";
								}
								else if (elevationHere > 6) {
									cout << "\033[1;37;42m";
								}
								else if (elevationHere > 4) {
									cout << "\033[1;37;1;42m";
								}
								else if (elevationHere > 2) {
									cout << "\033[1;37;41m";
								}
								else if (elevationHere >= 0) {
									cout << "\033[1;37;1;41m";
								}
								
								cout << "\033[1;30m"; //black text if you can't reach
								
								if (mainMap.getGridGold(newXpos,newYpos) > 0) {
									cout << "-$";
								}
								else {
									cout << "-";
									mainMap.getGridSymbol(newXpos,newYpos);
									
								}
								
								cout << "\033[1;37m"; //back to white text
							}
							
						}
						else if (checkMovePath(dude[moveGuy].getXpos(),dude[moveGuy].getYpos(),newXpos,newYpos,tempElevationMap,tempPassableMap,range)) {
								//displays plus signs if you can reach there, or what ever needed symbol
							if (mainMap.getGridPlayer(newXpos,newYpos) > 0 ) {
								
								mapInitial = dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getCharacterClass();
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getTeam() == 1)
								{
									mapInitialDisplay1(mainMap.getGridPlayer(newXpos,newYpos));
								}
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos)].getTeam() == 2)
								{
									mapInitialDisplay2(mainMap.getGridPlayer(newXpos,newYpos));
								}
							}
							else { 
								int elevationHere = mainMap.getGridElevation(newXpos,newYpos);
								if (elevationHere == 21) {
								cout << "\033[1;37;1;46m";
								}
								else if (elevationHere > 18) {
									cout << "\033[1;37;45m";
								}
								else if (elevationHere > 16) {
									cout << "\033[1;37;1;45m";
								}
								else if (elevationHere > 14) {
									cout << "\033[1;37;44m";
								}
								else if (elevationHere > 12) {
									cout << "\033[1;37;1;44m";
								}
								else if (elevationHere > 10) {
									cout << "\033[1;37;43m";
								}
								else if (elevationHere > 8) {
									cout << "\033[1;37;1;43m";
								}
								else if (elevationHere > 6) {
									cout << "\033[1;37;42m";
								}
								else if (elevationHere > 4) {
									cout << "\033[1;37;1;42m";
								}
								else if (elevationHere > 2) {
									cout << "\033[1;37;41m";
								}
								else if (elevationHere >= 0) {
									cout << "\033[1;37;1;41m";
								}
								
								
								if (mainMap.getGridGold(newXpos,newYpos) > 0) {
									cout << "+$";
								}
								else {
									cout << "+";
									mainMap.getGridSymbol(newXpos,newYpos);
									
								}
								
							cout << "\033[0;40m";
							}
							
						}
						else {//too far away
							//displays a minus sign if you can't reach there
							//or the person's initial if they are in the way
							if (mainMap.getGridPlayer(newXpos,newYpos) > 0 ) {
								mapInitial = dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getCharacterClass();
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getTeam() == 1)
								{
									mapInitialDisplay1(mainMap.getGridPlayer(newXpos,newYpos));
								}
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos)].getTeam() == 2)
								{
									mapInitialDisplay2(mainMap.getGridPlayer(newXpos,newYpos));
								}
							}
							
							else { 
								int elevationHere = mainMap.getGridElevation(newXpos,newYpos);
								if (elevationHere == 21) {
								cout << "\033[1;37;1;46m";
								}
								else if (elevationHere > 18) {
									cout << "\033[1;37;45m";
								}
								else if (elevationHere > 16) {
									cout << "\033[1;37;1;45m";
								}
								else if (elevationHere > 14) {
									cout << "\033[1;37;44m";
								}
								else if (elevationHere > 12) {
									cout << "\033[1;37;1;44m";
								}
								else if (elevationHere > 10) {
									cout << "\033[1;37;43m";
								}
								else if (elevationHere > 8) {
									cout << "\033[1;37;1;43m";
								}
								else if (elevationHere > 6) {
									cout << "\033[1;37;42m";
								}
								else if (elevationHere > 4) {
									cout << "\033[1;37;1;42m";
								}
								else if (elevationHere > 2) {
									cout << "\033[1;37;41m";
								}
								else if (elevationHere >= 0) {
									cout << "\033[1;37;1;41m";
								}
								
								cout << "\033[1;30m"; //black text if you can't reach
								
								if (mainMap.getGridGold(newXpos,newYpos) > 0) {
									cout << "-$";
								}
								else {
									cout << "-";
									mainMap.getGridSymbol(newXpos,newYpos);
									
								}
								
								cout << "\033[1;37m"; //back to white text
							}
							
						
						}	
		
					}
					else //this one for attacks
					{
					
						//finds distance in the x and y directions
						deltaxsquared=(dude[moveGuy].getXpos()-newXpos)*(dude[moveGuy].getXpos()-newXpos);
						deltaysquared=(dude[moveGuy].getYpos()-newYpos)*(dude[moveGuy].getYpos()-newYpos);
					
						//squares the distance in elevations
						int elevationChangeSquared = (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) ) * (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) );
						//this line makes it negative if it should be, and makes it less of an impact
						if (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos())  < 0) {
							elevationChangeSquared = elevationChangeSquared * -1/2;
						}
						
						//if they are an archer with the nimble attribute who is moving
						if (elevationChangeSquared > 0 && dude[moveGuy].getRenown() == 202 && moving) {
							elevationChangeSquared = 0;
						}
						
						if ((mainMap.getGridPassable(newXpos,newYpos) && range * range >= deltaxsquared + deltaysquared + elevationChangeSquared) && !(range < 4 && deltaxsquared + deltaysquared > range * range)) {//if it is in their move rate
							
							//displays plus signs if you can reach there, or what ever needed symbol
							if (mainMap.getGridPlayer(newXpos,newYpos) > 0 ) {//dude's initial
								mapInitial = dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getCharacterClass();
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getTeam() == 1)
								{
									mapInitialDisplay1(mainMap.getGridPlayer(newXpos,newYpos));
								}
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos)].getTeam() == 2)
								{
									mapInitialDisplay2(mainMap.getGridPlayer(newXpos,newYpos));
								}
							}
							else { //plus signs
								int elevationHere = mainMap.getGridElevation(newXpos,newYpos);
								if (elevationHere == 21) {
								cout << "\033[1;37;1;46m";
								}
								else if (elevationHere > 18) {
									cout << "\033[1;37;45m";
								}
								else if (elevationHere > 16) {
									cout << "\033[1;37;1;45m";
								}
								else if (elevationHere > 14) {
									cout << "\033[1;37;44m";
								}
								else if (elevationHere > 12) {
									cout << "\033[1;37;1;44m";
								}
								else if (elevationHere > 10) {
									cout << "\033[1;37;43m";
								}
								else if (elevationHere > 8) {
									cout << "\033[1;37;1;43m";
								}
								else if (elevationHere > 6) {
									cout << "\033[1;37;42m";
								}
								else if (elevationHere > 4) {
									cout << "\033[1;37;1;42m";
								}
								else if (elevationHere > 2) {
									cout << "\033[1;37;41m";
								}
								else if (elevationHere >= 0) {
									cout << "\033[1;37;1;41m";
								}
								
								if (mainMap.getGridGold(newXpos,newYpos) > 0) {
									cout << "+$";
								}
								else {
									cout << "+";
									mainMap.getGridSymbol(newXpos,newYpos);
									
								}
								
							cout << "\033[0;40m";
							}
							
						}
						else {//too far away
							//displays a minus sign if you can't reach there
							//or the person's initial if they are in the way
							if (mainMap.getGridPlayer(newXpos,newYpos) > 0 ) {//dude's initial
								mapInitial = dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getCharacterClass();
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos) ].getTeam() == 1)
								{
									mapInitialDisplay1(mainMap.getGridPlayer(newXpos,newYpos));
								}
								if (dude[ mainMap.getGridPlayer(newXpos,newYpos)].getTeam() == 2)
								{
									mapInitialDisplay2(mainMap.getGridPlayer(newXpos,newYpos));
								}
							}
							
							else { //minus signs
								int elevationHere = mainMap.getGridElevation(newXpos,newYpos);
								if (elevationHere == 21) {
								cout << "\033[1;37;1;46m";
								}
								else if (elevationHere > 18) {
									cout << "\033[1;37;45m";
								}
								else if (elevationHere > 16) {
									cout << "\033[1;37;1;45m";
								}
								else if (elevationHere > 14) {
									cout << "\033[1;37;44m";
								}
								else if (elevationHere > 12) {
									cout << "\033[1;37;1;44m";
								}
								else if (elevationHere > 10) {
									cout << "\033[1;37;43m";
								}
								else if (elevationHere > 8) {
									cout << "\033[1;37;1;43m";
								}
								else if (elevationHere > 6) {
									cout << "\033[1;37;42m";
								}
								else if (elevationHere > 4) {
									cout << "\033[1;37;1;42m";
								}
								else if (elevationHere > 2) {
									cout << "\033[1;37;41m";
								}
								else if (elevationHere >= 0) {
									cout << "\033[1;37;1;41m";
								}
								
								cout << "\033[1;30m"; //black text if you can't reach
								
								if (mainMap.getGridGold(newXpos,newYpos) > 0) {
									cout << "-$";
								}
								else {
									cout << "-";
									mainMap.getGridSymbol(newXpos,newYpos);
									
								}
								
								cout << "\033[1;37m"; //back to white text
							}
							
							
						
						}
						
					}
					cout << "\033[0;40m";
					}
				cout << endl;
			}
			cout << endl;
		
				
	return;
}
	return;
}

//displays the map
void showMap() {
	cout << endl << endl << endl;
	int x = 0, y = 0;
	cout << "                       1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 5\n";
	cout << "   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n";
	for ( x = 0; x < 25; x++) {
		if(x < 10){cout << " " << x;} else {cout << x;}
		for ( y = 0; y <= 50; y++) {
			
			if (mainMap.getGridPlayer(x,y) > 0 ) {
					mapInitial = dude[ mainMap.getGridPlayer(x,y) ].getCharacterClass();
					
					if (dude[ mainMap.getGridPlayer(x,y) ].getTeam() == 1)
					{
						mapInitialDisplay1(mainMap.getGridPlayer(x,y));
					}
					if (dude[ mainMap.getGridPlayer(x,y) ].getTeam() == 2)
					{
						mapInitialDisplay2(mainMap.getGridPlayer(x,y));
					}
				}
				
			else { 
							int elevationHere = mainMap.getGridElevation(x,y);
							if (elevationHere == 21) {
							cout << "\033[1;37;1;46m";
							}
							else if (elevationHere > 18) {
								cout << "\033[1;37;45m";
							}
							else if (elevationHere > 16) {
								cout << "\033[1;37;1;45m";
							}
							else if (elevationHere > 14) {
								cout << "\033[1;37;44m";
							}
							else if (elevationHere > 12) {
								cout << "\033[1;37;1;44m";
							}
							else if (elevationHere > 10) {
								cout << "\033[1;37;43m";
							}
							else if (elevationHere > 8) {
								cout << "\033[1;37;1;43m";
							}
							else if (elevationHere > 6) {
								cout << "\033[1;37;42m";
							}
							else if (elevationHere > 4) {
								cout << "\033[1;37;1;42m";
							}
							else if (elevationHere > 2) {
								cout << "\033[1;37;41m";
							}
							else if (elevationHere >= 0) {
								cout << "\033[1;37;1;41m";
							}
							
							
							if (mainMap.getGridGold(x,y) > 0) {
								cout << "$";
								mainMap.getGridSymbol(x,y);
							}
							else {
								cout << " ";
								mainMap.getGridSymbol(x,y);
							}
						}
						
			
			cout << "\033[0;40m";
			}
					
		cout << endl;
	}
	cout << endl;
	}


//this is how you leave the game
void leaveGame(){
	
    cout << "\nAre you sure you want to leave the game?\n 123:yes\n 2:no\n";
    cin >> userInput;
    if(userInput==123)
    running = 0;		
}

void armyGainMoney(int team, int money) {
	if (team == 1) {
		army1[1] = army1[1] + money;
		if (money > 0) {
			cout << endl << armyName1 << " gains " << money << " gold.\n\n";
		}
		if (money < 0) {
			cout << endl << armyName1 << " spends " << money << " gold.\n\n";
		}
	}
	if (team == 2) {
		army2[1] = army2[1] + money;
		if (money > 0) {
			cout << endl << armyName2 << " gains " << money << " gold.\n\n";
		}
		if (money < 0) {
			cout << endl << armyName2 << " spends " << money << " gold.\n\n";
		}
	}
	
	return;
}

void getSaveArmy(int team) {
	ifstream saves;
	string saveArmyNameString;
	string saveArmyUsingString;
	string saveArmyGoldString;
	string saveArmyMaxSizeString;
	string saveArmyWhichFileString;
	string saveArmyWinsString;
	string saveArmyLossesString;
	string saveArmyTiesString;
	string saveArmyWinOrNotString;
	string saveArmyWinStreakString;
	string saveArmyLoseStreakString;
	string correctArmyName;
	
	int saveArmyUsing, saveArmyGold, saveArmyMaxSize, saveArmyWhichFile, saveArmyWins, saveArmyLosses;
	int saveArmyTies, saveArmyWinOrNot, saveArmyWinStreak, saveArmyLoseStreak;
	
	bool correctArmyFound = 0;
	
	cout << "What is the name of the army that you want?\n";
	cin >> correctArmyName;
	cout << endl << endl;
	
	while(!correctArmyFound) {
		saves.open("1army.txt");//opens file
		if(saves.fail()){  //checks if the file opened right
		cout << "saves file open failed" << endl;
		return;
		}
		getline(saves, saveArmyNameString);
		if (saveArmyNameString == correctArmyName) {
			break;
		}
		saves.close();
		
		saves.open("2army.txt");//opens file
		if(saves.fail()){  //checks if the file opened right
		cout << "saves file open failed" << endl;
		return;
		}
		getline(saves, saveArmyNameString);
		if (saveArmyNameString == correctArmyName) {
			break;
		}
		saves.close();
		
		saves.open("3army.txt");//opens file
		if(saves.fail()){  //checks if the file opened right
		cout << "saves file open failed" << endl;
		return;
		}
		getline(saves, saveArmyNameString);
		if (saveArmyNameString == correctArmyName) {
			break;
		}
		saves.close();
		
		saves.open("4army.txt");//opens file
		if(saves.fail()){  //checks if the file opened right
		cout << "saves file open failed" << endl;
		return;
		}
		getline(saves, saveArmyNameString);
		if (saveArmyNameString == correctArmyName) {
			break;
		}
		saves.close();
		
		cout << "Please retry typing the name\n";
		cin >> correctArmyName;
		cout << endl << endl;
	}
	
	getline(saves, saveArmyUsingString);
	getline(saves, saveArmyGoldString);
	getline(saves, saveArmyMaxSizeString);
	getline(saves, saveArmyWhichFileString);
	getline(saves, saveArmyWinsString);
	getline(saves, saveArmyLossesString);
	getline(saves, saveArmyTiesString);
	getline(saves, saveArmyWinOrNotString);
	getline(saves, saveArmyWinStreakString);
	getline(saves, saveArmyLoseStreakString);
	
	istringstream ( saveArmyUsingString ) >> saveArmyUsing;
	istringstream ( saveArmyGoldString ) >> saveArmyGold;
	istringstream ( saveArmyMaxSizeString ) >> saveArmyMaxSize;
	istringstream ( saveArmyWhichFileString ) >> saveArmyWhichFile;
	istringstream ( saveArmyWinsString ) >> saveArmyWins;
	istringstream ( saveArmyLossesString ) >> saveArmyLosses;
	istringstream ( saveArmyTiesString ) >> saveArmyTies;
	istringstream ( saveArmyWinOrNotString ) >> saveArmyWinOrNot;
	istringstream ( saveArmyWinStreakString ) >> saveArmyWinStreak;
	istringstream ( saveArmyLoseStreakString ) >> saveArmyLoseStreak;
	
	//mobileproblem
	/*
	saveArmyUsing = stoi (saveArmyUsingString, 0, 10);  //converts them into ints
	saveArmyGold = stoi (saveArmyGoldString, 0, 10);
	saveArmyMaxSize = stoi (saveArmyMaxSizeString, 0, 10);
	saveArmyWhichFile = stoi (saveArmyWhichFileString, 0, 10);
	saveArmyWins = stoi (saveArmyWinsString, 0, 10);
	saveArmyLosses = stoi (saveArmyLossesString, 0, 10);
	saveArmyTies = stoi (saveArmyTiesString, 0, 10);	
	saveArmyWinOrNot = stoi (saveArmyWinOrNotString, 0, 10);
	saveArmyWinStreak = stoi (saveArmyWinStreakString, 0, 10);
	saveArmyLoseStreak = stoi (saveArmyLoseStreakString, 0, 10);
	*/
		
	if (team == 1) {
		armyName1 = saveArmyNameString;
		army1[0] = saveArmyUsing;
		army1[1] = saveArmyGold;
		army1[2] = saveArmyMaxSize;
		army1[3] = saveArmyWhichFile;
		army1[4] = saveArmyWins;
		army1[5] = saveArmyLosses;
		army1[6] = saveArmyTies;
		army1[7] = saveArmyWinOrNot;
		army1[8] = saveArmyWinStreak;
		army1[9] = saveArmyLoseStreak;
	}
	if (team == 2) {
		armyName2 = saveArmyNameString;
		army2[0] = saveArmyUsing;
		army2[1] = saveArmyGold;
		army2[2] = saveArmyMaxSize;
		army2[3] = saveArmyWhichFile;
		army2[4] = saveArmyWins;
		army2[5] = saveArmyLosses;
		army2[6] = saveArmyTies;
		army2[7] = saveArmyWinOrNot;
		army2[8] = saveArmyWinStreak;
		army2[9] = saveArmyLoseStreak;
	}
	
	return;
}

void getArmyPeopleSaves(int team) {
	ifstream saves;
	string characterChoice, line, classStatString, attackStatString, defenseStatString, moveStatString, rangeStatString, xpStatString, healthStatString, manaStatString, regenStatString, levelStatString, prestigeStatString;
	string raceStatString, birthRightStatString, renownStatString, paragonStatString, startingManaStatString, accuracyStatString, evasionStatString;
	int classStat, attackStat, defenseStat, moveStat, rangeStat, xpStat, healthStat, manaStat, regenStat, levelStat, prestigeStat;
	int	raceStat, birthRightStat, renownStat, paragonStat, startingManaStat, accuracyStat, evasionStat;
	bool leave = 0;
	
	if (team == 1) {
		if (army1[3] == 1) {
			saves.open("1army.txt"); //opens the file
		}
		if (army1[3] == 2) {
			saves.open("2army.txt"); //opens the file
		}
		if (army1[3] == 3) {
			saves.open("3army.txt"); //opens the file
		}
		if (army1[3] == 4) {
			saves.open("4army.txt"); //opens the file
		}
		if (army1[3] == 5) {
			saves.open("5army.txt"); //opens the file
		}
	}
	
	if (team == 2) {
		if (army2[3] == 1) {
			saves.open("1army.txt"); //opens the file
		}
		if (army2[3] == 2) {
			saves.open("2army.txt"); //opens the file
		}
		if (army2[3] == 3) {
			saves.open("3army.txt"); //opens the file
		}
		if (army2[3] == 4) {
			saves.open("4army.txt"); //opens the file
		}
		if (army2[3] == 5) {
			saves.open("5army.txt"); //opens the file
		}
	}
		
	if(saves.fail()){  //checks if the file opened right
	cout << "saves file open failed" << endl;
	return;
	}
	
	while(leave==0) {
		cout << "\nWhat character from your army do you want?\n";
		cin >> characterChoice;
		
				
			size_t pos;
			while(saves.good())
			  {
				  getline(saves,line); // get line from file
				  getline(saves, classStatString);
				  getline(saves, attackStatString);
				  getline(saves, defenseStatString);
				  getline(saves, moveStatString);
				  getline(saves, rangeStatString);
				  getline(saves, xpStatString);
				  getline(saves, healthStatString);
				  getline(saves, manaStatString);
				  getline(saves, regenStatString);
				  getline(saves, levelStatString);
				  getline(saves, prestigeStatString);
				  getline(saves, raceStatString);
				  getline(saves, birthRightStatString);
				  getline(saves, renownStatString);
				  getline(saves, paragonStatString);
				  getline(saves, startingManaStatString);
				  getline(saves, accuracyStatString);
				  getline(saves, evasionStatString);
				  
				  
				  pos=line.find(characterChoice); // search
				  if(pos!=string::npos) // string::npos is returned if string is not found
					{
						cout << "Found!" << endl;
						cout << "Name:         " << line << endl;
						cout << "Renown:       " << renownStatString << endl;
						cout << "Class:        " << classStatString << endl;
						cout << "Prestige:     " << prestigeStatString << endl;
						cout << "Paragon:      " << paragonStatString << endl;
						cout << "Race:         " << raceStatString << endl;
						cout << "Attack:       " << attackStatString << endl;
						cout << "Defense:      " << defenseStatString << endl;
						cout << "Move:         " << moveStatString << endl;
						cout << "Range:        " << rangeStatString << endl;
						cout << "Accuracy:     " << accuracyStatString << endl;
						cout << "Evasion:      " << evasionStatString << endl;
						cout << "Max health:   " << healthStatString << endl;
						cout << "Starting mana:" << startingManaStatString << endl;
						cout << "Max mana:     " << manaStatString << endl;
						cout << "Mana regen:   " << regenStatString << endl;
						cout << "Level:        " << levelStatString << endl;
						cout << "Xp:           " << xpStatString << endl;
						cout << "BirthRight:   " << birthRightStatString << endl;
						
						
						
						break;
					}
					if(saves.eof()){
					getArmyPeopleSaves(team);
					saves.close();}
					
			  }
			  
			  cout << "\nIs this who you wanted\n1: Yes\n0: No\n";
			  cin >> leave;
			  
		}

		istringstream ( classStatString ) >> classStat;
		istringstream ( attackStatString ) >> attackStat;
		istringstream ( defenseStatString ) >> defenseStat;
		istringstream ( moveStatString ) >> moveStat;
		istringstream ( rangeStatString ) >> rangeStat;
		istringstream ( healthStatString ) >> healthStat;
		istringstream ( manaStatString ) >> manaStat;
		istringstream ( regenStatString ) >> regenStat;
		istringstream ( levelStatString ) >> levelStat;
		istringstream ( xpStatString ) >> xpStat;
		istringstream ( prestigeStatString ) >> prestigeStat;
		istringstream ( raceStatString ) >> raceStat;
		istringstream ( birthRightStatString ) >> birthRightStat;
		istringstream ( renownStatString ) >> renownStat;
		istringstream ( paragonStatString ) >> paragonStat;
		istringstream ( startingManaStatString ) >> startingManaStat;
		istringstream ( accuracyStatString ) >> accuracyStat;
		istringstream ( evasionStatString ) >> evasionStat;
		
	
		//mobileProblem
		/*
		classStat = stoi (classStatString, 0, 10);  //converts them into ints
		attackStat = stoi (attackStatString, 0, 10);
		defenseStat = stoi (defenseStatString, 0, 10);
		moveStat = stoi (moveStatString, 0, 10);
		rangeStat = stoi (rangeStatString, 0, 10);
		healthStat = stoi (healthStatString, 0, 10);
		manaStat = stoi (manaStatString, 0, 10);
		regenStat = stoi (regenStatString, 0, 10);
		levelStat = stoi (levelStatString, 0, 10);
		xpStat = stoi (xpStatString, 0, 10);
		prestigeStat = stoi (prestigeStatString, 0, 10);
		raceStat = stoi (raceStatString, 0, 10);
		birthRightStat = stoi (birthRightStatString, 0, 10);
		renownStat = stoi (renownStatString, 0, 10);
		paragonStat = stoi (paragonStatString, 0, 10);
		startingManaStat = stoi (startingManaStatString, 0, 10);
		accuracyStat = stoi (accuracyStatString, 0, 10);
		evasionStat = stoi (evasionStatString, 0, 10);
		*/
		
	//assigns the values to the person
	dude[assignGuy].setCharacterClass(classStat);
	dude[assignGuy].setAttack(attackStat);
	dude[assignGuy].setDefense(defenseStat);
	dude[assignGuy].setHealth(healthStat);
	dude[assignGuy].setMaxHealth(healthStat);
	dude[assignGuy].setMove(moveStat);
	dude[assignGuy].setRange(rangeStat);
	dude[assignGuy].setAp(12);
	dude[assignGuy].setXp(xpStat);
	dude[assignGuy].setMana(manaStat);
	dude[assignGuy].setMaxMana(manaStat);
	dude[assignGuy].setManaRegen(regenStat);
	dude[assignGuy].setLevel(levelStat);
	dude[assignGuy].setPrestige(prestigeStat);
	dude[assignGuy].setRace(raceStat);
	dude[assignGuy].setBirthRight(birthRightStat);
	dude[assignGuy].setRenown(renownStat);
	dude[assignGuy].setParagon(paragonStat);
	dude[assignGuy].setStartingMana(startingManaStat);
	dude[assignGuy].setMissChance(accuracyStat);
	dude[assignGuy].setEvasion(evasionStat);
	
	dude[assignGuy].setName(line);
	
	saves.close();
	return;
}

void newArmy(int team) {
	int slot = 0;
	
	cout << "What is the name of the army?\n";
	
	if (team == 1) {

        if (!FAST_START)
            cin >> armyName1;
        else
            armyName1 = "armyName1";

		cout << "\nWhich of the 5 army slots do you want to use?\n";

        if (!FAST_START)
            cin >> slot;
        else
            slot = 5;

		cout << endl;
		
		army1[0] = 1;//says it is being used
		army1[1] = 1000; //sets beginning money
		army1[2] = 1; //sets max population to 1
		army1[3] = slot; //sets slot to use in memory
		army1[4] = 0; //wins
		army1[5] = 0; //losses
		army1[6] = 0; //ties
		army1[7] = 0; //win streak
		army1[8] = 0; //best win streak
		army1[9] = 0; //worst loss streak
		
		
	}
	else if (team == 2) {

        if (!FAST_START)
            cin >> armyName2;
        else
            armyName2 = "armyName1";

		cout << "\nWhich of the 5 army slots do you want to use?\n";

        if (!FAST_START)
            cin >> slot;
        else
            slot = 5;

		cout << endl;
		
		army2[0] = 1;//says it is being used
		army2[1] = 1000; //sets beginning money
		army2[2] = 1; //sets max population to 1
		army2[3] = slot; //sets slot to use in memory
		army2[4] = 0; //wins
		army2[5] = 0; //losses
		army2[6] = 0; //ties
		army2[7] = 0; //win streak
		army2[8] = 0; //best win streak
		army2[9] = 0; //worst loss streak
	}
	
	
	
	return;
}

void saveArmy(int team) {
	int saveCharacter, i, j, k;
	ofstream saves;
	fstream tempStream;
	fstream saving;
	string holdTemp[15];
	string holdSaves[15];
	int endOfFileTwice = 0;
	int doneCheckingPeople = 1;
	string copyLines;
	
	cout << "goherenow\n";
	
	remove("tempFile.txt");
	
	if (team == 1) {
		
		switch (army1[3]) { 
			case 1:
			rename("1army.txt","tempFile.txt"); //renames it
			saves.open("1army.txt"); //opens the save
			
			break;
			case 2:
			rename("2army.txt","tempFile.txt");
			saves.open("2army.txt", fstream :: app); //opens the save
			
			break;
			case 3:
			rename("3army.txt","tempFile.txt");
			saves.open("3army.txt", fstream :: app); //opens the save
			
			break;
			case 4:
			rename("4army.txt","tempFile.txt");
			saves.open("4army.txt", fstream :: app); //opens the save
			
			break;
			case 5:
			rename("5army.txt","tempFile.txt");
			saves.open("5army.txt", fstream :: app); //opens the save
			
			break;
		}
		
		tempStream.open("tempFile.txt"); //opens the temp file
		
		
		saves << armyName1 << endl;
		for (i=0; i <= 9; i++) {	
			saves << army1[i] << endl;
			
		}
		saves << "\n\n\n\n\n\n\n\n\n";
		
		
		
		for (saveCharacter=1; saveCharacter <= teamSize1; saveCharacter++) {
			saves << dude[saveCharacter].getName() << endl;
			for (i=0; i <= 25; i++) {
				if (i == 0 || i == 1 || i == 2 || i == 4 || i == 5  || i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23 || i == 24) {
					saves << playerInfo[saveCharacter][i] << endl;	//saves the important attributes
				}
			}
		}
	}
	
	if (team == 2) {
		
		
		
		switch (army2[3]) { 
			case 1:
			rename("1army.txt","tempFile.txt");
			saves.open("1army.txt", fstream :: app); //opens the save
			
			break;
			case 2:
			rename("2army.txt","tempFile.txt");
			saves.open("2army.txt", fstream :: app); //opens the save
			
			break;
			case 3:
			rename("3army.txt","tempFile.txt");
			saves.open("3army.txt", fstream :: app); //opens the save
			
			break;
			case 4:
			rename("4army.txt","tempFile.txt");
			saves.open("4army.txt", fstream :: app); //opens the save
			
			break;
			case 5:
			rename("5army.txt","tempFile.txt");
			saves.open("5army.txt", fstream :: app); //opens the save
			
			break;
		}
		
		saves << armyName2 << endl;
		for (i=0; i <= 9; i++) {
			saves << army2[i] << endl;
		}
		saves << "\n\n\n\n\n\n\n\n\n";
		
		
		for (saveCharacter=teamSize1 + 1; saveCharacter <= teamSize2 + teamSize1; saveCharacter++) {
			saves << dude[saveCharacter].getName() << endl;
			for (i=0; i <= 25; i++) {
				if (i == 0 || i == 1 || i == 2 || i == 4 || i == 5 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23 || i == 24) {
					saves << playerInfo[saveCharacter][i] << endl;	//saves the important attributes
				}
			}
		}
	}
	
	
	
	
	saves.close();
	
	/*this will eventually make it delete old data and overwrite it
	while(doneCheckingPeople) {
		
		for (j=0; j<=14; j++) {//to go through the temp file
			cout << "getting line\n";
			getline(tempStream, holdTemp[j]);
		}
		
		cout << "checking " << holdTemp[0] << endl;
		
		
			
			if (team == 1) {//opens the right save file
				
			switch (army1[3]) { 
				case 1:
				cout << "opening the save file that includes all the prior characters\n";
				saving.open("1army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 2:
				
				saving.open("2army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 3:
				
				saving.open("3army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 4:
				
				saving.open("4army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 5:
				
				saving.open("5army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
			}
		}
		if (team == 2) {//opens the right save file
			switch (army2[3]) { 
				case 1:
				
				saving.open("1army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 2:
				
				saving.open("2army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 3:
				
				saving.open("3army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 4:
				
				saving.open("4army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
				case 5:
				
				saving.open("5army.txt",  fstream::in | fstream::out | fstream :: app); //opens the save
				
				break;
			}
		}
			
		
		while(endOfFileTwice < 200) {
				
			for (i=0; i<=14; i++) {//to go through the save file
				getline(saving, holdSaves[i]);
				cout << "holdsaves[i] " << holdSaves[i];
			}
			if (holdSaves[0] == holdTemp[0]) {//if they match, then leave the loop
				cout << "The holdsaves " << holdSaves[0] << " matches the holdtemp " << holdTemp[0] << endl;
				break;
			}
			cout << "holdsaves " << holdSaves[0] << " holdTemp " << holdTemp[0] << endl;
				endOfFileTwice++;
			
			if (endOfFileTwice >= 200) {
				
				cout << "sending " << holdTemp[0] << " to the saves, because it doesn't match " << holdSaves[0] << endl;
				for (k=0; k<=14; k++) {//sends the person to the save
					cout << holdTemp[k] << endl;
					saving << holdTemp[k] << endl;
				}
				
			}
			
		}
		endOfFileTwice = 0;
		
		if(tempStream.eof()) {
			cout << "end tempstream\n";
			doneCheckingPeople--;
		}
		
	}
	
	
	
	saving.close();
	*/
	tempStream.close();
	return;
}

void getSave() {
	ifstream saves;
	string characterChoice, line, classStatString, attackStatString, defenseStatString, moveStatString, rangeStatString, xpStatString, healthStatString, manaStatString, regenStatString, levelStatString, prestigeStatString;
	string raceStatString, birthRightStatString, renownStatString, paragonStatString, startingManaStatString, accuracyStatString, evasionStatString;
	int classStat, attackStat, defenseStat, moveStat, rangeStat, xpStat, healthStat, manaStat, regenStat, levelStat, prestigeStat;
	int	raceStat, birthRightStat, renownStat, paragonStat, startingManaStat, accuracyStat, evasionStat;
	bool leave = 0;
	
	saves.open("saves.txt"); //opens the file
		
	if(saves.fail()){  //checks if the file opened right
	cout << "saves file open failed" << endl;
	return;
	}
	
	while(leave==0) {
		cout << "\nWhat character from the saves did you want to get?\n";
		cin >> characterChoice;
		
				
			size_t pos;
			while(saves.good())
			  {
				  getline(saves,line); // get line from file
				  getline(saves, classStatString);
				  getline(saves, attackStatString);
				  getline(saves, defenseStatString);
				  getline(saves, moveStatString);
				  getline(saves, rangeStatString);
				  getline(saves, xpStatString);
				  getline(saves, healthStatString);
				  getline(saves, manaStatString);
				  getline(saves, regenStatString);
				  getline(saves, levelStatString);
				  getline(saves, prestigeStatString);
				  getline(saves, raceStatString);
				  getline(saves, birthRightStatString);
				  getline(saves, renownStatString);
				  getline(saves, paragonStatString);
				  getline(saves, startingManaStatString);
				  getline(saves, accuracyStatString);
				  getline(saves, evasionStatString);
				  
				  
				  pos=line.find(characterChoice); // search
				  if(pos!=string::npos) // string::npos is returned if string is not found
					{
						cout << "Found!" << endl;
						cout << "Name:         " << line << endl;
						cout << "Renown:       " << renownStatString << endl;
						cout << "Class:        " << classStatString << endl;
						cout << "Prestige:     " << prestigeStatString << endl;
						cout << "Paragon:      " << paragonStatString << endl;
						cout << "Race:         " << raceStatString << endl;
						cout << "Attack:       " << attackStatString << endl;
						cout << "Defense:      " << defenseStatString << endl;
						cout << "Move:         " << moveStatString << endl;
						cout << "Range:        " << rangeStatString << endl;
						cout << "Accuracy:     " << accuracyStatString << endl;
						cout << "Evasion:      " << evasionStatString << endl;
						cout << "Max health:   " << healthStatString << endl;
						cout << "Starting mana:" << startingManaStatString << endl;
						cout << "Max mana:     " << manaStatString << endl;
						cout << "Mana regen:   " << regenStatString << endl;
						cout << "Level:        " << levelStatString << endl;
						cout << "Xp:           " << xpStatString << endl;
						cout << "BirthRight:   " << birthRightStatString << endl;
						
						
						
						break;
					}
					if(saves.eof()){
					getSave();
					saves.close();}
			  }
			  
			  cout << "\nIs this who you wanted\n1: Yes\n0: No\n";
			  cin >> leave;
			  
		}

		istringstream ( classStatString ) >> classStat;
		istringstream ( attackStatString ) >> attackStat;
		istringstream ( defenseStatString ) >> defenseStat;
		istringstream ( moveStatString ) >> moveStat;
		istringstream ( rangeStatString ) >> rangeStat;
		istringstream ( healthStatString ) >> healthStat;
		istringstream ( manaStatString ) >> manaStat;
		istringstream ( regenStatString ) >> regenStat;
		istringstream ( levelStatString ) >> levelStat;
		istringstream ( xpStatString ) >> xpStat;
		istringstream ( prestigeStatString ) >> prestigeStat;
		istringstream ( raceStatString ) >> raceStat;
		istringstream ( birthRightStatString ) >> birthRightStat;
		istringstream ( renownStatString ) >> renownStat;
		istringstream ( paragonStatString ) >> paragonStat;
		istringstream ( startingManaStatString ) >> startingManaStat;
		istringstream ( accuracyStatString ) >> accuracyStat;
		istringstream ( evasionStatString ) >> evasionStat;

		/*
		classStat = stoi (classStatString, 0, 10);  //converts them into ints
		attackStat = stoi (attackStatString, 0, 10);
		defenseStat = stoi (defenseStatString, 0, 10);
		moveStat = stoi (moveStatString, 0, 10);
		rangeStat = stoi (rangeStatString, 0, 10);
		healthStat = stoi (healthStatString, 0, 10);
		manaStat = stoi (manaStatString, 0, 10);
		regenStat = stoi (regenStatString, 0, 10);
		levelStat = stoi (levelStatString, 0, 10);
		xpStat = stoi (xpStatString, 0, 10);
		prestigeStat = stoi (prestigeStatString, 0, 10);
		raceStat = stoi (raceStatString, 0, 10);
		birthRightStat = stoi (birthRightStatString, 0, 10);
		renownStat = stoi (renownStatString, 0, 10);
		paragonStat = stoi (paragonStatString, 0, 10);
		startingManaStat = stoi (startingManaStatString, 0, 10);
		accuracyStat = stoi (accuracyStatString, 0, 10);
		evasionStat = stoi (evasionStatString, 0, 10);
		*/
		
	//assigns the values to the person

	
	dude[assignGuy].setCharacterClass(classStat);
	dude[assignGuy].setAttack(attackStat);
	dude[assignGuy].setDefense(defenseStat);
	dude[assignGuy].setHealth(healthStat);
	dude[assignGuy].setMaxHealth(healthStat);
	dude[assignGuy].setMove(moveStat);
	dude[assignGuy].setRange(rangeStat);
	dude[assignGuy].setAp(12);
	dude[assignGuy].setXp(xpStat);
	dude[assignGuy].setMana(manaStat);
	dude[assignGuy].setMaxMana(manaStat);
	dude[assignGuy].setManaRegen(regenStat);
	dude[assignGuy].setLevel(levelStat);
	dude[assignGuy].setPrestige(prestigeStat);
	dude[assignGuy].setRace(raceStat);
	dude[assignGuy].setBirthRight(birthRightStat);
	dude[assignGuy].setRenown(renownStat);
	dude[assignGuy].setParagon(paragonStat);
	dude[assignGuy].setStartingMana(startingManaStat);
	dude[assignGuy].setMissChance(accuracyStat);
	dude[assignGuy].setEvasion(evasionStat);
	
	dude[assignGuy].setName(line);
	
	
	saves.close();
	
	return;
}

void savegame() {
	int i = 0, saveCharacter = 0;
	bool again = 1;
	ofstream saves;
	int assignGuy = 0;
	
	
	
	for (assignGuy=1; assignGuy <= teamSize1 + teamSize2; assignGuy++) {//if they are a familiar
		if (playerInfo[assignGuy][19]/100 == 802) {
			playerInfo[assignGuy][11] = playerInfo[assignGuy][11] + dude[assignGuy].getLevel() * 50;//turns their levels into xp, some point loss at higher levels
			playerInfo[assignGuy][15] = 0;
			playerInfo[playerInfo[assignGuy][19]%100][11] = playerInfo[assignGuy][11];
			playerInfo[assignGuy][11] = 0;
			teamSize1--;
			
		}
	}
	
	
	
	//this following chunks reset priests with the blessed renown
	 for (assignGuy=1; assignGuy <= teamSize1; assignGuy++) {//attack, defense, move, mana regen
		if (dude[assignGuy].getRenown() == 301) {
			switch (initialBlessed[assignGuy]) {
				case 1:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 1);//lower attack
				break;
				case 2:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 2);//lower attack
				break;
				case 3:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 3);//lower attack
				break;
				case 4:
					dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 1);//lower defense
				break;
				case 5:
					dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 2);//lower defense
				break;
				case 6:
					dude[assignGuy].setMove(dude[assignGuy].getMove() - 2);//lower move
				break;
				case 7:
					dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 1);//lower mana regen
				break;
				case 8:
					dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 2);//lower mana regen
				break;
				case 20:
				
				dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 3);//lower attack
				dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 2);//lower defense
				dude[assignGuy].setMove(dude[assignGuy].getMove() - 2);//lower move
				dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 2);//lower mana regen
				break;
				
			}
		}
	}
				
	for (assignGuy= teamSize1 + 1; assignGuy <= teamSize2 + teamSize1; assignGuy++) {
		if (dude[assignGuy].getRenown() == 301) {
			switch (initialBlessed[assignGuy]) {
				case 1:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 1);//lower attack
				break;
				case 2:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 2);//lower attack
				break;
				case 3:
					dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 3);//lower attack
				break;
				case 4:
					dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 1);//lower defense
				break;
				case 5:
					dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 2);//lower defense
				break;
				case 6:
					dude[assignGuy].setMove(dude[assignGuy].getMove() - 2);//lower move
				break;
				case 7:
					dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 1);//lower mana regen
				break;
				case 8:
					dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 2);//lower mana regen
				break;
				case 20:
				
				dude[assignGuy].setAttack(dude[assignGuy].getAttack() - 3);//lower attack
				dude[assignGuy].setDefense(dude[assignGuy].getDefense() - 2);//lower defense
				dude[assignGuy].setMove(dude[assignGuy].getMove() - 2);//lower move
				dude[assignGuy].setManaRegen(dude[assignGuy].getManaRegen() - 2);//lower mana regen
				break;
			}
		}
	}
	
	saves.open("saves.txt", fstream :: app); //opens the file
	
		if(saves.fail())  //checks if the file opened right
	{
		cout << "saves file open failed" << endl;
		return;
	}
	 
	cout << "\nDo you want to save any characters?\n1: Yes\n0: No\n";
	cin >> again;
	while (again == 1) {
	cout << "\nWhat character do you want to save?\n";
	
	for (i=1; i <= teamSize1 + teamSize2; i++) {
		cout << i << ": " << epithet(i) << endl;
	}
	
	cin >> saveCharacter;
	
	saves << dude[saveCharacter].getName() << endl;
	
	saves << dude[saveCharacter].getCharacterClass() << endl;
	saves << dude[saveCharacter].getAttack() << endl;
	saves << dude[saveCharacter].getDefense() << endl;
	saves << dude[saveCharacter].getMove() << endl;
	saves << dude[saveCharacter].getRange() << endl;
	saves << dude[saveCharacter].getXp() << endl;
	saves << dude[saveCharacter].getMaxHealth() << endl;
	saves << dude[saveCharacter].getMaxMana() << endl;
	saves << dude[saveCharacter].getManaRegen() << endl;
	saves << dude[saveCharacter].getLevel() << endl;
	saves << dude[saveCharacter].getPrestige() << endl;
	saves << dude[saveCharacter].getRace() << endl;
	saves << dude[saveCharacter].getBirthRight() << endl;
	saves << dude[saveCharacter].getRenown() << endl;
	saves << dude[saveCharacter].getParagon() << endl;
	saves << dude[saveCharacter].getStartingMana() << endl;
	saves << dude[saveCharacter].getMissChance() << endl;
	saves << dude[saveCharacter].getEvasion() << endl;
			
		

	cout << "\nDo you want to save anyone else?\n0: No\n1: Yes\n";
	cin >> again;
	}

	
	saves.close();
	
	if (army1[0]) {
		saveArmy(1);
	}
	
	if (army2[0]) {
		saveArmy(2);
	}
	
	return;
}

//Assigns the names of the prestiges
void assignPrestige() {
	int l = 1;
	int x = 0;
	
	for (l=1; l<= teamSize1 + teamSize2; l++) {
		
	switch (dude[l].getPrestige()) {
		case 101: 
		dude[l].setPrestigeName(p101);
		break;
		case 102:
		dude[l].setPrestigeName(p102);
		break;
		
		case 201: 
		dude[l].setPrestigeName(p201);
		break;
		case 202:
		dude[l].setPrestigeName(p202);
		break;
		
		case 301: 
		dude[l].setPrestigeName(p301);
		break;
		case 302:
		dude[l].setPrestigeName(p302);
		break;
		case 303: 
		dude[l].setPrestigeName(p303);
		break;

		case 401: 
		dude[l].setPrestigeName(p401);
		break;
		case 402:
		dude[l].setPrestigeName(p402);
		break;
		
		case 501: 
		dude[l].setPrestigeName(p501);
		break;
		case 502:
		dude[l].setPrestigeName(p502);
		break;
		
		case 601: 
		dude[l].setPrestigeName(p601);
		break;
		case 602:
		dude[l].setPrestigeName(p602);
		break;
		case 603: 
		dude[l].setPrestigeName(p603);
		break;
		
		case 701: 
		dude[l].setPrestigeName(p701);
		break;
		case 702:
		dude[l].setPrestigeName(p702);
		break;
		case 703: 
		dude[l].setPrestigeName(p703);
		break;
		
		case 801: 
		dude[l].setPrestigeName(p801);
		break;
		case 802:
		dude[l].setPrestigeName(p802);
		break;
		case 803:
		dude[l].setPrestigeName(p803);
		break;
		

	}
}

	
	
	return;
}

void prestige() {
	int x=0, classChoice;
	
	
	
	for (x=1; x<= teamSize1; x++) {
		if (dude[x].getLevel() == 7 && dude[x].getPrestige() == 0){
			cout << "\nCongratulations, you have now aquired enough experience to prestige\n";
			
			if (dude[x].getCharacterClass() == 1) {	//fighter	brawler				defender
				cout << "\nWhat do you want to prestige as?\n1: Brawler\n2: Defender\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 5); //attack
					dude[x].setDefense(dude[x].getDefense() + 1); //defense
					dude[x].setHealth(dude[x].getHealth() + 5); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 5);//maxhealth
					dude[x].setPrestige(101);
					
				}
				else if (classChoice == 2){
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10);//maxhealth
					dude[x].setMove(dude[x].getMove() - 1);//move
					dude[x].setPrestige(102);
				}
			}
			if (dude[x].getCharacterClass() == 2) {	//archer	crossbow			longbow
				cout << "\nWhat do you want to prestige as?\n1: Crossbowman\n2: Longbowman\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 11); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setMove(dude[x].getMove() - 1); //move
					dude[x].setPrestige(201);
				}
				else { //also, double attack
					dude[x].setAttack(dude[x].getAttack() - 2); //attack
					dude[x].setRange(dude[x].getRange() + 5); //range
					dude[x].setPrestige(202);
				}
			}
			if (dude[x].getCharacterClass() == 3) {	//priest	cleric				acolyte			paladin
				cout << "\nWhat do you want to prestige as?\n1: Cleric\n2: Acolyte\n3: Paladin\n";
				cin >> classChoice;
				if (classChoice == 1) { // heal
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setPrestige(301);
				}
				else if (classChoice == 2) { //bless curse revive heal
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 2); //regen	
					dude[x].setPrestige(302);
				}
				else if (classChoice == 3) { // heal smite
					dude[x].setAttack(dude[x].getAttack() + 4); //attack
					dude[x].setDefense(dude[x].getDefense() + 4); //defense
					dude[x].setHealth(dude[x].getHealth() + 5); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 5);//maxhealth
					dude[x].setMove(dude[x].getMove() - 1); //move
					dude[x].setManaRegen(dude[x].getManaRegen() - 3); //regen	
					dude[x].setMaxMana(dude[x].getMaxMana() - 20); //maxMana
					dude[x].setPrestige(303);
				}
			}
			if (dude[x].getCharacterClass() == 4) {	//berserker	battlerager			thumper
				cout << "\nWhat do you want to prestige as?\n1: Battlerager\n2: Thumper\n";
				cin >> classChoice;
				if (classChoice == 1) { //also double attack
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10); //maxhealth
					dude[x].setAttack(dude[x].getAttack() - 3); //attack
					dude[x].setDefense(dude[x].getDefense() - 1);//defense
					dude[x].setPrestige(401);
				}

				else if (classChoice == 2) { //also, bloodlust
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10);//maxhealth
					dude[x].setRange(dude[x].getRange() + 1); //range
					dude[x].setPrestige(402);
				}
			}
			if (dude[x].getCharacterClass() == 5) {	//knight	lancer				mounted pally
				cout << "\nWhat do you want to prestige as?\n1: Lancer\n2: Mounted Paladin\n";
				cin >> classChoice;
				if (classChoice == 1) { //better charge
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setMove(dude[x].getMove() + 3); //move
					dude[x].setPrestige(501);
				}
				else if (classChoice == 2) { //also, heal spells
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 4); //regen	
					dude[x].setPrestige(502);
				}
			}
			if (dude[x].getCharacterClass() == 6) {	//scout		mounted archer		assassin		ranger
				cout << "\nWhat do you want to prestige as?\n1: Mounted archer\n2: Assassin\n3: Ranger\n";
				cin >> classChoice;
				if (classChoice == 1) { //also ranged
					dude[x].setMove(dude[x].getMove() + 4); //move
					dude[x].setRange(dude[x].getRange() + 12); //range
					dude[x].setMissChance(dude[x].getMissChance() - 15);//raise chance to miss
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setPrestige(601);
				}
				else if (classChoice == 2) {//critical strike, and poison
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setPrestige(602);
				}
				else if (classChoice == 3) {//also double attack
					dude[x].setAttack(dude[x].getAttack() - 1); //attack
					dude[x].setRange(dude[x].getRange() + 8); //range
					dude[x].setPrestige(603);
				}
			}	
			if (dude[x].getCharacterClass() == 7) {	//mage		fire				water			arcane summoner
				cout << "\nWhat do you want to prestige as?\n1: Fire\n2: Water\n3: Arcane Summoner\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 5); //attack	
					dude[x].setPrestige(701);
				}
				else if (classChoice == 2) {
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setPrestige(702);
				}
				else if (classChoice == 3) {
					dude[x].setMaxMana(dude[x].getMaxMana() + 15); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 4); //regen	
					dude[x].setPrestige(703);
				}
			}
			if (dude[x].getCharacterClass() == 8) {	//warlock	druid				necromancer		spellsword
				cout << "\nWhat do you want to prestige as?\n1: Druid\n2: Necromancer\n3: Spellsword\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 3); //attack	
					dude[x].setMaxMana(dude[x].getMaxMana() - 10); //maxMana
					dude[x].setPrestige(801);
				}
				else if (classChoice == 2) {
					dude[x].setDefense(dude[x].getDefense() - 2); //defense
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 2); //regen	
					dude[x].setMaxHealth(dude[x].getMaxHealth() - 15);//maxhealth
					dude[x].setPrestige(802);
				}
				else if (classChoice == 3) {
					dude[x].setMove(dude[x].getMove() + 2); //move
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setManaRegen(dude[x].getManaRegen() - 1); //regen
					dude[x].setPrestige(803);
				}
				
			}
		
		}
	}
	
	for (x = teamSize1 + 1; x <= teamSize2 + teamSize1; x++ ) {
		if (dude[x].getLevel() == 7 && dude[x].getPrestige() == 0){
			cout << "\nCongratulations, you have now aquired enough experience to prestige\n";
	
			if (dude[x].getCharacterClass() == 1) {	//fighter	brawler				defender
				cout << "\nWhat do you want to prestige as?\n1: Brawler\n2: Defender\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 5); //attack
					dude[x].setDefense(dude[x].getDefense() + 1); //defense
					dude[x].setHealth(dude[x].getHealth() + 5); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 5);//maxhealth
					dude[x].setPrestige(101);
					
				}
				else if (classChoice == 2){
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10);//maxhealth
					dude[x].setMove(dude[x].getMove() - 1);//move
					dude[x].setPrestige(102);
				}
			}
			if (dude[x].getCharacterClass() == 2) {	//archer	crossbow			longbow
				cout << "\nWhat do you want to prestige as?\n1: Crossbowman\n2: Longbowman\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 11); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setMove(dude[x].getMove() - 1); //move
					dude[x].setPrestige(201);
				}
				else { //also, double attack
					dude[x].setAttack(dude[x].getAttack() - 2); //attack
					dude[x].setRange(dude[x].getRange() + 5); //range
					dude[x].setPrestige(202);
				}
			}
			if (dude[x].getCharacterClass() == 3) {	//priest	cleric				acolyte			paladin
				cout << "\nWhat do you want to prestige as?\n1: Cleric\n2: Acolyte\n3: Paladin\n";
				cin >> classChoice;
				if (classChoice == 1) { // heal
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setPrestige(301);
				}
				else if (classChoice == 2) { //bless curse revive heal
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 2); //regen	
					dude[x].setPrestige(302);
				}
				else if (classChoice == 3) { // heal smite
					dude[x].setAttack(dude[x].getAttack() + 4); //attack
					dude[x].setDefense(dude[x].getDefense() + 4); //defense
					dude[x].setHealth(dude[x].getHealth() + 5); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 5);//maxhealth
					dude[x].setMove(dude[x].getMove() - 1); //move
					dude[x].setManaRegen(dude[x].getManaRegen() - 3); //regen	
					dude[x].setMaxMana(dude[x].getMaxMana() - 20); //maxMana
					dude[x].setPrestige(303);
				}
			}
			if (dude[x].getCharacterClass() == 4) {	//berserker	battlerager			thumper
				cout << "\nWhat do you want to prestige as?\n1: Battlerager\n2: Thumper\n";
				cin >> classChoice;
				if (classChoice == 1) { //also double attack
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10); //maxhealth
					dude[x].setAttack(dude[x].getAttack() - 3); //attack
					dude[x].setDefense(dude[x].getDefense() - 1);//defense
					dude[x].setPrestige(401);
				}

				else if (classChoice == 2) { //also, bloodlust
					dude[x].setHealth(dude[x].getHealth() + 10); //health
					dude[x].setMaxHealth(dude[x].getMaxHealth() + 10);//maxhealth
					dude[x].setRange(dude[x].getRange() + 1); //range
					dude[x].setPrestige(402);
				}
			}
			if (dude[x].getCharacterClass() == 5) {	//knight	lancer				mounted pally
				cout << "\nWhat do you want to prestige as?\n1: Lancer\n2: Mounted Paladin\n";
				cin >> classChoice;
				if (classChoice == 1) { //better charge
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setMove(dude[x].getMove() + 3); //move
					dude[x].setPrestige(501);
				}
				else if (classChoice == 2) { //also, heal spells
					dude[x].setAttack(dude[x].getAttack() + 2); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 4); //regen	
					dude[x].setPrestige(502);
				}
			}
			if (dude[x].getCharacterClass() == 6) {	//scout		mounted archer		assassin		ranger
				cout << "\nWhat do you want to prestige as?\n1: Mounted archer\n2: Assassin\n3: Ranger\n";
				cin >> classChoice;
				if (classChoice == 1) { //also ranged
					dude[x].setMove(dude[x].getMove() + 4); //move
					dude[x].setRange(dude[x].getRange() + 12); //range
					dude[x].setMissChance(dude[x].getMissChance() - 15);//raise chance to miss
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setPrestige(601);
				}
				else if (classChoice == 2) {//critical strike, and poison
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setPrestige(602);
				}
				else if (classChoice == 3) {//also double attack
					dude[x].setAttack(dude[x].getAttack() - 1); //attack
					dude[x].setRange(dude[x].getRange() + 8); //range
					dude[x].setPrestige(603);
				}
			}
			if (dude[x].getCharacterClass() == 7) {	//mage		fire				water			arcane summoner
				cout << "\nWhat do you want to prestige as?\n1: Fire\n2: Water\n3: Arcane Summoner\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 5); //attack	
					dude[x].setPrestige(701);
				}
				else if (classChoice == 2) {
					dude[x].setDefense(dude[x].getDefense() + 3); //defense
					dude[x].setPrestige(702);
				}
				else if (classChoice == 3) {
					dude[x].setMaxMana(dude[x].getMaxMana() + 15); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 4); //regen	
					dude[x].setPrestige(703);
				}
			}
			if (dude[x].getCharacterClass() == 8) {	//warlock	druid				necromancer		spellsword
				cout << "\nWhat do you want to prestige as?\n1: Druid\n2: Necromancer\n3: Spellsword\n";
				cin >> classChoice;
				if (classChoice == 1) {
					dude[x].setAttack(dude[x].getAttack() + 3); //attack	
					dude[x].setMaxMana(dude[x].getMaxMana() - 10); //maxMana
					dude[x].setPrestige(801);
				}
				else if (classChoice == 2) {
					dude[x].setDefense(dude[x].getDefense() - 2); //defense
					dude[x].setMaxMana(dude[x].getMaxMana() + 10); //maxMana
					dude[x].setManaRegen(dude[x].getManaRegen() + 2); //regen	
					dude[x].setMaxHealth(dude[x].getMaxHealth() - 15);//maxhealth
					dude[x].setPrestige(802);
				}
				else if (classChoice == 3) {
					dude[x].setMove(dude[x].getMove() + 2); //move
					dude[x].setAttack(dude[x].getAttack() + 3); //attack
					dude[x].setDefense(dude[x].getDefense() + 2); //defense
					dude[x].setManaRegen(dude[x].getManaRegen() - 1); //regen
					dude[x].setPrestige(803);
				}
				
			}
		
		}
	}
	
	assignPrestige(); //adds the prestige name
	return;
}

void assignParagon() {
	int l = 1;
	int x = 0;
	
	for (l=1; l<= teamSize1 + teamSize2; l++) {
		switch (dude[l].getParagon()) {
			case 1011:
			dude[l].setParagonName(par1011);
			break;
			
			case 1012:
			dude[l].setParagonName(par1012);
			break;
			
			case 1021:
			dude[l].setParagonName(par1021);
			break;
			
			case 1022:
			dude[l].setParagonName(par1022);
			break;
			
			
			case 2011:
			dude[l].setParagonName(par2011);
			break;
			
			case 2012:
			dude[l].setParagonName(par2012);
			break;
			
			case 2021:
			dude[l].setParagonName(par2021);
			break;
			
			case 2022:
			dude[l].setParagonName(par2022);
			break;
			
			
			case 3011:
			dude[l].setParagonName(par3011);
			break;
			
			case 3012:
			dude[l].setParagonName(par3012);
			break;
			
			case 3021:
			dude[l].setParagonName(par3021);
			break;
			
			case 3022:
			dude[l].setParagonName(par3022);
			break;
			
			case 3031:
			dude[l].setParagonName(par3031);
			break;
			
			case 3032:
			dude[l].setParagonName(par3032);
			break;
			
			
			case 4011:
			dude[l].setParagonName(par4011);
			break;
			
			case 4012:
			dude[l].setParagonName(par4012);
			break;
			
			case 4021:
			dude[l].setParagonName(par4021);
			break;
			
			case 4022:
			dude[l].setParagonName(par4022);
			break;
			
			
			case 5011:
			dude[l].setParagonName(par5011);
			break;
			
			case 5012:
			dude[l].setParagonName(par5012);
			break;
			
			case 5021:
			dude[l].setParagonName(par5021);
			break;
			
			case 5022:
			dude[l].setParagonName(par5022);
			break;
			
			
			case 6011:
			dude[l].setParagonName(par6011);
			break;
			
			case 6012:
			dude[l].setParagonName(par6012);
			break;
			
			case 6021:
			dude[l].setParagonName(par6021);
			break;
			
			case 6022:
			dude[l].setParagonName(par6022);
			break;
			
			case 6031:
			dude[l].setParagonName(par6031);
			break;
			
			case 6032:
			dude[l].setParagonName(par6032);
			break;
			
			
			case 7011:
			dude[l].setParagonName(par7011);
			break;
			
			case 7012:
			dude[l].setParagonName(par7012);
			break;
			
			case 7021:
			dude[l].setParagonName(par7021);
			break;
			
			case 7022:
			dude[l].setParagonName(par7022);
			break;
			
			case 7031:
			dude[l].setParagonName(par7031);
			break;
			
			case 7032:
			dude[l].setParagonName(par7032);
			break;
			
			
			case 8011:
			dude[l].setParagonName(par8011);
			break;
			
			case 8012:
			dude[l].setParagonName(par8012);
			break;
			
			case 8021:
			dude[l].setParagonName(par8021);
			break;
			
			case 8022:
			dude[l].setParagonName(par8022);
			break;
			
			case 8031:
			dude[l].setParagonName(par8031);
			break;
			
			case 8032:
			dude[l].setParagonName(par8032);
			break;
		}
	}	

	
}

void paragon() {
	int x=0, paragonChoice;
	
	
	for (x=1; x <= teamSize1 + teamSize2; x++) {
		if (dude[x].getLevel() == 12 && dude[x].getParagon() == 0){
			cout << "\nCongratulations, you are becoming a paragon, and nearing the highest level of your class.\n";
			
			if (dude[x].getPrestige() == 101) {	//brawler
				cout << "What are you considered a paragon for your mastery of?\n 1:Bullrushing\n 2:Vice-grip\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//bullrush
					
					
					dude[x].setParagon(1011);
					
				}
				else if (paragonChoice == 2){//vice grip
					
					dude[x].setParagon(1012);
				}
			}
			if (dude[x].getPrestige() == 102) {	//defender
				cout << "What are you considered a paragon for your mastery of?\n 1:Nullification\n 2:Fortification\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//nullification
					//defender of nullification gets rid of their weakness to magic
					dude[x].setParagon(1021);
					
				}
				else if (paragonChoice == 2){//fortification
					
					dude[x].setParagon(1022);
				}
			}
			
			if (dude[x].getPrestige() == 201) {	//crossbowman
				cout << "What are you considered a paragon for your mastery of?\n 1:Conflagration\n 2:Dexterity\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//conflagration
					
					dude[x].setParagon(2011);
					
				}
				else if (paragonChoice == 2){//dexterity
					
					dude[x].setParagon(2012);
				}
			}
			if (dude[x].getPrestige() == 202) {	//longbowman
				cout << "What are you considered a paragon for your mastery of?\n 1:Precision\n 2:Piercing\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//precision
					dude[x].setMissChance(dude[x].getMissChance() - 1);//lower chance to miss
					dude[x].setParagon(2021);
					
				}
				else if (paragonChoice == 2){//piercing
					
					dude[x].setParagon(2022);
				}
			}
			
			if (dude[x].getPrestige() == 301) {	//cleric
				cout << "What are you considered a paragon for your mastery of?\n 1:Healing\n 2:Compassion\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//healing
					
					dude[x].setParagon(3011);
					
				}
				else if (paragonChoice == 2){//compassion
					
					dude[x].setParagon(3012);
				}
			}
			if (dude[x].getPrestige() == 302) {	//acolyte
				cout << "What are you considered a paragon for your mastery of?\n 1:Revival\n 2:Vlessing\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//revival
					
					dude[x].setParagon(3021);
					
				}
				else if (paragonChoice == 2){//blessing
					
					dude[x].setParagon(3022);
				}
			}
			if (dude[x].getPrestige() == 303) {	//paladin
				cout << "What are you considered a paragon for your mastery of?\n 1:Holiness\n 2:Righteousness\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//holiness
					dude[x].setStartingMana(dude[x].getStartingMana() + 10);
					dude[x].setParagon(3031);
					
				}
				else if (paragonChoice == 2){//righteousness
					
					dude[x].setParagon(3032);
				}
			}
			
			if (dude[x].getPrestige() == 401) {	//battlerager
				cout << "What are you considered a paragon for your mastery of?\n 1:Aerobics\n 2:Grappling\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//aerobics
					
					dude[x].setParagon(4011);
					
				}
				else if (paragonChoice == 2){//grappling
					
					dude[x].setParagon(4012);
				}
			}
			if (dude[x].getPrestige() == 402) {	//thumper
				cout << "What are you considered a paragon for your mastery of?\n 1:Bounding\n 2:Bloodthirst\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//bounding
					
					dude[x].setParagon(4021);
					
				}
				else if (paragonChoice == 2){//bloodthirst
					
					dude[x].setParagon(4022);
				}
			}
			
			if (dude[x].getPrestige() == 501) {	//lancer
				cout << "What are you considered a paragon for your mastery of?\n 1:Reaching\n 2:Expeditedness\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//reaching
					dude[x].setRange(dude[x].getRange() + 1); //range
					dude[x].setParagon(5011);
					//lancer of reaching
					
				}
				else if (paragonChoice == 2){//expeditedeness
					
					dude[x].setParagon(5012);
				}
			}
			if (dude[x].getPrestige() == 502) {	//mounted paladin
				cout << "What are you considered a paragon for your mastery of?\n 1:Smiting\n 2:Shielding\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//smiting
					
					dude[x].setParagon(5021);
					
				}
				else if (paragonChoice == 2){//shielding
					
					dude[x].setParagon(5022);
				}
			}
			
			if (dude[x].getPrestige() == 601) {	//mounted archer
				cout << "What are you considered a paragon for your mastery of?\n 1:Quick-Shot\n 2:Split-Shot\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//quick-shot
					
					dude[x].setAttack(dude[x].getAttack() - 2); //attack
					dude[x].setParagon(6011);
					
				}
				else if (paragonChoice == 2){//split-shot
					
					dude[x].setParagon(6012);
				}
			}
			if (dude[x].getPrestige() == 602) {	//assassin
				cout << "What are you considered a paragon for your mastery of?\n 1:Incapacitation\n 2:Vitriol\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//incapacitation
					
					dude[x].setParagon(6021);
					
				}
				else if (paragonChoice == 2){//vitriol
					
					dude[x].setParagon(6022);
				}
			}
			if (dude[x].getPrestige() == 603) {	//ranger
				cout << "What are you considered a paragon for your mastery of?\n 1:Venom\n 2:Herbs\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//venom
					
					dude[x].setParagon(6031);
					
				}
				else if (paragonChoice == 2){//herbs
					
					dude[x].setParagon(6032);
				}
			}
			
			if (dude[x].getPrestige() == 701) {	//fire-mage
				cout << "What are you considered a paragon for your mastery of?\n 1:Infernos\n 2:Repulsion\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//infernos
					
					dude[x].setParagon(7011);
					
				}
				else if (paragonChoice == 2){//repulsion
					
					dude[x].setParagon(7012);
				}
			}
			if (dude[x].getPrestige() == 702) {	//water-mage
				cout << "What are you considered a paragon for your mastery of?\n 1:Frost\n 2:Barriers\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//frost
					
					dude[x].setParagon(7021);
					
				}
				else if (paragonChoice == 2){//barriers
					
					dude[x].setParagon(7022);
				}
			}
			if (dude[x].getPrestige() == 703) {	//arcane-summoner
				cout << "What are you considered a paragon for your mastery of?\n 1:Unbridled-Power\n 2:Imbuing\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//unbridled-power
					
					dude[x].setParagon(7031);
					
				}
				else if (paragonChoice == 2){//imbuing
					
					dude[x].setParagon(7032);
				}
			}
			
			if (dude[x].getPrestige() == 801) {	//druid
				cout << "What are you considered a paragon for your mastery of?\n 1:Morphing\n 2:Nature\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//morphing
					
					dude[x].setParagon(8011);
					
				}
				else if (paragonChoice == 2){//nature
					
					dude[x].setParagon(8012);
				}
			}
			if (dude[x].getPrestige() == 802) {	//necromancer
				cout << "What are you considered a paragon for your mastery of?\n 1:Resurrection\n 2:Malediction\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//resurrection
					
					dude[x].setParagon(8021);
					
				}
				else if (paragonChoice == 2){//malediction
					
					dude[x].setParagon(8022);
				}
			}
			if (dude[x].getPrestige() == 803) {	//spellsword
				cout << "What are you considered a paragon for your mastery of?\n 1:Unleashing\n 2:Enchanting\n";
				cin >> paragonChoice;
				if (paragonChoice == 1) {//unleashing
					
					dude[x].setParagon(8031);
					
				}
				else if (paragonChoice == 2){//enchanting
					
					dude[x].setParagon(8032);
				}
			}
			
				
		
		}
	}
	
	assignParagon(); //adds the paragon modifier
	return;
}

void assignRenown() {
	int l = 1;
	int x = 0;
	
	for (l=1; l<= teamSize1 + teamSize2; l++) {
		switch (dude[l].getRenown()) {
			case 101:
			dude[l].setRenownName(r101);
			break;
			
			case 102:
			dude[l].setRenownName(r102);
			break;
			
			case 201:
			dude[l].setRenownName(r201);
			break;
			
			case 202:
			dude[l].setRenownName(r202);
			break;
			
			
			case 301:
			dude[l].setRenownName(r301);
			break;
			
			case 302:
			dude[l].setRenownName(r302);
			break;
			
			
			case 401:
			dude[l].setRenownName(r401);
			break;
			
			case 402:
			dude[l].setRenownName(r402);
			break;
			
			
			case 501:
			dude[l].setRenownName(r501);
			break;
			
			case 502:
			dude[l].setRenownName(r502);
			break;
			
			
			case 601:
			dude[l].setRenownName(r601);
			break;
			
			case 602:
			dude[l].setRenownName(r602);
			break;
			
			
			case 701:
			dude[l].setRenownName(r701);
			break;
			
			case 702:
			dude[l].setRenownName(r702);
			break;
			
			
			case 801:
			dude[l].setRenownName(r801);
			break;
			
			case 802:
			dude[l].setRenownName(r802);
			break;
		}
	}	

	
}

void renown() {
	int x=0, renownChoice;
	
	
	for (x=1; x<= teamSize1 + teamSize2; x++) {
		if (dude[x].getLevel() == 4 && dude[x].getRenown() == 0){
			cout << "\nCongratulations, you are now starting to becomed renowned for your work.\n";
			
			if (dude[x].getCharacterClass() == 1) {	//fighter	Tomahawking		overbearing
				cout << "What are you renowned for being?\n 1:Tomahawking\n 2:Overbearing\n";
				cin >> renownChoice;
				if (renownChoice == 1) {//axeThrow
					
					dude[x].setRenown(101);
					
				}
				else if (renownChoice == 2){//pushback
					
					dude[x].setRenown(102);
				}
			}
			if (dude[x].getCharacterClass() == 2) {	//archer	accurate		nimble
				cout << "What are you renowned for being?\n 1:Accurate\n 2:Nimble\n";
				cin >> renownChoice;
				if (renownChoice == 1) {//full round attack at 100% accuracy
					dude[x].setMissChance(dude[x].getMissChance() - 1);//lower chance to miss
					dude[x].setRenown(201);
				}
				else { 
					
					dude[x].setRenown(202);//can move uphill better
				}
			}
			if (dude[x].getCharacterClass() == 3) {	//priest	blessed			miraculous	
				cout << "What are you renowned for being?\n 1:Blessed\n 2:Miraculous\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //random stat boost at beginning of a game for the duration of that game
					
					dude[x].setRenown(301);
				}
				else if (renownChoice == 2) { //random chance to regain health or mana (higher chance with lower health/mana)
					
					dude[x].setRenown(302);
				}
				
			}
			if (dude[x].getCharacterClass() == 4) {	//berserker	raging			sprinting
				cout << "What are you renowned for being?\n 1:Raging\n 2:Sprinting\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //lose 1/4 health to gain 1/4 attack for a turn or two
					
					dude[x].setRenown(401);
				}

				else if (renownChoice == 2) { //gets to move extra on first turn
					
					dude[x].setRenown(402);
				}
			}
			if (dude[x].getCharacterClass() == 5) {	//knight	inspiring		untouchable
				cout << "What are you renowned for being?\n 1:Inspiring\n 2:Untouchable\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //raise attack for allies
					
					dude[x].setRenown(501);
				}
				else if (renownChoice == 2) { //even better defense from charging
					
					dude[x].setRenown(502);
				}
			}
			if (dude[x].getCharacterClass() == 6) {	//scout		backstabbing	dazing	
				cout << "What are you renowned for being?\n 1:Backstabbing\n 2:Dazing\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //skip half of armour or something
					
					dude[x].setRenown(601);
				}
				else if (renownChoice == 2) { //stuns someone (reset their ap right before their turn)
					
					dude[x].setRenown(602);
				}
				
			}	
			if (dude[x].getCharacterClass() == 7) {	//mage		rapid-fire		mystic
				cout << "What are you renowned for being?\n 1:Rapid-fire\n 2:Mystic\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //mage missile fires an additional ball
					
					dude[x].setRenown(701);
				}
				else if (renownChoice == 2) { // +3 to normal attack (but don't actually raise the attack stat)
					
					dude[x].setRenown(702);
				}
				
			}
			if (dude[x].getCharacterClass() == 8) {	//warlock	earthshaking	animalistic
				cout << "What are you renowned for being?\n 1:Earthshaking\n 2:Animalistic\n";
				cin >> renownChoice;
				if (renownChoice == 1) { //gets earthquake
					
					dude[x].setRenown(801);
				}
				else if (renownChoice == 2) { //has a wolf familiar or something whose stats are proportional, lowers some stats
					dude[x].setAttack(dude[x].getAttack() - 1); //attack
					dude[x].setDefense(dude[x].getDefense() - 1); //defense
					dude[x].setManaRegen(dude[x].getManaRegen() - 2); //regen	
					
					dude[x].setRenown(802);
				}
				
				
			}
		
		}
	}
	
	assignRenown(); //adds the renown modifier
	return;
}

void levelUp() {
	int x=0;
	int levelupchoice = 0, statchoice=0;
	
	for (x=1; x <= teamSize1 + teamSize2; x++) {
		if (dude[x].getXp() >=(50 + (dude[x].getLevel() * 30))) { //checks if they have enough xp, need more at higher levels
				
				dude[x].setLevel(dude[x].getLevel() + 1); //adds a level
				
				cout << endl << epithet(x)  << " has leveled up to level " << dude[x].getLevel() << endl << endl;
				
				if(dude[x].getLevel() %  2 == 0) { //on even levels they get to raise a stat
					cout << "\nWhat stat would you like to raise?\n1: Attack+1\n2: Defense+1\n3: Movement+1\n4: Max health+5\n";
					cout << "5: Accuracy+2\n6: Evasion+2\n";
					if (dude[x].getMaxMana() > 0) {cout << "7: Starting mana+5\n8: Max mana+5\n9: Mana regen+1\n";}
					if (dude[x].getRange() > 3) { cout << "10:Range+3\n"; }
					
					cin >> statchoice;
					
					if (statchoice == 1) {dude[x].setAttack(dude[x].getAttack() + 1);}//raises attack
					if (statchoice == 2) {dude[x].setDefense(dude[x].getDefense() + 1);}//raises defense
					if (statchoice == 3) {dude[x].setMove(dude[x].getMove() + 1);}//raises movement
					if (statchoice == 4) {dude[x].setMaxHealth(dude[x].getMaxHealth() + 5); dude[x].setHealth(dude[x].getHealth() + 5);}//raises max and current health
					if (statchoice == 5) {dude[x].setMissChance(dude[x].getMissChance() - 2);}//lower chance to miss
					if (statchoice == 6) {dude[x].setEvasion(dude[x].getEvasion() + 2);}//raises evasion
					if (statchoice == 7) {dude[x].setStartingMana(dude[x].getStartingMana() + 5);}//raises starting mana
					if (statchoice == 8) {dude[x].setMaxMana(dude[x].getMaxMana() + 5);}//raises max mana
					if (statchoice == 9) {dude[x].setManaRegen(dude[x].getManaRegen() + 1);}//raises mana regen
					if (statchoice == 10) {dude[x].setRange(dude[x].getRange() + 3);}//raises range
				}					
				if (dude[x].getMaxMana() > 0) {//checks if they are a spellcaster to raise mana pool
					int manaRaise = 4;
					switch (dude[x].getCharacterClass()) {
						case 1://fighter
							manaRaise = manaRaise - 1;
							break;
						case 2://archer
							manaRaise = manaRaise - 1;
							break;
						case 3://priest
							manaRaise = manaRaise;
							break;
						case 4://berserker
							manaRaise = manaRaise - 1 + upOrDown();// +0, +1, or +2
							break;
						case 5://knight
							manaRaise = manaRaise;
							break;
						case 6://scout
							manaRaise = manaRaise;
							break;
						case 7://mage
							manaRaise = manaRaise + 1;
							break;
						case 8://warlock
							manaRaise = manaRaise + 1 + upOrDown();
							break;
						default:
							manaRaise = manaRaise;
							break;
					}
							
					switch(dude[x].getRace()) {
						case 1://human
							manaRaise = manaRaise + upOrDown();
							break;
						case 2://wood
							manaRaise = manaRaise + 1;
							break;
						case 3://high
							manaRaise = manaRaise + 2;
							break;
						case 4://dark
							manaRaise = manaRaise;
							break;
						case 5://hill
							manaRaise = manaRaise - 1;
							break;
						case 6://mountain
							manaRaise = manaRaise + 1;
							break;
						case 7://halfling
							manaRaise = manaRaise;
							break;
						case 8://orc
							manaRaise = manaRaise - 2;
							break;
						case 9://centaur
							manaRaise = manaRaise;
							break;
						default:
							manaRaise = manaRaise;
							break;
						
					}
					dude[x].setMaxMana(dude[x].getMaxMana() + manaRaise); //raises mana pool a little
					if (dude[x].getLevel() %  2 == 1) {
						dude[x].setManaRegen(dude[x].getManaRegen() + 1); //on odd levels, raises their regen
					}
				}
				
				int healthRaise = 8 + upOrDown();//standard amount 7, 8, 9
				switch (dude[x].getCharacterClass()) {
					case 1://fighter
						healthRaise = healthRaise + 1;
						break;
					case 2://archer
						healthRaise = healthRaise - 1;
						break;
					case 3://priest
						healthRaise = healthRaise;
						break;
					case 4://berserker
						healthRaise = healthRaise + 1 + upOrDown();// +0, +1, or +2
						break;
					case 5://knight
						healthRaise = healthRaise + 2;
						break;
					case 6://scout
						healthRaise = healthRaise;
						break;
					case 7://mage
						healthRaise = healthRaise - 1;
						break;
					case 8://warlock
						healthRaise = healthRaise - 1;
						break;
					default:
						healthRaise = healthRaise;
						break;
				}
						
				switch(dude[x].getRace()) {
					case 1://human
						healthRaise = healthRaise + upOrDown();
						break;
					case 2://wood
						healthRaise = healthRaise;
						break;
					case 3://high
						healthRaise = healthRaise - 2;
						break;
					case 4://dark
						healthRaise = healthRaise - 3;
						break;
					case 5://hill
						healthRaise = healthRaise + 1;
						break;
					case 6://mountain
						healthRaise = healthRaise + 2;
						break;
					case 7://halfling
						healthRaise = healthRaise;
						break;
					case 8://orc
						healthRaise = healthRaise + 1;
						break;
					case 9://centaur
						healthRaise = healthRaise + 2;
						break;
					default:
						healthRaise = healthRaise;
						break;
					
				}
				
					
					
				
				dude[x].setMaxHealth(dude[x].getMaxHealth() + (healthRaise) ); //raises their max health
				dude[x].setHealth(dude[x].getHealth() + (healthRaise) ); //raises their current health
				
				dude[x].setXp(dude[x].getXp() - (50 + (dude[x].getLevel() * 30) - 30) );//resets xp for the next level
				
				prestige();
				renown();
				paragon();
		}
	}

	return;
}

void assignStartingMana() {
	
	int l = 1;
	int x = 0;
	
	for (l=1; l<= teamSize1 + teamSize2; l++) {
		dude[l].setMana(dude[l].getStartingMana());//starting mana
		}	

	
}
	
void assignVariousOtherStats() {
	
	int l = 1;
	int x = 0;
	int lClass = 0, lPrestige = 0;
	for (l=1; l<= teamSize1 + teamSize2; l++) {
		lClass = dude[l].getCharacterClass();
		lPrestige = dude[l].getPrestige();
		if (lClass == 7 || lClass == 8) {//mages and warlocks
			dude[l].setIsArcane(true);
		}
		if (lClass == 3 || lClass == 8 || lPrestige == 502) {//priests, warlocks, and mounted paladins
			dude[l].setIsDivine(true);
		}
		
		
	}	

}


//if someone wins, this will send the final information from the game to a text file
void infodump() {
	
	int x=0;
	time_t now = time(0); //captures the time
	char* dt = ctime(&now);
	
	ofstream hall_of_heroes;
	
	hall_of_heroes.open("hall_of_heroes.txt", fstream :: app); //opens the hall of heroes
	
		if(hall_of_heroes.fail())  //checks if the file opened right
	{
		cout << "Hall of heros file open failed" << endl;
		return;
	}
	
	hall_of_heroes << endl << "On " << dt;
	hall_of_heroes << winner << loser;
	hall_of_heroes << endl << "In " << turnCounter << " turns\n";
	
	
	hall_of_heroes << endl << teamNames[1] << " your team was:\n";
    
for (x=1; x <= teamSize1; x++) {
	
	 hall_of_heroes << "Number:   " << x << endl;
     hall_of_heroes << "Name:     " << dude[x].getName() << endl << "Race:     " << dude[x].getRaceName() << endl << "Class:    " << dude[x].getRenownName() << dude[x].getCharacterClassName() << endl;
     hall_of_heroes << "Attack:   " << dude[x].getAttack() << endl;
     hall_of_heroes << "Defense:  " << dude[x].getDefense() << endl;
     hall_of_heroes << "Health:   ";
    if (dude[x].getHealth() <= 0) { hall_of_heroes << "dead\n"; } else hall_of_heroes << dude[x].getHealth() << "/" << dude[x].getMaxHealth() << endl;
    if (dude[x].getCharacterClass() == 3 || dude[x].getCharacterClass() == 7) {hall_of_heroes << "Mana:     " << dude[x].getMana() << "/" << dude[x].getMaxMana() << endl;}
     hall_of_heroes << "Move:     " << dude[x].getMove() << endl;
     hall_of_heroes << "Range:    " << dude[x].getRange() - 1 << endl;
     hall_of_heroes << "XP:       " << dude[x].getXp() << endl;
     hall_of_heroes << "Level:    " << dude[x].getLevel() << endl;
     hall_of_heroes << "Location: (" << dude[x].getXpos() << "," << dude[x].getYpos() << ")" << endl << endl;
   }
	
	hall_of_heroes << endl;
	
	hall_of_heroes << endl << teamNames[2] << " your team was:\n";

//this'll shoot out the stats for everyone
   for (x = teamSize1 + 1; x <= teamSize2 + teamSize1; x++ ) {
	
	hall_of_heroes << "Number:   " << (x - teamSize1) << endl;
    hall_of_heroes << "Name:     " << dude[x].getName() << endl << "Race:     " << dude[x].getRaceName() << endl << "Class:    " << dude[x].getRenownName() << dude[x].getCharacterClassName() << endl;
    hall_of_heroes << "Attack:   " << dude[x].getAttack() << endl;
    hall_of_heroes << "Defense:  " << dude[x].getDefense() << endl;
    hall_of_heroes << "Health:   ";
    if (dude[x].getHealth() <= 0) {hall_of_heroes << "dead\n"; } else hall_of_heroes << dude[x].getHealth() << "/" << dude[x].getMaxHealth() << endl;
    if (dude[x].getCharacterClass() == 3 || dude[x].getCharacterClass() == 7) {hall_of_heroes << "Mana:     " << dude[x].getMana() << "/" << dude[x].getMaxMana() << endl;}
    hall_of_heroes << "Move:     " << dude[x].getMove() << endl;
    hall_of_heroes << "Range:    " << dude[x].getRange() - 1 << endl;
    hall_of_heroes << "XP:       " << dude[x].getXp() << endl;
    hall_of_heroes << "Level:    " << dude[x].getLevel() << endl;
    hall_of_heroes << "Location: (" << dude[x].getXpos() << "," << dude[x].getYpos() << ")" << endl << endl;
   }
	hall_of_heroes.close();
	
	return;
}

void moreRandom() {
	int i = 0, j = 0;
	
	if (moreRandomTeam1 == 1) {
		for (i=1; i <= teamSize1; i++) {
			if (dude[i].getXp() == 0 && dude[i].getLevel() == 0) {//if they are a new character
				
				dude[i].setAttack(dude[i].getAttack() + upOrDown() );//attack
				dude[i].setDefense(dude[i].getDefense() + upOrDown() ); //defense
				dude[i].setMove(dude[i].getMove() + upOrDown() ); //move
				dude[i].setMaxHealth(dude[i].getMaxHealth() + (5 * upOrDown() ) ); //max health
				dude[i].setEvasion(dude[i].getEvasion() + (2 * upOrDown() ) ); //evasion
				dude[i].setMissChance(dude[i].getMissChance() + (2 * upOrDown() ) ); //accuracy
				
				if (dude[i].getMaxMana() > 0) {
					dude[i].setStartingMana(dude[i].getStartingMana() + (5 * upOrDown() ) ); //starting mana
					dude[i].setMaxMana(dude[i].getMaxMana() + (5 * upOrDown() ) ); //max mana
					dude[i].setManaRegen(dude[i].getManaRegen() + upOrDown() ); //mana regen
				}
				
				if (dude[i].getRange() > 3) {
					dude[i].setRange(dude[i].getRange() + (5*upOrDown() ) );//range
				}
			}
			
		}
	}
	if (moreRandomTeam2 == 1) {
		for (j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++) {
			if (dude[j].getXp() == 0 && dude[j].getLevel() == 0) {//if they are a new character
				
				dude[j].setAttack(dude[j].getAttack() + upOrDown() );//attack
				dude[j].setDefense(dude[j].getDefense() + upOrDown() ); //defense
				dude[j].setMove(dude[j].getMove() + upOrDown() ); //move
				dude[j].setMaxHealth(dude[j].getMaxHealth() + (5 * upOrDown() ) ); //max health
				dude[j].setEvasion(dude[j].getEvasion() + (2 * upOrDown() ) ); //evasion
				dude[j].setMissChance(dude[j].getMissChance() + (2 * upOrDown() ) ); //accuracy
				
				if (dude[j].getMaxMana() > 0) {
					dude[j].setStartingMana(dude[j].getStartingMana() + (5 * upOrDown() ) ); //starting mana
					dude[j].setMaxMana(dude[j].getMaxMana() + (5 * upOrDown() ) ); //max mana
					dude[j].setManaRegen(dude[j].getManaRegen() + upOrDown() ); //mana regen
				}
				
				if (dude[j].getRange() > 3) {
					dude[j].setRange(dude[j].getRange() + (5*upOrDown() ) );//range
				}
			}
			
		}
		
	} 
	
	return;
}

//Assigns the race names to each guy
void assignRace() {
	int l = 1;
	int x = 0;
	for ( l = 1; l <= teamSize1 + teamSize2; l++ ) {
		
	
    if(dude[l].getRace() == 1) {dude[l].setRaceName("Human");}
    else if(dude[l].getRace() == 2) {dude[l].setRaceName("Wood elf");}
    else if(dude[l].getRace() == 3) {dude[l].setRaceName("High elf");}
    else if(dude[l].getRace() == 4) {dude[l].setRaceName("Dark elf");}
    else if(dude[l].getRace() == 5) {dude[l].setRaceName("Hill dwarf");}
    else if(dude[l].getRace() == 6) {dude[l].setRaceName("Mountain dwarf");}
    else if(dude[l].getRace() == 7) {dude[l].setRaceName("Halfling");}
    else if(dude[l].getRace() == 8) {dude[l].setRaceName("Orc");}
    else if(dude[l].getRace() == 9) {dude[l].setRaceName("Centaur");}
	else if(dude[l].getRace() == 101) {dude[l].setRaceName("Wolf");}
    else if(dude[l].getRace() == 102) {dude[l].setRaceName("Bear");}
    else if(dude[l].getRace() == 103) {dude[l].setRaceName("Goblin");}
    else if(dude[l].getRace() == 104) {dude[l].setRaceName("Goblin");}
    else if(dude[l].getRace() == 105) {dude[l].setRaceName("Golem");}
    else if(dude[l].getRace() == 106) {dude[l].setRaceName("Golem");} 
    else if(dude[l].getRace() == 107) {dude[l].setRaceName("Goblin");} 
	else if(dude[l].getRace() == 108) {dude[l].setRaceName("Goblin");} 
	else if(dude[l].getRace() == 109) {dude[l].setRaceName("Rat");} 
	else if(dude[l].getRace() == 110) {dude[l].setRaceName("Beetle");} 
	else if(dude[l].getRace() == 111) {dude[l].setRaceName("Ant");} 
}
	
}

//Assigns birthright names
void assignBirthRight() {
	int l = 1;
	int x = 0;
	for ( l = 1; l <= teamSize2 + teamSize1; l++ ) {
	
	if(dude[l].getBirthRight() > 100) {dude[l].setBirthRightName("Dragonspawn");}
    else if(dude[l].getBirthRight() == 2) {dude[l].setBirthRightName("Vampire");}
    else if(dude[l].getBirthRight() == 3) {dude[l].setBirthRightName("Werewolf");}
    else if(dude[l].getBirthRight() == 4) {dude[l].setBirthRightName("Spellscarred");}
    else if(dude[l].getBirthRight() == 5) {dude[l].setBirthRightName("Lucky");}
}
	
return;
}


//Assigns the class names to each guy
void assignClass() {
	int l = 1;
	int x = 0;
	for ( l = 1; l <= teamSize1 + teamSize2; l++ ) {
	
    if(dude[l].getCharacterClass() == 1) {dude[l].setClassName(fighterName);}
    else if(dude[l].getCharacterClass() == 2) {dude[l].setClassName(archerName);}
    else if(dude[l].getCharacterClass() == 3) {dude[l].setClassName(priestName);}
    else if(dude[l].getCharacterClass() == 4) {dude[l].setClassName(berserkerName);}
    else if(dude[l].getCharacterClass() == 5) {dude[l].setClassName(knightName);}
    else if(dude[l].getCharacterClass() == 6) {dude[l].setClassName(scoutName);}
    else if(dude[l].getCharacterClass() == 7) {dude[l].setClassName(mageName);}
    else if(dude[l].getCharacterClass() == 8) {dude[l].setClassName(warlockName);}
	else if(dude[l].getCharacterClass() == 101) {dude[l].setClassName(wolfName);}
    else if(dude[l].getCharacterClass() == 102) {dude[l].setClassName(bearName);}
    else if(dude[l].getCharacterClass() == 103) {dude[l].setClassName(goblinFighterName);}
    else if(dude[l].getCharacterClass() == 104) {dude[l].setClassName(goblinArcherName);}
    else if(dude[l].getCharacterClass() == 105) {dude[l].setClassName(stoneGolemName);}
    else if(dude[l].getCharacterClass() == 106) {dude[l].setClassName(ironGolemName);} 
    else if(dude[l].getCharacterClass() == 107) {dude[l].setClassName(goblinMageName);} 
	else if(dude[l].getCharacterClass() == 108) {dude[l].setClassName(goblinPriestName);} 
	else if(dude[l].getCharacterClass() == 109) {dude[l].setClassName(giantRatName);} 
	else if(dude[l].getCharacterClass() == 110) {dude[l].setClassName(giantBeetleName);} 
	else if(dude[l].getCharacterClass() == 111) {dude[l].setClassName(giantAntName);} 
}
	
return;
}


void arcaneSummonerManaStream() {
	int spellChoice = 0, j = 0, damage = 0, manaAmount = 0;
	
	
	if (dude[moveGuy].getMana() >= 0)
	{
		cout << "You have " << dude[moveGuy].getMana() << " mana.\n";
		cout << "How much mana do you wish to stream?\n";
		cin >> manaAmount;
		
		if (manaAmount > dude[moveGuy].getMana()) {
			cout << "\nYou do not have that much mana.\n\n";
			arcaneSummonerManaStream();
		}
		
		
		cout << "\nWho do you wish to stream the mana to?\n0: no one\n";
		
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0 && dude[j].getMaxMana() > 0) { //checks for alllies who aren't dead, and use mana
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0 && dude[j].getMaxMana() > 0) { //checks for allies who aren't dead, and use mana
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (49 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A stream of glowing blue light glides from "<< dude[moveGuy].getName() << " to " << dude[spellChoice].getName() << endl;
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - manaAmount); //uses up mana
					dude[spellChoice].setMana(dude[spellChoice].getMana() + manaAmount); //adds mana
					
					cout << endl << dude[moveGuy].getName() << " now has " << dude[moveGuy].getMana() << " mana, and ";
					cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getMana() << " mana\n\n";
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	
	return;
	
}

//range 3 mana 15 turns 2
void mageProtectRanged() { 
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 15)
	{
		cout << "\nWho do you wish to shield from ranged attacks?\n0: no one\n";
		
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for alllies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A glowing shield of light envelopes "<< dude[spellChoice].getName() << endl;
					

					protectRangedTimer[spellChoice] = 2; //last for 2 turns
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 15); //uses up 15 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	
	return;
}

//15 mana, blocks defense/2 for 2 rounds
void mageShield() {
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 15)
	{
		cout << "\nWho do you wish to shield?\n0: no one\n";
		
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for alllies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A glowing shield of light envelopes "<< dude[spellChoice].getName() << endl;
					
					if (dude[moveGuy].getParagon() == 7022) { //water mage of barriers
						shield[spellChoice] = dude[moveGuy].getDefense() * 2 / 3; //sets the shield to 2/3 of their defense
					}
					else {
						shield[spellChoice] = dude[moveGuy].getDefense() / 2; //sets the shield to half of their defense
					}
					shieldTimer[spellChoice] = 2; //last for 2 turns
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 15); //uses up 15 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	
	return;
}

//the slow spell lasts 1 round 10 mana
void mageSlow() {
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 10)
	{
		cout << "\nWho do you wish to slow down?\n0: no one\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A light shines from " << dude[moveGuy].getName() << " to " << dude[spellChoice].getName() << "'s legs slowing their move speed\n";
					
					haste[spellChoice] = haste[spellChoice] - 3; //makes the slow spell counter go up 3
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	return;
}

void mageBlink() {//15 mana
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5) {	
		
		int newXpos = dude[moveGuy].getXpos() + rd20() - 10;
		int newYpos = dude[moveGuy].getYpos() + rd20() - 10;
		
		if (mainMap.getGridPassable(newXpos,newYpos) && newXpos > 0 && newYpos > 0 && newXpos < 25 && newYpos < 50) {//if no one is there, and on the map
			
				mainMap.setGridPlayer(newXpos,newYpos,moveGuy); //draws the person number on the map
				mainMap.setGridPlayer(dude[moveGuy].getXpos(),dude[moveGuy].getYpos(),0);//deletes old class initial
											
				
				cout << epithet(moveGuy) << " blinks to (" << newXpos << "," << newYpos << ")\n\n";
				
				dude[moveGuy].setXpos(newXpos);
				dude[moveGuy].setYpos(newYpos); //saves the new location for the player
				dude[moveGuy].setMana(dude[moveGuy].getMana() - 15);//uses 15 mana
					
				return;
		}
		else { //if something is there, just redoes it
			mageBlink();
			
		}
		
		
	}
	else {
	cout << "\nYou do not have the required mana to cast this\n\n";
	}
	return;
}

//the haste spell lasts 2 rounds 5 mana
void mageHaste() {
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5)
	{
		cout << "\nWho do you wish to raise their move?\n0: no one\n";
		
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for alllies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A light shines from " << dude[moveGuy].getName() << " to " << dude[spellChoice].getName() << "'s legs increasing their move speed\n";
					
					haste[spellChoice] = haste[spellChoice] + 3; //makes the haste spell counter go up 3
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	return;
}

void mageIceTouch() {
	if (dude[moveGuy].getMana() >=10 || freeMana)
	{
	
		int spellChoice = 0, j = 0, damage = 0, attackRoll = 0, defenseRoll = 0, heightBonus = 0;
		
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				int heightAttacker = mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos());
				int heightDefender = mainMap.getGridElevation(dude[spellChoice].getXpos(),dude[spellChoice].getYpos());
				int heightDifferenceSquared = (heightDefender-heightAttacker)*(heightDefender-heightAttacker);
				if (heightAttacker > heightDefender) {//makes the height difference negative if you are higher
					heightDifferenceSquared = heightDifferenceSquared * -1/2;
				}
				// checks spell range
				if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					attackRoll = rd12();
					defenseRoll = rd10();
					
						//if a scout, halfling, or lucky rolls poorly, they get to use luck to re-roll
						
					int rerollDefense = 0;
					if (dude[spellChoice].getCharacterClass() == 6){rerollDefense++;}
					if (dude[spellChoice].getBirthRight() == 5){rerollDefense++;}
					if (dude[spellChoice].getRace() == 7){rerollDefense++;}
					if ((rerollDefense == 1 && (defenseRoll <= 2)) || (rerollDefense == 2 && (defenseRoll <= 3)) || (rerollDefense == 3 && (defenseRoll <= 4)) ) {
					
					dude[spellChoice].setXp(dude[spellChoice].getXp() + 5); //adds xp
					if (spellChoice < 7 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
					if (spellChoice > 7 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
					cout << endl << epithet(spellChoice) << " was able help himself after a fumble";
					defenseRoll = rd10();
					}
					
					int rerollAttack = 0;
					if (dude[moveGuy].getCharacterClass() == 6){rerollAttack++;}
					if (dude[spellChoice].getBirthRight() == 5){rerollAttack++;}
					if (dude[moveGuy].getRace() == 7){rerollAttack++;}
					if ((rerollAttack == 1 && attackRoll == 1) || (rerollAttack == 2 && (attackRoll <= 2)) || (rerollAttack == 3 && (attackRoll <= 3))) {
						
					dude[moveGuy].setXp(dude[moveGuy].getXp() + 5);	//adds xp
					if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
					if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
					cout << endl << epithet(moveGuy) << " was able to help himself after a fumble\n";
					attackRoll = rd12();
					}
					
					cout << endl << dude[moveGuy].getName() << " rolls a " << attackRoll << " and " << dude[spellChoice].getName() << " rolls a " << defenseRoll << endl;
					
					if (heightDifferenceSquared <= -8) { //if the attacker is 4 spaces higher, adds 10% attack (it got divided by 2
							cout << epithet(moveGuy) << " uses their elevation to their advantage\n";
							heightBonus = dude[moveGuy].getAttack() / 10;
						}
					else if (heightDifferenceSquared > 16) { //if the defender is 4 spaces higher, adds 10% defense
							cout << epithet(spellChoice) << " uses their elevation to their advantage\n";
							heightBonus = dude[spellChoice].getDefense() / 10;
					}
					
					damage = attackRoll +(dude[moveGuy].getAttack() * 3 / 2) + heightBonus - dude[spellChoice].getDefense() - defenseRoll;
					
					if (charge[spellChoice] > 0) { //less damage against charging knights
						if (dude[spellChoice].getRenown() == 502) {
							damage = damage / 2; cout << endl << epithet(spellChoice) << "'s charge makes them nigh on untouchable\n";
						}
						else {
						damage = damage * 2 / 3; cout << endl << epithet(spellChoice) << "'s charge minimizes the damage\n";}} 
			
			
					if (shield[spellChoice] > 0) {
						damage = damage - shield[spellChoice]; //does the mage shield
						if (damage > 0) {
							cout << endl <<  dude[spellChoice].getName() << "'s shield minimizes the damage\n";
						}
						if (damage <= 0) {
							cout << endl << dude[spellChoice].getName() << "'s shield blocks the damage\n";
						}	
					}
					
					if (defended[spellChoice] > 0) { //checks if they are under the defender ability
						cout << endl << dude[spellChoice].getName() << " is being defended by their team-mate\n";
						damage = damage - defended[spellChoice];
					}
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					dude[spellChoice].setHealth(dude[moveGuy].getHealth() - damage); //inflicts damage
					
					haste[spellChoice]--;
					haste[spellChoice]--;
					
					if (damage > 0) {
						
						
						if (dude[spellChoice].getHealth() > 0){
							if (attackRoll >=11) { //on a really good roll adds more slow
								cout << dude[moveGuy].getName() << " punches " << dude[spellChoice].getName() << " in the face with an icy fist doing " << damage << " damage\n";
								haste[spellChoice]--;
							}
							else {
								cout << dude[moveGuy].getName() << " touches " << dude[spellChoice].getName() << " with an icy hand doing " << damage << " damage\n";
							}
							cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
							dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
							if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, damage * 2);}//if team 1, gets money
							if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, damage * 2);}//if team 2, gets money
						}
						else {
							cout << dude[moveGuy].getName() << " punches " << dude[spellChoice].getName() << " in the face with an icy fist doing " << damage << " damage\n";
							cout << dude[spellChoice].getName() << " dies from the damage and their frozen body shatters\n";
							dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
							if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
							if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
						}
					}
					else {
						cout << "The ice touch failed to do any damage\n";
					}
					
					if (!(freeMana)) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
					}
					
				}
				else {
					cout << "\nThey are not in range\n";
				}
		}
	}
	else {cout << "\nYou do not have enough mana\n\n";}
	
	return;
}

//fireball 2d4 with 1d4 splash + 50% to add attack
void mageFireBall() {
	
	int spellChoice = 0, j = 0, i = 0, damage = 0, splashDamage = 0;
	
	
	if (dude[moveGuy].getMana() >= 15 || freeMana)
	{
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (49 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
				
					damage = rd4() + rd4() + (rd2() * dude[moveGuy].getAttack()); 
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					
					dude[spellChoice].setHealth(dude[spellChoice].getHealth() - damage); //inflicts damage
					cout << "A large fireball flies from " << dude[moveGuy].getName() << " and strikes " << dude[spellChoice].getName();
					cout << " doing " << damage << " damage\n\n";
					
					
					if (dude[moveGuy].getTeam() == 1) {//if in team 1, does damage here
						for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on the team and checks if they are less than 2 from the target
							splashDamage = 0;
							if (i != spellChoice && 4 >= (dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos()))
							{ //that^^ checks if they are in the splash zone, but aren't themself
								splashDamage = rd4() + (rd2() * dude[moveGuy].getAttack());//d4 + attack
								

								//magic resist and fighter magic weakness
								if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022 || (dude[i].getCharacterClass() == 1 && dude[i].getParagon() != 1021)) {
										if (dude[i].getBirthRight() == 4) {//spellscarred
											cout << dude[i].getName() << "'s spellscarred skin glows and they recieve less damage\n";
											splashDamage = splashDamage * 3 / 4;
										}
										if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
											cout << dude[i].getName() << "'s shielded skin glows and they recieve less damage\n";
											splashDamage = splashDamage * 3 / 4;
										}
										if (dude[i].getCharacterClass() == 1) {//fighter weakness
											splashDamage = splashDamage * 5 / 4;
										}
										
								}
								cout << dude[i].getName() << " takes " << splashDamage << " damage from the blast \n";
								
								dude[i].setHealth(dude[i].getHealth() - splashDamage);//inflicts damage
							} 

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, does damage here
							for (i=1; i <= teamSize1; i++) { //goes through all the people on the team and checks if they are less than 2 from the target
								splashDamage = 0;
								if (i != spellChoice && dude[i].getHealth() > 0 && 4 >= (dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos()))
								{
									splashDamage = rd4() + (rd2() * dude[moveGuy].getAttack());//d4 + attack
									
									//magic resist and fighter magic weakness
									if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022 || (dude[i].getCharacterClass() == 1 && dude[i].getParagon() != 1021)) {
											if (dude[i].getBirthRight() == 4) {//spellscarred
												cout << dude[i].getName() << "'s spellscarred skin glows and they recieve less damage\n";
												splashDamage = splashDamage * 3 / 4;
											}
											if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
												cout << dude[i].getName() << "'s shielded skin glows and they recieve less damage\n";
												splashDamage = splashDamage * 3 / 4;
											}
											if (dude[i].getCharacterClass() == 1) {//fighter weakness
												splashDamage = splashDamage * 5 / 4;
											}
											
									}

									
									cout << dude[i].getName() << " takes " << splashDamage << " damage from the blast \n";
									
									dude[i].setHealth(dude[i].getHealth() - splashDamage);//inflicts damage
									if (dude[i].getHealth() <= 0) {
										cout << dude[i].getName() << " dies from the blast damage\n";
										
									}
								} 
		
							}
					}
					
					
					
					if (dude[spellChoice].getHealth() > 0){
						cout << endl << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					}
					else {
						cout << endl << dude[spellChoice].getName() << " dies from the damage and their body burns to ash\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					if (!(freeMana)) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 15); //uses up 15 mana
					}
					
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

void magePoison() { //range 12 mana 15 damage attack - 1d6    poisons for 1d4
	int spellChoice = 0, j = 0, i = 0, damage = 0, extraPoison = 0;
	
	
	if (dude[moveGuy].getMana() >= 15)
	{
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (144 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					damage = dude[moveGuy].getAttack() - rd6(); //attack minus d6
					extraPoison = rd4();
					poison[spellChoice] = poison[spellChoice] + extraPoison;
					
					if (damage > 0) {
						cout << "A green sphere flies from " << dude[moveGuy].getName() << "'s palm and does " << damage << " to " << dude[spellChoice].getName() << endl;
						cout << dude[spellChoice].getName() << " is now at poison level " << poison[spellChoice] << endl;
						
						//magic resist and fighter magic weakness
						if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
						}
						
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() - damage);
						
						if (dude[spellChoice].getHealth() > 0){
							cout << endl << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
							dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
							if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
							if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
						}
						else {
							cout << endl << dude[spellChoice].getName() << " dies from the damage and their poisoned lifeless body falls to the ground\n";
							dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
							if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
							if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
						}
					}
					else {
						cout << "The poisonous sphere flies past " << dude[spellChoice].getName() << " doing no harm\n";
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 15); //uses up 15 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
	
}

//range 7 damage: d4  mana:5  steals life
void mageLeech() {
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5)
	{
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (49 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					damage =  rd4() ;//calculates the damage
					
					if (lichForm[moveGuy] == 1) {
						damage = damage + 1;
						cout << endl << dude[moveGuy].getName() << "'s body glows with ethereal power";
					}
					
					cout << "\nA glowing tendril extends from " << dude[moveGuy].getName() << "'s hand\n";
					cout << endl << dude[spellChoice].getName()  << " has " << damage << " life sucked away\n";
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					dude[spellChoice].setHealth(dude[spellChoice].getHealth() - damage); //inflicts damage
					dude[moveGuy].setHealth(dude[moveGuy].getHealth() + damage * 3 / 4); //adds life
					if (dude[moveGuy].getHealth() > dude[moveGuy].getMaxHealth()) {
						dude[moveGuy].setHealth(dude[moveGuy].getMaxHealth());//keeps it from exceeding max health
					}
					
					
					if (dude[spellChoice].getHealth() > 0){
						cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 2); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 2) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 2) * 2);}//if team 2, gets money
					}
					else {
						cout << dude[spellChoice].getName() << "'s shriveled corpse falls to the ground\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

//mage minor missile spell 3d2 range 10
void mageMinorMissile() {
	
	if (dude[moveGuy].getMana() >= 3)
	{
	
		int spellChoice = 0, j = 0, damage = 0;
		
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (100 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					cout << "\nThree glowing balls fly from " << dude[moveGuy].getName() << "'s hand\n";
					damage = rd2() + rd2() + rd2();//calculates the damage
					
		
					cout << endl << dude[spellChoice].getName()  << " is struck by " << damage << " of the glowing balls\n";
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					dude[spellChoice].setHealth(dude[moveGuy].getHealth() - damage); //inflicts damage
					
					if (dude[spellChoice].getHealth() > 0){
						cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					}
					else {
						cout << dude[spellChoice].getName() << " dies from the damage\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 3); //uses up 3 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
		}
	}
	else {cout << "\nYou do not have enough mana\n\n";}
	return;
}

//mage missile spell 5d2 range 7
void mageMissile() {
	
	int spellChoice = 0, j = 0, damage = 0;
	int presentManaPool = dude[moveGuy].getMana(), i = 0;
	int unleashTarget = 0;
	bool unleashed = 0;
	
	if (dude[moveGuy].getMana() >= 5 && dude[moveGuy].getParagon() == 7031 && rd20() <= 1) {//arcane summoner of unbridled power
		unleashed = 1;
		cout << dude[moveGuy].getName() << "'s body glows as they unleash all their magic in every direction\n";
		for (i=1; i < presentManaPool; i++) {
			//attacks enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				unleashTarget = rand() % teamSize1 + 1;
				if (dude[unleashTarget].getHealth() > 0) {
				
					damage = rd4() - 1;
					if (damage == 0) {
						cout << "a few spheres fly just past " << dude[unleashTarget].getName() << endl;
					}
					else {
						cout << dude[unleashTarget].getName() << " is struck by " << damage << " spheres\n";
						dude[unleashTarget].setHealth(dude[unleashTarget].getHealth() - damage );
						if (dude[unleashTarget].getHealth() <= 0) {
							cout << "and they slowly fall to the ground from the damage\n";
						}
					}
					
				}
				else {//if the target was dead, redoes it
					i--;
				}
			}
			//attacks enemies if in team 1
			if (dude[moveGuy].getTeam() == 1){
				unleashTarget = (rand() % teamSize2) + teamSize1 + 1;
				
				if (dude[unleashTarget].getHealth() > 0) {
				
					damage = rd4() - 1;
					if (damage == 0) {
						cout << "a few spheres fly just past " << dude[unleashTarget].getName() << endl;
					}
					else {
						cout << dude[unleashTarget].getName() << " is struck by " << damage << " spheres\n";
						dude[unleashTarget].setHealth(dude[unleashTarget].getHealth() - damage);
						if (dude[unleashTarget].getHealth() == 0) {
							cout << "and they slowly fall to the ground from the damage\n";
						}
					}
					
				}
				else {//if the target was dead, redoes it
					i--;
				}
			}	
		}
		dude[moveGuy].setMana(0);//uses all mana
	}
	if (dude[moveGuy].getMana() >= 5 && unleashed == 0)
	{
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (49 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					if (dude[moveGuy].getRenown() != 701) {//regular
						cout << "\nFive glowing balls fly from " << dude[moveGuy].getName() << "'s hand\n";
						damage = rd2() + rd2() + rd2() + rd2() + rd2();//calculates the damage
						if (damage == 5) {
							cout << "\nAll 5 of the balls strike the enemy and do a major 10 damage\n";
							damage = 10;
							
						}
						else {
						cout << endl << dude[spellChoice].getName()  << " is struck by " << damage << " of the glowing balls\n";
						}
					} 
					else {//if they are rapid-fire
						cout << "\nSix glowing balls rapidly fly from " << dude[moveGuy].getName() << "'s hand\n";
						damage = rd2() + rd2() + rd2() + rd2() + rd2() + rd2();//calculates the damage
						if (damage == 6) {
							cout << "\nAll 6 of the balls strike the enemy and do a major 12 damage\n";
							damage = 12;
							
						}
						else {
						cout << endl << dude[spellChoice].getName()  << " is struck by " << damage << " of the glowing balls\n";
						}
						
					}
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					dude[spellChoice].setHealth(dude[spellChoice].getHealth() - damage); //inflicts damage
					
					if (dude[spellChoice].getHealth() > 0){
						cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					}
					else {
						cout << dude[spellChoice].getName() << " dies from the damage\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else if (dude[moveGuy].getMana() < 5) {
		cout << "\nYou do not have the required mana to cast this\n\n";
	}
	return;
}



//range 1  mana 5  raise burn by 1 to 3
void mageIgnite() {
	int burnAmount = 0;
	
	if (dude[moveGuy].getMana() >= 5 || freeMana)
	{
	
		int spellChoice = 0, j = 0, damage = 0;
		
		cout << "\nWho do you wish to ignite?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				cout << "Enemies:\n";
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
					
				cout << "\nAllies:\n";
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				cout << "Enemies:\n";
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				cout << "\nAllies:\n";
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					burnAmount = rd2() + rd2() + rd2();//calculates the amount
					
					if (usingForceOfNature) {//druids of nature do extra
						burnAmount = burnAmount * 2;
					}
					
					if (burn[spellChoice] == 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and they ignite in flames\n";
						burn[spellChoice] = burn[spellChoice] + burnAmount;
					}
					if (burn[spellChoice] > 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and the flames around them grow even higher\n";
						burn[spellChoice] = burn[spellChoice] + burnAmount;
					}
					if (burn[spellChoice] < 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and flames sprout up to thaw them out\n";
						burn[spellChoice] = 0;
					}
					
					
					if (!(freeMana)) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
					}
					
				}
				else {
					cout << "\nThey are not in range\n";
				}
		}
	}
	else {cout << "\nYou do not have enough mana\n\n";}
	return;
}

//range 1  mana 5  raise freeze by 1 to 3
void mageFreeze() {
	//water mage of frost
	int freezeAmount = 0;
	
	if (dude[moveGuy].getMana() >= 5 || freeMana)
	{
	
		int spellChoice = 0, j = 0, damage = 0;
		
		cout << "\nWho do you wish to freeze?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				cout << "Enemies:\n";
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
					
				cout << "\nAllies:\n";
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				cout << "Enemies:\n";
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				cout << "\nAllies:\n";
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					freezeAmount = rd2() + rd2() + rd2();//calculates the amount
					
					if (usingForceOfNature) {//druids of nature do extra
						freezeAmount = freezeAmount * 2;
					}
					
					if (burn[spellChoice] == 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and they start getting covered in frost\n";
						burn[spellChoice] = burn[spellChoice] - freezeAmount;
					}
					if (burn[spellChoice] < 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and the frost around them thickens\n";
						burn[spellChoice] = burn[spellChoice] - freezeAmount;
					}
					if (burn[spellChoice] > 0) {
						cout << dude[moveGuy].getName() << " shouts loudly and points at " << dude[spellChoice].getName() << " and frost settles on them to cool the flames\n";
						burn[spellChoice] = 0;
					}
					
					
					if (!(freeMana)) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
					}
				}
				else {
					cout << "\nThey are not in range\n";
				}
		}
	}
	else {cout << "\nYou do not have enough mana\n\n";}
	return;
}

//range 1 mana 10 raise enchant by 1
void enchantWeaponOther() {
	//arcane summoner of imbuing
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 10)
	{
		cout << "Do you wish to enchant a weapon?\n  1:yes\n  0:no\n";
		cin >> spellChoice;
		if (spellChoice == 1) {
			cout << endl << "Whose weapon do you wish to enchant?\n";
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for alllies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			cout << endl;
			cin >> spellChoice;
			cout << endl;
			if (spellChoice > 0) {
				 // checks spell range
				if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << dude[spellChoice].getName() << "'s weapon glows brightly as power is stored in it \n";
					
					enchantWeapon[spellChoice] = enchantWeapon[spellChoice] + 1; //makes the charge count go up 1
					cout << "Enchantments stored: " << enchantWeapon[spellChoice] << endl;
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
				
		}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
}

//repulse pushes back all enemies that are within 2
void mageRepulse() {
	//fire mage of repulsion
	
	int spellChoice = 0, j = 0, i = 0, damage = 0, splashDamage = 0;
	bool resisted = 0;
	
	
	if (dude[moveGuy].getMana() >= 15)
	{
				
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A bubble extends outward from " << dude[moveGuy].getName() << " to repulse their enemies\n";
					
					if (dude[moveGuy].getTeam() == 1) {//if in team 1, does pushing here
						for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on the enemy team and checks if they are less than 2 away
							if (4 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
							{ 
								
								
								if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022) {//magic resist
										if (dude[i].getBirthRight() == 4) {//spellscarred
											cout << dude[i].getName() << "'s spellscarred skin glows and they are not pushed back\n";
											resisted = 1;
										}
										if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
											cout << dude[i].getName() << "'s shielded skin glows and they are not pushed back\n";
											resisted = 1;
										}
								}
								
								if (!resisted) {
									
										int xshove = 0, yshove = 0;
										int newXpos = 0, newYpos = 0;
										
										//these 2 lines show which direction to shove 
										xshove = dude[i].getXpos() -  dude[moveGuy].getXpos();
										yshove = dude[i].getYpos() -  dude[moveGuy].getYpos();
										
										
										newXpos=dude[i].getXpos()+xshove;
										newYpos=dude[i].getYpos()+yshove;
										
										
										
										if (newXpos < 0 || newYpos < 0 || newXpos > 25 || newYpos > 50) { //checks that the target spot is on the map
											
											cout << "\nYou can not repulse them off the map\n";
										}
										if (mainMap.getGridPassable(newXpos,newYpos) ) {//if nothing is there
											
											mainMap.setGridPlayer(newXpos,newYpos,i); //draws the person number on the map
											mainMap.setGridPlayer(dude[i].getXpos(),dude[i].getYpos(),0);//deletes old class initial
											
											
											dude[i].setXpos(newXpos);//sets the player to the new spot
											dude[i].setYpos(newYpos);
											
										}
										else {
											cout << "\nYou can not repulse them into someone\n";
										}
											
									
								}
								else {
									resisted = 0;
								}
							} 

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, does pushing here
						for (i=1; i <= teamSize1; i++) { //goes through all the people on the enemy team and checks if they are less than 2 away
							if (4 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
							{ 
								
								
								if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022) {//magic resist
										if (dude[i].getBirthRight() == 4) {//spellscarred
											cout << dude[i].getName() << "'s spellscarred skin glows and they are not pushed back\n";
											resisted = 1;
										}
										if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
											cout << dude[i].getName() << "'s shielded skin glows and they are not pushed back\n";
											resisted = 1;
										}
								}
								
								if (!resisted) {
									
										int xshove = 0, yshove = 0;
										int newXpos = 0, newYpos = 0;
										
										//these 2 lines show which direction to shove 
										xshove = dude[i].getXpos() -  dude[moveGuy].getXpos();
										yshove = dude[i].getYpos() -  dude[moveGuy].getYpos();
										
										
										newXpos=dude[i].getXpos()+xshove;
										newYpos=dude[i].getYpos()+yshove;
										
										
										
										if (newXpos < 0 || newYpos < 0 || newXpos > 25 || newYpos > 50) { //checks that the target spot is on the map
											
											cout << "\nYou can not repulse them off the map\n";
										}
										if (mainMap.getGridPassable(newXpos,newYpos) ) {//if nothing is there
											
											mainMap.setGridPlayer(newXpos,newYpos,i); //draws the person number on the map
											mainMap.setGridPlayer(dude[i].getXpos(),dude[i].getYpos(),0);//deletes old class initial
											
											
											
											dude[i].setXpos(newXpos);//sets the player to the new spot
											dude[i].setYpos(newYpos);
											
										}
										else {
											cout << "\nYou can not repulse them into someone\n";
										}
											
									
								}
								else {
									resisted = 0;
								}
							} 

						}
				}
				
					
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					
					
					if (!(freeMana)) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 15); //uses up 15 mana
					}
					
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

//random spell between freeze, ignite, fireball, and ice touch. mana 7
void forceOfNature() {
	//druid of nature
	int randomSpell = rd4();
	
	if (dude[moveGuy].getMana() >= 7)
	{
		freeMana = 1;
		usingForceOfNature = 1;
		
		switch (randomSpell) {
		case 1:
			cout << "The force of ice comes over " << dude[moveGuy].getName() << endl;
			mageFreeze();
		break;
		case 2:
			cout << "The force of fire comes over " << dude[moveGuy].getName() << endl;
			mageIgnite();
		break;
		case 3:
			cout << dude[moveGuy].getName() <<"'s weapon becomes coated in frosty death\n";
			mageIceTouch();
		break;
		case 4:
			cout << "A fiery sphere coalesces in " << dude[moveGuy].getName() << "'s hand\n";
			mageFireBall();
		break;
		
		freeMana = 0;
		usingForceOfNature = 0;
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 7);//uses 7 mana
	}
	}
}

//list of spells for the mage
void mageSpells() {
	if (dude[moveGuy].getCharacterClass() == 7)
	{
			while (dude[moveGuy].getPrestige() == 0) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
		}

	}
	return;
}


void mageSpellsArcaneSummoner() {
	while (dude[moveGuy].getPrestige() == 703)
	{
			
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			cout << "3:Haste\n  mana: 5\n  range: 3\n  duration: 3\n4:Slow\n  mana: 10\n  range: 3\n  duration: 2\n";
			cout << "5:Fireball\n  mana: 15\n  range: 7\n";
			cout << "6:Leech\n  mana: 5\n  range:7\n";
			cout << "7:Mana stream\n  range:7\n";
			if (dude[moveGuy].getParagon() == 7032) {
				cout << "8:Enchant weapon\n  range:1\n  mana:10\n";
			}
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				mageHaste();
			}
			if (spellChoice == 4) {
				mageSlow();
			}
			if (spellChoice == 5) {
				mageFireBall();
			}
			if (spellChoice == 6) {
				mageLeech();
			}
			if (spellChoice == 7) {
				arcaneSummonerManaStream();
			}
			if (spellChoice == 8) {
				enchantWeaponOther();
			}
			
		

	}
	
	
	return;
}


void mageSpellsWater() {
	while (dude[moveGuy].getPrestige() == 702)
	{
			
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			cout << "3:Haste\n  mana: 5\n  range: 3\n  duration: 3\n4:Slow\n  mana: 10\n  range: 3\n  duration: 2\n";
			cout << "5:Shield\n  mana: 15\n  range: 3\n  duration: 2\n6:Protect from arrows\n  mana: 15\n  range: 3\n  duration: 2\n";
			cout << "7:Blink\n  mana: 15\n";
			if (dude[moveGuy].getParagon() == 7021) {
				cout << "8:Freeze\n  mana: 5\n  range: 1\n";
			}
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				mageHaste();
			}
			if (spellChoice == 4) {
				mageSlow();
			}
			if (spellChoice == 5) {
				mageShield();
			}
			if (spellChoice == 6) {
				mageProtectRanged();
			}
			if (spellChoice == 7) {
				mageBlink();
			}
			if (spellChoice == 8) {
				mageFreeze();
			}
			
	}
	
	return;
}

void mageSpellsFire() {
	while (dude[moveGuy].getPrestige() == 701)
	{
			
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n3:Fireball\n  mana: 15\n  range: 7\n";
			cout << "4:Poison sphere\n  mana: 15\n  range: 12\n5:Ice touch\n  mana: 10\n  range:1\n";
			cout << "6:Leech\n  mana: 5\n  range:7\n";
			if (dude[moveGuy].getParagon() == 7011) {
				cout << "7:Ignite\n  mana: 5\n  range:1\n";
			}
			if (dude[moveGuy].getParagon() == 7012) {
				cout << "7:Repulse\n  mana: 10\n  range:3\n";
			}
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				mageFireBall();
			}
			if (spellChoice == 4) {
				magePoison();
			}
			if (spellChoice == 5) {
				mageIceTouch();
			}
			if (spellChoice == 6) {
				mageLeech();
			}
			if (spellChoice == 7 && dude[moveGuy].getParagon() == 7011) {//fire mage of infernos
				mageIgnite();
			}
			if (spellChoice == 7 && dude[moveGuy].getParagon() == 7012) {//fire mage of repulsion
				mageRepulse();
			}
		

	}
	return;
}

//opposite of poison, moves counter by d4,   mana: 5   range: 3
void druidHealingBalm() {
	int spellChoice = 0;
	int j = 0;
	
	if (dude[moveGuy].getMana() < 5 || !(freeMana)) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
	cout << "\nWho do you want to put the healing balm on?\n0:back to spell list\n";
	
			//displays team mates if in team 2
		if (dude[moveGuy].getTeam() == 1){
			for (j=1; j <= teamSize1; j++) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
		//displays team mates if in team 1	
		if (dude[moveGuy].getTeam() == 2){
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
	
	cin >> spellChoice;
	if (spellChoice > 0) {
			
			// checks spell range
			if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
			{ 
				poison[spellChoice] = poison[spellChoice] - rd4();
				cout << dude[spellChoice].getName() << " is now at healing balm level " << -poison[spellChoice] << endl;
				
				if (!(freeMana)) {//uses mana if not free
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses 5 mana
				}
			}
			else {
				cout << "\nThey are out of range\n";
			}
		
	}
	}
		
	return;
	
	
}

void druidBearForm() {//attack*3/2   defense*3/2

	if (dude[moveGuy].getMana() >= 10)
	{
		druidForm[moveGuy] = 1;
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
		cout << dude[moveGuy].getName() << " grows in size and hair sprouts everywhere as they morph into a bear\n";
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

void druidWolfForm() {//move*2    attack*5/4    defense*4/3

	if (dude[moveGuy].getMana() >= 10)
	{
		druidForm[moveGuy] = 2;
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
		cout << dude[moveGuy].getName() << " gets on their hands and knees as their face extends into a snout and they turn into a wolf\n";
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

void druidHawkForm() {//move*3	  defense*5/4

	if (dude[moveGuy].getMana() >= 10)
	{
		druidForm[moveGuy] = 3;
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
		cout << dude[moveGuy].getName() << "'s arms extend and grow feathers as they morph into a hawk\n";
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

void druidSnakeForm() {//move*2   attack*4/3   poison

	if (dude[moveGuy].getMana() >= 10)
	{
		druidForm[moveGuy] = 4;
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
		cout << dude[moveGuy].getName() << "'s body extends and grows scales as they turn into a snake\n";
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

void druidNormalForm() {//back to normal

	if (dude[moveGuy].getMana() >= 10 || dude[moveGuy].getParagon() == 8011)
	{
		druidForm[moveGuy] = 0;
		if (dude[moveGuy].getParagon() != 8011) {//druid of morphing doesn't use mana
			dude[moveGuy].setMana(dude[moveGuy].getMana() - 10); //uses up 10 mana
		}
		cout << dude[moveGuy].getName() << "'s body morphs back into their 	 self\n";
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
}

//mana 5
void spellswordEnchantWeapon() {
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5)
	{
		cout << "Do you wish to enchant your weapon?\n  1:yes\n  0:no\n";
		cin >> spellChoice;
		if (spellChoice == 1) {
				
				 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << dude[moveGuy].getName() << "'s weapon glows brightly as power is stored in it \n";
					
					enchantWeapon[moveGuy] = enchantWeapon[moveGuy] + 1; //makes the charge count go up 1
					cout << "Enchantments stored: " << enchantWeapon[moveGuy] << endl;
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				
				
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
}

void necromancerBloodToMana() {
		
	int spellChoice = 0, j = 0, manaGain = 0;
	
	
	if (dude[moveGuy].getMana() >= 0)
	{
		cout << "You are currently at " << dude[moveGuy].getHealth() << " health, and you have " << dude[moveGuy].getMana() << " mana.\n";
		cout << "How much health do you want to turn to mana?\n";
		cin >> spellChoice;
		
		if (spellChoice >= dude[moveGuy].getHealth()) { //makes sure they don't kill themselves
			cout << "\nYou do not have enough health to do that.\n";
			necromancerBloodToMana();
		}
		cout << endl;
		if (spellChoice > 0) {
				
					manaGain = spellChoice;
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					
					dude[moveGuy].setHealth(dude[moveGuy].getHealth() - spellChoice);//inflicts damage
					dude[moveGuy].setMana(dude[moveGuy].getMana() + manaGain); //gives the mana
					
					cout << dude[moveGuy].getName() << " now has " << dude[moveGuy].getHealth() << " health and " << dude[moveGuy].getMana() << " mana\n";
						
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
	
	
	
}

void necromancerDeathChannel() {//range 12 mana 7 damage d4+deadCount*d4
		
	int spellChoice = 0, j = 0, damage = 0, deadCount = 0;
	
	
	if (dude[moveGuy].getMana() >= 7)
	{
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (144 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					
						//these add up the dead people
						for (j=1; j <= teamSize1; j++) {
							if (dude[j].getHealth() < 1) { //checks for dead people
								if (deadCount == 0) {
									cout << "A glowing black beam comes from " << dude[j].getName();
									deadCount++;
								}	
								else {
									cout << ", " << dude[j].getName();
									deadCount++;
								}
							}
						}
						for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
							if (dude[j].getHealth() < 1) { //checks for dead people
								if (deadCount == 0) {
									cout << "A glowing black beam comes from " << dude[j].getName();
									deadCount++;
								}	
								else {
									cout << ", " << dude[j].getName();
									deadCount++;
								}
							}
						}
					
					if (deadCount > 0) {
						cout << " and goes to " << dude[moveGuy].getName() << " empowering their attack\n";
					}
					
					for (j = 0; j < 1 + deadCount; j++) {//calculates damage based on the dead
						damage = damage + rd4();
					}
					if (lichForm[moveGuy] == 1) {
						damage= damage + rd4();
						cout << dude[moveGuy].getName() << "'s body glows with ethereal power\n";
					}
					
					cout << dude[moveGuy].getName() << " fires a sphere of darkness at " << dude[spellChoice].getName() << " doing " << damage << " damage\n\n";
					
					//magic resist and fighter magic weakness
					if (dude[spellChoice].getBirthRight() == 4 || dude[spellChoice].getParagon() == 5022 || (dude[spellChoice].getCharacterClass() == 1 && dude[spellChoice].getParagon() != 1021)) {
							if (dude[spellChoice].getBirthRight() == 4) {//spellscarred
								cout << dude[spellChoice].getName() << "'s spellscarred skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getParagon() == 5022) {//mounted paladin of shielding
								cout << dude[spellChoice].getName() << "'s shielded skin glows and they recieve less damage\n";
								damage = damage * 3 / 4;
							}
							if (dude[spellChoice].getCharacterClass() == 1) {//fighter weakness
								damage = damage * 5 / 4;
							}
							
					}
					
					dude[spellChoice].setHealth(dude[moveGuy].getHealth() - damage); //inflicts damage
					
					if (dude[spellChoice].getHealth() > 0){
						cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					}
					else {
						cout << dude[spellChoice].getName() << " dies from the damage\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 7); //uses up 7 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	return;
	
}

void earthQuake() {//range 7 mana 0 cooldown 5
	int hillCenterX = 0;
	int hillCenterY = 0;
	int pitDepth = 0;
	int radius = rand()%5+1;
	int spellChoice = 0, j = 0, damage = 0;
	int splashDamage = 0;
	float exactDistanceFromEpicenter = 1;
	int distanceFromEpicenter = 1;
	int i = 0, x = 0, y = 0;
	
	
	if (earthQuakeCoolDown[moveGuy] == 0) {
		cout << "\nWho do you wish to attack with the earthquake?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (49 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					damage =  rd4() * dude[moveGuy].getLevel() ;//calculates the damage
					
					
					cout << "The ground around " << epithet(spellChoice) << " violently shakes and cracks.\n";
					cout << endl << dude[spellChoice].getName()  << " recieves " << damage <<  " damage" << endl;
					
					
					dude[spellChoice].setHealth(dude[moveGuy].getHealth() - damage); //inflicts damage
					
					if (dude[moveGuy].getTeam() == 1) {//if in team 1, does damage here
						for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on the team and checks if they are less than 2 from the target
							splashDamage = 0;
							
								
							
							if (i != spellChoice && 4 >= (dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos())) {
								 //that^^ checks if they are in the splash zone, but aren't themself
								
								
								exactDistanceFromEpicenter = sqrt((dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos()));
								distanceFromEpicenter = int(exactDistanceFromEpicenter);
								
								splashDamage = damage / distanceFromEpicenter;//less damage if father away
								
								//magic resist and fighter magic weakness
								if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022 || (dude[i].getCharacterClass() == 1 && dude[i].getParagon() != 1021)) {
										if (dude[i].getBirthRight() == 4) {//spellscarred
											cout << dude[i].getName() << "'s spellscarred skin glows and they recieve less damage\n";
											splashDamage = splashDamage * 3 / 4;
										}
										if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
											cout << dude[i].getName() << "'s shielded skin glows and they recieve less damage\n";
											splashDamage = splashDamage * 3 / 4;
										}
										if (dude[i].getCharacterClass() == 1) {//fighter weakness
											splashDamage = splashDamage * 5 / 4;
										}
										
								}
								
								
								cout << dude[i].getName() << " takes " << splashDamage << " damage from the earthquake \n";
								
								dude[i].setHealth(dude[i].getHealth() - splashDamage);//inflicts damage
								
							} 

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, does damage here
							for (i=1; i <= teamSize1; i++) { //goes through all the people on the team and checks if they are less than 2 from the target
								splashDamage = 0;
								
								exactDistanceFromEpicenter = sqrt((dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos()));
								distanceFromEpicenter = int(exactDistanceFromEpicenter);
								
								if (i != spellChoice && dude[i].getHealth() > 0 && 4 >= (dude[i].getXpos()-dude[spellChoice].getXpos())*(dude[i].getXpos()-dude[spellChoice].getXpos()) + (dude[i].getYpos()-dude[spellChoice].getYpos())*(dude[i].getYpos()-dude[spellChoice].getYpos())) {
									
									splashDamage = damage / distanceFromEpicenter;//less damage if father away
									
									//magic resist and fighter magic weakness
									if (dude[i].getBirthRight() == 4 || dude[i].getParagon() == 5022 || (dude[i].getCharacterClass() == 1 && dude[i].getParagon() != 1021)) {
											if (dude[i].getBirthRight() == 4) {//spellscarred
												cout << dude[i].getName() << "'s spellscarred skin glows and they recieve less damage\n";
												splashDamage = splashDamage * 3 / 4;
											}
											if (dude[i].getParagon() == 5022) {//mounted paladin of shielding
												cout << dude[i].getName() << "'s shielded skin glows and they recieve less damage\n";
												splashDamage = splashDamage * 3 / 4;
											}
											if (dude[i].getCharacterClass() == 1) {//fighter weakness
												splashDamage = splashDamage * 5 / 4;
											}
											
									}
									
									cout << dude[i].getName() << " takes " << splashDamage << " damage from the earthquake \n";
									
									
									dude[i].setHealth(dude[i].getHealth() - splashDamage);//inflicts damage
									if (dude[i].getHealth() <= 0) {
										cout << dude[i].getName() << " dies from the blast damage\n";
										
									}
								} 
		
							}
					}
					
					
					if (dude[spellChoice].getHealth() > 0){
						cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 2); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 2) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 2) * 2);}//if team 2, gets money
					}
					else {
						cout << dude[spellChoice].getName() << "'s pummeled body falls lifelessly in the newly opened pit.\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					
					earthQuakeCoolDown[moveGuy] = 5;//sets the cooldown
					
					
					
					hillCenterX = dude[spellChoice].getXpos();
					hillCenterY = dude[spellChoice].getYpos();
					
					radius = radius * 2;//makes the pit bigger than the area that got injured
					
					for ( x = 0; x < 25; x++) {
						for ( y = 0; y <= 50; y++) {
							pitDepth = (radius*radius-((x-hillCenterX)*(x-hillCenterX)+(y-hillCenterY)*(y-hillCenterY)))/12;
							
							if (pitDepth > 0) {//if the pit is greater than zero
								
								mainMap.setGridElevation(x,y, mainMap.getGridElevation(x,y) - pitDepth);//then it gets added to the map
							}
						}
					}
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
		}
	else {
		cout << "You need to wait " << earthQuakeCoolDown << " more turns until you can use that again\n";
	}
	
	return;
	}


void warlockSpells() {
	if (dude[moveGuy].getCharacterClass() == 8)
	{
			while (dude[moveGuy].getPrestige() == 0) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			
			if (dude[moveGuy].getRenown() == 801) {
				cout << "3:Earthquake\n  mana: 10\n  range: 7\n";
			}
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3 && dude[moveGuy].getRenown() == 801) {
				earthQuake();
			}
		}

	}
	
}

void druidSpells() {
	if (dude[moveGuy].getCharacterClass() == 8)
	{
			//if in a form, doesn't get many spells
			while (dude[moveGuy].getPrestige() == 801 && druidForm[moveGuy] != 0) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Normal form\n  mana: 10\n";
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				druidNormalForm();
				}
			
		}
		
		
			while (dude[moveGuy].getPrestige() == 801 && druidForm[moveGuy] == 0) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			cout << "3:Bear form\n  mana: 10\n4:Wolf form\n  mana: 10\n5:Hawk form\n  mana: 10\n6:Snake form\n  mana: 10\n";
			cout << "7:Healing balm\n  mana:5\n  range:3\n";
			
			if (dude[moveGuy].getRenown() == 801) {
				cout << "8:Earthquake\n  mana: 10\n  range: 7\n";
			}
			
			if (dude[moveGuy].getParagon() == 8012 && dude[moveGuy].getRenown() == 801) {
				cout << "9:Force of nature\n  mana:5\n  range:1\n";
			}
			else if (dude[moveGuy].getParagon() == 8012) {
				cout << "8:Force of nature\n  mana:7\n  range:?\n";
			}
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				druidBearForm();
			}
			if (spellChoice == 4) {
				druidWolfForm();
			}
			if (spellChoice == 5) {
				druidHawkForm();
			}
			if (spellChoice == 6) {
				druidSnakeForm();
			}
			if (spellChoice == 7) {
				druidHealingBalm();
			}
			if (spellChoice == 8 && dude[moveGuy].getRenown() == 801) {
				earthQuake();
			}
			if (spellChoice == 8 && dude[moveGuy].getParagon() == 8012 && dude[moveGuy].getRenown() != 801) {
				forceOfNature();
			}
			if (spellChoice == 9 && dude[moveGuy].getParagon() == 8012 && dude[moveGuy].getRenown() == 801) {
				forceOfNature();
			}
		
		}

	}
	
}

void necromancerSpells() {
	if (dude[moveGuy].getCharacterClass() == 8)
	{
			while (dude[moveGuy].getPrestige() == 802) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			cout << "3:Leech\n  mana: 5\n  range: 7\n4:Death channel\n5:Blood to mana\n";
			
			if (dude[moveGuy].getRenown() == 801) {
				cout << "6:Earthquake\n  mana: 10\n  range: 7\n";
			}
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				mageLeech();
			}
			if (spellChoice == 4) {
				necromancerDeathChannel();
			}
			if (spellChoice == 5) {
				necromancerBloodToMana();
			}
			if (spellChoice == 6 && dude[moveGuy].getRenown() == 801) {
				earthQuake();
			}
		}

	}
	
}

void spellswordSpells() {
	
	if (dude[moveGuy].getCharacterClass() == 8)
	{
			while (dude[moveGuy].getPrestige() == 803) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage missile\n  mana: 5\n  range: 7\n2:Mage minor missile\n  mana: 3\n  range: 10\n";
			cout << "3:Haste \n  mana: 5\n  range: 3\n  duration: 2\n4:Enchant weapon \n  mana: 5\n";
			
			if (dude[moveGuy].getRenown() == 801) {
				cout << "5:Earthquake\n  mana: 10\n  range: 7\n";
			}
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMissile();
				}
			if (spellChoice == 2) {
				mageMinorMissile();
			}
			if (spellChoice == 3) {
				mageHaste();
			}
			if (spellChoice == 4) {
				spellswordEnchantWeapon();
			}
			if (spellChoice == 5 && dude[moveGuy].getRenown() == 801) {
				earthQuake();
			}
		}

	}
	
}




void goblinMageSpells() {
	while (dude[moveGuy].getCharacterClass() == 107)
	{
	
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Mage minor missile\n  mana: 3\n  range: 10\n";
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				mageMinorMissile();
			}
		

	}
	
	
}

void goblinPriestHeal() {
	int spellChoice = 0;
	int j = 0;
	
	if (dude[moveGuy].getMana() < 5) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
	cout << "\nWho do you want to heal?\n0:back to spell list\n";
	
			//displays team mates if in team 2
		if (dude[moveGuy].getTeam() == 1){
			for (j=1; j <= teamSize1; j++) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
		//displays team mates if in team 1	
		if (dude[moveGuy].getTeam() == 2){
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
	
	cin >> spellChoice;
	if (spellChoice > 0) {
			
			// checks spell range
			if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
			{ 
				if (dude[spellChoice].getHealth() <  dude[spellChoice].getMaxHealth()) { //checks if the target has low enough health to be healed
				spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 5);//uses up 5 mana
						int healAmount = rd4() + 1;
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() + healAmount);
						cout << "A shining light comes from " << dude[moveGuy].getName() << "'s hands and heals " << dude[spellChoice].getName() << " " << healAmount << " health" << " and is now at " << dude[spellChoice].getHealth() << " health\n\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + healAmount);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (healAmount) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (healAmount) * 2);}//if team 2, gets money
					
				}
				else {
					cout << "\nThey are not low on health\n";
					}
				}
			else {
				cout << "\nThey are out of range\n";
			}
		
	}
	}
		
	
	return;
}

void goblinPriestSpells() {
	
	while (dude[moveGuy].getCharacterClass() == 108)
	{
			
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Heal\n  mana: 5\n  range: 1\n";
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				goblinPriestHeal();
			}
		

	}
	
	
	return;
}


void clericLightningStrike() {//10 mana
	int spellChoice = 0;
	int spellDamage = 0;
	bool keepLooping = 1;
	int j = 0;
	
	if (dude[moveGuy].getMana() < 10 && !freeMana) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
		if (dude[moveGuy].getTeam() == 1){//if in team 1, finds enemies
			while (keepLooping) {
				j = rand() % teamSize2 + teamSize1 + 1;//picks a random enemy
				if (dude[j].getHealth() > 0) { //checks if alive
					spellChoice = j;
					keepLooping = 0;
					}
				}
			}

		if (dude[moveGuy].getTeam() == 2){//if in team 2 finds enemies
			while (keepLooping) {
				j = rand() % teamSize1 + 1;//picks a random enemy
				if (dude[j].getHealth() > 0) { //checks if alive
					spellChoice = j;
					keepLooping = 0;
					}
				}
			}
	

		
		spellDamage = rd4() + rd4() + rd4();
		
		//if they are a cleric and the enemy is hurt more by holy
		if (dude[moveGuy].getCharacterClass() == 3 && (lichForm[spellChoice] == 1 || dude[spellChoice].getBirthRight() == 2 || dude[spellChoice].getBirthRight() == 3 )) {//does extra to liches, vampires, and werewolves if the caster is a priest
			spellDamage = spellDamage * 2;
		}
		
		dude[spellChoice].setHealth(dude[spellChoice].getHealth() - spellDamage);//does damage
		cout << "Lightning shoots straight in the air from " << dude[moveGuy].getName() << "'s raised weapon and strikes " << epithet(spellChoice) << " doing " << spellDamage << " damage\n";
		
		if (dude[spellChoice].getHealth() > 0) {//if still alive
			cout << dude[spellChoice].getName() << " now has " << dude[spellChoice].getHealth() << " health\n";
		}
		else {
			cout << epithet(spellChoice) << "'s body convulses from the energy and their crispy body falls to the ground.\n";
		}
		
		
		if (!(freeMana)) {//uses mana if it wasn't free
			dude[moveGuy].setMana(dude[moveGuy].getMana() - 10);//uses up 10 mana
		}
	}
	
	
	
	return;
}

//this is where the cleric heal spell is stored d8+4 and heals poison
void clericHeal() {
	int spellChoice = 0;
	int j = 0;
	
	if (dude[moveGuy].getMana() < 8) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
	cout << "\nWho do you want to heal?\n0:back to spell list\n";
	
			//displays team mates if in team 2
		if (dude[moveGuy].getTeam() == 1){
			for (j=1; j <= teamSize1; j++) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
		//displays team mates if in team 1	
		if (dude[moveGuy].getTeam() == 2){
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
	
	cin >> spellChoice;
	if (spellChoice > 0) {
			
			// checks spell range
			if (4 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
			{ 
				if (dude[spellChoice].getHealth() <  dude[spellChoice].getMaxHealth() ) { //checks if the target has low enough health to be healed
				spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					if (rd20() == 20) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 8);//uses up 8 mana
						int healAmount = rd8() + rd8() + 8;
						
						if (dude[moveGuy].getParagon() == 3011) {//cleric of healing
							healAmount = healAmount + rd4() + rd4() - 2;
						}
						
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() + healAmount);
						cout << "A very bright shining light comes from " << dude[moveGuy].getName() << "'s hands and heals " << dude[spellChoice].getName() << " for " << healAmount << " health\n\n";
						if (poison[spellChoice] > 0) {
							poison[spellChoice] = 0;
							cout << dude[spellChoice].getName() << " is also healed of poison";
						}
						
						if (burn[spellChoice] > 0) {
							burn[spellChoice] = 0;
							cout << dude[spellChoice].getName() << " is also healed of their burns";
						}
						if (burn[spellChoice] < 0) {
							burn[spellChoice] = 0;
							cout << dude[spellChoice].getName() << " is also healed of their freezing";
						}
						
						dude[moveGuy].setXp(dude[moveGuy].getXp() + 20);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (20) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (20) * 2);}//if team 2, gets money
					}
					else {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 8);//uses up 8 mana
						int healAmount = rd8() + 4;
						
						if (dude[moveGuy].getParagon() == 3011) {//cleric of healing
							healAmount = healAmount + rd4() - 1;
						}
						
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() + healAmount);
						cout << "A shining light comes from " << dude[moveGuy].getName() << "'s hands and heals " << dude[spellChoice].getName() << " " << healAmount << " health" << " and is now at " << dude[spellChoice].getHealth() << " health\n\n";
						if (poison[spellChoice] > 0) {
							poison[spellChoice] = 0;
							cout << dude[spellChoice].getName() << " is also healed of poison";
						}
						if (burn[spellChoice] > 0) {
							burn[spellChoice] = burn[spellChoice] / 2;
							cout << dude[spellChoice].getName() << " is also healed of some of their burns";
						}
						if (burn[spellChoice] < 0) {
							burn[spellChoice] = burn[spellChoice] / 2;
							cout << dude[spellChoice].getName() << " is also healed of some of their freezing";
						}
						
						dude[moveGuy].setXp(dude[moveGuy].getXp() + healAmount);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (healAmount) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (healAmount) * 2);}//if team 2, gets money
					}
				}
				else {
					cout << "\nThey are not low on health\n";
					}
				}
			else {
				cout << "\nThey are out of range\n";
			}
		
	}
	}
		
	return;
}

//list of spells for the cleric
void clericSpells() {

	
while (dude[moveGuy].getPrestige() == 301) {
	
		
		int spellChoice = 0;
		cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
		cout << "What spell do you want to cast?\n0:None\n1:Cleric heal\n mana: 8\n range: 2\n";
		cout << "2:Lightning strike\n mana: 10\n";
		
		cin >> spellChoice;
		if (spellChoice == 0) {
			break;
		}
		if (spellChoice == 1) {
			
			clericHeal();
		}
		if (spellChoice == 2) {
			
			clericLightningStrike();
		}
	

}
return;
}

//this is where the priest heal spell is stored d6+2 mana 8
void priestHeal() {
	int spellChoice = 0;
	int j = 0;
	
	if (dude[moveGuy].getMana() < 8) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
	cout << "\nWho do you want to heal?\n0:back to spell list\n";
	
			//displays team mates if in team 2
		if (dude[moveGuy].getTeam() == 1){
			for (j=1; j <= teamSize1; j++) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
		//displays team mates if in team 1	
		if (dude[moveGuy].getTeam() == 2){
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
				if (dude[j].getHealth() > 0) { //checks for team mates who aren't dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
	
	cin >> spellChoice;
	if (spellChoice > 0) {
			
			// checks spell range
			if (4 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
			{ 
				if (dude[spellChoice].getHealth() <  dude[spellChoice].getMaxHealth()) { //checks if the target has low enough health to be healed
				spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					if (rd20() == 20) {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 8);//uses up 8 mana
						int healAmount = rd6() + rd6() + 4;
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() + healAmount);
						cout << "A very bright shining light comes from " << dude[moveGuy].getName() << "'s hands and heals " << dude[spellChoice].getName() << " for " << healAmount << " health\n\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + 20);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (20) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (20) * 2);}//if team 2, gets money
						
					}
					else {
						dude[moveGuy].setMana(dude[moveGuy].getMana() - 8);//uses up 8 mana
						int healAmount = rd6() + 2;
						dude[spellChoice].setHealth(dude[moveGuy].getHealth() + healAmount);
						cout << "A shining light comes from " << dude[moveGuy].getName() << "'s hands and heals " << dude[spellChoice].getName() << " " << healAmount << " health" << " and is now at " << dude[spellChoice].getHealth() << " health\n\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + healAmount);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (healAmount) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (healAmount) * 2);}//if team 2, gets money
					}
				}
				else {
					cout << "\nThey are not low on health\n";
					}
				}
			else {
				cout << "\nThey are out of range\n";
			}
		
	}
	}
		
	return;
}

//list of spells for the priest and mounted pally
void priestSpells() {

	
while ((dude[moveGuy].getCharacterClass() == 3 && dude[moveGuy].getPrestige() == 0) || (dude[moveGuy].getPrestige() == 502 && dude[moveGuy].getParagon() != 5021)) {
	
		
		int spellChoice = 0;
		cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
		cout << "What spell do you want to cast?\n0:None\n1:Basic heal\n mana: 8\n range: 2\n";
		
		cin >> spellChoice;
		if (spellChoice == 0) {
			break;
		}
		if (spellChoice == 1) {
			
			priestHeal();
			}

	

}
return;
}


void acolyteCurse() { //range 5 duration 3 mana 5  50% chance to lower attack 20% 
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5)
	{
		cout << "\nWho do you wish to lower their attack?\n0: no one\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (25 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A light shines down from the sky on "  << dude[spellChoice].getName() << " lowering their attack\n";
					
					bless[spellChoice] = bless[spellChoice] - 3; //makes the curse spell counter go down 3
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	return;
	
}

void acolyteBless() { //range 3 duration 2 mana 5 50% chance to raise attack 20%
	int spellChoice = 0, j = 0, damage = 0;
	
	
	if (dude[moveGuy].getMana() >= 5)
	{
		cout << "\nWho do you wish to raise their attack?\n0: no one\n";
		
			//displays team if in team 1
			if (dude[moveGuy].getTeam() == 1){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for alllies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays team if in team 2	
			if (dude[moveGuy].getTeam() == 2){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for allies who aren't dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
		cout << endl;
		cin >> spellChoice;
		cout << endl;
		if (spellChoice > 0) {
				
				// checks spell range
				if (9 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
				{ 
					spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
					
					cout << "A light shines down from the sky onto " << dude[spellChoice].getName() << " raising their attack \n";
					
					bless[spellChoice] = bless[spellChoice] + 3; //makes the bless spell counter go up 3
					
					if (dude[moveGuy].getParagon() == 3022) {//acolyte of blessing does extra
						bless[spellChoice] = bless[spellChoice] + 3; //makes the bless spell counter go up 3 more
					}
					
					dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //uses up 5 mana
				}
				else {
					cout << "\nThey are not in range\n";
				}
			}
	}
	else 
	cout << "\nYou do not have the required mana to cast this\n\n";
	
	
	
	
	return;
}

void acolyteRevive() { //range 1 mana: all   if mana used >= 4d20 they get revived to a random health amount
	int spellChoice = 0;
	int j = 0;
	int reviveBonus = 0;
	
	if (dude[moveGuy].getMana() < 0) {
		cout << "You do not have the mana to do this\n\n"; }
	else {	 
	cout << "\nWho do you want to heal?\n0:back to spell list\n";
	
			//displays team mates if in team 2
		if (dude[moveGuy].getTeam() == 1){
			for (j=1; j <= teamSize1; j++) {
				if (dude[j].getHealth() <= 0) { //checks for team mates who are dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
		//displays team mates if in team 1	
		if (dude[moveGuy].getTeam() == 2){
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
				if (dude[j].getHealth() <= 0) { //checks for team mates who are dead
					cout << j << ": " << epithet(j) << endl;
					}
				}
			}
	
	cin >> spellChoice;
	if (spellChoice > 0) {
			
			// checks spell range
			if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
			{ 
				
				spellCast[moveGuy] = 1; //says the player cast a spell, and can't move twice
				
				if (dude[moveGuy].getParagon() == 3021) {
					reviveBonus = rd10();
					cout << epithet(moveGuy) << " glows and their chance for a reviving miracle increases by " << reviveBonus << endl;
				}
				
					if (dude[moveGuy].getMana() + reviveBonus >= rd20() * 4) {
						dude[spellChoice].setHealth(dude[spellChoice].getMaxHealth() / rd4() ); // random health amount
						cout << "A very bright shining light comes from " << dude[moveGuy].getName() << "'s hands and brings " << dude[spellChoice].getName() << " back to life\n\n";
						poison[spellChoice] = 0;
						dude[moveGuy].setXp(dude[moveGuy].getXp() + 20);//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (20) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (20) * 2);}//if team 2, gets money
						
					}
					else {
						cout << dude[spellChoice].getName() << " glows for a moment but fails to return to life\n";
					}
				dude[moveGuy].setMana(0); //drops their mana to 0
			}
			else {
				cout << "\nThey are out of range\n";
			}
		
	}
	}
		

	
	return;
}

void acolyteSpells() {
	
	
while (dude[moveGuy].getPrestige() == 302) {
	
		
		int spellChoice = 0;
		cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
		cout << "What spell do you want to cast?\n0:None\n1:Heal\n mana: 8\n range: 2\n2:Revive\n mana: All of it\n range: 1\n";
		cout << "3:Bless\n mana: 5\n range: 3\n4:Curse\n mana: 5\n range: 5\n";
		
		cin >> spellChoice;
		if (spellChoice == 0) {
			break;
		}
		if (spellChoice == 1) {
			clericHeal();
		}
		if (spellChoice == 2) {
			acolyteRevive();
		}
		if (spellChoice == 3) {
			acolyteBless();
		}
		if (spellChoice == 4) {
			acolyteCurse();
		}

	

}
return;
	
}


void learnBirthrights() {
	int pickBirthright = 0;
	
	
	return;
}

void learnRaces() {
	int pickRace = 0;
	
	
	cout << "What race do you want to learn more about?\n 1:Human\n 2:Wood elf\n 3:High elf\n 4:Dark elf\n 5:Hill dwarf\n 6:Mountain Dwarf\n 7:Halfling\n 8:Orc\n 9:Centaur\n";
	cin >> pickRace;
	cout << endl;
	
	switch (pickRace) {
		case 1:
		cout << "Human:\n";
		cout << "Random stat boosts\n";
		cout << "\nDescription: \n  Humans are the most average of the races. The stat boosts that they get are random, but always positive. ";
		cout << "Some of the stat boosts that they get can be fairly good. They are a great choice if you want to just play it safe and simple.\n";
		break;
		
		case 2:
		cout << "Wood elf:\n";
		cout << "Attack + 1\nDefense - 1\nMove + 1\nRange + 5\n";
		cout << "\nDescription: \n  Wood elves are the masters of archery. They are the only class to feature a range boost, so they ";
		cout << "can hit from really far away. They also get an attack boost, which especially helps archers and other low attack people. ";
		cout << "Their higher movement helps them to get to the high ground to have a better attack and range. The downside is that they ";
		cout << "have a lower defense, so it's best for them to keep their distance.\n";
		break;
		
		case 3:
		cout << "High elf:\n";
		cout << "Defense - 1\nHealth - 5\nMana regen + 2\nMana + 5\n  ";
		cout << "\nDescription: \n  High elves are fragile. They have lower health, and they have lower defense. They do not last very ";
		cout << "long in a melee because of this. However, they do know how to throw a spell pretty well. They get more mana than normal ";
		cout << "and they have a significant boost to their mana regen rate;";
		break;
		
		case 4:
		cout << "Dark elf: \n";
		cout << "Attack + 3\nDefense - 2\nMove + 2\n";
		cout << "\nDescription: \n  Dark elves have a very high attack. This means that they can do a lot of damage very fast, ";
		cout << "which is good, because with such a low defense they don't often last too long. They also have a pretty good move rate, ";
		cout << "this way they can quickly close the gap between them and their enemies.\n";
		break;
		
		case 5:
		cout << "Hill dwarf: \n";
		cout << "Attack + 1\nDefense + 1\nMove - 1\n";
		cout << "\nDescription: \n  Hill dwarves make great fighters. They get a boost to both attack and defense so they can last well in a fight. ";
		cout << "Their one downfall is that they are a bit slower, so watch out for the long range people who can take them out before they get there.\n";
		break;
		
		case 6:
		cout << "Mountain dwarf: \n";
		cout << "Attack + 1\nDefense + 2\nMove - 1\nHealth - 5\n";
		cout << "\nDescription: \n  Mountain dwarves are like hill dwarves, but even more dwarvy. They get a substantial boost to defense, and ";
		cout << "they also get an attack boost, however this is counteracted by a slower movement, and even more by having less health than normal.\n";
		break;
		
		case 7:
		cout << "Halfling: \n";
		cout << "Attack - 2\nDefense - 1\nMove + 2\n";
		cout << "\nDescription: \n  Halflings may not have very good looking stats, but it is balanced out by how lucky they are. ";
		cout << "They have a 1/10 chance to dodge regular attacks against them, and this stacks with the scouts ability to do the same.\n";
		break;
		
		case 8:
		cout << "Orc: \n";
		cout << "Attack + 2\nDefense - 1\nHealth + 5\n";
		cout << "\nDescription: \n  Orcs are the epitomy of berserkers. They get extra health, and they get a pretty good attack boost. ";
		cout << "Of course this means that they also have a lower defense, but this is not someone that you want to get in a fight with.\n";
		break;
		
		case 9:
		cout << "Centaur: \n";
		cout << "Attack + 1\nDefense - 1\nMove + 5\n";
		cout << "\nDescription: \n  Centaurs are fast. Like, really fast. No matter what class you choose, if they are a centaur, ";
		cout << "then they will end up being fast. They also get an attack boost, but lose some defense.\n";
		break;
		

		
		
		
	}
	return;
}

//descriptions of the classes, and shows their base stats
void learnClasses() {
	int pickClass = 0;
	
	
	cout << "What class do you want to learn more about?\n 1:Fighter \n 2:Archer \n 3:Priest \n 4:Berserker \n 5:Knight \n 6:Scout \n 7:Mage \n 8:Warlock \n 0:NPC  \n";
    cin >> pickClass;
    if (pickClass == 9) {
		cout << "What NPC do you want to learn more about?\n 101:Wolf  \n 102:Bear  \n 103:Goblin Fighter  \n 104:Goblin Archer  \n 105:Stone Golem \n 106:Iron Golem  \n 107:Goblin Mage  \n";
		cout << " 108:Goblin priest \n 109:Giant rat\n 110:Giant beetle\n 111:Giant ant\n";
		cin >> pickClass;
	}
	
	
	switch (pickClass) {
		case 1:
		cout << "\nFighter:\n\nAttack:" << fighter[0][1] << "\nDefense:" << fighter[0][2] << "\nHealth:" << fighter[0][3] << "\nMove:" << fighter[0][4] << "\nRange:" << fighter[0][5] << endl;
		
		cout << "\nDescription: \n	Fighters are built to take a hit and keep on swinging. They boast a fairly high attack and the highest base defense. They cannot move very fast,";
		cout << " but once they catch someone, it's over for them. Especially since the fighters have the ability to hold an enemy ";
		cout << "in place so they can't run away 50% of the time. They need to watch out for magic users though, because they recieve 25% more ";
		cout << "damage from the attacks. When they become renowned enough they can either throw axes occasionally or ";
		cout << "be overbearing so they are able to shove people backwards a space.\n";
		
		cout << "Prestiges:\n 1:Brawler\n 2:Defender\n";
		cin >> pickClass;
		switch (pickClass) {
			case 1:
			cout << "\nBrawler:\n\nAttack:" << fighter[0][1] + 5 << "\nDefense:" << fighter[0][2] + 1 << "\nHealth:" << fighter[0][3] + 5 << "\nMove:" << fighter[0][4] << "\nRange:" << fighter[0][5] << endl;
			cout << "\nDescription: \n	Brawlers are meant to bring the beat down, they have one of the highest attacks of anyone, and a super high ";
			cout << "defense to go with it. This is not someone you want to make angry. It's best to try to take them out from a distance ";
			cout << "preferably with magic. Because if you get close, you're not getting away.\n";
			
			break;
			
			case 2:
			cout << "\nDefender:\n\nAttack:" << fighter[0][1] + 2 << "\nDefense:" << fighter[0][2] + 3 << "\nHealth:" << fighter[0][3] + 10 << "\nMove:" << fighter[0][4] - 1 << "\nRange:" << fighter[0][5] << endl;
			cout << "\nDescription: \n	Defenders are as hard to kill as a brick wall, unfortunately they also move at probably the ";
			cout << "same speed as a brick wall too. They can also defend allies that are adjacent by adding 1/5 of their defense ";
			cout << "to their allies defense. If the enemy has a spell caster, watch out, because they can skip right past all their ";
			cout << "defenses. But for other enemies, it's like they are punching a boulder.\n";
			
			break;
			
			default:
			break;
		}
		
		break;
		
		case 2:
		cout << "\nArcher:\n\nAttack:" << archer[0][1] << "\nDefense:" << archer[0][2] << "\nHealth:" << archer[0][3] << "\nMove:" << archer[0][4] << "\nRange:" << archer[0][5] << endl;
		cout << "\nDescription: \n	Archers have the best range of any character. Most of their other stats are fairly average, but ";
		cout << "when someone can kill you from that far away, it's best not to make fun of them. Of course, at longer distances ";
		cout << "their chance to hit goes down, at their max range they have about a 50% chance to hit. When they become rather renowned they can ";
		cout << "eitherbe accurate and take a full round to be 100% accurate, or be nimble and able to run up hill much easier.\n";
		
		cout << "Prestiges:\n 1:Crossbowman\n 2:Longbowman\n";
		cin >> pickClass;
		switch (pickClass) {
			
			case 1:
			cout << "\nCrossbowman:\n\nAttack:" << archer[0][1] + 11 << "\nDefense:" << archer[0][2] + 2<< "\nHealth:" << archer[0][3] << "\nMove:" << archer[0][4] - 1 << "\nRange:" << archer[0][5] << endl;
			cout << "\nDescription: \n	Crossbowmen can dish out a lot of damage at range. Their attack goes up significantly from ";
			cout << "how they were before their prestige. They also now boast a higher defense. They never miss at a range of 4 or ";
			cout << "less. They can wreak havoc on anyone who is otherwise tied up in a battle, but watch out for knights and others ";
			cout << "that are able to close the gap quickly. And the payment for such a long range high attack is that after each ";
			cout << "shot, the crossbowman needs to take a round to reload\n";
			break;
			
			case 2:
			cout << "\nLongbowman:\n\nAttack:" << archer[0][1] - 2 << "\nDefense:" << archer[0][2] << "\nHealth:" << archer[0][3] << "\nMove:" << archer[0][4] << "\nRange:" + 5 << archer[0][5] << endl;
			cout << "\nDescription \n	Longbowman know how to make a big impact from a long distance away. They have the highest range ";
			cout << "of everyone. Though their stats may not seem impressive, be sure to keep in mind that their attacks are only ";
			cout << "3 Ap, up to 3 times a turn. So, they can attack 3 times, or move and attack twice. This makes them super ";
			cout << "versatile, and against lower defense people, like mages and berserkers, the longbowman can wreak havoc on them.\n";
			break;
			
			default:
			break;
		}
		
		break;
		
		case 3:
		cout << "\nPriest:\n\nAttack:" << priest[0][1] << "\nDefense:" << priest[0][2] << "\nHealth:" << priest[0][3] << "\nMove:" << priest[0][4] << "\nRange:" << priest[0][5] << "\nMax Mana:" << priest[0][13] << "\nMana Regen:" << priest[0][14] << endl;
		cout << "\nDescription: \n	Priests may not have much defense, but that doesn't mean that they'll go down easy. They have  a ";
		cout << "heal spell that can change the game very quickly. And though their attack is fairly low, they'll still get some ";
		cout << "hits in, especially on the lower defense enemies. Priests shine the most when with a group, that fighter that ";
		cout << "you took forever to get his health down, now can get back up to full health. As they gain renown they can either be blessed ";
		cout << "with a random stat boost at the beginning of each game, or randomly gain health and mana with increasing frequency as their health ";
		cout << "goes down.\n";
		
		cout << "Prestiges:\n 1:Cleric\n 2:Acolyte\n 3:Paladin\n";
		cin >> pickClass;
		switch (pickClass) {
			case 1:
			cout << "\nCleric:\n\nAttack:" << priest[0][1] + 3 << "\nDefense:" << priest[0][2] + 2 << "\nHealth:" << priest[0][3] << "\nMove:" << priest[0][4] << "\nRange:" << priest[0][5] << "\nMax Mana:" << priest[0][13] << "\nMana Regen:" << priest[0][14] << endl;
			cout << "\nDescription: \n	Clerics are a great balance between battle prowess, and team usefulness. They gain some ";
			cout << "attack and defense, and they also get access to a better heal spell that can heal more, and that can cancel ";
			cout << "poison. They are valuable on a team because they can heal some of your heavy hitters, but, if they need to ";
			cout << "a cleric can pack a pretty powerful punch on their own.\n";
			break;
			
			case 2:
			cout << "\nAcolyte:\n\nAttack:" << priest[0][1] << "\nDefense:" << priest[0][2] << "\nHealth:" << priest[0][3] << "\nMove:" << priest[0][4] << "\nRange:" << priest[0][5] << "\nMax Mana:" << priest[0][13] + 10 << "\nMana Regen:" << priest[0][14] + 2 << endl;
			cout << "\nDescription: \n	Acolytes are very useful team-mates to have. They have a great heal spell, and they have ";
			cout << "the ability to bless or curse someone which will raise or lower their attack by 20%. But that's not all, they also ";
			cout << "can raise an ally from the dead, though this takes a lot of mana, and still isn't guaranteed. But it can be ";
			cout << "a major game changer.\n";
			break;
			
			case 3:
			cout << "\nPaladin:\n\nAttack:" << priest[0][1] + 4 << "\nDefense:" << priest[0][2] + 4 << "\nHealth:" << priest[0][3] + 5 << "\nMove:" << priest[0][4] - 1 << "\nRange:" << priest[0][5] << "\nMax Mana:" << priest[0][13] - 20 << "\nMana Regen:" << priest[0][14] - 3 << endl;
			cout << "\nDescription: \n	Paladins are holy warriors. Upon reaching their prestige they lose a lot of their max mana ";
			cout << "and a lot of their mana regen, but they gain a ton of attack and defense. plus they gain a powerful smite attack ";
			cout << "which is like a regular attack, but with two d12's rather than just one. This makes the attack fairly ";
			cout << "random, but with the potential to be devastating.\n";
			break;
			
			default:
			break;
			
			
		}
		
		break;
		
		case 4:
		cout << "\nBerserker:\n\nAttack:" << berserker[0][1] << "\nDefense:" << berserker[0][2] << "\nHealth:" << berserker[0][3] << "\nMove:" << berserker[0][4] << "\nRange:" << berserker[0][5] <<  endl;
		cout << "\nDescription: \n	Berserkers have the highest attack in the game by far, they also have the lowest defense of all. ";
		cout << "This means that any game with a berserker on the field ends quickly, they can be risky to use, but when they pay off, ";
		cout << "then watch out, because they really dish out the damage. They are especially good against mages because since the ";
		cout << "berserker's defense is so small, the fact that a mage gets to skip past defense doesn't matter as much. As the beserker fights ";
		cout << "battles and wins renown they can choose between either sprinting fast on the first turn, or having the ability to rage and lose ";
		cout << "some health to increase their attack damage for one attack.\n";
		
		cout << "Prestiges:\n 1:Battlerager\n 2:Thumper\n";
		cin >> pickClass;
		switch (pickClass) {
			case 1:
			cout << "\nBattlerager:\n\nAttack:" << berserker[0][1] - 3 << "\nDefense:" << berserker[0][2] - 1 << "\nHealth:" << berserker[0][3] + 10 << "\nMove:" << berserker[0][4] << "\nRange:" << berserker[0][5] <<  endl;
			cout << "\nDescription: \n	Battleragers make regular berserkers look sane and docile. Though they now do less damage per ";
			cout << "attack, they also get to make an extra attack. This means that they can do a ton of damage per turn. Plus since ";
			cout << "they can move and then attack twice, they still do lots of damage right from the start. Though they can have ";
			cout << "troubles when facing an opponent with a high defense because their lowered attack doesn't usually make it through.\n";
			break;
			case 2:
			cout << "\nThumper:\n\nAttack:" << berserker[0][1] << "\nDefense:" << berserker[0][2] << "\nHealth:" << berserker[0][3] + 10 << "\nMove:" << berserker[0][4] << "\nRange:" << berserker[0][5] + 1 <<  endl;
			cout << "\nDescription: \n	Thumpers wield massives battlehammers that can crush foes. This gives them a longer reach so ";
			cout << "they can attack their opponent before the opponent can retaliate. They also have a bloodlust ability that raises ";
			cout << "their attack as their health goes down. Their attack goes up by 1/10 of the damage they have recieved. So when ";
			cout << "they are a low health, their enemies should beware, because their attack becomes beyond formidable.\n";
			break;
			
			default:
			break;
		}
		break;
		
		case 5:
		cout << "\nKnight:\n\nAttack:" << knight[0][1] << "\nDefense:" << knight[0][2] << "\nHealth:" << knight[0][3] << "\nMove:" << knight[0][4] << "\nRange:" << knight[0][5] << endl;
		cout << "\nDescription: \n	Knights have an astonishingly high move rate and have an above average attack and defense. ";
		cout << "If you ever need to get across a field very fast, they are the best choice. Plus they have a very powerfull charge ";
		cout << "special. If they move more than 5 spaces in the x or y direction, they will do 50% more damage, and, as if that ";
		cout << "wasn't enough already, they will recieve 1/3 less damage that turn. utilizing their charge can be a big game changer. If a ";
		cout << "knight gets enough renown, they they can either become inspiring, and hae a chance to raise the attack of nearby allies, ";
		cout << "or untouchable, so that when they charge they get an even larger boost to their defense.\n";
		
		cout << "Prestiges:\n 1:Battlerager\n 2:Thumper\n";
		cin >> pickClass;
		switch (pickClass) {
			case 1:
			cout << "\nLancer:\n\nAttack:" << knight[0][1] + 3 << "\nDefense:" << knight[0][2] + 2 << "\nHealth:" << knight[0][3] << "\nMove:" << knight[0][4] + 3 << "\nRange:" << knight[0][5] <<  endl;
			cout << "\nDescription: \n	Lancers are just like regular knights, but even more awesome. They have more attack and defense ";
			cout << "and they get more moe too. They also have an even better attack from charging the enamy. If a lancer charges ";
			cout << "an enemy, then the lancer will do double damage. This leads to lancers being one of the best units in the game ";
			cout << "for quickly taking out lower defense enemies such as berserkers and mages.\n";
			break;
			case 2:
			cout << "\nMounted Paladin:\n\nAttack:" << knight[0][1] + 2 << "\nDefense:" << knight[0][2] + 2 << "\nHealth:" << knight[0][3] << "\nMove:" << knight[0][4] << "\nRange:" << knight[0][5] << "\nMax Mana:" << knight[0][13] + 10 << "\nMana Regen:" << knight[0][14] + 4 <<  endl;
			cout << "\nDescription: \n	Mounted Paladins are the best at getting the healing powers to the front line. They still ";
			cout << "have their great moe rate, and their charging attack, but now they can heal people. This makes them ideal for ";
			cout << "quickly running up the the frontline to heal your fighter that got in a little over his head. Also, since  ";
			cout << "the mounted paladin still has a good attack and defense, he can stand his own pretty well and just heal ";
			cout << "himself as the need arises.\n";
			break;
			
			default:
			break;
		}
		break;
		
		case 6:
		cout << "\nScout:\n\nAttack:" << scout[0][1] << "\nDefense:" << scout[0][2] << "\nHealth:" << scout[0][3] << "\nMove:" << scout[0][4] << "\nRange:" << scout[0][5] << endl;
		cout << "\nDescription: \n	Scouts have a fairly high attack and a respectable defense, and one of the highest move rates. ";
		cout << "they also have the ability to re-roll an attack if they roll a 1, and to re-roll defense if they roll a 1 or 2. ";
		cout << "This helps them to be fairly hard to get a one hit kill on. When they become renowned enough a scout can learn to backstab, which ";
		cout << "will cut through half of the opponent's defense. Or they can daze an opponent, which will make them lose part of their turn.\n";
		
		
		
		cout << "Prestiges:\n 1:Mounted Archer\n 2:Assassin\n 3:Ranger\n";
		cin >> pickClass;
		switch (pickClass) {
			case 1:
			cout << "\nMounted Archer:\n\nAttack:" << scout[0][1] + 3 << "\nDefense:" << scout[0][2] << "\nHealth:" << scout[0][3]  << "\nMove:" << scout[0][4] + 4 << "\nRange:" << scout[0][5] + 12 <<  endl;
			cout << "\nDescription: \n Mounted Archers are the kings of hit and run tactics. They have a great range and one ";
			cout << "of the fastest move rates in the game, and they have a fairly high attack too. They are great for slowly ";
			cout << "chipping down on you enemies with a lot of health, or for when there is a berserker that you don't want ";
			cout << "to get too close to. You can also have them run back to your healers after each attack run as you tear down ";
			cout << "your enemies defense.\n";
			break;
			
			case 2:
			cout << "\nAssassin:\n\nAttack:" << scout[0][1] + 3  << "\nDefense:" << scout[0][2] << "\nHealth:" << scout[0][3]  << "\nMove:" << scout[0][4] << "\nRange:" << scout[0][5] <<  endl;
			cout << "\nDescription: \n Assassins can deal a ton of damage. They have a super high attack and a ton of usefull ";
			cout << "abilities. Their attacks add 2 poison to the poison counter for each attack, and they have a 10% chance each attack to get a ";
			cout << "crit, which will do double damage. They can get a bunch of attacks in and then just flee and let the poison do ";
			cout << "its work. Their high attack can even pierce a fighter, and their poison can ignore the fighter's defense.\n";
			break;
			
			case 3:
			cout << "\nRanger:\n\nAttack:" << scout[0][1] - 1  << "\nDefense:" << scout[0][2] << "\nHealth:" << scout[0][3]  << "\nMove:" << scout[0][4] << "\nRange:" << scout[0][5] + 8 <<  endl;
			cout << "\nDescription: \n Rangers are like a jack of all trades. They have a high enough attack to be able to melee well ";
			cout << "but they all have a ranged attack. They take a fair decrease in attack power when at range, but they make up for ";
			cout << "this because they can move, and then attack twice. So they can just rain arrows, or attacks. This makes them ";
			cout << "great for fleeing while still being able to get in 2 attacks per turn.\n";
			break;
			
			default:
			break;
		}
		
		
		break;
		
		case 7:
		cout << "\nMage:\n\nAttack:" << mage[0][1] << "\nDefense:" << mage[0][2] << "\nHealth:" << mage[0][3] << "\nMove:" << mage[0][4] << "\nRange:" << mage[0][5] << "\nMax Mana:" << mage[0][13]  << "\nMana Regen:" << mage[0][14]  <<  endl;
		cout << "\nDescription: \n	Mages are very unique to use. Their attack and defense are dismal, and they move slow. But, ";
		cout << "they have access to some powerful magic. Their mage missile spells get to skip through armour, which makes them ";
		cout << "great for attacking those high defense enemies. Plus since they can wait a few turns to fill up their mana pool ";
		cout << "they are able to unleash a ton of damage in a single turn. As a mage gains power and becomes renowned they can either ";
		cout << "choose to become rapid-fire and launch an additional ball with each mage missile. Or become mystic, and increase ";
		cout << "the damage done by their regular attack by 3\n";
		
		cout << "Prestiges:\n 1:Fire Mage\n 2:Water Mage\n 3:Arcane Summoner\n";
		cin >> pickClass;
		switch (pickClass) {
			
			case 1:
			cout << "\nFire Mage:\n\nAttack:" << mage[0][1] + 5  << "\nDefense:" << mage[0][2] << "\nHealth:" << mage[0][3]  << "\nMove:" << mage[0][4] << "\nRange:" << mage[0][5]  << "\nMax Mana:" << mage[0][13]  << "\nMana Regen:" << mage[0][14]  <<  endl;
			cout << "\nDescription: \n Fire Mages are all about doing as much damage as they can. They have a fireball that can do ";
			cout << "a ton of AOE damage. They also have a poison spell that does initial damage as well as raising the poison counter. ";
			cout << "The ice touch spell does 50% extra damage and slows the enemy down. If their health starts getting low they can  ";
			cout << "use their leech spell to get it back. Fire mages are great at decimating berserkers before they get a chance ";
			cout << "to even get in close. \n";
			break;
			
			case 2:
			cout << "\nWater Mage:\n\nAttack:" << mage[0][1]  << "\nDefense:" << mage[0][2] + 3 << "\nHealth:" << mage[0][3]  << "\nMove:" << mage[0][4] << "\nRange:" << mage[0][5]  << "\nMax Mana:" << mage[0][13]  << "\nMana Regen:" << mage[0][14]  <<  endl;
			cout << "\nDescription: \n Water Mages are built to give buffs and debuffs. They can speed up allies, or slow enemies. ";
			cout << "They can also shield allies from damage, or shield an ally from arrows. Their usefullness is epecially shown ";
			cout << "when you sheild someone who has a low defense, like a berserker or a spellcaster, because it can almost ";
			cout << "effectively double their defense. And helping out your slower fighters can help get them where they need to be.\n";
			break;
			
			case 3:
			cout << "\nArcane Summoner:\n\nAttack:" << mage[0][1]  << "\nDefense:" << mage[0][2] << "\nHealth:" << mage[0][3]  << "\nMove:" << mage[0][4] << "\nRange:" << mage[0][5]  << "\nMax Mana:" << mage[0][13] + 15 << "\nMana Regen:" << mage[0][14] + 4 <<  endl;
			cout << "\nDescription: \n Arcane Summoners are the most well rounded mages. They can speed or slow people, but they ";
			cout << "still have some good attack spells. They can shoot a fireball for an awesome AOE attack, or they can leech ";
			cout << "health away from someone. They also have an amazing mana regen rate, so they can use their mage missiles  ";
			cout << "super fast. If your team needs a spellcaster, but you don't know what kind, an arcane summoner is you best bet.\n";
			break;
			
			default:
			break;
		
		break;
	}
		break;
		
		case 8:
		cout << "\nWarlock:\n\nAttack:" << warlock[0][1] << "\nDefense:" << warlock[0][2] << "\nHealth:" << warlock[0][3] << "\nMove:" << warlock[0][4] << "\nRange:" << warlock[0][5] << "\nMax Mana:" << warlock[0][13]  << "\nMana Regen:" << warlock[0][14]  <<  endl;
		cout << "\nDescription: \n	Warlocks are similar to mages. But they boast a higher attack and defense. This does come at a cost, as their ";
		cout << "mana pool is significantly smaller. This means that they can't unload quite as many spells at once. However, their ranged attack, ";
		cout << "though not very large, is perfect for attacking the lower defense units. This leaves them open to use their spells on the higher ";
		cout << "defense units, such as fighters and knights. As they practice a more primal type of magic, as a warlock gains renown they can ";
		cout << "either become earthshaking, and gain a powerfull spell that does damage and makes a large pit in the ground. Or they can be ";
		cout << "animalistic and gain an animal companion to help fight with them at the cost of some stats\n";
		
		cout << "Prestiges:\n 1:Druid\n 2:Necromancer\n 3:Spellsword\n";
		cin >> pickClass;
		switch (pickClass) {//still need to make it display the right attack and defense etc.
			case 1:
			cout << "\nDruid:\n\nAttack:" << warlock[0][1] + 3 << "\nDefense:" << warlock[0][2] << "\nHealth:" << warlock[0][3] << "\nMove:" << warlock[0][4] << "\nRange:" << warlock[0][5] << "\nMax Mana:" << warlock[0][13] - 10  << "\nMana Regen:" << warlock[0][14]  <<  endl;
			cout << "\nDescription: \n	Druids are the masters of nature. They can use healing balms to help someone heal every turn, which makes them ";
			cout << "great if you don't have a dedicated healer. They also have a higher attack than before, but a smaller mana pool. This is all ";
			cout << "balanced by their great ability to shapeshift. They can turn into a wolf, bear, snake, or hawk. Each of these have their own ";
			cout << "different bonuses, and it makes the druid a formidable foe to melee with.\n";
			break;
			
			case 2:
			cout << "\nNecromancer:\n\nAttack:" << warlock[0][1] << "\nDefense:" << warlock[0][2] - 2 << "\nHealth:" << warlock[0][3] - 15<< "\nMove:" << warlock[0][4] << "\nRange:" << warlock[0][5] << "\nMax Mana:" << warlock[0][13] + 10 << "\nMana Regen:" << warlock[0][14]  + 2 <<  endl;
			cout << "\nDescription: \n Necromancers are the masters of life draining. They have the leech life spell, and they  also have a spell ";
			cout << "that can turn their own life into mana. Death channel is a very usefull spell later on in a game, because it does more damage ";
			cout << "depending on how many corpses there are. But the biggest ability of necromancers is their lich form. When they die they come back ";
			cout << "to undeath, and they are more magically powerful. But have less health, and they are succeptable to some holy attacks.\n";
			
			break;
			
			case 3:
			cout << "\nSpellsword:\n\nAttack:" << warlock[0][1] + 3 << "\nDefense:" << warlock[0][2] + 2 << "\nHealth:" << warlock[0][3] << "\nMove:" << warlock[0][4] + 2 << "\nRange:" << warlock[0][5] << "\nMax Mana:" << warlock[0][13]  << "\nMana Regen:" << warlock[0][14] - 1 <<  endl;
			cout << "\nDescription: \n Spellswords walk the line between a magic user and a fighter. They can have a fair attack, and still can ";
			cout << "use a handfull of spells like mage missile to soften up the heavily armoured enemies. Their most iconic spell is their ";
			cout << "enchant weapon spell. It can charge their weapon so that it will do extra damage upon attacking if they get a hit. Because of ";
			cout << "their unique position on the fighter-mage spectrum they can fulfill many roles depending on the playstyle.\n";
			break;
			 
		}
		
		break;
	}
	return;
}



//this is going to be the menu where player 1 can see their characters 
void menuFuncTeam1() {
	
int x = 0, j = 0;
int healthBar = 0, manaBar = 0;
	
	if (army1[0]) {
		cout << "Army name:        " << teamNames[1] << endl;
		cout << "Gold:             " << army1[1] << endl;
		cout << "Max size:         " << army1[2] << endl;
		cout << "Wins:             " << army1[4] << endl;
		cout << "Losses:           " << army1[5] << endl;
		cout << "Ties:             " << army1[6] << endl;
		cout << "Current streak:   " << army1[7] << endl;
		cout << "Best win streak:  " << army1[8] << endl;
		cout << "Worst loss streak:" << army1[9] << endl << endl;
	}
	else {
		cout << endl << teamNames[1] << " your team consists of:\n\n";
	}
    
for (x=1; x <= teamSize1; x++) {
	
	cout << "Number:    " << x  << endl;
    cout << "Name:      " << dude[x].getName() << endl << "Race:      " << dude[x].getRaceName() << endl << "Class:     " << dude[x].getRenownName() << dude[x].getCharacterClassName() << endl;
    if (dude[x].getPrestige() > 0) {
	cout << "Prestige:  " << dude[x].getPrestigeName() << endl;	
	}
    if (dude[x].getBirthRight() > 0) {
		cout << "Birthright:" << dude[x].getBirthRightName() << endl;
	}
    cout << "Attack:    " << dude[x].getAttack() << endl;
    cout << "Defense:   " << dude[x].getDefense() << endl;
    cout << "Health:    ";
    if (dude[x].getHealth() <= 0) { cout << "dead\n"; } else cout << dude[x].getHealth() << "/" << dude[x].getMaxHealth() << endl; //current out of total health
    healthBar = dude[x].getHealth() * 10 / dude[x].getMaxHealth(); 
	cout << "[";
	for (j=0; j < 10; j++) {
		if (j<=healthBar && healthBar > 0) {
			
			cout << "*";
		}
		else {
			cout << "-";
		}
	}
	cout << "]\n";
    if (dude[x].getMaxMana() > 0) {cout << "Mana:      " << dude[x].getMana() << "/" << dude[x].getMaxMana()<< endl;
    manaBar = dude[x].getMana() * 10 / dude[x].getMaxMana(); 
    cout << "[";
	for (j=0; j < 10; j++) {
		if (j<=manaBar) {
			cout << "*";
		}
		else {
			cout << "-";
		}
	}
	cout << "]" << endl;
    cout << "Mana Regen " << dude[x].getManaRegen() << endl;}
    cout << "Move:      " << dude[x].getMove() << endl;
    cout << "Range:     " << dude[x].getRange() << endl;
    cout << "Accuracy:  " << 100 - dude[x].getMissChance() << endl;
    cout << "Evasion:   " << dude[x].getEvasion() << endl;
    cout << "XP:        " << dude[x].getXp() << "/" << (50 + (dude[x].getLevel() * 30)) << endl;
    cout << "Level:     " << dude[x].getLevel() << endl;
    cout << "Location:  (" << dude[x].getXpos() << "," << dude[x].getYpos() << ")" << endl;
    cout << "Status:    ";
    if (defended[x] > 0) {cout << "Defended: " << defended[x] << "\t";}
    if (charge[x] > 0) {cout << "Charging\t";}
    if (bullrush[x] > 0) {cout << "Bullrushing\t";}
    if (poison[x] > 0) {cout << "Poisoned: " << poison[x] << "\t";}
    if (poison[x] < 0) {cout << "Healing Balm: " << -poison[x] << "\t";}
    if (burn[x] > 0) {cout << "Burning: " << burn[x] << "\t";}
    if (burn[x] < 0) {cout << "Freezing: " << - burn[x] << "\t";}
    if (haste[x] > 0) {cout << "Hastened: " << haste[x] << "\t";}
    if (haste[x] < 0) {cout << "Slowed: " << -haste[x] << "\t";}
    if (bless[x] > 0) {cout << "Blessed: " << bless[x] << "\t";}
    if (bless[x] < 0) {cout << "Cursed: " << -bless[x] << "\t";}
    if (enchantWeapon[x] > 0) {cout << "Weapon Enchantments Stored: " << enchantWeapon[x] << "\t";}
	if (shieldTimer[x] > 0) {cout << "Shielded: " << shield[x] << " for " << shieldTimer[x] << " turns\t";}
	if (hold[x] > 0) {cout << "Held in place\t";}
	if (protectRangedTimer[x] > 0) {cout << "Protected from arrows for " << protectRangedTimer[x] << " turns\t";}
	if (druidForm[x] == 1) {cout << "Bear form\t";}
	if (druidForm[x] == 2) {cout << "Wolf form\t";}
	if (druidForm[x] == 3) {cout << "Hawk form\t";}
	if (druidForm[x] == 4) {cout << "Snake form\t";}
	if (needToReload[x] > 0) {cout << "Needs to reload\t";}
	if (lichForm[x] == 1) {cout << "Lich\t";}
	if (backstabCoolDown[x] > 0) {cout << "Backstab cooldown: " << backstabCoolDown[x] << "\t";}
	if (doubleShotCoolDown[x] > 0) {cout << "Double-shot cooldown: " << doubleShotCoolDown[x] << "\t";}
	if (boundCoolDown[x] > 0) {cout << "Bound cooldown: " << boundCoolDown[x] << "\t";}
	if (dazeCoolDown[x] > 0) {cout << "Daze cooldown: " << dazeCoolDown[x] << "\t";} 
	if (crippleCoolDown[x] > 0) {cout << "Cripple cooldown: " << crippleCoolDown[x] << "\t";}
	if (pushBackCoolDown[x] > 0) {cout << "Pushback cooldown: " << pushBackCoolDown[x] << "\t";}
	if (throwCoolDown[x] > 0) {cout << "Throw cooldown: " << throwCoolDown[x] << "\t";}
	if (axeThrowCoolDown[x] > 0) {cout << "Axe throw cooldown: " << axeThrowCoolDown[x] << "\t";}
	if (aimedShotCoolDown[x] > 0) {cout << "Aimed shot cooldown: " << aimedShotCoolDown[x] << "\t";}
	if (piercingShotCoolDown[x] > 0) {cout << "Piercing shot cooldown: " << piercingShotCoolDown[x] << "\t";}
	if (breathCoolDown[x] > 0) {cout << "Breath cooldown: " << breathCoolDown[x] << "\t";}
	if (healingBalmCoolDown[x] > 0) {cout << "Healing Balm cooldown: " << healingBalmCoolDown[x] << "\t";}
	

	
    cout << endl << endl;
   }


    return;
}

//this is going to be the menu where player 2 can see their characters
void menuFuncTeam2() {
	
	int x = 0, j = 0;
	int healthBar = 0, manaBar = 0;
	
	if (army2[0]) {
		cout << "Army name:        " << teamNames[2] << endl;
		cout << "Gold:             " << army2[1] << endl;
		cout << "Max size:         " << army2[2] << endl;
		cout << "Wins:             " << army2[4] << endl;
		cout << "Losses:           " << army2[5] << endl;
		cout << "Ties:             " << army2[6] << endl;
		cout << "Current streak:   " << army2[7] << endl;
		cout << "Best win streak:  " << army2[8] << endl;
		cout << "Worst loss streak:" << army2[9] << endl << endl;
	}
	else {
		cout << endl << teamNames[2] << " your team consists of:\n\n";
	}

//this'll shoot out the stats for everyone
   for (x = teamSize1 + 1; x <= teamSize2 + teamSize1; x++ ) {
	
	cout << "Number:    " << x - teamSize1 << endl;
    cout << "Name:      " << dude[x].getName() << endl <<  "Race:      " << dude[x].getRaceName() << endl << "Class:     " << dude[x].getRenownName() << dude[x].getCharacterClassName() << endl;
    if (dude[x].getPrestige() > 0) {
	cout << "Prestige:  " << dude[x].getPrestigeName() << endl;	
	}
     if (dude[x].getBirthRight() > 0) {
		cout << "Birthright:" << dude[x].getBirthRightName() << endl;
	}
    cout << "Attack:    " << dude[x].getAttack() << endl;
    cout << "Defense:   " << dude[x].getDefense() << endl;
    cout << "Health:    ";
	if (dude[x].getHealth() <= 0) { cout << "dead\n"; } else {cout << dude[x].getHealth() << "/" << dude[x].getMaxHealth() << endl;} //current out of total health
	healthBar = dude[x].getHealth() * 10 / dude[x].getMaxHealth(); 
	cout << "[";
	for (j=0; j < 10; j++) {
		if (j<=healthBar && healthBar > 0) {
			cout << "*";
		}
		else {
			cout << "-";
		}
	}
	cout << "]\n";
    if (dude[x].getMaxMana() > 0) {cout << "Mana:      " << dude[x].getMana() << "/" << dude[x].getMaxMana() << endl;
    manaBar = dude[moveGuy].getMana() * 10 / dude[x].getMaxMana(); 
    cout << "[";
	for (j=0; j < 10; j++) {
		if (j<=manaBar) {
			cout << "*";
		}
		else {
			cout << "-";
		}
	}
	cout << "]" << endl;
    cout << "Mana Regen " << dude[x].getManaRegen() << endl;
	}
    cout << "Move:      " << dude[x].getMove() << endl;
    cout << "Range:     " << dude[x].getRange() << endl;
    cout << "Accuracy:  " << 100 - dude[x].getMissChance() << endl;
    cout << "Evasion:   " << dude[x].getEvasion() << endl;
    cout << "XP:        " << dude[x].getXp() << "/" << (50 + (dude[x].getLevel() * 30)) << endl;
    cout << "Level:     " << dude[x].getLevel() << endl;
    cout << "Location:  (" << dude[x].getXpos() << "," << dude[x].getYpos() << ")" << endl;
    cout << "Status:    ";
    if (defended[x] > 0) {cout << "Defended: " << defended[x] << "\t";}
    if (charge[x] > 0) {cout << "Charging\t";}
    if (bullrush[x] > 0) {cout << "Bullrushing\t";}
    if (poison[x] > 0) {cout << "Poisoned: " << poison[x] << "\t";}
    if (poison[x] < 0) {cout << "Healing Balm: " << -poison[x] << "\t";}
    if (burn[x] > 0) {cout << "Burning: " << burn[x] << "\t";}
    if (burn[x] < 0) {cout << "Freezing: " << - burn[x] << "\t";}
    if (haste[x] > 0) {cout << "Hastened: " << haste[x] << "\t";}
    if (haste[x] < 0) {cout << "Slowed: " << -haste[x] << "\t";}
    if (bless[x] > 0) {cout << "Blessed: " << bless[x] << "\t";}
    if (bless[x] < 0) {cout << "Cursed: " << -bless[x] << "\t";}
    if (enchantWeapon[x] > 0) {cout << "Weapon Enchantments Stored: " << enchantWeapon[x] << "\t";}
	if (shieldTimer[x] > 0) {cout << "Shielded: " << shield[x] << " for " << shieldTimer[x] << " turns\t";}
	if (hold[x] > 0) {cout << "Held in place\t";}
	if (protectRangedTimer[x] > 0) {cout << "Protected from arrows for " << protectRangedTimer[x] << " turns\t";}
	if (druidForm[x] == 1) {cout << "Bear form\t";}
	if (druidForm[x] == 2) {cout << "Wolf form\t";}
	if (druidForm[x] == 3) {cout << "Hawk form\t";}
	if (druidForm[x] == 4) {cout << "Snake form\t";}
	if (needToReload[x] > 0) {cout << "Needs to reload\t";}
	if (lichForm[x] == 1) {cout << "Lich\t";}
	if (backstabCoolDown[x] > 0) {cout << "Backstab cooldown: " << backstabCoolDown[x] << "\t";}
	if (doubleShotCoolDown[x] > 0) {cout << "Double-shot cooldown: " << doubleShotCoolDown[x] << "\t";}
	if (boundCoolDown[x] > 0) {cout << "Bound cooldown: " << boundCoolDown[x] << "\t";}
	if (dazeCoolDown[x] > 0) {cout << "Daze cooldown: " << dazeCoolDown[x] << "\t";} 
	if (crippleCoolDown[x] > 0) {cout << "Cripple cooldown: " << crippleCoolDown[x] << "\t";}
	if (pushBackCoolDown[x] > 0) {cout << "Pushback cooldown: " << pushBackCoolDown[x] << "\t";}
	if (throwCoolDown[x] > 0) {cout << "Throw cooldown: " << throwCoolDown[x] << "\t";}
	if (axeThrowCoolDown[x] > 0) {cout << "Axe throw cooldown: " << axeThrowCoolDown[x] << "\t";}
	if (aimedShotCoolDown[x] > 0) {cout << "Aimed shot cooldown: " << aimedShotCoolDown[x] << "\t";}
	if (piercingShotCoolDown[x] > 0) {cout << "Piercing shot cooldown: " << piercingShotCoolDown[x] << "\t";}
	if (breathCoolDown[x] > 0) {cout << "Breath cooldown: " << breathCoolDown[x] << "\t";}
	if (healingBalmCoolDown[x] > 0) {cout << "Healing Balm cooldown: " << healingBalmCoolDown[x] << "\t";}
	
	
    cout << endl << endl;
    
   }

    return;
}

void spellDescriptions() {
	cout << "Spell Name\t\tMana\tRange\tDamage\tOther\n";
	cout << "Mage Missile\t\t5\t7\t5D2\tif all 5 hit, does 10 damage\n";
	cout << "Minor Mage Missile\t3\t10\t3D2\t\n";
	cout << "Leech\t\t5\t7\tD4\tSpellcaster steals the damage done\n";
	cout << "Haste\t\t\t5\t3\t\tRaises move by 50% for 3 turns\n";
	cout << "Slow\t\t\t10\t3\t\tCuts move in half for 2 turns\n";
	cout << "Shield\t\t\t15\t3\t\tAdds half the spellcaster's defense to the target for 2 turns\n";
	cout << "Fireball\t\t15\t7\t2d4+50% chance to add attack, splash is 1d4 with 50% chance to add attack\n";
	cout << "Poison Sphere\t\t15\t12\tattack-1d6\tAdds 1d4 to the poison counter\n";
	cout << "Ice Touch\t\t10\t1\tregular attack +50% also slows for a turn\n";
	cout << "Protect From Arrows\t15\t3\t\tArrows have a 50% chance to miss person, lasts 2 turns\n";
	cout << endl;
	cout << "Priest Heal\t\t8\t2\t\tHeals for d6+2\n";
	cout << "Cleric heal\t\t8\t2\t\tHeals for d8+4 and heals poison\n";
	cout << "Revive\t\t\tAll\t1\t\tRevives if current mana is greater than 4d20\n";
	cout << "Bless\t\t\t5\t3\t\tlasts 2 turns, 50% chance to raise attack by 20%\n";
	cout << "Curse\t\t\t5\t5\t\tlasts 3 turns, 50 chance to lower attack by 20%\n";
	cout << "Smite\t\t\t5\t1\t\tA normal attack plus another d12\n";
	cout << "Healing balm\t\t5\t3\t\topposite of poison, moves counter D4\n";
	cout << endl;
	cout << "Druid forms:\tAttack\tDefense\tMove\tOther\n";
	cout << "Normal Form\t1\t1\t1\tCan still cast healing balm, or turn to another form\n";
	cout << "Bear Form\t3/2\t3/2\t1\t\n";
	cout << "Wolf Form\t5/4\t4/3\t2\t\n";
	cout << "Hawk Form\t1\t5/4\t3\t\t\n";
	cout << "Snake Form\t4/3\t1\t2\tpoisons for 2 counters\n";
	return;
}

//this'll be where the rule book will go
void menuFuncRules() {
	int menuChoice = 0, leaveMenu = 1;
		
		while (leaveMenu == 1) {
			cout << "\nI sincerely doubt that we can fit all of the rules into one menu\n\n";
			cout << "0: Do nothing\n";
			cout << "1: Spell descriptions\n";
			cout << "2: Class descriptions\n";
			cout << "3: Race descriptions\n";
			cin >> menuChoice;
			cout << endl;
			
			if (menuChoice == 0) {
				break;
			}
			if (menuChoice == 1) {
				spellDescriptions();
			}
			if (menuChoice == 2) {
				learnClasses();
				
			}
			if (menuChoice == 3) {
				learnRaces();
				
			}
		
		}
    return;
}

void buyXP(int team) {
	int yesNo = 0, i=0, j=0, xpGainer=0, amount=0;
	cout << "goherenow\n";
	if (team == 1) {
		cout << teamNames[1] << " you have " << army1[1] << " gold\n";
		cout << "Do you want to buy some xp for someone at 10 gold per xp?\n 1:Yes\n 2:No\n";
		cin >> yesNo;
		cout << endl;
		if (yesNo == 1) {
			cout << "Who would you like to buy xp for?\n";
			for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) {
						cout << j << ": " << epithet(j) << endl;
						}
				}
				
			cin >> xpGainer;
			cout << endl;
			cout << "How much xp do you want to buy for them?\n";
			cin >> amount;
			cout << endl;
			
			if (army1[1] >= 10 * amount) {
				armyGainMoney(1,-10*amount);
				
				dude[xpGainer].setXp(dude[xpGainer].getXp() + amount);//adds xp
			}
			else {
			cout << "You do not have enough gold.\n";
		}
		}
	}
	
	if (team == 2) {
		cout << teamNames[2] << " you have " << army2[1] << " gold\n";
		cout << "Do you want to buy some xp for someone at 10 gold per xp?\n 1:Yes\n 2:No\n";
		cin >> yesNo;
		cout << endl;
		if (yesNo == 1) {
			cout << "Who would you like to buy xp for?\n";
			for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) {
						cout << j << ": " << epithet(j) << endl;
						}
				}
				
			cin >> xpGainer;
			cout << endl;
			cout << "How much xp do you want to buy for them?\n";
			cin >> amount;
			cout << endl;
			
			if (army2[1] >= 10 * amount) {
				armyGainMoney(2,-10*amount);
				
				dude[xpGainer].setXp(dude[xpGainer].getXp() + amount);//adds xp
			}
			else {
			cout << "You do not have enough gold.\n";
		}
		}
	}
		
	
	return;
}

//the player 1 menu table of contents
void menuFuncPlayer1() {
	cout << teamNames[1] << " what would you like to do?\n 1:View team\n 2:View rules\n 3:Buy xp\n\n";
	cin >> userInput;
 
	if(userInput == 1) menuFuncTeam1();
	else if(userInput == 2) menuFuncRules();
	else if(userInput == 3) buyXP(1);
    return;
}

//the player 2 menu table of contents
void menuFuncPlayer2() {
	cout << teamNames[2] << " what would you like to do?\n 1:View team\n 2:View rules\n 3:Buy xp\n\n";
	cin >> userInput;
 
	if(userInput == 1) menuFuncTeam2();
	else if(userInput == 2) menuFuncRules();
	else if(userInput == 3) buyXP(2);
    return;
}

void miraculous() {
	if (dude[moveGuy].getRenown() == 302) {//if miraculous
				if (rd20() > dude[moveGuy].getMaxHealth() * 5 / dude[moveGuy].getHealth() + 15) {//as health goes down, chance goes up, from 0% to 25%
					cout << "A glimmering light shines down on " << epithet(moveGuy) << endl;
					if (rd2()==1) {
						if (dude[moveGuy].getHealth() < dude[moveGuy].getMaxHealth()) {
							
							cout << epithet(moveGuy) << " miraculously gained health.\n";
							cout << dude[moveGuy].getName() << " was at " << dude[moveGuy].getHealth() << " health, but is now at ";
							
							
							dude[moveGuy].setHealth(dude[moveGuy].getHealth() + dude[moveGuy].getMaxHealth() / 3);//inflicts damage
							if (dude[moveGuy].getHealth() > dude[moveGuy].getMaxHealth() ) { // stops it from going over health cap
								dude[moveGuy].setHealth(dude[moveGuy].getMaxHealth());
							}
							cout << dude[moveGuy].getHealth() << " health.\n\n";
						}
					}
					else {
						if (dude[moveGuy].getMana() < dude[moveGuy].getMaxHealth()) {
							
							cout << epithet(moveGuy) << " miraculously gained mana.\n";
							cout << dude[moveGuy].getName() << " was at " << dude[moveGuy].getMana() << " mana, but is now at ";
							dude[moveGuy].setMana(dude[moveGuy].getMana() + dude[moveGuy].getMaxMana() / 3);
							if (dude[moveGuy].getMana() > dude[moveGuy].getMaxHealth()) { // stops it from going over mana cap
								dude[moveGuy].setMana(dude[moveGuy].getMaxMana());
							}
							cout << dude[moveGuy].getMana() << " mana.\n\n";
						}
						
					}
				
				}
			}
			
	return;
}

void lichTransformation() {
	
	int i=0, j=0;
	
	for (j=1; j <= teamSize1; j++) {
		if (dude[j].getHealth() < 1) { //checks for dead people
			if (dude[j].getPrestige() == 802 && lichForm[j] == 0) {//if the dead guy is a necromancer
				cout << dude[j].getName() << "'s dead body convulses as they transform into a lich.\n";
				lichForm[j] = 1;
				
				dude[j].setHealth(dude[j].getMaxHealth() / 2 );//half health
				if (dude[j].getParagon() == 8021) {//necromancer of resurrection gets more health
					dude[j].setHealth(dude[j].getMaxHealth() * 3 / 4 );
				}
			}
		}
						}
	for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
		if (dude[j].getHealth() < 1) { //checks for dead people
			if (dude[j].getPrestige() == 802 && lichForm[j] == 0) {//if the dead guy is a necromancer
				cout << dude[j].getName() << "'s dead body convulses as they transform into a lich.\n";
				lichForm[j] = 1;
				dude[j].setHealth(dude[j].getMaxHealth() / 2 );//half health
				if (dude[j].getParagon() == 8021) {//necromancer of resurrection gets more health
					dude[j].setHealth(dude[j].getMaxHealth() * 3 / 4 );
				}
			}
		}
	}
					
	
	
	return;
}

void checkDisengage () {
	int i = 0;
				if (dude[moveGuy].getTeam() == 1) {//if in team 1, checks here
						for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on the other team and checks if they are adjacent
							
							
							
							if (1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
							{ 
								if (rd2() == 2) {//half the time they take damage
									//hurts people trying to flee
									cout << dude[i].getName() << " attacks " << dude[moveGuy].getName() <<  " for " << dude[i].getAttack() / 2 <<" damage while they are trying to flee\n";
									
									dude[moveGuy].setHealth(dude[moveGuy].getHealth() - dude[i].getAttack() / 2);//damage equal to half of attack
								}
							} 
							

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, checks here
							for (i=1; i <= teamSize1; i++) { //goes through all the people on the team and checks if they are adjacent
								
								if (1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
								{
									if (rd2() == 2) {//half the time they take damage
										//hurts people trying to flee
										cout << dude[i].getName() << " attacks " << dude[moveGuy].getName() <<  " for " << dude[i].getAttack() / 2 <<" damage while they are trying to flee\n";
										
										dude[moveGuy].setHealth(dude[moveGuy].getHealth() - dude[i].getAttack() / 2);//damage equal to half of attack
									}
									
									
								} 
		
							}
					}
	
}

void checkDefend() {
	int i = 0;
	if (dude[moveGuy].getTeam() == 1) {
		for (i=1; i <= teamSize1; i++) {
			if ( i != moveGuy && 1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos())) {
				if (dude[i].getPrestige() == 102) { //checks if the adjacent team-mate is a defender
					if (dude[moveGuy].getParagon() == 1022) {//defender of fortification
						defended[moveGuy] = dude[i].getDefense() / 4;//says they are under the defender's defense
					}
					else {
						defended[moveGuy] = dude[i].getDefense() / 5;//says they are under the defender's defense
					}
					
				}
			}
		}
	}
	if (dude[moveGuy].getTeam() == 2) {
		for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++) {
			if ( i != moveGuy && 1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos())) {
				if (dude[moveGuy].getParagon() == 1022) {//defender of fortification
					defended[moveGuy] = dude[i].getDefense() / 4;//says they are under the defender's defense
				}
				else {
					defended[moveGuy] = dude[i].getDefense() / 5;//says they are under the defender's defense
				}
			}
		}
	}
	
	
	return;
}

void checkBloodlust() {
	if (dude[moveGuy].getPrestige() == 402 ) { //checks if they are a thumper
		if (dude[moveGuy].getParagon() == 4022) {//thumper of bloodthirst
			damage = damage + ((dude[moveGuy].getMaxHealth() - dude[moveGuy].getHealth()) / 5);
		}
		else {
			damage = damage + ((dude[moveGuy].getMaxHealth() - dude[moveGuy].getHealth()) / 10);
		}
		if (dude[moveGuy].getMaxHealth() / dude[moveGuy].getHealth() > 4) cout << "\nThe berserker's bloodlust is is blinding\n";
		else if (dude[moveGuy].getMaxHealth() / dude[moveGuy].getHealth() >= 3) cout << "\nThe berserker's bloodlust is immense\n";
		else if (dude[moveGuy].getMaxHealth() / dude[moveGuy].getHealth() >= 2) cout << "\nThe berserker's bloodlust is great\n";
		else if (dude[moveGuy].getMaxHealth() / dude[moveGuy].getHealth() > 1) cout << "\nThe berserker's bloodlust is building\n";
}
	
	return;
}

void checkInspire() {
	
	int inspireBoost = rd4() - 1;
	int i = 0;
				if (dude[moveGuy].getTeam() == 1) {//if in team 1, checks here
						for (i=1; i <= teamSize1; i++) { //goes through all the people on your team to check if they are inspiring knights
							
							
							
							if (4 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
							{ 
								if (dude[i].getRenown() == 501 && inspireBoost > 0 && i != moveGuy) {
									cout << endl << epithet(moveGuy) << " is inspired by ";
									cout << epithet(i) << " and their attack does " << inspireBoost << " extra damage.\n";
									damage = damage + inspireBoost;
								}
								
							} 
							

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, checks here
							for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on your team to check if they are inspiring knights
								
								if (4 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
								{
									
									
									if (dude[i].getRenown() == 501 && inspireBoost > 0 && i != moveGuy) {
										cout << endl << epithet(moveGuy) << " is inspired by ";
										cout << epithet(i) << " and their attack does " << inspireBoost << " extra damage.\n";
										damage = damage + inspireBoost;
									}
									
								} 
		
							}
					}
	
	
	return;
}

//this checks if they get to charge
void checkCharge() {
		if (charge[moveGuy] == 1) { //here is where the knight charge special does the extra damage
		dude[moveGuy].setXp(dude[moveGuy].getXp() + 5);//adds xp
		if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
		if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
		cout << "\n\nThe knight's valient charge strikes the enemy\n";
		if (dude[moveGuy].getPrestige() == 501) {damage = damage + damage;} //lancers get extra
		else {damage = damage * 3 / 2;}
	}
	return;
}

//this checks if they get to bullrush
void checkBullrush() {
	//brawler of bullrushing
		if (bullrush[moveGuy] == 1) { //here is where the bullrush does the damage
		dude[moveGuy].setXp(dude[moveGuy].getXp() + 5);//adds xp
		if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
		if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
		cout << "\n\nThe brawler bullrushes into the enemy\n";
		damage = damage * 5 / 4;
	}
	return;
}


//checks if they are a spellsword with an enchanted weapon
void checkEnchantWeapon() {
	int enchantDamage = 0;
	int whatLevel = rd4();
	if (enchantWeapon[moveGuy] > 0) { //here is where the spellsword's enchant damage gets added
									//roll a d4, the higher the number the better roll you get for additional attack
									//either a d2, d4, d8, or a d12
									//also a 1/24 chance to unload all stored charges in the weapon doing 
									// 6 damage for each charge stored
									
		if (dude[moveGuy].getParagon() == 8032 && whatLevel == 1) {//spellsword of enchantment
			whatLevel = rd4();//reroll try on a bad roll for spellswords of enchantment
			cout << epithet(moveGuy) << "'s weapon glows as the charge increases\n";
		}
		if (whatLevel == 1) {
			enchantDamage = rd2();
			cout << endl << endl << dude[moveGuy].getName() << "'s weapon sparks and does an additional " << enchantDamage << " damage\n";
			damage = damage + enchantDamage;
		}
		else if (whatLevel == 2) {
			enchantDamage = rd4();
			cout << endl<< dude[moveGuy].getName() << "'s weapon crackles doing an additional " << enchantDamage << " damage\n";
			damage = damage + enchantDamage;
		}
		else if (whatLevel == 3) {
			enchantDamage = rd8();
			cout << endl << endl << dude[moveGuy].getName() << "'s weapon crackles loudly doing an additional " << enchantDamage << " damage\n";
			damage = damage + enchantDamage;
		}
		else if (whatLevel == 4) {
			if (rd6() == 6 || (dude[moveGuy].getParagon() == 8031 && rd2() == 1)) {//chance to unleash all, spellsword of unleashing has a higher chance
				enchantDamage = enchantWeapon[moveGuy] * 8;
				cout << endl << endl << dude[moveGuy].getName() << "'s weapon crackles and empties all its power doing an additional " << enchantDamage << " damage\n";
				damage = damage + enchantDamage;
				enchantWeapon[moveGuy] = 1; //it'll go to zero when it gets the minus-minus in a second
			}
			else {
				enchantDamage = rd12();
				cout << endl << endl << dude[moveGuy].getName() << "'s weapon crackles with power doing an additional " << enchantDamage << " damage\n";
				damage = damage + enchantDamage;
			}
			
		}
		
		enchantWeapon[moveGuy]--;
	}
	return;
	
}

void poisonDamages() {
	
			
			int poisonDamage = 0;
			
			
			if (poison[moveGuy] < 0) { //if they have healing balm, heals
				poisonDamage--;
				poisonDamage--;
				
				if (poison[moveGuy] < -3) { //more balm, more healing
					poisonDamage--;
					poisonDamage--;
					
					if (poison[moveGuy] < -5) { // lots of balm, lots of healing
						poisonDamage--;
						poisonDamage--;
					}
				}
				poison[moveGuy] = poison[moveGuy] + 1; //lowers the counter by 1
				
				dude[moveGuy].setHealth(dude[moveGuy].getHealth() - poisonDamage);//does healing
				if (dude[moveGuy].getHealth() > dude[moveGuy].getMaxHealth()) {//stops from going over max
					dude[moveGuy].setHealth(dude[moveGuy].getMaxHealth());
				}
				
				cout << dude[moveGuy].getName() << " is healed " << -poisonDamage << " by the healing balm and is now at " << dude[moveGuy].getHealth() << " health and is now at healing balm level " << -poison[moveGuy] << endl;
			}
			
			if (poison[moveGuy] > 0) { //if they are poisoned, does damage
				poisonDamage++;
				poisonDamage++;
				
				if (poison[moveGuy] > 3) { //more poison means more damage
					poisonDamage++;
					poisonDamage++;
					
					if (poison[moveGuy] > 5) { // lots of poison means lots of damage
						poisonDamage++;
						poisonDamage++;
					}
				}
				poison[moveGuy] = poison[moveGuy] - 1; //lowers the counter by 1
				
				dude[moveGuy].setHealth(dude[moveGuy].getHealth() - poisonDamage);//does damage
				cout << dude[moveGuy].getName() << " takes " << poisonDamage << " damage from poison and is at " << dude[moveGuy].getHealth() << " health and is now at poison level " << poison[moveGuy] << endl;
			}
			
			if (dude[moveGuy].getHealth() <= 0) { //if they died
				cout << epithet(moveGuy) << " succumbs to the poison and dies.\n";
				dude[moveGuy].setAp(0); //gets rid of their ap for the turn
			}
	
	return;
}

void burnDamages() {
	
			
			int burnDamage = 0;
			
			
			if (burn[moveGuy] < 0) { //if they are frozen
				burnDamage--;
				burnDamage--;
				burnDamage--;
				
				if (burn[moveGuy] < -3) { //more freezing, more damage
					burnDamage--;
					burnDamage--;
					burnDamage--;
					
					if (burn[moveGuy] < -5) { // lots of freezing, lots of damage
						burnDamage--;
						burnDamage--;
						burnDamage--;
					}
				}
				burn[moveGuy] = burn[moveGuy] + 1; //lowers the counter by 1
				dude[moveGuy].setHealth(dude[moveGuy].getHealth() + burnDamage );//inflicts damage (note, it is negative)
				
				cout << dude[moveGuy].getName() << " takes " << -burnDamage << " damage from freezing and is now at " << dude[moveGuy].getHealth() << " health and is now at freezing level " << -burn[moveGuy] << endl;
				
				if (dude[moveGuy].getHealth() <= 0) { //if they died
					cout << epithet(moveGuy) << " succumbs to the cold and their frozen body collapses\n";
					dude[moveGuy].setAp(0); //gets rid of their ap for the turn
				}
			}
			
			if (burn[moveGuy] > 0) { //if they are burned, does damage
				burnDamage++;
				burnDamage++;
				burnDamage++;
				
				if (burn[moveGuy] > 3) { //more burn means more damage
					burnDamage++;
					burnDamage++;
					burnDamage++;
					
					if (burn[moveGuy] > 5) { // lots of burn means lots of damage
						burnDamage++;
						burnDamage++;
						burnDamage++;
					}
				}
				burn[moveGuy] = burn[moveGuy] - 1; //lowers the counter by 1
				
				dude[moveGuy].setHealth(dude[moveGuy].getHealth() - burnDamage );//inflicts damage 
				
				cout << dude[moveGuy].getName() << " takes " << burnDamage << " damage from burning and is at " << dude[moveGuy].getHealth() << " health and is now at burn level " << burn[moveGuy] << endl;
			
				if (dude[moveGuy].getHealth() <= 0) { //if they died
					cout << epithet(moveGuy) << " succumbs to the burning and their charred body \n";
					dude[moveGuy].setAp(0); //gets rid of their ap for the turn
				}
			}
			
			
	
	return;
}

bool uncontested(int x,int y) {
	int i,j;
	bool team1Guy, team2Guy;
	
	for (i=-1;i<=1;i++) {//the for loops check everything within 1 space of the center, and the center
		for (j=-1;j<=1;j++) {
			if (mainMap.getGridPlayer(x + i,y + j) ) {
				if (dude[mainMap.getGridPlayer(x + i,y + j)].getTeam() == 1) {
					team1Guy = true;
				}
				if (dude[mainMap.getGridPlayer(x + i,y + j)].getTeam() == 2) {
					team2Guy = true;
				}
			}
		}
	}
	
	if (team1Guy && team2Guy) {
		return false;
	}
	else {
		return true;
	}
}

void usingSiegeWeaponBallista(int x, int y) {
	
		int heightSiegeWeapon, heightTarget, heightDifferenceSquared, distanceSquared, chanceToMiss;
		int sectionsAway;
		int target = 0, j = 0, i = 0, damage = 0;
		int flaming = 0;
		
		range = mainMap.getGridSiegeRange(x,y);
		if (dude[moveGuy].getEngineering() >= 1 && range > 2) {
			cout << dude[moveGuy].getName() << " checks the range " << skillAdverbs( dude[moveGuy].getEngineering() ) << endl;
			range = range + 5;
		}
		showMapRange();
		
		cout << "\nWho do you wish to attack?\n";
		
			//displays enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j);
						distanceSquared = (x-dude[j].getXpos())*(x-dude[j].getXpos()) + (y-dude[j].getYpos())*(y-dude[j].getYpos());
						heightSiegeWeapon = mainMap.getGridElevation(x,y);
						heightTarget = mainMap.getGridElevation(dude[target].getXpos(),dude[target].getYpos());
						heightDifferenceSquared = (heightTarget-heightSiegeWeapon) * (heightTarget-heightSiegeWeapon);
						if (heightSiegeWeapon > heightTarget) {//makes the height difference negative if you are higher (and smaller)
							heightDifferenceSquared = heightDifferenceSquared * -1/2;
						}
						//how many groups of 5 they are away, and adds 1 so that it can't be zero
						sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5;
					
						//the chance to miss times the multiples of 5 away that the enemy is
						chanceToMiss = sectionsAway * mainMap.getGridSiegeAccuracy(x,y);
						cout << " " << 100 - chanceToMiss - dude[j].getEvasion() << "%" << endl;
						
					}
				}
			}
			//displays enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() > 0) { //checks for enemies who aren't dead
						cout << j << ": " << epithet(j);
						distanceSquared = (x-dude[j].getXpos())*(x-dude[j].getXpos()) + (y-dude[j].getYpos())*(y-dude[j].getYpos());
						heightSiegeWeapon = mainMap.getGridElevation(x,y);
						heightTarget = mainMap.getGridElevation(dude[target].getXpos(),dude[target].getYpos());
						heightDifferenceSquared = (heightTarget-heightSiegeWeapon) * (heightTarget-heightSiegeWeapon);
						if (heightSiegeWeapon > heightTarget) {//makes the height difference negative if you are higher (and smaller)
							heightDifferenceSquared = heightDifferenceSquared * -1/2;
						}
						//how many groups of 5 they are away, and adds 1 so that it can't be zero
						sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5;
					
						//the chance to miss times the multiples of 5 away that the enemy is
						chanceToMiss = sectionsAway * mainMap.getGridSiegeAccuracy(x,y);
						cout << " " << 100 - chanceToMiss - dude[j].getEvasion() << "%" << endl;
						
						}
					}
				}
		cout << endl;
		cin >> target;
		cout << endl;
		if (target > 0) {
			if (dude[moveGuy].getEngineering() >= 5) {
				cout << "Do you wish to ignite the bolt?\n1:yes\n2:no\n";
				cin >> flaming;
			}
			heightSiegeWeapon = mainMap.getGridElevation(x,y);
			heightTarget = mainMap.getGridElevation(dude[target].getXpos(),dude[target].getYpos());
			heightDifferenceSquared = (heightTarget-heightSiegeWeapon) * (heightTarget-heightSiegeWeapon);
			if (heightSiegeWeapon > heightTarget) {//makes the height difference negative if you are higher (and smaller)
				heightDifferenceSquared = heightDifferenceSquared * -1/2;
			}
			distanceSquared = (x-dude[target].getXpos()) * (x-dude[target].getXpos()) + (y-dude[target].getYpos()) * (y-dude[target].getYpos());
			
			// checks range
			int range = mainMap.getGridSiegeRange(x,y);
			if (dude[moveGuy].getEngineering() >= 1 && range > 2) {
				cout << dude[moveGuy].getName() << " checks the range " << skillAdverbs(dude[moveGuy].getEngineering()) << endl;
				range = range + 5;
			}
			if (range * range >= (distanceSquared + heightDifferenceSquared) ) { 
				dude[moveGuy].setAp(dude[moveGuy].getAp() - 6);
				int missChance = 0;
				
				//checks accuracy
				//how many groups of 5 they are away, and adds 1 so that it can't be zero
				sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5;
			
				//the chance to miss times the multiples of 5 away that the enemy is
				chanceToMiss = sectionsAway * mainMap.getGridSiegeAccuracy(x,y);
				if (dude[moveGuy].getEngineering() >= 2) {
					cout << dude[moveGuy].getName() << " aims at the target " << skillAdverbs(dude[moveGuy].getEngineering()) << endl;
					chanceToMiss = chanceToMiss / 2;
				}
				
				if (rand() % 100 + 1 < 100 - chanceToMiss - dude[target].getEvasion()) {
				
				
					damage = mainMap.getGridSiegeAttack(x,y); 
					if (dude[moveGuy].getEngineering() >= 4) {//50% extra damage
						damage = damage * 6 / 4;
					}
					else if (dude[moveGuy].getEngineering() >= 2) {//25% extra damage
						damage = damage * 5 / 4;
					}
					dude[target].setHealth(dude[target].getHealth() - damage); //inflicts damage
					
					if (dude[moveGuy].getEngineering() >= 5 && flaming == 1) {//a master engineer, with flaming
						cout << dude[moveGuy].getName() << " masterfully operates the ballista launching a large flaming bolt that strikes " << dude[target].getName();
						cout << " doing " << damage << " damage\n\n";
						cout << "The flaming bolt lights " << dude[target].getName() << " on fire\n";
						burn[target] = burn[target] + 4;
					}
					else {
						cout << dude[moveGuy].getName() << " operates the ballista " << skillAdverbs(dude[moveGuy].getEngineering()) << ", launching a large bolt that strikes " << dude[target].getName();
						cout << " doing " << damage << " damage\n\n";
					}
						
					if (dude[target].getHealth() > 0){
						cout << endl << dude[target].getName() << " now has " << dude[target].getHealth() << " health\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
					}
					else {
						cout << endl << dude[target].getName() << " is killed by the giant bolt, and their impaled body drops to the ground\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //gives XP
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
					}
					
					
				}
				else {
					cout << "The bolt harmlessly misses " << dude[target].getName() << endl;
				}
				mainMap.setGridSiegeReloadCoolDown(x,y,  mainMap.getGridSiegeReloadTime(x,y) );//resets cooldown
			}
			else {
				cout << "\nThey are not in range\n";
			}
		}	
	
		
}

void usingSiegeWeapon(int x, int y) {//make it so some characters can do this better, either reloading or shooting
	int isLoading = 0;
	int isFiring = 0;
	int loadAmount = 0;
	if (mainMap.getGridSiegeReloadCoolDown(x,y) > 0) {
		cout << "The siege weapon is currently " << mainMap.getGridSiegeReloadTime(x,y) - mainMap.getGridSiegeReloadCoolDown(x,y) << "/" << mainMap.getGridSiegeReloadTime(x,y) << " loaded\n";
		cout << "Do you wish to work on loading it?\n1:Yes\n2:No\n";
		cin >> isLoading;
		if (isLoading == 1) {
			cout << "engineering level " << dude[moveGuy].getEngineering() << endl;
			cout << "loading\n";
			loadAmount = 10 + dude[moveGuy].getEngineering() * 5;
			cout << "passed loadAmount\n";
			mainMap.setGridSiegeReloadCoolDown(x,y,  mainMap.getGridSiegeReloadCoolDown(x,y) - loadAmount);//takes some off the cooldown time left
			cout << "passed the loading equation\n";
			dude[moveGuy].setAp(dude[moveGuy].getAp() - 6);
			cout << "passed the ap counter\n";
			cout << dude[moveGuy].getName() << endl;
			cout << dude[moveGuy].getName() << " loads the weapon " << skillAdverbs(dude[moveGuy].getEngineering()) << endl;
			cout << "The weapon is now " << mainMap.getGridSiegeReloadTime(x,y) - mainMap.getGridSiegeReloadCoolDown(x,y) << "/" << mainMap.getGridSiegeReloadTime(x,y) << " loaded\n";
		}
	}
	else {//it is fully reloaded
		cout << "This weapon is fully loaded, do you with to operate it?\n1:Yes\n2:No\n";
		cin >> isFiring;
		
		if (isFiring == 1) {
			if (mainMap.getGridSiegeWeaponType(x,y) == 1) {
				usingSiegeWeaponBallista(x,y);
			}
		}
		
		
	}
	
	
}


void checkForSiegeWeapon() {
	int useSiegeWeapon = 0;
	int x,y;
	
	
	for (x=-1;x<=1;x++) {//the for loops check everything within 1 space of moveGuy (and the space they are standing on)
		for (y=-1;y<=1;y++) {
			if (mainMap.getGridHasSiegeWeapon(dude[moveGuy].getXpos() + x,dude[moveGuy].getYpos()  + y) ) {
				if( uncontested(dude[moveGuy].getXpos() + x,dude[moveGuy].getYpos() + y ) || dude[moveGuy].getEngineering() >= 2 )  {//either uncontested or higher than level 2 engineer
					cout << "Do you wish to use the siege weapon on " << dude[moveGuy].getXpos() + x << "," << dude[moveGuy].getYpos() + y << "?\n1:Yes\n2:No\n";
					cin >> useSiegeWeapon;
					if (useSiegeWeapon  == 1) {
						if (dude[moveGuy].getAp() >= 6) {
							usingSiegeWeapon(dude[moveGuy].getXpos() + x,dude[moveGuy].getYpos() + y );
						}
						else {
							cout << "You do not have the Ap to do this\n";
						}
					}
				}
				else {
					cout << "The siege weapon on " << dude[moveGuy].getXpos() + x << "," << dude[moveGuy].getYpos() + y << " is contested\n";
				}
			}
		}
	}
	
}

void checkCrit() {
	if (dude[moveGuy].getPrestige() == 602){
		if (rd10() == 10) {
			cout << "\nThe assassin did some critical damage\n";
			damage=damage*2;
		}
		
		
	}
	
	return;
}

void checkNewPoison() {
	
	
	if (dude[moveGuy].getPrestige() == 602 || druidForm[moveGuy] == 4 || dude[moveGuy].getParagon() == 6031){
		
		if (dude[moveGuy].getTeam() == 2) {	
			poison[defender]= poison[defender] + 2; //makes the poison counter longer 
			if (dude[moveGuy].getParagon() == 6022) {//assassin of vitriol
				poison[defender]= poison[defender] + 1; //extra poison
			}
			if (dude[moveGuy].getParagon() == 6031) {//ranger of venom
				poison[defender]= poison[defender] - rd2(); //makes it just 1 or 2 poison
			}
		}
		if (dude[moveGuy].getTeam() == 1) {	
			poison[defender]= poison[defender] + 2; //makes the poison counter longer 
			if (dude[moveGuy].getParagon() == 6022) {//assassin of vitriol
				poison[defender]= poison[defender] + 1; //extra poison
			}
			if (dude[moveGuy].getParagon() == 6031) {//ranger of venom
				poison[defender]= poison[defender] - rd2(); //makes it just 1 or 2 poison
			}
		}
		
	}
	
	return;
}

void checkHold() {
	int i = 0;
	
				if (dude[moveGuy].getTeam() == 1) {//if in team 1, checks here
						for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) { //goes through all the people on the other team and checks if they are adjacent
							
							if (1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
							{ 
								if (dude[i].getParagon() == 102 && rd4() != 1) {
									//brawler of vice grip
									cout << endl << dude[moveGuy].getName() << " is unable to move because " << dude[i].getName() << "'s vice grip is holding them in place\n";
									hold[moveGuy] = 1;
								}
								else if (dude[i].getCharacterClass() == 1 && rd2() != 1) {
									cout << endl << dude[moveGuy].getName() << " is unable to move because " << dude[i].getName() << " is holding them in place\n";
									hold[moveGuy] = 1;
								}
								
								
							} 
							

						}
				}
				
					if (dude[moveGuy].getTeam() == 2) {//if in team 2, checks here
							for (i=1; i <= teamSize1; i++) { //goes through all the people on the team and checks if they are adjacent
								
								if (1 >= (dude[i].getXpos()-dude[moveGuy].getXpos())*(dude[i].getXpos()-dude[moveGuy].getXpos()) + (dude[i].getYpos()-dude[moveGuy].getYpos())*(dude[i].getYpos()-dude[moveGuy].getYpos()))
								{
									if (dude[i].getParagon() == 102 && rd4() != 1) {
										//brawler of vice grip
										cout << endl << dude[moveGuy].getName() << " is unable to move because " << dude[i].getName() << "'s vice grip is holding them in place\n";
										hold[moveGuy] = 1;
									}
									else if (dude[i].getCharacterClass() == 1 && rd2() != 1) {
										cout << endl << dude[moveGuy].getName() << " is unable to move because " << dude[i].getName() << " is holding them in place\n";
										hold[moveGuy] = 1;
									}
									
								} 
		
							}
					}
	
}

void inquireSquare() {
	int x,y;
	int keepGoing = 1;
	
	showMap();
	
	cout << "What square do you want to look at closer?\n";
	cin >> x;
	cin >> y;
	mainMap.printGrid(x,y);
	cout << "\nDo you want to keep checking squares?\n1:Yes\n0:No\n";
	cin >> keepGoing;
	if (keepGoing == 1) {
		inquireSquare();
	}
	
}

//this'll make people move
void move() {
	int newXpos = 0, newYpos = 0, deltax = 0, deltay = 0;
	int moveNumber = dude[moveGuy].getMove();
	moving = 1;
	
	if (druidForm[moveGuy] == 2) {
		moveNumber = moveNumber * 2;
	}
	else if (druidForm[moveGuy] == 3) {
		moveNumber = moveNumber * 3;
	}
	else if (druidForm[moveGuy] == 4) {
		moveNumber = moveNumber * 2;
	}
	
	checkHold();
	
	if (moved[moveGuy] == 1 && spellCast[moveGuy] == 1) {cout << "You are too drained to move\n\n";}
	
	else if (hold[moveGuy] != 1) {
		
		if (moved[moveGuy] == 1 && dude[moveGuy].getParagon() == 4011) {//battlerager of aerobics, 50% speed boost on second move
			moveNumber = moveNumber * 3 / 2;
		}
		
		if (haste[moveGuy] > 0) { //if they have the haste buff, they move an 50% faster
			moveNumber = moveNumber * 3 / 2;
		}
		
		if (haste[moveGuy] < 0) { //if they have the slow debuff, they move half speed
			moveNumber = moveNumber / 2;
		}
		
		if (dude[moveGuy].getRenown() == 402 && firstTurn[moveGuy]) {
			moveNumber = moveNumber * 3 / 2;
			cout << epithet(moveGuy) << "'s rage helps them move even faster\n";
		}
		
		range = moveNumber;//sets range for the map to use
		
		showMapRange(); //displays the map
		
		if (haste[moveGuy] > 0) { //if they have the haste buff, they move an 50% faster
			cout << dude[moveGuy].getName() << "'s legs are glowing and they can move very fast\n\n";
		}
		
		if (haste[moveGuy] < 0) { //if they have the slow debuff, they move half speed
			cout << dude[moveGuy].getName() << "'s legs are glowing and they are slowed\n\n";
		}
		
		cout << epithet(moveGuy) << " is on (" << dude[moveGuy].getXpos() << "," << dude[moveGuy].getYpos() << ")\n";
		cout << "How should they move?\n";
		cin >> deltax;
		
		
		if(deltax == 33) {showMap(); move();}
		else if(deltax == 34) {showMapValuesMenu(); move();}
		else if(deltax == 35) {inquireSquare(); move();}
		
				
		cout << endl;
		cin >> deltay;
		cout << endl;
		
		newXpos = 0, newYpos = 0;
		
		newXpos = dude[moveGuy].getXpos() + deltax;
		newYpos = dude[moveGuy].getYpos() + deltay;
				
				
		if (newXpos < 0 || newYpos < 0 || newXpos > 25 || newYpos > 50) { //checks that the target spot is on the map
		cout << "\nA true warrior will not flee the battlefield\n";
		}
		else if (deltax == 0 && deltay == 0) {
			cout << epithet(moveGuy) << " stays still\n";
		}
		else {
			
			//checks if they are a knight who is charging
			if((dude[moveGuy].getCharacterClass() == 5) && (deltax >= 5 || deltay >= 5 || deltax <= -5 || deltay <= -5)) {
				charge[moveGuy] = 1;
			}
			//if lancer of expeditedness
			if((dude[moveGuy].getParagon() == 5012) && (deltax >= 4 || deltay >= 4 || deltax <= -4 || deltay <= -4)) {
				charge[moveGuy] = 1;
			}
			//checks if they are a brawler who is bullrushing
			if((dude[moveGuy].getParagon() == 1011) && (deltax >= 5 || deltay >=5 || deltax <= -5 || deltay <= -5)) {
				bullrush[moveGuy] = 1;
			}
			
			//the next line squares the differense in elevation
			int elevationChangeSquared = (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) ) * (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) );
			//this line makes it negative if it should be, and makes it less of an impact
			if (mainMap.getGridElevation(newXpos,newYpos) - mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos())  < 0) {
					elevationChangeSquared = elevationChangeSquared * -1/2;
			}
				
			//if they are an archer with the nimble attribute
			if (elevationChangeSquared > 0 && dude[moveGuy].getRenown() == 202) {
				elevationChangeSquared = 0;
			}
			
			//finds distance in the x and y directions
			int deltaxsquared=(dude[moveGuy].getXpos()-newXpos)*(dude[moveGuy].getXpos()-newXpos);
			int deltaysquared=(dude[moveGuy].getYpos()-newYpos)*(dude[moveGuy].getYpos()-newYpos);
			
			if (mainMap.getGridPassable(newXpos,newYpos) && moveNumber * moveNumber >= deltaxsquared + deltaysquared + elevationChangeSquared) {//if it is in their move rate
			
				mainMap.setGridPlayer(newXpos,newYpos,moveGuy); //draws the person number on the map
				mainMap.setGridPlayer(dude[moveGuy].getXpos(),dude[moveGuy].getYpos(),0);//deletes old class initial
						
				showMap();
						
    
				checkDisengage();//checks if they are fleeing someone
				cout << epithet(moveGuy) << " moves to (" << newXpos << "," << newYpos << ")\n\n";
				
				
				dude[moveGuy].setXpos(newXpos);
				dude[moveGuy].setYpos(newYpos); //saves the new location for the player
				dude[moveGuy].setAp(dude[moveGuy].getAp() - 6); //lowers Ap 
				moved[moveGuy] = 1; //says that the guy moved
						
				if (dude[moveGuy].getTeam() == 1) {
					if (army1[0]) {
						if (mainMap.getGridGold(newXpos,newYpos) > 0) {
							cout << dude[moveGuy].getName() << " picks up " << mainMap.getGridGold(newXpos,newYpos) << " gold\n";
							armyGainMoney(1,mainMap.getGridGold(newXpos,newYpos));
							mainMap.setGridGold(newXpos,newYpos,0);
						}
					}
				}
				if (dude[moveGuy].getTeam() == 2) {
					if (army2[0]) {
						if (mainMap.getGridGold(newXpos,newYpos) > 0) {
							cout << dude[moveGuy].getName() << " picks up " << mainMap.getGridGold(newXpos,newYpos) << " gold\n";
							armyGainMoney(2,mainMap.getGridGold(newXpos,newYpos));
							mainMap.setGridGold(newXpos,newYpos,0);
						}
					}
				}
				
				
				
			}		
			else {//can't move there
				cout << "\nYou can't move there\n\n";
				move();
			}
		}
	}
	moving = 0;	
	
}

//puts the people on the map 
void placement() {
	int x = 0;
	for ( x = 1; x <= teamSize1; x++) {
		mainMap.setGridPlayer(1,x+24,x);//marks them on the map
		
		dude[x].setXpos(1); //writes map position onto the character's memory
		dude[x].setYpos(x + 24);
	}
	for ( x = teamSize1 + 1; x <= teamSize2 + teamSize1; x++) {
		mainMap.setGridPlayer(24,x+24,x);//marks them on the map
		
		dude[x].setXpos(24); //writes map position onto the character's memory
		dude[x].setYpos(x + 24);
	}
	return;
}

//This is what fills out the beginning character sheets
void fillStats() {
int x=0;
int l=0;

for (l=1; l <= teamSize1 + teamSize2; l++){

	switch(dude[l].getCharacterClass() ) //class stats filling
	{
		case 1:
		//goherenownow
			
			dude[l].setCharacterClass(fighter[0][0]);
			dude[l].setAttack(fighter[0][1]);
			dude[l].setDefense(fighter[0][2]);
			dude[l].setHealth(fighter[0][3]);
			dude[l].setMove(fighter[0][4]);
			dude[l].setRange(fighter[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(fighter[0][7]);
			dude[l].setXp(fighter[0][11]);
			dude[l].setMaxHealth(fighter[0][12]);
			dude[l].setMaxMana(fighter[0][13]);
			dude[l].setManaRegen(fighter[0][14]);
			dude[l].setLevel(fighter[0][15]);
			dude[l].setPrestige(fighter[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(fighter[0][19]);
			dude[l].setParagon(fighter[0][20]);
			dude[l].setStartingMana(fighter[0][21]);
			dude[l].setMissChance(fighter[0][22]);
			dude[l].setEvasion(fighter[0][23]);
			dude[l].setEngineering(fighter[0][24]);
			
			
		break;
		case 2:
			dude[l].setCharacterClass(archer[0][0]);
			dude[l].setAttack(archer[0][1]);
			dude[l].setDefense(archer[0][2]);
			dude[l].setHealth(archer[0][3]);
			dude[l].setMove(archer[0][4]);
			dude[l].setRange(archer[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(archer[0][7]);
			dude[l].setXp(archer[0][11]);
			dude[l].setMaxHealth(archer[0][12]);
			dude[l].setMaxMana(archer[0][13]);
			dude[l].setManaRegen(archer[0][14]);
			dude[l].setLevel(archer[0][15]);
			dude[l].setPrestige(archer[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(archer[0][19]);
			dude[l].setParagon(archer[0][20]);
			dude[l].setStartingMana(archer[0][21]);
			dude[l].setMissChance(archer[0][22]);
			dude[l].setEvasion(archer[0][23]);
			dude[l].setEngineering(archer[0][24]);

		break;
		case 3:
			dude[l].setCharacterClass(priest[0][0]);
			dude[l].setAttack(priest[0][1]);
			dude[l].setDefense(priest[0][2]);
			dude[l].setHealth(priest[0][3]);
			dude[l].setMove(priest[0][4]);
			dude[l].setRange(priest[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(priest[0][7]);
			dude[l].setXp(priest[0][11]);
			dude[l].setMaxHealth(priest[0][12]);
			dude[l].setMaxMana(priest[0][13]);
			dude[l].setManaRegen(priest[0][14]);
			dude[l].setLevel(priest[0][15]);
			dude[l].setPrestige(priest[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(priest[0][19]);
			dude[l].setParagon(priest[0][20]);
			dude[l].setStartingMana(priest[0][21]);
			dude[l].setMissChance(priest[0][22]);
			dude[l].setEvasion(priest[0][23]);
			dude[l].setEngineering(priest[0][24]);

		break;
		case 4:
			dude[l].setCharacterClass(berserker[0][0]);
			dude[l].setAttack(berserker[0][1]);
			dude[l].setDefense(berserker[0][2]);
			dude[l].setHealth(berserker[0][3]);
			dude[l].setMove(berserker[0][4]);
			dude[l].setRange(berserker[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(berserker[0][7]);
			dude[l].setXp(berserker[0][11]);
			dude[l].setMaxHealth(berserker[0][12]);
			dude[l].setMaxMana(berserker[0][13]);
			dude[l].setManaRegen(berserker[0][14]);
			dude[l].setLevel(berserker[0][15]);
			dude[l].setPrestige(berserker[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(berserker[0][19]);
			dude[l].setParagon(berserker[0][20]);
			dude[l].setStartingMana(berserker[0][21]);
			dude[l].setMissChance(berserker[0][22]);
			dude[l].setEvasion(berserker[0][23]);
			dude[l].setEngineering(berserker[0][24]);

		break;
		case 5:
			dude[l].setCharacterClass(knight[0][0]);
			dude[l].setAttack(knight[0][1]);
			dude[l].setDefense(knight[0][2]);
			dude[l].setHealth(knight[0][3]);
			dude[l].setMove(knight[0][4]);
			dude[l].setRange(knight[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(knight[0][7]);
			dude[l].setXp(knight[0][11]);
			dude[l].setMaxHealth(knight[0][12]);
			dude[l].setMaxMana(knight[0][13]);
			dude[l].setManaRegen(knight[0][14]);
			dude[l].setLevel(knight[0][15]);
			dude[l].setPrestige(knight[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(knight[0][19]);
			dude[l].setParagon(knight[0][20]);
			dude[l].setStartingMana(knight[0][21]);
			dude[l].setMissChance(knight[0][22]);
			dude[l].setEvasion(knight[0][23]);
			dude[l].setEngineering(knight[0][24]);

		break;
		case 6:
			dude[l].setCharacterClass(scout[0][0]);
			dude[l].setAttack(scout[0][1]);
			dude[l].setDefense(scout[0][2]);
			dude[l].setHealth(scout[0][3]);
			dude[l].setMove(scout[0][4]);
			dude[l].setRange(scout[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(scout[0][7]);
			dude[l].setXp(scout[0][11]);
			dude[l].setMaxHealth(scout[0][12]);
			dude[l].setMaxMana(scout[0][13]);
			dude[l].setManaRegen(scout[0][14]);
			dude[l].setLevel(scout[0][15]);
			dude[l].setPrestige(scout[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(scout[0][19]);
			dude[l].setParagon(scout[0][20]);
			dude[l].setStartingMana(scout[0][21]);
			dude[l].setMissChance(scout[0][22]);
			dude[l].setEvasion(scout[0][23]);
			dude[l].setEngineering(scout[0][24]);

		break;
		case 7:
			dude[l].setCharacterClass(mage[0][0]);
			dude[l].setAttack(mage[0][1]);
			dude[l].setDefense(mage[0][2]);
			dude[l].setHealth(mage[0][3]);
			dude[l].setMove(mage[0][4]);
			dude[l].setRange(mage[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(mage[0][7]);
			dude[l].setXp(mage[0][11]);
			dude[l].setMaxHealth(mage[0][12]);
			dude[l].setMaxMana(mage[0][13]);
			dude[l].setManaRegen(mage[0][14]);
			dude[l].setLevel(mage[0][15]);
			dude[l].setPrestige(mage[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(mage[0][19]);
			dude[l].setParagon(mage[0][20]);
			dude[l].setStartingMana(mage[0][21]);
			dude[l].setMissChance(mage[0][22]);
			dude[l].setEvasion(mage[0][23]);
			dude[l].setEngineering(mage[0][24]);

		break;
		case 8:
			dude[l].setCharacterClass(warlock[0][0]);
			dude[l].setAttack(warlock[0][1]);
			dude[l].setDefense(warlock[0][2]);
			dude[l].setHealth(warlock[0][3]);
			dude[l].setMove(warlock[0][4]);
			dude[l].setRange(warlock[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(warlock[0][7]);
			dude[l].setXp(warlock[0][11]);
			dude[l].setMaxHealth(warlock[0][12]);
			dude[l].setMaxMana(warlock[0][13]);
			dude[l].setManaRegen(warlock[0][14]);
			dude[l].setLevel(warlock[0][15]);
			dude[l].setPrestige(warlock[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(warlock[0][19]);
			dude[l].setParagon(warlock[0][20]);
			dude[l].setStartingMana(warlock[0][21]);
			dude[l].setMissChance(warlock[0][22]);
			dude[l].setEvasion(warlock[0][23]);
			dude[l].setEngineering(warlock[0][24]);

		break;
		case 101:
			dude[l].setCharacterClass(wolf[0][0]);
			dude[l].setAttack(wolf[0][1]);
			dude[l].setDefense(wolf[0][2]);
			dude[l].setHealth(wolf[0][3]);
			dude[l].setMove(wolf[0][4]);
			dude[l].setRange(wolf[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(wolf[0][7]);
			dude[l].setXp(wolf[0][11]);
			dude[l].setMaxHealth(wolf[0][12]);
			dude[l].setMaxMana(wolf[0][13]);
			dude[l].setManaRegen(wolf[0][14]);
			dude[l].setLevel(wolf[0][15]);
			dude[l].setPrestige(wolf[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(wolf[0][19]);
			dude[l].setParagon(wolf[0][20]);
			dude[l].setStartingMana(wolf[0][21]);
			dude[l].setMissChance(wolf[0][22]);
			dude[l].setEvasion(wolf[0][23]);

		break;
		case 102:
			dude[l].setCharacterClass(bear[0][0]);
			dude[l].setAttack(bear[0][1]);
			dude[l].setDefense(bear[0][2]);
			dude[l].setHealth(bear[0][3]);
			dude[l].setMove(bear[0][4]);
			dude[l].setRange(bear[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(bear[0][7]);
			dude[l].setXp(bear[0][11]);
			dude[l].setMaxHealth(bear[0][12]);
			dude[l].setMaxMana(bear[0][13]);
			dude[l].setManaRegen(bear[0][14]);
			dude[l].setLevel(bear[0][15]);
			dude[l].setPrestige(bear[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(bear[0][19]);
			dude[l].setParagon(bear[0][20]);
			dude[l].setStartingMana(bear[0][21]);
			dude[l].setMissChance(bear[0][22]);
			dude[l].setEvasion(bear[0][23]);

		break;
		case 103:
			dude[l].setCharacterClass(goblinFighter[0][0]);
			dude[l].setAttack(goblinFighter[0][1]);
			dude[l].setDefense(goblinFighter[0][2]);
			dude[l].setHealth(goblinFighter[0][3]);
			dude[l].setMove(goblinFighter[0][4]);
			dude[l].setRange(goblinFighter[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(goblinFighter[0][7]);
			dude[l].setXp(goblinFighter[0][11]);
			dude[l].setMaxHealth(goblinFighter[0][12]);
			dude[l].setMaxMana(goblinFighter[0][13]);
			dude[l].setManaRegen(goblinFighter[0][14]);
			dude[l].setLevel(goblinFighter[0][15]);
			dude[l].setPrestige(goblinFighter[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(goblinFighter[0][19]);
			dude[l].setParagon(goblinFighter[0][20]);
			dude[l].setStartingMana(goblinFighter[0][21]);
			dude[l].setMissChance(goblinFighter[0][22]);
			dude[l].setEvasion(goblinFighter[0][23]);

		break;
		case 104:
			dude[l].setCharacterClass(goblinArcher[0][0]);
			dude[l].setAttack(goblinArcher[0][1]);
			dude[l].setDefense(goblinArcher[0][2]);
			dude[l].setHealth(goblinArcher[0][3]);
			dude[l].setMove(goblinArcher[0][4]);
			dude[l].setRange(goblinArcher[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(goblinArcher[0][7]);
			dude[l].setXp(goblinArcher[0][11]);
			dude[l].setMaxHealth(goblinArcher[0][12]);
			dude[l].setMaxMana(goblinArcher[0][13]);
			dude[l].setManaRegen(goblinArcher[0][14]);
			dude[l].setLevel(goblinArcher[0][15]);
			dude[l].setPrestige(goblinArcher[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(goblinArcher[0][19]);
			dude[l].setParagon(goblinArcher[0][20]);
			dude[l].setStartingMana(goblinArcher[0][21]);
			dude[l].setMissChance(goblinArcher[0][22]);
			dude[l].setEvasion(goblinArcher[0][23]);

		break;
		case 105:
			dude[l].setCharacterClass(stoneGolem[0][0]);
			dude[l].setAttack(stoneGolem[0][1]);
			dude[l].setDefense(stoneGolem[0][2]);
			dude[l].setHealth(stoneGolem[0][3]);
			dude[l].setMove(stoneGolem[0][4]);
			dude[l].setRange(stoneGolem[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(stoneGolem[0][7]);
			dude[l].setXp(stoneGolem[0][11]);
			dude[l].setMaxHealth(stoneGolem[0][12]);
			dude[l].setMaxMana(stoneGolem[0][13]);
			dude[l].setManaRegen(stoneGolem[0][14]);
			dude[l].setLevel(stoneGolem[0][15]);
			dude[l].setPrestige(stoneGolem[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(stoneGolem[0][19]);
			dude[l].setParagon(stoneGolem[0][20]);
			dude[l].setStartingMana(stoneGolem[0][21]);
			dude[l].setMissChance(stoneGolem[0][22]);
			dude[l].setEvasion(stoneGolem[0][23]);

		break;
		case 106:
			dude[l].setCharacterClass(ironGolem[0][0]);
			dude[l].setAttack(ironGolem[0][1]);
			dude[l].setDefense(ironGolem[0][2]);
			dude[l].setHealth(ironGolem[0][3]);
			dude[l].setMove(ironGolem[0][4]);
			dude[l].setRange(ironGolem[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(ironGolem[0][7]);
			dude[l].setXp(ironGolem[0][11]);
			dude[l].setMaxHealth(ironGolem[0][12]);
			dude[l].setMaxMana(ironGolem[0][13]);
			dude[l].setManaRegen(ironGolem[0][14]);
			dude[l].setLevel(ironGolem[0][15]);
			dude[l].setPrestige(ironGolem[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(ironGolem[0][19]);
			dude[l].setParagon(ironGolem[0][20]);
			dude[l].setStartingMana(ironGolem[0][21]);
			dude[l].setMissChance(ironGolem[0][22]);
			dude[l].setEvasion(ironGolem[0][23]);

		break;
		case 107:
			dude[l].setCharacterClass(goblinMage[0][0]);
			dude[l].setAttack(goblinMage[0][1]);
			dude[l].setDefense(goblinMage[0][2]);
			dude[l].setHealth(goblinMage[0][3]);
			dude[l].setMove(goblinMage[0][4]);
			dude[l].setRange(goblinMage[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(goblinMage[0][7]);
			dude[l].setXp(goblinMage[0][11]);
			dude[l].setMaxHealth(goblinMage[0][12]);
			dude[l].setMaxMana(goblinMage[0][13]);
			dude[l].setManaRegen(goblinMage[0][14]);
			dude[l].setLevel(goblinMage[0][15]);
			dude[l].setPrestige(goblinMage[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(goblinMage[0][19]);
			dude[l].setParagon(goblinMage[0][20]);
			dude[l].setStartingMana(goblinMage[0][21]);
			dude[l].setMissChance(goblinMage[0][22]);
			dude[l].setEvasion(goblinMage[0][23]);

		break;
		case 108:
			dude[l].setCharacterClass(goblinPriest[0][0]);
			dude[l].setAttack(goblinPriest[0][1]);
			dude[l].setDefense(goblinPriest[0][2]);
			dude[l].setHealth(goblinPriest[0][3]);
			dude[l].setMove(goblinPriest[0][4]);
			dude[l].setRange(goblinPriest[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(goblinPriest[0][7]);
			dude[l].setXp(goblinPriest[0][11]);
			dude[l].setMaxHealth(goblinPriest[0][12]);
			dude[l].setMaxMana(goblinPriest[0][13]);
			dude[l].setManaRegen(goblinPriest[0][14]);
			dude[l].setLevel(goblinPriest[0][15]);
			dude[l].setPrestige(goblinPriest[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(goblinPriest[0][19]);
			dude[l].setParagon(goblinPriest[0][20]);
			dude[l].setStartingMana(goblinPriest[0][21]);
			dude[l].setMissChance(goblinPriest[0][22]);
			dude[l].setEvasion(goblinPriest[0][23]);

		break;
		case 109:
			dude[l].setCharacterClass(giantRat[0][0]);
			dude[l].setAttack(giantRat[0][1]);
			dude[l].setDefense(giantRat[0][2]);
			dude[l].setHealth(giantRat[0][3]);
			dude[l].setMove(giantRat[0][4]);
			dude[l].setRange(giantRat[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(giantRat[0][7]);
			dude[l].setXp(giantRat[0][11]);
			dude[l].setMaxHealth(giantRat[0][12]);
			dude[l].setMaxMana(giantRat[0][13]);
			dude[l].setManaRegen(giantRat[0][14]);
			dude[l].setLevel(giantRat[0][15]);
			dude[l].setPrestige(giantRat[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(giantRat[0][19]);
			dude[l].setParagon(giantRat[0][20]);
			dude[l].setStartingMana(giantRat[0][21]);
			dude[l].setMissChance(giantRat[0][22]);
			dude[l].setEvasion(giantRat[0][23]);

		break;
		case 110:
			dude[l].setCharacterClass(giantBeetle[0][0]);
			dude[l].setAttack(giantBeetle[0][1]);
			dude[l].setDefense(giantBeetle[0][2]);
			dude[l].setHealth(giantBeetle[0][3]);
			dude[l].setMove(giantBeetle[0][4]);
			dude[l].setRange(giantBeetle[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(giantBeetle[0][7]);
			dude[l].setXp(giantBeetle[0][11]);
			dude[l].setMaxHealth(giantBeetle[0][12]);
			dude[l].setMaxMana(giantBeetle[0][13]);
			dude[l].setManaRegen(giantBeetle[0][14]);
			dude[l].setLevel(giantBeetle[0][15]);
			dude[l].setPrestige(giantBeetle[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(giantBeetle[0][19]);
			dude[l].setParagon(giantBeetle[0][20]);
			dude[l].setStartingMana(giantBeetle[0][21]);
			dude[l].setMissChance(giantBeetle[0][22]);
			dude[l].setEvasion(giantBeetle[0][23]);

		break;
		case 111:
			dude[l].setCharacterClass(giantAnt[0][0]);
			dude[l].setAttack(giantAnt[0][1]);
			dude[l].setDefense(giantAnt[0][2]);
			dude[l].setHealth(giantAnt[0][3]);
			dude[l].setMove(giantAnt[0][4]);
			dude[l].setRange(giantAnt[0][5]);
			dude[l].setAp(12);
			dude[l].setMana(giantAnt[0][7]);
			dude[l].setXp(giantAnt[0][11]);
			dude[l].setMaxHealth(giantAnt[0][12]);
			dude[l].setMaxMana(giantAnt[0][13]);
			dude[l].setManaRegen(giantAnt[0][14]);
			dude[l].setLevel(giantAnt[0][15]);
			dude[l].setPrestige(giantAnt[0][16]);//skip 17 and 18 because they are race and birthright
			dude[l].setRenown(giantAnt[0][19]);
			dude[l].setParagon(giantAnt[0][20]);
			dude[l].setStartingMana(giantAnt[0][21]);
			dude[l].setMissChance(giantAnt[0][22]);
			dude[l].setEvasion(giantAnt[0][23]);

		break;
	}
	

	
	switch(dude[l].getRace()) {//gives race bonuses
		case 1:
			switch(rd4()) {
				case 1:
					dude[l].setAttack(dude[l].getAttack() + 2);//attack
				break;
				case 2:
					dude[l].setDefense(dude[l].getDefense() + 1);//defense
					dude[l].setMove(dude[l].getMove() + 1);//move
				break;
				case 3:
					dude[l].setHealth(dude[l].getHealth() + 5);//health
					dude[l].setMaxHealth(dude[l].getMaxHealth() + 5);//max health
					dude[l].setMove(dude[l].getMove() + 1);//move
				break;
				case 4:
					dude[l].setHealth(dude[l].getHealth() + 5);//health
					dude[l].setMaxHealth(dude[l].getMaxHealth() + 5);//max health
					dude[l].setAttack(dude[l].getAttack() + 1);//attack
					dude[l].setDefense(dude[l].getDefense() + 1);//defense
					dude[l].setMove(dude[l].getMove() + 1);//move
				break;
			}
		break;
		case 2:
			dude[l].setAttack(dude[l].getAttack() + 1);//attack
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			if (dude[l].getRange() > 2) {
				dude[l].setRange(dude[l].getRange() + 5);//range	
				
			}
			dude[l].setMove(dude[l].getMove() + 1);//move
		break;
		case 3:
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			dude[l].setHealth(dude[l].getHealth() - 5);//health
			dude[l].setMaxHealth(dude[l].getMaxHealth() - 5);//max health
			if (dude[l].getMaxMana() > 0) { 
				dude[l].setManaRegen(dude[l].getManaRegen() + 2);//mana regen
				dude[l].setMaxMana(dude[l].getMaxMana() + 5);//max mana 
				dude[l].setMana(dude[l].getMana() + 5);//mana
			}
		break;
		case 4:
			dude[l].setAttack(dude[l].getAttack() + 3);//attack
			dude[l].setDefense(dude[l].getDefense() - 2);//defense
			dude[l].setMove(dude[l].getMove() + 2);//move
		break;
		case 5:
			dude[l].setAttack(dude[l].getAttack() + 1);//attack
			dude[l].setDefense(dude[l].getDefense() + 1);//defense
			dude[l].setMove(dude[l].getMove() - 1);//move
			dude[l].setEngineering(dude[l].getEngineering() + 1);
		break;
		case 6:
			dude[l].setAttack(dude[l].getAttack() + 1);//attack
			dude[l].setDefense(dude[l].getDefense() + 2);//defense
			dude[l].setMove(dude[l].getMove() - 1);//move
			dude[l].setHealth(dude[l].getHealth() - 5);//health
			dude[l].setMaxHealth(dude[l].getMaxHealth() - 5);//max health
			dude[l].setEngineering(dude[l].getEngineering() + 1);
		break;
		case 7:
			dude[l].setAttack(dude[l].getAttack() - 2);//attack
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			dude[l].setMove(dude[l].getMove() + 2);//move
		break;
		case 8:
			dude[l].setAttack(dude[l].getAttack() + 2);//attack
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			dude[l].setHealth(dude[l].getHealth() + 5);//health
			dude[l].setMaxHealth(dude[l].getMaxHealth() + 5);//max health
		break;
		case 9:
			dude[l].setAttack(dude[l].getAttack() + 1);//attack
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			dude[l].setMove(dude[l].getMove() + 3);//move
		break;

	}


	switch(dude[l].getBirthRight()) //birthright additions
	{
		case 101://dragonspawn fire
			dude[l].setAttack(dude[l].getAttack() + 1);//attack
		break;
		case 102://dragonspawn ice
			dude[l].setDefense(dude[l].getDefense() + 1);//defense
		break;
		case 103://dragonspawn poison
			dude[l].setMaxHealth(dude[l].getMaxHealth() + 5);//max health
			dude[l].setHealth(dude[l].getHealth() + 5);//health
		break;
		case 104://dragonspawn lightning
			dude[l].setMove(dude[l].getMove() + 2);//speed
		break;
		case 2://also can drain bodies, weak to smite
			dude[l].setAttack(dude[l].getAttack() + 2);//attack
			dude[l].setDefense(dude[l].getDefense() + 1);//defense
			dude[l].setHealth(dude[l].getHealth() - 5);//health
			dude[l].setMaxHealth(dude[l].getMaxHealth() - 5);//max health
		break;
		case 3:
			dude[l].setMove(dude[l].getMove() + 3);//move
			dude[l].setAttack(dude[l].getAttack() + 2);//attack
			dude[l].setDefense(dude[l].getDefense() - 1);//defense
			if (dude[l].getMaxMana() > 0) { 
				dude[l].setManaRegen(dude[l].getManaRegen() - 1);//mana regen
				dude[l].setMaxMana(dude[l].getMaxMana() - 5);//max mana 
			}
		break;
		case 4://resist magic
			if (dude[l].getMaxMana() > 0) {
				dude[l].setManaRegen(dude[l].getManaRegen() + 2);//mana regen
				dude[l].setMaxMana(dude[l].getMaxMana() + 10);//max mana 
				dude[l].setMana(dude[l].getMana() + 5);//mana 
			}
			else {
				dude[l].setAttack(dude[l].getAttack() + 2);//attack
				dude[l].setDefense(dude[l].getDefense() + 1);//defense
			}
			dude[l].setDefense(dude[l].getDefense() - 2);//defense
		break;
		case 5: //rerolls
			dude[l].setDefense(dude[l].getDefense() + 1);//defense
			dude[l].setHealth(dude[l].getHealth() + 5);//health
			dude[l].setMaxHealth(dude[l].getMaxHealth() + 5);//max health
		break;

	}


}

return;
}

//this is for skipping up a few levels
void jumpingUp(int jumper, int finalLevel) {
	int xpNeeded = 0;
	for (int i = dude[jumper].getLevel(); i < finalLevel; i++) {
		xpNeeded = xpNeeded + 50 + (i * 30);
	}
	dude[jumper].setXp(xpNeeded);
	
}

void familiar() {//going to need to make it add 1 to all of team 2 or something
	int increaseTeamSize = 0;
	
	for (assignGuy=1; assignGuy <= teamSize1; assignGuy++) {
		
		if (dude[assignGuy].getRenown() == 802) {
			
			names[teamSize1+increaseTeamSize] = names[assignGuy] + "'s familiar";
			playerInfo[teamSize1+increaseTeamSize][0] = 101;
			playerInfo[teamSize1+increaseTeamSize][1] = playerInfo[assignGuy][1];//same attack
			playerInfo[teamSize1+increaseTeamSize][2] = playerInfo[assignGuy][2]/3;//lower defense
			playerInfo[teamSize1+increaseTeamSize][3] = playerInfo[assignGuy][3]/3;// 1/3 health
			playerInfo[teamSize1+increaseTeamSize][4] = playerInfo[assignGuy][4]*3/2;//higher move
			playerInfo[teamSize1+increaseTeamSize][5] = 1;//range 1
			playerInfo[teamSize1+increaseTeamSize][6] = 12;//full ap
			playerInfo[teamSize1+increaseTeamSize][7] = 0;//mana
			playerInfo[teamSize1+increaseTeamSize][8] = teamSize1+increaseTeamSize;
			playerInfo[teamSize1+increaseTeamSize][9] = 0;//x coord
			playerInfo[teamSize1+increaseTeamSize][10] = 0;//y coord
			playerInfo[teamSize1+increaseTeamSize][11] = 0;//xp
			playerInfo[teamSize1+increaseTeamSize][12] = playerInfo[assignGuy][12]/3;// 1/3 health
			playerInfo[teamSize1+increaseTeamSize][13] = 0;//max mana
			playerInfo[teamSize1+increaseTeamSize][14] = 0;//mana regen
			playerInfo[teamSize1+increaseTeamSize][15] = 0;//level
			playerInfo[teamSize1+increaseTeamSize][16] = 0;//prestige
			playerInfo[teamSize1+increaseTeamSize][17] = 101;//race
			playerInfo[teamSize1+increaseTeamSize][18] = 0;//birthright
			playerInfo[teamSize1+increaseTeamSize][19] = 80200+assignGuy;//renown (being used to show which person they belong to)
			increaseTeamSize++;//says the team is bigger
		}
	}
	teamSize1 = teamSize1 + increaseTeamSize;
	
	increaseTeamSize = 0;
	
	for (assignGuy= teamSize1 + 1; assignGuy <= teamSize2 + teamSize1; assignGuy++) {
		if (dude[assignGuy].getRenown() == 802) {
			names[teamSize2+increaseTeamSize] = names[assignGuy] + "'s familiar";
			playerInfo[teamSize2+increaseTeamSize][0] = 101;
			playerInfo[teamSize2+increaseTeamSize][1] = playerInfo[assignGuy][1];//same attack
			playerInfo[teamSize2+increaseTeamSize][2] = playerInfo[assignGuy][2]/3;//lower defense
			playerInfo[teamSize2+increaseTeamSize][3] = playerInfo[assignGuy][3]/2;// 1/2 health
			playerInfo[teamSize2+increaseTeamSize][4] = playerInfo[assignGuy][4]*3/2;//higher move
			playerInfo[teamSize2+increaseTeamSize][5] = 1;//range 1
			playerInfo[teamSize2+increaseTeamSize][6] = 12;//full ap
			playerInfo[teamSize2+increaseTeamSize][7] = 0;//mana
			playerInfo[teamSize2+increaseTeamSize][8] = teamSize2+increaseTeamSize;
			playerInfo[teamSize2+increaseTeamSize][9] = 0;//x coord
			playerInfo[teamSize2+increaseTeamSize][10] = 0;//y coord
			playerInfo[teamSize2+increaseTeamSize][11] = 0;//xp
			playerInfo[teamSize2+increaseTeamSize][12] = playerInfo[assignGuy][12]/3;// 1/3 health
			playerInfo[teamSize2+increaseTeamSize][13] = 0;//max mana
			playerInfo[teamSize2+increaseTeamSize][14] = 0;//mana regen
			playerInfo[teamSize2+increaseTeamSize][15] = 0;//level
			playerInfo[teamSize2+increaseTeamSize][16] = 0;//prestige
			playerInfo[teamSize2+increaseTeamSize][17] = 101;//race
			playerInfo[teamSize2+increaseTeamSize][18] = 0;//birthright
			playerInfo[teamSize2+increaseTeamSize][19] = 80200+assignGuy;//renown (being used to show which person they belong to)
			increaseTeamSize++;//says the team is bigger
		}
	}
	teamSize2 = teamSize2 + increaseTeamSize;
	
	return;
}

void playerPlopper(int plopTeam1, int plopTeam2) {
	int newXpos = 0, newYpos = 0;
	int ploppingPlayer = 0;//which person is being plopped
	
	if (plopTeam1 = 1) {
		for (ploppingPlayer=1; ploppingPlayer <= teamSize1; ploppingPlayer++) {
		
			newXpos = dude[ploppingPlayer].getXpos() + rd6() - 1;//up to 5 from start
			newYpos = dude[ploppingPlayer].getYpos() + (2 * rd20()) - 20;//up to 20 in either way
			
			cout << "Was on " << dude[ploppingPlayer].getXpos()  << "," << dude[ploppingPlayer].getYpos() << endl;
			cout << newXpos << "," << newYpos << endl;
			
			if (mainMap.getGridPassable(newXpos,newYpos) && newXpos >= 0 && newYpos >= 0 && newXpos < 25 && newYpos < 50) {//if no one is there, and on the map
					
					mainMap.setGridPlayer(newXpos,newYpos,ploppingPlayer); //draws the person number on the map
					mainMap.setGridPlayer(dude[ploppingPlayer].getXpos(),dude[ploppingPlayer].getYpos(),0);//deletes old class initial
					
					
					
					dude[ploppingPlayer].setXpos(newXpos);
					dude[ploppingPlayer].setYpos(newYpos); //saves the new location for the player
					cout << epithet(ploppingPlayer) << " is on  " << newXpos << "," << newYpos << " and will stay plopped here\n\n";
			}
			else { //if something is there, just redoes it
				cout << epithet(ploppingPlayer) << " is on  " << newXpos << "," << newYpos << " and will be re-plopped\n\n";
				ploppingPlayer--;
			}
		}
	}
	if (plopTeam2 = 1) {
		for (ploppingPlayer=teamSize1 + 1; ploppingPlayer <= teamSize2 + teamSize1; ploppingPlayer++) {
		
			newXpos = dude[ploppingPlayer].getXpos() - rd6() + 1;//up to 5 from start
			newYpos = dude[ploppingPlayer].getYpos() + (2 * rd20()) - 20;//up to 20 in either way
			
			cout << "Was on " << dude[ploppingPlayer].getXpos()  << "," << dude[ploppingPlayer].getYpos() << endl;
			cout << newXpos << "," << newYpos << endl;
			
			if (mainMap.getGridPassable(newXpos,newYpos) && newXpos >= 0 && newYpos >= 0 && newXpos < 25 && newYpos < 50) {//if no one is there, and on the map
					
					
					mainMap.setGridPlayer(newXpos,newYpos,ploppingPlayer); //draws the person number on the map
					mainMap.setGridPlayer(dude[ploppingPlayer].getXpos(),dude[ploppingPlayer].getYpos(),0);//deletes old class initial
					
					
					dude[ploppingPlayer].setXpos(newXpos);
					dude[ploppingPlayer].setYpos(newYpos); //saves the new location for the player
					cout << epithet(ploppingPlayer) << " is on  " << newXpos << "," << newYpos << " and will stay plopped here\n\n";
			}
			else { //if something is there, just redoes it
				cout << epithet(ploppingPlayer) << " is on  " << newXpos << "," << newYpos << " and will be re-plopped\n\n";
				ploppingPlayer--;
			}
		}
	}
	
	
	

return;	
}

// this is the beginning character creation part 
void newGameFunc() {
string userInputString;
int bonusOptions = 0;
int l = 0, k = 0;
int usingArmy = 0;
int armyType = 0;
int buyPerson[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    cout << "\nWelcome to Ben and Dillon's awesome game\n";
    
    cout << "\nPlayer 1, do you want to use an army?\n 1:Yes\n 2:No\n";
    if (!FAST_START)
        cin >> usingArmy;
    else
        usingArmy = 1;

    if (usingArmy == 1) {
		cout << "\n\nWhat kind of army?\n 0:Nevermind\n 1:New army\n 2:Saved army\n";

        if (!FAST_START)
            cin >> armyType;
        else
            armyType = 1;

		if (armyType == 1) {
			newArmy(1);//new army for team 1
			
		}
		else if (armyType == 2) {
			getSaveArmy(1);//finds a saved army for team 1
		}
	}

	if (army1[0]) {//if team 1 is an army
		teamNames[1] = armyName1;
		
		cout << "Before you get started, do you want to increase the size of your army?\n";
		cout << "Current max size: " << army1[2] << endl;
		cout << "Current gold: " << army1[1] << endl;
		cout << "Cost to increase army size by 1 is " << (army1[2])*1000 << " gold\n";
		cout << "1:Yes\n2:No\n";
		if (!FAST_START)
			cin >> userInput;
		else
			userInput = 2;
		
		if (userInput == 1 && army1[1] >= army1[2]*1000) {
			army1[1] = army1[1] - army1[2]*1000;
			army1[2]++;
		}
		else if (userInput == 1 && army1[1] < army1[2]*1000) {
			cout << "You do not have enough gold to do that\n";
		}
		
		while (1) {
			cout << "\nHow many characters do you want on your team?\n";
			cout << "Current max size: " << army1[2] << endl;
			if (!FAST_START)
				cin >> teamSize1;
			else
				teamSize1 = 1;
            
			if (teamSize1 > army1[2]) {
				cout << "You cannot support an army that large.\n";
			}
			else {
				break;
			}
		}
		
		if (armyType == 2) {
			
		}
		
	}
	else {//if not using an army
		cout << "\nHow many characters do you want on the first team?\n";

        if (!FAST_START)
            cin>> teamSize1;
        else
            teamSize1 = 1;

		cout << "\nPlayer 1, please type in your name\n";

        if (!FAST_START)
            cin >> teamNames[1];
        else
            teamNames[1] = "Ben";
	}
		
for ( l = 1; l <= teamSize1; l++ )
{
 
	while (dude[l].getCharacterClass() == 0) {
		cout << endl << teamNames[1] << " pick their class\n 0:Saved character\n 1:Fighter \n 2:Archer \n 3:Priest \n 4:Berserker \n 5:Knight \n";
		cout << " 6:Scout \n 7:Mage \n 8:Warlock \n 9:NPC  \n 999:Random  \n 888:Learn more\n";


        if (!FAST_START)
            cin >> userInput;
        else
            userInput = 999;

		if (userInput == 9) {
			cout << "What should the NPC be?\n 101:Wolf  \n 102:Bear  \n 103:Goblin Fighter  \n 104:Goblin Archer  \n 105:Stone Golem \n 106:Iron Golem  \n 107:Goblin Mage  \n";
			cout << " 108:Goblin priest \n 109:Giant rat\n 110:Giant beetle\n 111:Giant ant\n 999:Random\n";
			cin >> userInput;
			if (userInput == 999) { // random npc
				userInput = rand() % 10 + 101;
				cout << userInput << " was chosen\n";
			}
		}
		if (userInput == 999) { //random class
			userInput = rand() % 8 +1;
			cout << userInput << " was chosen\n";
		}
		if (userInput == 888) { //learn about classes
			learnClasses();
			userInput = 999; //makes the for loop re-do the loop it did last time
			
		}

		
		dude[l].setCharacterClass(userInput); // stores character's class
		if (userInput == 0) {break;}
	}
    
    while (dude[l].getRace() == 0 && dude[l].getCharacterClass() != 0 && dude[l].getCharacterClass() != 999) {
		cout << endl << teamNames[1] << " pick their race\n 1:Human \n 2:Wood elf \n 3:High elf \n 4:Dark elf\n 5:Hill dwarf\n";
		cout << " 6:Mountain dwarf \n 7:Halfling \n 8:Orc  \n 9:Centaur \n 999:Random  \n 888:Learn more\n";

        if (!FAST_START)
            cin >> userInput;
        else
            userInput = 999;
	 
		if (userInput == 999) { //random race
			userInput = rand() % 8 +1;
			cout << endl << userInput << " was chosen\n";
		}
		if (userInput == 888) { //learn about races
			learnRaces();
			userInput = 999;
		}

		dude[l].setRace(userInput); // stores character's race
	}
    
    cout << endl;
    if (dude[l].getCharacterClass() != 0 && dude[l].getCharacterClass() != 999 && dude[l].getRace() != 999) {
		cout << endl << teamNames[1] << " please name your character\n";

        if (!FAST_START)
            cin >> userInputString;
        else
            userInputString ="Ben";

		dude[l].setName(userInputString);
		dude[l].setTeam(1);
		cout << endl;
	}
			
	if (rd20() == 20 && dude[l].getCharacterClass() != 0 && dude[l].getCharacterClass() != 999 && dude[l].getRace() != 999){//chance for birthright
		userInput = rand() % 5 +1;//random birthright
		if (userInput == 1) {//decides type of dragonspawn
			userInput = rand() % 4 + 101;//random dragonspawn
		}
		dude[l].setBirthRight(userInput);
		
	}
		
	if (dude[l].getCharacterClass() == 999 || dude[l].getRace() == 999) {//reloops if you looked at a menu
		if (dude[l].getCharacterClass() == 999) {
			dude[l].setCharacterClass(0);
		}
		if (dude[l].getRace() == 999) {
			dude[l].setRace(0);
		}
		l--;
	}

	if (dude[l].getCharacterClass() != 0 && dude[l].getCharacterClass() != 999 && dude[l].getRace() != 999 && army1[0]) {//if they are using an army, each person costs money
		if (army1[1] >= 1000) {
			cout << "Are you sure to want to pay 1000 gold to use this person?\n 1:Yes\n 2:No\n";
			if (!FAST_START)
				cin >> buyPerson[l];
			else
				buyPerson[l] = 1;
			
			cout << endl;
			if (buyPerson[l] == 1) {
				armyGainMoney(1,-1000);
			}
		}
		else {
			cout << "This army does not have the required funds for this person.\n";
			buyPerson[l] = 0;
		}
	}
}

	cout << "\nPlayer 2, do you want to use an army?\n 1:Yes\n 2:No\n";

    if (!FAST_START)
        cin >> usingArmy;
    else
        usingArmy = 2;

	if (usingArmy == 1) {
		cout << "\n\nWhat kind of army?\n 0:Nevermind\n 1:New army\n 2:Saved army\n";

        if (!FAST_START)
            cin >> armyType;
        else
            armyType = 1;

		if (armyType == 1) {
			newArmy(2);//new army for team 2			
		}
		else if (armyType == 2) {
			getSaveArmy(2);//finds a saved army for team 2
		}
	}

	if (army2[0]) {//if team 2 is an army
		teamNames[2] = armyName2;
		
		cout << "Before you get started, do you want to increase the size of your army?\n";
		cout << "Current max size: " << army2[2] << endl;
		cout << "Current gold: " << army2[1] << endl;
		cout << "Cost to increase army size by 1 is " << (army2[2])*1000 << " gold\n";
		cout << "1:Yes\n2:No\n";
		cin >> userInput;
		if (userInput == 1 && army2[1] >= army2[2]*1000) {
			army2[1] = army2[1] - army2[2]*1000;
			army2[2]++;
		}
		else if (userInput == 1 && army2[1] < army2[2]*1000) {
			cout << "You do not have enough gold to do that\n";
		}
		
		while (1) {
			cout << "\nHow many characters do you want on your team?\n";
			cout << "Current max size: " << army2[2] << endl;
            cin >> teamSize2;
			if (teamSize2 > army2[2]) {
				cout << "You cannot support an army that large.\n";
			}
			else {
				break;
			}
		}
		
		if (armyType == 2) {
			
		}
		
	}
	else {//if not using an army
		cout << "\nHow many characters do you want on the second team?\n";
		
		 if (!FAST_START)
            cin>> teamSize2;
        else
            teamSize2 = 1;
		
		
		cout << "\nPlayer 2, please type in your name\n";
		
		if (!FAST_START)
            cin>> teamNames[2];
        else
            teamNames[2] = "Dillon";
	}

for ( k = teamSize1 + 1; k <= teamSize1 + teamSize2; k++ )
{
	
	while (dude[k].getCharacterClass() == 0) {
		cout << endl << teamNames[2] << " pick their class\n 0:Saved Character\n 1:Fighter \n 2:Archer \n 3:Priest \n 4:Berserker \n";
		cout << " 5:Knight \n 6:Scout \n 7:Mage \n 8:Warlock \n 9:NPC\n 999:Random\n 888:Learn more\n";
		
		
		if (!FAST_START)
            cin >> userInput;
        else
            userInput = 999;
            
		if (userInput == 9) {
			cout << "What should the NPC be?\n 101:Wolf  \n 102:Bear  \n 103:Goblin Fighter  \n 104:Goblin Archer  \n 105:Stone Golem \n 106:Iron Golem  \n 107:Goblin Mage  \n";
			cout << " 108:Goblin priest \n 109:Giant rat\n 110:Giant beetle\n 111:Giant ant\n 999:Random\n";
			cin >> userInput;
			if (userInput == 999) { //random npc
				userInput = rand() % 10 + 101;
				cout << userInput << " was chosen\n";
			}
		}
		
		if (userInput == 999) { //random class
				userInput = rand() % 8 + 1;
				cout << userInput << " was chosen\n";
		}
		if (userInput == 888) { //learn about classes
			learnClasses();
			userInput = 999; //makes the for loop re-do the loop it did last time
			
		}
		dude[k].setCharacterClass(userInput);
		if (userInput == 0) {break;}
	}
    
    
    while (dude[k].getRace() == 0 && dude[k].getCharacterClass() != 0 && dude[k].getCharacterClass() != 999) {
		cout << endl << teamNames[2] << " pick their race\n 1:Human \n 2:Wood elf \n 3:High elf \n 4:Dark elf\n 5:Hill dwarf\n";
		cout << " 6:Mountain dwarf \n 7:Halfling \n 8:Orc  \n 9:Centaur  \n 999:Random  \n 888:Learn more\n";
		
		
		if (!FAST_START)
            cin >> userInput;
        else
            userInput = 999;
		
		if (userInput == 999) { //random race
			userInput = rand() % 9 +1;
			cout << endl << userInput << " was chosen\n";
		}
		if (userInput == 888) { //learn about races
			learnRaces();
			userInput = 0; //makes the for loop re-do the loop it did last time
			
		}

		dude[k].setRace(userInput); // stores character's race
		
	}
    
    cout << endl;
    if (dude[k].getCharacterClass() > 0 && dude[k].getCharacterClass() != 999 && dude[k].getRace() != 999) {
		    cout << endl << teamNames[2] << " please name your character\n";
			
			
			if (!FAST_START)
				cin >> userInputString;
			else
				userInputString = "Dillon";
			
			dude[k].setName(userInputString);
			dude[k].setTeam(2);
			cout << endl;
		}
	if (rd20() == 20 && dude[k].getCharacterClass() != 0 && dude[k].getCharacterClass() != 999 && dude[k].getRace() != 999){//chance for birthright
		userInput = rand() % 5 +1;//random birthright
		if (userInput == 1) {//decides type of dragonspawn
			userInput = rand() % 4 + 101;//random dragonspawn
		}
		dude[k].setBirthRight(userInput);
	
	
	}
	
	if (dude[k].getCharacterClass() == 999 || dude[k].getRace() == 999) {//reloops if you looked at a menu
		if (dude[k].getCharacterClass() == 999) {
			dude[k].setCharacterClass(0);
		}
		if (dude[k].getRace() == 999) {
			dude[k].setRace(0);
		}
		k--;
		
	}

	if (dude[k].getCharacterClass() != 0 && dude[k].getCharacterClass() != 999 && dude[k].getRace() != 999 && army2[0]) {//if they are using an army, each person costs money
		if (army2[1] >= 1000) {
			cout << "Are you sure to want to pay 1000 gold to use this person?\n 1:Yes\n 2:No\n";
			cin >> buyPerson[k];
			cout << endl;
			if (buyPerson[k] == 1) {
				armyGainMoney(2,-1000);
			}
		}
		else {
			cout << "This army does not have the required funds for this person.\n";
			buyPerson[l] = 0;
		}
	}
}
	
	
    fillStats();
    
    if (army1[0]) {
		for (assignGuy=1; assignGuy <= teamSize1; assignGuy++) {
			if (dude[assignGuy].getCharacterClass() == 0) {
				cout << teamNames[1] << " ";
				getArmyPeopleSaves(1); 
				dude[assignGuy].setTeam(1);
			}
		}
	}
    else {
		for (assignGuy=1; assignGuy <= teamSize1; assignGuy++) {
			if (dude[assignGuy].getCharacterClass() == 0) {
				cout << teamNames[1] << " ";
				getSave(); 
				dude[assignGuy].setTeam(1);
				
			}
		}
	}
	
	if (army2[0]) {
		for (assignGuy= teamSize1 + 1; assignGuy <= teamSize2 + teamSize1; assignGuy++) {
			if (dude[assignGuy].getCharacterClass() == 0) {
				cout << teamNames[2] << " ";
				getArmyPeopleSaves(2); 
				dude[assignGuy].setTeam(2);
			}
		}
		
	}
	else {		
		for (assignGuy= teamSize1 + 1; assignGuy <= teamSize2 + teamSize1; assignGuy++) {
			if (dude[assignGuy].getCharacterClass() == 0) {
				cout << teamNames[2] << " ";
				getSave(); 
				dude[assignGuy].setTeam(2);
				
			}
		}
	}
	
	
	familiar();
		
    assignClass();
    assignRace();
    assignBirthRight();
    assignPrestige();
    assignRenown();
    assignParagon();
    assignStartingMana();
    assignVariousOtherStats();
    
    if (worldSeed > 0) {
		srand (worldSeed);
	}
    mainMap.addGrass(30,27,7,2);
    mainMap.addTrees(5,9);
    mainMap.addCastles(1000);
    mainMap.addElevation(200,10,1,20);
    mainMap.addDivine(40,8,1,rd6() * 10);
    mainMap.addArcane(40,8,1,rd6() * 10);
    mainMap.addGold(5,50,10);
    mainMap.addSiegeWeapons(1);
    if (worldSeed > 0) {
		srand (time(NULL));
	}
    
    placement();
    
    cout << "Do you want to adjust detailed options?\n0:No\n1:Yes\n";
    
    
    if (!FAST_START)
            cin >> bonusOptions;
        else
            bonusOptions = 0;
    
    cout << endl;
    if (bonusOptions) {
		cout << "What world seed do you want to use?\n(type \'0\' to not use a world seed)\n";
		
		if (!FAST_START)
            cin >> worldSeed;
        else
            worldSeed = 0;
		
		
		cout << "Do you want the game to be more random?\n0: No\n1: Yes\n";
		if (!FAST_START)
            cin >> moreRandomTeam1;
        else
            moreRandomTeam1 = 0;
		
		
		if (moreRandomTeam1 == 1) { 
			int randomLocation1 = 0, randomLocation2 = 0;
			cout << teamNames[1] << " do you want your team stats more random?\n0: No\n1: Yes\n"; 
			if (!FAST_START)
				cin >> moreRandomTeam1;
			else
				moreRandomTeam1 = 0;	
			
			cout <<  teamNames[2] << " do you want your team stats more random?\n0: No\n1: Yes\n"; 
			if (!FAST_START)
				cin >> moreRandomTeam2;
			else
				moreRandomTeam2 = 0;
			moreRandom(); 
			
			
			cout << teamNames[1] <<  " do you want your character locations to be more random?\n0: No\n1: Yes\n";
			if (!FAST_START)
				cin >> randomLocation1;
			else
				randomLocation1 = 0;
			
			cout << teamNames[2] <<  " do you want your character locations to be more random?\n0: No\n1: Yes\n";
			if (!FAST_START)
				cin >> randomLocation1;
			else
				randomLocation1 = 0;
			
			playerPlopper(randomLocation1,randomLocation2);
			
		}     
		
		
		cout << "Do you want some people to enter the battle later?\n0: No\n1: Yes\n";
		if (!FAST_START)
				cin >> staggerStartSpread[0];
			else
				staggerStartSpread[0] = 0;
		
		if (staggerStartSpread[0] = 1) {
			cout << endl << teamNames[1] << " how many from team 1 should start on the field?\n";
			cin >> staggerStartBeginningPeople[1];
			if (staggerStartBeginningPeople[1] + 1 <= teamSize1) {
				cout << "\nHow long do you want to wait before the other people start coming?\n";
				cin >> staggerStartPreSpread[1];
				cout << "\nHow many turns apart do you want the rest of team 1 spread out?\n";
				cin >> staggerStartSpread[1];
			}
			staggerStartCounter[1] = staggerStartBeginningPeople[1] * staggerStartSpread[1] + 1;
			
			cout << endl << teamNames[2] << " how many from team 2 should start on the field?\n";
			cin >> staggerStartBeginningPeople[2];
			if (staggerStartBeginningPeople[2] + 1 <= teamSize2) {
				cout << "\nHow long do you want to wait before the other people start coming?\n";
				cin >> staggerStartPreSpread[2];
				cout << "\nHow many turns apart do you want the rest of team 2 spread out?\n";
				cin >> staggerStartSpread[2];
			}
			staggerStartCounter[2] = staggerStartBeginningPeople[2] * staggerStartSpread[2] + 1;
			
		}
		
		cout << "Do you want there to be more dramatic pauses?\n0: No\n1: Yes\n";
		if (!FAST_START)
				cin >> moreDrama;
			else
				moreDrame = 0;
		
		
		
		bool jumpUp = 0;
		int jumpUpLevel = 0;
		cout << "Do you want people to skip up some levels?\n0: No\n1: Yes\n";
		if (!FAST_START)
				cin >> jumpUp;
			else
				jumpUp = 0;
		
		
		if (jumpUp) {
			for (assignGuy=1; assignGuy <= teamSize1 + teamSize2; assignGuy++) {
				cout << "What level do you want " << dude[assignGuy].getName() << " to level up to?\n";
				cin >> jumpUpLevel;
				jumpingUp(assignGuy, jumpUpLevel);
			}
		}
		
		
		
	}	
	
	
	//for priests renowned for being blessed
	 for (assignGuy=1; assignGuy <= teamSize1 + teamSize2; assignGuy++) {//attack, defense, move, mana regen
		 
		if (dude[assignGuy].getRenown() == 301) {
			initialBlessed[assignGuy] = rd8();
			switch (initialBlessed[assignGuy]) {
				case 1:
					dude[assignGuy].setAttack( dude[assignGuy].getAttack() + 1 );//raise attack
				break;
				case 2:
					dude[assignGuy].setAttack( dude[assignGuy].getAttack() + 2 );//raise attack
				break;
				case 3:
					dude[assignGuy].setAttack( dude[assignGuy].getAttack() + 3 );//raise attack
				break;
				case 4:
					dude[assignGuy].setDefense( dude[assignGuy].getDefense() + 1 );//raise defense
				break;
				case 5:
					dude[assignGuy].setDefense( dude[assignGuy].getDefense() + 2 );//raise defense
				break;
				case 6:
					dude[assignGuy].setMove( dude[assignGuy].getMove() + 2 );//raise move
				break;
				case 7:
					dude[assignGuy].setManaRegen( dude[assignGuy].getManaRegen() + 1 );//raise mana regen
				break;
				case 8:
					dude[assignGuy].setManaRegen( dude[assignGuy].getManaRegen() + 2 );//raise mana regen
				break;
				
			}
			if (rd20() <=20) {//chance for super bless
				initialBlessed[assignGuy]=20;
				dude[assignGuy].setAttack( dude[assignGuy].getAttack() + 3 );//raise attack
				dude[assignGuy].setDefense( dude[assignGuy].getDefense() + 1 );//raise defense
				dude[assignGuy].setMove( dude[assignGuy].getMove() + 2 );//raise move
				dude[assignGuy].setManaRegen( dude[assignGuy].getManaRegen() + 2 );//raise mana regen
			}
		}
	}
			
	

	
    cout << endl;
    return;
}

//the title page for the game 
void titleFunc() {
	
    cout << "\n\n\n\t\t\t\tBen and Dillon's Awesome Game\n\n\n";
    cout << "\t\t\t\t   1: Play\n";
    
    
 
    if (!FAST_START)
        cin >> userInput;
    else
        userInput = 1;

    if(userInput == 1) {
       newGameFunc();
	}
    else {
        running = 0; // If the user does not enter a valid command, we will terminate the program
    }
    return;
}

void attack() {
	int j = 0;
	int damagePreBless = 0;
	int heightBonus = 0;
	int chanceToMiss = 0, chanceToEvade = 0, sectionsAway = 0;
	int heightAttacker, heightDefender, heightDifferenceSquared, distanceSquared;
	moving = 0;
	usedSpecial = 0;
		
if (needToReload[moveGuy] > 0) {
		cout << dude[moveGuy].getName() << " is reloading.\n";
		needToReload[moveGuy]--;
		dude[moveGuy].setAp(dude[moveGuy].getAp() - 6); //lowers Ap
		
		if (dude[moveGuy].getParagon() == 2012) {//crossbowman of dexterity
			if (rd4() == 4) {//25% chance to not use ap on a reload
				dude[moveGuy].setAp( dude[moveGuy].getAp() + 6 ); //raises Ap to level from before
			}
			cout << epithet(moveGuy) << "'s dextrous hands reload their crossbow in the blink of an eye\n";
		}
	}
	else {
		range = dude[moveGuy].getRange();//sets range for the map to use
		
		if (throwingAxe == 1) {//if throwing an axe
			range = 5;
		}
		
		showMapRange();
		
		
		
			
			if (dude[moveGuy].getTeam() == 1) {//if team 1
				cout <<  endl << teamNames[1] <<  ", who will " << epithet(moveGuy) << " choose to attack?\n0:nobody\n";
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) 
				{
					if (dude[j].getHealth() > 0) //checks for defenders who aren't dead
					{
						cout << j - teamSize1 << ": " << epithet(j);
						distanceSquared = (dude[moveGuy].getXpos()-dude[j].getXpos())*(dude[moveGuy].getXpos()-dude[j].getXpos()) + (dude[moveGuy].getYpos()-dude[j].getYpos())*(dude[moveGuy].getYpos()-dude[j].getYpos());
						heightAttacker = mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos());
						heightDefender = mainMap.getGridElevation(dude[j].getXpos(),dude[j].getYpos());
						heightDifferenceSquared = (heightDefender-heightAttacker)*(heightDefender-heightAttacker);
						//how many groups of 5 they are away, and adds 1 so that it can't be zero
						sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5 + 1;
						if (dude[moveGuy].getPrestige() == 201) {//crossbow is more accurate at close range
							sectionsAway--;
						}
						//the chance to miss times the multiples of 5 away that the enemy is
						chanceToMiss = sectionsAway * dude[moveGuy].getMissChance();
						cout << " " << 100 - chanceToMiss - dude[j].getEvasion() << "%" << endl;
					}
				}
			}
				
			if (dude[moveGuy].getTeam() == 2) {//if team 2
				cout <<  endl << teamNames[2] <<  ", who will " << epithet(moveGuy) << " choose to attack?\n0:nobody\n";
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() > 0) //checks for defenders who aren't dead
					{
						cout << j << ": " << epithet(j);
						distanceSquared = (dude[moveGuy].getXpos()-dude[j].getXpos())*(dude[moveGuy].getXpos()-dude[j].getXpos()) + (dude[moveGuy].getYpos()-dude[j].getYpos())*(dude[moveGuy].getYpos()-dude[j].getYpos());
						heightAttacker = mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos());
						heightDefender = mainMap.getGridElevation(dude[j].getXpos(),dude[j].getYpos());
						heightDifferenceSquared = (heightDefender-heightAttacker)*(heightDefender-heightAttacker);
						//how many groups of 5 they are away, and adds 1 so that it can't be zero
						sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5 + 1;
						if (dude[moveGuy].getPrestige() == 201) {//crossbow is more accurate at close range
							sectionsAway--;
						}
						//the chance to miss times the multiples of 5 away that the enemy is
						chanceToMiss = sectionsAway * dude[moveGuy].getMissChance();
						cout << " " << 100 - chanceToMiss - dude[j].getEvasion() << "%" << endl;
					}
				}
			}
			
		cin >> defender;	
		
	if (defender != 0) {
		if (!(doubleShooting) || (doubleShooting && (defender != doubleShootingFirstTarget))) {

			dramaticPause();
			
			if (dude[moveGuy].getTeam() == 1) {//if on team 1, makes it aim at the right guy
				defender = defender + teamSize1;
			}
			
			if (doubleShooting) {
				doubleShootingFirstTarget = defender;
			}
			
			distanceSquared = (dude[moveGuy].getXpos()-dude[defender].getXpos())*(dude[moveGuy].getXpos()-dude[defender].getXpos()) + (dude[moveGuy].getYpos()-dude[defender].getYpos())*(dude[moveGuy].getYpos()-dude[defender].getYpos());
			
			heightAttacker = mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos());
			heightDefender = mainMap.getGridElevation(dude[defender].getXpos(),dude[defender].getYpos());
			heightDifferenceSquared = (heightDefender-heightAttacker)*(heightDefender-heightAttacker);
			if (heightAttacker > heightDefender) {//makes the height difference negative if you are higher (and smaller)
				heightDifferenceSquared = heightDifferenceSquared * -1/2;
			}
			bool missed = 0;
			
					
					
			
			//checks for range
			//if throwing an axe sets range to 5
			//if in melee distance, ignores elevation
			if ((dude[moveGuy].getRange()*dude[moveGuy].getRange() >= distanceSquared + heightDifferenceSquared) || distanceSquared == 1 || (throwingAxe == 1 && 25 >= distanceSquared + heightDifferenceSquared))
			{
				dude[moveGuy].setAp(dude[moveGuy].getAp() - 6); //lowers Ap
				
				attackTimes[moveGuy] = attackTimes[moveGuy] + 1; //says they attacked
				
				//double attackers
				if ((dude[moveGuy].getPrestige() == 202 || dude[moveGuy].getPrestige() == 401 || dude[moveGuy].getPrestige() == 603 || dude[moveGuy].getParagon() == 6011) && attackTimes[moveGuy] < 3) { //lets them double attack, but not 3 times
					//longbowman, battlerager, ranger, mounted archer of quick-shot
					dude[moveGuy].setAp( dude[moveGuy].getAp() + 3 ); //raises Ap
				}
				//checks if archer misses
				/*
				if (dude[moveGuy].getCharacterClass() == 2 || dude[moveGuy].getPrestige() == 601 || dude[moveGuy].getPrestige() == 603 || dude[moveGuy].getCharacterClass() == 104) { 
					if (distanceSquared + heightDifferenceSquared >=16 && dude[moveGuy].getPrestige() != 201) {if (rd6() == 1) {missed = 1; }	}
					if (distanceSquared + heightDifferenceSquared >=64) {if (rd6() == 1) {missed = 1; }	}
					if (distanceSquared + heightDifferenceSquared >=144) {if (rd6() == 1) {missed = 1; }	}
					if (distanceSquared + heightDifferenceSquared >=256) {if (rd6() == 1) {missed = 1; }	}
					if (distanceSquared + heightDifferenceSquared >=400) {if (rd6() == 1) {missed = 1; }	}
					if (distanceSquared + heightDifferenceSquared >=4) { if (protectRangedTimer[defender] > 0) {if (rd2() == 1) {missed = 1;
					cout << "The shield protected " << dude[defender].getName() << "from the attack"; }	} } //if protect from missiles is on them, they can be protected
				}
				*/
				
				//how many groups of 5 they are away, and adds 1 so that it can't be zero
				sectionsAway = sqrt(distanceSquared + heightDifferenceSquared) / 5 + 1;
				if (dude[moveGuy].getPrestige() == 201) {//crossbow is more accurate at close range
					sectionsAway--;
				}
				//the chance to miss times the multiples of 5 away that the enemy is
				chanceToMiss = sectionsAway * dude[moveGuy].getMissChance();
				
				
				if (aimingShot) {
					chanceToMiss = -(dude[defender].getEvasion());
				}
				
				cout << "Total hit chance: " << 100 - chanceToMiss - dude[defender].getEvasion() << "%" << endl;
				if (100 - chanceToMiss - dude[defender].getEvasion() < rd100()) { 
					//range 1-5 10%,  range 6-10 20%,  range 11-15 30%,  range 16-20 40%,  range 21-25 50%
					//range 1-5 9%,   range 6-10 18%,  range 11-15 27%,  range 16-20 36%,  range 21-25 45%
					//range 1-5 8%,   range 6-10 16%,  range 11-15 24%,  range 16-20 32%,  range 21-25 40%
					//range 1-5 7%,   range 6-10 14%,  range 11-15 21%,  range 16-20 28%,  range 21-25 35%
					//range 1-5 6%,   range 6-10 12%,  range 11-15 18%,  range 16-20 24%,  range 21-25 30%
					//range 1-5 5%,   range 6-10 10%,  range 11-15 15%,  range 16-20 20%,  range 21-25 25%
					//range 1-5 4%,   range 6-10 8%,   range 11-15 12%,  range 16-20 16%,  range 21-25 20%
					//range 1-5 3%,   range 6-10 6%,   range 11-15 9%,   range 16-20 12%,  range 21-25 15%
					//range 1-5 2%,   range 6-10 4%,   range 11-15 6%,   range 16-20 8%,   range 21-25 10%
					missed = 1;
				}
				
				//checks if there is an arrow blocking shield
				if (dude[moveGuy].getCharacterClass() == 2 || dude[moveGuy].getPrestige() == 601 || dude[moveGuy].getPrestige() == 603 || dude[moveGuy].getCharacterClass() == 104) { 
					if (protectRangedTimer[defender] > 0) {
						if (rd2() == 1) {
							missed = 1;
							cout << "The shield protected " << dude[defender].getName() << "from the attack"; 
						}
					}
				}
					
				if (aimingShot) {//aimed shot always hits
					cout << epithet(moveGuy) << " aims very carefully.\n";
					
				}	
			
				if (throwingAxe) {//axes miss 50% of the time no matter the accuracy
					missed = rd2();
				}
				
				if (dude[moveGuy].getParagon() == 2021) {//longbowman of precision
					if (missed == 1 && rd6()==6) {
						cout << dude[moveGuy].getName() << "'s precision allows them to hit their target\n\n";
						missed = 0;
					}
				}
			
			if (missed == 0) { //checks if the archer didn't miss
				
						int attackRoll = rd12(), defenseRoll = rd10();
						
						
						//if a scout, halfling, or lucky rolls poorly, they get to use luck to re-roll
							
						int rerollDefense = 0;
						if (dude[defender].getCharacterClass() == 6){rerollDefense++;}
						if (dude[defender].getBirthRight() == 5){rerollDefense++;}
						if (dude[defender].getRace() == 7){rerollDefense++;}
						if ((rerollDefense == 1 && (defenseRoll <= 2)) || (rerollDefense == 2 && (defenseRoll <= 3)) || (rerollDefense == 3 && (defenseRoll <= 4)) ) {
						
						dude[defender].setXp(dude[defender].getXp() + 5); //adds xp
						if (defender < 7 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money for defender
						if (defender > 7 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money for defender
						cout << endl << dude[defender].getName() << " was able help himself after a fumble";
						defenseRoll = rd10();
						dramaticPause();
						}
						
						int rerollAttack = 0;
						if (dude[moveGuy].getCharacterClass() == 6){rerollAttack++;}
						if (dude[moveGuy].getBirthRight() == 5){rerollAttack++;}
						if (dude[moveGuy].getRace() == 7){rerollAttack++;}
						if ((rerollAttack == 1 && attackRoll == 1) || (rerollAttack == 2 && (attackRoll <= 2)) || (rerollAttack == 3 && (attackRoll <= 3))) {
							
						dude[moveGuy].setXp(dude[moveGuy].getXp() + 5);	//adds xp
						if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
						if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
						cout << endl << dude[moveGuy].getName() << " was able to help himself after a fumble\n";
						attackRoll = rd12();
						dramaticPause();
						}
						
							if (heightDifferenceSquared <= -8) { //if the attacker is 4 spaces higher, adds 10% attack (it was divided by 2)
								cout << epithet(moveGuy) << " uses their elevation to their advantage\n";
								heightBonus = dude[moveGuy].getAttack() / 10;
							}
							else if (heightDifferenceSquared > 16) { //if the defender is 4 spaces higher, adds 10% defense
								cout <<epithet(defender) << " uses their elevation to their advantage\n";
								heightBonus = dude[defender].getDefense() / 10;
							}
							
							
							if (smiteDamage > 0 && (lichForm[defender] == 1 || dude[defender].getBirthRight() == 2 || dude[defender].getBirthRight() == 3 )) {smiteDamage = smiteDamage * 2;}//double smite to liches, vampires, and werewolves
							attackRoll = attackRoll + smiteDamage; // if it is a paladin's smite, they do extra
							
							int druidBoostAttack = 0, druidBoostDefense = 0;
							if (druidForm[moveGuy] > 0) {
								if (druidForm[moveGuy] == 1) {
									druidBoostAttack = dude[moveGuy].getAttack()/2;
								}
								if (druidForm[moveGuy] == 2) {
									druidBoostAttack = dude[moveGuy].getAttack()/4;
								}
								if (druidForm[moveGuy] == 3) {
									druidBoostAttack = dude[moveGuy].getAttack()/4;
								}
								if (druidForm[moveGuy] == 4) {
									druidBoostAttack = dude[moveGuy].getAttack()/3;
								}	
							}
							if (druidForm[defender] > 0) {
								if (druidForm[defender] == 1) {
									druidBoostDefense = dude[defender].getDefense()/2;
								}
								if (druidForm[defender] == 2) {
									druidBoostDefense = dude[defender].getDefense()/3;
								}
								if (druidForm[defender] == 3) {
									druidBoostDefense = dude[defender].getDefense()/4;
								}
								if (druidForm[defender] == 4) {
									druidBoostDefense = dude[defender].getDefense()/3;
								}	
							}
							
							damage = dude[moveGuy].getAttack() + attackRoll + druidBoostAttack + heightBonus - dude[defender].getDefense() - defenseRoll - druidBoostDefense; //calculates the damage done
							
							damage = damage + rageDamage;//raging berserker does more
							
							
							
							if (bless[moveGuy] > 0) {
								damagePreBless = damage;
								damage = damage + (rd2() * dude[moveGuy].getAttack() / 5);// 50% chance to raise attack by 20%
								
								if (damagePreBless < damage) {
									cout << endl << dude[moveGuy].getName() << " is blessed and has a higher attack\n";
									dramaticPause();
								}
							}
							else if (bless[moveGuy] < 0) {
								damagePreBless = damage;
								damage = damage - (rd2() * dude[moveGuy].getAttack() / 5);//50% chance to lower attack by 20%
								
								if (damagePreBless > damage) {
									cout << endl << dude[moveGuy].getName() << " is cursed and has a lower attack\n";
									dramaticPause();
								}
							}
							
							cout << endl << dude[moveGuy].getName() << " rolls a ";
							dramaticPause();
							cout <<  attackRoll;
							dramaticPause();
							cout << " and " << dude[defender].getName() << " rolls a ";
							dramaticPause();
							cout << defenseRoll; 
							dramaticPause();
							
							if (backstabbing || piercing) {//if backstabbing or piercing cancels half of armour
								damage = damage + dude[defender].getDefense()/2;
								if (backstabbing) {
									cout << endl << endl << epithet(moveGuy) << " stabs " << epithet(defender) << " in the back.\n\n"; 
								}
								if (piercing) {
									cout << endl << endl << epithet(moveGuy) << " hits " << epithet(defender) << " with a piercing arrow.\n\n"; 
								}
							}
							
							//if they are a ranger attacking at range, they lower their attack
							if (dude[moveGuy].getPrestige() == 603 && distanceSquared >= 4) {damage = ((damage*2)/3);}
							
							if (dude[moveGuy].getMaxMana() > 0) {//any sort of magic user
								//magic resist and fighter magic weakness
								if (dude[defender].getBirthRight() == 4 || dude[defender].getParagon() == 5022 || (dude[defender].getCharacterClass() == 1 && dude[defender].getParagon() != 1021)) {
										if (dude[moveGuy].getCharacterClass() == (7 || 8)) {//resist magic of devoted spellcasters
											if (dude[defender].getBirthRight() == 4) {//spellscarred
												cout << dude[defender].getName() << "'s spellscarred skin glows and they recieve less damage\n";
												damage = damage * 3 / 4;
											}
											if (dude[defender].getParagon() == 5022) {//mounted paladin of shielding
												cout << dude[defender].getName() << "'s shielded skin glows and they recieve less damage\n";
												damage = damage * 3 / 4;
											}
										}
										if (dude[defender].getCharacterClass() == 1) {//fighter weakness to magic
											damage = damage * 5 / 4;
										}
										
								}
							}
							
							if (charge[defender] > 0) { //less damage against charging knights
								if (dude[defender].getRenown() == 502) {
									damage = damage / 2; cout << endl << epithet(defender) << "'s charge makes them nigh on untouchable\n";
								}
								else {
								damage = damage * 2 / 3; cout << endl << epithet(defender) << "'s charge minimizes the damage\n";
								}
							} 
				
							if (dude[moveGuy].getRenown() == 702) {//mystics do more damage
								damage = damage + 3;
								cout << endl << epithet(moveGuy) << " glows with mystical power as they attack\n";
							}
							
							if (shield[defender] > 0) {
								damage = damage - shield[defender]; //does the mage shield
								if (damage > 0) {
									cout << endl <<  dude[defender].getName() << "'s shield minimizes the damage\n";
								}
								if (damage <= 0) {
									cout << endl << dude[defender].getName() << "'s shield blocks the damage\n";
								}	
							}
							
							if (defended[defender] > 0) { //checks if they are under the defender ability
								cout << endl << dude[defender].getName() << " is being defended by their team-mate\n";
								damage = damage - defended[defender];
							}
							
							checkBloodlust();	
							checkCrit();
							checkNewPoison();
							checkInspire();
							
									
							int tumble = 0;
							if (damage > 0) {
								if (dude[defender].getCharacterClass() == 6){tumble++;}
								if (dude[defender].getBirthRight() == 5){tumble++;}
								if (dude[defender].getRace() == 7){tumble++;}
								if (tumble >= rd10()) {//succesful tumble
								}
								else {
									tumble = 0;//unsuccessful tumble resets the tumble to zero
								}
									
							}
					
							//does damage here if there is damage, and the defender didn't tumble, and there was no coup de grace
							if (damage > 0 && tumble == 0 && !(dude[moveGuy].getParagon() == 3012 && (dude[defender].getMaxHealth() / dude[defender].getHealth() >= 10))) {
								checkCharge();	
								checkBullrush();
								checkEnchantWeapon();
								
								
								dude[defender].setHealth(dude[defender].getHealth() - damage); //inflicts the damage then after displays the results
									if (dude[defender].getHealth() <= 0) 
									{
										
										if (smiteDamage > 0) {
											cout <<endl << dude[moveGuy].getName() << " raises their glowing weapon and smites " << dude[defender].getName() << endl; 
											dude[moveGuy].setXp(dude[moveGuy].getXp() + 5);//adds xp
											if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (5) * 2);}//if team 1, gets money
											if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (5) * 2);}//if team 2, gets money
										} 
										
										if (rageDamage > 0) { 
											cout << endl << dude[moveGuy].getName() << " vehemently strikes " << dude[defender].getName() << endl; 
										}
										
										dramaticPause();
										cout << endl << endl << dude[defender].getName() << " takes " << damage << " damage,";
										dramaticPause();
										cout << " and dies\n\n";
										
										dude[moveGuy].setXp(dude[moveGuy].getXp() + damage + 10); //adds xp
										if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage + 10) * 2);}//if team 1, gets money
										if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage + 10) * 2);}//if team 2, gets money
										
										//check for teabag
										if (rd20() == 20) {
											dramaticPause();
											cout << dude[moveGuy].getName() << " teabags " << dude[defender].getName() << endl << endl;
											dude[moveGuy].setAttack(dude[moveGuy].getAttack() + 1); //adds one attack
											dude[moveGuy].setDefense(dude[moveGuy].getDefense() + 1); //adds one defense
										}
									}
									if (dude[defender].getHealth() > 0) 
									{
										dramaticPause();
										dude[moveGuy].setXp(dude[moveGuy].getXp() + damage); //adds xp
										if (dude[moveGuy].getTeam() == 1 && army1[0]) { armyGainMoney(1, (damage) * 2);}//if team 1, gets money
										if (dude[moveGuy].getTeam() == 2 && army2[0]) { armyGainMoney(2, (damage) * 2);}//if team 2, gets money
										
										
										
										if (smiteDamage > 0) {
											cout << endl << dude[moveGuy].getName() << " raises their glowing weapon and smites " << dude[defender].getName() << endl;
										}
										
										if (rageDamage > 0) { 
											cout << endl << dude[moveGuy].getName() << " vehemently strikes " << dude[defender].getName() << endl; 
										}
										
										cout << endl << endl << dude[defender].getName() << " takes " << damage << " damage,";
										dramaticPause();
										cout << " and has ";
										cout << dude[defender].getHealth() << " health left\n\n";
										
										if (dazing) {//if it is a scout using daze, the enemy loses 6 ap;
											dazed[defender] = 1;
											cout << epithet(defender) << " is dazed\n\n";
										}
										
										if (crippling) {//assassin of incapacitation
											haste[defender] = haste[defender] - 2;
											cout << epithet(defender) << " is crippled from " << dude[moveGuy].getName() << "'s attack\n\n";;
										}
										
										if (pushingBack || throwing) {//overbearing fighter and battlerager of grappling
											int xshove = 0, yshove = 0;
											int newXpos = 0, newYpos = 0;
											
											//these 2 lines show which direction to shove or throw
											xshove = dude[defender].getXpos() -  dude[moveGuy].getXpos();
											yshove = dude[defender].getYpos() -  dude[moveGuy].getYpos();
											
											if (pushingBack) {
												newXpos=dude[defender].getXpos()+xshove;
												newYpos=dude[defender].getYpos()+yshove;
											}
											else if (throwing) {
												newXpos=dude[defender].getXpos() - (2 * xshove);
												newYpos=dude[defender].getYpos() - (2 * yshove);
											}
											
											if (newXpos < 0 || newYpos < 0 || newXpos > 25 || newYpos > 50) { //checks that the target spot is on the map
												if (pushingBack) {
													cout << "\nYou can not shove them off the map\n";
												}
												else if (throwing) {
													cout << "\nYou can not throw them off the map\n";
												}
											}
											if (mainMap.getGridPassable(newXpos,newYpos) ) {//if nothing is there
												
												mainMap.setGridPlayer(newXpos,newYpos,defender); //draws the person number on the map
												mainMap.setGridPlayer(dude[defender].getXpos(),dude[defender].getYpos(),0);//deletes old class initial
												
												dude[defender].setXpos(newXpos);//sets the player to the new spot
												dude[defender].setYpos(newYpos);
												if (pushingBack) {
													cout << "\n" << dude[moveGuy].getName() << " shoves " << dude[defender].getName() << " backward\n\n";
												}
												if (throwing) {
													cout << "\n" << dude[moveGuy].getName() << " throws " << dude[defender].getName() << " over their head\n\n";
												}
											}
											else {
												if (pushingBack) {
													cout << "\nYou can not shove them into someone\n";
												}
												if (throwing) {
													cout << "\nYou can not throw them into someone\n";
												}
											}
										}
										
										
										
										if (dude[moveGuy].getParagon() == 2011) {//crossbowman of conflagration
											burn[defender] = burn[defender] + 2; //adds to the timer
										}
										
										if (dude[moveGuy].getParagon() == 8022) {//necromancer of malediction
											bless[defender]--;//curses the enemy
										}
									
									}
						}
					else if (dude[moveGuy].getParagon() == 3012 && (dude[defender].getMaxHealth() / dude[defender].getHealth() >= 10)) {//coup de grace for cleric of compassion
						dramaticPause();
						cout << dude[moveGuy].getName() << " raises their weapon and finishes " << dude[defender].getName() << " off with a coup de grace\n";
						dude[moveGuy].setXp(dude[moveGuy].getXp() + 25 + dude[defender].getHealth()); //adds xp
						if (defender < 7 && army1[0]) { armyGainMoney(1, (25 + dude[defender].getHealth()) * 2);}//if team 1, gets money for defender
						if (defender > 7 && army2[0]) { armyGainMoney(2, (25 + dude[defender].getHealth()) * 2);}//if team 2, gets money for defender
						dude[defender].setHealth(0);
					}
					else if (tumble > 0) {
						dramaticPause();
						cout << endl << dude[defender].getName() << " tumbles and dodges the attack\n";
						
					} 
					else {
						dramaticPause();
						cout << "\nThe attack failed\n\n";
					}
			}
			else if (throwingAxe) {
					cout << endl << dude[moveGuy].getName() << "'s throwing axe misses the target\n\n";
				}
			else {
				cout << endl << dude[moveGuy].getName() << "'s attack misses the target\n\n";
			}
			if (dude[moveGuy].getPrestige() == 201) { //says the crossbowman needs to reload next time
					cout << dude[moveGuy].getName() << " will need to reload\n\n";
					needToReload[moveGuy]++;
				}
		}	
		else {
		cout << "\nThey are not in range\n";
		attack();
		}
		}
		else {
			cout << epithet(moveGuy) << " can't attack the same person twice\n";
			attack();
			
		}		
	}
	else {
			cout << epithet(moveGuy) << " decides not to attack\n\n";
			usedSpecial = 1;
	}
	
}

	dramaticPause();
}


void dragonSpawnBreath() {//still need to add the cooldown timer to the character status in the menu
int confirmation = 0;

	if (dude[moveGuy].getBirthRight() > 100 && dude[moveGuy].getLevel() >= 0) {//if they are a dragonspawn at lvl 10 or more
	
		if (breathCoolDown[moveGuy] == 0) {//the cooldown is done
		
			freeMana = 1;//lets them use it for free
			
			switch(dude[moveGuy].getBirthRight()) {
				case 101://fire
				cout << "Do you want to fire your fireball?\n 1:Yes\n 2:No\n";
				cin >> confirmation;
				if (confirmation == 1) {
					mageFireBall();
					breathCoolDown[moveGuy] = 5;
				}
				break;
				
				case 102://ice
				cout << "Do you want to use your icy touch?\n 1:Yes\n 2:No\n";
				cin >> confirmation;
				if (confirmation == 1) {
					mageIceTouch();
					breathCoolDown[moveGuy] = 4;
				}
				break;
				
				case 103://poison
				cout << "Do you want to fire your poison?\n 1:Yes\n 2:No\n";
				cin >> confirmation;
				if (confirmation == 1) {
					magePoison();
					breathCoolDown[moveGuy] = 5;
				}
				break;
				
				case 104://lightning
				cout << "Do you want to fire your lightning?\n 1:Yes\n 2:No\n";
				cin >> confirmation;
				if (confirmation == 1) {
					clericLightningStrike();
					breathCoolDown[moveGuy] = 4;
				}
				break;
				
			freeMana = 0;//stops the free mana stuff
			}
		}
		else {
			cout << endl << epithet(moveGuy) << " is still recharging\n";
		}
		
	}
	return;
}

void vampireDrain() {
int confirmation = 0;
int spellChoice = 0;
int deadCount = 0;
int j = 0;

	if (dude[moveGuy].getBirthRight() == 2) {
		cout << "Do you want to drain a corpse's blood to gain health?\n 1:Yes\n 2:No\n";
		cin >> confirmation;
		
		//these add up the dead people
		for (j=1; j <= teamSize1; j++) {
			if (dude[j].getHealth() < 1) { //checks for dead people
				deadCount++;
			}
		}
		for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
			if (dude[j].getHealth() < 1) { //checks for dead people
				deadCount++;
			}
		}
		
		if (confirmation == 1 && deadCount > 0 ) {
			cout << "Whose corpse do you want to drain?\n";
			
			//displays dead enemies if in team 2
			if (dude[moveGuy].getTeam() == 2){
				for (j=1; j <= teamSize1; j++) {
					if (dude[j].getHealth() <= 0) { //checks for enemies who are dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
			//displays dead enemies if in team 1	
			if (dude[moveGuy].getTeam() == 1){
				for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ) {
					if (dude[j].getHealth() <= 0) { //checks for enemies who are dead
						cout << j << ": " << epithet(j) << endl;
						}
					}
				}
				cout << endl;
				cin >> spellChoice;
				cout << endl;
				if (spellChoice > 0) {
						
						// checks spell range
						if (1 >= (dude[moveGuy].getXpos()-dude[spellChoice].getXpos())*(dude[moveGuy].getXpos()-dude[spellChoice].getXpos()) + (dude[moveGuy].getYpos()-dude[spellChoice].getYpos())*(dude[moveGuy].getYpos()-dude[spellChoice].getYpos()))
						{ 
							if (drained[spellChoice] == 0) {
								
								damage = dude[spellChoice].getMaxHealth() * (24 + rd10()) / 100;//gains from 25 to 35% of enemies max health
								
								if (lichForm[moveGuy] == 1) {
									damage= damage + rd4();
									cout << dude[moveGuy].getName() << "'s body glows with ethereal power\n";
								}
								
								
								drained[spellChoice] = 1;
								dude[moveGuy].setHealth(dude[moveGuy].getHealth() + damage); //adds life
								
								if (dude[moveGuy].getHealth() > dude[moveGuy].getMaxHealth()) {
									dude[moveGuy].setHealth(dude[moveGuy].getMaxHealth());//keeps it from exceeding max health
								}
								
								cout << epithet(moveGuy) << " gains " << damage << " health, and is ";
								cout << "now at " << dude[moveGuy].getHealth() << " health.\n";
								
							}	
							else {
								cout << "That corpse has already been drained.\n";
							}
						}
						else {
							cout << "\nThey are not in range\n";
						}		
				}
			}
		else if (confirmation == 1 && deadCount == 0) {
			cout << "There are no corpses for you to drain.\n\n";
		}
			
			return;
		
			
		
	}
}

void Throw() {
	if (dude[moveGuy].getAp() > 0) {
		if (throwCoolDown[moveGuy] == 0) {
			
			throwing = 1;
			
			attack();
			
			throwing = 0;
			
			if (!usedSpecial) {//says they used it
				throwCoolDown[moveGuy] = 3;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;		
}

void bound() {
	//thumper of bounding
	int xmove, ymove;
	if (dude[moveGuy].getAp() > 0) {
		if (boundCoolDown[moveGuy] == 0) {
			
			range = 4;//sets range for the map to use
			showMapRange(); //displays the map
			
			cout << "Where do you want to bound to?\n";
			cin >> xmove;
			cout << endl;
			cin >> ymove;
			cout << endl;
			
			int distanceSquared = (xmove * xmove) + (ymove * ymove);
			
			int heightBounder = mainMap.getGridElevation(dude[moveGuy].getXpos(),dude[moveGuy].getYpos());
			int heightTarget = mainMap.getGridElevation(dude[moveGuy].getXpos() + xmove,dude[moveGuy].getYpos()) + ymove;
			int heightDifferenceSquared = (heightTarget-heightBounder)*(heightTarget-heightBounder);
			if (heightBounder > heightTarget) {//makes the height difference negative if you are higher
				heightDifferenceSquared = heightDifferenceSquared * -1/2;
			}
			
			int newXpos = dude[moveGuy].getXpos() + xmove;
			int newYpos = dude[moveGuy].getYpos() + ymove;
			
			if (mainMap.getGridPassable(newXpos,newYpos) == 0 && newXpos > 0 && newYpos > 0 && newXpos < 25 && newYpos < 50) {//if no one is there, and on the map
				if (16 >= distanceSquared + heightDifferenceSquared) {//checks range

					mainMap.setGridPlayer(newXpos,newYpos,moveGuy); //draws the person number on the map
					mainMap.setGridPlayer(dude[moveGuy].getXpos(),dude[moveGuy].getYpos(),0);//deletes old class initial
											
					
					cout << epithet(moveGuy) << " bounds to (" << newXpos << "," << newYpos << ")\n\n";
					
					dude[moveGuy].setXpos(newXpos);
					dude[moveGuy].setYpos(newYpos); //saves the new location for the player
					boundCoolDown[moveGuy] = 3;
						
					return;
				}
				else {
					cout << "You can't bound that far\n";
					bound();
				}
			}
			else { //if something is there, just redoes it
				cout << "You can't bound onto that spot\n";
				bound();
				
			}
		
			
			boundCoolDown[moveGuy] = 3;
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;		
}


void rage() {
	int spellChoice = 0;
		
			cout << "You have " << dude[moveGuy].getHealth() << " health, do you want to lose " << dude[moveGuy].getMaxHealth() / 8 << " health to increase attack by ";
			cout << dude[moveGuy].getAttack()/4 << "?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice == 1) {
				rageDamage = dude[moveGuy].getAttack()/4;
				attack();
				rageDamage = 0;
				
				cout << "Because of their rage " << dude[moveGuy].getName() << " went from " << dude[moveGuy].getHealth() << " health to ";
				dude[moveGuy].setHealth(dude[moveGuy].getHealth() - dude[moveGuy].getMaxHealth() / 8);
				cout << dude[moveGuy].getHealth() << " health ";
				
				if (dude[moveGuy].getHealth() <= 0) {
					cout << "and died";
				}
					cout << endl << endl;
				
			}
		
}

void berserkerSkills() {
	int spellChoice = 0;
	
		if (dude[moveGuy].getRenown() == 401) {
			cout << "Do you want to unleash your rage?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				rage();
			}
		}
		if (dude[moveGuy].getParagon() == 4012) {
			cout << "Do you want to throw someone?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				Throw();
			}
		}
		
		if (dude[moveGuy].getParagon() == 4021) {
			cout << "Do you want to bound in the air?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				bound();
			}
		}
		
	return;
	
}

void cripple() {
	//assassin of incapacitation
	if (dude[moveGuy].getAp() > 0) {
		if (crippleCoolDown[moveGuy] == 0) {
			
			
				crippling = 1;
				attack();
				crippling = 0;
				
			if (!usedSpecial) {//says they used it
				crippleCoolDown[moveGuy] = 2;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;
}


void backstab() {
	if (dude[moveGuy].getAp() > 0) {
		if (backstabCoolDown[moveGuy] == 0) {
			
			
				backstabbing = 1;
				attack();
				backstabbing = 0;
				
			if (!usedSpecial) {//says they used it
				backstabCoolDown[moveGuy] = 2;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;
}

void daze() {//regular attack, makes the enemy lose 6 ap if it hits
	if (dude[moveGuy].getAp() > 0) {
		if (dazeCoolDown[moveGuy] == 0) {
			
			
				dazing = 1;
				attack();
				dazing = 0;
				
			if (!usedSpecial) {//says they used it
				dazeCoolDown[moveGuy] = 2;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;		
}

void healingBalm() {
	//ranger of herbs
	int confirmation = 0;
	
	if (healingBalmCoolDown[moveGuy] == 0) {//the cooldown is done
		cout << "Do you want to use your healing balm?\n1:Yes\n2:No\n";
		cin >> confirmation;
		
		if (confirmation == 1) {
			freeMana = 1;//lets them use it for free
			druidHealingBalm();
			healingBalmCoolDown[moveGuy] = 5;
			freeMana = 0;
		}
	}
}

void doubleShot() {
	//mounted archer of split-shot
	if (dude[moveGuy].getAp() > 0) {
		if (doubleShotCoolDown[moveGuy] == 0) {
			
			
				doubleShooting = 1;
				attack();
				doubleShooting = 0;
				
			if (!usedSpecial) {//says they used it
				doubleShotCoolDown[moveGuy] = 3;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	
}

void scoutSkills() {
	int spellChoice = 0;
		if (dude[moveGuy].getRenown() == 602) {
			cout << "Do you want to daze someone?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				daze();
			}
		}
		if (dude[moveGuy].getRenown() == 601) {
			cout << "Do you want to backstab someone?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				backstab();
			}
		}
		if (dude[moveGuy].getParagon() == 6012) {
			cout << "Do you want to do a double shot on two people?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				doubleShot();
			}
		}
		if (dude[moveGuy].getParagon() == 6021) {
			cout << "Do you want to cripple someone?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				cripple();
			}
		}
		if (dude[moveGuy].getParagon() == 6031) {
			cout << "Do you want to use healing balm?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				cripple();
			}
		}
		
	
	return;
}

void aimedShot() {
	if (dude[moveGuy].getAp() >= 12) {
		if (aimedShotCoolDown[moveGuy] == 0) {
			
			
			aimingShot = 1;
			
			attack();
			
			aimingShot = 0;
			
			if (!usedSpecial) {//says they used it
				aimedShotCoolDown[moveGuy] = 2;
				dude[moveGuy].setAp(dude[moveGuy].getAp() - 6);//lowers the ap more
			}
			usedSpecial = 0;
			
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	else {
		cout << "You do not have enough ap to use that this round\n";
	}
	
	return;
}

void piercingShot() {
	//longbowman of piercing
	if (dude[moveGuy].getAp() >= 6) {
		if (piercingShotCoolDown[moveGuy] == 0) {
			
			
			piercing = 1;
			
			attack();
			
			piercing = 0;
			
			if (!usedSpecial) {//says they used it
				piercingShotCoolDown[moveGuy] = 2;
			}
			usedSpecial = 0;
			
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	else {
		cout << "You do not have enough ap to use that this round\n";
	}
	
	return;
}

void archerSkills() {
	int spellChoice = 0;
		if (dude[moveGuy].getRenown() == 201) {
			cout << "Do you want to take the time to do an accurate shot?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				aimedShot();
			}
		}
		if (dude[moveGuy].getParagon() == 2022) {
			cout << "Do you want fire a piercing shot?\n 1:Yes\n 2:No\n";
			cin >> spellChoice;
			if (spellChoice==1) {
				piercingShot();
			}
		}
		
	return;
}

void pushBack() {
	if (dude[moveGuy].getAp() > 0) {
		if (pushBackCoolDown[moveGuy] == 0) {
			
			pushingBack = 1;
			
			attack();
			
			pushingBack = 0;
			
			if (!usedSpecial) {//says they used it
				pushBackCoolDown[moveGuy] = 3;
			}
			usedSpecial = 0;
			
		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;		
}

void axeThrow() {
	
	if (dude[moveGuy].getAp() > 0) {
		if (axeThrowCoolDown[moveGuy] == 0) {
			
			
			throwingAxe = 1;
			
			attack();
			
			throwingAxe = 0;
			if (!usedSpecial) {//says they used it
				axeThrowCoolDown[moveGuy] = 3;
			}
			usedSpecial = 0;

		}
		else {
			cout << "You can't use that again yet\n";
		}
	}
	return;		
}

void fighterSkills() {
	int spellChoice = 0;
	if (dude[moveGuy].getRenown() == 101) {//Tomahawking
		cout << "Do you want to throw an axe?\n 1:Yes\n 2:No\n";
		cin >> spellChoice;
		if (spellChoice == 1) {
			axeThrow();
		}
	}
	if (dude[moveGuy].getRenown() == 102) {//pushback
		cout << "Do you want to shove someone back?\n 1:Yes\n 2:No\n";
		cin >> spellChoice;
		if (spellChoice == 1) {
			pushBack();
		}
	}
	return;
}

void paladinSmite() { //like a normal attack plus d12
	if (dude[moveGuy].getMana() >= 5) {
		dude[moveGuy].setMana(dude[moveGuy].getMana() - 5); //subtracts mana
		
		
		smiteDamage = rd12();
		
		if (dude[moveGuy].getParagon() == 3032) {//paladin of righteousness
			smiteDamage = smiteDamage + rd4();
		}
		
		attack();
		smiteDamage = 0;
		
	}
	else {
		cout << "You do not have the required mana to do this\n";
	}
	return;
}  

void paladinSpells() {
	//paladin or mounted paladin of smiting
	if (dude[moveGuy].getPrestige() == 303 || dude[moveGuy].getParagon() == 5021) {
		while (dude[moveGuy].getAp() > 0) {
			
			int spellChoice = 0;
			cout << "\nYou have " << dude[moveGuy].getMana() << " mana\n";
			cout << "What spell do you want to cast?\n0:None\n1:Basic heal\n mana: 8\n range: 2\n2:Smite\n mana: 5\n range: 1\n";
			
			cin >> spellChoice;
			if (spellChoice == 0) {
				break;
			}
			if (spellChoice == 1) {
				
				priestHeal();
				}
			if (spellChoice == 2) {
				paladinSmite();
			}

		}

	}	
	return;
}
  
int teamKillXP(int team) {
	int i=0, j=0, totalXP = 0;
	
	if (team == 2) {//how much xp worth of team 1 did they kill
		for ( i = 1; i <= teamSize1; i++ ){
			//if they are dead
			if (dude[i].getHealth() <= 0) {
				//running total + current xp + geometric sum for level a*n+(b*n(n+1)/2)
				totalXP = totalXP + dude[i].getXp() + 50*dude[i].getLevel() + 30*dude[i].getLevel()*(1+dude[i].getLevel())/2;
			}
			
			//if they are alive
			else {
				//running total + (fraction of health lost) * (current xp + geometric sum for level a*n+(b*n(n+1)/2))
				totalXP = totalXP + (100*(dude[i].getMaxHealth() - dude[i].getHealth())/dude[i].getMaxHealth()) * (dude[i].getXp() + 50*dude[i].getLevel() + 30*dude[i].getLevel()*(1+dude[i].getLevel())/2)/100;
			}
		}
	}
	if (team == 1) {//how much xp worth of team 2 did they kill
		for ( j = teamSize1 + 1; j <= teamSize2 + teamSize1; j++ ){
			//if they are dead
			if (dude[j].getHealth() <= 0) {
				//running total + current xp + geometric sum for level a*n+(b*n(n+1)/2)
				totalXP = totalXP + dude[j].getXp() + 50*dude[j].getLevel() + 30*dude[j].getLevel()*(1+dude[j].getLevel())/2;
				
			}
			
			//if they are alive
			else {
				//running total + (fraction of health lost) * (current xp + geometric sum for level a*n+(b*n(n+1)/2))
				totalXP = totalXP + (100*(dude[j].getMaxHealth() - dude[j].getHealth())/dude[j].getMaxHealth()) * (dude[j].getXp() + 50*dude[j].getLevel() + 30*dude[j].getLevel()*(1+dude[j].getLevel())/2)/100;
				
			}
		}
	}
	
	return(totalXP);
	
}
 
//checks if one team is all dead, then congratulates the winner, doles out gold,
bool checkWin() {
	bool ended = 0;
	int answer = 0;
	int winnerMoney = 0,loserMoney = 0;
	int team1dead = 1, team2dead = 1;//assumes dead, and if anyone is alive, it changes it
	
	int i;
	
	for ( i = 1; i <= teamSize1; i++ ) {
		if (dude[i].getHealth() > 0) {
			team1dead = 0;
		}
	}
	for ( i = teamSize1 + 1; i <= teamSize1 + teamSize2; i++ ) {
		if (dude[i].getHealth() > 0) {
			team2dead = 0;
		}
	}
	
	
	if (team1dead && team2dead){
		ended = 1;
		winningTeam = 0;
		cout << teamNames[1] << " and " << teamNames[2] << " both fought valiently, and in the end they were equals\n\n";
		
		if (army1[0]) {
			army1[6] = army1[6] + 1;
			army1[7] = 0;
			armyGainMoney(1,125 + teamKillXP(1)/10);
		}
		if (army2[0]) {
			army2[6] = army2[6] + 1;
			army2[7] = 0;
			armyGainMoney(2,125 + teamKillXP(2)/10);
		}
		
		sleep(2);
		cout << "Thanks for playing Ben and Dillon's awesome game\n\n";
		sleep(2);
		cout << "I hope you enjoyed playing it as much as we enjoyed making it for you\n";
		sleep(2);
		cout << "\nDon't steal the credit for making it from us, because no one likes a Manny\n\n";
		sleep(5);
		
		winner= "Tie game between " + teamNames[1] + " and " + teamNames[2];
		
		menuFuncTeam2();
		sleep(5);
		menuFuncTeam1();
		sleep(2);
		running = 0;
		
		savegame();
		
		infodump(); //This'll send out the final game conditions to a text file
	}
	
	else if (team1dead){
	ended = 1;
	winningTeam = 2;
	winner = teamNames[2] + " beat ";
	loser = teamNames[1];
	
	sleep(2);
	cout << teamNames[2] << " is the ultimate champion of the whole world and " << teamNames[1] << " is but a peon\n\n";
	
	if (army2[0]) {
		armyGainMoney(2,250 + teamKillXP(2)/10);
		
		if (army2[7] > 0){//if their current streak is winning
			army2[7]++;
		}
		else if (army2[7] <= 0) {//if their current streak was losing or tied
			army2[7] = 1;
		}
		
		if (army2[7] > army2[8]) {//if current winning streak beats best winning streak
			army2[8] = army2[7];
		}
		
		army2[4]++;
	}
	if (army1[0]) {
		armyGainMoney(1,125 + teamKillXP(1)/10);
		
		if (army1[7] < 0){//if their current streak is losing
			army1[7]--;
		}
		else if (army1[7] >= 0) {//if their current streak was winning or tied
			army1[7] = -1;
		}
		
		if (-(army1[7]) > army1[9]) {//if current losing streak beats worst losing streak
			army1[9] = -(army1[7]);
		}
		
		army1[5]++;
	}
	
	sleep(2);
	cout << "Thanks for playing Ben and Dillon's awesome game\n\n";
	sleep(2);
	cout << "I hope you enjoyed playing it as much as we enjoyed making it for you\n";
	sleep(2);
	cout << "\nDon't steal the credit for making it from us, because no one likes a Manny\n\n";
	sleep(5);
	
	
	menuFuncTeam2();
	sleep(5);
	menuFuncTeam1();
	sleep(2);
	running = 0;
	
	savegame();
	
	infodump(); //This'll send out the final game conditions to a text file
	}


	else if (team2dead){
	ended = 1;
	winningTeam = 1;
	winner = teamNames[1] + " beat ";
	loser = teamNames[2];
	
	sleep(2);
	cout << teamNames[1] << " is the ultimate champion of the whole world and " << teamNames[2] << " is but a peon\n\n";
	
	
	if (army1[0]) {
		armyGainMoney(1,250 + teamKillXP(1)/10);
		
		if (army1[7] > 0){//if their current streak is winning
			army1[7]++;
		}
		else if (army1[7] <= 0) {//if their current streak was losing or tied
			army1[7] = 1;
		}
		
		if (army1[7] > army1[8]) {//if current winning streak beats best winning streak
			army1[8] = army1[7];
		}
		
		army1[4]++;
	}
	if (army2[0]) {
		armyGainMoney(2,125 + teamKillXP(2)/10);
		
		if (army2[7] < 0){//if their current streak is losing
			army2[7]--;
		}
		else if (army2[7] >= 0) {//if their current streak was winning or tied
			army2[7] = -1;
		}
		
		if (-(army2[7]) > army2[9]) {//if current losing streak beats worst losing streak
			army2[9] = -(army2[7]);
		}
		
		army2[5]++;
	}
	
	
	sleep(3);
	cout << "Thanks for playing Ben and Dillon's awesome game\n\n";
	sleep(3);
	cout << "I hope you enjoyed playing it as much as we enjoyed making it for you\n";
	sleep(3);
	cout << "\nDon't steal the credit for making it from us, because no one likes a Manny\n\n";
	sleep(3);
	
	menuFuncTeam1();
	sleep(5);
	menuFuncTeam2();
	sleep(2);
	running = 0;
	
	savegame();
	
	infodump(); //This'll send out the final game conditions to a text file
	
	}
	
	else {
		ended = 0;
	}
	
	return ended;
}
     
//this is the turn function
void turn() {
	int i = 0;

	staggerStartPreCounter[1]++;
	staggerStartPreCounter[2]++;
	if (staggerStartPreCounter[1] > staggerStartPreSpread[1]) {
		staggerStartCounter[1]++;
	}
	if (staggerStartPreCounter[2] > staggerStartPreSpread[2]) {
		staggerStartCounter[2]++;
	}
	turnCounter = turnCounter + 1;
	
	
	for (i=1; i <= teamSize1; i++){ //team1 moves and attacks
		{
				//mobileProblem
				// GUI
				//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene
				//glLoadIdentity();   // reset previous matrix transformations

				//gGameGui.createObjects(map);

				//gGameGui.drawObjects();

				//glFlush();          // send drawing command
				//glutSwapBuffers();  // swap glut buffers
				
				//glutPostRedisplay(); // refresh display
		}
		lichTransformation();
		
		if (dude[i].getHealth() > 0 && i * staggerStartSpread[1] < staggerStartCounter[1]){ //checks if the person is dead and lets them do stuff
			
			damage = 0;
			dude[i].setAp(12); //resets the Ap of the character
			attackTimes[i] = 0;
			moveGuy = i;
			
			
			spellCast[moveGuy] = 0;	//resets whether or not they cast a spell
			moved[moveGuy] = 0; //resets whether or not they moved
			charge[moveGuy] = 0; //resets the charge for the knights
			bullrush[moveGuy] = 0;//resets the bullrush for brawlers
			hold[moveGuy] = 0; //resets the fighter's hold
			defended[moveGuy] = 0; //resets if they are defended by a defender
			if (breathCoolDown[moveGuy] > 0) {
				breathCoolDown[moveGuy] = breathCoolDown[moveGuy] - 1;
			}
			
			if (dazeCoolDown[moveGuy] > 0) {
				dazeCoolDown[moveGuy] = dazeCoolDown[moveGuy] - 1;
			}
			if (backstabCoolDown[moveGuy] > 0) {
				backstabCoolDown[moveGuy] = backstabCoolDown[moveGuy] - 1;
			}
			if (doubleShotCoolDown[moveGuy] > 0) {
				doubleShotCoolDown[moveGuy] = doubleShotCoolDown[moveGuy] - 1;
			}
			if (boundCoolDown[moveGuy] > 0) {
				boundCoolDown[moveGuy] = boundCoolDown[moveGuy] - 1;
			}
			if (crippleCoolDown[moveGuy] > 0) {
				crippleCoolDown[moveGuy] = crippleCoolDown[moveGuy] - 1;
			}
			if (pushBackCoolDown[moveGuy] > 0) {
				pushBackCoolDown[moveGuy] = pushBackCoolDown[moveGuy] - 1;
			}
			if (axeThrowCoolDown[moveGuy] > 0) {
				axeThrowCoolDown[moveGuy] = axeThrowCoolDown[moveGuy] - 1;
			}
			if (earthQuakeCoolDown[moveGuy] > 0) {
				earthQuakeCoolDown[moveGuy] = earthQuakeCoolDown[moveGuy] - 1;
			}
			
			
			
			miraculous();
			
			int manaRegenAmount = dude[moveGuy].getManaRegen();
			if (dude[moveGuy].getIsArcane() && !( dude[moveGuy].getIsDivine() ) ) {
				manaRegenAmount = manaRegenAmount * (mainMap.getGridArcane(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) + 100) / 100;
			}
			else if (dude[moveGuy].getIsDivine() && !( dude[moveGuy].getIsArcane() )) {
				manaRegenAmount = manaRegenAmount * (mainMap.getGridDivine(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) + 100) / 100;
			}
			else if (dude[moveGuy].getIsDivine() && dude[moveGuy].getIsArcane()) {
				manaRegenAmount = manaRegenAmount * (mainMap.getGridDivine(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) + 100) / 200;
				manaRegenAmount = manaRegenAmount * (mainMap.getGridArcane(dude[moveGuy].getXpos(),dude[moveGuy].getYpos()) + 100) / 200;
			}
			
			
			dude[moveGuy].setMana(dude[moveGuy].getMana() + manaRegenAmount); //adds the regen amount to the current of mana
			if(dude[moveGuy].getCharacterClass() == 8) {//if they are a warlock
				int randomRegen = rd4();
				if (randomRegen == 1) {
					dude[moveGuy].setMana(dude[moveGuy].getMana() - dude[moveGuy].getManaRegen() / 2);//subtracts half their mana regen
				}
				if (randomRegen == 2) {
					dude[moveGuy].setMana(dude[moveGuy].getMana() + dude[moveGuy].getManaRegen() / 2);//adds half their mana regen
				}
				
				
			}
			
			
			if (dude[moveGuy].getMana() > dude[moveGuy].getMaxMana()) { // stops it from going over mana cap
					dude[moveGuy].setMana(dude[moveGuy].getMaxMana());
				}
			
			//does poison and healing balm
			poisonDamages();
			//does burn and healing
			burnDamages();
			
			if (protectRangedTimer[moveGuy] > 0) {//lowers the protect ranged timer
				protectRangedTimer[moveGuy]--;
			}
			
			if (shieldTimer[moveGuy] > 0) {//lowers the shield timer
				shieldTimer[moveGuy]--;
			}
			
			if (dazed[i] > 0) {//if they are dazed they lose 6 ap
				dude[i].setAp(dude[i].getAp() - 6);
				dazed[i]--;
			}
			
			//this is where each individual character's turn takes place
			while (dude[i].getAp() > 0) { //checks if they still have Ap

			levelUp();
			int choice = 0;
			
			{
				//mobileproblem
				// GUI
				/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene
				glLoadIdentity();   // reset previous matrix transformations

				gGameGui.createObjects(map);

				gGameGui.drawObjects();

				glFlush();          // send drawing command
				glutSwapBuffers();  // swap glut buffers
				
				glutPostRedisplay(); // refresh display
				*/
			}
			cout << endl << epithet(moveGuy) << " what would you like to do?\n1:Move\n2:Attack\n3:Use abilities\n0:End turn\n\n";
            cin >> choice;
			
			if (choice == 1) {move();}
			else if (choice == 2) {attack();}
			else if (choice == 3) {priestSpells(); mageSpells(); clericSpells(); mageSpellsArcaneSummoner();
			mageSpellsFire(); mageSpellsWater();acolyteSpells(); paladinSpells(); goblinMageSpells();
			goblinPriestSpells(); warlockSpells(); druidSpells(); necromancerSpells(); spellswordSpells();dragonSpawnBreath(); vampireDrain();
			scoutSkills(); berserkerSkills(); fighterSkills(); archerSkills(); checkForSiegeWeapon();}
			else if(choice == 11) menuFuncPlayer1();
			else if(choice == 22) menuFuncPlayer2();
			else if(choice == 33) showMap();
			else if(choice == 34) showMapValuesMenu();
			else if(choice == 35) inquireSquare();
			else if (choice == 0) dude[i].setAp(0);
			levelUp();
			
		}
		
			if (haste[moveGuy] > 0) { //lowers the haste counter
				haste[moveGuy]--; 
			}
			else if (haste[moveGuy] < 0) { //lowers the slow counter
				haste[moveGuy]++;
			}
			if (bless[moveGuy] > 0) { //lowers the bless counter
				bless[moveGuy]--; 
			}
			else if (bless[moveGuy] < 0) { //lowers the curse counter
				bless[moveGuy]++;
			}
			

	
	checkDefend();	
	firstTurn[moveGuy] = 0;//says it is no longer the first turn for this person	
	}
}
	
	for (i = teamSize1 + 1; i <= teamSize2 + teamSize1; i++ ) //team2 moves and attacks
	{
		{
				//mobileproblem
				// GUI
				/*
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene
				glLoadIdentity();   // reset previous matrix transformations

				gGameGui.createObjects(map);

				gGameGui.drawObjects();

				glFlush();          // send drawing command
				glutSwapBuffers();  // swap glut buffers
				
				glutPostRedisplay(); // refresh display
				*/
			}
			
		lichTransformation();

		if (dude[i].getHealth() > 0 && (i-teamSize1) * staggerStartSpread[2] < staggerStartCounter[2]) //checks if the person is dead and lets them do stuff, also checks if they have started in a stagger start
		{
		damage = 0;
		dude[i].setAp(12); //resets the Ap of the character
		attackTimes[i] = 0;
		moveGuy = i;
		

			spellCast[moveGuy] = 0;	//resets whether or not they cast a spell
			moved[moveGuy] = 0; //resets whether or not they moved
			charge[moveGuy] = 0; //resets the charge for the knights
			bullrush[moveGuy] = 0; //resets the bullrush for the brawlers
			hold[moveGuy] = 0; //resets the fighter's hold
 			defended[moveGuy] = 0; //resets if they are defended by a defender
			if (breathCoolDown[moveGuy] > 0) {
				breathCoolDown[moveGuy] = breathCoolDown[moveGuy] - 1;
			}
			
			if (dazeCoolDown[moveGuy] > 0) {
				dazeCoolDown[moveGuy] = dazeCoolDown[moveGuy] - 1;
			}
			if (backstabCoolDown[moveGuy] > 0) {
				backstabCoolDown[moveGuy] = backstabCoolDown[moveGuy] - 1;
			}
			if (doubleShotCoolDown[moveGuy] > 0) {
				doubleShotCoolDown[moveGuy] = doubleShotCoolDown[moveGuy] - 1;
			}
			if (boundCoolDown[moveGuy] > 0) {
				boundCoolDown[moveGuy] = boundCoolDown[moveGuy] - 1;
			}
			if (crippleCoolDown[moveGuy] > 0) {
				crippleCoolDown[moveGuy] = crippleCoolDown[moveGuy] - 1;
			}
			if (pushBackCoolDown[moveGuy] > 0) {
				pushBackCoolDown[moveGuy] = pushBackCoolDown[moveGuy] - 1;
			}
			if (axeThrowCoolDown[moveGuy] > 0) {
				axeThrowCoolDown[moveGuy] = axeThrowCoolDown[moveGuy] - 1;
			}
			if (earthQuakeCoolDown[moveGuy] > 0) {
				earthQuakeCoolDown[moveGuy] = earthQuakeCoolDown[moveGuy] - 1;
			}
			
			miraculous();
			
			dude[moveGuy].setMana(dude[moveGuy].getMana() + dude[moveGuy].getManaRegen()); // adds their regen to their current mana
			
			if (dude[moveGuy].getMana() > dude[moveGuy].getMaxHealth()) { // stops it from going over mana cap
					dude[moveGuy].setMana(dude[moveGuy].getMaxMana());
				}
			
			//does poison and healing balm
			poisonDamages();
			//does burn and freezing damage
			burnDamages();
			
			if (protectRangedTimer[moveGuy] > 0) {//lowers the protect ranged timer
				protectRangedTimer[moveGuy]--;
			}
			
			if (shieldTimer[moveGuy] > 0) {//lowers the shield timer
				shieldTimer[moveGuy]--;
			}

			if (dazed[i] > 0) {//if they are dazed they lose 6 ap
				dude[i].setAp(dude[i].getAp() - 6);
				dazed[i]--;
			}
			
			while (dude[i].getAp() > 0) { //checks if they still have Ap
			levelUp();
			int choice = 0;
			cout << endl << epithet(moveGuy) << " what would you like to do?\n1:Move\n2:Attack\n3:Use abilities\n0:End turn\n\n";
            cin >> choice;
			
			if (choice == 1) {move();}
			else if (choice == 2) {attack();}
			else if (choice == 3) {priestSpells(); mageSpells(); clericSpells(); mageSpellsArcaneSummoner();
			mageSpellsFire(); mageSpellsWater(); acolyteSpells(); paladinSpells(); goblinMageSpells();
			goblinPriestSpells(); warlockSpells(); druidSpells();necromancerSpells(); spellswordSpells();dragonSpawnBreath(); vampireDrain();
			 scoutSkills(); berserkerSkills(); fighterSkills(); archerSkills(); checkForSiegeWeapon();}
			else if(choice == 11) menuFuncPlayer1();
			else if(choice == 22) menuFuncPlayer2();
			else if(choice == 33) showMap();
			else if(choice == 34) showMapValuesMenu();
			else if(choice == 35) inquireSquare();
			else if (choice == 0) dude[i].setAp(0);
			levelUp();
			
			}
	
			if (haste[moveGuy] > 0) { //lowers the haste counter
				haste[moveGuy]--; 
			}
			else if (haste[moveGuy] < 0) { //lowers the slow counter
				haste[moveGuy]++;
			}
			if (bless[moveGuy] > 0) { //lowers the bless counter
				bless[moveGuy]--; 
			}
			else if (bless[moveGuy] < 0) { //lowers the curse counter
				bless[moveGuy]++;
			}

	
	checkDefend();
	firstTurn[moveGuy] = 0;//says it is no longer the first turn for this person
	}
}

return;
}


void updateGamePlayInTerminal()
{
    bool showMapRightAway = 0;
    if (FAST_START) {
        showMapRightAway = 0;
    }

    while(running)
    {
        

            if(showMapRightAway) {
                showMap();
                showMapRightAway = 0;
            }

            cout << "\n\nWhat will you do for the next round of turns?\n 1:Commence with attacks and such\n 11:" << teamNames[1] << "'s menu\n 22:";
            cout << teamNames[2]<< "'s menu\n 33:Display map\n 34:Display map values\n 0:Exit the Game\n\n";

            cin >> userInput; // 11 will open player one's menu, 22 will open player two's menu, 33 will display map, 0 will exit the game, 34 displays elevation map
            if(userInput == 11) menuFuncPlayer1();
            else if(userInput == 22) menuFuncPlayer2();
            else if(userInput == 0) leaveGame();
            else if(userInput == 1) turn();
            else if(userInput == 33) showMap();
            else if(userInput == 34) showMapValuesMenu();
            else if(userInput == 35) inquireSquare();
			lichTransformation();
			if (checkWin() ) {
				running = 0;
			
			}
        }
     exit(0); 
}

int main(int argc, char** argv)
{
	//mobileproblem
    //glutInit(&argc, argv); // initialize glut

    //init();
	srand (time(NULL));
    titleFunc();

    //glutMainLoop(); // run glut loop
	
	//get rid of this if not mobile
	while (running) {
		cout << "\n\nWhat will you do for the next round of turns?\n 1:Commence with attacks and such\n 11:" << teamNames[1] << "'s menu\n 22:";
		cout << teamNames[2]<< "'s menu\n 33:Display map\n 34:Display map values\n 0:Exit the Game\n\n";

		cin >> userInput; // 11 will open player one's menu, 22 will open player two's menu, 33 will display map, 0 will exit the game, 34 displays elevation map
		if(userInput == 11) menuFuncPlayer1();
		else if(userInput == 22) menuFuncPlayer2();
		else if(userInput == 0) leaveGame();
		else if(userInput == 1) turn();
		else if(userInput == 33) showMap();
		else if(userInput == 34) showMapValuesMenu();
		else if(userInput == 35) inquireSquare();
		lichTransformation();
		if (checkWin() ) {
			running = 0;
		}
	}
	
    return 0;
}
