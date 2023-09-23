// Approach
// Use stack data structure
// pop two values whenever an operator comes
// and after applying operation insert its result

class Solution {
public:
    bool arith(string op) {
        if (op == "+" || op == "-" || op == "*" || op == "/")
            return 1;
        return 0;
    }
    
    string solve(int a, int b, string op) {
        if (op == "-")
            return to_string(b - a);
        if (op == "+")
            return to_string(a + b);
        if (op == "*")
            return to_string(a * b);
        if (op == "/")
            return to_string(b / a);
        return "";
    }
    
    int evalRPN(vector<string>& tokens) {
        int n = (int)(tokens.size());
        stack<string> st;
        for (int i = 0; i < n; i++) {
            if (arith(tokens[i])) {
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                int a = stoi(n1), b = stoi(n2);
                st.push(solve(a, b, tokens[i]));
            }
            else {
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};