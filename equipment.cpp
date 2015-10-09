

class equipment	{	
	public:
	int durability, equipmentDamageResist;
	string equipSlot;
	string name;
	string materialType;
	string material;
	int equipmentResistFire, equipmentResistCold, equipmentResistLightning, equipmentResistLight, equipmentResistDark, equipmentResistPoison, equipmentResistManaEnergy, equipmentResistBludgeoning, equipmentResistSlashing, equipmentResistPiercing;
	int equipmentDamageFire, equipmentDamageCold, equipmentDamageLightning, equipmentDamageLight, equipmentDamageDark, equipmentDamagePoison, equipmentDamageManaEnergy, equipmentDamageBludgeoning, equipmentDamageSlashing, equipmentDamagePiercing;
	int equipmentBaseAttack;
	int heaviness;
	int price;
	int level;
	int accuracy;
	int toHit;
	int evasion;
	int materialCondition;
	
	
	equipment(): name(""), materialType(""), material(""), materialCondition(0), durability(0), equipmentDamageResist(0), equipSlot(""), equipmentResistFire(0), equipmentResistCold(0), equipmentResistLightning(0), equipmentResistLight(0), equipmentResistDark(0), equipmentResistPoison(0), equipmentResistManaEnergy(0), equipmentResistBludgeoning(0), equipmentResistSlashing(0), equipmentResistPiercing(0), equipmentDamageFire(0), equipmentDamageCold(0), equipmentDamageLightning(0), equipmentDamageLight(0), equipmentDamageDark(0), equipmentDamagePoison(0), equipmentDamageManaEnergy(0), equipmentDamageBludgeoning(0), equipmentDamageSlashing(0), equipmentDamagePiercing(0), equipmentBaseAttack(0), heaviness(0), price(0), level(0), accuracy(0), toHit(0), evasion(0)  {}
	
	equipment( string Name, string EquipSlot, string MaterialType, string Material, int MaterialCondition, int Durability, int EquipmentDamageResist, int EquipmentResistFire, int EquipmentResistCold, int EquipmentResistLightning, int EquipmentResistLight, int EquipmentResistDark, int EquipmentResistPoison, int EquipmentResistManaEnergy, int EquipmentResistSlashing, int EquipmentResistBludgeoning, int EquipmentResistPiercing, int EquipmentDamageFire, int EquipmentDamageCold, int EquipmentDamageLightning, int EquipmentDamageLight, int EquipmentDamageDark, int EquipmentDamagePoison, int EquipmentDamageManaEnergy, int EquipmentDamageSlashing, int EquipmentDamageBludgeoning, int EquipmentDamagePiercing, int EquipmentBaseAttack, int Heaviness, int Price, int Level, int Accuracy, int ToHit, int Evasion) {
		name = Name;
		equipSlot = EquipSlot;
		materialType = MaterialType;
		material = Material;
		materialCondition = MaterialCondition;
		durability = Durability;
		equipmentDamageResist = EquipmentDamageResist;
		
		equipmentResistFire = EquipmentResistFire;
		equipmentResistCold = EquipmentResistCold;
		equipmentResistLightning = EquipmentResistLightning;
		equipmentResistLight = EquipmentResistLight;
		equipmentResistDark = EquipmentResistDark;
		equipmentResistPoison = EquipmentResistPoison;
		equipmentResistManaEnergy = EquipmentResistManaEnergy;
		equipmentResistBludgeoning = EquipmentResistBludgeoning;
		equipmentResistSlashing = EquipmentResistSlashing;
		equipmentResistPiercing = EquipmentResistPiercing;
		
		equipmentDamageFire = EquipmentDamageFire;
		equipmentDamageCold = EquipmentDamageCold;
		equipmentDamageLightning = EquipmentDamageLightning;
		equipmentDamageLight = EquipmentDamageLight;
		equipmentDamageDark = EquipmentDamageDark;
		equipmentDamagePoison = EquipmentDamagePoison;
		equipmentDamageManaEnergy = EquipmentDamageManaEnergy;
		equipmentDamageBludgeoning = EquipmentDamageBludgeoning;
		equipmentDamageSlashing = EquipmentDamageSlashing;
		equipmentDamagePiercing = EquipmentDamagePiercing;
		
		equipmentBaseAttack = EquipmentBaseAttack;
		heaviness = Heaviness;
		price = Price;
		level = Level;
		accuracy = Accuracy;
		toHit = ToHit;
		evasion = Evasion;
	}
	
	void makeNull() {
		equipSlot = "null";
		name = "null";
		materialType = "null";
		material = "null";
		materialCondition = 0;
		durability = 0;
		equipmentDamageResist = 0;
		
		equipmentResistFire = 0;
		equipmentResistCold = 0;
		equipmentResistLightning = 0;
		equipmentResistLight = 0;
		equipmentResistDark = 0;
		equipmentResistPoison = 0;
		equipmentResistManaEnergy = 0;
		equipmentResistBludgeoning = 0;
		equipmentResistSlashing = 0;
		equipmentResistPiercing = 0;
		
		equipmentDamageFire = 0;
		equipmentDamageCold = 0;
		equipmentDamageLightning = 0;
		equipmentDamageLight = 0;
		equipmentDamageDark = 0;
		equipmentDamagePoison = 0;
		equipmentDamageManaEnergy = 0;
		equipmentDamageBludgeoning = 0;
		equipmentDamageSlashing = 0;
		equipmentDamagePiercing = 0;
		
		equipmentBaseAttack = 0;
		heaviness = 0;
		price = 0;
		level = 0;
		accuracy = 0;
		toHit = 0;
		evasion = 0;
	}
	
	int getClassifier() {
		return price * 100 / (level*level*25);
	}
	
	void getColor() {
		int classifier = getClassifier();
		
		cout << "Classifier:  " << classifier << endl;
		if (classifier <= 25) {//red
			cout << "\033[31;40m";
		}
		else if (classifier <= 75) {//grey
			cout << "\033[1;31;40m";
		}
		else if (classifier <= 125) {//white
			cout << "\033[1;37;40m";
		}
		else if (classifier <= 200) {//green
			cout << "\033[1;32;40m";
		}
		else if (classifier <= 300) {//blue
			cout << "\033[1;34;40m";
		}
		else if (classifier <= 400) {//magenta
			cout << "\033[1;35;40m";
		}
		else if (classifier <= 500) {//cyan
			cout << "\033[1;36;40m";
		}
		else {//yellow
			cout << "\033[1;33;40m";//yellow
		}
		
	}
	
	void cancelColor() {
		cout << "\033[0;40m";
	}
	
	void viewItem() {
		if (level != 0 && heaviness != 0) {
			cout << endl;
			
			cout << "Name:              ";
			getColor();
			cout << name << endl;
			cancelColor();
			cout << "Price:             " << price << endl;
			cout << "Level:             " << level << endl;
			cout << "Slot:              " << equipSlot << endl;
			if (equipmentBaseAttack) {
				cout << "Base Damage        " << equipmentBaseAttack << endl;
			}
			if (equipmentDamageBludgeoning || equipmentDamageSlashing || equipmentDamagePiercing) {
				cout << "Damage BSP         " << equipmentDamageBludgeoning <<  "|" << equipmentDamageSlashing << "|" << equipmentDamagePiercing << endl;
			}
			if (toHit) {
				cout << "To hit bonus:      " << toHit << endl;
			}
			cout << "Heaviness:         " << heaviness << endl;
			if (accuracy) {
				cout << "Accuracy:          " << accuracy << endl;
			}
			if (evasion) {
				cout << "Evasion:           " << evasion << endl;
			}
			if (equipmentResistFire) {
				cout << "Resist fire        " << equipmentResistFire << endl;
			}
			if (equipmentResistCold) {
				cout << "Resist cold        " << equipmentResistCold << endl;
			}
			if (equipmentResistLightning) {
				cout << "Resist lightning   " << equipmentResistLightning << endl;
			}
			if (equipmentResistLight) {
				cout << "Resist light       " << equipmentResistLight << endl;
			}
			if (equipmentResistDark) {
				cout << "Resist dark        " << equipmentResistDark << endl;
			}
			if (equipmentResistPoison) {
				cout << "Resist poison      " << equipmentResistPoison << endl;
			}
			if (equipmentResistManaEnergy) {
				cout << "Resist mana        " << equipmentResistManaEnergy << endl;
			}
			if (equipmentResistBludgeoning) {
				cout << "Resist bludgeoning " << equipmentResistBludgeoning << endl;
			}
			if (equipmentResistSlashing) {
				cout << "Resist slashing    " << equipmentResistSlashing << endl;
			}
			if (equipmentResistPiercing) {
				cout << "Resist piercing    " << equipmentResistPiercing << endl;
			}
			if (equipmentDamageFire) {
				cout << "Damage fire        " << equipmentDamageFire << endl;
			}
			if (equipmentDamageCold) {
				cout << "Damage cold        " << equipmentDamageCold << endl;
			}
			if (equipmentDamageLightning) {
				cout << "Damage lightning   " << equipmentDamageLightning << endl;
			}
			if (equipmentDamageLight) {
				cout << "Damage light       " << equipmentDamageLight << endl;
			}
			if (equipmentDamageDark) {
				cout << "Damage dark        " << equipmentDamageDark << endl;
			}
			if (equipmentDamagePoison) {
				cout << "Damage poison      " << equipmentDamagePoison << endl;
			}
			if (equipmentDamageManaEnergy) {
				cout << "Damage mana        " << equipmentDamageManaEnergy << endl;
			}
	}	
		
		
	}
	
	string getEquipSlot() {return equipSlot;}
	void setEquipSlot(string EquipSlot) {equipSlot = EquipSlot;}
	string getName() {return name;}
	void setName(string Name) {name = Name;}
	int getDurability() {return durability;}
	void setDurability(int Durability) {durability = Durability;}
	int getEquipmentDamageResist() {return equipmentDamageResist;}
	void setEquipmentDamageResist(int EquipmentDamageResist) {equipmentDamageResist = EquipmentDamageResist;}
	int getHeaviness() {return heaviness;}
	void setHeaviness(int Heaviness) {heaviness = Heaviness;}
	int getPrice() {return price;}
	void setPrice(int Price) {price = Price;}
	int getLevel() {return level;}
	void setLevel(int Level) {level = Level;}
	
	int getAccuracy() {return accuracy;}
	void setAccuracy(int Accuracy) {accuracy = Accuracy;}
	int getEvasion() {return evasion;}
	void setEvasion(int Evasion) {evasion = Evasion;}
	
	
	int getToHit() {return toHit;}
	void setToHit(int ToHit) {toHit = ToHit;}
	
	
	int getEquipmentBaseAttack() {return equipmentBaseAttack;}
	void setEquipmentBaseAttack(int EquipmentBaseAttack) {equipmentBaseAttack = EquipmentBaseAttack;}
	
	string getMaterialType() {return materialType;}
	void setMaterialType(string MaterialType) {materialType = MaterialType;}
	string getMaterial() {return material;}
	void setMaterial(string Material) {material = Material;}
	int getMaterialCondition() {return materialCondition;}
	void setMaterialCondition(int MaterialCondition) {materialCondition = MaterialCondition;}
	
	
	int getEquipmentResistFire() {return equipmentResistFire;}
	void setEquipmentResistFire(int EquipmentResistFire) {equipmentResistFire = EquipmentResistFire;}
	int getEquipmentResistCold() {return equipmentResistCold;}
	void setEquipmentResistCold(int EquipmentResistCold) {equipmentResistCold = EquipmentResistCold;}
	int getEquipmentResistLightning() {return equipmentResistLightning;}
	void setEquipmentResistLightning(int EquipmentResistLightning) {equipmentResistLightning = EquipmentResistLightning;}
	int getEquipmentResistLight() {return equipmentResistLight;}
	void setEquipmentResistLight(int EquipmentResistLight) {equipmentResistLight = EquipmentResistLight;}
	int getEquipmentResistDark() {return equipmentResistDark;}
	void setEquipmentResistDark(int EquipmentResistDark) {equipmentResistDark = EquipmentResistDark;}
	int getEquipmentResistPoison() {return equipmentResistPoison;}
	void setEquipmentResistPoison(int EquipmentResistPoison) {equipmentResistPoison = EquipmentResistPoison;}
	int getEquipmentResistManaEnergy() {return equipmentResistManaEnergy;}
	void setEquipmentResistManaEnergy(int EquipmentResistManaEnergy) {equipmentResistManaEnergy = EquipmentResistManaEnergy;}
	int getEquipmentResistBludgeoning() {return equipmentResistBludgeoning;}
	void setEquipmentResistBludgeoning(int EquipmentResistBludgeoning) {equipmentResistBludgeoning = EquipmentResistBludgeoning;}
	int getEquipmentResistSlashing() {return equipmentResistSlashing;}
	void setEquipmentResistSlashing(int EquipmentResistSlashing) {equipmentResistSlashing = EquipmentResistSlashing;}
	int getEquipmentResistPiercing() {return equipmentResistPiercing;}
	void setEquipmentResistPiercing(int EquipmentResistPiercing) {equipmentResistPiercing = EquipmentResistPiercing;}
	
	
	int getEquipmentDamageFire() {return equipmentDamageFire;}
	void setEquipmentDamageFire(int EquipmentDamageFire) {equipmentDamageFire = EquipmentDamageFire;}
	int getEquipmentDamageCold() {return equipmentDamageCold;}
	void setEquipmentDamageCold(int EquipmentDamageCold) {equipmentDamageCold = EquipmentDamageCold;}
	int getEquipmentDamageLightning() {return equipmentDamageLightning;}
	void setEquipmentDamageLightning(int EquipmentDamageLightning) {equipmentDamageLightning = EquipmentDamageLightning;}
	int getEquipmentDamageLight() {return equipmentDamageLight;}
	void setEquipmentDamageLight(int EquipmentDamageLight) {equipmentDamageLight = EquipmentDamageLight;}
	int getEquipmentDamageDark() {return equipmentDamageDark;}
	void setEquipmentDamageDark(int EquipmentDamageDark) {equipmentDamageDark = EquipmentDamageDark;}
	int getEquipmentDamagePoison() {return equipmentDamagePoison;}
	void setEquipmentDamagePoison(int EquipmentDamagePoison) {equipmentDamagePoison = EquipmentDamagePoison;}
	int getEquipmentDamageManaEnergy() {return equipmentDamageManaEnergy;}
	void setEquipmentDamageManaEnergy(int EquipmentDamageManaEnergy) {equipmentDamageManaEnergy = EquipmentDamageManaEnergy;}
	int getEquipmentDamageBludgeoning() {return equipmentDamageBludgeoning;}
	void setEquipmentDamageBludgeoning(int EquipmentDamageBludgeoning) {equipmentDamageBludgeoning = EquipmentDamageBludgeoning;}
	int getEquipmentDamageSlashing() {return equipmentDamageSlashing;}
	void setEquipmentDamageSlashing(int EquipmentDamageSlashing) {equipmentDamageSlashing = EquipmentDamageSlashing;}
	int getEquipmentDamagePiercing() {return equipmentDamagePiercing;}
	void setEquipmentDamagePiercing(int EquipmentDamagePiercing) {equipmentDamagePiercing = EquipmentDamagePiercing;}	
};
