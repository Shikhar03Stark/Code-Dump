#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public : 

    TreeNode* rightMost(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    if (root->right)
        return rightMost(root->right);
    else
        return root;
}
    
    void flatten(TreeNode* root) {
        if(root){
            if(root->left){
                TreeNode* r = root->right;
                root->right = root->left;
                root->left = nullptr;
                if (root->right){
                    flatten(root->right);
                    TreeNode* rMost = rightMost(root->right);
                    rMost->right = r;   
                }
            }
        }
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    sol.flatten(root);
    return 0;
}
