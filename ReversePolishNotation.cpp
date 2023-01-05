class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {

        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*")
            {
                s.push(stoi(tokens[i]));
                continue;
            }
            else
            {
                long long ftop = s.top();
                s.pop();
                long long stop = s.top();
                s.pop();
                if (tokens[i] == "+")

                    s.push(stop + ftop);

                else if (tokens[i] == "-")

                    s.push(stop - ftop);

                else if (tokens[i] == "*")

                    s.push(stop * ftop);

                else

                    s.push(stop / ftop);
            }
        }
        return s.top();
    }
};