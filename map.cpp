#include <iostream>
#include <cstdlib>
#include "mapSquare.cpp"
#include "plantSquare.cpp"
#include "treeSquare.cpp"
#include "grassySquare.cpp"
#include "wallSquare.cpp"
#include "flagStoneSquare.cpp"
#include "castleSeedSquare.cpp"

using namespace std;



class mappy {
	
	private:
		mapSquare* grid[100][100];
		
	public:
		mappy ()
		{
			srand (time(NULL));
			int typeOfTile;
			for (int i=0; i<100; i++) // i is columns
			{
				for (int j=0; j<100; j++) // j is rows
				{
					grid[i][j] = new mapSquare();
				}
			}
		}
		
		//suggest iterations=20, numberToBeat=30, maxRadius=7, minRadius=2
		void addGrass(int iterations, int numberToBeat, int maxRadius, int minRadius) {
			int x,y,i;
			int grassChance;
			int grassCenterX;
			int grassCenterY;
			int radius;
			
			
			for (i = 0; i <= iterations; i++) {
				grassCenterX = rand() % 25;
				grassCenterY = rand() % 50;
				radius = rand()% (maxRadius - minRadius) + minRadius;
				
				for ( x = 0; x < 25; x++) {
					for ( y = 0; y <= 50; y++) {
						grassChance = radius*radius-((x-grassCenterX)*(x-grassCenterX)+(y-grassCenterY)*(y-grassCenterY));
						grassChance = grassChance;
						if (grassChance > rand() % numberToBeat + 1 && (grid[x][y])->getMaterial() == 0) {
							delete grid[x][y];
							grid[x][y] = NULL;
							grid[x][y] = new grassySquare();
						}
						
					}
				}
			}
		}
		
		//suggest chance=10, clumpfactor=7
		void addTrees(int chance, int clumpFactor) {
			
			for (int i=0; i<100; i++) // i is columns
			{
				for (int j=0; j<100; j++) // j is rows
				{
					if (rand() % 100 + 1 <= chance) {
						delete grid[i][j];
						grid[i][j] = NULL;
						grid[i][j] = new treeSquare();
					}
						
				}
			}
			
			//adds some clumpy brothers
			int chanceToBeTree = 0;
			for (int x=1; x<99; x++) // x is columns
			{
				for (int y=1; y<99; y++) // y is rows
				{
					chanceToBeTree = 0;
					
					if ((grid[x-1][y])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x-1][y-1])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x][y-1])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x+1][y])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y+1])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x+1][y])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getMaterial() == 1) {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					
					if (rand() % 100 + 1 < chanceToBeTree && (grid[x][y])->getMaterial() != 1) {
						delete grid[x][y];
						grid[x][y] = NULL;
						grid[x][y] = new treeSquare();
					}
					
				}
			}
			
		}
		
		//inverseCastleChance=10000
		void addCastles(int inverseCastleChance) {
			int castleSize;
			int entranceDirection;
			for (int i=1; i<=18; i++) // i is columns
			{
				for (int j=1; j<=44; j++) // j is rows
				{
					if (rand() % inverseCastleChance + 1 <= 1) {
						delete grid[i][j];
						grid[i][j] = NULL;
						grid[i][j] = new castleSeedSquare();
						cout << "castle seed at " << i << "," << j << endl;
					}
				}
				
			}
			for (int i=0; i<50; i++) // i is columns
			{
				for (int j=0; j<50; j++) // j is rows
				{
					if ((grid[i][j])->getMaterial() == 100 || (grid[i][j])->getMaterial() == 101 ) {
						if ((grid[i][j])->getMaterial() == 101) {//round ones need to be bigger
							castleSize = rand() % 100 + 1;
							if (castleSize <= 50){//50%
								castleSize = 4;
							}
							else if (castleSize <= 85){//35%
								castleSize = 5;
							}
							else if (castleSize <= 100){//15%
								castleSize = 6;
							}
						}
						else {//higher chance for a smaller one
							castleSize = rand() % 100 + 1;
							
							if (castleSize <= 40){//40%
								castleSize = 1;
							}
							else if (castleSize <= 65){//25%
								castleSize = 2;
							}
							else if (castleSize <= 80){//15%
								castleSize = 3;
							}
							else if (castleSize <= 90){//10%
								castleSize = 4;
							}
							else if (castleSize <= 99){//9%
								castleSize = 5;
							}
							else if (castleSize <= 100){//1%
								castleSize = 6;
							}			
						}
						entranceDirection = rand() % 4 + 1;
						
						if ((grid[i][j])->getMaterial() == 101) {//makes a round tower
							for (int castleX = 0; castleX <= 50; castleX++) {//covers the whole castle area
								for (int castleY = 0; castleY <= 50; castleY++) {
									int distanceFromMiddle = (castleX - i)*(castleX - i) + (castleY - j)*(castleY - j);
									int castleSizeSquared = castleSize * castleSize;
									if (distanceFromMiddle == castleSizeSquared || distanceFromMiddle == castleSizeSquared-1 || distanceFromMiddle == castleSizeSquared - 2 || distanceFromMiddle == castleSizeSquared + 1 || distanceFromMiddle == castleSizeSquared + 2 || distanceFromMiddle == castleSizeSquared + 3|| distanceFromMiddle == castleSizeSquared + 4) {//if it is on the perimeter
										
										
										delete grid[castleX][castleY];
										grid[castleX][castleY] = NULL;
										grid[castleX][castleY] = new wallSquare();
										
										if (entranceDirection == 1 && castleY == j &&  castleX == i - castleSize) {//west door
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 2 && castleY == j + castleSize && castleX == i) {//north door
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 3 && castleY == j && castleX == i + castleSize) {//east door
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 4 && castleY == j - castleSize && castleX == i) {//south door
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new flagStoneSquare();
										}
									
									}
									
									if ((castleX-i)*(castleX-i) + (castleY-j)*(castleY-j) < (castleSize) * (castleSize)) {//lays the floor
										delete grid[castleX][castleY];
										grid[castleX][castleY] = NULL;
										grid[castleX][castleY] = new flagStoneSquare();
										if (castleX == i && castleY == j) {//puts gold in the middle
											(grid[castleX][castleY])-> setGold(rand() % (castleSize * 50) + castleSize * 100); //up to like 700 gold, depends on size
										}
									}
								}
							}
						}
						else if ((grid[i][j])->getMaterial() == 100) {//makes a square tower
							for (int castleX = 0; castleX <= castleSize + 2; castleX++) {//covers the whole castle area
								for (int castleY = 0; castleY <= castleSize + 2; castleY++) {
									if (castleX == 0 || castleY == 0 || castleX == castleSize + 2 || castleY == castleSize + 2) {//if it is on the perimeter
										
										delete grid[i + castleX][j + castleY];
										grid[i + castleX][j + castleY] = NULL;
										grid[i + castleX][j + castleY] = new wallSquare();
										if (entranceDirection == 1 && castleY == (castleSize + 1) / 2 && castleX == 0) {//west door
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 2 && castleY == 0 && castleX == (castleSize + 1) / 2) {//north door
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 3 && castleY == (castleSize + 1) / 2 && castleX == castleSize + 2) {//east door
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
										if (entranceDirection == 4 && castleY == castleSize + 2 && castleX == (castleSize + 1) / 2) {//south door
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
									
									}
									else {//lays the floor
										delete grid[i + castleX][j + castleY];
										grid[i + castleX][j + castleY] = NULL;
										grid[i + castleX][j + castleY] = new flagStoneSquare();
										if (castleX == (castleSize + 2) / 2 && castleY == (castleSize + 2) / 2) {//puts gold in the middle
											(grid[castleX + i][castleY + j])-> setGold(rand() % (castleSize * 50) + castleSize * 100); //up to like 700 gold, depends on size
										}
									}
								}
							}
						}
					}
				}
				
			}
		}

		//suggest goldChanceTimesTen=5 maxGold=30 minGold=10
		void addGold(int goldChanceTimesTen, int maxGold, int minGold) {
			int x,y;
			for ( x = 0; x < 25; x++) {//initialize all object locations on the map, and places money
				for ( y = 0; y <= 50; y++) {
					if ((rand() % 1000 + 1) <= goldChanceTimesTen) {
						
						(grid[x][y])->setGold(rand()%(maxGold - minGold)+minGold);
					}
				}
			}
		}
			
		//suggest iterations=200 maxRadius=10 minRadius=1
		void addElevation(int iterations, int maxRadius, int minRadius, int maxElevation) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int hillCenterX = 0, hillCenterY = 0;
			int hillHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				hillCenterX = rand() % 25;
				hillCenterY = rand() % 50;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 == 1) {//1 in 5 chance to be a pit instead of a hill
					pit = true;	
					radius--;
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < 25; x++) {
					for ( y = 0; y <= 50; y++) {
						hillHeight = radius*radius-((x-hillCenterX)*(x-hillCenterX)+(y-hillCenterY)*(y-hillCenterY));
						
						if (hillHeight > 0) {//if the hill point is greater than zero
							if (pit) {
								hillHeight = - hillHeight;//makes it a pit
							}
							
							(grid[x][y])->setElevation(hillHeight + (grid[x][y])->getElevation() );//then it gets added to the map
						}
					}
				}
				
				
			}
			for ( x = 0; x < 25; x++) {//finds min and max heights
					for ( y = 0; y <= 50; y++) {
						if ((grid[x][y])->getElevation() > maximumFound) {
							maximumFound = (grid[x][y])->getElevation();
						}
						if ((grid[x][y])->getElevation() < minimumFound) {
							minimumFound = (grid[x][y])->getElevation();
						}
					}
				}
			for ( x = 0; x < 25; x++) {//normalizes it so that the minimum is zero and max is 20
				for ( y = 0; y <= 50; y++) {
					(grid[x][y])->setElevation((maxElevation*(grid[x][y])->getElevation() - minimumFound)/(maximumFound-minimumFound) );
				}
			}

		}
		
		//suggest iterations=200 maxRadius=5 minRadius=1
		void addArcane(int iterations, int maxRadius, int minRadius, int maxPeak) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % 25;
				peakCenterY = rand() % 50;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 4 + 1 <= 2) {//50% chance to be a pit
					pit = true;	
					radius--;
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < 25; x++) {
					for ( y = 0; y <= 50; y++) {
						peakHeight = radius*radius-((x-peakCenterX)*(x-peakCenterX)+(y-peakCenterY)*(y-peakCenterY));
						
						if (peakHeight > 0) {//if the peak point is greater than zero
							if (pit) {
								peakHeight = - peakHeight;//makes it a pit
							}
							
							(grid[x][y])->setArcane(peakHeight + (grid[x][y])->getArcane() );//then it gets added to the map
						}
					}
				}
				
				
			}
			for ( x = 0; x < 25; x++) {//finds min and max areas
					for ( y = 0; y <= 50; y++) {
						if ((grid[x][y])->getArcane() > maximumFound) {
							maximumFound = (grid[x][y])->getArcane();
						}
						if ((grid[x][y])->getArcane() < minimumFound) {
							minimumFound = (grid[x][y])->getArcane();
						}
					}
				}
			for ( x = 0; x < 25; x++) {//normalizes it so that the minimum is zero and max is the maxPeak
				for ( y = 0; y <= 50; y++) {
					
					(grid[x][y])->setArcane((maxPeak*(grid[x][y])->getArcane() + minimumFound)/(maximumFound-minimumFound) );
					int arcaneBoost = 1;
					if (grid[x][y]->getSquareType() == "flag stone") {
						arcaneBoost = 3;
					}
						
					(grid[x][y])->setArcane((grid[x][y])->getArcane() * arcaneBoost);
				}
			}

		}
		
		//suggest iterations=200 maxRadius=5 minRadius=1
		void addDivine(int iterations, int maxRadius, int minRadius, int maxPeak) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % 25;
				peakCenterY = rand() % 50;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 <= 2) {//40% chance to be a pit
					pit = true;	
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < 25; x++) {
					for ( y = 0; y <= 50; y++) {
						peakHeight = radius*radius-((x-peakCenterX)*(x-peakCenterX)+(y-peakCenterY)*(y-peakCenterY));
						
						if (peakHeight > 0) {//if the peak point is greater than zero
							if (pit) {
								peakHeight = - peakHeight;//makes it a pit
							}
							
							(grid[x][y])->setDivine(peakHeight + (grid[x][y])->getDivine() );//then it gets added to the map
						}
					}
				}
				
				
			}
			for ( x = 0; x < 25; x++) {//finds min and max areas
					for ( y = 0; y <= 50; y++) {
						if ((grid[x][y])->getDivine() > maximumFound) {
							maximumFound = (grid[x][y])->getDivine();
						}
						if ((grid[x][y])->getDivine() < minimumFound) {
							minimumFound = (grid[x][y])->getDivine();
						}
					}
				}
			for ( x = 0; x < 25; x++) {//normalizes it so that the minimum is zero and max is the maxPeak
				for ( y = 0; y <= 50; y++) {
					(grid[x][y])->setDivine((maxPeak*(grid[x][y])->getDivine() + minimumFound)/(maximumFound-minimumFound) );
					int divineHeightBoost = (grid[x][y])->getElevation() * 175 / getMaxElevation() + 25;//makes it go from 25 to 200 based on elevation
					(grid[x][y])->setDivine((grid[x][y])->getDivine() * divineHeightBoost / 100);
				}
			}

		}
		
		void addSiegeWeapons(int siegeWeaponChanceTimesTen) {
			int x, y;
			
			for ( x = 0; x < 25; x++) {
				for ( y = 0; y <= 50; y++) {
					if (rand() % 1000 + 1 <= siegeWeaponChanceTimesTen) {
						setGridSiegeWeapon(x,y,1);
					}
				}
			}
		}
		
		void printGrid(int i, int j) {
			(grid[i][j])->printSquareInfo();
			
		}
		
		void setGrid(int i, int j, int elevation, int material, int player, int condition, int conditionValue, bool passable, int gold, string symbol) {
			(grid[i][j])->setElevation(elevation);
			(grid[i][j])->setMaterial(material);
			(grid[i][j])->setPlayer(player);
			(grid[i][j])->setCondition(condition);
			(grid[i][j])->setConditionValue(conditionValue);
			(grid[i][j])->setPassable(passable);
			(grid[i][j])->setGold(gold);
			(grid[i][j])->setSymbol(symbol);
		}
		void setGridElevation(int i, int j, int elevation) {
			(grid[i][j])->setElevation(elevation);
		}
		void setGridMaterial(int i, int j, int material) {
			(grid[i][j])->setMaterial(material);
		}
		void setGridPlayer(int i, int j, int player) {
			(grid[i][j])->setPlayer(player);
		}
		void setGridCondition(int i, int j, int condition) {
			(grid[i][j])->setCondition(condition);
		}
		void setGridConditionValue(int i, int j, int conditionValue) {
			(grid[i][j])->setConditionValue(conditionValue);
		}
		void setGridPassable(int i, int j, bool passable) {
			(grid[i][j])->setPassable(passable);
		}
		void setGridGold(int i, int j, int gold) {
			(grid[i][j])->setGold(gold);
		}
		void setGridSymbol(int i, int j, string symbol) {
			(grid[i][j])->setSymbol(symbol);
		}
		void setGridDivine(int i, int j, int Divine) {
			(grid[i][j])->setDivine(Divine);
		}
		void setGridArcane(int i, int j, int Arcane) {
			(grid[i][j])->setArcane(Arcane);
		}
		
		
		int getGridElevation (int i, int j) {
			(grid[i][j])->getElevation();
		}
		int getGridMaterial (int i, int j) {
			(grid[i][j])->getMaterial();
		}
		int getGridPlayer (int i, int j) {
			(grid[i][j])->getPlayer();
		}
		int getGridCondition (int i, int j) {
			(grid[i][j])->getCondition();
		}
		int getGridConditionvalue (int i, int j) {
			(grid[i][j])->getConditionValue();
		}
		bool getGridPassable (int i, int j) {
			(grid[i][j])->getPassable();
		}
		int getGridGold (int i, int j) {
			(grid[i][j])->getGold();
		}
		void getGridSymbol (int i, int j) {
			cout << (grid[i][j])->getSymbol();
		}
		int getGridDivine (int i, int j) {
			(grid[i][j])->getDivine();
		}
		int getGridArcane (int i, int j) {
			(grid[i][j])->getArcane();
		}
		int getMaxDivine() {
			int max = 0;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridDivine(x,y) >= max) {
						max = getGridDivine(x,y);
					}
				}
			}
			return max;
		}
		int getMaxArcane() {
			int max = 0;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridArcane(x,y) >= max) {
						max = getGridArcane(x,y);
					}
				}
			}
			return max;
		}
		int getMaxElevation() {
			int max = 0;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridElevation(x,y) >= max) {
						max = getGridElevation(x,y);
					}
				}
			}
			return max;
		}
		int getMinDivine() {
			int min = 1000;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridDivine(x,y) <= min) {
						min = getGridDivine(x,y);
					}
				}
			}
			return min;
		}
		int getMinArcane() {
			int min = 1000;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridArcane(x,y) <= min) {
						min = getGridArcane(x,y);
					}
				}
			}
			return min;
		}
		int getMinElevation() {
			int min = 1000;
			for (int x = 0; x < 25; x++) {
				for (int y = 0; y <= 50; y++) {
					if (getGridElevation(x,y) <= min) {
						min = getGridElevation(x,y);
					}
				}
			}
			return min;
		}
		
		void setGridSiegeWeapon(int i, int j, int weaponType) {
			(grid[i][j])->setSiegeWeapon(weaponType);
		}
		void setHasSiegeWeapon(int i, int j, bool hasSiegeWeapon) {
			(grid[i][j])->setHasSiegeWeapon(hasSiegeWeapon);
		}
		bool getGridHasSiegeWeapon(int i, int j) {
			(grid[i][j])->getHasSiegeWeapon();
		}
		int getGridSiegeWeaponType (int i, int j) {
			(grid[i][j])->getSiegeWeaponType();
		}
		
		int getGridSiegeAttack (int i, int j) {
			(grid[i][j])->getSiegeAttack();
		}
		int getGridSiegeDefense (int i, int j) {
			(grid[i][j])->getSiegeDefense();
		}
		int getGridSiegeHealth (int i, int j) {
			(grid[i][j])->getSiegeHealth();
		}
		int getGridSiegeRange (int i, int j) {
			(grid[i][j])->getSiegeRange();
		}
		int getGridSiegeAccuracy (int i, int j) {
			(grid[i][j])->getSiegeAccuracy();
		}
		int getGridSiegeMove (int i, int j) {
			(grid[i][j])->getSiegeMove();
		}
		int getGridSiegeReloadTime (int i, int j) {
			(grid[i][j])->getSiegeReloadTime();
		}
		int getGridSiegeReloadCoolDown (int i, int j) {
			(grid[i][j])->getSiegeReloadCoolDown();
		}
		int setGridSiegeReloadCoolDown (int i, int j, int siegeReloadCoolDownSet) {
			(grid[i][j])->setSiegeReloadCoolDown(siegeReloadCoolDownSet);
		}
		
};

