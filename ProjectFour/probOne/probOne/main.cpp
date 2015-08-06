//
//  main.cpp
//  Problem One
//
// Tayseer Edouni 
//
/*
    Store 30 random letters A-Z i array char ALL[26]
 (i) Display array ALL followed by the frequency of each letter
 (ii) Display letter(s) with highest frequency
 */

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
struct letters
{
    char letter;
    int frequency;
    
};

int main(int argc, const char * argv[])
{
    //ASCII values for A-Z are 65-90
    //construct array ALL
    letters ALL[26];
    int tempasciivalue = 65;
    for (int i =0; i<26; i++)
    {
        ALL[i].frequency = 0;
        ALL[i].letter = tempasciivalue;
        tempasciivalue++;
    }
    
    srand(time(NULL));

    
    //Generate random letter and place into array ALL
    for (int i = 1; i<=30; ++i)
    {
        
        unsigned lb = 65, ub = 90;
        unsigned rnd = lb + (rand() % ((ub - lb) + 1));
        char tempLetter = (char)rnd;
        for (int j =0; j<26; j++)
        {
            if (tempLetter == ALL[j].letter)
            {
                ALL[j].frequency++;
                break;
            }
        }
    }
   
    
    //Display with Frequency greater than 0
    cout<<"Letter\tFrequency\n";
    int maxFreq = 0;
    for (int i =0; i<26; ++i)
    {
        if (ALL[i].frequency > 0)
        {
            cout<<setw(3)<<ALL[i].letter<<"\t\t\t"<<ALL[i].frequency<<endl;
            if (ALL[i].frequency > maxFreq)
            {
                maxFreq = ALL[i].frequency;
            }

        }
        
    }
    
    cout<<endl<<endl;
    cout<<"Letters: ";
    
    for (int i = 0; i<26; ++i)
    {
        if (ALL[i].frequency == maxFreq)
        {
            cout<<ALL[i].letter<<" ";
        }
    }
    
    cout<<"have highest frequencies "<<maxFreq<<endl;
    
    return 0;
}
