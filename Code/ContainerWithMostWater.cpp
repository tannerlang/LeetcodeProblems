//Container With Most Water

/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store. */



//will use the two pointer technique


//left = 0 and right = height.size()-1 starting at each end of the vector
//maxArea = 0;
//while(left<right)
    //set width = right-left
    //set area = min(height[left], height[right]) * width
    //maxArea = max(area, maxArea)
    //if height[left] < height[right]
        //left++;
    //else
        //right--


#include<vector>
using namespace std;

class Solution
{
    public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1 ;   //height.size()-1 because vector is 0 based, last index is always n-1 where n is number of elements in the vector.
        
        int maxArea = 0;

        while (left < right)        //until the pointers cross              O(n)
        {
            int width = right-left;
            int area = min(height[left],height[right]) * width;     //in this case, the area is determined by the smaller of the two heights, otherwise water will overflow.
            maxArea = max(area, maxArea);
            if (height[left] < height[right])                       //move the smaller of the heights inwards.
            {
                left++;
            }
            else
            {
                right--;
            }
        }                                                              //all ops within the whileloop are O(1)
        return maxArea;
    }                                                                   //Total Time Complexity = O(n)
};