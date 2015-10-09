class castleSeedSquare: public mapSquare {
	public:
		
		castleSeedSquare() {
			
			
			material = 100;
			if (rand()%2 == 1) {
				material++;
			}
			if (rand()% 50 + 1 == 100) {
				material = 103;
			}
			
			if (material == 101 || material == 103) {//round ones and mega ones need to be bigger
				castleSize = rand() % 100 + 1;
				if (castleSize <= 50){//50%
					castleSize = 3;
				}
				else if (castleSize <= 85){//35%
					castleSize = 4;
				}
				else if (castleSize <= 100){//15%
					castleSize = 5;
				}
				if (material == 103) {
					castleSize++;
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
		}
		
		
		
 };
