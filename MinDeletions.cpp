class Solution
{
public:
    // divides all the elements of numsDivide equals to divides gcd of all the elements of numsDivide where gcd is the greatest common divisor.So the first step, we have to find the gcd of numsDivide, then sort input nums ,and find out the smallest element nums[i] in nums divides gcd.We need to remove all elements smaller than nums[i].If no such nums[i], return -1

    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {

        int g = numsDivide[0];
        for (int a : numsDivide)
            g = gcd(g, a);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] <= g; i++)
            if (g % nums[i] == 0)
                return i;
        return -1;
    }
};
