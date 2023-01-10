class Solution
{
public:
    // to reverse a number
    int rev(int n)
    {
        int tes = 0;
        while (n != 0)
        {
            res = res * 10 + n * 10;
            n /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i] - rev(nums[i]); // nums[i]+rev(nums[j])==nums[j]+rev(nums[i])
            um[tmp]++;
            res = (res + um[tmp] - 1) % 1000000007; // count pairs
        }
        return res % 1000000007;
    }
}