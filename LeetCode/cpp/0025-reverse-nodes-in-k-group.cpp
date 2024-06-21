#include <iostream>
#include <cmath>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* node);

class Solution {
public:
    ListNode* get_kth(ListNode* node, int k) {
        while (node && k--)
            node = node->next;
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* groupPrev = dummy;
        ListNode* groupLast;
        ListNode* curr;
        ListNode* prev;
        ListNode* tmp;

        while (1)
        {
            groupLast = get_kth(groupPrev, k);
            if (!groupLast)
                break ;
            ListNode* groupNext = groupLast->next;
            curr = groupPrev->next;
            prev = groupLast->next;

            while (curr != groupNext)
            {
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            tmp = groupPrev->next;
            groupPrev->next = groupLast;
            groupPrev = tmp;
        }
        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};

// Helper function to print the list (for debugging)
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

// Helper function to create a list from vector (for testing)
ListNode* createList(std::vector<int>& nums) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummyHead->next;
}

// Main function to test the solution
int main() {
    Solution solution;

    std::vector<int> num = {1,2,3,4,5};

    ListNode* l = createList(num);

    ListNode* result = solution.reverseKGroup(l, 2);
    printList(result);

    return 0;
}