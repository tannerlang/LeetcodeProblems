//Missing Number
/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/


//sort the array
//loop
    //if the index matches the value
        //continue
    //return index


#include<algorithm>
#include<vector>
using namespace std;


class Solution 
{
    public:
    int missingNumber(vector<int>& nums) 
    {
        int result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != nums[i])
            {
                result = i;
                break;
            }
        }
        return result;
    }
};