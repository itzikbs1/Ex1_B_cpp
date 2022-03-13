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

    bool check_size(int row, int col){
        if (row == one || col == one)
        {
            return True;
        }
        return False;
    }

    void build_mat(vector<vector<char>> *s, int row, int col, int k, char c){
            for (int j = k; j < col-k; j++)
            {
                (*s)[k][j] = c;
            }
            
            for (int j = k; j < col-k; j++)
            {
                (*s)[row-k-one][j] = c;
            } 
       
            for (int j = k; j < row-k; j++)
            {
                (*s)[j][k] = c;
            }
       
            for (int j = k; j < row-k; j++)
            {
                (*s)[j][col-k-one] = c;
            } 
}

    string mat(int col, int row, char c1, char c2){

        if (col%two==zero || row%two==zero)
        {
            throw("can't get even number");
        }

        if (c1 == '\n' || c1 == '\t' || c1 == '\r' || c2 == '\n' || c2 == '\t' || c2 == '\r')
        {
            throw("can't get symb like this");
        }

        if (c1 < num1 || c1 > num2 || c2 < num1 || c2 > num2)
        {
            throw("can't get symb like this");
        }
        
        vector<vector<char>> mat( row, vector<char>(col) );

        int k=zero;
        for (int i = zero; i < (col/two)+one; i++)
        {
            if(mat[row/two][col/two] == c1 || mat[row/two][col/two] == c2){
                break;
            }
            if(i%two==zero){
                build_mat(&mat, row, col, k, c1);
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

// int main(){
//     string s = ariel::mat(3,3,'@', '-');
//     cout << s;
//     return 0;
// }