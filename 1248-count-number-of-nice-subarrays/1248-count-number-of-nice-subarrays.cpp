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

            copyLeft = left;
            tempOdd = countOdd;
            while(tempOdd == k && copyLeft <= right){
                countNice ++;
                if(nums[copyLeft] %2 != 0){
                    tempOdd--;
                }

                copyLeft ++;
            }
            
        }
        return countNice;
        
    }
};