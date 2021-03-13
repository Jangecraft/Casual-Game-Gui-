#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
	srand(time(NULL));
	char vs;
	int ATK,HP; //atk and hp player
	int lv=1,expl,exp=0,maxexp; //lv and exp
	int lvM=1,ATKM,HPM; //monter
	while(true){
		
		//player---------
		maxexp = lv*100;
		ATK = lv*10;
		HP = lv*100;
		//---------------
		
		//Monster---------
		ATKM = lv*10;
		HPM = lv*1000;
		//---------------

		cout <<"Casual Game V.1.1.2" <<endl <<endl ;
		cout <<"Lv   : " <<lv <<endl ;
		cout <<"Exp  : " <<exp <<"/" <<maxexp <<endl ;
		cout <<"ATK  : " <<ATK <<endl ;
		cout <<"HP   : " <<HP <<endl ;
	
		cout << "You want battle (Yes[Y] | No[N]) : ";
		cin >>vs ;
		if (vs == 'Y' || vs == 'y'){
			system("cls");
			char atkVS;
			while (true){
				cout <<"--- Player VS Monster ---" <<endl ;
				cout <<"Player HP  : " <<HP <<endl ;
				cout <<"Monster HP : " <<HPM <<endl ;
				cout <<"ATK[A] || Give up[G] : " ;
				cin >> atkVS ;
				if (atkVS == 'A' || atkVS == 'a'){
					int randomATK = rand() % 10;
					if (randomATK == 0){
						ATK = (lv*10)*2;
						cout << "Player : ATK " <<ATK <<" Critical !"<<endl;
						HPM -= ATK ;
						
						int randomATK = rand() % 10;
						if (randomATK == 0){
							ATKM = (lv*10)*2;
							cout << "Monter : ATK " <<ATKM <<" Critical !" <<endl;
							HP -= ATKM ;
						}
						else{
							ATKM = (lv*10);
							cout << "Monter : ATK " <<ATKM <<" Normal"<<endl;
							HP -= ATKM ;
						}
					}
					else{
						ATK = (lv*10);
						cout << "Player : ATK " <<ATK <<" Normal"<<endl;
						HPM -= ATK ;
						
						int randomATK = rand() % 10;
						if (randomATK == 0){
							ATKM = (lv*10)*2;
							cout << "Monter : ATK " <<ATKM <<" Critical !" <<endl;
							HP -= ATKM ;
						}
						else{
							ATKM = (lv*10);
							cout << "Monter : ATK " <<ATKM <<" Normal"<<endl;
							HP -= ATKM ;
						}
					}
				}
					else{
						cout << "you lose" <<endl ;
						getch ();
						system("cls");
						break;
				}
				
				if (HPM <= 0){
					cout << "you win" <<endl;
					expl = 100 ;
					exp = exp + expl;
					getch ();
					system("cls");
					break;
				}
				else if (HP <= 0){
					cout << "you lose" <<endl;
					expl = 10 ;
					exp = exp + expl;
					getch ();
					system("cls");
					break;
				}
				getch();
				system("cls");	
			}
		}
		else if (vs == 'N' || vs == 'n'){
			break;
		}
		else {
			cout <<"Error" <<endl ;
			break;
		}
	
		if (exp >= maxexp){
			expl = exp ;
			while (expl >= maxexp){
				maxexp = lv*100;
				
				expl = expl - maxexp ;
				lv += 1;
			}
			exp = expl;
		}
	}
	cout <<endl <<"End Game...........";
	return (0);
}
