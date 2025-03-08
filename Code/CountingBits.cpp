//Counting Bits

/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

/*Math Needed: Binary Conversion by Repeated Division
EX: 19
19/2 = 9, Rem:1
9/2 = 4,  Rem:1
4/2 = 2,  Rem:0
2/2 = 1,  Rem:0
1/2 = 0   Rem:1
Ans = 10011*/


/*Counting Bits EX: n = 5
ans.size() = 6
0->0
1->1
2->10
3->11
4->100
5->101

ans{0,1,1,2,1,3}        //number of 1's per ans[i]
*/

//Use DP
//Process
//base case is that ans[0] is always 0
//loop through dp
    //determin if i is even or odd
        //perform dp subproblem
//return dp


#include<vector>
using namespace std;

class Solution 
{
    public:
    vector<int> countBits(int n) 
    {
        vector<int> dp(n+1,0);

        //base case, i=0 has no 1's
        dp[0] = 0;

        for (int i = 0; i < dp.size(); i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = dp[i/2];    //# of 1s will be the same as dp[i/2]
            }
            if (i % 2 != 0)
            {
                dp[i] = dp[i-1] + 1;    //
            }
        }
        return dp;
    }
};