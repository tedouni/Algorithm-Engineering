//
//  main.cpp
//  AssignmentSixFloyd
//
//  Created by Tayseer Edouni on 4/19/15.
//  Copyright (c) 2015 Tayseer Edouni. All rights reserved.
//


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //100 for infinity
    int C[6][6] =
    //    A   B   C   D   E   F
    {
/*A*/   {0,   3,  100,  4,  100, 5},
/*B*/   {100, 0, 1, 100, 100, 1},
/*C*/   {100, 100, 0, 2,  100, 100},
/*D*/   {100, 1,  100, 0, 100, 100},
/*E*/   {100, 100, 100, 3, 0, 2},
/*F*/   {100, 100, 100, 2, 100, 0}
     
    };
    
//    int C[5][5] = {
//        {0,1,100,100,100},
//        {100,0,2,100,100},
//        {100,100,100,2,4},
//        {100,1,3,100,100},
//        {100,100,100,5,0}};
//    
//    

    
    int A[6][6] = {0};
    int P[6][6] = {0};
    int i, j, k;
    
    cout<<"Matrix C (cost matrix) = \n";
    for (i = 0; i<6; ++i)
    {
        for (j = 0; j <6; ++j)
        {
            if (C[i][j] == 100)
            {
                cout<<"∞"<<"\t";
            }

            else cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    
    
    
    for (i = 0; i<6; ++i)
    {
        for (j = 0; j<6; ++j)
        {
            A[i][j] = C[i][j];
        }
    }
    
    for (i = 0; i<6; ++i)
    {
        A[i][i] = 0;
    }
    
    for (k = 0; k<6; ++k)
    {
        for (i = 0; i<6; ++i)
        {
            for (j = 0; j<6; ++j)
            {
                if ((A[i][k] + A[k][j]) < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
    
    cout<<"Matrix A=\n";
    for (i = 0; i<6; ++i)
    {
        for (j = 0; j<6; ++j)
        {
            if (A[i][j] == 100)
            {
                cout<<"∞"<<"\t";
            }
            else cout<<A[i][j]<<"\t";
            
        }
        
        cout<<endl;
    }
    
    cout<<"Matrix P=\n";
    
    for (i = 0; i<6; ++i)
    {
        for (j = 0; j<6; ++j)
        {
            cout<<P[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
