#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)   
 {}
};

int countKSumPaths(TreeNode* root, int k) {
    vector<int> path;
    return countKSumPathsHelper(root, k, path);
}

int countKSumPathsHelper(TreeNode* root, int k, vector<int>& path) {
    int count = 0;

    if (!root) {
        return count;
    }

    path.push_back(root->val);

    // Check if the current path sums to k
    int currentSum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        currentSum += path[i];
        if (currentSum == k) {
            count++;
        }
    }

    // Recursively count paths in the left and right subtrees
    count += countKSumPathsHelper(root->left, k, path);
    count += countKSumPathsHelper(root->right, k, path);

    // Remove the current node from the path before returning
    path.pop_back();

    return count;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right   
 = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);   


    int k = 8;
    int count = countKSumPaths(root, k);
    cout << "Number of K-sum paths: " << count << endl;

    return 0;
}
