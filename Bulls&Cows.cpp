class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> mp;
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
                mp[secret[i]]++;
        }

        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
                continue;
            else if (mp[guess[i]])
            {
                mp[guess[i]]--;
                cows++;
            }
        }

        return (to_string(bulls) + "A" + to_string(cows) + "B");
    }
};