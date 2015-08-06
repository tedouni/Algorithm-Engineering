//
//  main.cpp
//  assignmentTwo_ProblemFour
//
// Tayseer Edouni & Lisa Nguyen
//
/* sort the following
    int[6] = {30, 50, 10, 90, 60, 80};
    char name[5][7] = {"Jack", "Bill", "Bob", "Adam", "Doug"};
    float gpa[6] = {3.2, 3.9, 2.7, 2.5, 3.6, 2.9};
    string seasons[4] = {"Winter", "Spring", "Summer", "Fall"};
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <stdlib.h>     /* qsort */
using namespace std;

int compare(void const *a, void const *b)
{
    return strcmp((char*)a,(char*)b);
}

int main(int argc, const char * argv[])
{
    //Declarations
    int numbers[6] = {30, 50, 10, 90, 60, 80};
    char name[5][7] = {"Jack", "Bill", "Bob", "Adam", "Doug"};
    float gpa[6] = {3.2, 3.9, 2.7, 2.5, 3.6, 2.9};
    string seasons[4] = {"Winter", "Spring", "Summer", "Fall"};
    
    cout<<"{30, 50, 10, 90, 60, 80} sorted is: ";
    sort(numbers,numbers+6);
    for (int i =0; i<6; ++i)
    {
        cout<<numbers[i]<<" ";
    }
    cout<<endl<<endl;
    
    
    cout<<"{Jack, Bill, Bob, Adam, Doug} sorted is: ";

    qsort(name, 5, sizeof(name[0]), compare);
    for (int i = 0; i<5; ++i)
    {
        for (int j = 0; j<7; ++j)
        {
            cout<<name[i][j];
        }
        cout<<" ";
    }
    cout<<endl<<endl;
    
    cout<<"{3.2, 3.9, 2.7, 2.5, 3.6, 2.9} sorted is: ";
    sort(gpa,gpa+6);
    for (int i =0; i<6; ++i)
    {
        cout<<gpa[i]<<" ";
    }
    cout<<endl<<endl;
    
    
    cout<<"{Winter, Spring, Summer, Fall} sorted is: ";
    sort(seasons,seasons+4);
    for (int i =0; i<4; ++i)
    {
        cout<<seasons[i]<<" ";
    }
    cout<<endl<<endl;
    
    
    return 0;
}
