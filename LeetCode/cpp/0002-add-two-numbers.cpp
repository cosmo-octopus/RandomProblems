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


//	Time and Space complexities O(max(n,m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;

        ListNode* head = new ListNode();
        ListNode* it = nullptr;
        ListNode* node = head;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            if (!node)
                node = new ListNode();

            int n = carry;
            carry = 0;

            if (l1)
            {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                n += l2->val;
                l2 = l2->next;
            }

            node->val = n % 10;
            if (n >= 10)
                carry = n / 10;

            if (it)
                it->next = node;
            it = node;
            node = node->next;
        }
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

    std::vector<int> num1 = {2, 4, 3}; // Represents the number 342
    std::vector<int> num2 = {5, 6, 4}; // Represents the number 465

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    printList(result); // Output should be 7 -> 0 -> 8

    return 0;
}
