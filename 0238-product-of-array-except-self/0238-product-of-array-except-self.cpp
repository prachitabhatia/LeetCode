class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> product(n);

        //forming prefix array
        for(int i = 0; i < n; i++){
            if(i == 0){
                prefix[i] = 1;
            }

            else if(i > 0){
                prefix[i] = nums[i-1] * prefix[i-1];
            }            
        }

         //forming suffix array
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                suffix[i] = 1;
            }

            else{
                suffix[i] = suffix[i + 1] * nums[i + 1];
            }            
        }

        //product array = prefix array * suffix array

        for(int i = 0; i < n; i++){
            product[i] = prefix[i] * suffix[i];
        }

        return product;
    }
};