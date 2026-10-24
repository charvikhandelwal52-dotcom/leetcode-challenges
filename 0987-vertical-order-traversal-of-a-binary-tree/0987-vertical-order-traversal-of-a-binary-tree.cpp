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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push({root, {0,0}});

        while( !q.empty()){
            auto temp= q.front();
            q.pop();

            TreeNode* node= temp.first;
            int col= temp.second.first;
            int row= temp.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)  q.push({node->left, {col-1, row+1}});
            if(node->right) q.push({node->right, {col+1, row+1}});
        }

        
        for(auto p: nodes){
            vector<int> col;
            for(auto row: p.second){
                for(int value : row.second){
                    col.push_back(value);
                }
            }
            ans.push_back(col);
        }
        return ans;

    }
};