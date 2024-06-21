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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
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

    std::vector<int> num = {1,2,3,4};

    ListNode* l = createList(num);

    ListNode* result = solution.swapPairs(l);
    printList(result);

    return 0;
}