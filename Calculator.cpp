/*
   
Calculator
Write a calculator program which provides a command-line interface 
Write Clean code 
Consider all possible test cases  
*/



//Code


#include <cstdlib>
#include<iostream>
#include<cstring>

using namespace std;


int main(int argc, char* argv[])
{
    double num1 = 0;
    double res = 0;
    char opr = argv[2][0];
    int i = 1;
    if(argc >= 4 && argc%2 == 0){
        res = atoi(argv[i++]);

        while(i < argc){
            opr = argv[i++][0];
            num1 = atoi(argv[i++]);
           
            switch (opr)
            {
            case '+': res += num1 ;
                break;
            case '-': res -= num1 ;
                break;
            case '*': res *= num1 ;
                break;
            case '/': res /= num1 ;
                break;
            default:
                cout << "Not a valid operator !!" << endl;
                break;
            }
        }
        cout << res << endl;
    }else{
        cout << "Not a valid expression !!" << endl;
    }
    return 0;
}
