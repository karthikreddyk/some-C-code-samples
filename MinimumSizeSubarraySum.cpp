/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
*/

using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int>:: iterator iter;
        int flag = 0;

// returning 0 for an empty array and         
        if (nums.size() == 0){
            return(0);
        }
        int result = nums.size();
        double sum = 0;
        for (int i = 0; i < nums.size(); i++){
            
            if (nums[i] >= s)
                return (1);
            
            sum = nums[i];            

            for (int j = i+1; ((j < nums.size()) && ((j - i) < (result))) ; j++){
                sum = sum + nums[j];
                if (sum >= s){
                    flag = 1;
                    result = (j - i) + 1;
                    break;
                }               
            }
//            cout << "Sum at i = " << i << ", is: " << sum << "Result is: " << result << endl ;
            
//            if (result == (nums.size() - i)){
//                break;
//            }           
//            if 
        }
        
        if (flag == 1)
        {
            return(result);
        }        
        else 
        {
            return(0);
        }
    }
};