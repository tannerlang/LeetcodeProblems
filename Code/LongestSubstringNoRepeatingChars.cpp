//Longest Substring without repeating characters

//use the sliding window technique and a hashmap.
//track chars in the window with hashmap
    //expand the right, add char that the right pointer is pointing at if it isnt in the hashmap and increase the max length
    //if right pointer is in the set remove left pointers value and move left pointer forward until window is unique

#include<string>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLength = 0;
        int left = 0, right = 0;
        unordered_map<char,int> uniqueChars;

        while(right < s.size())
        {
            if (uniqueChars.find(s[right]) != uniqueChars.end())        //if the character is already in the window
            {
                left = max(left, uniqueChars[s[right]] + 1);            //moves the left pointer 1 past the duplicate char.
            }
            
            
            uniqueChars[s[right]] = right;                              //update the latest index into the map regardless if there is a duplicate or not.
            maxLength = max(maxLength, right - left + 1);               //update length;
            right++;
        }
        
        return maxLength;
    }
};