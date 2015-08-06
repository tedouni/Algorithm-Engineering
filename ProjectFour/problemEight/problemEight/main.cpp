//
//  main.cpp
//  problemEight
//
//  Tayseer Edouni & Lisa Nguyen
#include <iostream>
using namespace std;

//remove duplicates in a[5]

class linkedList
{
private:
    struct node
    {
        int value;
        node *next;
    };
    
    node *list;
    
public:
    linkedList()
    {
        list = NULL;
    }
    
    void insert(int x)
    {

        node *p = new node;
        node *r = list;
        p->value = x;
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
            cout<<p->value<<" ";
            p = p->next;
        }
    }
    
    void removeRepeat()
    {

        if (list == NULL)
            return;
        node *prev = list;
        node* current = list->next;
        
        while (current != NULL)
        {
            node *kept = list;
            while(kept != current)
            {
                if (current->value == kept->value)
                {
                    prev->next = current->next;
                    current = current->next;
                    cout<<"Removed "<<kept->value<<endl;
                    break;
                }
                kept = kept->next;
            }
            
            if (kept == current)
            {
                prev = current;
                current= current->next;
            }
        }
        
    }

};

int main(int argc, const char * argv[]) {
    
    int a[5] = {3, 2, 2, 3, 5};
    
    cout<<"Remove duplicates in:\n";
    cout<<"a[5] = { ";
    linkedList myList;
    for (int i =0; i<5; ++i)
    {
        myList.insert(a[i]);
    }
    myList.display();
    cout<<"}\n";
    
    myList.removeRepeat();
    myList.display();
    return 0;
}
