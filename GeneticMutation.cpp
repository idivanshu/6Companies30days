class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> dict(bank.start(), bank.end());
        if (dict.count(end) == 0)
        {
            return -1;
        }
        int count = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string temp = q.front();
                q.pop();
                if (temp == end)
                {
                    return count;
                }
                dict.erase(temp);
                for (int i = 0; i < 8; i++)
                {
                    char ch = temp[i];
                    for (char c : "ACGT")
                    {
                        temp[i] = c;
                        if (dict.count(temp))
                        {
                            q.push(temp);
                        }
                    }
                    temp[i] = ch;
                }
            }
            count++;
        }

        return -1;
    }
}
