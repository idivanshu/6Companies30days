class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k--;
        while (k)
        {
            int steps = calcNodes(n, curr, curr + 1);
            if (steps <= k)
            {
                // we should go to next subtree cz we count all the nodes in this subtree
                k -= steps;
                curr++;
            }
            else
            {
                // in that subtree
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
    int calcNodes(long long max, long long n1, long long n2)
    {
        int res = 0;
        // counting the nodes
        while (n1 <= max)
        {
            res += min(max + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return res;
    }
};