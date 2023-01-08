class Solution {
public:
   int evalRPN(vector<string>& tokens) {
       // copied but remember it espacially the function dec
        unordered_map<string, function<long long (long long, long long) > > map = {
            { "+" , [] (long long a, long long b) { return a + b; } },
            { "-" , [] (long long a, long long b) { return a - b; } },
            { "*" , [] (long long a, long long b) { return a * b; } },
            { "/" , [] (long long a, long long b) { return a / b; } }
        };
        std::stack<long long> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                long long op1 = stack.top();
                stack.pop();
                long long op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};
