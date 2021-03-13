#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int MonsterATK (int,int);
int main ()
{
	srand(time(NULL));
	string name;
	char vs; //menu
	int ATK,HP; //atk and hp player
	int lv=1,expl,exp=0,maxexp; //lv and exp
	int Money=200,Moneyl;
	int lvM=1,ATKM,HPM; //monter
	int potionsHP1=0;
	int potionsHP2=0;
	int potionsHP3=0;
	int TNT1=0;
	
	cout << "Casual Game V.1.9.4" <<endl <<endl ;
	cout << "input name : ";
	cin >> name ;
	
	//ID Game Save (ID GM)
	if (name == "jang"){
		int password;
		cout << "input password : ";
		cin >> password;
		if (password == 1234){
			lv=100;
		}
	}
	else if (name == "jackpot"){
		int password;
		cout << "input password : ";
		cin >> password;
		if (password == 0000){
			Money = 100000 ;
		}
	}
	else if (name == "test"){
		int password;
		cout << "input password : ";
		cin >> password;
		if (password == 0){
			lv=lv;
			exp=exp;
			Money=Money;
			potionsHP1=potionsHP1;
			potionsHP2=potionsHP2;
			potionsHP3=potionsHP3;
			TNT1=TNT1;
		}
	}
	
	system("cls");
	
	while(true){
		
		//player---------
		maxexp = lv*100;
		ATK = lv*10;
		HP = lv*100;
		//---------------
		
		//Monster---------
		ATKM = lvM*12;
		HPM = lvM*120;
		//---------------

		cout <<"======================"<<endl ;
		cout <<"Player : " <<name <<endl ;
		cout <<"LV     : " <<lv <<endl ;
		cout <<"Exp    : " <<exp <<"/" <<maxexp <<endl ;
		cout <<"ATK    : " <<ATK <<endl ;
		cout <<"HP     : " <<HP <<endl ;
		cout <<"Money  : " <<Money <<endl ;
		cout <<"======================"<<endl <<endl ;
		
		cout <<"=========menu========="<<endl<<endl ; ;
		cout <<"  Battle Monster [B]"<<endl ;
		cout <<"       Item [I]"<<endl ;
		cout <<"     Exit Game [ ]"<<endl <<endl ;
		cout <<"======================"<<endl <<endl ;
	
		cout << "Please select a menu : ";
		cin >>vs ;
		system("cls");
//----------------------------------battle----------------------------------//
		if (vs == 'B' || vs == 'b'){
			while (true)
			{
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
				lvM = 1;
				Moneyl = 1;
				expl = 10 ;
			}
			else if (Difficulty == "V" || Difficulty == "v"){
				lvM = 2+(rand() % 3);
				Moneyl = 10;
				expl = 10 ;
			}
			else if (Difficulty == "E" || Difficulty == "e"){
				lvM = 5+(rand() % 5);
				Moneyl = 100;
				expl = 30 ;
			}
			else if (Difficulty == "N" || Difficulty == "n"){
				lvM = 10+(rand() % 10);
				Moneyl = 1000;
				expl = 50 ;
			}
			else if (Difficulty == "H" || Difficulty == "h"){
				lvM = 20+(rand() % 30);
				Moneyl = 10000;
				expl = 100 ;
			}
			else if (Difficulty == "I" || Difficulty == "i"){
				lvM = 50+(rand() % 150);
				Moneyl = 100000;
				expl = 1000 ;
			}
			else{
				system("cls");
				break;
			}
			system("cls");
			
					//player---------
					ATK = lv*10;
					HP = lv*100;
					//---------------
					
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
				cout <<"ATK[A] || Item[I] || Give up[ ] : " ;
				cin >> atkVS ;
				if (atkVS == 'A' || atkVS == 'a'){
					int NowATK;
					int randomATK = rand() % 10;
					if (randomATK == 0){
						NowATK = ATK*0;
						cout << "Player : ATK " <<NowATK <<" Missed..."<<endl;
						HPM -= NowATK ;
						
						HP = MonsterATK (ATKM,HP);
						
					}
					else if (randomATK == 1){
						NowATK = ATK*2;
						cout << "Player : ATK " <<NowATK <<" Critical !"<<endl;
						HPM -= NowATK ;
						
						HP = MonsterATK (ATKM,HP);
						
					}
					else{
						NowATK = ATK;
						cout << "Player : ATK " <<NowATK <<" Normal"<<endl;
						HPM -= NowATK ;
						
						HP = MonsterATK (ATKM,HP);
						
					}
				}
///////////////////////////////////////////////////////////////////////////////////
				else if (atkVS == 'I' || atkVS == 'i'){
					string wait;
					while (true){
						system("cls");
						cout <<"=============Item============="<<endl<<endl ;
						cout <<"1)potions + 10 HP     [x" <<potionsHP1 <<"]" <<endl;
						cout <<"2)potions + 20 HP     [x" <<potionsHP2 <<"]" <<endl;
						cout <<"3)potions + 30 HP     [x" <<potionsHP3 <<"]" <<endl;
						cout <<"4)TNT - 20 Monster HP [x" <<TNT1 <<"]" <<endl;
						cout <<"     Exit Item [ ]"<<endl <<endl ;
						cout <<"=============================="<<endl <<endl ;
						cout <<"Select an item  : " ;
						cin >> wait ;
						if (wait == "1"){
							if (potionsHP1 >= 1){
								potionsHP1 -= 1;
								HP += 10;
								cout << "\nPlayer : Use potions + 10 HP"<<endl;
								HP = MonsterATK (ATKM,HP);
								break;
							}
							else{
								continue;
							}
						}
						else if (wait == "2"){
							if (potionsHP2 >= 1){
								potionsHP2 -= 1;
								HP += 20;
								cout << "\nPlayer : Use potions + 20 HP"<<endl;
								HP = MonsterATK (ATKM,HP);
								break;
							}
							else{
								continue;
							}
						}
						else if (wait == "3"){
							if (potionsHP3 >= 1){
								potionsHP3 -= 1;
								HP += 30;
								cout << "\nPlayer : Use potions + 30 HP"<<endl;
								cout << "Player : Not ATK"<<endl;
								HP = MonsterATK (ATKM,HP);
								break;
							}
							else{
								continue;
							}
						}
						else if (wait == "4"){
							if (TNT1 >= 1){
								TNT1 -= 1;
								HPM -= 20;
								cout << "\nPlayer : Use TNT - 20 Monster HP"<<endl;
								getch ();
								cout << "Player : Not ATK"<<endl;
								HP = MonsterATK (ATKM,HP);
								break;
							}
							else{
								continue;
							}
						}
						else {
							cout << "Player : Not ATK"<<endl;
							HP = MonsterATK (ATKM,HP);
							break;
						}
					}
				}
///////////////////////////////////////////////////////////////////////////////////
				else{
					cout << "you lose" <<endl ;
					getch ();
					system("cls");
					break;
				}
				
				if (HPM <= 0){
					cout <<"---------you win---------" <<endl;
					
					//exp win
					exp = exp + (expl * 10);
					cout <<"You have been : " <<expl * 10 <<" EXP" <<endl; 
					
					//Money win
					Money = Money + (Moneyl * 2);
					cout <<"You have been : " <<Moneyl * 2 <<" Money" <<endl;
					
					cout <<"-------------------------" <<endl ; 
					
					getch ();
					system("cls");
					break;
				}
				else if (HP <= 0){
					cout <<"---------you lose--------" <<endl;
					
					//exp lose
					exp = exp + (expl/8);
					cout <<"You have been : " <<expl/8 <<" EXP" <<endl; 
					
					//Money lose
					Money = Money + (Moneyl / 100);
					cout <<"You have been : " <<Moneyl / 100 <<" Money" <<endl;
					
					cout <<"-------------------------" <<endl ; 
					
					getch ();
					system("cls");
					break;
				}
				getch();
				system("cls");	
			}
		}
		}
//--------------------------------------------------------------------------//

//////////////////////////////////////////////////////////////////////////////////////////////////
		else if (vs == 'I' || vs == 'i'){
			char wait;
			while (true){
				int price1=100;
				int price2=150;
				int price3=200;
				int price4=500;
				cout <<"=============Item============="<<endl<<endl ;
				cout <<"1)potions + 10 HP     [x" <<potionsHP1 <<"]" <<endl;
				cout <<"  price : 100 -" <<endl ;
				cout <<"2)potions + 20 HP     [x" <<potionsHP2 <<"]" <<endl;
				cout <<"  price : 150 -" <<endl ;
				cout <<"3)potions + 30 HP     [x" <<potionsHP3 <<"]" <<endl;
				cout <<"  price : 200 -" <<endl ;
				cout <<"4)TNT - 20 Monster HP [x" <<TNT1 <<"]" <<endl;
				cout <<"  price : 500 -" <<endl ;
				cout <<"     Exit Item [ ]"<<endl <<endl ;
				cout <<"=============================="<<endl <<endl ;
				cout <<"You have Money  : " <<Money <<endl ;
				cout <<"Select an item  : " ;
				cin >> wait ;
				if (wait == '1'){
					if (Money >= price1){
						Money = Money - price1 ;
						potionsHP1 += 1;
					}
					else {
						system("cls");
						continue;
					}
				}
				else if (wait == '2'){
					if (Money >= price2){
						Money = Money - price2 ;
						potionsHP2 += 1;
					}
					else {
						system("cls");
						continue;
					}
				}
				else if (wait == '3'){
					if (Money >= price3){
						Money = Money - price3 ;
						potionsHP3 += 1;
					}
					else {
						system("cls");
						continue;
					}
				}
				else if (wait == '4'){
					if (Money >= price4){
						Money = Money - price4 ;
						TNT1 += 1;
					}
					else {
						system("cls");
						continue;
					}
				}
				else {
					system("cls");
					break;
				}
				system("cls");
			}
			system("cls");
		}
//////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////

int MonsterATK (int ATKM,int HP){
	int NowATK;
	int randomATK = rand() % 10;
	if (randomATK == 0){
		NowATK = ATKM*0;
		cout << "Monter : ATK " <<NowATK <<" Missed..." <<endl;
		HP -= NowATK ;
	}
	else if (randomATK == 1){
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
