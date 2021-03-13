//#include <iostream>

using namespace std;

typedef struct{
	int HPx;
	int HPMx;
}allHP;

int MonsterATK (int ATKM, int HP){
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

allHP AtkVS (int ATK,int ATKM, int HP,int HPM){
	allHP all;
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
	
	all.HPx = HP ;
	all.HPMx = HPM ;
					
	return all;
}

