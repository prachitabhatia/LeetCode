class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hash;
        int prefixSum = 0;
        int length = 0;
        int maxLength = 0;
        hash[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(hash.find(prefixSum) != hash.end()){
                length = i - hash[prefixSum];
                maxLength = max(length, maxLength);
           }
           else{
                hash[prefixSum] = i;
           }
        }
        return maxLength;
    }
};