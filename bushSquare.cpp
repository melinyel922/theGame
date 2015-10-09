class bushSquare: public plantSquare {
	public:
		bushSquare() {
			squareType = "bush";
			passable = false;
			seeThrough = true;
			symbol = "*";
			material = 1;
		}
	
};
