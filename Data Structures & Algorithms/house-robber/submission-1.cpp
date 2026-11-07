class Solution {
public:
// int dp[101];
//     int solve(int i, vector<int> &nums)
//     {
//         if(i>=nums.size())
//         {
//             return 0;
//         }
//         if(dp[i]!=-1)
//         {
//             return dp[i];
//         }
//         int rob = nums[i] + solve(i+2,nums);
//         int skip = solve(i+1,nums);
//         return dp[i] = max(rob,skip);
//     }
//     int rob(vector<int>& nums) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,nums);
//     }
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
