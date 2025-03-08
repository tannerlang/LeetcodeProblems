//Reverse Bits
/*Reverse bits of a given usigned integer*/

#include<cstdint>
using namespace std;

class Solution 
{
    public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;

        for (int i = 0; i < 32 ; i++)
        {
            int bit = n%2;  //gets lsb, the rightmost bit of n.
            result = result << 1;   //shifts result to the left by 1 to make space
            if (bit == 1)
            {
                result = result + 1;    //sets lsb of result to 1.
            }
            
            n>>=1;           //shift n to the right 1 and update n.
        }
        return result;
    }
};