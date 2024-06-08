#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;


        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }


        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }


        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete; 

        return dummy.next;
    }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


ListNode* createList(const int* values, int size) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int i = 0; i < size; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return dummy.next;
}

int main() {
    Solution solution;


    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    int n1 = 2;
    ListNode* result1 = solution.removeNthFromEnd(head1, n1);
    cout << "Output for head = [1,2,3,4,5], n = 2: ";
    printList(result1);


    int arr2[] = {1};
    ListNode* head2 = createList(arr2, 1);
    int n2 = 1;
    ListNode* result2 = solution.removeNthFromEnd(head2, n2);
    cout << "Output for head = [1], n = 1: ";
    printList(result2);


    int arr3[] = {1, 2};
    ListNode* head3 = createList(arr3, 2);
    int n3 = 1;
    ListNode* result3 = solution.removeNthFromEnd(head3, n3);
    cout << "Output for head = [1,2], n = 1: ";
    printList(result3);

    return 0;
}
