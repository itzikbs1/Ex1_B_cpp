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
    cout<<"Please enter a col number: ";
    cin>>col;
    if (col%two == 0)
    {
        throw("Can't take even numbers");
    }
    
    // cout<<endl;
    cout<<"Please enter a row number: ";
    cin>>row;
    if (col%two == 0)
    {
        throw("Can't take even numbers");
    }
    // cout<<endl;
    string s = ariel::mat(col,row,'@', '-');
    cout<<"The Rug is: "<<s<<endl;
    return 0;
}
