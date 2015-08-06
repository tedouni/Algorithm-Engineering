//
//  main.cpp
//  problemTwo
//
//  Tayseer Edouni 

#include <iostream>

using namespace std;

class Fraction
{

private:
    int num;
    int den;
    
public:
    Fraction()
    {
        num = 1;
        den = 0;
    }
    
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }

    
    void normalize()
    {
        int u = num;
        int v = den;
        int temp;
        
        while (v!= 0)
        {
            temp = u%v;
            u = v;
            v = temp;
        }
        
        num /= u;
        den /= u;
    }
    
    Fraction operator + (const Fraction& other)
    {
        Fraction result;
        result.num =  this->num * other.den + this->den * other.num;
        result.den = this->den * other.den;
        
        result.normalize();
        
        return result;
    }
    
    friend ostream& operator<< ( ostream& os, const Fraction& fr );


};

ostream& operator<< ( ostream& os, const Fraction& fr )
{
    return os<<fr.num<<"/"<<fr.den;
}

int main(int argc, const char * argv[]) {
    
    char contVar;
    int tempNum;
    int tempDen;
    do
    {
        cout<<"Enter a faction: ";
        cin>>tempNum;
        cin.ignore();
        cin>>tempDen;
        Fraction f1(tempNum, tempDen);
        
        cout<<"Enter another faction: ";
        cin>>tempNum;
        cin.ignore();
        cin>>tempDen;
        Fraction f2(tempNum, tempDen);
        
        Fraction result = f1 + f2;
        cout<<f1<<" + "<<f2<<" = "<<result<<endl;
        
        cout<<"CONTINUE(y/n)? ";
        cin>>contVar;
    }
    while (contVar != 'n');
   
    
    return 0;
}
