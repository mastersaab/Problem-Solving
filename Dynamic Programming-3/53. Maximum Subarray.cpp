class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];
        int currSum = nums[0];

        for(int i = 1; i<n; i++){
            if(currSum>0){
                currSum= currSum+nums[i];
            }
            else
                currSum = nums[i];
            
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};
