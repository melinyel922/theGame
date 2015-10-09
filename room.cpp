//thanks for the help from this website http://gamedevelopment.tutsplus.com/tutorials/create-a-procedurally-generated-dungeon-cave-system--gamedev-10099

class room {
	public:
	int x1, x2, y1, y2;
	int roomWidth, roomLength;
	int roomCenterX, roomCenterY;
	
	room() {
		
	}
	
	room(int x, int y, int w, int l) {
		x1 = x;
		x2 = x + w;
		y1 = y;
		y2 = y + l;
		roomCenterX = (x1 + x2) / 2;
		roomCenterY = (y1 + y2) / 2; 
		roomWidth = w;
		roomLength = l;
		
	}
	
	bool intersects(room* Room) {
		return (x1 <= (Room)->x2 + 1 && x2 + 1 >= (Room)->x1 &&
			y1 <= (Room)->y2 + 1 && y2 + 1 >= (Room)->y1);
	}
	
	
	
	
};
