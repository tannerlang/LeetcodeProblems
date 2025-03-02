//TwoSum
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */


//simple method is a nested forloop O(n^2)
    //first forloop holds holds an index i of the vector
        //inner iterates through the indicies of the vector starting at j = i+1 
            //check if i + j = target
            //return the indicies of i and j as a vector.


#include<vector>
#include<unordered_map>     //hash table

class Solution
{
    public:

    std::vector<int> twoSum_simpleSolution(std::vector<int>& nums, int target)
    {
        std::vector<int>result; //will store the indicies of the two numbers that add to targe

        for (int i = 0; i < nums.size(); i++)                       
        {   
           for (int j = i+1; j < nums.size(); j++)                  //nested loop going through entire vector: O(n^2)
           {
                if (nums[i] + nums[j] == target)
                {
                    //store the indicies i and j in result.
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
                else
                {
                    continue;
                }                                                   //32 to 42 constant time
           }
           
        }
       return result; 
    }                                                               //Time complexity = O(n^2)


    //I should use a hashmap to make this more efficient.
    std::vector<int> twoSum_hashMapSolution(std::vector<int>& nums, int target)
    {
        std::vector<int>result;
        std::unordered_map<int,int> numHash;

        //iterate through nums add the current index to the hashmap and check if you can find the target with numbers stored in the hashMap
        for (int i = 0; i < nums.size(); i++)                      //O(n)
        {
            int complement = target - nums[i];  //find what value would get sum to target with nums[i]   O(1)

            if (numHash.find(complement) != numHash.end())  //if complement exists in the hashmap       O(1)
            {
                result.push_back(numHash.at(complement));   //stores the index of complement in result
                result.push_back(i);    //stores the index i in result

                return result;
            }                                                   //O(1)
            else
            {
                numHash[nums[i]] = i;   //otherwise inserts nums current index value into the hashmap
            }                                                   //O(1)
            
        }
        return {};
    }                                       //Time Complexity = O(n)

};




