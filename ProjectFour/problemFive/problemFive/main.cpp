//
//  main.cpp
//  problemFive
//
//  Created by Tayseer Edouni on 3/17/15.
//  Copyright (c) 2015 Tayseer Edouni. All rights reserved.
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



struct NODE
{
    string name;
    NODE *left, *right;
};

NODE* root, *root2;

void insert(NODE *&r, string x);
void displayInOrder(NODE *&r); //Part One (LC)(P)(RC)
void displayLeavesInOrder(NODE *&r); //Part Two
int height(NODE *p);
void displayDescendants (NODE *p, string x);
void displayTreeRotated(NODE *p, int sp);
bool compareTrees(const NODE* t1 , const NODE *t2);
int main()
{
    
    
    root = NULL;
    root2 = NULL;
    string myChar[16] = {"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TEA",
        "FOX", "TAB", "BAR" , "EAR", "TAR", "GIG", "BIG", "NOW"};
    
    for (int i = 0; i < 16; i++)
    {
        insert(root, myChar[i]);
        insert(root2, myChar[i]);
    }
    
    bool areEqual = compareTrees(root, root2);
    cout<<areEqual<<" both trees are equal\n";
//    cout<<"Display only the leaves of the tree in order:\n";
//    displayLeavesInOrder(root);
//    cout<<endl<<endl;
//    int heightOfTree= height(root);
//    cout<<"Height of tree is: "<<heightOfTree;
//    cout<<endl<<endl;
//    cout<<"Descendants of FOX: \n";
//    displayDescendants(root, "FOX");
//    cout<<endl<<endl;
//    cout<<"Descendants of GIG: \n";
//    displayDescendants(root, "GIG");
//    cout<<endl;
//    
//    displayTreeRotated(root,1);

    return 0;
}

void insert(NODE *&r, string x)
{
    if (r == NULL)
    {
        r = new NODE;
        r->name = x;
        r->left = r->right = NULL;
    }
    
    else if (x < r->name)
        insert(r->left, x);
    else
        insert(r->right, x);
    
}

void displayInOrder(NODE *&r)
{
    if (r != NULL)
    {
        cout << left << setw(15);
        displayInOrder(r->left);
        cout << r->name <<endl;
        cout << left << setw(15);
        displayInOrder(r->right);
    }
}

void displayLeavesInOrder(NODE *&r)
{
    if (r != NULL)
    {
        displayLeavesInOrder(r->left);
        if (r->left == NULL & r->right == NULL)
        {
            cout << r->name <<" ";
        }
        displayLeavesInOrder(r->right);
    }
}

int height(NODE *p)
{
    if (p == NULL)
    {
        return 0 ;
    }
    else
    {
        return 1 + max(height(p->left), height(p->right));
    }
}

void displayDescendants (NODE *p, string x)
{
    if (p == NULL)
        return;
    else if(p->name == x)
    {
        if (p->left == NULL && p->right == NULL)
        {
            cout<<"No Descendants of "<<p->name<<"\n";
            return;
        }
        displayLeavesInOrder(p);
    }
    else if (x< p->name)
    {
        displayDescendants(p->left, x);
    }
    
    else
    {
        displayDescendants(p->right, x);
    }
}

void displayTreeRotated(NODE *p, int sp)
{
    if (p!= NULL)
    {
        displayTreeRotated(p->right, sp += 5);
        cout<<setw(sp)<<p->name;
        displayTreeRotated(p->left, sp);
    }
}

bool compareTrees(const NODE *t1 , const NODE *t2)
{
 
    
    if (t1 == t2)
    {
        return true;
    }

    
    else if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    
    else
        return compareTrees(t1->left, t2->left) && compareTrees(t1->right, t2->right) && t1->name == t2->name;
    
}

