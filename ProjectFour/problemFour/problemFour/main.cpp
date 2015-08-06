//
// Main.cpp
// Problem 4
// Tayseer Edouni


#include <iostream>
#include <string>


using namespace std;
template <class T>

class Queue
{
private:
    struct NODE
    {
        T info;
        NODE* next;
    };
    
    NODE *front, *rear;
    
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    
    void pushQ( T x)
    {
        NODE *p = new NODE;
        
        p->info=x;
        p->next=NULL;
        
        if (front==NULL)
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    
    bool emptyQ()
    {
        return (front==NULL)? true : false;
        
    }
    
    T popQ()
    {
        NODE *p = front;
        T x;
        
        x= front->info;
        
        front=front->next;
        
        delete (p);
        
        return x;
    }
    
    void  display()
    {
        NODE *p = front;
        while (p!= NULL)
        {
            cout<<p->info<<" ";
            p = p->next;
        }
        cout<<endl;
    
    }
    
    
    ~Queue()
    {
        
    }

};




int main()
{

    string myChar[16] = {"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TEA",
        "FOX", "TAB", "BAR" , "EAR", "TAR", "GIG", "BIG", "NOW"};
    
    Queue<string> a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    Queue<string> hashTable[26] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
    
    
    cout<<"unsorted: ";
    
    for (int i =0 ; i<16; ++i)
    {
        cout<<myChar[i]<<" ";
        char thirdLetter = myChar[i][2];
        int tempIndex = int(thirdLetter) % 26;
        hashTable[tempIndex].pushQ(myChar[i]);
    }
    cout<<endl;
    
    string secondMyChar[16];
    int indexCounter = 0;

    for (int i = 0; i<26; ++i)
    {
        //hashTable[i].display();
        while (!hashTable[i].emptyQ())
        {
            string temp = hashTable[i].popQ();
            secondMyChar[indexCounter] = temp;
            indexCounter++;
        }
        

    }
    cout<<endl;
    
    cout<<"After first pass (third letter)\n";
    for (int i =0 ; i<16; ++i)
    {
        cout<<secondMyChar[i]<<" ";
        char secondLetter = secondMyChar[i][1];
        int tempIndex = int(secondLetter) % 26;
        hashTable[tempIndex].pushQ(secondMyChar[i]);
    }
    cout<<endl;
    string thirdmyChar[16];
    indexCounter = 0;
    
    for (int i = 0; i<26; ++i)
    {
        //hashTable[i].display();
        while (!hashTable[i].emptyQ())
        {
            string temp = hashTable[i].popQ();
            thirdmyChar[indexCounter] = temp;
            indexCounter++;
        }
    
    }
    
    cout<<"After second pass (middle letter)\n";
    for (int i =0 ; i<16; ++i)
    {
        cout<<thirdmyChar[i]<<" ";
        char firstLetter = thirdmyChar[i][1];
        int tempIndex = int(firstLetter) % 26;
        hashTable[tempIndex].pushQ(thirdmyChar[i]);
    }

    cout<<endl;
    string lastMyChar[16];
    indexCounter = 0;
    
    for (int i = 0; i<26; ++i)
    {
        //hashTable[i].display();
        while (!hashTable[i].emptyQ())
        {
            string temp = hashTable[i].popQ();
            lastMyChar[indexCounter] = temp;
            indexCounter++;
        }
        
    }
    
    cout<<"After last pass (first letter)\n";
    for (int i =0 ; i<16; ++i)
    {
        cout<<lastMyChar[i]<<" ";
        char firstLetter = lastMyChar[i][0];
        int tempIndex = int(firstLetter) % 26;
        hashTable[tempIndex].pushQ(lastMyChar[i]);
    }
    cout<<endl;
    
    return 0;
}