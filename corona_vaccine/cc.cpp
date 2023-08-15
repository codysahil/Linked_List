//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
public:
    int supplyVaccine(Node* root){
        // Your code goes here
                    const int inf = 1e9;
        function<array<int, 3>(Node*)> dfs = [&](Node * node) {
            array<int, 3> curr = {1, inf, 0};
            if(node->left == nullptr && node->right == nullptr) {
                // leaf node
                curr[2]=0;
                return curr;
            }
            array<int, 3> lft, rht;
            lft = rht = {inf,0,0};
            if(node->left) {
                lft = dfs(node->left);
                curr[0] += min({lft[0], lft[1], lft[2]});
            }
            if(node->right) {
                rht = dfs(node->right);
                curr[0] += min({rht[0], rht[1], rht[2]});
            }
            curr[2] = lft[1]+rht[1];
            curr[1] = min(lft[0]+min(rht[0],rht[1]), rht[0]+min(lft[0], lft[1]));
            // cout << node->data << endl;
            // cout << curr[0] << ' ' << curr[1] << ' ' << curr[2] << endl;
            return curr;
        };
        auto ans = dfs(root);
        // 0 -> putting a vaccine on myself
        // 1 -> getting vaccintaed from child
        // 2 -> not getting vaccinated
        return min(ans[0], ans[1]);

    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}




// } Driver Code Ends
