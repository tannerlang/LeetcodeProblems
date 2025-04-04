//Best Time to buy and sell stock

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/




#include<vector>


using namespace std;





class Solution
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);      
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
        
    };
};

