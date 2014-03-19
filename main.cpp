#include <iostream>
#include <iomanip>
#include "func.h"


using namespace std;



int main()
{
    int n=0;
    cout<<"Enter size of the field:"<<endl;
    cin>>n;
    char **field = new char *[n];
    for (int i=0; i<n; i++){
        field[i] = new char[n];
    }
    control(field,n);
    for (int i=0; i<n; i++){
        delete [] field[i];}
    delete [] field;
    return 0;
}
