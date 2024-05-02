int robbing(vector<int>&nums,int index){
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)
             pick+=dp[i-2];
            int notpick=dp[i-1];
            dp[i]= max(pick,notpick);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)  return nums[0];

        vector<int> nums1, nums2;
        for(int i=1;i<nums.size();i++)
            nums1.push_back(nums[i]);
        for(int i=0;i<nums.size()-1;i++)
            nums2.push_back(nums[i]);

        int first= robbing(nums1,nums1.size()-1);
        int second= robbing(nums2,nums2.size()-1);
        return max(first,second);
    }
