class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int countZeroes = 0;
        int length;
        int maxLength = 0;
        
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                countZeroes ++;
            }

            while(countZeroes > k){
                if(nums[left] == 0){
                    countZeroes --;
                }
                left ++;
            }

            length = right - left + 1;
            maxLength = max(maxLength , length);   
        }
        return maxLength;
    }
};