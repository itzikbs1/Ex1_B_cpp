#include <iostream>
#include <stdlib.h>
#include "mat.hpp"
#include <vector>

using namespace std;
namespace ariel{

const int zero = 0;
const int one = 1;
const int two = 2;
const int num1 = 33;
const int num2 = 126;
const bool True = true;
const bool False = false;

    //this function convert vector<vector<char>> to string and return a string that appropriate to the Rug
    string convert_char_to_string(vector<vector<char>> *s, int col, int row, char c1, char c2){
        string str;
        for(int i=zero; i<row; i++){
            for(int j=zero; j<col; j++){
                str.append(one,(*s)[i][j]);
            }
            str.append("\n");
        }
    return str;
    }

    //check if the row or col is one
    bool check_size(int row, int col){
        if (row == one || col == one)
        {
            return True;
        }
        return False;
    }
    //I look at the carpet as a rectangle inside a rectangle, etc. and fill the vector like this.
    void build_mat(vector<vector<char>> *s, int row, int col, int k, char c){
            
            //fill the up row of the rectangle in the symbol
            for (int j = k; j < col-k; j++)
            {
                (*s)[k][j] = c;
            }
            //fill the down row of the rectangle in the symbol
            for (int j = k; j < col-k; j++)
            {
                (*s)[row-k-one][j] = c;
            } 
            //fill the left col of the rectangle in the symbol
            for (int j = k; j < row-k; j++)
            {
                (*s)[j][k] = c;
            }
            //fill the right col of the rectangle in the symbol
            for (int j = k; j < row-k; j++)
            {
                (*s)[j][col-k-one] = c;
            } 
}
    //use with build_mat function to fill the rectangle and return string of the carpet
    string mat(int col, int row, char c1, char c2){

        //if the col or the row is even number thaj throw exception 
        if (col%two==zero || row%two==zero)
        {
            throw("can't get even number");
        }
        //if the char is one of the symbols here than throw exception
        if (c1 == '\n' || c1 == '\t' || c1 == '\r' || c2 == '\n' || c2 == '\t' || c2 == '\r')
        {
            throw("can't get symb like this");
        }
        //check if the char is one of the numbers between num1 or num2
        if (c1 < num1 || c1 > num2 || c2 < num1 || c2 > num2)
        {
            throw("can't get symb like this");
        }
        
        vector<vector<char>> mat( row, vector<char>(col) );

        int k=zero;
        
        for (int i = zero; i < (col/two)+one; i++)
        {
            //check if the middle of the mat is fill with sym1 or sym2 if so then finish
            if(mat[row/two][col/two] == c1 || mat[row/two][col/two] == c2){
                break;
            }
            //check if i even then build rectangle with c1 symbol else build rectangle with the another symbol
            if(i%two==zero){
                build_mat(&mat, row, col, k, c1);
                //if this true than we don`t need to continue because we finish in one Iteration
                if(check_size(row,col)){
                    break;
                }
            }else{
                build_mat(&mat, row, col, k, c2);
                if(check_size(row,col)){
                    break;
                }
            }
            k++;
        }
        string s = convert_char_to_string(&mat, col, row, c1,c2);
        return s;
    }
}