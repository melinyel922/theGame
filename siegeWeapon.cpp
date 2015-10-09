
class siegeWeapon {
	public:
	int attack, defense, health, range, accuracy, move, reloadTime, reloadCoolDown, weaponType;
	string symbol, weaponName;
		
		siegeWeapon(): attack(0), defense(0), health(0), range(0), accuracy(0), move(0), reloadTime(0), reloadCoolDown(0), weaponType(0), symbol("#"), weaponName("siege weapon") {}
	
		siegeWeapon(int Attack, int Defense, int Health, int Range, int Accuracy, int Move, int ReloadTime, int ReloadCoolDown, int WeaponType) {
			weaponType = 0;
			attack = Attack;
			defense = Defense;
			health = Health;
			range = Range;
			accuracy = Accuracy;
			move = Move;
			reloadTime = ReloadTime;
			reloadCoolDown = ReloadCoolDown;
			weaponType = WeaponType;
				
		}
			
		int getAttack () {
			return attack;
		}
		void setAttack (int attackSet) {
			attack = attackSet;
		}
		
		int getDefense () {
			return defense;
		}
		void setDefense (int defenseSet) {
			defense = defenseSet;
		}
		
		int getHealth () {
			return health;
		}
		void setHealth (int healthSet) {
			health = healthSet;
		}
		
		int getRange () {
			return range;
		}
		void setRange (int rangeSet) {
			range = rangeSet;
		}
		
		int getAccuracy () {
			return accuracy;
		}
		void setAccuracy (int accuracySet) {
			accuracy = accuracySet;
		}
		
		int getMove () {
			return move;
		}
		void setMove (int moveSet) {
			move = moveSet;
		}
		
		int getReloadTime () {
			return reloadTime;
		}
		void setReloadTime (int reloadTimeSet) {
			reloadTime = reloadTimeSet;
		}
		
		int getReloadCoolDown () {
			return reloadCoolDown;
		}
		void setReloadCoolDown (int reloadCoolDownSet) {
			reloadCoolDown = reloadCoolDownSet;
		}
		
		int getWeaponType () {
			return weaponType;
		}
		void setWeaponType (int weaponTypeSet) {
			weaponType = weaponTypeSet;
		}
		
		string getSymbol () {
			return symbol;
		}
		void setSymbol (int symbolSet) {
			symbol = symbolSet;
		}
		
		string getWeaponName () {
			
			return weaponName;
		}
		void setWeaponName (int weaponNameSet) {
			weaponName = weaponNameSet;
		}
};


