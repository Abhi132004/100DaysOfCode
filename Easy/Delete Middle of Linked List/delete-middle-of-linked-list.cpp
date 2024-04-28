//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    int midPoint(Node *head){
        int count = 0;
        int ev = 1;
        Node  *temp = head;
        while(temp!=NULL){
            temp=temp->next;
            ev++;
        }
        
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        if(ev%2 != 0){
            return count+1;
        }
        return count;
        
    }
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        int index = midPoint(head);
        if(head == NULL){
            return head;
        }
        if(index == 0){
            return NULL;
        }
         Node *prevNode = head;
        while(prevNode!=NULL && index !=1){
            prevNode = prevNode ->next;
            index--;
        }
        if(prevNode==NULL || prevNode->next==NULL){
            return head;
        }
        Node * temp = prevNode ->next;
        prevNode -> next = prevNode->next->next;
        delete temp;
        return head;
        
        
        
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends