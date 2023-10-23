// https://leetcode.com/submissions/detail/1082325522/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // No need to modify a list with 0 or 1 node.
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // Check if there are any even elements before connecting.
        
        odd->next = evenHead;
        

        return head;
    }
};
