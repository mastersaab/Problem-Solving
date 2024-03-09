class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n=nums.size();
       if(n==1) return nums[0];
       if(nums[0]!=nums[1]) return nums[0];
       if(nums[n-1]!=nums[n-2]) return nums[n-1];
       int l=0,h=n-1;
       while(l<=h){
           int mid=l+(h-l)/2;
           if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]) return nums[mid];
           else if(nums[mid]!=nums[mid-1]){//first occurance
               if(mid%2==0) l=mid+1;//ans is in right we r in left
               else h=mid-1; //ans is in left we r in right
            }
            else{
                if((mid-1)%2==0) l=mid+1;
                else h=mid-1;
            }
       } 
       return 0;
    }
};
