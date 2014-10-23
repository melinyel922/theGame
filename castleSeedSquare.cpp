class castleSeedSquare: public mapSquare {
	public:
		
		castleSeedSquare() {
			
			material = 100;
			if (rand()%2 == 1) {
				material++;
			}
		}
		
 };
