#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <unordered_map>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    Solution();
    ~Solution();
    std::vector<std::string> findRepeatedDnaSequences(std::string s);
    std::vector<std::vector<int> > generate(int numRows);
    int compareVersion(std::string version1, std::string version2);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    bool isPalindrome(std::string s);
    bool isPalindrome_2(std::string s);
    bool isPalindrome_3(std::string s);
    std::vector<int> getRow(int rowIndex);
    bool hasPathSum(TreeNode *root, int sum);

public:
    long double combination(int InputA, int InputB);
};

#endif // SOLUTION_H
