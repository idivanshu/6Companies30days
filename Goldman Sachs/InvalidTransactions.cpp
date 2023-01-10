// Class for access of all properties of each transaction.
class Info
{
public:
    string name;
    int time;
    int amount;
    string city;
    int id;

    Info(string name, int time, int amount, string city, int id)
    {
        this->name = name;
        this->time = time;
        this->amount = amount;
        this->city = city;
        this->id = id;
    }
};

class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        int n = transactions.size();
        // To store Info* corresponds to name.
        unordered_map<string, vector<Info *>> record;
        // To store transaction id's of each invalid transaction.
        unordered_set<int> invalid;

        for (int i = 0; i < n; i++)
        {
            // stringstream allows us to iterate string as an object.
            stringstream s(transactions[i]);
            string str;

            getline(s, str, ',');
            string name = str;
            getline(s, str, ',');
            int time = stoi(str);
            getline(s, str, ',');
            int amount = stoi(str);
            getline(s, str, ',');
            string city = str;

            Info *info = new Info(name, time, amount, city, i);

            if (amount > 1000)
            {
                invalid.insert(i);
            }

            record[name].push_back(info);
        }

        for (auto &it : record)
        {
            vector<Info *> v = it.second;

            // Comparing city and time property of each transaction of same name.
            for (int i = 0; i < v.size(); i++)
            {
                string city1 = v[i]->city;
                int time1 = v[i]->time;

                for (int j = i + 1; j < v.size(); j++)
                {
                    string city2 = v[j]->city;
                    int time2 = v[j]->time;

                    // If invalid then both are invalid transactions.
                    if (abs(time1 - time2) <= 60 && city1 != city2)
                    {
                        invalid.insert(v[i]->id);
                        invalid.insert(v[j]->id);
                    }
                }
            }
        }

        vector<string> ans;
        // Storing id's of invalid transaction helped us here. Since we want transactions in string form.
        for (auto it = invalid.begin(); it != invalid.end(); it++)
        {
            int idx = *it;
            ans.push_back(transactions[idx]);
        }

        return ans;
    }
};
// TC = O(c*n*n)  c->total different names, n-> size of vector contains all transactions of same name.
// SC = O(map) + O(set).