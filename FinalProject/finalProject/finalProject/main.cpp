//
//  main.cpp
//  finalProject
//
//  Created by Tayseer Edouni on 5/5/15.
//  Copyright (c) 2015 Tayseer Edouni. All rights reserved.
//
//source code http://alturl.com/mx9d2
#include <iostream>
#include <iomanip>
using namespace std;

double A[6][6] = {0};
double P[6][6] = {0};

bool isECircuit(int list[])
{
    
    for (int i =0; i< 6; ++i)
    {
        if (list[i] %2 != 0)
        {
            return false;
        }
    }
    
    return true;

}

class linkedList
{
private:
    struct node
    {
        int _vertexNumber;
        double _edgeValue;
        node *next;
    };
    
    node *list;
    
public:
    linkedList()
    {
        list = NULL;
    }
    
    void insert(int vertexNumber,double edgeValue)
    {
        
        node *p = new node;
        node *r = list;
        p->_vertexNumber = vertexNumber;
        p->_edgeValue = edgeValue;
        
        p->next = NULL; //queue first in first out
        //if queue is empty
        if (list == NULL)
        {
            list = p;
        }
        else
        {
            
            while (r->next != NULL)
            {
                r = r->next;
            }
            
            r->next = p;
        }
        
    }
    
    
    void display()
    {
        node *p = list;
        
        while (p!= NULL)
        {
            cout<<"->"<<p->_vertexNumber<<","<<p->_edgeValue;
            p = p->next;
        }
        cout<<"->"<<"NULL\n";
    }
    
    bool search(int x)
    {
        node *p = list;
        
        while (p!= NULL && x != p->_vertexNumber)
        {
            p = p->next;
        }
        if (x == p->_vertexNumber)
        {
            return true;
        }
        else
            return false;
    
    }
};

void _short(int v1, int v2)
{
    int pp = P[v1][v2];
    if (pp > 0)
    {
        
        _short(v1, pp);
        cout<<"-> "<<pp<<" ";
        _short(pp, v2);
      
    }
    
}

void getLength(int v1, int v2, int &_length)
{
    int pp = P[v1][v2];
    if (pp > 0)
    {
        
        getLength(v1, pp,_length);
        _length++;
        getLength(pp, v2,_length);
        
    }
    
}

int main(int argc, const char * argv[])
{

    cout<<"Final Project by Tayseer Edouni\n";
    cout<<"Source Code: http://alturl.com/mx9d2\n\n\n";
    
    double costMatrix[6][6]=
    {
        {0,.41,0,0,0,.29},
        {0,0,.51,0,.32,0},
        {0,0,0,.5,0,0},
        {.45,0,0,0,0,.38},
        {0,0,.32,.36,0,0},
        {0,.29,0,0,.21,0}

    };
    int aMatrix[6][6] =
    {
        {0,1,0,0,0,1},
        {0,0,1,0,1,0},
        {0,0,0,1,0,0},
        {1,0,0,0,0,1},
        {0,0,1,1,0,0},
        {0,1,0,0,1,0}
    };
    
    linkedList zero, one, two, three, four, five;
    linkedList table[6] = {zero, one, two, three, four, five};
    
    // a) construct adjacency list
    for (int i = 0; i<6; ++i)
    {
        
        for (int j = 0; j<6; ++j)
        {
            if (costMatrix[i][j] > 0)
            {
                switch (i)
                {
                    case 0:
                        table[0].insert(j, costMatrix[i][j]);
                        break;
                    case 1:
                        table[1].insert(j, costMatrix[i][j]);
                        break;

                    case 2:
                        table[2].insert(j, costMatrix[i][j]);
                        break;

                    case 3:
                        table[3].insert(j, costMatrix[i][j]);
                        break;

                    case 4:
                        table[4].insert(j, costMatrix[i][j]);
                        break;

                    case 5:
                        table[5].insert(j, costMatrix[i][j]);
                        break;
                        
                    default:
                        cout<<"ERROR\n";
                        break;
                }
            }
        }
    }
    
    // b) display adjacency list
    cout<<"\nPart B:\n";
    cout<<"This is the adjacency list of the graph\n";
    for (int i =0; i<6; ++i)
    {
        cout<<"G["<<i<<"]";
        table[i].display();
        
    }
    cout<<endl;
    
    // c) A graph has an Euler circuit if and only if each of its vertices has even degree.
    //Determine whether this graph has an Euler circuit or not
    //http://www.cs.mcgill.ca/~ethan/TA/251/eulerian.pdf
    
    cout<<"Part C\n";
    int dummyMatrix[6][6] =
    {
        {0,1,0,0,0,1},
        {0,0,1,0,1,0},
        {0,0,0,1,0,0},
        {1,0,0,0,0,1},
        {0,0,1,1,0,0},
        {0,1,0,0,1,0}
    };
   
    int vertex[6] = {0};

    //vertex 0
    int row = 0;
    int col = 0;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }

    //vertex 1
    row = 1;
    col = 1;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }
    
    //vertex 2
    row = 2;
    col = 2;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }
    
    //vertex 3
    row = 3;
    col = 3;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }
    
    //vertex 4
    row = 4;
    col = 4;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }

    //vertex 5
    row = 5;
    col = 5;
    for (int j = 0; j<6; ++j)
    {
        if (dummyMatrix[row][j] > 0)
        {
            
            vertex[row]++;
        }
    }
    for (int i = 0; i<6; ++i)
    {
        if (dummyMatrix[i][col] > 0)
        {
            vertex[row]++;
        }
    }
    
    if (isECircuit(vertex))
    {
        cout<<"Graph is a Euler Circuit. All vertexes have even degree\n";
    }
    else
        cout<<"NO!. This Graph does not contain an Euler Circuit\n\n";

    // d) Apply Floyd's Algorithm to find min path between all pairs of vertices
    cout<<"Part D\n\n";
    double C[6][6]=
    {
        {0,.41,100,100,100,.29},
        {100,0,.51,100,.32,100},
        {100,100,0,.5,100,100},
        {.45,100,100,0,100,.38},
        {100,100,.32,.36,0,100},
        {100,.29,100,100,.21,0}
        
    };
 
    int i, j, k;

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
    cout<<setw(4)<<"\t"<<0<<"\t\t"<<1<<"\t\t"<<2<<"\t\t"<<3<<"\t\t"<<4<<"\t\t"<<5<<endl;
    cout<<"------------------------------------------------\n";
    for (i = 0; i<6; ++i)
    {
        cout<<i<<"|\t";
        for (j = 0; j<6; ++j)
        {
            if (A[i][j] == 100)
            {
                cout<<"∞"<<"\t";
            }
            else cout<<setw(4)<<A[i][j]<<"\t";
            
        }
        
        cout<<endl;
    }
    
    cout<<endl<<endl;
    cout<<"Matrix P=\n";
    cout<<"\t"<<0<<"\t"<<1<<"\t"<<2<<"\t"<<3<<"\t"<<4<<"\t"<<5<<endl;
    cout<<"---------------------------\n";

    for (i = 0; i<6; ++i)
    {
        cout<<i<<"|\t";

        for (j = 0; j<6; ++j)
        {
            cout<<P[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    //E) Given two vertices, v1, v2 , and an integer number n.
    //Is there a path of length n between v1 and v2. Display the path.
    cout<<"\nPart E\n\n";
    cout<<"Please enter two vertices: ";
    int v1,v2;
    cin>>v1>>v2;
    
    cout<<"Enter a positive integer number (length): ";
    int length;
    cin>>length;
    //use vertex array
    
    if (length <= 0)
    {
        cout<<"No there is no path between "<<v1<<" and "<<v2<<" with length "<<length;
    }
    else
    {
        double C2[6][6]=
        {
            {0,.41,100,100,100,.29},
            {100,0,.51,100,.32,100},
            {100,100,0,.5,100,100},
            {.45,100,100,0,100,.38},
            {100,100,.32,.36,0,100},
            {100,.29,100,100,.21,0}
            
        };
        
        double pp = P[v1][v2];
        
        int checkLength = 0;
        if (aMatrix[v1][v2] < 100)
        {
            
            getLength(v1, v2,checkLength);
       }
        checkLength++;
        if (checkLength == length)
        {
            cout<<"Yes there is a path of length "<<length<<" between vertex "<<v1<<" and "<<v2<<": ";
            if (aMatrix[v1][v2] < 100)
            {
                cout<<v1<<" ";
                _short(v1, v2);
                cout<<"-> "<<v2;
            }
        }
        else
        {
            cout<<"No. There is no path of length "<<length<<" between vertex "<<v1<<" and "<<v2<<endl;
        
        }
    }


    return 0;
}
        
        
