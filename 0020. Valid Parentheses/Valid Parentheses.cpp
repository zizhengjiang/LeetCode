class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (auto ch : s) {
            if (ch == '(') st.push(')');
            else if (ch == '[') st.push(']');
            else if (ch == '{') st.push('}');
            else {
                if (ch != ')' && ch != ']' && ch != '}') continue;
                else if (st.empty() || st.top() != ch) return false;
                else st.pop();
            }
        }
        
        return st.empty();
    }
};