/*#include <iostream>
#include <conio.h>
*/
using namespace std;

typedef struct {
    char go;
    int xg=2;
	int yg=2;
	int sizeY=5,sizeX=10;
	int exitmap2=0;
} go_to2;
/*
void map (int, int, int, int);
go_to go (go_to);

int main ()
{
	go_to g2;
	while (true){
		g2 = go2 (g2);
		
		if (g.exitmap2 == 1){
			g.exitmap2 == 0;
			return(0);
		}
	}
	
}
*/
void map2 (int sizeY, int sizeX, int yg, int xg){
	for(int y=sizeY;y>=1;y--){
			cout<<"#";
			for(int x=2;x<=sizeX;x++){
				if ((y>1&&y<sizeY)&&(x>1&&x<sizeX)){
					if(yg==y&&xg==x){
						cout <<"o";
					}
					else if((y<=3&&y>=2)&&x==3){
						cout <<"#";
					}
					else if((x<=5&&x>=4)&&y==2){
						cout <<"#";
					}
					else {
						cout <<" ";
					}
				}
				else if(x==2&&y==1){
					cout <<"-";
				}
				else {
					cout<<"#";
				}
			}
			cout <<endl;
		}
}

go_to2 go2 (go_to2 g2){
	while(true){
		
//wall1
		if(g2.xg==g2.sizeX){
			g2.xg-=1;
		}
		if(g2.xg==1){
			g2.xg+=1;
		}
		if(g2.yg==g2.sizeY){
			g2.yg-=1;
		}
		if(g2.yg==1){
			g2.yg+=1;
		}
		
//wall2		
//////////////////////////////////////////////////////////////
		if((g2.yg<=3&&g2.yg>=2)&&g2.xg==3){
			if(g2.go == 'd' || g2.go == 'D'){
				g2.xg-=1;
			}
			if(g2.go == 'a' || g2.go == 'A'){
				g2.xg+=1;
			}
			if(g2.go == 'w' || g2.go == 'W'){
				g2.yg-=1;
			}
			if(g2.go == 's' || g2.go == 'S'){
				g2.yg+=1;
			}
		}
		if((g2.xg<=5&&g2.xg>=4)&&g2.yg==2){
			if(g2.go == 'w' || g2.go == 'W'){
				g2.yg-=1;
			}
			if(g2.go == 's' || g2.go == 'S'){
				g2.yg+=1;
			}
			if(g2.go == 'a' || g2.go == 'A'){
				g2.xg+=1;
			}
		}
//////////////////////////////////////////////////////////////
		
		map2 (g2.sizeY, g2.sizeX, g2.yg, g2.xg);
		
		cout <<"Press W to go up.\n"
			   "Press S to down.\n"
			   "Press D to go right.\n"
			   "Press A to go left.\n"
			   "Exit[ ]" <<endl;
		g2.go = getch();
		if(g2.go == 'w' || g2.go == 'W'){
			g2.yg+=1;
		}
		else if(g2.go == 's' || g2.go == 'S'){
			g2.yg-=1;
		}
		else if(g2.go == 'd' || g2.go == 'D'){
			g2.xg+=1;
		}
		else if(g2.go == 'a' || g2.go == 'A'){
			g2.xg-=1;
		}
		else{
			g2.exitmap2 = 1;
		}
		system("cls");
		return g2;
	}
}
