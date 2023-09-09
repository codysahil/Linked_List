//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        stack<Node*> stack0,stack1,stack2;
        
        Node *current = head;
        while(current){
            if(current->data == 0){
                stack0.push(current);
            }
            else if(current->data == 1){
                stack1.push(current);
            }
            else{
                stack2.push(current);
            }
            current = current->next;
        }
        Node *sorted_head = nullptr;
        while(!stack2.empty()){
            current = stack2.top();
            stack2.pop();
            current->next = sorted_head;
            sorted_head = current;
        }
        while(!stack1.empty()){
            current = stack1.top();
            stack1.pop();
            current->next = sorted_head;
            sorted_head = current;
        }
        while(!stack0.empty()){
            current = stack0.top();
            stack0.pop();
            current->next = sorted_head;
            sorted_head = current;
        }
        return sorted_head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
