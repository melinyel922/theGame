#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "mapSquare.cpp"
#include "plantSquare.cpp"
#include "treeSquare.cpp"
#include "bushSquare.cpp"
#include "grassySquare.cpp"
#include "wallSquare.cpp"
#include "wallWindowSquare.cpp"
#include "flagStoneSquare.cpp"
#include "castleSeedSquare.cpp"
#include "room.cpp"
#include "cloud.cpp"

using namespace std;

// Astar.cpp
// http://en.wikipedia.org/wiki/A*
// Compiler: Dev-C++ 4.9.9.2
// FB - 201012256
//replaced "map" with "Map"
const int n=150; // horizontal size of the Map
const int m=150; // vertical size size of the Map
static int closed_nodes_Map[n][m]; // Map of closed (tried-out) nodes
static int open_nodes_Map[n][m]; // Map of open (not-yet-tried) nodes
static int dir_Map[n][m]; // Map of directions
const int dir=8; // number of possible directions to go at any position
// if dir==4
//static int dx[dir]={1, 0, -1, 0};
//static int dy[dir]={0, 1, 0, -1};
// if dir==8
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

class node
{
	// current position
	int xPos;
	int yPos;
	// total distance already travelled to reach the node
	int level;
	// priority=level+remaining distance estimate
	int priority;  // smaller: higher priority
	

	public:
		node(int xp, int yp, int d, int p) 
			{xPos=xp; yPos=yp; level=d; priority=p;}
	
		int getxPos() const {return xPos;}
		int getyPos() const {return yPos;}
		int getLevel() const {return level;}
		int getPriority() const {return priority;}
		

		void updatePriority(const int & xDest, const int & yDest)
		{
			 priority=level+estimate(xDest, yDest)*10; //A*
		}

		// give better priority to going strait instead of diagonally
		void nextLevel(const int & i) // i: direction
		{
			 level+=(dir==8?(i%2==0?10:14):10);
			 
		}
		
		
		
		// Estimation function for the remaining distance to the goal.
		const int & estimate(const int & xDest, const int & yDest) const
		{
			static int xd, yd, d;
			xd=xDest-xPos;
			yd=yDest-yPos;         

			// Euclidian Distance
			d=static_cast<int>(sqrt(xd*xd+yd*yd));

			// Manhattan distance
			//d=abs(xd)+abs(yd);
			
			// Chebyshev distance
			//d=max(abs(xd), abs(yd));

			return(d);
		}
};



class mappy {
	
	private:
		mapSquare* grid[100][100];
		room* roomMap[100];
		cloud* manaCloudList[100];
		int totalRooms;
		int totalManaClouds;
		int xMapWidth, yMapLength;
		int digMap[100][100];
		
		
		
		
		
		
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
					digMap[i][j] = 0;
				}
			}
		}
		
		

		bool drawline(int xStart, int yStart, int xFinish, int yFinish) {
			int dx = abs(xStart - xFinish);
			int dy = abs(yStart - yFinish);
			double s = double(.01/(dx>dy?dx:dy));
			//double s = 0.01;
			double t = 0.0;
			bool found = true;
			
			while(t < 1.0) {
				
				dx = int((1.0 - t)*xStart + t*xFinish);
				dy = int((1.0 - t)*yStart + t*yFinish);
				
				if (getGridSeeThrough(dx,dy) == false && !(dx == xStart && dy == yStart) && !(dx == xFinish && dy == yFinish) ) {
					
					found = false;
				} 
				t += s; 
			}
			return found;
		}
		
			
		bool Bresenham(int x1,int y1,int const x2,int const y2) {
			int delta_x(x2 - x1);
			bool pathThrough = true;
			// if x1 == x2, then it does not matter what we set here
			signed char const ix((delta_x > 0) - (delta_x < 0));
			delta_x = std::abs(delta_x) << 1;
		 
			int delta_y(y2 - y1);
			// if y1 == y2, then it does not matter what we set here
			signed char const iy((delta_y > 0) - (delta_y < 0));
			delta_y = std::abs(delta_y) << 1;
		 
		 
			if (delta_x >= delta_y)
			{
				// error may go below zero
				int error(delta_y - (delta_x >> 1));
		 
				while (x1 != x2)
				{
					if ((error >= 0) && (error || (ix > 0)))
					{
						error -= delta_x;
						y1 += iy;
					}
					// else do nothing
		 
					error += delta_y;
					x1 += ix;
		 
					if (!(getGridSeeThrough(x1,y1)) ) {
						pathThrough = false;
					}
				}
			}
			else
			{
				// error may go below zero
				int error(delta_x - (delta_y >> 1));
		 
				while (y1 != y2)
				{
					if ((error >= 0) && (error || (iy > 0)))
					{
						error -= delta_y;
						x1 += ix;
					}
					// else do nothing
		 
					error += delta_x;
					y1 += iy;
		 
					if (!(getGridSeeThrough(x1,y1)) ) {
						pathThrough = false;
					}
				}
			}
			
			return pathThrough;
		}


		
		// A-star algorithm.
		// The route returned is a string of direction digits.
		string pathFind( const int & xStart, const int & yStart, 
						 const int & xFinish, const int & yFinish)
		{
			static priority_queue<node> pq[2]; // list of open (not-yet-tried) nodes
			static int pqi; // pq index
			static node* n0;
			static node* m0;
			static int i, j, x, y, xdx, ydy;
			static char c;
			pqi=0;

			// reset the node Maps
			for(y=0;y<m;y++)
			{
				for(x=0;x<n;x++)
				{
					closed_nodes_Map[x][y]=0;
					open_nodes_Map[x][y]=0;
				}
			}

			// create the start node and push into list of open nodes
			n0=new node(xStart, yStart, 0, 0);
			n0->updatePriority(xFinish, yFinish);
			pq[pqi].push(*n0);
			open_nodes_Map[x][y]=n0->getPriority(); // mark it on the open nodes Map

			// A* search
			while(!pq[pqi].empty())
			{
				// get the current node w/ the highest priority
				// from the list of open nodes
				n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
							 pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

				x=n0->getxPos(); y=n0->getyPos();

				pq[pqi].pop(); // remove the node from the open list
				open_nodes_Map[x][y]=0;
				// mark it on the closed nodes Map
				closed_nodes_Map[x][y]=1;

				// quit searching when the goal state is reached
				//if((*n0).estimate(xFinish, yFinish) == 0)
				if(x==xFinish && y==yFinish) 
				{
					// generate the path from finish to start
					// by following the directions
					string path="";
					while(!(x==xStart && y==yStart))
					{
						j=dir_Map[x][y];
						c='0'+(j+dir/2)%dir;
						path=c+path;
						x+=dx[j];
						y+=dy[j];
					}

					// garbage collection
					delete n0;
					// empty the leftover nodes
					while(!pq[pqi].empty()) pq[pqi].pop();           
					return path;
				}

				// generate moves (child nodes) in all possible directions
				for(i=0;i<dir;i++)
				{
					xdx=x+dx[i]; ydy=y+dy[i];

					if(!(xdx<0 || xdx>xMapWidth || ydy<0 || ydy>yMapLength || getGridPassable(xdx,ydy) == 0 
						|| closed_nodes_Map[xdx][ydy]==1))
					{
						// generate a child node
						m0=new node( xdx, ydy, n0->getLevel(), 
									 n0->getPriority());
						m0->nextLevel(i);
						m0->updatePriority(xFinish, yFinish);

						// if it is not in the open list then add into that
						if(open_nodes_Map[xdx][ydy]==0)
						{
							open_nodes_Map[xdx][ydy]=m0->getPriority();
							pq[pqi].push(*m0);
							// mark its parent node direction
							dir_Map[xdx][ydy]=(i+dir/2)%dir;
						}
						else if(open_nodes_Map[xdx][ydy]>m0->getPriority())
						{
							// update the priority info
							open_nodes_Map[xdx][ydy]=m0->getPriority();
							// update the parent direction info
							dir_Map[xdx][ydy]=(i+dir/2)%dir;

							// replace the node
							// by emptying one pq to the other one
							// except the node to be replaced will be ignored
							// and the new node will be pushed in instead
							while(!(pq[pqi].top().getxPos()==xdx && 
								   pq[pqi].top().getyPos()==ydy))
							{                
								pq[1-pqi].push(pq[pqi].top());
								pq[pqi].pop();       
							}
							pq[pqi].pop(); // remove the wanted node
							
							// empty the larger size pq to the smaller one
							if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
							while(!pq[pqi].empty())
							{                
								pq[1-pqi].push(pq[pqi].top());
								pq[pqi].pop();       
							}
							pqi=1-pqi;
							pq[pqi].push(*m0); // add the better node instead
						}
						else delete m0; // garbage collection
					}
				}
				delete n0; // garbage collection
			}
			
			return ""; // no route found
		}

		bool checkMovePath(int xA, int yA, int xB, int yB, int moveSpeed)
		{
			srand(time(NULL));
			// get the route
			
			string route=pathFind(xA, yA, xB, yB);
			
			// follow the route on the Map and display it 
			
			int moveCost = 0;
			int j = 0;
			char c;
			
			
			for (int i = 0; i < route.length(); i++) {
					c =route.at(i);
					istringstream(&c) >> j;
					
					if (j == 2 || j == 4 || j == 6  || j == 8 || j == 0) {
						moveCost += 2;
						
					}
					else if (j == 1 || j == 3 || j == 5 || j == 7) {
						moveCost += 3;
					}
			}
			int elevationChange = ((grid[xB][yB])->getElevation() - (grid[xA][yA])->getElevation());
			if (elevationChange < 0) {
				elevationChange = elevationChange / 2;
			}
			moveCost += elevationChange;
			moveCost = moveCost / 2; //this fixes the weighting diagonals as 1.5
			
			//cout << (grid[xB][yB])->getElevation() << " - " << (grid[xA][yA])->getElevation() << endl;
			//cout << "e-" << elevationChange << ",c-" << moveCost << ",s-" << moveSpeed << " ";
			
			if(route.length() > 0 && moveCost <= moveSpeed  )
			{
				
				return true;
			}
			else {
				return false;
			 }
			 
			return(0);
		}

		
		void setMapSize(int mapWidth, int mapLength) {
			xMapWidth = mapWidth;
			yMapLength = mapLength;
		}
		
		void removeThingsBlockingWindows(int windowX, int windowY) {
			for (int x = windowX - 1; x <= windowX + 1; x++) {
				for (int y = windowY - 1; y <= windowY + 1; y++) {
					if (x <= xMapWidth && y <= yMapLength) {
						if (!((grid[y][y])->getPassable()) && ((grid[y][y])->getMaterial() != 10)) {
							
							int elevationHere = grid[x][y]->getElevation();//resets it back to the true elevation
							delete grid[x][y];
							grid[x][y] = NULL;
							grid[x][y] = new mapSquare();
							grid[x][y]->setElevation(elevationHere);//conserves elevation
							
							
						} 
					}
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
				grassCenterX = rand() % xMapWidth;
				grassCenterY = rand() % yMapLength;
				radius = rand()% (maxRadius - minRadius) + minRadius;
				
				for ( x = 0; x < xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
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
		
		//suggest chance=3, clumpfactor=6
		void addTrees(int chance, int clumpFactor) {
			int middle = getMaxElevation() / 2;
			
			for (int i=0; i<xMapWidth; i++) // i is columns
			{
				for (int j=0; j<yMapLength; j++) // j is rows
				{
					int elevationHere = grid[i][j]->getElevation();
					if (elevationHere <= 0) {
						elevationHere = 1;
					}
					int adjustedChance = chance * middle / elevationHere / 2 + chance / 2;
					if (rand() % 1000 + 1 <= adjustedChance) {
						elevationHere = grid[i][j]->getElevation();//reset true elevation
						delete grid[i][j];
						grid[i][j] = NULL;
						grid[i][j] = new treeSquare();
						grid[i][j]->setElevation(elevationHere);
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
					
					if ((grid[x-1][y])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x-1][y-1])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x][y-1])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x+1][y])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y+1])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					if ((grid[x+1][y])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getSquareType() == "tree") {
						chanceToBeTree = chanceToBeTree + clumpFactor;
					}
					
					if (rand() % 1000 + 1 < chanceToBeTree && (grid[x][y])->getSquareType() != "tree") {
						int elevationHere = grid[x][y]->getElevation();//reset true elevation
						delete grid[x][y];
						grid[x][y] = NULL;
						grid[x][y] = new treeSquare();
						grid[x][y]->setElevation(elevationHere);
					}
					
				}
			}
			
		}
		//suggest chance = 3, clumpFactor = 8
		void addBushes(int chance, int clumpFactor) {
			int middle = getMaxElevation() / 2;
			for (int i=0; i<xMapWidth; i++) // i is columns
			{
				for (int j=0; j<yMapLength; j++) // j is rows
				{
					int elevationHere = grid[i][j]->getElevation();
					if (elevationHere <= 0) {
						elevationHere = 1;
					}
					int adjustedChance = chance * middle / elevationHere;
					if (rand() % 1000 + 1 <= adjustedChance) {
						elevationHere = grid[i][j]->getElevation();//resets to true elevation
						delete grid[i][j];
						grid[i][j] = NULL;
						grid[i][j] = new bushSquare();
						grid[i][j]->setElevation(elevationHere);
					}
						
				}
			}
			
			//adds some clumpy brothers around bushes/trees
			int chanceToBeBush = 0;
			for (int x=1; x<99; x++) // x is columns
			{
				for (int y=1; y<99; y++) // y is rows
				{
					chanceToBeBush = 0;
					
					if ((grid[x-1][y])->getSquareType() == "bush" || (grid[x-1][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor*2;
					}
					if ((grid[x-1][y-1])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor;
					}
					if ((grid[x][y-1])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor;
					}
					if ((grid[x+1][y])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor*2;
					}
					if ((grid[x+1][y+1])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor;
					}
					if ((grid[x+1][y])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor*2;
					}
					if ((grid[x+1][y-1])->getSquareType() == "bush" || (grid[x][y])->getSquareType() == "tree") {
						chanceToBeBush = chanceToBeBush + clumpFactor;
					}
					
					if (rand() % 1000 + 1 < chanceToBeBush && (grid[x][y])->getSquareType() != "bush" && (grid[x][y])->getSquareType() != "tree") {
						
						int elevationHere = grid[x][y]->getElevation();//resets to true elevation
						delete grid[x][y];
						grid[x][y] = NULL;
						grid[x][y] = new bushSquare();
						grid[x][y]->setElevation(elevationHere);
					}
					
				}
			}
			
		}
		
		
		void addMegaCastle(int x, int y, int size) {
			int elevationHere = grid[x][y]->getElevation();
			delete grid[x][y];
			grid[x][y] = NULL;
			grid[x][y] = new castleSeedSquare();
			(grid[x][y])->setMaterial(103);//makes it a mega tower seed
			(grid[x][y])->setCastleSize(size);//sets the tower size
			grid[x][y]->setElevation(elevationHere);
		}
		
		
		void wallFill() {
			
			
			
			for (int i=1; i < xMapWidth; i++) {// i is columns, this fills in areas that should be filled
				for (int j=1; j < yMapLength; j++) {// j is rows 
					if ((grid[i][j])->getSquareType() == "normal") {
						int wallNeighbours = 0;
						
						if ((grid[i-1][j])->getSquareType() == "wall") {
							wallNeighbours = wallNeighbours + 1;
						}
						if ((grid[i][j-1])->getSquareType() == "wall") {
							wallNeighbours = wallNeighbours + 1;
						}
						if ((grid[i+1][j])->getSquareType() == "wall") {
							wallNeighbours = wallNeighbours + 1;
						}
						if ((grid[i][j+1])->getSquareType() == "wall") {
							wallNeighbours = wallNeighbours + 1;
						}
						
						if (wallNeighbours > 1) {
							int elevationHere = grid[i][j]->getElevation();//resets it back to the true elevation
							delete grid[i][j];
							grid[i][j] = NULL;
							grid[i][j] = new wallSquare();
							grid[i][j]->setSquareType("dontCountAsWall");
							grid[i][j]->setElevation(elevationHere);//conserves elevation
						}
					}
				}
			}
			
			for (int i=1; i < xMapWidth; i++) {// i is columns, this fills in areas that should be filled
				for (int j=1; j < yMapLength; j++) {// j is rows 
					if ((grid[i][j])->getSquareType() == "dontCountAsWall") {
						grid[i][j]->setSquareType("wall");
					}
				}
			}
		}
		
		//inverseCastleChance=10000
		void addCastles(int inverseCastleChance) {
			int castleSize;
			int entranceDirection;
			int middle = getMaxElevation() / 2;
			
			
			int xMapWidthNarrow = xMapWidth - 6;
			int yMapLengthNarrow = yMapLength - 6;
			for (int i=5; i<= xMapWidthNarrow; i++) // i is columns this seeds castles
			{
				for (int j=5; j<= yMapLengthNarrow; j++) // j is rows
				{
					int elevationHere = grid[i][j]->getElevation();//makes sure there isn't a zero or negative
					if (elevationHere <= 0) {
						elevationHere = 1;
					}
					
					int adjustedChance = inverseCastleChance * middle / elevationHere;
						//ex: max height 20, middle = 10, inverseCastleChance = 10,000
						//1->100,000	2->50,000 5->20,000	10->10,000	15->6,666	18->5,555	20->5,000
					
					if (rand() % adjustedChance == 0) {//small chance, used to be  +1 <= 1, but this works too
						if (rand() % adjustedChance == 0) {//mega castles
							addMegaCastle(i,j,rand() % 4 + 4);
						}
						else {//regular castles
							elevationHere = grid[i][j]->getElevation();//resets it back to the true elevation
							delete grid[i][j];
							grid[i][j] = NULL;
							grid[i][j] = new castleSeedSquare();
							grid[i][j]->setElevation(elevationHere);//conserves elevation
						}
					}
				}
				
			}
			
			for (int i=0; i < xMapWidth; i++) // i is columns this builds castles
			{
				for (int j=0; j < yMapLength; j++) // j is rows
				{
					if ((grid[i][j])->getMaterial() == 100 || (grid[i][j])->getMaterial() == 101 || (grid[i][j])->getMaterial() == 103 ) {
						castleSize = (grid[i][j])->getCastleSize();
						entranceDirection = rand() % 4 + 1;
						
						if ((grid[i][j])->getMaterial() == 101) {//makes a round tower
							for (int castleX = 0; castleX <= xMapWidth; castleX++) {//covers the whole map area
								for (int castleY = 0; castleY <= yMapLength; castleY++) {
									int elevationHere = grid[castleX][castleY]->getElevation();
									int distanceFromMiddle = (castleX - i)*(castleX - i) + (castleY - j)*(castleY - j);
									int castleSizeSquared = castleSize * castleSize;
									
									if ((distanceFromMiddle >= castleSizeSquared - 1 && distanceFromMiddle <= castleSizeSquared + 6) && getGridMaterial(castleX,castleY) != 10 && getGridMaterial(castleX,castleY) != 11 ) {//if it is on the perimeter
										
										if (getGridMaterial(castleX,castleY) == 10 || getGridMaterial(castleX,castleY) == 11 ) {
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new flagStoneSquare();
										}
										else {
											delete grid[castleX][castleY];
											grid[castleX][castleY] = NULL;
											grid[castleX][castleY] = new wallSquare();
										}
										
										
										if (castleY == j &&  castleX == i - castleSize) {//west door
											if (entranceDirection == 1) {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
											else {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
										}
										else if (castleY == j + castleSize && castleX == i) {//north door
											if (entranceDirection == 2) {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
											else {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
										}
										else if (castleY == j && castleX == i + castleSize) {//east door
											if (entranceDirection == 3) {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
											else {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
										}
										else if (castleY == j - castleSize && castleX == i) {//south door
											if (entranceDirection == 4) {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
											else {
												delete grid[castleX][castleY];
												grid[castleX][castleY] = NULL;
												grid[castleX][castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX,castleY);
											}
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
								
									grid[castleX][castleY]->setElevation(elevationHere);
								}
							}
						}
						else if ((grid[i][j])->getMaterial() == 100) {//makes a square tower
							for (int castleX = 0; castleX <= castleSize + 2; castleX++) {//covers the whole castle area
								for (int castleY = 0; castleY <= castleSize + 2; castleY++) {
									int elevationHere = grid[i+castleX][j+castleY]->getElevation();
									if ((castleX == 0 || castleY == 0 || castleX == castleSize + 2 || castleY == castleSize + 2) ) {//if it is on the perimeter
										if (getGridMaterial(castleX + i,castleY + j) == 10 || getGridMaterial(castleX + i,castleY + j) == 11 ) {
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
										else {
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new wallSquare();
										}
										
										if (castleY == (castleSize + 2) / 2 && castleX == 0) {//west door
											if (entranceDirection == 1) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == 0 && castleX == (castleSize + 2) / 2) {//north door
											if (entranceDirection == 2) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == (castleSize + 2) / 2 && castleX == castleSize + 2) {//east door
											if (entranceDirection == 3) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == castleSize + 2 && castleX == (castleSize + 2) / 2) {//south door
											if (entranceDirection == 4) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
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
									grid[i+castleX][j+castleY]->setElevation(elevationHere);
								}
							}
						}
						else if ((grid[i][j])->getMaterial() == 103) {//makes a square tower and adds round ones on the corners
							
							for (int castleX = 0; castleX <= castleSize + 2; castleX++) {//covers the whole castle area
								for (int castleY = 0; castleY <= castleSize + 2; castleY++) {
									int elevationHere = grid[castleX+i][castleY+j]->getElevation();
									
									if ((castleX == 0 || castleY == 0 || castleX == castleSize + 2 || castleY == castleSize + 2) ) {//if it is on the perimeter
										if (getGridMaterial(castleX + i,castleY + j) == 10 || getGridMaterial(castleX + i,castleY + j) == 11 ) {
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new flagStoneSquare();
										}
										else {
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new wallSquare();
										}
										
										if (castleY == (castleSize + 2) / 2 && castleX == 0) {//west door
											if (entranceDirection == 1) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == 0 && castleX == (castleSize + 2) / 2) {//north door
											if (entranceDirection == 2) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == (castleSize + 2) / 2 && castleX == castleSize + 2) {//east door
											if (entranceDirection == 3) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										if (castleY == castleSize + 2 && castleX == (castleSize + 2) / 2) {//south door
											if (entranceDirection == 4) {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new flagStoneSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
											else {
												delete grid[i + castleX][j + castleY];
												grid[i + castleX][j + castleY] = NULL;
												grid[i + castleX][j + castleY] = new wallWindowSquare();
												removeThingsBlockingWindows(castleX + i,castleY + j);
											}
										}
										
										
									}
									else {//lays the floor
										delete grid[i + castleX][j + castleY];
										grid[i + castleX][j + castleY] = NULL;
										grid[i + castleX][j + castleY] = new flagStoneSquare();
										if (castleX == (castleSize + 2) / 2 && castleY == (castleSize + 2) / 2) {//puts gold in the middle
											(grid[castleX + i][castleY + j])-> setGold(rand() % (castleSize * 50) + castleSize * 100); //up to like 700 gold, depends on size
										}
										if ((castleX == castleSize + 1 && (castleY == 1 || castleY == castleSize + 1)) || (castleX == 1 && (castleY == 1 || castleY == castleSize + 1)) ) {
											delete grid[i + castleX][j + castleY];
											grid[i + castleX][j + castleY] = NULL;
											grid[i + castleX][j + castleY] = new castleSeedSquare();
											(grid[i + castleX][j + castleY])->setMaterial(101);//makes round towers in the corners
											(grid[i + castleX][j + castleY])->setCastleSize(castleSize / 3);//sets the round tower size
											addCastles(inverseCastleChance * 10);//basically just does it all again to finish the corners, and there is a chance for more castles technically
										}
									}
									grid[castleX+i][castleY+j]->setElevation(elevationHere);
								
								}
							}
						}
						
					}
				}
				
			}
		
			wallFill();

		}

		//suggest goldChanceTimesTen=5 maxGold=30 minGold=10
		void addGold(int goldChanceTimesTen, int maxGold, int minGold) {
			int x,y;
			for ( x = 0; x < xMapWidth; x++) {//initialize all object locations on the map, and places money
				for ( y = 0; y < yMapLength; y++) {
					if ((rand() % 1000 + 1) <= goldChanceTimesTen && (grid[x][y])->getPassable()) {
						
						(grid[x][y])->setGold(rand()%(maxGold - minGold)+minGold);
					}
				}
			}
		}
		
		equipment createItem(int level, string equipSlot, int heaviness,bool display) {
			equipment madeItem;
			
			
			
			string materialType = "";
			int itemType = rand() % 100 + 1;
			int itemMaterial = rand() % 100 + 1;
			int itemMaterialCondition = 0;
			if (heaviness == 0) {
				heaviness = rand() % 5 + 1;
			}
			
			int durability = 100, equipmentDamageResist = 50;
			int equipmentResistFire = 0, equipmentResistCold = 0, equipmentResistLightning = 0, equipmentResistLight = 0, equipmentResistDark = 0, equipmentResistPoison = 0, equipmentResistManaEnergy = 0, equipmentResistBludgeoning = 0, equipmentResistSlashing = 0, equipmentResistPiercing = 0;
			int enchantmentNumberDecider = 0;
			int numberOfEnchantments = rand() % (level / 5 + 1);
			int numberOfDetriments = rand() % (level / 10 + 1);
			int enchantmentType = 0;
			
			int jewelAmount = 0;
			int jewelChance = 0;
			int jewelQuality = 0;
			int jewelCondition = 0;
			string jewelType = "";
			string jewelDescriptor = "";
			string jewelMaterialConditionString = "";
			int materialQuality = rand() % 6 + rand() % 6;
			int secondMaterialQuality = materialQuality + upOrDown();
			if (secondMaterialQuality > 10) {
				secondMaterialQuality = 10;
			}
			else if (secondMaterialQuality < 0) {
				secondMaterialQuality = 0;
			}
			int materialCondition = 0;
			string materialConditionString = "";
			
			string itemSpecialName = "";
			string itemBaseName = "";
			string itemSecondMaterial = "";
			madeItem.makeNull();
			madeItem.setMaterialType(materialType);
			madeItem.setHeaviness(heaviness);
			madeItem.setLevel(level);
			int specialEnchant = rand() % 1000 + 1;
			
			//set materialCondition
			int materialConditionDecider = rand() % 100 + 1;
			//5% 10% 20% 30% 20% 10% 5%
			if (materialConditionDecider <= 5) {
				materialCondition = 1;
			}
			else if (materialConditionDecider <= 15) {
				materialCondition = 2;
			}
			else if (materialConditionDecider <= 35) {
				materialCondition = 3;
			}
			else if (materialConditionDecider <= 65) {
				materialCondition = 4;
			}
			else if (materialConditionDecider <= 85) {
				materialCondition = 5;
			}
			else if (materialConditionDecider <= 95) {
				materialCondition = 6;
			}
			else if (materialConditionDecider <= 100) {
				materialCondition = 7;
			}
			
			if (equipSlot == " ") {//if no equipSlot was specified
				if (itemType <= 30) {//equippable		30
					//cout << "making equippable\n";
					equipSlot = "equippable";
				}
				else if (itemType <= 45) {//hands		15
					//cout << "making hands\n";
					equipSlot = "hands";
				}
				else if (itemType <= 60) {//feet		15
					//cout << "making feet\n";
					equipSlot = "feet";
				}
				else if (itemType <= 70) {//arms		10
					//cout << "making arms\n";
					equipSlot = "arms";
				}
				else if (itemType <= 80) {//legs		10
					//cout << "making legs\n";
					equipSlot = "legs";
				}
				else if (itemType <= 90) {//shoulders	10
					//cout << "making shoulders\n";
					equipSlot = "shoulders";
				}
				else if (itemType <= 95) {//head		5
					//cout << "making head\n";
					equipSlot = "head";
				}
				else if (itemType <= 100) {//torso		5
					//cout << "making torso\n";
					equipSlot = "torso";
				}
			}
			
			if (equipSlot == "equippable") {//sets weapon accuracy, and armor evasion cost
				madeItem.setAccuracy( (2 - heaviness) * 3);
				madeItem.setQuickness( (2 - heaviness) * 3);
			}
			else {
				madeItem.setEvasion( (2 - heaviness));
				madeItem.setQuickness( (2 - heaviness));
			}
			
			if (equipSlot == "equippable") {//sets material
					switch(heaviness) {
					case 1:
						if (itemMaterial <= 50) {//wood
							//cout << "making wood\n";
							materialType = "wood";
						}
						else if (itemMaterial <= 100) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						break;
					case 2:
						if (itemMaterial <= 40) {//wood
							//cout << "making wood\n";
							materialType = "wood";
						}
						else if (itemMaterial <= 80) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						else if (itemMaterial <= 100) {//both
							//cout << "making both\n";
							materialType = "wood/metal";
						}
						break;
					case 3:
						if (itemMaterial <= 35) {//wood
							//cout << "making wood\n";
							materialType = "wood";
						}
						else if (itemMaterial <= 70) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						else if (itemMaterial <= 100) {//both
							//cout << "making both\n";
							materialType = "wood/metal";
						}
						break;
					case 4:
						if (itemMaterial <= 40) {//wood
							//cout << "making wood\n";
							materialType = "wood";
						}
						else if (itemMaterial <= 80) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						else if (itemMaterial <= 100) {//both
							//cout << "making both\n";
							materialType = "wood/metal";
						}
						break;
					case 5:
						if (itemMaterial <= 30) {//wood
							//cout << "making wood\n";
							materialType = "wood";
						}
						else if (itemMaterial <= 95) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						else if (itemMaterial <= 100) {//both
							//cout << "making both\n";
							materialType = "wood/metal";
						}
						break;
				}
			}
			else {//if armor
				switch(heaviness) {
					case 1:
						if (itemMaterial <= 80) {//cloth
							//cout << "making cloth\n";
							materialType = "cloth";
						}
						else if (itemMaterial <= 100) {//leather
							//cout << "making leather\n";
							materialType = "leather";
						}
						break;
					case 2:
						if (itemMaterial <= 25) {//cloth
							//cout << "making cloth\n";
							materialType = "cloth";
						}
						else if (itemMaterial <= 100) {//leather
							//cout << "making leather\n";
							materialType = "leather";
						}
						break;
					case 3:
						if (itemMaterial <= 20) {//cloth
							//cout << "making cloth\n";
							materialType = "cloth";
						}
						else if (itemMaterial <= 80) {//leather
							//cout << "making leather\n";
							materialType = "leather";
						}
						else if (itemMaterial <= 100) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						break;
					case 4:
						if (itemMaterial <= 50) {//leather
							//cout << "making leather\n";
							materialType = "leather";
						}
						else if (itemMaterial <= 100) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						break;
					case 5:
						if (itemMaterial <= 20) {//leather
							//cout << "making leather\n";
							materialType = "leather";
						}
						else if (itemMaterial <= 100) {//metal
							//cout << "making metal\n";
							materialType = "metal";
						}
						break;
				}
			}
			
			enchantmentNumberDecider = rand() % (level / 5 + 1);
			
			if (specialEnchant >= 990) {
				numberOfEnchantments++;
				numberOfEnchantments++;
				itemSpecialName += "extra heavily enchanted ";
			}
			else if (specialEnchant >= 950) {
				numberOfEnchantments++;
				itemSpecialName += "heavily enchanted ";
			}
			else if (specialEnchant >= 900) {
				numberOfEnchantments++;
				numberOfDetriments++;
				itemSpecialName += "overfocused ";
			}
			
			
			//craftmanship level title
			switch (level % 10) {
				case 0:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "chipped ";
							break;
						case 1:
							itemSpecialName += "cracked ";
							break;
						default:
							cout << "problem item name creation case 0\n";
							break;
					}
					//else if soft
					break;
				case 1:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "shoddy ";
							break;
						case 1:
							itemSpecialName += "ruined ";
							break;
						default:
							cout << "problem item name creation case 1\n";
							break;
					}
					break;
				case 2:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "poor ";
							break;
						case 1:
							itemSpecialName += "worn ";
							break;
						default:
							cout << "problem item name creation case 2\n";
							break;
					}
					break;
				case 3:
					switch (rand() % 3) {
						case 0:
							itemSpecialName += "battleworn ";
							break;
						case 1:
							itemSpecialName += "muddy ";
							break;
						case 2:
							itemSpecialName += "dirty ";
							break;
						default:
							cout << "problem item name creation case 3\n";
							break;
					}
					break;
				case 4:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "mediocre ";
							break;
						case 1:
							itemSpecialName += "acceptable ";
							break;
						default:
							cout << "problem item name creation case 4\n";
							break;
					}
					break;
				case 5:
					switch (rand() % 3) {
						case 0:
							itemSpecialName += "normal ";
							break;
						case 1:
							itemSpecialName += "ordinary ";
							break;
						case 2:
							itemSpecialName += "average ";
							break;
						default:
							cout << "problem item name creation case 5\n";
							break;
					}
					break;
				case 6:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "decent ";
							break;
						case 1:
							itemSpecialName += "competent ";
							break;
						default:
							cout << "problem item name creation case 6\n";
							break;
					}
					break;
				case 7:
				switch (rand() % 2) {
						case 0:
							itemSpecialName += "fine ";
							break;
						case 1:
							itemSpecialName += "quality ";
							break;
						default:
							cout << "problem item name creation case 7\n";
							break;
					}
					
					break;
				case 8:
				switch (rand() % 2) {
						case 0:
							itemSpecialName += "remarkable ";
							break;
						case 1:
							itemSpecialName += "exceptional ";
							break;
						default:
							cout << "problem item name creation case 8\n";
							break;
					}
					
					break;
				case 9:
					switch (rand() % 2) {
						case 0:
							itemSpecialName += "superior ";
							break;
						case 1:
							itemSpecialName += "excellent ";
							break;
						default:
							cout << "problem item name creation case 9\n";
							break;
					}
					break;
				default:
					cout << "problem with item name creation\n";
					break;
				
				
			} 
			
			//craftmanship tier title
			switch (level / 10) {
				case 0:
					break;
				case 1:
					itemSpecialName += "masterwork ";
					break;
				case 2:
					itemSpecialName += "grandmaster ";
					break;
				case 3:
					itemSpecialName += "legendary ";
					break;
				default:
					itemSpecialName += "legendary ";
					break;
				
			} 
			
			
			
			
			//material and quality
			if (materialType == "metal") {
				switch (materialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("copper");
								break;
							case 1:
								madeItem.setMaterial("nickel");
								break;
						}
						break;
					case 1:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("brass");
								break;
							case 1:
								madeItem.setMaterial("tin");
								break;
							case 2:
								madeItem.setMaterial("pewter");
								break;
						}
						break;
					case 2:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("pig iron");
								break;
							case 1:
								madeItem.setMaterial("bronze");
								break;
						}
						break;
					case 3:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("iron");
								break;
							case 1:
								madeItem.setMaterial("lead");
								break;
						}
						break;
					case 4:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("wrought iron");
								break;
						}
						break;
					case 5:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("steel");
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("titanium");
								break;
							case 1:
								madeItem.setMaterial("damascus");
								break;
						}
						break;
					case 7:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("tungsten");
								break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("mithril");
								break;
							case 1:
								madeItem.setMaterial("vibranium");
								break;
						}
						break;
					case 9:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("adamantine");
								break;
						}
						break;
					case 10:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("adamantine");
								break;
						}
						break;
					default:
						cout << "there was a problem with the metal item generator\n";
						break;
				} 
				
				switch(materialCondition) {
					case 1:
						materialConditionString = "pitted-";
						break;
					case 2:
						materialConditionString = "dented-";
						break;
					case 3:
						materialConditionString = "tarnished-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "polished-";
						break;
					case 6:
						materialConditionString = "mirror-finished-";
						break;
					case 7:
						materialConditionString = "refined-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			else if (materialType == "leather") {
				switch (materialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("frog skin");
								break;
							case 1:
								madeItem.setMaterial("salamander skin");
								break;
						}
						break;
					case 1:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("rat skin");
								break;
							case 1:
								madeItem.setMaterial("squirrel skin");
								break;
							case 2:
								madeItem.setMaterial("mole skin");
								break;
						}
						break;
					case 2:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("sheep skin");
								break;
							case 1:
								madeItem.setMaterial("lizard skin");
								break;
						}
						break;
					case 3:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("pig skin");
								break;
							case 1:
								madeItem.setMaterial("beaver skin");
								break;
							case 2:
								madeItem.setMaterial("skunk skin");
								break;
						}
						break;
					case 4:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("badger skin");
								break;
						}
						break;
					case 5:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("cow skin");
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("kangaroo skin");
								break;
							case 1:
								madeItem.setMaterial("wolverine skin");
								break;
						}
						break;
					case 7:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("bear skin");
								break;
							case 1:
								madeItem.setMaterial("wolf skin");
								break;
						}
						break;
					case 8:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("wyvern skin");
								break;
						}
						break;
					case 9:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("basilisk skin");
								break;
							case 1:
								madeItem.setMaterial("hydra skin");
								break;
						}
						break;
					case 10:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("dragon skin");
								break;
						}
						break;
					default:
						cout << "there was a problem with the leather item generator\n";
						break;
				} 
			
				switch(materialCondition) {
					case 1:
						materialConditionString = "untanned-";
						break;
					case 2:
						materialConditionString = "stunted-";
						break;
					case 3:
						materialConditionString = "blemished-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "boiled-";
						break;
					case 6:
						materialConditionString = "overgrown-";
						break;
					case 7:
						materialConditionString = "dire-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			else if (materialType == "wood") {
				switch (materialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("birch");
								break;
							case 1:
								madeItem.setMaterial("pine");
								break;
						}
						break;
					case 1:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("beech");
								break;
							case 1:
								madeItem.setMaterial("alder");
								break;
						}
						break;
					case 2:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("ash");
								break;
							case 1:
								madeItem.setMaterial("poplar");
								break;
							case 2:
								madeItem.setMaterial("oak");
								break;
						}
						break;
					case 3:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("maple");
								break;
							case 1:
								madeItem.setMaterial("cedar");
								break;
						}
						break;
					case 4:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("hickory");
								break;
							case 1:
								madeItem.setMaterial("walnut");
								break;
						}
						break;
					case 5:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("cherry");
								break;
							case 1:
								madeItem.setMaterial("osage");
								break;
						}
						break;
					case 6:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("mahogany");
								break;
							case 1:
								madeItem.setMaterial("purpleheart");
								break;
							case 2:
								madeItem.setMaterial("yew");
								break;
						}
						break;
					case 7:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("holly");
								break;
							case 1:
								madeItem.setMaterial("wenge");
								break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("teak");
								break;
							case 1:
								madeItem.setMaterial("bocote");
								break;
						}
						break;
						
					case 9:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("mesquite");
								break;
							case 1:
								madeItem.setMaterial("cocobolo");
								break;
						}
						break;
					case 10:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("ebony");
								break;
							case 1:
								madeItem.setMaterial("lignum vitae");
								break;
						}
						break;
					default:
						cout << "there was a problem with the wood item generator\n";
						break;
				} 
			
				switch(materialCondition) {
					case 1:
						materialConditionString = "warped-";
						break;
					case 2:
						materialConditionString = "checked-";
						break;
					case 3:
						materialConditionString = "knotty-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "seasoned-";
						break;
					case 6:
						materialConditionString = "quartersawn-";
						break;
					case 7:
						materialConditionString = "riftsawn-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			else if (materialType == "gem") {
				switch (materialQuality) {
					case 0:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("glass");
								break;
							case 1:
								madeItem.setMaterial("malachite");
								break;
							case 2:
								madeItem.setMaterial("chrysoberyl");
								break;
						}
						break;
					case 1:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("quartz");
								break;
							case 1:
								madeItem.setMaterial("jasper");
								break;
							case 2:
								madeItem.setMaterial("obsidian");
								break;
						}
						break;
					case 2:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("onyx");
								break;
							case 1:
								madeItem.setMaterial("lapiz lazuli");
								break;
							case 2:
								madeItem.setMaterial("agate");
								break;
						}
						break;
					case 3:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("jet");
								break;
							case 1:
								madeItem.setMaterial("amber");
								break;
							case 2:
								madeItem.setMaterial("turquoise");
								break;
						}
						break;
					case 4:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("jade");
								break;
							case 1:
								madeItem.setMaterial("topaz");
								break;
							case 2:
								madeItem.setMaterial("moonstone");
								break;
						}
						break;
					case 5:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("tourmaline");
								break;
							case 1:
								madeItem.setMaterial("opal");
								break;
							case 2:
								madeItem.setMaterial("amethyst");
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("garnet");
								break;
							case 1:
								madeItem.setMaterial("peridot");
								break;
						}
						break;
					case 7:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("aquamarine");
								break;
							case 1:
								madeItem.setMaterial("spinel");
								break;
							case 2:
								madeItem.setMaterial("zircon");
							break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("saphire");
								break;
							case 1:
								madeItem.setMaterial("alexandrite");
							break;
						}
						break;
					case 9:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("ruby");
								break;
							case 1:
								madeItem.setMaterial("emerald");
								break;
						}
						break;
					case 10:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("diamond");
								break;
						}
						break;
					default:
						cout << "there was a problem with the gem item generator\n";
						break;
				} 
			
				switch(materialCondition) {//possibly add inclusions, and maybe cut types
					case 1:
						materialConditionString = "rough-";
						break;
					case 2:
						materialConditionString = "rough-cut-";
						break;
					case 3:
						materialConditionString = "poorly-cut-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "well-cut-";
						break;
					case 6:
						materialConditionString = "polished-";
						break;
					case 7:
						materialConditionString = "brilliant-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			else if (materialType == "cloth") {
				switch (materialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("sack cloth");
								break;
							case 1:
								madeItem.setMaterial("duck cloth");
								break;
						}
						break;
					case 1:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("oil cloth");
								break;
							case 1:
								madeItem.setMaterial("canvas");
								break;
						}
						break;
					case 2:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("felt");
								break;
							case 1:
								madeItem.setMaterial("flannel");
								break;
							
						}
						break;
					case 3:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("cotton");
								break;
							case 1:
								madeItem.setMaterial("corduroy");
								break;
						}
						break;
					case 4:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("fleece");
								break;
							case 1:
								madeItem.setMaterial("camel hair");
								break;
						}
						break;
					case 5:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("tweed");
								break;
							case 1:
								madeItem.setMaterial("hemp");
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("velvet");
								break;
							case 1:
								madeItem.setMaterial("shetland wool");
								break;
						}
						break;
					case 7:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("linen");
								break;
							case 1:
								madeItem.setMaterial("alpacca wool");
								break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("mohair");
								break;
							case 1:
								madeItem.setMaterial("lambswool");
								break;
						}
						break;
					case 9:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("merino wool");
								break;
							case 1:
								madeItem.setMaterial("angora wool");
								break;
						}
						break;
					case 10:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("silk");
								break;
							case 1:
								madeItem.setMaterial("cashmere");
								break;
						}
						break;
					default:
						cout << "there was a problem with the cloth item generator\n";
						break;
				} 
			
				switch(materialCondition) {
					case 1:
						materialConditionString = "scrap-";
						break;
					case 2:
						materialConditionString = "threadbare-";
						break;
					case 3:
						materialConditionString = "patched-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "dyed-";
						break;
					case 6:
						materialConditionString = "supple-";
						break;
					case 7:
						materialConditionString = "damask-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			else if (materialType ==  "wood/metal") {//make it name the wood as itemSecondMaterial
				switch (materialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("copper");
								break;
							case 1:
								madeItem.setMaterial("nickel");
								break;
						}
						break;
					case 1:
						switch (rand() % 3) {
							case 0:
								madeItem.setMaterial("brass");
								break;
							case 1:
								madeItem.setMaterial("tin");
								break;
							case 2:
								madeItem.setMaterial("pewter");
								break;
						}
						break;
					case 2:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("pig iron");
								break;
							case 1:
								madeItem.setMaterial("bronze");
								break;
						}
						break;
					case 3:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("iron");
								break;
							case 1:
								madeItem.setMaterial("lead");
								break;
						}
						break;
					case 4:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("wrought iron");
								break;
						}
						break;
					case 5:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("steel");
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("titanium");
								break;
							case 1:
								madeItem.setMaterial("damascus");
								break;
						}
						break;
					case 7:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("tungsten");
								break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								madeItem.setMaterial("mithril");
								break;
							case 1:
								madeItem.setMaterial("vibranium");
								break;
						}
						break;
					case 9:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("adamantine");
								break;
						}
						break;
					case 10:
						switch (rand() % 1) {
							case 0:
								madeItem.setMaterial("adamantine");
								break;
						}
						break;
					default:
						cout << "there was a problem with the metal item generator\n";
						break;
				} 
				itemSecondMaterial = " and ";
				switch (secondMaterialQuality) {
					case 0:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "birch";
								break;
							case 1:
								itemSecondMaterial += "pine";
								break;
						}
						break;
					case 1:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "beech";
								break;
							case 1:
								itemSecondMaterial += "alder";
								break;
						}
						break;
					case 2:
						switch (rand() % 3) {
							case 0:
								itemSecondMaterial += "ash";
								break;
							case 1:
								itemSecondMaterial += "poplar";
								break;
							case 2:
								itemSecondMaterial += "oak";
								break;
						}
						break;
					case 3:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "maple";
								break;
							case 1:
								itemSecondMaterial += "cedar";
								break;
						}
						break;
					case 4:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "hickory";
								break;
							case 1:
								itemSecondMaterial += "walnut";
								break;
						}
						break;
					case 5:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "cherry";
								break;
							case 1:
								itemSecondMaterial += "osage";
								break;
						}
						break;
					case 6:
						switch (rand() % 3) {
							case 0:
								itemSecondMaterial += "mahogany";
								break;
							case 1:
								itemSecondMaterial += "purpleheart";
								break;
							case 2:
								itemSecondMaterial += "yew";
								break;
						}
						break;
					case 7:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "holly";
								break;
							case 1:
								itemSecondMaterial += "wenge";
								break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "teak";
								break;
							case 1:
								itemSecondMaterial += "bocote";
								break;
						}
						break;
						
					case 9:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "mequite";
								break;
							case 1:
								itemSecondMaterial += "cocobolo";
								break;
						}
						break;
					case 10:
						switch (rand() % 2) {
							case 0:
								itemSecondMaterial += "ebony";
								break;
							case 1:
								itemSecondMaterial += "lignum vitae";
								break;
						}
						break;
					default:
						cout << "there was a problem with the wood item generator\n";
						break;
				} 
		
				switch(materialCondition) {
					case 1:
						materialConditionString = "pitted-";
						break;
					case 2:
						materialConditionString = "dented-";
						break;
					case 3:
						materialConditionString = "tarnished-";
						break;
					case 4:
						materialConditionString = "";
						break;
					case 5:
						materialConditionString = "polished-";
						break;
					case 6:
						materialConditionString = "mirror-finished-";
						break;
					case 7:
						materialConditionString = "refined-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
			}
			
			
			//sets base names and base stats
			if (equipSlot == "feet") {
				madeItem.setEquipmentResistBludgeoning(level * (heaviness) / 2 + rand() % level);
				madeItem.setEquipmentResistSlashing(level * (heaviness) / 2 + rand() % level);
				madeItem.setEquipmentResistPiercing(level * (heaviness) / 2 + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "slippers";
								break;
								case 1:
									itemBaseName = "sandals";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "slippers";
								break;
								case 1:
									itemBaseName = "sandals";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "shoes";
								break;
								case 1:
									itemBaseName = "moccasins";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "shoes";
								break;
								case 1:
									itemBaseName = "moccasins";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "boots";
								break;
								case 1:
									itemBaseName = "boots";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "boots";
								break;
								case 1:
									itemBaseName = "boots";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "chain boots";
								break;
								case 1:
									itemBaseName = "scale boots";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "hobnail boots";
								break;
								case 1:
									itemBaseName = "hobnail boots";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "hobnail boots";
								break;
								case 1:
									itemBaseName = "splint boots";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "sabatons";
								break;
								case 1:
									itemBaseName = "sabatons";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "sabatons";
								break;
								case 1:
									itemBaseName = "sabatons";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "hands") {
				madeItem.setEquipmentResistBludgeoning(level * (heaviness) / 2 + rand() % level);
				madeItem.setEquipmentResistSlashing(level * (heaviness) / 2 + rand() % level);
				madeItem.setEquipmentResistPiercing(level * (heaviness) / 2 + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "half gloves";
								break;
								case 1:
									itemBaseName = "glovelettes";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "half gloves";
								break;
								case 1:
									itemBaseName = "glovelettes";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "handwraps";
								break;
								case 1:
									itemBaseName = "handwraps";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "handwraps";
								break;
								case 1:
									itemBaseName = "handwraps";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "gloves";
								break;
								case 1:
									itemBaseName = "mitts";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "gloves";
								break;
								case 1:
									itemBaseName = "mitts";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "chain gloves";
								break;
								case 1:
									itemBaseName = "chain mitts";
								break;
								case 2:
									itemBaseName = "scale gloves";
								break;
								case 3:
									itemBaseName = "scale mitts";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "heavy gloves";
								break;
								case 1:
									itemBaseName = "heavy gloves";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "clamshell gauntlets";
								break;
								case 1:
									itemBaseName = "splint gauntlets";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "gauntlets";
								break;
								case 1:
									itemBaseName = "gauntlets";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "gauntlets";
								break;
								case 1:
									itemBaseName = "gauntlets";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "arms") {
				madeItem.setEquipmentResistBludgeoning(3 * level * (heaviness) / 4 + rand() % level);
				madeItem.setEquipmentResistSlashing(3 * level * (heaviness) / 4 + rand() % level);
				madeItem.setEquipmentResistPiercing(3 * level * (heaviness) / 4 + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "sleeves";
								break;
								case 1:
									itemBaseName = "wristbands";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "wristguards";
								break;
								case 1:
									itemBaseName = "wristbands";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "armwraps";
								break;
								case 1:
									itemBaseName = "cuffs";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "armwraps";
								break;
								case 1:
									itemBaseName = "cuffs";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "bracers";
								break;
								case 1:
									itemBaseName = "bracers";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "bracers";
								break;
								case 1:
									itemBaseName = "bracers";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "chain bracers";
								break;
								case 1:
									itemBaseName = "scale bracers";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "vambraces";
								break;
								case 1:
									itemBaseName = "manica";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "vambraces";
								break;
								case 1:
									itemBaseName = "manica";
								break;
								case 2:
									itemBaseName = "splint vambraces";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "vambrace and rerebraces";
								break;
								case 1:
									itemBaseName = "vambrace and rerebraces";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "vambrace and rerebraces";
								break;
								case 1:
									itemBaseName = "vambrace and rerebraces";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "legs") {
				madeItem.setEquipmentResistBludgeoning(3 * level * (heaviness) / 4 + rand() % level);
				madeItem.setEquipmentResistSlashing(3 * level * (heaviness) / 4 + rand() % level);
				madeItem.setEquipmentResistPiercing(3 * level * (heaviness) / 4 + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "breeches";
								break;
								case 1:
									itemBaseName = "slacks";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "breeches";
								break;
								case 1:
									itemBaseName = "slacks";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "pants";
								break;
								case 1:
									itemBaseName = "trousers";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "pants";
								break;
								case 1:
									itemBaseName = "trousers";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "kilt";
								break;
								case 1:
									itemBaseName = "trews";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "lederhosen";
								break;
								case 1:
									itemBaseName = "lederhosen";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "chain skirt";
								break;
								case 1:
									itemBaseName = "scale skirt";
								break;
								case 2:
									itemBaseName = "chain chauses";
								break;
								case 3:
									itemBaseName = "scale chauses";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "chaps";
								break;
								case 1:
									itemBaseName = "scale skirt";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "faulds";
								break;
								case 1:
									itemBaseName = "greaves";
								break;
								case 2:
									itemBaseName = "splint greaves";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cuises";
								break;
								case 1:
									itemBaseName = "cuises";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cuises";
								break;
								case 1:
									itemBaseName = "cuises";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "shoulders") {
				madeItem.setEquipmentResistBludgeoning(level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistSlashing(level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistPiercing(level * (heaviness) + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "shawl";
								break;
								case 1:
									itemBaseName = "scarf";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "shawl";
								break;
								case 1:
									itemBaseName = "shawl";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cape";
								break;
								case 1:
									itemBaseName = "wrap";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cape";
								break;
								case 1:
									itemBaseName = "wrap";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cloak";
								break;
								case 1:
									itemBaseName = "overcoat";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cloak";
								break;
								case 1:
									itemBaseName = "overcoat";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "chain mantle";
								break;
								case 1:
									itemBaseName = "scale mantle";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "spaulders";
								break;
								case 1:
									itemBaseName = "spaulders";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "spaulders";
								break;
								case 1:
									itemBaseName = "splint spaulders";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "pauldrons";
								break;
								case 1:
									itemBaseName = "pauldrons";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "pauldrons";
								break;
								case 1:
									itemBaseName = "pauldrons";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "head") {
				madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "beret";
								break;
								case 1:
									itemBaseName = "pointed hat";
								break;
								case 2:
									itemBaseName = "veil";
								break;
								case 3:
									itemBaseName = "top hat";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "beret";
								break;
								case 1:
									itemBaseName = "top hat";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "hood";
								break;
								case 1:
									itemBaseName = "fez";
								break;
								case 2:
									itemBaseName = "cap";
								break;
								case 3:
									itemBaseName = "tam o'shanter";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "hood";
								break;
								case 1:
									itemBaseName = "fez";
								break;
								case 2:
									itemBaseName = "cap";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "turban";
								break;
								case 1:
									itemBaseName = "cowl";
								break;
								case 2:
									itemBaseName = "deerstalker";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cowl";
								break;
								case 1:
									itemBaseName = "skullcap";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "chain coif";
								break;
								case 1:
									itemBaseName = "scale coif";
								break;
								case 2:
									itemBaseName = "kettlehat";
								break;
								case 3:
									itemBaseName = "skullcap";
								break;
							}
						}
					break;
					
					case 4:
						if (materialType == "leather") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "barbute";
								break;
								case 1:
									itemBaseName = "spangenhelm";
								break;
								case 2:
									itemBaseName = "kabuto";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 5) {
								case 0:
									itemBaseName = "sallet";
								break;
								case 1:
									itemBaseName = "barbute";
								break;
								case 2:
									itemBaseName = "burgonet";
								break;
								case 3:
									itemBaseName = "spangenhelm";
								break;
								case 4:
									itemBaseName = "kabuto";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "bassinet";
								break;
								case 1:
									itemBaseName = "armet";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "sallet with bevor";
								break;
								case 1:
									itemBaseName = "great helm";
								break;
								case 2:
									itemBaseName = "bassinet";
								break;
								case 3:
									itemBaseName = "armet";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			
			}
			else if (equipSlot == "torso") {
				madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
				madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
				switch(heaviness) {
					case 1:
						if (materialType == "cloth") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "robes";
								break;
								case 1:
									itemBaseName = "blouse";
								break;
								case 2:
									itemBaseName = "tunic";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "tunic";
								break;
								case 1:
									itemBaseName = "tunic";
								break;
							}
						}
					break;
					case 2:
						if (materialType == "cloth") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "doublet";
								break;
								case 1:
									itemBaseName = "jacket";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "doublet";
								break;
								case 1:
									itemBaseName = "jacket";
								break;
							}
						}
					break;
					case 3:
						if (materialType == "cloth") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "padded jack";
								break;
								case 1:
									itemBaseName = "gambeson";
								break;
								case 2:
									itemBaseName = "aketon";
								break;
							}
						}
						else if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "jerkin";
								break;
								case 1:
									itemBaseName = "padded jack";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 6) {
								case 0:
									itemBaseName = "chain byrnie";
								break;
								case 1:
									itemBaseName = "scale byrnie";
								break;
								case 2:
									itemBaseName = "chain haubergeon";
								break;
								case 3:
									itemBaseName = "scale haubergeon";
								break;
								case 4:
									itemBaseName = "chain hauberk";
								break;
								case 5:
									itemBaseName = "scale hauberk";
								break;
							}
						}
					break;
					case 4:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "lorica segmentata";
								break;
								case 1:
									itemBaseName = "lamellar";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "lorica segmentata";
								break;
								case 1:
									itemBaseName = "lamellar";
								break;
								case 2:
									itemBaseName = "splint breastplate";
								break;
							}
						}
					break;
					
					case 5:
						if (materialType == "leather") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "brigandine";
								break;
								case 1:
									itemBaseName = "coat of plates";
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "cuirass";
								break;
								case 1:
									itemBaseName = "peascod breastplate";
								break;
							}
						}
					break;
					
					default:
						cout << "there was something that went wrong with the itemBaseName generator";
				}
			}
			else if (equipSlot == "equippable") {
				switch(heaviness) {
					case 1:
						if (materialType == "wood") {
							switch (rand() % 7) {
								case 0:
									itemBaseName = "baton";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "cane";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "wand";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(85);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
									if(rand() % 100 + 1 <= 20) {
										numberOfEnchantments++;
									}
								break;
								case 3:
									itemBaseName = "rod";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(85);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
									if(rand() % 100 + 1 <= 10) {
										numberOfEnchantments++;
									}
								break;
								case 4:
									itemBaseName = "scepter";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "tonfa";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "buckler";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 8) {
								case 0:
									itemBaseName = "stilleto";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(20);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "dagger";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(60);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "punching dagger";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(75);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "seax";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(60);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "dirk";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(60);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "rod";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "rondel dagger";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(25);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(75);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "kunai";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(40);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(50);//sets damage type percentages
								break;
								case 8:
									itemBaseName = "tanto";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(70);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 9:
									itemBaseName = "buckler";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "wood/metal") {
							switch (rand() % 1) {
								case 0:
									itemBaseName = "buckler";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								
							}
						}
					break;
					case 2:
						if (materialType == "wood") {
							switch (rand() % 7) {
								case 0:
									itemBaseName = "truncheon";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "nightstick";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "cudgel";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "nunchaku";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "light quarterstaff";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "shillelagh";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "targe";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 11) {
								case 0:
									itemBaseName = "shortsword";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(5);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(45);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "gladius";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(5);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(45);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(50);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "rapier";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(0);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(20);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "kukri";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(65);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(25);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "sickle";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(5);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(55);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "kama";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(5);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(55);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "falcata";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(60);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "kopis";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(55);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 8:
									itemBaseName = "wakizashi";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(75);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 9:
									itemBaseName = "xiphos";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(5);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(55);//sets damage type percentages
								break;
								case 10:
									itemBaseName = "targe";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "wood/metal") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "short spear";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(75);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "pitch fork";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "targe";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
					break;
					case 3:
						if (materialType == "wood") {
							switch (rand() % 4) {
								case 0:
									itemBaseName = "club";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "quarterstaff";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "round shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								case 3:
									itemBaseName = "heater shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 10) {
								case 0:
									itemBaseName = "longsword";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "saber";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(70);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "scimitar";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(75);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "warhammer";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(90);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(5);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "hooked warhammer";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(70);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(25);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "khopesh";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(55);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "chain";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "spiked chain";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 8:
									itemBaseName = "round shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								case 9:
									itemBaseName = "heater shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "wood/metal") {
							switch (rand() % 9) {
								case 0:
									itemBaseName = "longspear";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(75);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "trident";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "partisan";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(20);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(70);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "naginata";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(35);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(55);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "scythe";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(35);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "mace";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(85);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(5);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "morningstar";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(55);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(35);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "flail";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 8:
									itemBaseName = "handaxe";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(40);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
								break;
							}
						}
					break;
					case 4:
						if (materialType == "wood") {
							switch (rand() % 3) {
								case 0:
									itemBaseName = "heavy club";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "kite shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								case 2:
									itemBaseName = "scutum shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 9) {
								case 0:
									itemBaseName = "hand and a half sword";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(45);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "warpick";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(40);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(60);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "falchion";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(30);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "cutlass";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(60);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "katana";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(70);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "heavy chain";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "spiked heavy chain";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "kite shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
								case 8:
									itemBaseName = "scutum shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "wood/metal") {
							switch (rand() % 7) {
								case 0:
									itemBaseName = "heavy mace";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(85);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(5);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "two-handed flail";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(15);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "lucerne hammer";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(80);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "halberd";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(35);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(25);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "glaive";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(30);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 5:
									itemBaseName = "ranseur";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(85);//sets damage type percentages
								break;
								case 6:
									itemBaseName = "guisarme";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 7:
									itemBaseName = "voulge";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(60);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 8:
									itemBaseName = "bill hook";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 9:
									itemBaseName = "fauchard";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(10);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
								case 10:
									itemBaseName = "pike";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(15);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(5);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(80);//sets damage type percentages
								break;
							}
						}
					break;
					case 5:
						if (materialType == "wood") {
							switch (rand() % 2) {
								case 0:
									itemBaseName = "great club";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(100);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(0);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(0);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "tower shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "metal") {
							switch (rand() % 5) {
								case 0:
									itemBaseName = "greatsword";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(20);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(40);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "claymore";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(30);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(45);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(45);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "zweihander";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(35);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(35);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "flamberge";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(35);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(45);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(20);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "tower shield";
									madeItem.setEquipmentResistBludgeoning(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistSlashing(2 * level * (heaviness) + rand() % level);
									madeItem.setEquipmentResistPiercing(2 * level * (heaviness) + rand() % level);
								break;
							}
						}
						else if (materialType == "wood/metal") {
							switch (rand() % 5) {
								case 0:
									itemBaseName = "great mace";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(85);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(10);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(5);//sets damage type percentages
								break;
								case 1:
									itemBaseName = "lochabar axe";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(40);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
								break;
								case 2:
									itemBaseName = "great axe";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(40);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(50);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
								break;
								case 3:
									itemBaseName = "bardiche";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(30);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(30);//sets damage type percentages
								break;
								case 4:
									itemBaseName = "maul";
									madeItem.setEquipmentBaseAttack((level * 5 * (heaviness) + rand() % level * 5));
									madeItem.setEquipmentDamageBludgeoning(50);//sets damage type percentages
									madeItem.setEquipmentDamageSlashing(40);//sets damage type percentages
									madeItem.setEquipmentDamagePiercing(10);//sets damage type percentages
								break;
							}
						}
					break;
					default:
						cout << "there was a problem with the equippable item generator\n";
					break;
				}
			}
			
			
			//stud	embellished			encrusted	ornnamented			adorned		inlayed		
			jewelChance += 10;//start with 1% chance
			jewelChance += (materialQuality + materialCondition - 3) * 10;//raises it up to possibly 12% chance more
			if (rand() % 1000 + 1 <= jewelChance) {
				int jewelAmountDecider = rand() % 100 + 1;
				if (jewelAmountDecider <= 50) {
					jewelAmount += 1;
				}
				else if (jewelAmountDecider <= 84) {
					jewelAmount += 2;
				}
				else {
					jewelAmount += 3;
				}
			}
			if (jewelAmount > 0) {
				if (jewelAmount == 1) {
					switch(rand() % 2) {
						case 0:
							jewelDescriptor = "studded";
						break;
						case 1:
							jewelDescriptor = "embellished";
						break;
					}
				}
				else if (jewelAmount == 2) {
					switch(rand() % 2) {
						case 0:
							jewelDescriptor = "encrusted";
						break;
						case 1:
							jewelDescriptor = "ornamented";
						break;
					}
				}
				else {
					switch(rand() % 2) {
						case 0:
							jewelDescriptor = "adorned";
						break;
						case 1:
							jewelDescriptor = "inlayed";
						break;
					}
				}
				
				
				jewelQuality = materialQuality + upOrDown();
				if (jewelQuality < 0) { jewelQuality = 0;}
				if (jewelQuality > 10) { jewelQuality = 10;}
				switch (jewelQuality) {//similar material as weapon
					case 0:
						switch (rand() % 3) {
							case 0:
								jewelType ="glass-";
								break;
							case 1:
								jewelType ="malachite-";
								break;
							case 2:
								jewelType ="chrysoberyl-";
								break;
						}
						break;
					case 1:
						switch (rand() % 3) {
							case 0:
								jewelType ="quartz-";
								break;
							case 1:
								jewelType ="jasper-";
								break;
							case 2:
								jewelType ="obsidian-";
								break;
						}
						break;
					case 2:
						switch (rand() % 3) {
							case 0:
								jewelType ="onyx-";
								break;
							case 1:
								jewelType ="lapiz lazuli-";
								break;
							case 2:
								jewelType ="agate-";
								break;
						}
						break;
					case 3:
						switch (rand() % 3) {
							case 0:
								jewelType ="jet-";
								break;
							case 1:
								jewelType ="amber-";
								break;
							case 2:
								jewelType ="turquoise-";
								break;
						}
						break;
					case 4:
						switch (rand() % 3) {
							case 0:
								jewelType ="jade-";
								break;
							case 1:
								jewelType ="topaz-";
								break;
							case 2:
								jewelType ="moonstone-";
								break;
						}
						break;
					case 5:
						switch (rand() % 3) {
							case 0:
								jewelType ="tourmaline-";
								break;
							case 1:
								jewelType ="opal-";
								break;
							case 2:
								jewelType ="amethyst-";
								break;
						}
						break;
					case 6:
						switch (rand() % 2) {
							case 0:
								jewelType ="garnet-";
								break;
							case 1:
								jewelType ="peridot-";
								break;
						}
						break;
					case 7:
						switch (rand() % 3) {
							case 0:
								jewelType ="aquamarine-";
								break;
							case 1:
								jewelType ="spinel-";
								break;
							case 2:
								jewelType ="zircon-";
							break;
						}
						break;
					case 8:
						switch (rand() % 2) {
							case 0:
								jewelType ="saphire-";
								break;
							case 1:
								jewelType ="alexandrite-";
							break;
						}
						break;
					case 9:
						switch (rand() % 2) {
							case 0:
								jewelType ="ruby-";
								break;
							case 1:
								jewelType ="emerald-";
								break;
						}
						break;
					case 10:
						switch (rand() % 1) {
							case 0:
								jewelType ="diamond-";
								break;
						}
						break;
					default:
						cout << "there was a problem with the gem item generator\n";
						break;
				} 
				
				jewelCondition = materialCondition + upOrDown();
				if (jewelCondition < 1) { jewelCondition = 1;}
				if (jewelCondition > 7) { jewelCondition = 7;}
				switch(materialCondition) {//similar condition as weapon
					case 1:
						jewelMaterialConditionString = "rough-";
						break;
					case 2:
						jewelMaterialConditionString = "rough-cut-";
						break;
					case 3:
						jewelMaterialConditionString = "poorly-cut-";
						break;
					case 4:
						jewelMaterialConditionString = "";
						break;
					case 5:
						jewelMaterialConditionString = "well-cut-";
						break;
					case 6:
						jewelMaterialConditionString = "polished-";
						break;
					case 7:
						jewelMaterialConditionString = "brilliant-";
						break;
					default:
						cout << "there was a problem with the material condition naming\n\n";
						break;
				}
				
				
				jewelDescriptor = jewelMaterialConditionString + jewelType + jewelDescriptor + " ";
			}
			
			
			itemSpecialName = itemSpecialName + jewelDescriptor + materialConditionString + madeItem.getMaterial() + itemSecondMaterial + " ";
			
			
			
			//this sets bonus stats
			for (int x = 1; x <= numberOfEnchantments; x++) {
				enchantmentType = rand() % 19;
				switch (enchantmentType) {
					case 0:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageFire(level * (10) + rand() % level);
						}
						else {
							madeItem.setEquipmentResistFire(level * (5) + rand() % level);
						}
						
						itemSpecialName = "fiery " + itemSpecialName;
						break;
					case 1:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageCold(level * (10) + rand() % level);
						}
						else {
							madeItem.setEquipmentResistCold(level * (5) + rand() % level);
						}
						itemSpecialName = "icy " + itemSpecialName;
						break;
					case 2:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageLightning(level * (10) + rand() % level);
						}
						else {
							madeItem.setEquipmentResistLightning(level * (5) + rand() % level);
						}
						itemSpecialName = "shocking " + itemSpecialName;
						break;
					case 3:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageLight(level * (10) + rand() % level);
						}
						else {
							madeItem.setEquipmentResistLight(level * (5) + rand() % level);
						}
						itemSpecialName = "glowing " + itemSpecialName;
						break;
					case 4:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageDark(level * (10) + rand() % level);
						}
						else {
							madeItem.setEquipmentResistDark(level * (5) + rand() % level);
						}
						itemSpecialName = "dark " + itemSpecialName;
						break;
					case 5:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamagePoison(level * (10) + rand() % level);
							itemSpecialName = "poisonous " + itemSpecialName;
						}
						else {
							madeItem.setEquipmentResistPoison(level * (5) + rand() % level);
							itemSpecialName = "poison resistant " + itemSpecialName;
						}
						
						break;
					case 6:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							madeItem.setEquipmentDamageManaEnergy(level * (10) + rand() % level);
							itemSpecialName = "energetic " + itemSpecialName;
						}
						else {
							madeItem.setEquipmentResistManaEnergy(level * (5) + rand() % level);
							itemSpecialName = "shielded " + itemSpecialName;
						}
						
						break;
					case 7:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							itemSpecialName = "impacting " + itemSpecialName;
							madeItem.setEquipmentDamageBludgeoning(madeItem.getEquipmentDamageBludgeoning() + 10);
						}
						else {
							itemSpecialName = "unyielding " + itemSpecialName;
							madeItem.setEquipmentResistBludgeoning(madeItem.getEquipmentResistBludgeoning() + level * (5) + rand() % level);
						}
						break;
					case 8:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							itemSpecialName = "keen " + itemSpecialName;
							madeItem.setEquipmentDamageSlashing(madeItem.getEquipmentDamageSlashing() + 10);
						}
						else {
							itemSpecialName = "edge-catching " + itemSpecialName;
							madeItem.setEquipmentResistSlashing(madeItem.getEquipmentResistSlashing() + level * (5) + rand() % level);
						}
						break;
					case 9:
						if (rand() % 10 == 0 || equipSlot == "equippable" ) {
							itemSpecialName = "impaling " + itemSpecialName;
							madeItem.setEquipmentDamagePiercing(madeItem.getEquipmentDamagePiercing() + 10);
						}
						else {
							itemSpecialName = "point-catching " + itemSpecialName;
							madeItem.setEquipmentResistPiercing(madeItem.getEquipmentResistPiercing() + level * (5) + rand() % level);
						}
						break;
					case 10:
						itemSpecialName = "light " + itemSpecialName;
						madeItem.setHeaviness(madeItem.getHeaviness() - 2);
						break;
					case 11:
						itemSpecialName = "thick " + itemSpecialName;
						madeItem.setHeaviness(madeItem.getHeaviness() + 1);
						madeItem.setEquipmentResistBludgeoning(madeItem.getEquipmentResistBludgeoning() + level * (2) + rand() % level);
						madeItem.setEquipmentResistSlashing(madeItem.getEquipmentResistSlashing() + level * (2) + rand() % level);
						madeItem.setEquipmentResistPiercing(madeItem.getEquipmentResistPiercing() + level * (2) + rand() % level);
						break;
					case 12:
						itemSpecialName = "accurate " + itemSpecialName;
						madeItem.setAccuracy(madeItem.getAccuracy() + 3);
						break;
					case 13:
						itemSpecialName = "eagle eye " + itemSpecialName;
						madeItem.setAccuracy(madeItem.getAccuracy() + 6);
						break;
					case 14:
						itemSpecialName = "evasive " + itemSpecialName;
						madeItem.setEvasion(madeItem.getEvasion() + 2);
						break;
					case 15:
						itemSpecialName = "camoflage " + itemSpecialName;
						madeItem.setEvasion(madeItem.getEvasion() + 4);
						break;
					case 16:
						itemSpecialName = "lethal " + itemSpecialName;
						madeItem.setToHit(madeItem.getToHit() + level / 10 + 1);
						break;
					case 17:
						itemSpecialName = "bloodseeking " + itemSpecialName;
						madeItem.setToHit(madeItem.getToHit() + level / 5 + 1);
						break;
					case 18:
						itemSpecialName = "raging " + itemSpecialName;
						madeItem.setToHit(madeItem.getToHit() + level / 10 + 1);
						madeItem.setEquipmentBaseAttack(madeItem.getEquipmentBaseAttack() * 3 / 2);
						madeItem.setAccuracy(madeItem.getAccuracy() - 10);
						break;
					
						
					default: 
						cout << "there was a problem while enchanting the item\n\n";
						break;
				}
			}
			
			for (int x = 1; x <= numberOfDetriments; x++) {
				enchantmentType = rand() % 16 + 1;
				switch (enchantmentType) {
					case 1:
						madeItem.setEquipmentResistFire(madeItem.getEquipmentResistFire() - (level * (5) + rand() % level));
						itemSpecialName = "flammable " + itemSpecialName;
						break;
					case 2:
						madeItem.setEquipmentResistCold(madeItem.getEquipmentResistCold() - (level * (5) + rand() % level));
						itemSpecialName = "frostless " + itemSpecialName;
						break;
					case 3:
						madeItem.setEquipmentResistLightning(madeItem.getEquipmentResistLightning() - (level * (5) + rand() % level));
						itemSpecialName = "shocked " + itemSpecialName;
						break;
					case 4:
						madeItem.setEquipmentResistLight(madeItem.getEquipmentResistLight() - (level * (5) + rand() % level));
						itemSpecialName = "pale " + itemSpecialName;
						break;
					case 5:
						itemSpecialName = "dim " + itemSpecialName;
						madeItem.setEquipmentResistDark(madeItem.getEquipmentResistDark() - (level * (5) + rand() % level));
						break;
					case 6:
						itemSpecialName = "poisoned " + itemSpecialName;
						madeItem.setEquipmentResistPoison(madeItem.getEquipmentResistPoison() - (level * (5) + rand() % level));
						break;
					case 7:
						itemSpecialName = "mana burned " + itemSpecialName;
						madeItem.setEquipmentResistManaEnergy(madeItem.getEquipmentResistManaEnergy() - (level * (5) + rand() % level));
						break;
					case 8:
						itemSpecialName = "bludgeoned " + itemSpecialName;
						madeItem.setEquipmentResistBludgeoning(madeItem.getEquipmentResistBludgeoning() - (level * (5) + rand() % level));
						break;
					case 9:
						itemSpecialName = "slashed " + itemSpecialName;
						madeItem.setEquipmentResistSlashing(madeItem.getEquipmentResistSlashing() - (level * (5) + rand() % level));
						break;
					case 10:
						itemSpecialName = "pierced " + itemSpecialName;
						madeItem.setEquipmentResistPiercing(madeItem.getEquipmentResistPiercing() - (level * (5) + rand() % level));
						break;
					case 11:
						itemSpecialName = "inaccurate " + itemSpecialName;
						madeItem.setAccuracy(madeItem.getAccuracy() - 3);
						break;
					case 12:
						itemSpecialName = "bat eye " + itemSpecialName;
						madeItem.setAccuracy(madeItem.getAccuracy() - 6);
						break;
					case 13:
						itemSpecialName = "easily seen " + itemSpecialName;
						madeItem.setEvasion(madeItem.getEvasion() - 2);
						break;
					case 14:
						itemSpecialName = "unevasive " + itemSpecialName;
						madeItem.setEvasion(madeItem.getEvasion() - 4);
						break;
					case 15:
						itemSpecialName = "unlethal " + itemSpecialName;
						madeItem.setToHit(madeItem.getToHit() - level / 10 - 1);
						break;
					case 16:
						itemSpecialName = "terribly unlethal " + itemSpecialName;
						madeItem.setToHit(madeItem.getToHit() - level / 5 - 1);
						break;
					default: 
						cout << "there was a problem while enchanting the item\n\n";
						break;
				}
			}
			
			int jewelContribution = 0;
			if (jewelAmount > 0) {
				jewelContribution = jewelQuality + jewelCondition - 8;
			}
			int totalMaterialQuality = materialQuality + materialCondition + jewelContribution;
			
			//goherenow work on getting the negatives to work without canceling out
			madeItem.setEquipmentResistFire(madeItem.getEquipmentResistFire() + (madeItem.getEquipmentResistFire() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistCold(madeItem.getEquipmentResistCold() + (madeItem.getEquipmentResistCold() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistLightning(madeItem.getEquipmentResistLightning() + (madeItem.getEquipmentResistLightning() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistLight(madeItem.getEquipmentResistLight() + (madeItem.getEquipmentResistLight() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistDark(madeItem.getEquipmentResistDark() + (madeItem.getEquipmentResistDark() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistPoison(madeItem.getEquipmentResistPoison() + (madeItem.getEquipmentResistPoison() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistManaEnergy(madeItem.getEquipmentResistManaEnergy() + (madeItem.getEquipmentResistManaEnergy() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistBludgeoning(madeItem.getEquipmentResistBludgeoning() + (madeItem.getEquipmentResistBludgeoning() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentResistSlashing(madeItem.getEquipmentResistSlashing() + (madeItem.getEquipmentResistSlashing() * (totalMaterialQuality - 8) / 10) );  
			madeItem.setEquipmentResistPiercing(madeItem.getEquipmentResistPiercing() + (madeItem.getEquipmentResistPiercing() * (totalMaterialQuality - 8) / 10) );
			
			madeItem.setEquipmentDamageFire(madeItem.getEquipmentDamageFire() + (madeItem.getEquipmentDamageFire() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageCold(madeItem.getEquipmentDamageCold() + (madeItem.getEquipmentDamageCold() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageLightning(madeItem.getEquipmentDamageLightning() + (madeItem.getEquipmentDamageLightning() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageLight(madeItem.getEquipmentDamageLight() + (madeItem.getEquipmentDamageLight() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageDark(madeItem.getEquipmentDamageDark() + (madeItem.getEquipmentDamageDark() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamagePoison(madeItem.getEquipmentDamagePoison() + (madeItem.getEquipmentDamagePoison() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageManaEnergy(madeItem.getEquipmentDamageManaEnergy() + (madeItem.getEquipmentDamageManaEnergy() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageBludgeoning(madeItem.getEquipmentDamageBludgeoning() + (madeItem.getEquipmentDamageBludgeoning() * (totalMaterialQuality - 8) / 10) ); 
			madeItem.setEquipmentDamageSlashing(madeItem.getEquipmentDamageSlashing() + (madeItem.getEquipmentDamageSlashing() * (totalMaterialQuality - 8) / 10) );  
			madeItem.setEquipmentDamagePiercing(madeItem.getEquipmentDamagePiercing() + (madeItem.getEquipmentDamagePiercing() * (totalMaterialQuality - 8) / 10) );
			
			if (madeItem.getQuickness() > 0) {
					madeItem.setQuickness(madeItem.getQuickness() + (madeItem.getQuickness() * (totalMaterialQuality - 8) / 10) );
			}
			
			madeItem.setEquipmentBaseAttack(madeItem.getEquipmentBaseAttack() + (madeItem.getEquipmentBaseAttack() * (totalMaterialQuality - 8) / 10) ); 
			
			//price = 25*L^2 with 20% jumps for material quality
			
			int effectiveLevel = (level + (numberOfEnchantments - numberOfDetriments) * 2);
			int totalPrice = effectiveLevel * effectiveLevel * 25 + effectiveLevel * effectiveLevel * 25 * (totalMaterialQuality - 8) / 5;
			
			
			madeItem.setName(itemSpecialName + itemBaseName );
			madeItem.setEquipSlot(equipSlot);
			madeItem.setPrice(totalPrice);
			if (display) {madeItem.viewItem();}
			return madeItem;
		}
		
		void addItems(int itemChanceTimesTen, int averageLevelItem) {
			//cout << "adding items\n";
			int x,y;
			int variability;
			int thisItemLevel;
			
			for ( x = 0; x < xMapWidth; x++) {//initialize all object locations on the map, and places money
				for ( y = 0; y < yMapLength; y++) {
					if ((rand() % 1000 + 1) <= itemChanceTimesTen && (grid[x][y])->getPassable()) {
						//cout << "found an item location to add stuff\n";
						
						variability = rand() % 3 - 1;
						if (variability < averageLevelItem) {
							thisItemLevel = averageLevelItem - variability;
						}
						else {
							thisItemLevel = averageLevelItem;
						}
						
						
						putInPile(x,y,createItem(thisItemLevel, " ", 0,0) );
					}
				}
			}
		}
		
		//suggest iterations=200 maxRadius=10 minRadius=1
		void addElevation(int iterations, int maxRadius, int minRadius, int maxElevation, int worldSeed) {
			srand(worldSeed);
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int hillCenterX = 0, hillCenterY = 0;
			int hillHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				hillCenterX = rand() % xMapWidth;
				hillCenterY = rand() % yMapLength;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 == 1) {//1 in 5 chance to be a pit instead of a hill
					pit = true;	
					radius--;
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x <= xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
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
			for ( x = 0; x <= xMapWidth; x++) {//finds min and max heights
					for ( y = 0; y <= yMapLength; y++) {
						if ((grid[x][y])->getElevation() > maximumFound) {
							maximumFound = (grid[x][y])->getElevation();
						}
						if ((grid[x][y])->getElevation() < minimumFound) {
							minimumFound = (grid[x][y])->getElevation();
						}
					}
			}
			int elevationRange = maximumFound-minimumFound;
			for ( x = 0; x <= xMapWidth; x++) {//normalizes it so that the minimum is zero and max is 20
				for ( y = 0; y <= yMapLength; y++) {
					(grid[x][y])->setElevation((maxElevation*(grid[x][y])->getElevation() - minimumFound)/(elevationRange) );
				}
			}
			if (getMinElevation() < 0) {
				int newMinimumFound = getMinElevation();
				for ( x = 0; x <= xMapWidth; x++) {//double checks that it is above zero
					for ( y = 0; y <= yMapLength; y++) {
						(grid[x][y])->setElevation( (grid[x][y])->getElevation() - newMinimumFound );
					}
				}
			}

		}
		
		
		void BresenhamLineDig(int x1,int y1,int const x2,int const y2, int width, int depth) {
			int delta_x(x2 - x1);
							
			
			// if x1 == x2, then it does not matter what we set here
			signed char const ix((delta_x > 0) - (delta_x < 0));
			delta_x = std::abs(delta_x) << 1;
		 
			int delta_y(y2 - y1);
			// if y1 == y2, then it does not matter what we set here
			signed char const iy((delta_y > 0) - (delta_y < 0));
			delta_y = std::abs(delta_y) << 1;
		 
		 
			if (delta_x >= delta_y)
			{
				// error may go below zero
				int error(delta_y - (delta_x >> 1));
		 
				while (x1 != x2)
				{
					for (int digX = x1 - (width / 2); digX <= x1 + (width / 2); digX++) {
						for (int digY = y1 - (width / 2); digY <= y1 + (width / 2); digY++) {
							if(digX == x1 && digY == y1) {//if it is in the middle drops the full depth
								digMap[digX][digY] = 1;
								//(grid[digX][digY])->setElevation( (grid[digX][digY])->getElevation() - depth);
							}
							else if (digX >= 0 && digY >= 0 && digX <= xMapWidth && digY <= yMapLength && (digMap[digX][digY] == 0 || digMap[digX][digY] > 2)) {
								digMap[digX][digY] = 2;
							}
							
						}
					}
					if ((error >= 0) && (error || (ix > 0)))
					{
						error -= delta_x;
						y1 += iy;
					}
					// else do nothing
		 
					error += delta_y;
					x1 += ix;
					
					
				}
			}
			else
			{
				// error may go below zero
				int error(delta_x - (delta_y >> 1));
		 
				while (y1 != y2)
				{
					for (int digX = x1 - (width / 2); digX <= x1 + (width / 2); digX++) {
						for (int digY = y1 - (width / 2); digY <= y1 + (width / 2); digY++) {
							if(digX == x1 && digY == y1) {//if it is in the middle drops the full depth
								digMap[digX][digY] = 1;
								//(grid[digX][digY])->setElevation( (grid[digX][digY])->getElevation() - depth);
							}
							else if (digX >= 0 && digY >= 0 && digX <= xMapWidth && digY <= yMapLength && (digMap[digX][digY] == 0 || digMap[digX][digY] > 2) ) {
								digMap[digX][digY] = 2;
							}
						}
					}
					
					if ((error >= 0) && (error || (iy > 0)))
					{
						error -= delta_y;
						x1 += ix;
					}
					// else do nothing
		 
					error += delta_x;
					y1 += iy;
		 
					
				}
			}
			
		}
		

		
		void addValleys(int iterations, int numberOfCorners, int minWidth, int maxWidth, int depth) {
			int startingSide, endingSide;
			int startX, startY, endX, endY;
			int valleyMap[xMapWidth][yMapLength];//0:nothing, 1:corner, 2:valleyBed
			int cornerX[10000];
			int cornerY[10000];
			bool usedCorners[10000];
			int totalCorners = 0;
			int inOrderCornerX[10000];
			int inOrderCornerY[10000];
			int totalOrderedCorners = 0;
			int maxElevation = getMaxElevation();
			int minElevation = getMinElevation();
			int elevationRange = maxElevation - minElevation;
			int width = rand() % (maxWidth - minWidth) + minWidth;
			
			
			startingSide = rand() % 4 + 1;
			endingSide = rand() % 4 + 1;
			
			while (startingSide == endingSide) {
				endingSide = rand() % 4 + 1;
			}
			
			
			//sets the starting location depending on what edge it starts on
			if (startingSide == 1) {
				startX = 0;
				startY = rand() % yMapLength; 
			}
			if (startingSide == 2) {
				startX = xMapWidth;
				startY = rand() % yMapLength; 
			}
			if (startingSide == 3) {
				startX = rand() % xMapWidth;
				startY = 0; 
			}
			if (startingSide == 4) {
				startX = rand() % xMapWidth;
				startY = yMapLength; 
			}
			
			//sets the ending location depending on what edge it ends on
			if (endingSide == 1) {
				endX = 0;
				endY = rand() % yMapLength; 
			}
			if (endingSide == 2) {
				endX = xMapWidth;
				endY = rand() % yMapLength; 
			}
			if (endingSide == 3) {
				endX = rand() % xMapWidth;
				endY = 0; 
			}
			if (endingSide == 4) {
				endX = rand() % xMapWidth;
				endY = yMapLength; 
			}
			
			if ( (grid[endX][endY])->getElevation() > (grid[startX][startY])->getElevation() ) {
				int xHolder = startX;
				int yHolder = startY;
				int sideHolder = startingSide;
				startX = endX;
				startY = endY;
				startingSide = endingSide;
				endX = xHolder;
				endY = yHolder;
				endingSide = startingSide;
				
			}
			
			
			
			cout << "start " << startX << "," << startY << endl;
			cout << "end " << endX << "," << endY << endl;
			
			//assigns locations for the corner possibilities
			for (int x = 1; x<xMapWidth; x++) {
				for (int y = 1; y<yMapLength; y++) {
					valleyMap[x][y] = 0;
					
					if (rand() % (elevationRange * elevationRange) + elevationRange < (maxElevation - getGridElevation(x,y)) * 10 ) {//lower elevations have higher chance
						bool farEnough = true;
						for (int j=0; j<=totalCorners - 1; j++) {//cycles through corners
							if ( sqrt( (x - cornerX[j]) * (x - cornerX[j]) + (y - cornerY[j]) * (y - cornerY[j]) )  <= 4) {//not within 5 spaces of another corner
								farEnough = false;
							}
						}
						
						if (farEnough) {
							valleyMap[x][y] = 1;
							cornerX[totalCorners] = x;
							cornerY[totalCorners] = y;
							usedCorners[totalCorners] = false;//this is for when i lay them in order later
							
							//cout << "new corner possibility: " << x << "," << y << endl;
							totalCorners++;
							
						}
						
						
						
					}
					
				}
			}
			cornerX[totalCorners] = endX;
			cornerY[totalCorners] = endY;
			usedCorners[totalCorners] = false;//this is for when i lay them in order later
			totalCorners++; 
			
			
			
			int thisSpotX=startX;
			int thisSpotY=startY;
			int thisElevation = (grid[thisSpotX][thisSpotY])->getElevation();
			int fails = 0;
			int bestCorner;
			inOrderCornerX[totalOrderedCorners] = thisSpotX;
			inOrderCornerY[totalOrderedCorners] = thisSpotY;
			totalOrderedCorners++;
			bestCorner = 1;
			while(1) {//finds all the best corners
				
				cout << "\n\nfound an ordered corner " << thisSpotX << "," << thisSpotY << endl;
				int bestCornerQuality = 10000000;//lower numbers are better
				
				for (int j=0; j<=totalCorners; j++) {//find the next corner
					if ( !(usedCorners[j]) ) {
						int nextCornerCheckX = cornerX[j];
						int nextCornerCheckY = cornerY[j];
						int nextCornerDistance = sqrt( (nextCornerCheckX - thisSpotX) * (nextCornerCheckX - thisSpotX) + (nextCornerCheckY - thisSpotY) * (nextCornerCheckY - thisSpotY ) );
						int nextCornerDistanceFromEnd = sqrt( (endX - nextCornerCheckX)*(endX - nextCornerCheckX) + (endY - nextCornerCheckY)*(endY - nextCornerCheckY) );
						int nextCornerElevationIncrease = (grid[nextCornerCheckX][nextCornerCheckX])->getElevation() - thisElevation;
						//int nextCornerQuality = nextCornerDistance * nextCornerDistanceFromEnd * nextCornerDistanceFromEnd * nextCornerDistanceFromEnd + nextCornerElevationIncrease * 10000 ;
						int nextCornerQuality = nextCornerDistance * 2 + nextCornerDistanceFromEnd + nextCornerElevationIncrease * 2  ;
						//cout << "nextCornerQuality" << cornerX[j] << "," << cornerY[j] << "  " << nextCornerQuality << endl;
						
						if (nextCornerQuality < bestCornerQuality && (thisSpotX != nextCornerCheckX || thisSpotY != nextCornerCheckY) ) {
							
							bestCorner = j;
							bestCornerQuality = nextCornerQuality;
							cout << "nextCornerQuality" << cornerX[j] << "," << cornerY[j] << "  " << nextCornerQuality << "    new best:" << bestCorner << ":" << bestCornerQuality << endl;
							cout << "^^corner distance " << nextCornerDistance << "  end distance " << nextCornerDistanceFromEnd << "   elevation " << nextCornerElevationIncrease << endl;
						}
					}
				}
				usedCorners[bestCorner] = true;
				thisSpotX = cornerX[bestCorner];
				thisSpotY = cornerY[bestCorner];
				thisElevation = (grid[thisSpotX][thisSpotY])->getElevation();
				
				inOrderCornerX[totalOrderedCorners] = thisSpotX;
				inOrderCornerY[totalOrderedCorners] = thisSpotY;
				totalOrderedCorners++;
				
				
				if (thisSpotX == endX && thisSpotY == endY) {
					break;
				}	
				fails ++;
				if (fails > 100) {
					
					break;
				}
			}
			
			
			for(int i = 1; i<totalOrderedCorners; i++ ) {
				cout << "Corner: " << i - 1 << endl << inOrderCornerX[i - 1] << "," << inOrderCornerY[i - 1] << endl;
				BresenhamLineDig(inOrderCornerX[i-1], inOrderCornerY[i-1], inOrderCornerX[i], inOrderCornerY[i], width, depth);
			}
			for(int x = 0; x < xMapWidth; x++) {
				for(int y = 0; y < yMapLength; y++) {
					if (digMap[x][y] > 0) {
						(grid[x][y])->setElevation( (grid[x][y])->getElevation() - (depth / digMap[x][y]) );
					}
				}
			}
			
			cout << "Total corners " << totalCorners << endl;
			
		}
		
		//suggest iterations=40 maxRadius=8 minRadius=1
		void addArcane(int iterations, int maxRadius, int minRadius, int maxPeak) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % xMapWidth;
				peakCenterY = rand() % yMapLength;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 4 + 1 <= 2) {//50% chance to be a pit
					pit = true;	
					radius--;
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
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
			for ( x = 0; x < xMapWidth; x++) {//finds min and max areas
					for ( y = 0; y <= yMapLength; y++) {
						if ((grid[x][y])->getArcane() > maximumFound) {
							maximumFound = (grid[x][y])->getArcane();
						}
						if ((grid[x][y])->getArcane() < minimumFound) {
							minimumFound = (grid[x][y])->getArcane();
						}
					}
			}
			int arcaneRange = maximumFound-minimumFound;
			for ( x = 0; x < xMapWidth; x++) {//normalizes it so that the minimum is zero and max is the maxPeak
				for ( y = 0; y <= yMapLength; y++) {
					
					(grid[x][y])->setArcane((maxPeak*(grid[x][y])->getArcane() + minimumFound)/(arcaneRange) );
					int arcaneBoost = 1;
					if (grid[x][y]->getSquareType() == "flag stone") {
						arcaneBoost = 3;
					}
						
					(grid[x][y])->setArcane((grid[x][y])->getArcane() * arcaneBoost);
				}
			}
		}
		
		//suggest iterations=40 maxRadius=8 minRadius=1
		void addDivine(int iterations, int maxRadius, int minRadius, int maxPeak) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int minimumFound = 10000, maximumFound = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % xMapWidth;
				peakCenterY = rand() % yMapLength;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 <= 2) {//40% chance to be a pit
					pit = true;	
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
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
			for ( x = 0; x < xMapWidth; x++) {//finds min and max areas
					for ( y = 0; y <= yMapLength; y++) {
						if ((grid[x][y])->getDivine() > maximumFound) {
							maximumFound = (grid[x][y])->getDivine();
						}
						if ((grid[x][y])->getDivine() < minimumFound) {
							minimumFound = (grid[x][y])->getDivine();
						}
					}
				}
			int divineRange = maximumFound - minimumFound;
			for ( x = 0; x < xMapWidth; x++) {//normalizes it so that the minimum is zero and max is the maxPeak
				for ( y = 0; y <= yMapLength; y++) {
					(grid[x][y])->setDivine((maxPeak*(grid[x][y])->getDivine() + minimumFound)/(divineRange) );
					int divineHeightBoost = (grid[x][y])->getElevation() * 175 / getMaxElevation() + 25;//makes it go from 25 to 200 based on elevation
					(grid[x][y])->setDivine((grid[x][y])->getDivine() * divineHeightBoost / 100);
				}
			}

		}
		
		int findTotalArcaneUnderlay() {
			int x=0, y=0;
			int totalArcaneUnderlayTemp = 0;
			
			
			for ( x = 0; x < xMapWidth; x++) {
				for ( y = 0; y <= yMapLength; y++) {
					if (grid[x][y]->getArcaneUnderlay() > 0 ) {
						totalArcaneUnderlayTemp += grid[x][y]->getArcaneUnderlay();
					}
					else {
						totalArcaneUnderlayTemp -= grid[x][y]->getArcaneUnderlay();
					}
				}
			}
			return totalArcaneUnderlayTemp;
		}
		
		int findTotalDivineUnderlay() {
			int x=0, y=0;
			int totalDivineUnderlayTemp = 0;
			
			
			for ( x = 0; x < xMapWidth; x++) {
				for ( y = 0; y <= yMapLength; y++) {
					if (grid[x][y]->getDivineUnderlay() > 0 ) {
						totalDivineUnderlayTemp += grid[x][y]->getDivineUnderlay();
					}
					else {
						totalDivineUnderlayTemp -= grid[x][y]->getDivineUnderlay();
					}
				}
			}
			return totalDivineUnderlayTemp;
		}
		
		void addManaUnderlay() {
			int x=0, y=0;
			
			
			for ( x = 0; x < xMapWidth; x++) {
				for ( y = 0; y <= yMapLength; y++) {
					grid[x][y]->setDivineUnderlay( grid[x][y]->getDivine() );
					grid[x][y]->setArcaneUnderlay( grid[x][y]->getArcane() ); 
				}
			}
		}
		
		void updateManaUnderlayEffects() {
			int x=0, y=0;
			int disparity = 0;
			
			for ( x = 0; x < xMapWidth; x++) {
				for ( y = 0; y <= yMapLength; y++) {
					disparity = grid[x][y]->getDivineUnderlay() - grid[x][y]->getDivine();
					grid[x][y]->setDivine(grid[x][y]->getDivine() + disparity / 4);
					grid[x][y]->setDivineUnderlay(grid[x][y]->getDivineUnderlay() - disparity / 8);
					
					disparity = grid[x][y]->getArcaneUnderlay() - grid[x][y]->getArcane();
					grid[x][y]->setArcane(grid[x][y]->getArcane() + disparity / 4);
					grid[x][y]->setArcaneUnderlay(grid[x][y]->getArcaneUnderlay() - disparity / 8);
				}
			}
		}
		
		
		void manaDivineUnderlayVibrations(int iterations, int maxRadius, int minRadius) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int goalTotalDivineUnderlay = findTotalDivineUnderlay() * (rand() % 20 + 106) / 100 + 500;//extra to account for rounding
			int multiplyPercent = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % xMapWidth;
				peakCenterY = rand() % yMapLength;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 <= 2) {//50% chance to be a pit
					pit = true;	
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
						peakHeight = radius*radius-((x-peakCenterX)*(x-peakCenterX)+(y-peakCenterY)*(y-peakCenterY));
						//peakHeight = peakHeight / 2; //makes the peak flatter
						if (peakHeight > 0) {//if the peak point is greater than zero
							if (pit) {
								peakHeight = - peakHeight;//makes it a pit
							}
							
							int divineHeightBoost = (grid[x][y])->getElevation() * 175 / getMaxElevation() + 25;//makes it go from 25 to 200 based on elevation
							peakHeight = peakHeight * divineHeightBoost / 100;
							(grid[x][y])->setDivineUnderlay(peakHeight + (grid[x][y])->getDivineUnderlay() );//then it gets added to the map
							
						}
					}
				}
				
				
			}
			
			//setting multiply percent
			multiplyPercent = goalTotalDivineUnderlay * 100 / findTotalDivineUnderlay();
			//cout << "total underlay " << findTotalDivineUnderlay() << " goal total " << goalTotalDivineUnderlay << endl;
			//cout << "multiply percent " << multiplyPercent << endl;
			
			for ( x = 0; x < xMapWidth; x++) {//normalizes it so that the total mana underlay is similar to before
				for ( y = 0; y <= yMapLength; y++) {
					(grid[x][y])->setDivineUnderlay( (grid[x][y])->getDivineUnderlay() * multiplyPercent / 100);
					//(grid[x][y])->setDivineUnderlay((maxPeak*(grid[x][y])->getDivineUnderlay())/(maximumFound-minimumFound) );
					//int divineHeightBoost = (grid[x][y])->getElevation() * 175 / getMaxElevation() + 25;//makes it go from 25 to 200 based on elevation
					//(grid[x][y])->setDivine((grid[x][y])->getDivine() * divineHeightBoost / 100);
				}
			}

		
		}
		
		void manaArcaneUnderlayVibrations(int iterations, int maxRadius, int minRadius) {
			int x=0, y=0, i=0;
			int zCoord = 0;
			int radius = 0;
			int peakCenterX = 0, peakCenterY = 0;
			int peakHeight = 0;
			int goalTotalArcaneUnderlay = findTotalArcaneUnderlay() * (rand() % 20 + 106) / 100 + 500;//extra to account for rounding
			int multiplyPercent = 0;
			bool pit;
			
			
			for (i=0; i<=iterations; i++) {
				peakCenterX = rand() % xMapWidth;
				peakCenterY = rand() % yMapLength;
				radius = rand()%(maxRadius-minRadius)+minRadius;
				if (rand() % 5 + 1 <= 2) {//50% chance to be a pit
					pit = true;	
				}
				else {
					pit = false;
				}
				
				for ( x = 0; x < xMapWidth; x++) {
					for ( y = 0; y <= yMapLength; y++) {
						peakHeight = radius*radius-((x-peakCenterX)*(x-peakCenterX)+(y-peakCenterY)*(y-peakCenterY));
						//peakHeight = peakHeight / 2;
						if (peakHeight > 0) {//if the peak point is greater than zero
							if (pit) {
								peakHeight = - peakHeight;//makes it a pit
							}
							int arcaneBoost = 1;
							if (grid[x][y]->getSquareType() == "flag stone") {
								arcaneBoost = 3;
								peakHeight = peakHeight * arcaneBoost;
							}
								
							
							(grid[x][y])->setArcaneUnderlay(peakHeight + (grid[x][y])->getArcaneUnderlay() );//then it gets added to the map
						}
					}
				}
				
				
			}
			
			//setting multiply percent
			multiplyPercent = goalTotalArcaneUnderlay * 100 / findTotalArcaneUnderlay();
			
			for ( x = 0; x < xMapWidth; x++) {//normalizes it so that the total mana underlay is similar to before
				for ( y = 0; y <= yMapLength; y++) {
					(grid[x][y])->setArcaneUnderlay( (grid[x][y])->getArcaneUnderlay() * multiplyPercent / 100);
					//(grid[x][y])->setArcaneUnderlay((maxPeak*(grid[x][y])->getArcaneUnderlay())/(maximumFound-minimumFound) );
					//int divineHeightBoost = (grid[x][y])->getElevation() * 175 / getMaxElevation() + 25;//makes it go from 25 to 200 based on elevation
					//(grid[x][y])->setArcane((grid[x][y])->getArcane() * divineHeightBoost / 100);
				}
			}

		
		}
		
		void addManaClouds(int percentChance, int numberOfClouds, int minRadius, int maxRadius, int minChaosChance, int maxChaosChance, int minChaosFactor, int maxChaosFactor, int minIntensityPercent, int maxIntensityPercent, int minMinimumIntensity, int maxMinimumIntensity) {
			
			int chaosChanceRange = maxChaosChance - minChaosChance;
			int chaosFactorRange = maxChaosFactor - minChaosFactor;
			int radiusRange = maxRadius - minRadius;
			int intensityPercentRange = maxIntensityPercent - minIntensityPercent;
			int minimumIntensityRange = maxMinimumIntensity - minMinimumIntensity;
			
			for (int cloudNumber = 1; cloudNumber <= numberOfClouds; cloudNumber++) {
				int Radius = rand() % radiusRange + minRadius + 1;
				int ChaosChance = rand() % chaosChanceRange + minChaosChance + 1;
				int ChaosFactor = rand() % chaosFactorRange + minChaosFactor + 1;
				int IntensityPercent = rand() % intensityPercentRange + minIntensityPercent + 1;
				int MinimumIntensity = rand() % minimumIntensityRange + minMinimumIntensity + 1;
				
				int PositionX = rand() % xMapWidth, PositionY = rand() % yMapLength, VelocityX = rand() % (xMapWidth / 10), VelocityY = rand() % (yMapLength / 10);
				if (PositionX > xMapWidth / 2) {
					VelocityX = VelocityX * (-1);
				}
				if (PositionY > yMapLength / 2) {
					VelocityY = VelocityY * (-1);
				}
				
				if (rand() % 3 == 0) {
					MinimumIntensity = MinimumIntensity * (-1);
					IntensityPercent = IntensityPercent * (-1);
				}
				
				bool cloudMade = false;
				
				if (rand() % 100 + 1 <= percentChance) {
					for (int x = 1; x <= totalManaClouds; x++) {
						if (manaCloudList[x]->positionY == 0 && manaCloudList[x]->positionX == 0) {
							delete manaCloudList[totalManaClouds];
							manaCloudList[totalManaClouds] = new cloud(Radius, ChaosChance, ChaosFactor, PositionX, PositionY, VelocityX, VelocityY, IntensityPercent, MinimumIntensity);
							
							cloudMade = true;
						}
					}
					if (!(cloudMade)) {
						
						totalManaClouds++;
						manaCloudList[totalManaClouds] = new cloud(Radius, ChaosChance, ChaosFactor, PositionX, PositionY, VelocityX, VelocityY, IntensityPercent, MinimumIntensity);
					}
				}
			}
			
		}
		
		void manaCloudUpdate() {
			int changeIntensityChance = 0, changeVelocityChance = 0;
			for (int x = 1; x <= totalManaClouds; x++) {
				changeIntensityChance = rand() % 100 + 1;
				changeVelocityChance = rand() % 100 + 1;
				if (manaCloudList[x]->chaosChance >= changeIntensityChance) {
					if (rand() % 2 == 1) {
						manaCloudList[x]->minimumIntensity += manaCloudList[x]->chaosFactor;
					}
					else {
						manaCloudList[x]->minimumIntensity -= manaCloudList[x]->chaosFactor;
					}
				}
				if (manaCloudList[x]->chaosChance >= changeVelocityChance) {
					int newVelocityDirection = rand() % 4;
					if (newVelocityDirection == 0) {
						manaCloudList[x]->velocityX += manaCloudList[x]->chaosFactor;
					}
					else if (newVelocityDirection == 1) {
						manaCloudList[x]->velocityX -= manaCloudList[x]->chaosFactor;
					}
					else if (newVelocityDirection == 2) {
						manaCloudList[x]->velocityY += manaCloudList[x]->chaosFactor;
					}
					else if (newVelocityDirection == 3) {
						manaCloudList[x]->velocityY -= manaCloudList[x]->chaosFactor;
					}
				} 
				
				if (manaCloudList[x]->positionX + manaCloudList[x]->velocityX > 0 && manaCloudList[x]->positionX + manaCloudList[x]->velocityX < xMapWidth) {
					manaCloudList[x]->positionX += manaCloudList[x]->velocityX;
					
					if (manaCloudList[x]->positionY + manaCloudList[x]->velocityY > 0 && manaCloudList[x]->positionY + manaCloudList[x]->velocityY < yMapLength) {
						manaCloudList[x]->positionY += manaCloudList[x]->velocityY;
					}
					else {
						delete manaCloudList[x];
						manaCloudList[x] = new cloud();
						addManaClouds(50,1,1,4, 0, 50, 0, 5, 10,50,2,10);
						
					}
				}
				else {
					delete manaCloudList[x];
					manaCloudList[x] = new cloud();
					addManaClouds(50,1,1,4, 0, 50, 0, 5, 10,50,2,10);
				}
			}
			
		}
		
		void cloudInfoCheck () {
			for (int x = 1; x <= totalManaClouds; x++) {
				cout << "cloud " << x << endl;
				cout << "location " << "(" << manaCloudList[x]->positionX << "," << manaCloudList[x]->positionY << ")" << endl;
				cout << "velocity " << "(" << manaCloudList[x]->velocityX << "," << manaCloudList[x]->velocityY << ")" << endl;
				cout << "radius " << manaCloudList[x]->radius;
				cout << "\nchaos chance " << manaCloudList[x]->chaosChance;
				cout << "\nchaos factor " << manaCloudList[x]->chaosFactor;
				cout << "\nintensity percent " << manaCloudList[x]->intensityPercent;
				cout << "\nminimum intensity " << manaCloudList[x]->minimumIntensity;
				cout << endl << endl;
			}
		}
		
		void manaCloudFactor(int &manaAmount, int xPos, int yPos) {
			int distance = 0;
			
			for (int x = 1; x <= totalManaClouds; x++) {
				if (manaCloudList[x]->radius * manaCloudList[x]->radius >= (xPos - manaCloudList[x]->positionX) * (xPos - manaCloudList[x]->positionX)  + (yPos - manaCloudList[x]->positionY) * (yPos - manaCloudList[x]->positionY) ) {
					manaAmount = manaAmount + manaAmount * (100 + manaCloudList[x]->minimumIntensity + manaCloudList[x]->intensityPercent * ( manaCloudList[x]->radius * manaCloudList[x]->radius - (xPos - manaCloudList[x]->positionX) * (xPos - manaCloudList[x]->positionX) - (yPos - manaCloudList[x]->positionY) * (yPos - manaCloudList[x]->positionY) )) / 100 /100;
					
				}
			}
		}
		
		void manaCloudValue(int &value, int xPos, int yPos) {
			int distance = 0;
			
			for (int x = 1; x <= totalManaClouds; x++) {
				if (manaCloudList[x]->radius * manaCloudList[x]->radius >= (xPos - manaCloudList[x]->positionX) * (xPos - manaCloudList[x]->positionX)  + (yPos - manaCloudList[x]->positionY) * (yPos - manaCloudList[x]->positionY) ) {
					value += manaCloudList[x]->minimumIntensity + manaCloudList[x]->intensityPercent * ( manaCloudList[x]->radius * manaCloudList[x]->radius - (xPos - manaCloudList[x]->positionX) * (xPos - manaCloudList[x]->positionX) - (yPos - manaCloudList[x]->positionY) * (yPos - manaCloudList[x]->positionY) ) / 100;
					
				}
			}
		}
		
		void addSiegeWeapons(int siegeWeaponChanceTimesTen, int averagePlayerLevel) {
			int x, y;
			
			for ( x = 0; x < xMapWidth; x++) {
				for ( y = 0; y <= yMapLength; y++) {
					if (rand() % 1000 + 1 <= siegeWeaponChanceTimesTen && getGridPassable(x,y)) {
						setGridSiegeWeapon(x,y,1,averagePlayerLevel);
					}
					
				}
			}
		}
		
		
		int countAliveNeighbours(bool map[100][100], int x, int y){
			int count = 0;
			for(int i=-1; i<2; i++){
				for(int j=-1; j<2; j++){
					int neighbourX = x+i;
					int neighbourY = y+j;
					//If we're looking at the middle point
					if(i == 0 && j == 0){
						//Do nothing, we don't want to add ourselves in!
					}
					//In case the index we're looking at it off the edge of the map
					else if(neighbourX <= 0 || neighbourY <= 0 || neighbourX >= xMapWidth || neighbourY >= yMapLength){
						count = count + 1;
					}
					//Otherwise, a normal check of the neighbour
					else if(map[neighbourX][neighbourY]){
						count = count + 1;
					}
				}
			}
			return count;
		}
		
		
		
		
		void placeTreasure(bool world[100][100], int minGold, int maxGold){
			//How hidden does a spot need to be for treasure?
			//I find 5 or 6 is good. 6 for very rare treasure.
			int treasureHiddenLimit = 5;
			for (int x=0; x < xMapWidth; x++){
				for (int y=0; y < yMapLength; y++){
					if(!world[x][y]){
						int nbs = countAliveNeighbours(world, x, y);
						if(nbs >= treasureHiddenLimit + 1) {
							(grid[x][y])->setGold((rand()%(maxGold - minGold)+minGold));
						}
						else if(nbs >= treasureHiddenLimit && rand() % 2 == 1){
							(grid[x][y])->setGold((rand()%(maxGold - minGold)+minGold) / 2);
						}
					}
				}
			}
		}
		
  
		
		//suggest chanceToStartAlive=45
		void addCaves(int chanceToStartAlive, int numberOfSteps, int deathLimit, int birthLimit, int minGold, int maxGold, int worldSeed) {
			srand(worldSeed);
			
			bool cellMap[100][100];//true means rock, false means open area
 
			
			for(int x=0; x <= xMapWidth; x++){
				for(int y=0; y <= yMapLength; y++){
					if(rand() % 100 + 1 < chanceToStartAlive){
						cellMap[x][y] = true;
					}
				}
			}
			
			
			for(int i=0; i<numberOfSteps; i++){
				bool newMap[100][100];
				 //Loop over each row and column of the map
				 
				for(int x=0; x<= xMapWidth; x++){
					for(int y=0; y<= yMapLength; y++){
						int nbs = countAliveNeighbours(cellMap, x, y);
						
						//The new value is based on our simulation rules
						//First, if a cell is alive but has too few neighbours, kill it.
						if(cellMap[x][y]){
							if(nbs < deathLimit){
								newMap[x][y] = false;
							}
							else{
								newMap[x][y] = true;
							}
						} //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
						else{
							if(nbs > birthLimit){
								newMap[x][y] = true;
							}
							else{
								newMap[x][y] = false;
							}
						}
					}
				}
				
				
				//copies the new map over
				for(int x=0; x<= xMapWidth; x++){
					for(int y=0; y<= yMapLength; y++){
						cellMap[x][y] = newMap[x][y];
					}
				}
				
				
			}
			
			
			
			
			for(int x=0; x<= xMapWidth; x++){
				for(int y=0; y<= yMapLength; y++){
					
					if (cellMap[x][y] ) {
						delete grid[x][y];
						grid[x][y] = NULL;
						grid[x][y] = new wallSquare();
					}
					else {
						delete grid[x][y];
						grid[x][y] = NULL;
						grid[x][y] = new mapSquare();
					}	
				}
			}
			placeTreasure(cellMap, minGold, maxGold);
		}
		
		
		int getRoomCenterX(int roomNumber) {
			return (roomMap[roomNumber])->roomCenterX;
		}
		int getRoomCenterY(int roomNumber) {
			return (roomMap[roomNumber])->roomCenterY;
		}
		int getRoomWidth(int roomNumber) {
			return (roomMap[roomNumber])->roomWidth;
		}
		int getRoomLength(int roomNumber) {
			return (roomMap[roomNumber])->roomLength;
		}
		int getTotalRooms() {
			return totalRooms;
		}
		int getFarthestRoom(int firstRoom) {
			
			int farthestRoom;
			int farthestRoomDistance = 0;
			for (int j=1; j<=totalRooms - 1; j++) {
				int farthestRoomCheckX = (roomMap[j])->roomCenterX;
				int farthestRoomCheckY = (roomMap[j])->roomCenterY;
				int thisRoomDistance = sqrt( (farthestRoomCheckX - (roomMap[firstRoom])->roomCenterX) * (farthestRoomCheckX - (roomMap[firstRoom])->roomCenterX) + (farthestRoomCheckY - (roomMap[firstRoom])->roomCenterY) * (farthestRoomCheckY - (roomMap[firstRoom])->roomCenterY) );
				
				if (thisRoomDistance >= farthestRoomDistance ) {
					farthestRoom = j;
					farthestRoomDistance = thisRoomDistance;
				}
			}	
			return farthestRoom;		
		}
		
		void hCorridor(int x1, int x2,int y) {//makes the corridor of open tiles
			
			int x;
			for (x = min(x1,x2);x <= max(x1,x2);x++) {
				
				
				delete grid[x][y];
				grid[x][y] = NULL;
				grid[x][y] = new mapSquare();
			}
		}
		
		void vCorridor(int y1, int y2,int x) {//makes the corridor of open tiles
			
			int y;
			for (y=min(y1,y2);y<=max(y1,y2);y++) {
				delete grid[x][y];
				grid[x][y] = NULL;
				grid[x][y] = new mapSquare();
			}
		}
		
		void addDungeons(int maxRooms, int minRoomSize, int maxRoomSize, int worldSeed) {
			
			srand(worldSeed);
			int i, j;
			int failCounter = 0;
			int closestRoom = 0;
			int mainLoop;
			int roomsMade = 0;
			bool failed;
			int roomWidth, roomLength, roomx, roomy;
			int newCenterX, newCenterY;
			
			for (i=0; i<=xMapWidth; i++) // i is columns
			{
				for (j=0; j<=yMapLength; j++) // j is rows
				{			
					delete grid[i][j];
					grid[i][j] = NULL;
					grid[i][j] = new wallSquare();
					//(grid[i][j])->setElevation(10);
				}
			}
			
			for (mainLoop=0; mainLoop < maxRooms; mainLoop++) {
				roomWidth = minRoomSize + rand() % (maxRoomSize - minRoomSize);
				roomLength = minRoomSize + rand() % (maxRoomSize - minRoomSize);
				roomx = rand() % (xMapWidth - roomWidth - 1);
				roomy = rand() % (yMapLength - roomLength - 1);
				
				
				
				room* newRoom = new room(roomx, roomy, roomWidth, roomLength);
				
				failed = false;
				if (roomsMade > 0) {
					for (j=0; j<=roomsMade - 1; j++) {
						if ( (newRoom)->intersects(roomMap[j]) ) {
							
							failed = true;
							break;
						}
					}
				}
				
				if (!(failed) ) {
					failCounter = 0;
					roomMap[roomsMade] = newRoom;
					
					for (i=(newRoom)->x1; i<=(newRoom)->x2; i++) // i is columns
					{
						for (j=(newRoom)->y1; j<=(newRoom)->y2; j++) // j is rows
						{			
							delete grid[i][j];
							grid[i][j] = NULL;
							grid[i][j] = new mapSquare();
							
						}
					}
					
					
					if (roomsMade > 0 && !(checkMovePath((newRoom)->roomCenterX, (newRoom)->roomCenterY, (roomMap[roomsMade - 1])->roomCenterX, (roomMap[roomsMade - 1])->roomCenterY, 1000)) ) {//the movespeed is huge so that that isn't a factor
						
						
						int closestRoomDistance = 1000;
						for (j=0; j<=roomsMade - 1; j++) {
							int closestRoomCheckX = (roomMap[j])->roomCenterX;
							int closestRoomCheckY = (roomMap[j])->roomCenterY;
							int thisRoomDistance = sqrt( (closestRoomCheckX - (newRoom)->roomCenterX) * (closestRoomCheckX - (newRoom)->roomCenterX) + (closestRoomCheckY - (newRoom)->roomCenterY) * (closestRoomCheckY - (newRoom)->roomCenterY) );
							
							if (thisRoomDistance <= closestRoomDistance ) {
								closestRoom = j;
								closestRoomDistance = thisRoomDistance;
							}
						}
					
						
						newCenterX = (newRoom)->roomCenterX;// + rand() % 3 - 1;
						newCenterY = (newRoom)->roomCenterY;// + rand() % 3 - 1;
						
						int prevCenterX, prevCenterY;
						if (rand()%100 <= 10) {
							prevCenterX = (roomMap[roomsMade - 1])->roomCenterX  + rand() % 3 - 1;
							prevCenterY = (roomMap[roomsMade - 1])->roomCenterY + rand() % 3 - 1;
						}
						else {
							prevCenterX = (roomMap[closestRoom])->roomCenterX  + rand() % 3 - 1;
							prevCenterY = (roomMap[closestRoom])->roomCenterY + rand() % 3 - 1;
						}
						
						if (prevCenterX <= (newRoom)->x2 && prevCenterX >= (newRoom)->x1) {
							hCorridor(prevCenterX,newCenterX,prevCenterY);
							vCorridor(prevCenterY,newCenterY,newCenterX);
						} 
						else if (prevCenterY <= (newRoom)->y2 && prevCenterY >= (newRoom)->y1) {
							hCorridor(prevCenterX,newCenterX,newCenterY);
							vCorridor(prevCenterY,newCenterY,prevCenterX);
						} 
						else if (rand() % 2 == 1) {
							hCorridor(prevCenterX,newCenterX,prevCenterY);
							vCorridor(prevCenterY,newCenterY,newCenterX);
						}
						else {
							hCorridor(prevCenterX,newCenterX,newCenterY);
							vCorridor(prevCenterY,newCenterY,prevCenterX);
						}
						
						
					}
					
					roomsMade++;
				}
				else {
					
					mainLoop--;
					failCounter++;
					if (failCounter > 100000) {//if it fails a bunch, just leave loop
						
						break;
					}
				}
			}
			
			totalRooms = roomsMade;
			
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
		void setGridSeeThrough(int i, int j, bool seeThrough) {
			(grid[i][j])->setSeeThrough(seeThrough);
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
		bool getGridSeeThrough (int i, int j) {
			(grid[i][j])->getSeeThrough();
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
		int getGridDivineUnderlay (int i, int j) {
			(grid[i][j])->getDivineUnderlay();
		}
		int getGridArcaneUnderlay (int i, int j) {
			(grid[i][j])->getArcaneUnderlay();
		}
		int getMaxDivine() {
			int max = 0;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridDivine(x,y) >= max) {
						max = getGridDivine(x,y);
					}
				}
			}
			return max;
		}
		int getMaxArcane() {
			int max = 0;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridArcane(x,y) >= max) {
						max = getGridArcane(x,y);
					}
				}
			}
			return max;
		}
		int getMaxElevation() {
			int max = 0;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridElevation(x,y) >= max) {
						max = getGridElevation(x,y);
					}
				}
			}
			return max;
		}
		int getMinDivine() {
			int min = 1000;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridDivine(x,y) <= min) {
						min = getGridDivine(x,y);
					}
				}
			}
			return min;
		}
		int getMinArcane() {
			int min = 1000;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridArcane(x,y) <= min) {
						min = getGridArcane(x,y);
					}
				}
			}
			return min;
		}
		int getMinElevation() {
			int min = 1000;
			for (int x = 0; x < xMapWidth; x++) {
				for (int y = 0; y <= yMapLength; y++) {
					if (getGridElevation(x,y) <= min) {
						min = getGridElevation(x,y);
					}
				}
			}
			return min;
		}
		
		void setGridSiegeWeapon(int i, int j, int weaponType, int weaponLevel) {
			(grid[i][j])->setSiegeWeapon(weaponType, weaponLevel);
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
		
		void viewEquipmentPile(int i, int j) {
			(grid[i][j])->viewEquipmentPile();
		}
		void putInPile(int i, int j, equipment dropThisItem) {
			(grid[i][j])->putInPile(dropThisItem);
		}
		equipment removeFromPile(int i, int j, int whichItem) {
			return (grid[i][j])->removeFromPile(whichItem);
		}
		
		bool somethingInPile(int i, int j) {
			(grid[i][j])->somethingInPile();
		}
};


// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

