class Solution {
public:
    bool check(vector<int>& nums,int n,int target)
{
    int low=0,high=n-1;
    if(target>nums[high])
     return false;
     if(nums[low]>target)return false;
     while(low<=high)
     {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
          return true;
        else if(nums[mid]>target )
          high=mid-1;
        else
          low=mid+1;
     }
     return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n=matrix.size();
      int m=matrix[0].size();
      for(int i=0;i<n;i++)
      {
        if(check(matrix[i],m,target))
            return true;
      }  
      return false;
    }
};
