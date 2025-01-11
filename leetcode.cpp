// LEETCODE PROBLEM 344


#include <vector>
class Solution {
public:
    void reverseString(vector<char>& s) {
        // in place algorithm-- iterate from 0 to middle. swap first and last in
        // each iteration and size down
        for (size_t i = 0; i < (s.size()/2) + 1; i++) {
            int calc = s.size() - i;
            swap(s[i], s[calc - 1]);
        }
    }
};



// LEETCODE 83

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head != NULL) {
        struct ListNode* curr = head;

        while (curr->next) {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }

        return head;
    }
    return NULL;
}
