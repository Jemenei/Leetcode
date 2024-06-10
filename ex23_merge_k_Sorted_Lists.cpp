class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
    return a -> val > b -> val;

    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }

        
    priority_queue<ListNode*, vector<ListNode*>, compare> minheap;
    for(int i = 0; i < lists.size(); i++){
        if(lists[i]!= NULL)
    minheap.push(lists[i]);
    }  
    
    ListNode* head = NULL;
    ListNode* temp1;
    while(!minheap.empty()){
    ListNode* temp = minheap.top();
   
    if(head == NULL){
    head = temp;
    temp1 = temp;
    } else {
    temp1->next=temp;
    temp1=temp;
    }

    minheap.pop();
    if(temp -> next != NULL) {
        minheap.push(temp -> next);
    }
    }

    if(temp1 != NULL)
    temp1 -> next = NULL;
    return head; 

    }
};