#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* getRoot(vector<int>& nums, int i ,int k)
{
    return new TreeNode(nums[(i + k) / 2]);
}


TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int start = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[start]);
    TreeNode* leftChild = getRoot(nums, 0, start);
    TreeNode* rightChild = getRoot(nums, start, nums.size());

    root->left = leftChild;;
    root->right = rightChild;

    
}

int main() {

    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);

    node1->left = node2;
    node1->right = node4;
    node2->right = node3;

    return 0;
}