//
//  main.cpp
//  problemSeven
//
//  Tayseer Edouni 

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Queue
{
private:
    struct node
    {
        float coeff;
        float power;
        node *next;
    };
    
    node *list;
    
public:
    
    Queue()
    {
        list = NULL;
        
    }
    
    void display()
    {
        node *p = list;
        
        //Do not display if coefficient is equal to 0
        while (p!= NULL)
        {
            if(p == list) //front of queue
            {
                cout<<"F(x) = "<<p->coeff<<"X^"<<p->power<<" ";
            }
            else if (p->coeff > 0)
            {
                cout<<"+ "<<p->coeff<<"X^"<<p->power<<" ";

            }
            else if(p->coeff <0)
            {
                cout<<"- "<<fabs(p->coeff)<<"X^"<<p->power<<" ";

            }
            p = p->next;
        }
        cout<<endl;
    }
    
    void compute (float x)
    {
        float result = 0;
        node *p = list;
        
        while(p!= NULL)
        {
            result += p->coeff * pow(x, p->power);
            p = p->next;
        }
        cout<<"F("<<x<<") = "<<fixed<<setprecision(2)<<result<<endl;
        
    }
    
    
    
    void  insert(float coefficient, float pow)
    {
        node *p = new node;
        node *r = list;
        p->coeff = coefficient;
        p->power = pow;
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

};
int main(int argc, const char * argv[]) {
  
    Queue myQueue;
    float coeff, power;
    bool cont = true;
    do
    {
    
        cout<<"Enter the coefficient and power of a term (0 0 to stop): ";
        cin>>coeff>>power;
        cout<<endl;
        if (coeff == 0 && power == 0)
        {
            
            cont = false;
        }
        else
        {
            myQueue.insert(coeff, power);

        }
    } while (cont);
    
    myQueue.display();
    
    cout<<"Given the x value: ";
    float xValue;
    cin>>xValue;
    myQueue.compute(xValue);
    

    
    
    
    return 0;
}
