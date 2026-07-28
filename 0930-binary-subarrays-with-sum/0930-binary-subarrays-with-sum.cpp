class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0;
        int sum = 0;
        int needed;
        int count = 0;
        unordered_map<int,int> hash;
        
        hash[0] = 1;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            needed = sum - goal;

            if(hash[needed]){
                count += hash[needed];
            }
            hash[sum] ++; 

        }
        return count;
    }
};