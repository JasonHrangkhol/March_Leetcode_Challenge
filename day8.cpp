/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* temp = new ListNode();
        
        ListNode* curr = head;
        
        while(curr){
            
            if(curr->next == temp)
                return true;
            
            ListNode* next_ptr = curr->next;
            curr->next = temp;
            curr = next_ptr;
        }
        
        return false;
    }
};