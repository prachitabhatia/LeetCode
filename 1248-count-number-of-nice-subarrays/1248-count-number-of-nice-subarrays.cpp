class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int countOdd = 0;
        int countNice = 0;
        int left = 0;
        int copyLeft,tempOdd;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] % 2 != 0){
                countOdd ++;
            }

            while(countOdd > k){
                if(nums[left] % 2 != 0){
                    countOdd--;
                }
                left ++;
            }

            if(countOdd == k){
                copyLeft = left;
                while(nums[copyLeft] %2 == 0){
                    countNice++;
                    copyLeft++;
                }
                countNice++;
            }
            
        }
        return countNice;
        
    }
};