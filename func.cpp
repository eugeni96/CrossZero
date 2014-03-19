#include <iostream>
#include <iomanip>
#include "func.h"

using namespace std;


int enterCol(int n)
{
    char a;
    int b;
    cin>>a;
    if(64<a && a<91)
    {
        a-=17;
    }
    else
    {
        if(96<a && a<123)
        {
            a-=49;
        }
        else
        {
            a=99;
        }
    }
    b=a-'0';
    return b;
}

int enterRow(int n)
{
    char a;
    int b;
    cin>>a;
    b=a-'0'-1;
    return b;
}

bool freeCell(char **field, int *row, int *col)
{
    if (field[*row][*col]==' ')
    {
        return 1;
    }
    else
        return 0;

}

void enterCoord(char **field, int n, int *row, int *col, char metka)
{
    cout<<"enter coordinates"<<endl;
    *col=enterCol(n);
    *row=enterRow(n);
    if (*col<0 || *row<0 || *col>n || *row>n || !freeCell(field, row, col))
        enterCoord(field,n,row,col,metka);
    field[*row][*col]=metka;
}


void init(char **field, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            field[i][j]=' ';
    }
}

void print(char **field, int n)
{
    char symbol;
    for(int k=0; k<n+1; k++)
        cout<<"+-";
    cout<<"+"<<endl<<"|"<<" "<<"|";
    for (int i=0; i<n; i++)
    {
        symbol=65+i;
        cout<<symbol<<"|";
    }
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        for(int k=0; k<n+1; k++)
            cout<<"+-";
        cout<<"+"<<endl<<"|"<<i+1<<"|";
        for (int j=0; j<n; j++)
            cout<<field[i][j]<<"|";
        cout<<endl;
    }
    for(int k=0; k<n+1; k++)
        cout<<"+-";
    cout<<"+"<<endl;
}

bool victoryCheck(char **field, int n, int row, int col)
{
    bool tester1=1, tester2=1, tester3=1, tester4=1;
    for (int i=0; i<n; i++)
    {
        if(field[i][col]!=field[row][col])
            tester1=0;
    }
    for (int i=0; i<n; i++)
    {
        if(field[row][i]!=field[row][col])
            tester2=0;
    }
    for (int i=0; i<n; i++)
    {
        if(field[i][i]!=field[row][col])
            tester3=0;
    }
    for (int i=0; i<n; i++)
    {
        if(field[n-1-i][i]!=field[row][col])
            tester4=0;
    }
    return (tester1||tester2||tester3||tester4);
}


void control(char **field, int n)
{

    init(field,n);
    bool finish=0;
    int col=0, row=0, hodi=0;
    char metka;
    while (!finish)
    {
        if (hodi%2==0)
        {
            cout<<"First player"<<endl;
            metka='X';
            enterCoord(field,n,&row,&col,metka);
            print(field,n);
            if(victoryCheck(field,n,row,col))
            {
                cout<<"First player win!"<<endl;
                finish=1;
            }
        }
        else
        {
            cout<<"Second player"<<endl;
            metka='O';
            enterCoord(field,n,&row,&col,metka);
            print(field,n);
            if(victoryCheck(field,n,row,col))
            {
                cout<<"Second player win!"<<endl;
                finish=1;
            }
        }
        hodi++;
        if(hodi==n*n && finish==0)
        {
            finish=1;
            cout<<"pobedila dryjba:)"<<endl;
        }
    }
}

