//House Robber
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

#include<vector>
using namespace std;

// i cannot rob houses next to eachoter
//figure out, in the array, what set of every other house will give me the most money.

/*if i rob a house, next house I can rob is dp[i-2], thus the total money robbed would be nums[i] + dp[i-2], if I skip, then take dp[i-1]

the recurrence relation of dp[i] would be dp[i] = max(dp[i-1], nums[i] + dp[i-2])   ---- this determines the optimal solution to the subproblem, whether or not I skip the house or should I rob i
*/


class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {   
        //init dp vector to be the size of nums
        vector<int> dp(nums.size(), 0);

        //base case, if there is 1 house in nums
        if (nums.size() == 1)
        {
            return nums[0];
        }
        //if there are two houses in nums, return which house makes the most money
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]); //init dp[1] as the max cash you can rob from the first two houses

        //start at i = 2, because I already handled the first two elements of nums.
        for (int i = 2; i < dp.size(); i++)
        {
            
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
            
        }
        return dp[nums.size()-1];       

    }
};