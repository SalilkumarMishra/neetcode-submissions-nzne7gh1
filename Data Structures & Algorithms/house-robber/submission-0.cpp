class Solution {
public:
        int rob(vector<int>& nums)
    {
        int next1 = 0;
        int next2 = 0;
        for(int i=nums.size()-1;i >= 0;i--)
        {
            int current = max(nums[i]+next2, next1);
            next2 = next1;
            next1 = current;
        } 
        return next1;  
}
};
