/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> allPaths;
        solve(root, targetSum, path, allPaths);
        return allPaths;
    }

    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& allPaths){
        if(!root) return;
        path.push_back(root->val);
        targetSum -= root->val;

        if(!root->left && !root->right){
            if(targetSum == 0) allPaths.push_back(path);
        }
        else{
            solve(root->left, targetSum, path, allPaths);
            solve(root->right, targetSum, path, allPaths);
        }
        path.pop_back();
    }
};