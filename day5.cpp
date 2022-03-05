class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        int size = mp.size();
        int* dp = new int[size+1];
        
        auto it = mp.begin();
        int prev;
        dp[0]=0;
        for(int i=1;i<=size;i++){
            
            if(i==1){
                 
                dp[i] = it->first*it->second;
                prev = it->first;
            }
            else{
                
                 if(prev+1==it->first){
                     
                      dp[i]=max(it->first*it->second+dp[i-2],dp[i-1]);
                      dp[i]==dp[i-1]?prev=prev:prev=it->first;  
                 }
                    
                 else{
                      
                     dp[i] =it->first*it->second+max(dp[i-1], dp[i-2]);
                     prev = it->first;
                 }
                    
            }
            it++;
        }
        return dp[size];
    }
};