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

    ListNode* reverseLL(ListNode* head){
        ListNode* temp= head;
        ListNode* prev= NULL;
        while(temp != NULL){
            ListNode* front= temp->next;
            temp->next= prev;
            prev= temp;
            temp= front;
        }
        return prev;
    }

    ListNode* getKNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k> 0){
            k--;
            temp= temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        ListNode* prevLast= NULL;
        while(temp != NULL){
            ListNode* kNode= getKNode(temp,k);
            if(kNode == NULL){
                if(prevLast != NULL) prevLast->next= temp;
                break;
            }
        
            ListNode*  nextNode= kNode->next;
            kNode->next= NULL;
            reverseLL(temp);
            if(temp == head){
                head= kNode;
            }
            else prevLast->next= kNode;
            prevLast= temp;
            temp= nextNode;
        }
        return head;
    }
};