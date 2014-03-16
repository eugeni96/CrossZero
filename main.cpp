#include <iostream>
#include <iomanip>

using namespace std;

int enterCol(int n)
{
    char a;
    int b;
    cin>>a;
    a-=17;
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
    if (field[*row][*col]=='.')
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
            field[i][j]='.';
    }
}

void print(char **field, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<field[i][j]<<" ";
        cout<<endl;
    }
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
        if(field[n-1-i][n-1-i]!=field[row][col])
            tester4=0;
    }
    return (tester1||tester2||tester3||tester4);
}

void control(char (**field), int n)
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
            if(victoryCheck(field,n,row,col))
            {
                cout<<"Second player win!"<<endl;
                finish=1;
            }
        }
        print(field,n);

        hodi++;
        if(hodi==n*n && finish==0)
        {
            finish=1;
            cout<<"pobedila dryjba:)"<<endl;
        }
    }
}

int main()
{
    int n=3;
//    cout<<"Enter size of the field:"<<endl;
//    cin>>n;
    char **field = new char *[n];
    for (int i=0; i<n; i++)
        field[i] = new char[n];
    control(field,n);
    for (int i=0; i<n; i++)
        delete [] field[i];
    delete [] field;
    return 0;
}
