class ballista: public siegeWeapon {
	public:
		ballista(int weaponLevel) {
			attack = 90 + rand() % 40 + weaponLevel * 10;//80-120
			defense = 5 + weaponLevel / 2;
			health = 200 + weaponLevel * 25;
			range = 20;
			accuracy = 5;
			move = 2;
			reloadTime = 50;
			reloadCoolDown = 50;
			weaponType = 1;
			weaponName = "ballista";
		}
	
};


