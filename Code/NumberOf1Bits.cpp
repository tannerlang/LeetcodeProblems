//Number of 1 Bits
/*Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).*/

#include<vector>
using namespace std;

class Solution 
{
    public:
    int hammingWeight(int n) 
    {
        int quotient = n / 2;   
        int remainder = n % 2;
        int setBit = 0;

        //base case 
        if (n == 0)
        {
            return setBit;
        }
        
        if (remainder != 0)
        {
            setBit++;       //increments the setBit number if the remainder is 1
        }
       if (quotient != 0)
       {
            setBit += hammingWeight(quotient);  //accumulate setBits recursively
       }
       
        return setBit;
    }
};