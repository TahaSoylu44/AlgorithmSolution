#include <iostream>
#include <vector>
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

void bfs(TreeNode* root, vector<vector<int>>& array)
{
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    bool seenNull = false;

    vector<int> v;

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if (node) v.push_back(node->val);
        else seenNull = true;
        
        if (q.empty() && seenNull)
        {
            array.push_back(v);
            v.clear();
            seenNull = false;
        }

        q.push(node->left);
        q.push(node->right);
    }
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> array;
    bfs(root, array);
    return array;
}

int main() {
    
    return 0;
}