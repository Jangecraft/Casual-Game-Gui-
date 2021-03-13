/*
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
*/

using namespace std ;

typedef struct {
	int ruby ;
    int Stick = 0;
    int Iron_Stick = 0;
    int Iron_Sword = 0;
    int Steel_Sword = 0;
    int Gun = 0;
} weapon;

weapon G_allw (weapon w, int ruby){
	w.ruby = ruby;
	while (true){
		
			char Random_Gacha;
			cout <<"=========Gacha========="<<endl<<endl ;
 	 		cout << "ruby : " << w.ruby <<endl <<endl;
			
			cout << "Random Gacha (Yes[Y] | No[ ])";
			Random_Gacha = getch();
			
			if ((Random_Gacha == 'Y' || Random_Gacha == 'y') && w.ruby >= 20){
				int randomNumber = 1+(rand() % 100);
		 	    
		 	    cout <<endl <<endl;
		 	    
		 	    if (randomNumber == 100){
		 	    	cout <<"Legendary : Gun" <<endl <<endl ;
		 	    	w.Gun += 1;
				 }
				 else if (randomNumber >= 85 && randomNumber <= 99){
				 	cout <<"Super Epic : Steel Sword" <<endl <<endl ;
		 			w.Steel_Sword += 1;
				 }
				 else if (randomNumber >= 70 && randomNumber <= 85){
				 	cout <<"Epic : Iron Sword" <<endl <<endl ;
		 			w.Iron_Sword += 1;
				 }
				 else if (randomNumber >= 40 && randomNumber <= 70){
				 	cout <<"Rare : Iron Stick" <<endl <<endl ;
		 			w.Iron_Stick += 1;
				 }
				 else if (randomNumber >= 1 && randomNumber <= 40){
				 	cout <<"Common : Stick" <<endl <<endl ;
		 			w.Stick += 1;
				 }
				w.ruby -= 20;
		 	}
		 	else {
		 		cout <<"\n\n======================="<<endl<<endl ;
		 		break;
			}
			cout <<"======================="<<endl<<endl ;
			getch();
 			system("cls");
		}
	return w;
}
/*
int main ()
{
	srand(time(NULL));
	int ruby = 100;
	while (true){
	weapon w;
	
	w = G_allw(w,ruby);
	ruby = w.ruby;
	
	cout <<endl;
	cout <<w.Gun <<endl ;
	cout <<w.Steel_Sword <<endl ;
	cout <<w.Iron_Sword <<endl ;
	cout <<w.Iron_Stick <<endl ;
	cout <<w.Stick <<endl ;
  }
  return (0);
}
*/
