class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int n = nums.size();
        long long number;
        long long windowSum = 0;
        long long increments = 0;
        long long ans = 0;

        for(int right = 0; right < n; right++){
            number = right - left + 1; //number of elements.
            windowSum += nums[right];
            increments = (number * nums[right]) - windowSum;

            while(increments > k){
                windowSum -= nums[left];
                left++;
                number = right - left + 1;
                increments = (number * nums[right]) - windowSum;

            }
            ans = max(ans,number);
            
        } 
        return ans;       
    }
};