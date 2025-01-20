//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
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
// User function Template for C++

/*
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
class Solution {
  public:
    unordered_map<int, Node*> parent; // Map child value -> parent node

    Node* findtargetpointer(Node* root, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->data == target) return temp;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return nullptr; // Handle case where target is not found
    }

    void buildParentMap(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left) {
                parent[temp->left->data] = temp; // Map left child to parent
                q.push(temp->left);
            }
            if (temp->right) {
                parent[temp->right->data] = temp; // Map right child to parent
                q.push(temp->right);
            }
        }
    }

    void cal_dist(Node* target, int& maxDist) {
        unordered_set<int> visited; // Keep track of visited nodes
        queue<Node*> q;
        q.push(target);
        visited.insert(target->data);

        while (!q.empty()) {
            int size = q.size();
            bool expanded = false; // Track if any new nodes are added at this level

            while (size--) {
                Node* temp = q.front();
                q.pop();

                // Add left child if not visited
                if (temp->left && visited.find(temp->left->data) == visited.end()) {
                    q.push(temp->left);
                    visited.insert(temp->left->data);
                    expanded = true;
                }

                // Add right child if not visited
                if (temp->right && visited.find(temp->right->data) == visited.end()) {
                    q.push(temp->right);
                    visited.insert(temp->right->data);
                    expanded = true;
                }

                // Add parent if not visited
                if (parent.find(temp->data) != parent.end() && visited.find(parent[temp->data]->data) == visited.end()) {
                    q.push(parent[temp->data]);
                    visited.insert(parent[temp->data]->data);
                    expanded = true;
                }
            }

            if (expanded) maxDist++;
        }
    }

    int minTime(Node* root, int targetValue) {
        Node* target = findtargetpointer(root, targetValue);
        if (!target) return 0; // If target node is not found, return 0

        buildParentMap(root); // Build parent-child relationships

        int maxDist = 0;
        cal_dist(target, maxDist); // Calculate maximum distance
        return maxDist;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends