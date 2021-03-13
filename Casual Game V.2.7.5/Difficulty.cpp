/*
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
*/
using namespace std ;

typedef struct{
	unsigned long int lvM ;
	int Moneyl ;
	unsigned long int expl ;
	int exitDifficulty=0;
}wait;

wait Difficulty(wait w){
			string Difficulty ;
			cout <<"======Difficulty======"<<endl<<endl ;
			cout <<"  Super Very Easy [S]"<<endl ;
			cout <<"     Very Easy [V]"<<endl ;
			cout <<"       Easy [E]"<<endl ;
			cout <<"      Normal [N]"<<endl ;
			cout <<"       Hard [H]"<<endl ;
			cout <<"     Impossible[I]"<<endl ;
			cout <<"       Exit [ ]"<<endl <<endl ;
			cout <<"======================"<<endl <<endl ;
			cout <<"Difficulty : " ;
			cin >> Difficulty ;
			if (Difficulty == "S" || Difficulty == "s"){
				w.lvM = 1;
				w.Moneyl = 1;
				w.expl = 10 ;
			}
			else if (Difficulty == "V" || Difficulty == "v"){
				w.lvM = 2+(rand() % 3);
				w.Moneyl = 10;
				w.expl = 10 ;
			}
			else if (Difficulty == "E" || Difficulty == "e"){
				w.lvM = 5+(rand() % 5);
				w.Moneyl = 100;
				w.expl = 30 ;
			}
			else if (Difficulty == "N" || Difficulty == "n"){
				w.lvM = 10+(rand() % 10);
				w.Moneyl = 1000;
				w.expl = 50 ;
			}
			else if (Difficulty == "H" || Difficulty == "h"){
				w.lvM = 20+(rand() % 30);
				w.Moneyl = 10000;
				w.expl = 100 ;
			}
			else if (Difficulty == "I" || Difficulty == "i"){
				w.lvM = 50+(rand() % 150);
				w.Moneyl = 100000;
				w.expl = 1000 ;
			}
			else{
				system("cls");
				w.exitDifficulty = 1;
			}
			
	return w;
}
/*
int main ()
{
	int lvM ;
	int Moneyl ;
	int expl ;
	wait w;
	w = Difficulty(w);
	lvM = w.lvM ;
	Moneyl = w.Moneyl ;
	expl = w.expl ;
	
	if (w.exitDifficulty == 1){
			w.exitDifficulty == 0;
			return(0);
		}
	
}*/
