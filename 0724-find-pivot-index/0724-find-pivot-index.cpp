class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftPrefix(nums.size());
        vector<int> rightPrefix(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i==0){
                leftPrefix[i] = nums[i];
            }
            else{
                leftPrefix[i] = nums[i] + leftPrefix[i-1];
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                rightPrefix[i] = nums[nums.size() - 1];
            }
            else{
                rightPrefix[i] = nums[i] + rightPrefix[i+1];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(leftPrefix[i] == rightPrefix[i]){
                return i;
            }
        }
        return -1;
    }
};