class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return;
        }

        int p1 = n-2;
        int p2 = n-1;

        while(p1 >= 0 && nums[p1] >= nums[p1+1] ){
            p1--;
        }

        if(p1 == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        while(p2 > p1){
            if(nums[p2] > nums[p1]){
                swap(nums[p2],nums[p1]);
                reverse(nums.begin() + p1 + 1, nums.end());
                break;
            }
            p2--;
        }

    }
};