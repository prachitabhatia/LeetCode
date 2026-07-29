class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < n; i++){
            totalSum += cardPoints[i];
        }
        int sums = 0;
        int minSum = INT_MAX;

        //finding subarray with minimum sum and n-k elements.

        int left = 0;
        int right = n-k;

        for(int j = 0; j < right; j++){
            sums += cardPoints[j];
        }
        minSum = min(minSum,sums);

        for(int l = right; l < n; l++){
            sums += cardPoints[right];
            sums -= cardPoints[left];
            left++;
            right++;
            minSum = min(minSum, sums);
        }
        return totalSum - minSum;
    }
};