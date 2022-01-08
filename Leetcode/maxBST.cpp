#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left, *right;
    TreeNode(): left(nullptr), right(nullptr), data(0){}
    TreeNode(int data): left(nullptr), right(nullptr), data(data){}
};

bool isBST(TreeNode* root, int min=INT_MIN, int max=INT_MAX){
    if(root == nullptr){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int TreeHeight(TreeNode* root){
    if(root == nullptr){
        return -1;
    }
    return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
}

TreeNode* maxBSTSubtree(TreeNode* root){
    if(root){
        if(isBST(root)){
            //if root is BST, this is also highest BST.
            return root;
        }
        // check if left or right child is BST, then return max height child
        int leftH = -1, rightH = -1;
        if(isBST(root->left)){
            leftH = TreeHeight(root->left);
        }
        if(isBST(root->right)){
            rightH = TreeHeight(root->right);
        }

        if(leftH != -1 || rightH != -1){

            if(leftH > rightH){
                return root->left;
            }
            return root->right;
        }
        else{
            //continue search for BST in subtree
            TreeNode *left = maxBSTSubtree(root->left), *right = maxBSTSubtree(root->right);
            if(left == nullptr && right == nullptr){
                //no BST found in subtrees
                return nullptr;
            }
            if(TreeHeight(left) > TreeHeight(right)){
                //return BST root with highest height
                return left;
            }
            else{
                return right;
            }
        }

    }
    return nullptr;
}

int main(){
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(22);
    root->right = new TreeNode(19);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(32);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(25);  

    root->right->left->right = new TreeNode(10);

    root->right->left->right->right = new TreeNode(12);

    TreeNode* ans = maxBSTSubtree(root);
    cout << ans->data << " " << TreeHeight(ans) << endl;

    tuple<bool, int, int, int> state = {false, 2, 12, 25};

    const bool ans = get<0>(state);
    
    return 0;
}