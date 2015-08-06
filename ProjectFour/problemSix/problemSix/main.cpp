//
//  main.cpp
//  problemSix
//
//  Created by Tayseer Edouni on 3/13/15.
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
    
    bool testForValue(int x)
    {
        bool xIsFound = false;
        node *p = list;
        while (p!= NULL)
        {
            if (p->value == x)
            {
                xIsFound = true;
            }
            p = p->next;
        }
        
        return xIsFound;
    }
    
    void  deleteNode(int x)
    {
        node *r, *p = list;
        
        while (p->value != x)
        {
            r = p;
            p = p->next;
        }
        r->next = p->next;
        delete (p);
        
    
    }

    friend OrderedLinkedList returnUnion(const OrderedLinkedList& , const OrderedLinkedList& );
    friend OrderedLinkedList returnDifference(const OrderedLinkedList& , const OrderedLinkedList& );

};


 OrderedLinkedList returnUnion(const OrderedLinkedList&  a, const OrderedLinkedList& b)
{
    OrderedLinkedList result;
    
    OrderedLinkedList::node *x = a.list;
    OrderedLinkedList::node *y = b.list;
    
    while (x!= NULL && y!= NULL)
    {
        if (x->value > y->value)
        {
            result.insert(x->value);
            x = x->next;
        }
        else if (y->value > x->value)
        {
            
            result.insert(y->value);
            y = y->next;
        }
        else
        {
            
            result.insert(x->value);
            x = x->next;
            y = y->next;
        }
    }
    
    
    while (x!= NULL)
    {
        if (!result.testForValue(x->value))
        {
            result.insert(x->value);
        }
        x = x->next;
    }
    
    while (y!= NULL)
    {
        if (!result.testForValue(y->value))
        {
            result.insert(y->value);
        }
        y = y->next;
    }
    
    return result;
}

OrderedLinkedList returnDifference(const OrderedLinkedList& a, const OrderedLinkedList& b)
{
    OrderedLinkedList result;
    
    OrderedLinkedList::node *x = a.list;
    OrderedLinkedList::node *y = b.list;
    OrderedLinkedList::node *finalRun = b.list;

    
    //setA - setB
    
    while (x!= NULL && y!= NULL)
    {
        if (x->value != y->value)
        {
            result.insert(x->value);
            x = x->next;
            y = y->next;
        }
        else
        {
            x = x->next;
            y = y->next;
        }
    }
    
    
    while (x!= NULL)
    {
        if (!result.testForValue(x->value))
        {
            result.insert(x->value);

        }
        x = x->next;
    }
    
    while (finalRun != NULL)
    {
        if (result.testForValue(finalRun->value))
        {
            result.deleteNode(finalRun->value);
            cout<<finalRun->value<<" found \n";
        }
        
        finalRun = finalRun->next;
    }
    
    
    return result;

}

int main(int argc, const char * argv[]) {
    
    OrderedLinkedList setA;
    OrderedLinkedList setB;
    
    setA.insert(6);
    setA.insert(4);
    setA.insert(9);
    setA.insert(2);

    setB.insert(10);
    setB.insert(6);
    setB.insert(4);
    setB.insert(2);
    setB.insert(8);
   


    cout<<"A = { ";
    setA.display();
    cout<<"}\n";
    
    cout<<"B = { ";
    setB.display();
    cout<<"}\n";
    OrderedLinkedList aUnionB = returnUnion(setA, setB);
    
    cout<<"AUB = { ";
    aUnionB.display();
    cout<<"}\n";
    
    
    OrderedLinkedList aDifferenceB = returnDifference(setA, setB);
    cout<<"A-B = { ";
    aDifferenceB.display();
    cout<<"}\n";

    
    
    
    
    return 0;
}
