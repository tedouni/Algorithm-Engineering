//
//  main.cpp
//  problemThree
//
//  Created by Tayseer Edouni on 3/16/15.
//  Copyright (c) 2015 Tayseer Edouni. All rights reserved.
//

#include <iostream>
using namespace std;
class OrderedLinkedList
{
private:
    struct node
    {
        int value;
        node *next;
    };
    
    node *list;
    
public:
    OrderedLinkedList()
    {
        list = NULL;
    }
    
    void display()
    {
        node *p = list;
        
        while (p!= NULL)
        {
            cout<<p->value<<" ";
            p = p->next;
        }
    }
    
    void insert(int x)
    {
        node *p = list, *q = list, *r;
        r = new node;
        r->value = x;
        
        while (p!= NULL && p->value < x)
        {
            q = p;
            p = p->next;
        }
        
        //first node
        if (p == list)
        {
            list = r;
            r->next = p;
        }
        //last node
        else if(p == NULL)
        {
            q->next = r;
        }
        else
        {
            r->next = p;
            q->next = r;
        }
        
    }
    
};



int main(int argc, const char * argv[]) {
    int a[10] = {79, 13, 16, 64, 39, 20, 89, 53, 71, 42};
    OrderedLinkedList zero, one, two, three, four;
    OrderedLinkedList hashTable[5]={zero,one,two,three,four};
    cout<<"unsorted: ";
    for (int i = 0; i<10; ++i)
    {
        int tempIndex = a[i] /10 /2;
        hashTable[tempIndex].insert(a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"sorted: \n";
    for (int i = 0; i<5; ++i)
    {
        cout<<"For Index "<<i<<endl;
        hashTable[i].display();
        cout<<endl;
    }
    
    return 0;
}
