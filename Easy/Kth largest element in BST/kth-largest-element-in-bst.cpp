//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
// Back-end complete function template in C++

class Solution
{
    public:
    // Utility function to find the kth largest element in a binary search tree
    void kthLargestUtil(Node *root, int k, int &c, int &res)
    {
        // Base case: if root is NULL or we have already found k elements
        if (root == NULL || c >= k)
            return;
        
        // Recursively traverse the right subtree
        kthLargestUtil(root->right, k, c, res);
        
        // Increment the count
        c++;
        
        // If we have found the kth largest element, update the result
        if (c == k)
        {
            res = root->data;
            return;
        }
        
        // Recursively traverse the left subtree
        kthLargestUtil(root->left, k, c, res);
    }
    
    // Function to find the kth largest element in a binary search tree
    int kthLargest(Node *root, int k)
    {
        // Initialize count and result variables
        int c = 0;
        int res = -1;
        
        // Call the utility function to find the kth largest element
        kthLargestUtil(root, k, c, res);
        
        // Return the result
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}
// } Driver Code Ends