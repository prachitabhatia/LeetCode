class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int length;
        int minLen = INT_MAX;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(sum >= target){
                length = right - left + 1;
                minLen = min(length,minLen);
                sum -= nums[left];
                left++;
            }
        }

        if(minLen == INT_MAX){
            minLen = 0;
        }
        return minLen;
    }
};