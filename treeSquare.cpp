class treeSquare: public plantSquare {
	public:
		treeSquare() {
			squareType = "tree";
			passable = false;
			seeThrough = false;
			symbol = "^";
			material = 1;
		}
	
};
