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
private:
    unordered_map<int,int> res;
public:
    TreeNode* MybuildTree(vector<int>& preorder,vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(preleft > preright) return NULL;
        int preIndex = preleft;
        int inIndex = res[preorder[preIndex]];
        TreeNode* root = new TreeNode(preorder[preIndex]);
        root->left = MybuildTree(preorder, inorder, preleft + 1, inIndex - inleft + preleft, inleft, inIndex - 1);
        root->right = MybuildTree(preorder, inorder, inIndex - inleft + preleft + 1, preright, inIndex + 1, inright);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            res[inorder[i]] = i;
        }
        return MybuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};