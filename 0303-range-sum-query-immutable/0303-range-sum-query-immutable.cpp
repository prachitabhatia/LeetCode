class NumArray {
vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i==0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = nums[i] + prefix[i-1];
            }
        }
    }
    
    int sumRange(int left, int right) {
        int ans;
        if(left == 0){
            ans = prefix[right];
        }
        else{
            ans = prefix[right] - prefix[left-1];
        }
        return ans;
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */