// Astar.cpp
// http://en.wikipedia.org/wiki/A*
// Compiler: Dev-C++ 4.9.9.2
// FB - 201012256
//replaced "map" with "Map"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

const int n=150; // horizontal size of the Map
const int m=150; // vertical size size of the Map
static int Map[n][m];
static int elevationMap[n][m];
static int closed_nodes_Map[n][m]; // Map of closed (tried-out) nodes
static int open_nodes_Map[n][m]; // Map of open (not-yet-tried) nodes
static int dir_Map[n][m]; // Map of directions
const int dir=8; // number of possible directions to go at any position
// if dir==4
//static int dx[dir]={1, 0, -1, 0};
//static int dy[dir]={0, 1, 0, -1};
// if dir==8
static float dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static float dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

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

// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
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

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || Map[xdx][ydy]==1 
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

bool checkMovePath(int xA, int yA, int xB, int yB, int importElevationMap[150][150], bool passableMap[150][150], int moveSpeed)
{
    srand(time(NULL));

    // fill empty Maps
    for(int yCounter=0;yCounter<m;yCounter++)
    {
        for(int xCounter=0;xCounter<n;xCounter++) 
        {
			if (passableMap[xCounter][yCounter]) {
				
				Map[xCounter][yCounter]=0;
			}
			else {
				Map[xCounter][yCounter]=1;
			}
		 }
    }
    for(int yCounter=0;yCounter<m;yCounter++)
    {
        for(int xCounter=0;xCounter<n;xCounter++) 
        {
			elevationMap[xCounter][yCounter] = importElevationMap[xCounter][yCounter];//sets the elevation map
		 }
    }
    
    

  

	
    // get the route
    
    string route=pathFind(xA, yA, xB, yB);
    
    // follow the route on the Map and display it 
    
    int moveCost = 0;
    int j = 0, x = 0, y = 0;
    char c;
     
        for(int i=0;i<route.length();i++)
        {
            
            
            x=x+dx[j];
            y=y+dy[j];
            Map[x][y]=3;
        }
        
    int currentElevation = elevationMap[xA][yA]
    
    for (int i = 0; i <= route.length(); i++) {
			c =route.at(i);
			istringstream(&c) >> j;
			
			if (j == 2 || j == 4 || j == 6  || j == 8 || j == 0) {
				moveCost += 20;
				
			}
			else if (j == 1 || j == 3 || j == 5 || j == 7) {
				moveCost += 30;
			}
			x=x+dx[j];
            y=y+dy[j];
            int changeTimes5 = (elevationMap[x][y] - currentElevation) * 5
            if (changeTimes5 > 0) {
				changeTimes5 = changeTimes5 / 2;
			}
            moveCost += changeTimes5;
	}
	//int elevationChange = (elevationMap[xB][yB] - elevationMap[xA][yA]) / 2;
	//if (elevationChange < 0) {
	//	elevationChange = elevationChange / 4;
	//}
	//moveCost += elevationChange;
	moveCost = moveCost / 20; //this fixes the weighting diagonals as 1.5, and gets rid of the tens multiplier
	//cout << "route is " << route << endl;
	
    
    if(route.length() > 0 && moveCost <= moveSpeed  )
    {
		
		return true;
		/*
        int j; char c;
        int x=xA;
        int y=yA;
        Map[x][y]=2;
        for(int i=0;i<route.length();i++)
        {
            c =route.at(i);
            j=atoi(&c); 
            x=x+dx[j];
            y=y+dy[j];
            Map[x][y]=3;
        }
        Map[x][y]=4;
    
        // display the Map with the route
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(Map[x][y]==0)
                    cout<<".";
                else if(Map[x][y]==1)
                    cout<<"O"; //obstacle
                else if(Map[x][y]==2)
                    cout<<"S"; //start
                else if(Map[x][y]==3)
                    cout<<"R"; //route
                else if(Map[x][y]==4)
                    cout<<"F"; //finish
            cout<<endl;
         
        }
        */
    }
    else {
		return false;
     }
     
    return(0);
}
