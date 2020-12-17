#solution BFS 8ms O(n) O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool level = true;
        while(!q.empty()){
            int n = q.size();
            deque<int> temp;
            for(int i = 0; i < n; ++i){
                root = q.front();
                q.pop();
                if(level)
                    temp.push_back(root->val);
                else
                    temp.push_front(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            res.push_back(vector<int>(temp.begin(), temp.end()));
            level = !level;
        }
        return res;
    } 
};