class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        // Count frequency
        for(char t : tasks) {
            freq[t - 'A']++;
        }
        
        // Find max frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        
        // Count how many tasks have max frequency
        int maxCount = 0;
        for(int f : freq) {
            if(f == maxFreq) maxCount++;
        }
        
        // Apply formula
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        
        int minTime = partCount * partLength + maxCount;
        
        return max((int)tasks.size(), minTime);
    }
};