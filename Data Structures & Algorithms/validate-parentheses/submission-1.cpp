class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(c == '[' || c == '{' || c == '(')
                st.push(c);
            else
            {
                if(st.empty())
                    return false;
                    
                char t = st.top();
                if(t == '[' && c != ']')
                    return false;
                else if(t == '{' && c != '}')
                    return false;
                else if(t == '(' && c != ')')
                    return false;
                else
                    st.pop();
            }
        }

        return st.empty();
    }
};
