/*#include <iostream>
#include <conio.h>
*/
using namespace std;

typedef struct {
    char go;
    int xg=2;
	int yg=2;
	int sizeY=10,sizeX=20;
	int exitmap=0;
} go_to;
/*
void map (int, int, int, int);
go_to go (go_to);

int main ()
{
	go_to g;
	while (true){
		g = go (g);
		
		if (g.exit == 1){
			g.exitmap == 0;
			return(0);
		}
	}
	
}
*/
void map (int sizeY, int sizeX, int yg, int xg){
	for(int y=sizeY;y>=1;y--){
			cout<<"#";
			for(int x=2;x<=sizeX;x++){
				if ((y>1&&y<sizeY)&&(x>1&&x<sizeX)){
					if(yg==y&&xg==x){
						cout <<"o";
					}
					else if((y<=7&&y>=4)&&x==7){
						cout <<"#";
					}
					else if((x<=10&&x>=8)&&y==5){
						cout <<"#";
					}
					else if(x==10&&y==7){
						cout <<"X";
					}
					else {
						cout <<" ";
					}
				}
				else {
					cout<<"#";
				}
			}
			cout <<endl;
		}
}

go_to go (go_to g){
	while(true){
		
//wall1
		if(g.xg==g.sizeX){
			g.xg-=1;
		}
		if(g.xg==1){
			g.xg+=1;
		}
		if(g.yg==g.sizeY){
			g.yg-=1;
		}
		if(g.yg==1){
			g.yg+=1;
		}
		
//wall2		
//////////////////////////////////////////////////////////////
		if((g.yg<=7&&g.yg>=4)&&g.xg==7){
			if(g.go == 'd' || g.go == 'D'){
				g.xg-=1;
			}
			if(g.go == 'a' || g.go == 'A'){
				g.xg+=1;
			}
			if(g.go == 'w' || g.go == 'W'){
				g.yg-=1;
			}
			if(g.go == 's' || g.go == 'S'){
				g.yg+=1;
			}
		}
		if((g.xg<=10&&g.xg>=8)&&g.yg==5){
			if(g.go == 'w' || g.go == 'W'){
				g.yg-=1;
			}
			if(g.go == 's' || g.go == 'S'){
				g.yg+=1;
			}
			if(g.go == 'a' || g.go == 'A'){
				g.xg+=1;
			}
		}
		
		if(g.yg==7&&g.xg==10){
			g.exitmap = 2;
		}
//////////////////////////////////////////////////////////////
		
		map (g.sizeY, g.sizeX, g.yg, g.xg);
		
		cout <<"Press W to go up.\n"
			   "Press S to down.\n"
			   "Press D to go right.\n"
			   "Press A to go left.\n"
			   "Exit[ ]" <<endl;
		g.go = getch();
		if(g.go == 'w' || g.go == 'W'){
			g.yg+=1;
		}
		else if(g.go == 's' || g.go == 'S'){
			g.yg-=1;
		}
		else if(g.go == 'd' || g.go == 'D'){
			g.xg+=1;
		}
		else if(g.go == 'a' || g.go == 'A'){
			g.xg-=1;
		}
		else{
			g.exitmap = 1;
		}
		system("cls");
		return g;
	}
}
