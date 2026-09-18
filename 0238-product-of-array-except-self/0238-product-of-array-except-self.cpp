class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> product(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        //forming prefix array
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];         
        }

        //forming suffix array
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i + 1];
          }

        //product array = prefix array * suffix array
        for(int i = 0; i < n; i++){
            product[i] = prefix[i] * suffix[i];
        }

        return product;
    }
};