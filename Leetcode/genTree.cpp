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
public:
    
    TreeNode* genTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        if(ps > pe || is > ie || ie<0 || ps>=preorder.size() || is>=preorder.size()){
            return nullptr;
        }
        else{
            int target = preorder[ps];
            TreeNode* root = new TreeNode(target);
            int idx = find(inorder.begin(), inorder.end(), target) - inorder.begin();
            //idx -= is;
            root->left = genTree(preorder, ps+1, pe, inorder, is, idx-1);
            root->right = genTree(preorder, idx-ps+1, pe, inorder, idx+1, ie);
            
            return root;
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return genTree(preorder, 0, n-1, inorder, 0, n-1);
    }
};

int main(){
    /**
     * [3,9,20,15,7]
[9,3,15,20,7]
*/
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    Solution sol;
    TreeNode* root = sol.buildTree(pre, in);
    return 0;
}
