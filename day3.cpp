class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size(),ans=0;
        int** dp = new int*[n];
        for(int i=0;i<n;i++)
            dp[i]= new int[n];
        
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        for(int i=1;i<n;i++)
            dp[i-1][i]=nums[i]-nums[i-1];
        for(int i=0;i+2<n;i++){
            int j = i+2;
            if(nums[i+1]-nums[i] == nums[j]-nums[j-1]){
                ans++;
                dp[i][j] =nums[j]-nums[j-1];
            }
            else
                dp[i][j]=5000;
        }        
            
        for(int len=4;len<=n;len++){
            
            for(int i=0;i+len-1<n;i++){
                int j = i+len-1;
                if(nums[i+1]-nums[i] == nums[j]-nums[j-1] && dp[i+1][j-1]==nums[i+1]-nums[i]){
                    ans++;
                    dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j]=5000;
            }
        }
        return ans;
    }
};