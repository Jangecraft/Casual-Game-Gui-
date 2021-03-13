#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int PlayerVSMonster (int,int);
int MonsterATK (int,int);
int main ()
{
	srand(time(NULL));
	string name;
	char vs; //menu
	int ATK,HP; //atk and hp player
	int lv=1,expl,exp=0,maxexp; //lv and exp
	int lvM=1,ATKM,HPM; //monter
	
	cout << "Casual Game V.1.5.5" <<endl <<endl ;
	cout << "input name : ";
	cin >> name ;
	
	if (name == "jang"){
		int password;
		cout << "input password : ";
		cin >> password;
		if (password == 1234){
			lv += 99;
		}
	}
	
	system("cls");
	
	while(true){
		
		//player---------
		maxexp = lv*100;
		ATK = lv*10;
		HP = lv*100;
		//---------------

		cout <<"======================"<<endl ;
		cout <<"Player : " <<name <<endl ;
		cout <<"LV     : " <<lv <<endl ;
		cout <<"Exp    : " <<exp <<"/" <<maxexp <<endl ;
		cout <<"ATK    : " <<ATK <<endl ;
		cout <<"HP     : " <<HP <<endl ;
		cout <<"======================"<<endl <<endl ;
		
		cout <<"=========menu========="<<endl<<endl ; ;
		cout <<"  Battle Monster [B]"<<endl ;
		cout <<"     New  Game [N]"<<endl ;
		cout <<"     Exit Game [ ]"<<endl <<endl ;
		cout <<"======================"<<endl <<endl ;
	
		cout << "Please select a menu : ";
		cin >>vs ;
		if (vs == 'B' || vs == 'b'){
			system("cls");
			char Difficulty ;
			cout <<"======Difficulty======"<<endl<<endl ;
			cout <<"  Super Very Easy [S]"<<endl ;
			cout <<"     Very Easy [V]"<<endl ;
			cout <<"       Easy [E]"<<endl ;
			cout <<"      Normal [N]"<<endl ;
			cout <<"       Hard [H]"<<endl ;
			cout <<"       Exit [ ]"<<endl <<endl ;
			cout <<"======================"<<endl <<endl ;
			cout <<"Difficulty : " ;
			cin >> Difficulty ;
			if (Difficulty == 'S' || Difficulty == 's'){
				lvM = 1;
			}
			else if (Difficulty == 'V' || Difficulty == 'v'){
				lvM = 2+(rand() % 3);
			}
			else if (Difficulty == 'E' || Difficulty == 'e'){
				lvM = 5+(rand() % 5);
			}
			else if (Difficulty == 'N' || Difficulty == 'n'){
				lvM = 10+(rand() % 10);
			}
			else if (Difficulty == 'H' || Difficulty == 'h'){
				lvM = 20+(rand() % 30);
			}
			else{
				system("cls");
				break;
			}
			system("cls");
			
					//Monster---------
					ATKM = lvM*12;
					HPM = lvM*120;
					//---------------
					
			char atkVS;
			while (true){
				cout <<"--- Player VS Monster ---" <<endl ;
				cout <<"Player LV  : " <<lv <<endl ;
				cout <<"Player HP  : " <<HP <<endl ;
				cout <<"Monster LV : " <<lvM <<endl ;
				cout <<"Monster HP : " <<HPM <<endl ;
				cout <<"-------------------------" <<endl ;
				cout <<"ATK[A] || Give up[ ] : " ;
				cin >> atkVS ;
				if (atkVS == 'A' || atkVS == 'a'){
					int randomATK = rand() % 10;
					if (randomATK == 0){
						ATK = (lv*10)*2;
						cout << "Player : ATK " <<ATK <<" Critical !"<<endl;
						HPM -= ATK ;
						
						HP = MonsterATK (ATKM,HP);
						
					}
					else{
						ATK = (lv*10);
						cout << "Player : ATK " <<ATK <<" Normal"<<endl;
						HPM -= ATK ;
						
						HP = MonsterATK (ATKM,HP);
						
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

int PlayerVSMonster (int ATK,int HPM){
	
}

int MonsterATK (int ATKM,int HP){
	int NowATK;
	int randomATK = rand() % 10;
	if (randomATK == 0){
		NowATK = ATKM*2;
		cout << "Monter : ATK " <<NowATK <<" Critical !" <<endl;
		HP -= NowATK ;
	}
	else{
		NowATK = ATKM;
		cout << "Monter : ATK " <<NowATK <<" Normal"<<endl;
		HP -= NowATK ;
	}
	return HP;
}
