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
 #soulution1 递归 O(n) O(n)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec){
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};

#soulution2 迭代 O(n) O(n)
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& vec){
        if(!root) return;
        stack<TreeNode*> nstack;
        while(!nstack.empty() || root){
            if(root){
                nstack.push(root);
                root = root->left;
            }
            else{
                root = nstack.top();
                vec.push_back(root->val);
                nstack.pop();
                root = root->right;           
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
};