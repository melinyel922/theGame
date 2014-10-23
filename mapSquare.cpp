#include <iostream>
#include "siegeWeapon.cpp"
#include "ballista.cpp"

using namespace std;

class mapSquare {
	protected:
		int elevation, material, player, condition, conditionValue, gold;
		int divine, arcane;
		bool hasSiegeWeapon;
		siegeWeapon* weaponHere;
		bool passable;
		bool hasCeiling;
		string symbol, squareType;
		
		
    
	public:
		mapSquare(): elevation(0), material(0), player(0), condition(0), conditionValue(0), passable(true), gold(0), symbol("."), squareType("normal"), hasSiegeWeapon(false) {}
	
		mapSquare (int elev, int mat, int playr, int cond, int condVal, bool passy, int gol, string symb) {
			elevation = elev;
			material = mat;
			player = playr;
			condition = cond;
			conditionValue = condVal;
			passable = passy;
			gold = gol;
			symbol = symb;
			hasCeiling = false;
			divine = 0;
			arcane = 0;
		}
		
		void printSquareInfo () {
			cout << "Elevation: " << elevation << endl;
			cout << "Arcane:    " << arcane << endl;
			cout << "Divine:    " << divine << endl;
			cout << "Material:  " << material << endl;
			cout << "Player:    " << player << endl;
			cout << "Condition: " << condition << "  Value: " << conditionValue << endl;
			cout << "Passable:  " << passable << endl;
			cout << "Gold:      " << gold << endl;
			cout << "Symbol:    " << symbol << endl;
			if (hasSiegeWeapon) {
				cout << "\nSiege weapon info: \n";
				printSiegeWeaponInfo();
			}
		}
		
		int getElevation () {
			return elevation;
		}
		
		void setElevation (int elevationSet) {
			elevation = elevationSet;
		}
		
		int getMaterial () {
			return material;
		}
		
		void setMaterial (int materialSet) {
			material = materialSet;
		}
		
		int getPlayer () {
			return player;
		}
		
		void setPlayer (int playerSet) {
			player = playerSet;
		}
		
		int getCondition () {
			return condition;
		}
		
		void setCondition (int conditionSet) {
			condition = conditionSet;
		}
		
		int getConditionValue () {
			return conditionValue;
		}
		
		void setConditionValue (int conditionValueSet) {
			conditionValue = conditionValueSet;
		}
		
		bool getPassable () {
			if (player == 0 && hasSiegeWeapon == 0) {
				return passable; 
			}
			else {
				return false;
			}
		}
		
		void setPassable (bool passableSet) {
			passable = passableSet;
		}
		
		int getGold () {
			return gold;
		}
		
		void setGold(int goldSet) {
			gold = goldSet;
		}
		
		string getSymbol () {
			if (hasSiegeWeapon) {
				return (weaponHere)->getSymbol();
			}
			else {
				return symbol;
			}
		}
		
		void setSymbol(string symbolSet) {
			symbol = symbolSet;
		}
		
		string getSquareType () {
			return squareType;
		}
		void setSquareType(string squareTypeSet) {
			squareType = squareTypeSet;
		}
		
		int getDivine () {
			return divine;
		}
		void setDivine(int divineSet) {
			divine = divineSet;
		}
		
		int getArcane () {
			return arcane;
		}
		void setArcane(int arcaneSet) {
			arcane = arcaneSet;
		}
		
		void setSiegeWeapon(int weaponTypeSet) {
			if (weaponTypeSet == 1) {
				weaponHere = new ballista();
				setHasSiegeWeapon(true);
			}
			if(weaponTypeSet == 0) {
				setHasSiegeWeapon(false);
				delete weaponHere;
				weaponHere = NULL;
			}
		}
		void printSiegeWeaponInfo () {
			
			cout << getSiegeWeaponName() << endl;
			cout << "Attack:     " << getSiegeAttack() <<endl;
			cout << "Defense:    " << getSiegeDefense() <<endl;
			cout << "Health:     " << getSiegeHealth() <<endl;
			cout << "Range:      " << getSiegeRange() <<endl;
			cout << "Accuracy:   " << getSiegeAccuracy() <<endl;
			cout << "Move:       " << getSiegeMove() <<endl;
			cout << "Reload time:" << getSiegeReloadTime() <<endl;
			cout << "Time left:  " << getSiegeReloadCoolDown() <<endl;
		}
		bool getHasSiegeWeapon () {
			return hasSiegeWeapon;
		}
		void setHasSiegeWeapon(bool hasSiegeWeaponSet) {
			hasSiegeWeapon = hasSiegeWeaponSet;
		}
		int getSiegeAttack() {
			(weaponHere)->getAttack();
		}
		int getSiegeDefense() {
			(weaponHere)->getDefense();
		}
		int getSiegeHealth() {
			(weaponHere)->getHealth();
		}
		int getSiegeRange() {
			(weaponHere)->getRange();
		}
		int getSiegeAccuracy() {
			(weaponHere)->getAccuracy();
		}
		int getSiegeMove() {
			(weaponHere)->getMove();
		}
		int getSiegeReloadTime() {
			(weaponHere)->getReloadTime();
		}
		int getSiegeReloadCoolDown() {
			(weaponHere)->getReloadCoolDown();
		}
		void setSiegeReloadCoolDown(int reloadCoolDownSet) {
			(weaponHere)->setReloadCoolDown(reloadCoolDownSet);
		}
		int getSiegeWeaponType() {
			(weaponHere)->getWeaponType();
		}
		string getSiegeWeaponName() {
			
			return (weaponHere)->getWeaponName();
		}
		
 };
