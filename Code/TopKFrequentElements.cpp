//Top K Frequent Elements
/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/


#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;

        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for (auto it : freq)
        {
            pq.push(make_pair(it.second, it.first));    //puts all freq pairrs into the maxheap, frequency is first for max heap ordering.
        }

        for (int j = 0; j<k; j++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};