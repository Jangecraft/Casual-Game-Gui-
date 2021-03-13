//#include <iostream>

using namespace std;

typedef struct {
    unsigned long int lvU;
    unsigned long int expU;
    int ruby;
} Lv_Up;

Lv_Up lv_up (unsigned long int exp,unsigned long int expl, unsigned long int maxexp, unsigned long int lv,int ruby){
	Lv_Up up;
	maxexp = lv*100;
	//cout << "exp = " << exp <<endl;
	if (exp >= maxexp){
			expl = exp ;
			while (expl >= maxexp){
				maxexp = lv*100;
				//cout << "maxexp = " << maxexp <<endl;
				expl = expl - maxexp ;
				//cout << "expl = " << expl <<endl;
				lv += 1;
				//cout << "Lv = " << lv <<endl;
				ruby += 5;
			}
			exp = expl;
		}
	up.lvU = lv ;
	up.expU = exp;
	up.ruby = ruby;
	return up;
}

/*
int main ()
{
	int ATK,HP; //atk and hp player
	unsigned long int lv=1,expl,exp=0,maxexp; //lv and exp
	int Money=200,Moneyl;
	while(true){
		
		maxexp = lv*100;
		ATK = lv*10;
		HP = lv*100;

		cout <<"======================"<<endl ;
		//cout <<"Player : " <<name <<endl ;
		cout <<"LV     : " <<lv <<endl ;
		cout <<"Exp    : " <<exp <<"/" <<maxexp <<endl ;
		cout <<"ATK    : " <<ATK <<endl ;
		cout <<"HP     : " <<HP <<endl ;
		cout <<"Money  : " <<Money <<endl ;
		cout <<"======================"<<endl <<endl ;
	
		cout <<"Give exp free : " ;
		cin >>expl;
		
		exp = exp + expl;
		
		Lv_Up up = lv_up (exp, expl, maxexp, lv);
		lv = up.lvU;
		exp = up.expU;
		
	}
	return (0);
}
*/
