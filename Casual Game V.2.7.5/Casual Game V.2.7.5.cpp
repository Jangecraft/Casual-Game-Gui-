#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "LV.cpp"
#include "VS.cpp"
#include "map.cpp"
#include "map2.cpp"
#include "Difficulty.cpp"
#include "weapon_gacha.cpp"

using namespace std;

int main ()
{
	srand(time(NULL));
	string name;
	char vs; //menu
	int ATK=0,HP=0,W_atk=1; //atk and hp player
	unsigned long int lv=1,expl,exp=0,maxexp; //lv and exp
	int Money=200,Moneyl;
	int lvM=1,ATKM=0,HPM=0; //monter
	int ruby=100 ;
	weapon w ;
	int potionsHP1=0;
	int potionsHP2=0;
	int potionsHP3=0;
	int potionsHP4=0;
	int TNT1=0;
	
	cout << "Game Beta V.2.7.5" <<endl <<endl ;
	cout << "input name : ";
	cin >> name ;
	
	//ID Game (ID GM)
	if (name == "jang"){
		int password;
		cout << "input password : ";
		cin >> password;
		rewind(stdin);
		
		if (password == 1234){
			lv=100;
		}
	}
	else if (name == "jackpot"){
		int password;
		cout << "input password : ";
		cin >> password;
		rewind(stdin);
		
		if (password == 0000){
			Money = 100000 ;
		}
	}
	else if (name == "test"){
		int password;
		cout << "input password : ";
		cin >> password;
		rewind(stdin);
		
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
		ATK = (lv*10)*W_atk;
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
		cout <<"Ruby   : " <<ruby <<endl ;
		cout <<"======================"<<endl <<endl ;
		
		cout <<"=========menu========="<<endl<<endl ;
		cout <<"  Battle Monster [B]"<<endl ;
		cout <<"       Item [I]"<<endl ;
		cout <<"        Map [M]"<<endl ;
		cout <<"       Gacha [G]"<<endl ;
		cout <<"      Weapon [W]"<<endl ;
		cout <<"     Exit Game [ ]"<<endl <<endl ;
		cout <<"======================"<<endl <<endl ;
	
		cout << "Please select a menu : ";
		cin >>vs ;
		system("cls");
//----------------------------------battle----------------------------------//
		if (vs == 'B' || vs == 'b'){
			while (true){
				
		//////////////////////////////////////////
			wait w;
			w = Difficulty(w);
			lvM = w.lvM ;
			Moneyl = w.Moneyl ;
			expl = w.expl ;
			
			if (w.exitDifficulty == 1){
					w.exitDifficulty == 0;
					break;
				}
		//////////////////////////////////////////
		
			system("cls");
			
					//player---------
					ATK = (lv*10)*W_atk;
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
					
					allHP all;
					all = AtkVS (ATK,ATKM,HP,HPM);
					HP = all.HPx ;
					HPM = all.HPMx ;
					
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
						cout <<"5)potions + 1000 HP   [x" <<potionsHP4 <<"]" <<endl;
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
						else if (wait == "5"){
							if (potionsHP4 >= 1){
								potionsHP4 -= 1;
								HP += 1000;
								cout << "\nPlayer : Use potions + 1000 HP"<<endl;
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
					
					/////////////////////LvUp/////////////////////
					rewind(stdin);
					Lv_Up up = lv_up (exp, expl, maxexp, lv, ruby);
					lv = up.lvU;
					exp = up.expU;
					ruby = up.ruby;
					/////////////////////////////////////////////
					
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
					
					/////////////////////LvUp/////////////////////
					rewind(stdin);
					Lv_Up up = lv_up (exp, expl, maxexp, lv, ruby);
					lv = up.lvU;
					exp = up.expU;
					ruby = up.ruby;
					/////////////////////////////////////////////
					
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
				int price5=10000;
				cout <<"=============Item============="<<endl<<endl ;
				cout <<"1)potions + 10 HP     [x" <<potionsHP1 <<"]" <<endl;
				cout <<"  price : 100 -" <<endl ;
				cout <<"2)potions + 20 HP     [x" <<potionsHP2 <<"]" <<endl;
				cout <<"  price : 150 -" <<endl ;
				cout <<"3)potions + 30 HP     [x" <<potionsHP3 <<"]" <<endl;
				cout <<"  price : 200 -" <<endl ;
				cout <<"4)TNT - 20 Monster HP [x" <<TNT1 <<"]" <<endl;
				cout <<"  price : 500 -" <<endl ;
				cout <<"5)potions + 1000 HP   [x" <<potionsHP4 <<"]" <<endl;
				cout <<"  price : 10000 -" <<endl ;
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
				else if (wait == '5'){
					if (Money >= price3){
						Money = Money - price5 ;
						potionsHP4 += 1;
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
		else if (vs == 'M' || vs == 'm'){
			go_to g;
			go_to2 g2;
			while (true){
				g = go (g);
				
				if (g.exitmap == 1){
					g.exitmap = 0;
					break;
				}
				else if (g.exitmap == 2){
					g.exitmap = 0;
					g2.xg = 2;
					g2.yg = 2;
					while (true){
						g2 = go2 (g2);
						
						if (g2.exitmap2 == 1){
						g2.exitmap2 = 0;
						break;
						}
					}
				}
			}
		}
//////////////////////////////////////////////////////////////////////////////////////////////////
		else if (vs == 'G' || vs == 'g'){
	
			w = G_allw(w,ruby);
			ruby = w.ruby;
				
			getch();
			system("cls");
			
		}
//////////////////////////////////////////////////////////////////////////////////////////////////
		else if (vs == 'W' || vs == 'w'){
			//while (true){
				
				cout <<"========Weapon========"<<endl<<endl ;
				cout <<"- Gun         [x" <<w.Gun <<"]" <<endl ;
				cout <<"- Steel Sword [x" <<w.Steel_Sword <<"]" <<endl ;
				cout <<"- Iron Sword  [x" <<w.Iron_Sword <<"]" <<endl ;
				cout <<"- Iron Stick  [x" <<w.Iron_Stick <<"]" <<endl ;
				cout <<"- Stick       [x" <<w.Stick <<"]" <<endl <<endl ;
				cout <<"======================"<<endl<<endl ;
				
				getch();
				system("cls");
				
  			//}
		}
//////////////////////////////////////////////////////////////////////////////////////////////////
		else {
			system("cls");
			char exit_my_game ;
			cout <<"Exit Game ? (Yes [Y]) : ";
			cin >> exit_my_game;
			system("cls");
			if (exit_my_game == 'Y' || exit_my_game == 'y'){
				break;
			}
			else {
				continue;
			}
		}
		/////////////////////LvUp/////////////////////
		rewind(stdin);
		Lv_Up up = lv_up (exp, expl, maxexp, lv, ruby);
		lv = up.lvU;
		exp = up.expU;
		ruby = up.ruby;
		/////////////////////////////////////////////
	}
	cout <<endl <<"End Game...........";
	return (0);
}
