//Contains Duplicate

/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/


//create hashmap to track frequency of elements in nums
//traverse map, first appearance of frequency value > 1, return true
//false if nothing.

#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) 
        {
            unordered_map<int,int> count;
            for (int i = 0; i < nums.size(); i++)   //O(n)
            {
                count[nums[i]]++;   //increments frequency val for that key.
            }

            for (auto it = count.begin(); it != count.end(); it++)      //O(n)
            {
                if (it->second > 1)
                {
                    return true;
                }
            }
            return false;
        }
    };                                      //time complexity = O(n)



#include<unordered_set>
    //set method, slightly faster

    //loop through nums
        //check if set already has this number
            //return true
    
        //insert current element into set
    //return false

class Solution 
{
    public:
        bool containsDuplicate(vector<int>& nums) 
        {
            unordered_set<int> seen;

            for(int i = 0; i < nums.size(); i++)
            {
                if (seen.count(nums[i]))    //if it already exists in the set
                {
                    return true;   
                }
                seen.insert(nums[i]);
            }
            return false;
        }
};     