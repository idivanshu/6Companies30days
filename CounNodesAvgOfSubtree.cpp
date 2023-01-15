class Solution
{
public:
    int ans = 0;
    int sum(TreeNode *root, int &count)
    {
        // we are counting the nodes in tree
        if (root == NULL)
            return 0;
        count++;
        int left = sum(root->left, count);
        int right = sum(root->right, count);
        return (root->val + left + right);
    }
    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        int count = 0;
        int avg = (sum(root, count)) / count;
        if (avg == root->val)
            ans++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        solve(root);
        return ans;
    }
}