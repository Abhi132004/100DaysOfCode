//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void dfs(Node* root, vector<int>& parent,int &mx) {
    if (!root) return;
    mx=max(mx,root->data);
    if (root->left) {
        parent[root->left->data] = root->data;
        dfs(root->left, parent,mx);
    }
    if (root->right) {
        parent[root->right->data] = root->data;
        dfs(root->right, parent,mx);
    }
}
int kthAncestor(Node *root, int k, int node)
{
    int limit=1e5+1;
    int mx=1;
    vector<int>parent(limit,-1);
    if(root) parent[root->data]=-1;
    dfs(root,parent,mx);
    vector<vector<int>>pre(mx+1,vector<int>(10,-1));
    for(int j=0;j<=9;j++){
      for(int i=1;i<=mx;i++){
          if(j==0) pre[i][j]=parent[i];
          else{
              if(pre[i][j-1]!=-1){
              pre[i][j]=pre[pre[i][j-1]][j-1];
              }
          }
      }
    }
    for(int i=0;i<=9;i++){
        if((1<<i)&k){
            node=pre[node][i];
            if(node==-1) return node;
        }
    }
    return node;
    
}
