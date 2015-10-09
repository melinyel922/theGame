class wallSquare: public mapSquare {
	public:
		wallSquare() {
			squareType = "wall";
			passable = false;
			seeThrough = false;
			symbol = "O";
			material = 10;
		}
		
		
 };
