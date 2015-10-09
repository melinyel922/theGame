class cloud {
	public :
	
	int radius, chaosChance, chaosFactor, positionX, positionY, velocityX, velocityY, intensityPercent, minimumIntensity;
	
	cloud (): radius(0), chaosChance(0), chaosFactor(0), positionX(0), positionY(0), velocityX(0), velocityY(0), intensityPercent(0), minimumIntensity(0) {};
	
	
	cloud (int Radius, int ChaosChance, int ChaosFactor, int PositionX, int PositionY, int VelocityX, int VelocityY, int IntensityPercent, int MinimumIntensity) {
		radius = Radius;
		chaosChance = ChaosChance;
		chaosFactor = ChaosFactor;
		positionX = PositionX;
		positionY = PositionY;
		velocityX = VelocityX;
		velocityY = VelocityY;
		intensityPercent = IntensityPercent;
		minimumIntensity = MinimumIntensity;
	}
	
	
};
