#include <graphics.h>
#include <iostream>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;
char pit[20];


void prinBorder(){
	cleardevice();
	setbkcolor(0);
	setcolor(11);
	settextstyle(3,0,1);
    rectangle(10,10,700,500);
    line(10,40,700,40);
    outtextxy(20,13,"score : 0");
    outtextxy(450,13,"press esc key to quit game !");
}

void setPlayer(){
	prinBorder();	
}

void gamePlay(){
	int x,y,xnew,ynew,speedX=rand()%(8-3+1)+3, speedY=rand()%(8-3+1)+3;

	int y1=150, y2=270, y1old, y2old;
	
	int go=1;
	int op=1;
	int pp=0;
	int score = 0;
	int sleep = rand()%(50-10+1)+10;
	
	xnew=680; 
	ynew=250;
	
	time_t now, endd;
	now=time(0);
	
	setPlayer();
	setfillstyle(1,11);
	bar(15,y1,25,y2);
	void Menu();
	
	while(1){
		if(go==1){
			while(!kbhit()&&op){
				time_t t;
				x = xnew;//x, y la toa do qua bong chu ky truoc
				y = ynew;
				xnew=x+speedX;//xnew, ynew la toa do qua bong chu ky hien tai
				ynew=y+speedY;
				setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,10,10);//xoa qua bong cu
				setfillstyle(1,11);
				fillellipse(xnew,ynew,10,10);//in qua bong moi
				setcolor(11);
				
				if(ynew>485 ||ynew<60){
					speedY=-speedY;
				}
				if(xnew>685 ){
					speedX=-speedX;	
				}
				if(xnew<41){
					endd = time(0);
					if(ynew>y1&&ynew<y2){
						score++;
						sprintf(pit,"score : %d",score);
						outtextxy(20,13,pit);
						speedX=-speedX;
					}else{
						if(endd - now > 30){
							outtextxy(300,200,"Game Over");
							sprintf(pit,"Your score : %d",score);
							outtextxy(290,250,pit);
							outtextxy(250,300,"Press r or enter to play again !");
							op=0;
							break;
						}else{
							speedX=-speedX;
						}
					}	
				}
	
				delay(sleep);
	
			}		
		}
		
		char ch = getch();
		
		if(ch==' '&&op==1){
			pp=1;
			go=0;
			outtextxy(200, 250, "game pause ! press enter to continue !");
		}
		if(ch==13&&op==1){
			pp=0;
			go=1;
			setcolor(0);
			outtextxy(200, 250, "game pause ! press enter to continue !");
		}
		if((ch=='r'||ch=='R'||ch==13) && op==0){
			op=1;
			gamePlay();
			break;
		}
		if((ch=='s'||ch=='S'||ch==80) && op ){
			if(y1<380){
				y1old=y1;
				y2old=y2;
				y1+=5;
				y2+=5;
				setfillstyle(1,0);
				bar(15,y1old,25,y2old);
				setfillstyle(1,11);
				bar(15,y1,25,y2);	
			}else{
				delay(10);
				setfillstyle(1,11);
				bar(15,y1,25,y2);
			}	
		}
		if((ch=='w'||ch=='W'||ch==72) && op ){
			if(y2>165){
				y1old=y1;
				y2old=y2;
				y1-=5;
				y2-=5;
				setfillstyle(1,0);
				bar(15,y1old,25,y2old);
				setfillstyle(1,11);
				bar(15,y1,25,y2);
			}
			else{
				delay(10);
				setfillstyle(1,11);
				bar(15,y1,25,y2);
			}
		}
		if(ch==27){
			Menu();
			break;
		}	
	}
}

void Menu(){
	cleardevice();
	void htPlay();
	
	setlinestyle(0,10,1);//(kieu duong, mau, do dam )
	setcolor(11);
	settextstyle(3,0,1);
	outtextxy(250,150,"------------PING PONG !-------------");
	outtextxy(250,180,"----------------MENU------------------");
	outtextxy(250,210,"1. play the game ");
	outtextxy(250,240,"2. how to play ");
	outtextxy(250,270,"3. exit ");
	outtextxy(250,310,"enter option from menu ");
	
	char op = getch();
	
	if(op=='1') gamePlay();
	if(op=='2') htPlay();
	if(op=='3') exit(0);
}

void htPlay(){
	cleardevice();
	outtextxy(250, 100,"INSTRUCTION");
    outtextxy(180, 150,"------------------------------------------------");
    outtextxy(200, 180,"- press w or up arrow to move up");
    outtextxy(200, 210,"- press s or down arrow to move down");
    outtextxy(200, 240,"- press Spacebar to pause game");
    outtextxy(200, 270,"- press esc to quit game");
    outtextxy(200, 300,"- press any key to go to menu ....");
    getch();
    Menu();
}



main(){
	initwindow(1000, 600);
	Menu();
	
	
	getch();
}
