class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0;
        unordered_map<int,int> hash;
        long long rem;
        bool goodSubarray = false;
        hash[0] = -1; //if the first two elements itself satisfy the condition then remainder = 0 needs to exist and since we are storing the value as index of the remainder, we can set the index of 0 as -1.

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            
            rem = ((prefixSum % k) + k) % k;
            if (hash.find(rem) != hash.end()){
                if(i - hash[rem] >= 2){
                    goodSubarray = true;
                    break;
                }
            }
            else{
                hash[rem] = i;
            }
        }
        return goodSubarray;
    }
};