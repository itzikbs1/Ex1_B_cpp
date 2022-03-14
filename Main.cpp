#include <iostream>
#include <stdlib.h>
#include "mat.hpp"
#include "mat.cpp"

using namespace std;
using namespace ariel;
int main(){

const int two = 2;

    int row;
    int col;
    char c1;
    char c2;
    cout<<"Please enter a col number: ";
    cin>>col;
    while(col%two == 0 || col < 1)
    {
        cout<<"Please enter a another col number: ";
        cin>>col;
    }
    
    cout<<"Please enter a row number: ";
    cin>>row;
    while(row%two == 0 || row < 1)
    {
        cout<<"Please enter a another Row number: ";
        cin>>row;
    }
    cout<<"Please enter a symbol1 number: ";
    cin>>c1;
    cout<<"Please enter a symbol2 number: ";
    cin>>c2;
    string s = ariel::mat(col,row,c1, c2);
    cout<<"The Rug is: \n"<<s<<endl;
    return 0;
}
