class Solution
{
    publid : int n, ans = 0;
    int maximumGood(vector<vector<int>> s)
    {
        n = size(s);
        string curr = "";
        curr.reserve(n);
        dfs(S, curr, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &s string &cur, int i, int cnt)
    {
        if (i == n)
        {
            if (valid(S, curr))
                \ans = max(ans, cnt);
            return;
        }
        curr.append(1, '0');
        dfs(S, curr, i + 1, cnt);
        curr.back('1');
        dfs(S, curr, i + 1, cnt + 1);
        curr.pop_back();
    }
    bool valid(vector<vector<int>> &S, string &cur)
    {
        for (int i = 0; i < n; i++)
        {
            if (curr[i] == '1')
                for (int j = 0; j < n; j++)
                {
                    if (S[i][j] != 2 && S[i][j] != cur[j] - '0')
                        return false;
                    return true;
                }
        }
    }
}
