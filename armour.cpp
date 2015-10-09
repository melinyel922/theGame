class armour: public equipment {
	public:
		//armour(): durability(0), equipmentDamageResist(0), equipSlot(""), equipmentResistFire(0), equipmentResistCold(0), equipmentResistLightning(0), equipmentResistLight(0), equipmentResistDark(0), equipmentResistPoison(0), equipmentResistManaEnergy(0), equipmentResistBludgeoning(0), equipmentResistSlashing(0), equipmentResistPiercing(0)  {}
		
		armour(string Name, string EquipSlot, string MaterialType, string Material, int Durability, int EquipmentDamageResist, int EquipmentResistFire, int EquipmentResistCold, int EquipmentResistLightning, int EquipmentResistLight, int EquipmentResistDark, int EquipmentResistPoison, int EquipmentResistManaEnergy, int EquipmentResistBludgeoning, int EquipmentResistSlashing, int EquipmentResistPiercing) {
			name = Name;
			equipSlot = EquipSlot;
			materialType = MaterialType;
			material = Material;
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
		}
		
		
};


