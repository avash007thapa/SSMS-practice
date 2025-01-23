// LEETCODE EASY PROBLEM 66- PLUS ONE

void sum_nine(vector<int>& dig, int pos) {
    if (pos >= 0) {
        if (dig[pos] == 9) {
            dig[pos] = 0;
            sum_nine(dig, pos - 1);  // Propagate the carry to the previous digit
        } else {
            dig[pos]++;  // Increment the digit and stop further propagation
        }
    } else {
        dig.insert(dig.begin(), 1);  // Handle carry overflow at the most significant position
    }
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if (digits[n - 1] == 9) {
            sum_nine(digits, n - 1);
        } else {
            digits[n - 1]++;
        }

        return digits;
    }
};

// LEETCODE MEDIUM PROBLEM 443- STRING COMPRESSION
void print_container(vector<char>& c) {
    for (char ch : c)
        cout << ch;
    cout << '\n';
}

// CREDITS to solution from Hemalatha M

class Solution {
public:
    int compress(vector<char>& c) {
        int n = c.size();
        if (n == 0) return 0;

        int w = 0, r = 0; // w is for, and r is index for current letter
        while (r < n) {
            char x = c[r]; // find duplicates of x
            int count = 0; // no. of duplicates found

            while (r < n && c[r] == x) {
                r++; 
                count++; 
            }

            c[w++] = x; // rewrite first letter in c with x
            // rewrite the number if count is more than 1 
            if (count > 1) { 
                for (char d : to_string(count)) {
                    c[w++] = d;
                }
            }
        }
        return w;
    }
};

// LEETCODE PROBLEM 605
// IN COLLABORATION WITH Rajnesh Joshi

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    // Count number of zeroes

    int tempflowerbed[flowerbedSize + 2];
    int tempflowerbedSize = flowerbedSize + 2;

    for (int i = 0; i < flowerbedSize + 2; i++) {
        if (i == 0 || i == flowerbedSize + 1) {
            tempflowerbed[i] = 0;
            continue;
        }

        tempflowerbed[i] = flowerbed[i-1];
    }


    int i = 1;
    while(i < tempflowerbedSize - 1 && n > 0) {
    
        if (tempflowerbed[i] == 1) {
            i++;
            continue;
        }

        else {
            if (tempflowerbed[i-1] || tempflowerbed[i+1]) {
                i++;
                continue;
            } else {
                tempflowerbed[i] = 1;
                i+=2;
                n--;
            }
        }
    }

    if (!n)
        return true;
    else
        return false;
}

// LEETCODE PROBLEM 58


class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 1)
            return 1;
        
        int strlen = s.length();

        cout << strlen;

        int wordLength = 0;
        
        while (strlen != 0) {
            if (isalnum(s[strlen-1])) {
                wordLength++;
                strlen--;
                continue;
            } else {
                if (wordLength > 0)
                    break;
                strlen--;
                continue;
            }
        }

        return wordLength;
    }
};

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
