class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int,int> hash;
        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right ++){
            hash[nums[right]]++;
            while(hash.size() > k){
                hash[nums[left]]--;
                if(hash[nums[left]]==0){
                    hash.erase(nums[left]);
                }
                left++;
            }
            if(hash.size() <= k){
                count += right-left+1;
            }
            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};