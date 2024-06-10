
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = NULL, *curr = head, *start = head;
        int count = 0, totalcount = 0;
        
        ListNode *dummy = new ListNode(0);
        ListNode *end = dummy; 
        
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        while(curr != nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
            totalcount++; 
            
            if(count == k)
            {
                count = 0; 
                end->next = prev; 
                end = start;
                start->next = curr; 
                start = curr;
                prev = NULL;
                
                if(n - totalcount < k) break;
            }
        }        
        return dummy->next;
    }
};