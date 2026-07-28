class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        int left = 0;
        int sum = 0;
        int subArrayCount = 0;

        if(goal < 0){
            return 0;
        }

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(goal < sum){
                sum -= nums[left];
                left++;
            }
            subArrayCount += (right - left + 1);
        }
        return subArrayCount;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums,goal) - atMost(nums,goal-1);
    }
};