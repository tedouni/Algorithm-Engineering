//
//  main.cpp
//  assignmentOne
//  Tayseer Edouni & Lisa Nguyen
//
//Write a c++ Program to display the binary representation of an unsigned number (use 16 bit binary
//representation operators). Do not use arrays
//Sample,
//Enter a positive integer. 125
// 125 at base 2 is 0000 0000 0111 1101
//1111101 binary conversion of 25 (not in 16 bit binary representation
#include <iostream>
#include <string>
using namespace std;

string convertDecimalToBinary(int number)
{
    string result = "";
    
    do
    {
        
        if ( (number & 1) == 0 )
            result += "0";
        else
            result += "1";
        
        //shift to right by 1
        number >>= 1;
    } while ( number );
    
    //Reverse string to ensure correct binary
    reverse(result.begin(), result.end());
    return result;
}


int main(int argc, const char * argv[])
{
    int baseTwoNumber;
    
    cout<<"Enter a positive integer: ";
    cin>>baseTwoNumber;
    
    //Check to see if entered number is positive, if not then convert to positive
    if (baseTwoNumber < 0 )
    {
        cout<<"Enterted a negative number, converting to positive number.\n";
        baseTwoNumber*= -1;
    }

    
    cout<<baseTwoNumber<<" at base 2 is ";
    
    //Convert number to binary (base 2)
    string output = convertDecimalToBinary(baseTwoNumber);
    
    //Must be in 16 bit binary representation
    if (output.length() < 16)
    {
        int count2 = 0;
        int difference = 16 - (int) output.length();
        for (int i =0 ; i<difference; ++i)
        {
            if (count2 %4 == 0)
            {
                cout<<" ";
            }
            count2++;

            cout<<"0";
        }
    }
    
    
    //conintue 16 bit binary representation
    int count = 0;
    for (int i = 0; i<output.length(); ++i)
    {
        count++;
        if (count % 4 == 0)
        {
            cout<<" ";
            
        }
        cout<<output[i];
    }
    cout<<endl;
    
    return 0;
}
