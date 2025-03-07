//Climbing Stairs DYNAMIC PROGRAMMING

/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/


#include<vector>
using namespace std;


//thought process: tabulation
//how many variations of ways can you make it to the top of the stairs by climbing either 1 or two steps

    //dp[i] num of ways to reach the top
    //dp[i-1] to take 1 step
    //dp[i-2] to take 2 steps

class Solution 
{
    public:
    int climbStairs(int n) 
    {
        vector<int> dp(max(n+1,3),0);  //inits vector of n+1 elements, ensures vector has a size of at least 3 to prevent out of bounds access if n=1 and I try to set dp[2] = 2 for the base case.
        //base cases

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];  //the number of ways to reach i is the sum of ways to reach i-1 and i-2
        }
        return dp[n];
    }
};