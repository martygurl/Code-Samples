#include <iostream>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


bool isLeaf(TreeNode * root)
{
    return (root->left == NULL && root->right == NULL);
}

void findLeafs(TreeNode * root, vector<int> * ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans->push_back(root->val);
    }
    else if(root->right == NULL)
    {
        findLeafs(root->left, ans);
    }
    else if(root->left == NULL)
    {
        findLeafs(root->right, ans);
    }
    else
    {
        findLeafs(root->left, ans);
        findLeafs(root->right, ans);
    }
}


vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    // finding the left boundary 
    // we stop the search right before a leaf node 
    // leaf nodes will be counted by the findLeaf function
    TreeNode * temp = root;
    while(temp != NULL)
    {
        if (!isLeaf(temp))
        {
            ans.push_back(temp->val);
        }
        
        // the root is the left boundary case;
        if (root->left == NULL){
            break;
        }
        
        if(temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    // now find the leafs;
    findLeafs(root, &ans);

    // now do the right boundary, BUT! we have to print in order starting with the leafs
    // first create a list to store all the nodes in order that we traverse
    

    // now find all the right boundry in the order we traverse
    temp = (root->right);
    int i = 0;
    while(temp != NULL)
    {
        if (!isLeaf(temp))
        {
            if (i == 0)
            {
                ans.push_back(temp->val);
            }
            else
            {
                ans.insert(ans.end()-i, temp->val); 
            }
            ++i;
        }
        
        // the root is the right boundary case;
        if (root->right == NULL){
            break;
        }
        
        if(temp->right != NULL)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    // now we use a simple for-loop to push the data in rightBound in reverse order to ans
    return ans;
}
