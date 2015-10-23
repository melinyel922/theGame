#include <iostream>
#include "equipment.cpp"
#include "armour.cpp"

using namespace std;


class dude
{	private:
		
		string name;
		string raceName;
		string className;
		string renownName;
		string prestigeName;	
		string prestigeSpecializationName;
		string paragonName;
		string epitomeName;
		string birthRightName;
		int team;//what team they are on
		int characterClass;
		int attack;
		int defense;
		int health;
		int move;
		int range;
		int ap;
		int mana;
		int xpos;
		int ypos;
		int xp;
		int maxHealth;
		int maxMana;
		int manaRegen;
		int level;
		int prestige;
		int race;
		int birthRight;
		int renown;
		int prestigeSpecialization;
		int paragon;
		int epitome;
		int startingMana;
		int missChance;
		int evasion;
		int quickness;
		
		int engineering;
		int heavinessUsage;
		
		int resistFire, resistCold, resistLightning, resistLight, resistDark, resistPoison, resistManaEnergy, resistBludgeoning, resistSlashing, resistPiercing;
		
		bool isArcane;
		bool isDivine;
		
		
		
	
	public:
		
		
		equipment head;
		equipment torso;
		equipment shoulders;
		equipment arms;
		equipment hands;
		equipment legs;
		equipment feet;
		equipment rightHand;
		equipment leftHand;
		equipment inventory[100];
		
		
		
		dude(): name(), team(0), characterClass(0), attack(0), defense(0), health(0), move(0), range(0), ap(0), mana(0), xpos(0), ypos(0), xp(0), maxHealth(0), maxMana(0), manaRegen(0), level(0), prestige(0), race(0), birthRight(0), renown(0), prestigeSpecialization(0), paragon(0), epitome(0), startingMana(0), missChance(0), evasion(0), quickness(0), isArcane(false), isDivine(false), engineering(0), heavinessUsage(0), resistFire(0), resistCold(0), resistLightning(0), resistLight(0), resistDark(0), resistPoison(0), resistManaEnergy(0), resistBludgeoning(0), resistSlashing(0), resistPiercing(0) { 
			for (int x = 0; x < 100; x++) {
				inventory[x].makeNull();
			}
			head.makeNull();
			torso.makeNull();
			shoulders.makeNull();
			arms.makeNull();
			hands.makeNull();
			legs.makeNull();
			feet.makeNull();
			rightHand.makeNull();
			leftHand.makeNull();
		}
		
		int addUpEquipmentStats(string statType) {
			int total = 0;
		
			if (statType ==  "resistFire") {
				total += head.getEquipmentResistFire();
				total += torso.getEquipmentResistFire();
				total += shoulders.getEquipmentResistFire();
				total += arms.getEquipmentResistFire();
				total += hands.getEquipmentResistFire();
				total += legs.getEquipmentResistFire();
				total += feet.getEquipmentResistFire();
				total += rightHand.getEquipmentResistFire();
				total += leftHand.getEquipmentResistFire();
			}
			else if (statType == "resistCold") {
				total += head.getEquipmentResistCold();
				total += torso.getEquipmentResistCold();
				total += shoulders.getEquipmentResistCold();
				total += arms.getEquipmentResistCold();
				total += hands.getEquipmentResistCold();
				total += legs.getEquipmentResistCold();
				total += feet.getEquipmentResistCold();
				total += rightHand.getEquipmentResistCold();
				total += leftHand.getEquipmentResistCold();
			}
			else if (statType == "resistLightning") {
				total += head.getEquipmentResistLightning();
				total += torso.getEquipmentResistLightning();
				total += shoulders.getEquipmentResistLightning();
				total += arms.getEquipmentResistLightning();
				total += hands.getEquipmentResistLightning();
				total += legs.getEquipmentResistLightning();
				total += feet.getEquipmentResistLightning();
				total += rightHand.getEquipmentResistLightning();
				total += leftHand.getEquipmentResistLightning();
			}
			else if (statType == "resistLight") {
				total += head.getEquipmentResistLight();
				total += torso.getEquipmentResistLight();
				total += shoulders.getEquipmentResistLight();
				total += arms.getEquipmentResistLight();
				total += hands.getEquipmentResistLight();
				total += legs.getEquipmentResistLight();
				total += feet.getEquipmentResistLight();
				total += rightHand.getEquipmentResistLight();
				total += leftHand.getEquipmentResistLight();
			}
			else if (statType == "resistDark") {
				total += head.getEquipmentResistDark();
				total += torso.getEquipmentResistDark();
				total += shoulders.getEquipmentResistDark();
				total += arms.getEquipmentResistDark();
				total += hands.getEquipmentResistDark();
				total += legs.getEquipmentResistDark();
				total += feet.getEquipmentResistDark();
				total += rightHand.getEquipmentResistDark();
				total += leftHand.getEquipmentResistDark();
			}
			else if (statType == "resistPoison") {
				total += head.getEquipmentResistPoison();
				total += torso.getEquipmentResistPoison();
				total += shoulders.getEquipmentResistPoison();
				total += arms.getEquipmentResistPoison();
				total += hands.getEquipmentResistPoison();
				total += legs.getEquipmentResistPoison();
				total += feet.getEquipmentResistPoison();
				total += rightHand.getEquipmentResistPoison();
				total += leftHand.getEquipmentResistPoison();
			}
			else if (statType == "resistManaEnergy") {
				total += head.getEquipmentResistManaEnergy();
				total += torso.getEquipmentResistManaEnergy();
				total += shoulders.getEquipmentResistManaEnergy();
				total += arms.getEquipmentResistManaEnergy();
				total += hands.getEquipmentResistManaEnergy();
				total += legs.getEquipmentResistManaEnergy();
				total += feet.getEquipmentResistManaEnergy();
				total += rightHand.getEquipmentResistManaEnergy();
				total += leftHand.getEquipmentResistManaEnergy();
			}
			else if (statType == "resistBludgeoning") {
				total += head.getEquipmentResistBludgeoning();
				total += torso.getEquipmentResistBludgeoning();
				total += shoulders.getEquipmentResistBludgeoning();
				total += arms.getEquipmentResistBludgeoning();
				total += hands.getEquipmentResistBludgeoning();
				total += legs.getEquipmentResistBludgeoning();
				total += feet.getEquipmentResistBludgeoning();
				total += rightHand.getEquipmentResistBludgeoning();
				total += leftHand.getEquipmentResistBludgeoning();
			}
			else if (statType == "resistSlashing") {
				total += head.getEquipmentResistSlashing();
				total += torso.getEquipmentResistSlashing();
				total += shoulders.getEquipmentResistSlashing();
				total += arms.getEquipmentResistSlashing();
				total += hands.getEquipmentResistSlashing();
				total += legs.getEquipmentResistSlashing();
				total += feet.getEquipmentResistSlashing();
				total += rightHand.getEquipmentResistSlashing();
				total += leftHand.getEquipmentResistSlashing();
			}
			else if (statType == "resistPiercing") {
				total += head.getEquipmentResistPiercing();
				total += torso.getEquipmentResistPiercing();
				total += shoulders.getEquipmentResistPiercing();
				total += arms.getEquipmentResistPiercing();
				total += hands.getEquipmentResistPiercing();
				total += legs.getEquipmentResistPiercing();
				total += feet.getEquipmentResistPiercing();
				total += rightHand.getEquipmentResistPiercing();
				total += leftHand.getEquipmentResistPiercing();
			}
			else if (statType == "damageFire") {
				total += head.getEquipmentDamageFire();
				total += torso.getEquipmentDamageFire();
				total += shoulders.getEquipmentDamageFire();
				total += arms.getEquipmentDamageFire();
				total += hands.getEquipmentDamageFire();
				total += legs.getEquipmentDamageFire();
				total += feet.getEquipmentDamageFire();
				total += rightHand.getEquipmentDamageFire();
				total += leftHand.getEquipmentDamageFire();
			}
			else if (statType == "damageCold") {
				total += head.getEquipmentDamageCold();
				total += torso.getEquipmentDamageCold();
				total += shoulders.getEquipmentDamageCold();
				total += arms.getEquipmentDamageCold();
				total += hands.getEquipmentDamageCold();
				total += legs.getEquipmentDamageCold();
				total += feet.getEquipmentDamageCold();
				total += rightHand.getEquipmentDamageCold();
				total += leftHand.getEquipmentDamageCold();
			}
			else if (statType == "damageLightning") {
				total += head.getEquipmentDamageLightning();
				total += torso.getEquipmentDamageLightning();
				total += shoulders.getEquipmentDamageLightning();
				total += arms.getEquipmentDamageLightning();
				total += hands.getEquipmentDamageLightning();
				total += legs.getEquipmentDamageLightning();
				total += feet.getEquipmentDamageLightning();
				total += rightHand.getEquipmentDamageLightning();
				total += leftHand.getEquipmentDamageLightning();
			}
			else if (statType == "damageLight") {
				total += head.getEquipmentDamageLight();
				total += torso.getEquipmentDamageLight();
				total += shoulders.getEquipmentDamageLight();
				total += arms.getEquipmentDamageLight();
				total += hands.getEquipmentDamageLight();
				total += legs.getEquipmentDamageLight();
				total += feet.getEquipmentDamageLight();
				total += rightHand.getEquipmentDamageLight();
				total += leftHand.getEquipmentDamageLight();
			}
			else if (statType == "damageDark") {
				total += head.getEquipmentDamageDark();
				total += torso.getEquipmentDamageDark();
				total += shoulders.getEquipmentDamageDark();
				total += arms.getEquipmentDamageDark();
				total += hands.getEquipmentDamageDark();
				total += legs.getEquipmentDamageDark();
				total += feet.getEquipmentDamageDark();
				total += rightHand.getEquipmentDamageDark();
				total += leftHand.getEquipmentDamageDark();
			}
			else if (statType == "damagePoison") {
				total += head.getEquipmentDamagePoison();
				total += torso.getEquipmentDamagePoison();
				total += shoulders.getEquipmentDamagePoison();
				total += arms.getEquipmentDamagePoison();
				total += hands.getEquipmentDamagePoison();
				total += legs.getEquipmentDamagePoison();
				total += feet.getEquipmentDamagePoison();
				total += rightHand.getEquipmentDamagePoison();
				total += leftHand.getEquipmentDamagePoison();
			}
			else if (statType == "damageManaEnergy") {
				total += head.getEquipmentDamageManaEnergy();
				total += torso.getEquipmentDamageManaEnergy();
				total += shoulders.getEquipmentDamageManaEnergy();
				total += arms.getEquipmentDamageManaEnergy();
				total += hands.getEquipmentDamageManaEnergy();
				total += legs.getEquipmentDamageManaEnergy();
				total += feet.getEquipmentDamageManaEnergy();
				total += rightHand.getEquipmentDamageManaEnergy();
				total += leftHand.getEquipmentDamageManaEnergy();
			}
			else if (statType == "damageBludgeoning") {
				total += head.getEquipmentDamageBludgeoning();
				total += torso.getEquipmentDamageBludgeoning();
				total += shoulders.getEquipmentDamageBludgeoning();
				total += arms.getEquipmentDamageBludgeoning();
				total += hands.getEquipmentDamageBludgeoning();
				total += legs.getEquipmentDamageBludgeoning();
				total += feet.getEquipmentDamageBludgeoning();
				total += rightHand.getEquipmentDamageBludgeoning();
				total += leftHand.getEquipmentDamageBludgeoning();
			}
			else if (statType == "damageSlashing") {
				total += head.getEquipmentDamageSlashing();
				total += torso.getEquipmentDamageSlashing();
				total += shoulders.getEquipmentDamageSlashing();
				total += arms.getEquipmentDamageSlashing();
				total += hands.getEquipmentDamageSlashing();
				total += legs.getEquipmentDamageSlashing();
				total += feet.getEquipmentDamageSlashing();
				total += rightHand.getEquipmentDamageSlashing();
				total += leftHand.getEquipmentDamageSlashing();
			}
			else if (statType == "damagePiercing") {
				total += head.getEquipmentDamagePiercing();
				total += torso.getEquipmentDamagePiercing();
				total += shoulders.getEquipmentDamagePiercing();
				total += arms.getEquipmentDamagePiercing();
				total += hands.getEquipmentDamagePiercing();
				total += legs.getEquipmentDamagePiercing();
				total += feet.getEquipmentDamagePiercing();
				total += rightHand.getEquipmentDamagePiercing();
				total += leftHand.getEquipmentDamagePiercing();
			}
			else if (statType == "baseAttack") {
				total += head.getEquipmentBaseAttack();
				total += torso.getEquipmentBaseAttack();
				total += shoulders.getEquipmentBaseAttack();
				total += arms.getEquipmentBaseAttack();
				total += hands.getEquipmentBaseAttack();
				total += legs.getEquipmentBaseAttack();
				total += feet.getEquipmentBaseAttack();
				total += rightHand.getEquipmentBaseAttack();
				total += leftHand.getEquipmentBaseAttack();
			}
			else if (statType == "missChance") {
				//flipped because accuracy instead of misschance
				total -= head.getAccuracy();
				total -= torso.getAccuracy();
				total -= shoulders.getAccuracy();
				total -= arms.getAccuracy();
				total -= hands.getAccuracy();
				total -= legs.getAccuracy();
				total -= feet.getAccuracy();
				total -= rightHand.getAccuracy();
				total -= leftHand.getAccuracy();
			}
			else if (statType == "toHit") {
				total += head.getToHit();
				total += torso.getToHit();
				total += shoulders.getToHit();
				total += arms.getToHit();
				total += hands.getToHit();
				total += legs.getToHit();
				total += feet.getToHit();
				total += rightHand.getToHit();
				total += leftHand.getToHit();
			}
			else if (statType == "evasion") {
				total += head.getEvasion();
				total += torso.getEvasion();
				total += shoulders.getEvasion();
				total += arms.getEvasion();
				total += hands.getEvasion();
				total += legs.getEvasion();
				total += feet.getEvasion();
				total += rightHand.getEvasion();
				total += leftHand.getEvasion();
			}
			else if (statType == "quickness") {
				total += head.getQuickness();
				total += torso.getQuickness();
				total += shoulders.getQuickness();
				total += arms.getQuickness();
				total += hands.getQuickness();
				total += legs.getQuickness();
				total += feet.getQuickness();
				total += rightHand.getQuickness();
				total += leftHand.getQuickness();
			}
			else if (statType == "attack") {
				total += head.getToHit();
				total += torso.getToHit();
				total += shoulders.getToHit();
				total += arms.getToHit();
				total += hands.getToHit();
				total += legs.getToHit();
				total += feet.getToHit();
				total += rightHand.getToHit();
				total += leftHand.getToHit();
			}
			
			
			return total;
		}
		
		string getName() {return name;}
		void setName(string Name) {name = Name;}
		string getRaceName() {return raceName;}
		void setRaceName(string RaceName) {raceName = RaceName;}
		string getCharacterClassName() {return className;}
		void setClassName(string ClassName) {className = ClassName;}
		string getRenownName() {return renownName;}
		void setRenownName(string RenownName) {renownName = RenownName;}
		string getPrestigeName() {return prestigeName;}
		void setPrestigeName(string PrestigeName) {prestigeName = PrestigeName;}
		string getPrestigeSpecializationName() {return prestigeSpecializationName;}
		void setPrestigeSpecializationName(string PrestigeSpecializationName) {prestigeSpecializationName = PrestigeSpecializationName;}
		string getParagonName() {return paragonName;}
		void setParagonName(string ParagonName) {paragonName = ParagonName;}
		string getEpitomeName() {return epitomeName;}
		void setEpitomeName(string EpitomeName) {epitomeName = EpitomeName;}
		string getBirthRightName() {return birthRightName;}
		void setBirthRightName(string BirthRightName) {birthRightName = BirthRightName;}


		int getTeam() {return team;}
		void setTeam(int Team) {team = Team;}
		
		int getCharacterClass() {return characterClass;}
		void setCharacterClass(int CharacterClass) {characterClass = CharacterClass;}
		
		int getAttack() {return attack + addUpEquipmentStats("attack");}
		int getAttackStat() {return attack;}
		void setAttack(int Attack) {attack = Attack;}
		
		int getDefense() {return defense + addUpEquipmentStats("defense");}
		int getDefenseStat() {return defense;}
		void setDefense(int Defense) {defense = Defense;}
		
		int getHealth() {return health;}
		void setHealth(int Health) {health = Health;}
		
		int getMove() {return move + addUpEquipmentStats("move");}
		int getMoveStat() {return move;}
		void setMove(int Move) {move = Move;}
		
		int getRange() {return range + addUpEquipmentStats("range");}
		int getRangeStat() {return range;}
		void setRange(int Range) {range = Range;}
		
		int getAp() {return ap;}
		void setAp(int Ap) {ap = Ap;}
		
		int getMana() {return mana;}
		void setMana(int Mana) {mana = Mana;}
		
		int getXpos() {return xpos;}
		void setXpos(int Xpos) {xpos = Xpos;}
		
		int getYpos() {return ypos;}
		void setYpos(int Ypos) {ypos = Ypos;}
		
		int getXp() {return xp;}
		void setXp(int Xp) {xp = Xp;}
		
		int getMaxHealth() {return maxHealth + addUpEquipmentStats("maxHealth");}
		int getMaxHealthStat() {return maxHealth;}
		void setMaxHealth(int MaxHealth) {maxHealth = MaxHealth;}
		
		int getMaxMana() {return maxMana + addUpEquipmentStats("maxMana");}
		int getMaxManaStat() {return maxMana;}
		void setMaxMana(int MaxMana) {maxMana = MaxMana;}
		
		int getManaRegen() {return manaRegen + addUpEquipmentStats("manaRegen");}
		int getManaRegenStat() {return manaRegen;}
		void setManaRegen(int ManaRegen) {manaRegen = ManaRegen;}
		
		int getLevel() {return level;}
		void setLevel(int Level) {level = Level;}
		
		int getPrestige() {return prestige;}
		void setPrestige(int Prestige) {prestige = Prestige;}
		
		int getRace() {return race;}
		void setRace(int Race) {race = Race;}
		
		int getBirthRight() {return birthRight;}
		void setBirthRight(int BirthRight) {birthRight = BirthRight;}
		
		int getRenown() {return renown;}
		void setRenown(int Renown) {renown = Renown;}
		
		int getPrestigeSpecialization() {return prestigeSpecialization;}
		void setPrestigeSpecialization(int PrestigeSpecialization) {prestigeSpecialization = PrestigeSpecialization;}
		
		int getParagon() {return paragon;}
		void setParagon(int Paragon) {paragon = Paragon;}
		
		int getEpitome() {return epitome;}
		void setEpitome(int Epitome) {epitome = Epitome;}
		
		int getStartingMana() {return startingMana + addUpEquipmentStats("startingMana");}
		int getStartingManaStat() {return startingMana;}
		void setStartingMana(int StartingMana) {startingMana = StartingMana;}
		
		int getMissChance() {return missChance + addUpEquipmentStats("missChance");}
		int getMissChanceStat() {return missChance;}
		void setMissChance(int MissChance) {missChance = MissChance;}
		
		int getEvasion() {return evasion + addUpEquipmentStats("evasion");}
		int getEvasionStat() {return evasion;}
		void setEvasion(int Evasion) {evasion = Evasion;}
		
		int getQuickness() {return quickness + addUpEquipmentStats("quickness");}
		int getQuicknessStat() {return quickness;}
		void setQuickness(int Quickness) {quickness = Quickness;}
		
		int getEngineering() {return engineering + addUpEquipmentStats("engineering");}
		int getEngineeringStat() {return engineering;}
		void setEngineering(int Engineering) {engineering = Engineering;}
		
		int getHeavinessUsage() {return heavinessUsage + addUpEquipmentStats("heavinessUsage");}
		int getHeavinessUsageStat() {return heavinessUsage;}
		void setHeavinessUsage(int HeavinessUsage) {heavinessUsage = HeavinessUsage;}


		int getResistFire() {return resistFire + addUpEquipmentStats("resistFire");}
		int getResistFireStat() {return resistFire;}
		void setResistFire(int ResistFire) {resistFire = ResistFire;}
		
		int getResistCold() {return resistCold + addUpEquipmentStats("resistCold");}
		int getResistColdStat() {return resistCold;}
		void setResistCold(int ResistCold) {resistCold = ResistCold;}
		
		int getResistLightning() {return resistLightning + addUpEquipmentStats("resistLightning");}
		int getResistLightningStat() {return resistLightning;}
		void setResistLightning(int ResistLightning) {resistLightning = ResistLightning;}
		
		int getResistLight() {return resistLight + addUpEquipmentStats("resistLight");}
		int getResistLightStat() {return resistLight;}
		void setResistLight(int ResistLight) {resistLight = ResistLight;}
		
		int getResistDark() {return resistDark + addUpEquipmentStats("resistDark");}
		int getResistDarkStat() {return resistDark;}
		void setResistDark(int ResistDark) {resistDark = ResistDark;}
		
		int getResistPoison() {return resistPoison + addUpEquipmentStats("resistPoison");}
		int getResistPoisonStat() {return resistPoison;}
		void setResistPoison(int ResistPoison) {resistPoison = ResistPoison;}
		
		int getResistManaEnergy() {return resistManaEnergy + addUpEquipmentStats("resistManaEnergy");}
		int getResistManaEnergyStat() {return resistManaEnergy;}
		void setResistManaEnergy(int ResistManaEnergy) {resistManaEnergy = ResistManaEnergy;}
		
		int getResistBludgeoning() {return resistBludgeoning + addUpEquipmentStats("resistBludgeoning");}
		int getResistBludgeoningStat() {return resistBludgeoning;}
		void setResistBludgeoning(int ResistBludgeoning) {resistBludgeoning = ResistBludgeoning;}
		
		int getResistSlashing() {return resistSlashing + addUpEquipmentStats("resistSlashing");}
		int getResistSlashingStat() {return resistSlashing;}
		void setResistSlashing(int ResistSlashing) {resistSlashing = ResistSlashing;}
		
		int getResistPiercing() {return resistPiercing + addUpEquipmentStats("resistPiercing");}
		int getResistPiercingStat() {return resistPiercing;}
		void setResistPiercing(int ResistPiercing) {resistPiercing = ResistPiercing;}
		
		
		
		
		

		bool getIsArcane() {return isArcane;}
		void setIsArcane(int IsArcane) {isArcane = IsArcane;}
		bool getIsDivine() {return isDivine;}
		void setIsDivine(int IsDivine) {isDivine = IsDivine;}
		
		
		void viewInventory() {
			for (int x = 0; x < 100; x++) {
				if (inventory[x].equipSlot != "null") {
					
					cout << x << ": ";
					inventory[x].getColor();
					cout << inventory[x].getName() << endl;
					inventory[x].cancelColor();
					
				}
			}
		}
		
		void viewInventoryDetails() {
			for (int x = 0; x < 100; x++) {
				if (inventory[x].equipSlot != "null") {
					
					cout << x << ": " << endl;
					inventory[x].viewItem();
				}
			}
		}
		
		void viewEquipped() {
			if (head.equipSlot != "null") {
				cout << "Head: "; head.getColor(); cout << head.getName() << endl; head.cancelColor();
			}
			if (torso.equipSlot != "null") {
				cout << "Torso: "; torso.getColor(); cout << torso.getName() << endl; torso.cancelColor();
			}
			if (shoulders.equipSlot != "null") {
				cout << "Shoulders: "; shoulders.getColor(); cout << shoulders.getName() << endl; shoulders.cancelColor();
			}
			if (arms.equipSlot != "null") {
				cout << "Arms: "; arms.getColor(); cout << arms.getName() << endl; arms.cancelColor();
			}
			if (hands.equipSlot != "null") {
				cout << "Hands: "; hands.getColor(); cout << hands.getName() << endl; hands.cancelColor();
			}
			if (legs.equipSlot != "null") {
				cout << "Legs: "; legs.getColor(); cout << legs.getName() << endl; legs.cancelColor();
			}
			if (feet.equipSlot != "null") {
				cout << "Feet: "; feet.getColor(); cout << feet.getName() << endl; feet.cancelColor();
			}
			if (rightHand.equipSlot != "null") {
				cout << "Right: "; rightHand.getColor(); cout << rightHand.getName() << endl; rightHand.cancelColor();
			}
			if (leftHand.equipSlot != "null") {
				cout << "Left: ";leftHand.getColor(); cout << leftHand.getName() << endl; leftHand.cancelColor();
			}
			
		}
		void viewEquippedDetails() {
			cout << endl << endl;
			cout << "Head: " << endl;
			head.viewItem();
			cout << "\nTorso: " << endl;
			torso.viewItem();
			cout << "\nShoulders: "<< endl;
			shoulders.viewItem();
			cout << "\nArms: " << endl;
			arms.viewItem();
			cout << "\nHands: " << endl;
			hands.viewItem();
			cout << "\nLegs: " << endl;
			legs.viewItem();
			cout << "\nFeet: " << endl;
			feet.viewItem();
			cout << "\nRight: " << endl;
			rightHand.viewItem();
			cout << "\nLeft: " << endl;
			leftHand.viewItem();
		}
		
		
		void putInInventory(equipment storeThis) {
			for (int x = 0; x < 100; x++) {
				if (inventory[x].equipSlot == "null") {
					
					inventory[x] = storeThis;
					
					break;
				}
			}
		}
		
		int numberOfItemsInInventory() {
			int total = 0;
			
			for (int x = 0; x < 100; x++) {
				if (inventory[x].equipSlot == "null") {
					return total;
				}
				else {
					total++;
				}
			}
		}
		
		int numberOfEquippedItems() {
			int total = 0;
			
			if (head.getEquipSlot() == "head") {
				total++;
			}
			if (torso.getEquipSlot() == "torso") {
				total++;
			}
			if (shoulders.getEquipSlot() == "shoulders") {
				total++;
			}
			if (arms.getEquipSlot() == "arms") {
				total++;
			}
			if (hands.getEquipSlot() == "hands") {
				total++;
			}
			if (legs.getEquipSlot() == "legs") {
				total++;
			}
			if (feet.getEquipSlot() == "feet") {
				total++;
			}
			if (rightHand.getEquipSlot() == "equippable") {
				total++;
			}
			if (leftHand.getEquipSlot() == "equippable") {
				total++;
			}
			return total;
		}
		
		void equip(equipment newEquipment) {
			if (newEquipment.equipSlot == "head" ) {
				equipment temp = head;
				setHead(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "torso" ) {
				equipment temp = torso;
				setTorso(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "shoulders" ) {
				equipment temp = shoulders;
				setShoulders(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "arms" ) {
				equipment temp = arms;
				setArms(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "hands" ) {
				equipment temp = hands;
				setHands(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "legs" ) {
				equipment temp = legs;
				setLegs(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			else if (newEquipment.equipSlot == "feet" ) {
				equipment temp = feet;
				setFeet(newEquipment);
				putInInventory(temp);
				//return temp;
			}
			//goherenow fix weapon equipping
			else if (newEquipment.equipSlot == "equippable" ) {
				cout << "What hand?\n 1:Right hand\n 2:Left hand\n";
				int handChoice = 0;
				cin >> handChoice;
				if (handChoice == 1) {
					equipment temp = rightHand;
					setRightHand(newEquipment);
					putInInventory(temp);
				}
				else if (handChoice == 2) {
					equipment temp = leftHand;
					setLeftHand(newEquipment);
					putInInventory(temp);
				}
				//return temp;
			}
			
		}
		
		void setHead(equipment newHead) {
			head = newHead;
		}
		equipment getHead() {
			return head;
		}
		void setTorso(equipment newTorso) {
			torso = newTorso;
		}
		equipment getTorso() {
			return torso;
		}
		void setShoulders(equipment newShoulders) {
			shoulders = newShoulders;
		}
		equipment getShoulders() {
			return shoulders;
		}
		void setArms(equipment newArms) {
			arms = newArms;
		}
		equipment getArms() {
			return arms;
		}
		void setHands(equipment newHands) {
			hands = newHands;
		}
		equipment getHands() {
			return hands;
		}
		void setLegs(equipment newLegs) {
			legs = newLegs;
		}
		equipment getLegs() {
			return legs;
		}
		void setFeet(equipment newFeet) {
			feet = newFeet;
		}
		equipment getFeet() {
			return feet;
		}
		void setRightHand(equipment newRightHand) {
			rightHand = newRightHand;
		}
		equipment getRightHand() {
			return rightHand;
		}
		void setLeftHand(equipment newLeftHand) {
			leftHand = newLeftHand;
		}
		equipment getLeftHand() {
			return leftHand;
		}
		
};


