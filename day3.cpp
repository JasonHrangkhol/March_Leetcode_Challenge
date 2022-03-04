class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();  
        if(n<3)
            return 0;
        int diff;
        int ans  =0 ;     
        diff = nums[1]-nums[0];
        int start =0,end=1;
        for(int i=2;i<n;i++)
        {
            if(diff==nums[i]-nums[i-1])
                end=i;
            else
            {
                start=i-1,end=i;
                diff = nums[end]-nums[start];
            }
            
            if(end-start+1>=3)
                ans=ans+(end-start-1);
        }
        return ans;
   
    }
};