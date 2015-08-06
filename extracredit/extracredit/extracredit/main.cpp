//Tayseer Edouni
//335 Extra Credit

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


struct NODE
{
    int data;
    NODE *left, *right;
};

void insert(NODE *&r, int x)
{
    if (r == NULL)
    {
        r = new NODE;
        r->data = x;
        r->left = r->right = NULL;
    }
    
    else if (x < r->data)
        insert(r->left, x);
    else
        insert(r->right, x);
    
}

struct nodeDepth
{
    NODE * n;
    int level;
    
    //constructor
    nodeDepth(NODE* n_, int level_)
    {
        n = n_;
        level = level_;
    }
};

int height(NODE * n)
{
    if (n == NULL)
        return 0;
    
    else
        return 1 + max(height(n->left), height(n->right));
}

void prettyPrint(NODE* n)
{
 
    int lastLevel = 0;
    char buffer[100];
    int depth = height(n);
    int offset = (1 << depth) - 1;
    
    //queue of nodeDepth
    queue<nodeDepth> q;
    q.push(nodeDepth(n, lastLevel));
    
    while (!q.empty())
    {
        nodeDepth temp = q.front();
        
        if (lastLevel != temp.level)
        {
            cout<<endl;
            lastLevel = temp.level;
            offset = (1 << (depth - temp.level)) - 1;
        }
        
        // output
        if (temp.n)
            sprintf(buffer, "%*s%d%*s", offset, " ", temp.n->data, offset, " ");
        else
            sprintf(buffer, "%*s", offset << 1, " ");
        
        cout << buffer;
        
        if (temp.n)
        {
            q.push(nodeDepth(temp.n->left, lastLevel + 1));
            q.push(nodeDepth(temp.n->right, lastLevel + 1));
        }
        q.pop();
    }
}


int main()
{

    cout<<"Tayseer Edouni\nCPSC335 Extra Credit\n\n";
    NODE *root = NULL;
    
    int a[7] = {8,5,4,9,7,11,1};
    
    for (int i =0; i<7; ++i)
    {
        insert(root, a[i]);
    }
    
    prettyPrint(root);
    return 0;
}