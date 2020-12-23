#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>


using namespace std;
char l[] = "0000000";
int i;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
CursorPosition.X = x;
CursorPosition.Y = y;
SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
    if ( size ==0)
        {
            size == 20;
        }
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void printBorder(){
    for (i = 2; i <= 79; i++)
    {
        gotoxy(i, 1);
        cout << '-';
        gotoxy(i ,25);
        cout << '-';
    }
    for(i = 1; i <= 25; i++)
    {
        gotoxy(2, i);
        cout << "|";
        gotoxy(79, i);
        cout << "|";
    }
}

void setplayers()
{
    system("cls");
    printBorder();
    gotoxy(4,3);
    cout << "score : 0";
    gotoxy(50,3);
    cout << "press esc key to quit game !";
    for(i =3; i<= 78; i++)
    {
        gotoxy(i, 4);
        cout << '-';
    }
    for(i =0; i<= strlen(l); i++)
    {
        gotoxy(5, 7+i);
        cout <<l[i];
    }
    for(i=0;i<=strlen(l);i++)
    {
        gotoxy(76, 7+i);
        cout << l[i];
    }
}

void gameplay()
{
 	int sc = 0, pp = 0, st=1;
	int c=7,k=5,x=73,y=6 + rand()%15;//x, y la toa do qua bong
	int d = rand() %2,px,py;//px, py
	int op=1,go=1;
	int rld=0,rlu=0,lru=0,lrd=0;
	     
 	time_t now = time(0);
 	time_t endd;
 	 	
    setplayers();
    void displayMenu();
	     
		
    while(1){
	    if(go==1){//neu go=1 thi in ra -> tiep tuc chu ky
	        while(!kbhit()&&op){//kiem tra nguoi dung co nhap phim nao khong
			// op = 1 thi game bat dau
	            px = x;
	            py = y;
	            gotoxy(x,y);
	            cout << "0";
	            Sleep(50);
	            gotoxy(x, y);
	            cout << " ";
	
	            if(st == 1){
	                st =0;
	                if(d==0){
	                    x--;
	                    y++;
	                }else{
	                    x--;
	                    y--;
	                }
	            }
	            if(rld){
	                x--;
	                y++;
	            }
	            if(rlu){
	                x--;
	                y--;
	            }
	            if(lru){
	                x++;
	                y--;
	            }
	            if(lrd){
	                x++;
	                y++;
	            }
	
	            if(x<px&&y>py) rld =1;
	            if(x<px&&y<py) rlu =1;
	            
	            if(y==5&&rlu){
	                rld =1;
	                rlu =0;
	            }
	            if(y==24&&rld){
	                rlu=1;
	                rld=0;
	            }//qua bong cham bien duoi
	            if(x==6&&rlu){
	                lru = 1;
	                rlu = 0;
	            }//qua bong cham bien trai ( khong trung thanh do )
	            if(x==6&&rld){
	                lrd = 1;
	                rld = 0;
	            }
	            if(y==5&&lru){
	                lrd = 1;
	                lru = 0;
	            }
	            if(y==24&&lrd){
	                lru = 1;
	                lrd = 0;
	            }
	            if(x==75&&lrd){
	                rld = 1;
	                lrd = 0;
	            }
	            if(x==75&&lru){
	                rlu = 1;
	                lru = 0;
	            }
	
	            if(x==75 || x==6){
	                Sleep(50);
	            }//khi cham bien doc dung lai 50ms
	            if(y==5 || y==24){
	                Sleep(50);
	            }//khi cham bien ngang dung lai 50ms
				
	            if(lru || lrd || rlu || rld){
	                if(y >= 6 && y<= 22){
	                    if(y>k+strlen(l)-3){
	                        gotoxy(76, k+strlen(l));
	                        cout << "0";
	                        gotoxy(76, k);
	                        if(k !=4) cout << ' ';
	                        k++;
	                    }
	                    if(y<k+strlen(l)-3){
	                        gotoxy(76, k);
	                        cout << "0";
	                        if(k+strlen(l)!=25)
	                            cout << ' ';
	                        k--;
	                    }
	                }
	            }//ham tang giam thanh ben phai ( them phan sinh dong ) khong anh huong den ket cuc tro choi
	            
	            if(x==6&&(y<c||y>c+strlen(l)-1)){
	            	endd = time(0);
	            	if(endd - now > 30){
	                	gotoxy(x,y);
	                	cout << "you  lose ! press 'r' or enter to play again !";
	                	op=0;
	                	break;
	                }
	                op=1;//game van tiep tuc
	            }//khi bong cham bien trai, check timeout
	
	            if(x==6&&op==1){
	            	if(y>c&&y<=c+strlen(l)) sc++;
	                gotoxy(4,3);
	                cout << "Score :" << sc;
	            }
	        }
	    }
	
	    char ch = getch();
	
	    if (ch == ' '&&op ==1){
	        pp=1;//game tam dung
	        go=0;//game tam dung
	        gotoxy(22,12);
	        cout << "game pause ! press enter to continue !";
	    }//an space de tam dung game
	    if(ch==13&&pp&&op==1){
	        pp=0;//game tiep tuc
	        go=1;//game tiep tuc
	        gotoxy(22,12);
	        cout << "                                      ";
	    }//chon phim bat ky de tiep tuc
	    if((ch=='r'||ch=='R'||ch==13)&&op==0){
	        op=1;//game van tiep tuc
	        gameplay();
	        break;
	    }
	    if((ch=='s'||ch=='S'||ch==80)&&c<=19&&op){
	        gotoxy(5, c+strlen(l));
	        cout << "0";//them 1 phan tu duoi cung
	        gotoxy(5,c);
	        cout << ' ';//xoa bo phan tu tren cung
	        c++;
	    }//dieu khien L[] di xuong
	    if((ch=='w'||ch=='W'||ch==72)&&c>=6&&op){
	        gotoxy(5, c-1);
	        cout << "0";
	        gotoxy(5,c+6);
	        cout << ' ';
	        c--;
	    }//dieu khien L[] di len
	    if(ch==27){
	        displayMenu();
	        break;
		}//an esc de thoat
	}	
}
 
 void displayMenu()
{
    system("cls");
    void htpwindow();

    gotoxy(34,4);
    cout << "ping pong !";
    for (i=8;i<=73;i++){
        gotoxy(i,6);
        cout << '-';
    }
    gotoxy(34,10);
    cout << "1.play the game ";
    gotoxy(34,12);
    cout << "2. how to play ";
    gotoxy(34,14);
    cout << "3. exit ";
    gotoxy(34,16);
    cout << "enter option from menu";

    char op = getch();
    if(op=='1')gameplay();
    if(op=='2')htpwindow();
    if(op=='3')exit(0);
}

void htpwindow()
{
    system("cls");
    printBorder();
    gotoxy(4,3);
    cout << "instruction";
    gotoxy(4,4);
    cout << "----------------";
    gotoxy(4,5);
    cout << "-press w or up arrow to move up";
    gotoxy(4,7);
    cout << "-press s or down arrow to move down";
    gotoxy(4,9);
    cout << "-press Spacebar to pause game";
    gotoxy(4,11);
    cout << "-press esc to quit game";
    gotoxy(4,15);
    cout << "press any key to go to menu ....";
    getch();
    displayMenu();
}


int main()
{
    setcursor(0,0);
    srand((unsigned) time(NULL));
    system("cls");

    displayMenu();
    return 0;
}

