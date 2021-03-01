#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

using namespace std;

char d0[5][3] = {	178,178,178,
					178,' ',178,
					178,' ',178,
					178,' ',178,
					178,178,178	};
					
char d1[5][3] = {	' ',' ',178,
					' ',' ',178,
					' ',' ',178,
					' ',' ',178,
					' ',' ',178	};

char d2[5][3] = {	178,178,178,
					' ',' ',178,
					178,178,178,
					178,' ',' ',
					178,178,178	};

char d3[5][3] = {	178,178,178,
					' ',' ',178,
					178,178,178,
					' ',' ',178,
					178,178,178	};

char d4[5][3] = {	178,' ',178,
					178,' ',178,
					178,178,178,
					' ',' ',178,
					' ',' ',178	};

char d5[5][3] = {	178,178,178,
					178,' ',' ',
					178,178,178,
					' ',' ',178,
					178,178,178	};

char d6[5][3] = {	178,178,178,
					178,' ',' ',
					178,178,178,
					178,' ',178,
					178,178,178	};

char d7[5][3] = {	178,178,178,
					' ',' ',178,
					' ',' ',178,
					' ',' ',178,
					' ',' ',178	};

char d8[5][3] = {	178,178,178,
					178,' ',178,
					178,178,178,
					178,' ',178,
					178,178,178	};

char d9[5][3] = {	178,178,178,
					178,' ',178,
					178,178,178,
					' ',' ',178,
					' ',' ',178	};


char sep[5][3] = {	' ',' ',' ',
					' ',178,' ',
					' ',' ',' ',
					' ',178,'  ',
					' ',' ',' '	};
 

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void printDigit(int no, int x, int y ){
	 
	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			switch(no){
				case 0:
					gotoxy(x+j, y+i); cout<<d0[i][j]; break;
				case 1:
					gotoxy(x+j, y+i); cout<<d1[i][j]; break;
				case 2:
					gotoxy(x+j, y+i); cout<<d2[i][j]; break;
				case 3:
					gotoxy(x+j, y+i); cout<<d3[i][j]; break;
				case 4:
					gotoxy(x+j, y+i); cout<<d4[i][j]; break;
				case 5:
					gotoxy(x+j, y+i); cout<<d5[i][j]; break;
				case 6:
					gotoxy(x+j, y+i); cout<<d6[i][j]; break;
				case 7:
					gotoxy(x+j, y+i); cout<<d7[i][j]; break;
				case 8:
					gotoxy(x+j, y+i); cout<<d8[i][j]; break;
				case 9:
					gotoxy(x+j, y+i); cout<<d9[i][j]; break;
				case 10:
					gotoxy(x+j, y+i); cout<<sep[i][j]; break;
			} 
		}
	}
	
}

void drawBorder(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 50;
    int height = 11;
    
    gotoxy((width/2)+x-20, y); cout<<"S T O P   W A T C H   P R O G R E S S";
    
    for( int i=1; i<=height; i++ ){
		for( int j=1; j<=width; j++ ){
	    	gotoxy(j+x,i+y);
	    	if( i==1 && j==1 ) cout<< tl;
			else if( i==height && j==1 ) cout<< bl;
	    	else if( i==1 && j==width ) cout<< tr;
			else if( i==height && j==width ) cout<< br;
			else if( i==1 || i==height ) cout<< h;
			else if( j==1 || j==width ) cout<< v;
		}
	}
}

int main() {
	system("cls");
	setcursor(0,0);  
 	  
 	int hour = 0;  
 	int min  = 0;
 	int sec  = 0;
	int timerStart = 1;
	 
	int uHour, uMin, uSec;
	
	int gap  = 5;
	int posX;
	int posY  = 8;
	char op;
	do{
		system("cls");
		
		cout<<endl<<endl;
		cout<<"======================================="<<endl;
		cout<<"         S T O P   W A T C H           "<<endl;
		cout<<"======================================="<<endl<<endl;
		
		cout<<"Set Time for Stop Watch "<<endl<<endl;
		
		cout<<"Enter Hour: ";
		cin>> uHour;
		cout<<"Enter Minute: ";
		cin>> uMin;
		cout<<"Enter Seconds: ";
		cin>> uSec;
		 
		while(1){
			system("cls");
			drawBorder(9,4);
			
			posX  = 15;
			
			if( hour < 10 ){
				printDigit(0, posX, posY);
				printDigit(hour, posX+=gap, posY);
			}
			else{
				printDigit(hour/10, posX, posY);
				printDigit(hour%10, posX+=gap, posY);
			}
			
			printDigit(10, posX+=gap, posY);
			
			if( min < 10 ){
				printDigit(0, posX+=gap, posY);
				printDigit(min, posX+=gap, posY);
			}
			else{
				printDigit(min/10, posX+=gap, posY);
				printDigit(min%10, posX+=gap, posY);
			}
			printDigit(10, posX+=gap, posY);
			if( sec < 10 ){
				printDigit(0, posX+=gap, posY);
				printDigit(sec, posX+=gap, posY);
			}
			else{
				printDigit(sec/10, posX+=gap, posY);
				printDigit(sec%10, posX+=gap, posY);
			}
			
			if(kbhit()){
				char ch = getch();
				if(ch==32){
					gotoxy(10,19); cout<<"Press Any Key to Resume";
					getch(); 
					gotoxy(10,19); cout<<"                       ";
				}
				if(ch==27){
					break;
				}
			} 
			
			gotoxy(10,20); cout<<"Press Space Bar to Pause";
			//50 millisecond processing time is deducted, you can change it...
			Sleep(950); 
						
			if( hour == uHour && min == uMin && sec == uSec ){
				gotoxy(10,18); cout<<"Stop Watch Stopped";
				gotoxy(10,20); cout<<"                          ";
//				getch();
				break;
			}
			
			sec++;
			if( sec>=60 ){
				sec = 0;
				min++;
			}
			if( min>=60 ){
				min = 0;
				hour++;
			}
			if( hour>=24 ){
				sec = 0;
				min = 0;
				hour = 0;
			}
		}
		
		gotoxy(10,22); cout<<"Do you want to use stop watch again (y/n): ";
		op = getch();
	}while(op=='y' || op=='Y');
	
	
    return 0;
}
