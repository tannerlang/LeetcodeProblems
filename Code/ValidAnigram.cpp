//Valid Anigram

/*Given two strings s and t, return true if t is an anagram and false otherwise.
(An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once*/


#include <string>
using namespace std;
#include<unordered_map>


//use a hash table and store each character of one string and its frequency, then iterate through the second string and find each character in the hashtable and decrement
//its frequency. In the end return true if all frequencys in the hash table are 0, false otherwise.
class Solution
{
    public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> charCount; //key value relationship here is character and its frequency

        //add each character of s to wordCheck
        for (int i = 0; i < s.size(); i++)              //O(n)
        {
            charCount[s[i]]++;      //increases the frequency value of the specific character
        }
        
        for (int j = 0; j < t.size(); j++)              //O(n)
        {
            charCount[t[j]]--;      //decrement its frequency
        }

        //iterate through the hashmap and determine if any frequency is != 0
        for (auto k : charCount)                        //O(n)
        {
            if(k.second != 0)
            {
                return false;
            }
        }

        return true;
    }                                                //Total Time Complexity = O(n)

};