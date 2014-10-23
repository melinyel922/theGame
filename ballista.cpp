class ballista: public siegeWeapon {
	public:
		ballista() {
			attack = 9 + rand() % 4;//8-12
			defense = 10;
			health = 20;
			range = 20;
			accuracy = 5;
			move = 2;
			reloadTime = 50;
			reloadCoolDown = 50;
			weaponType = 1;
			weaponName = "ballista";
		}
	
};


