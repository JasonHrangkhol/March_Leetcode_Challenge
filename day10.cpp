/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while(l1 && l2){
            
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            l1->val=sum%10;
            curr->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            curr=curr->next;
        }
        
        while(l1){
            
            int sum = l1->val+carry;
            carry = sum/10;
            l1->val = sum%10;
            curr->next = l1;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2){
            
            int sum = l2->val+carry;
            carry = sum/10;
            l2->val =sum%10;
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
       // cout<<carry<<endl;
        if(carry){
            ListNode *node = new ListNode(carry);
            curr->next = node;
        }
        return dummy->next;;
        
    }
};