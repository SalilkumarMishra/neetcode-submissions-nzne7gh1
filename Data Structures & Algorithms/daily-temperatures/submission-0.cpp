class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result (n,0); //default 0
        stack<int> st; // Store indices
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prev = st.top();
                st.pop();
                result[prev] = i - prev;
            }
            st.push(i);
        }
        return result;
    }
};
