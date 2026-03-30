class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        
        for (string s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        
        while (i < s.size()) {
            // find '#'
            int j = i;
            while (s[j] != '#') j++;
            
            // length of string
            int len = stoi(s.substr(i, j - i));
            
            // move to actual string
            j++;  
            
            // extract string
            string word = s.substr(j, len);
            res.push_back(word);
            
            // move pointer
            i = j + len;
        }
        
        return res;
    }
};