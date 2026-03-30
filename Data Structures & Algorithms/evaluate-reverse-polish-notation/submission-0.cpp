class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string a : tokens) {
            if(a == "+") {
                int b = st.top(); st.pop();
                int a1 = st.top(); st.pop();
                st.push(a1 + b);
            }
            else if(a == "-") {
                int b = st.top(); st.pop();
                int a1 = st.top(); st.pop();
                st.push(a1 - b);
            }
            else if(a == "*") {
                int b = st.top(); st.pop();
                int a1 = st.top(); st.pop();
                st.push(a1 * b);
            }
            else if(a == "/") {
                int b = st.top(); st.pop();
                int a1 = st.top(); st.pop();
                st.push(a1 / b);
            }
            else {
                st.push(stoi(a));
            }
        }

        return st.top();
    }
};