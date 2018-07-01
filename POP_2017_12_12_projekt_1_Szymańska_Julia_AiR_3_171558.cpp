
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;
const int xmax = 5;
const int ymax = 5;

const int x = 20;
const int y = 10;
char lab[x][y];
//deklaracja 6 ró¿nych sgmentów z których zbudowany bêdzie labirynt
char mazeA[xmax][ymax]=
{
{'#','#','.','#','#'},
{'#','.','.','#','#'},
{'.','.','#','.','.'},
{'#','.','.','.','#'},
{'#','#','.','#','#'},
};
char mazeB[xmax][ymax] =
{
{'#','#','.','.','#'},
{'.','#','#','.','#'},
{'.','.','.','.','.'},
{'#','.','.','.','#'},
{'#','#','.','.','#'},
};
char mazeC[xmax][ymax] =
{
{'.','.','.','.','.'},
{'.','.','#','.','.'},
{'.','.','#','#','.'},
{'#','.','#','#','#'},
{'#','.','.','.','.'},
};
char mazeD[xmax][ymax] =
{
{'#','#','.','.','.'},
{'#','.','.','#','.'},
{'.','.','#','.','.'},
{'.','#','.','.','#'},
{'#','.','.','#','#'},
};
char mazeE[xmax][ymax] =
{
{'.','.','.','#','#'},
{'#','.','.','.','#'},
{'.','.','#','.','.'},
{'.','.','#','.','.'},
{'.','.','.','.','#'},
};
char mazeF[xmax][ymax] =
{
{'#','#','.','#','#'},
{'#','#','.','#','#'},
{'.','.','.','.','.'},
{'#','#','.','#','#'},
{'#','#','.','#','#'},
};
//losowy wybór segmentów buduj¹cych labirynt
 void init(char taba[xmax][ymax],int a)
 {
 	srand((int)time(NULL));
 	a=(rand()%6)+1;
 	switch(a)
{
case 1:
	{
	for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeA[i][k];}
	}
	break;
case 2:
	{
	for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeB[i][k];}
	}
	break;
case 3:
	{
		for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeC[i][k];}
	}
	break;
case 4:
	{
		for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeD[i][k];}
	}
	break;
case 5:
	{
		for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeE[i][k];}
	}
	break;
case 6:
	{
		for(int i = 0; i < xmax; i++)
    {
    for(int k=0; k < ymax; k++)
        taba[i][k]= mazeF[i][k];}
	}
	break;
};
 }

 void printMaze()
 {
  		srand((int)time(NULL));
int z,b,c,d,e,f,g,h;
char tab[xmax][ymax];
char tabb[xmax][ymax];
char tabc[xmax][ymax];
char tabd[xmax][ymax];
char tabe[xmax][ymax];
char tabf[xmax][ymax];
char tabg[xmax][ymax];
char tabh[xmax][ymax];
init(tab,z);
init(tabc,c);
init(tabb,b);
init(tabd,d);
init(tabe,e);
init(tabf,f);
init(tabg,g);
init(tabh,h);
 //inicjalizacja tablicy 
 for(int i=0; i<x; i++)
 {
 if (i<5) 
 {
 	for(int k=0; k<y; k++)
 {
 	if(k<5) lab[i][k]=tab[i][k];
	else lab[i][k]=tabb[i][k-5];
  }
 }
 if(i>=5&&i<10)
 {
 	for(int k=0; k<y; k++)
 {
 	if(k<5) lab[i][k]=tabc[i-5][k];
    else  lab[i][k]=tabd[i-5][k-5];
  }
 }
 if(i>=10&&i<15)
 {
    for(int k=0; k<y; k++)
 	if(k<5) lab[i][k]=tabe[i-10][k];
	else lab[i][k]=tabf[i-10][k-5];
 }
  if(i>=15&&i<20)
 {
    for(int k=0; k<y; k++)
 	if(k<5) lab[i][k]=tabg[i-15][k];
	else lab[i][k]=tabh[i-15][k-5];
 }
}
}
//rysuj labirynt
void rysuj(int k, int l)
{
for(int i=0; i<k; i++)
 {
 for(int j=0; j<l; j++)
 {cout<<lab[i][j];
}
 cout<<endl;
}
}
void rysujl()
{
	for(int i=0; i<x; i++)
 {
 for(int k=0; k<y; k++)
 {cout<<lab[i][k];
 }
 cout<<endl;
}
}
//losoowa lokalizacja skarbów 
void losowanie_skarbow()
{
	int H, J;
	srand((int)time(NULL));
	int i=0;
	do
	{
	 H=(rand()%20);
	 J=(rand()%10);
	 if(lab[H][J]=='.')
	    {
		 lab[H][J]='$';
		 i++;
	    }
	}
	while(i<5);
	
};

//wypisanie instrukicji poruszania sie
void instrukcja()
{
	cout<<"---------------->GRA SKARBY W LABIRYNCIE<------------------\n Gra polega na odnalezieniu 5 skarbów ukrytych w labiryncie,\n przy wykonaniu jak najmniejszej ilosci ruchow\n Gora-->wcisnij'g'\n Dol-->wcisnij 'd'\n Prawo-->wcisnij'p'\n Lewo-->wcisnij'l'\n---------------------->POWODZENIA!!!<----------------------"<<endl;
}

//poruszanie sie gracza
void ruch()
{
	char r;
	int liczba_ruch=0;
	int liczba_skarb=0;
	int wsp_x=2, wsp_y=0, gr_x=0, gr_y=0;
	do{
		instrukcja();
		if(gr_x<wsp_x+2)gr_x=wsp_x+2;
		if(gr_y<wsp_y+2) gr_y=wsp_y+2;
		if(wsp_x==20) gr_x=20;
		if(wsp_y==10) gr_y=10;
	    if(lab[wsp_x][wsp_y]=='.')
		{
		lab[wsp_x][wsp_y]='@';
		liczba_ruch=liczba_ruch+1;	
		}
		if(lab[wsp_x][wsp_y]=='$')
		{
		lab[wsp_x][wsp_y]='@';
		liczba_ruch=liczba_ruch+1;
		liczba_skarb=liczba_skarb+1;
	    }
	    rysuj(gr_x,gr_y);
		cin>>r;
	    if(r=='d')
		{
	    	if(lab[wsp_x+1][wsp_y]=='#' || wsp_x+1>19)	cout<<"NIEDOZWOLONY RUCH---->MUR"<<endl;
	    	else
	    	{
	    		if(lab[wsp_x][wsp_y]=='@') lab[wsp_x][wsp_y]='.';
	    		wsp_x=wsp_x+1;
			}
			 }
	    if(r=='g')
	    {
	    	if(lab[wsp_x-1][wsp_y]=='#'|| wsp_x-1<0)	cout<<"NIEDOZWOLONY RUCH---->MUR"<<endl;
	    	else
	    	{
	    		if(lab[wsp_x][wsp_y]=='@') lab[wsp_x][wsp_y]='.';
	    		wsp_x=wsp_x-1;
			}
			 }
		if(r=='p')
			    {
	    	if(lab[wsp_x][wsp_y+1]=='#'|| wsp_x+1>9)	cout<<"NIEDOZWOLONY RUCH---->MUR"<<endl;
	    	else
	    	{
	    		if(lab[wsp_x][wsp_y]=='@') lab[wsp_x][wsp_y]='.';
	    		wsp_y=wsp_y+1;
			}
			 }
		if(r=='l')
			    {
	    	if(lab[wsp_x][wsp_y-1]=='#'|| wsp_y-1<0)	cout<<"NIEDOZWOLONY RUCH---->MUR"<<endl;
	    	else
	    	{
	    		if(lab[wsp_x][wsp_y]=='@') lab[wsp_x][wsp_y]='.';
	    		wsp_y=wsp_y-1;
			}
			 }
		if(r=='c'){gr_y=y;gr_x=x;
		}
	 
	  
	    
		system("cls");
	}
	while(liczba_skarb<5);
	cout<<"----->HUUUURA!!!<-----\n ZEBRALES WSZYSTKIE SKARBY\n---->WYKONANE RUCHY="<<liczba_ruch<<"<----";
}



int main()
{
	
	
	printMaze();
	losowanie_skarbow();

	ruch();
	return 0;
}


