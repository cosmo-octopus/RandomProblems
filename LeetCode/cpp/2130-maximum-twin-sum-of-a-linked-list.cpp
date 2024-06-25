#include <iostream>
#include <vector>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* node);

/********************************************* WORKS JUST RIGHT */
class Solution {
public:
    ListNode* reverse_list(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    int pairSum(ListNode* head) {

		// Palindrome type question 
        // find middle (1st middle node)
        // reverse after middle node
        // sum node of both half and find max

		// edge cases
		if (!head)
			return 0;
		if (!head->next->next)
			return head->val + head->next->val;

		int sum = 0;

		// find the middle
		ListNode *s = head, *f = head->next;

		while (f)
		{
			f = f->next;
			if (f)
			{
				f = f->next;
				s = s->next;
			}
		}

		ListNode* reversed = reverse_list(s);

		while (head)
		{
			sum = std::max(sum, head->val + reversed->val);
			head = head->next;
			reversed = reversed->next;
		}

        return sum;
    }
};

/****************************************** FASTEST
class Solution {
public:
    int pairSum(ListNode* head) {
        int sum = 0;
        std::vector<int> vec;

        while (head)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        int size = vec.size();

        for (int i = 0; i < size / 2; ++i)
            sum = std::max(sum, vec[i] + vec[size - i - 1]);

        return sum;
    }
};
*/

/************************************ TIMEOUT
class Solution {
public:
    int pairSum(ListNode* head) {
        int sum = 0;
        int size = 0;

        ListNode* it = head;
        while (it)
        {
            if (!it->next)
                sum = head->val + it->val;
            size ++;
            it = it->next;
        }

        if (size == 2)
            return sum;

        it = head->next;
        int step = 1;
        while (step < size / 2)
        {
            ListNode* iter = it;
            for (int n = step; n < size - step - 1; ++n)
                iter = iter->next;
			std::cout << it->val << " + " << iter->val << std::endl;
            if (it->val + iter->val > sum)
                sum = it->val + iter->val;
            step ++;
            it = it->next;
        }

        return sum;
    }
};
*/

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

    // std::vector<int> num = {47,22,81,46,94,95,90,22,55,91,6,83,49,65,10,32,41,26,83,99,14,85,42,99,89,69,30,92,32,74,9,81,5,9};
    std::vector<int> num = {79,90,23,26,68,5};

    ListNode* l = createList(num);

	// ListNode* rev = solution.reverse_list(l);
	// printList(rev);

    std::cout << solution.pairSum(l) << std::endl;

    return 0;
}