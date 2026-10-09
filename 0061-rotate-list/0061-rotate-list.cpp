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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== NULL) return NULL;
        ListNode* tail= head;
        ListNode* temp= head;
        int len=1;
        while(tail->next != NULL){
            len++;
            tail= tail->next;
        }
        k= k % len;
        if(k==0)  return head;
        tail->next= head;
        int cnt= len-k;
        for(int i=1; i< cnt; i++){
            temp= temp->next;
        }
        
        ListNode* newHead= temp->next;
        temp->next= NULL;
        head= newHead;
    
        
        

        return head;
    }
};