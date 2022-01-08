#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

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

        int calcMax(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        
        int ans = 0;
        
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,0});
        while(!Q.empty()){
            int size = Q.size();
            if(size == 1){
                ans = max(ans, 1);
                auto p = Q.front();
                Q.pop();
                if(p.first->left)
                    Q.push({p.first->left, 2*p.second});
                if(p.first->right)
                    Q.push({p.first->right, 2*p.second+1});
            }
            else{
                auto left = Q.front();
                //Q.pop();
                pair<TreeNode*, int> right;
                for(int i = 0; i<size; i++){
                    right = Q.front();
                    Q.pop();
                    if(right.first->left)
                        Q.push({right.first->left, 2*right.second});
                    if(right.first->right)
                        Q.push({right.first->right, 2*right.second+1});
                }
                
                ans = max(ans, right.second - left.second);
            }
        }
        
        return ans;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        return calcMax(root);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);
    Solution sol;
    cout << sol.widthOfBinaryTree(root) << endl;
    return 0;
}