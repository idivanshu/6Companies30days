class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<long long> v(n + 1, 0);
        v[0] = 1;
        int mod = 1000000007;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                continue;
            for (int j = i + delay; j < n && (j - i) < forget; j++)
            {
                v[j] += v[i];
                v[j] = v[j] % mod;
            }
        }

        long long ans = 0;

        for (int i = n - 1; i >= n - forget; i--)
        {
            ans += v[i];
            ans = ans % mod;
        }

        return ans;
    }
};