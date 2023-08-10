//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    string a,b;
    Node *temp1=l1,*temp2=l2;
    
    while(temp1)
    {
        if(temp1->data!=0)
        break;
        temp1=temp1->next;
    } 
    
    while(temp1)
    {
        a.push_back('0'+temp1->data);
        temp1=temp1->next;
    } 
    
     while(temp2)
    {
        if(temp2->data!=0)
        break;
        temp2=temp2->next;
    } 
    
    while(temp2)
    {
        b.push_back('0'+temp2->data);
        temp2=temp2->next;
    } 
    
    string ele1,ele2;
    if(a.size()<b.size())
    {
        ele1=b;
        ele2=a;
    }
    else if(a.size()==b.size())
    {
        if(a<b)
        {
            ele1=b;
            ele2=a;
        }
        else
        {
            ele1=a;
            ele2=b;
        }
    }
    else
    {
         ele1=a;
        ele2=b;
    }
    
    string result;
    int i=ele1.size()-1,j=ele2.size()-1;
    int borr=0;
    while(i>=0 && j>=0)
    {
        int x=ele1[i]-'0';
        int y=ele2[j]-'0';
        int z=x-y-borr;
        if(z>=0)
        {
            borr=0;
            result.push_back('0'+z);
        }
        else
        {
            z=z+10;
            borr=1;
            result.push_back('0'+z);
        }
        i--;
        j--;
    }
    while(i>=0)
    {
        int x=ele1[i]-'0';
        int z=x-borr;
        if(z>=0)
        {
            borr=0;
            result.push_back('0'+z);
        }
        else
        {
            z=x-borr+10;
            borr=1;
            result.push_back('0'+z);
        }
        i--;
    }
    while(j>=0)
    {
        int y=ele2[j]-'0';
        int z=y-borr;
        if(z>=0)
        {
            borr=0;
            result.push_back('0'+z);
        }
        else
        {
            z=y-borr+10;
            borr=1;
            result.push_back('0'+z);
        }
        j-- ;
    }
    
    i=result.size()-1;
    while(i>=0)
    {
        if(result[i]!='0')
        break;
        
        i--;
    }
    
    if(i==-1)
    {
        struct Node *newnode =new Node(0);
        return newnode;
    }
    
    j=0;
    struct Node *dummy=new Node(-1);
    struct Node *d=dummy;
    while(i>=0)
    {
        struct Node *newnode=new Node(result[i]-'0');
        dummy->next=newnode;
        dummy=newnode;
        i-- ;
        
    }
    return d->next;
}
