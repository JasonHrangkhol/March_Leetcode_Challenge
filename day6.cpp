class Solution {
public:
    
    int countOrders(int n) {
       
        if(n==1)
            return 1;
        
        int mod = 1e9+7;
        long long ans = 1,x=2;
        
        for(long long  i=2;i<=n;i++){
            
            long long d = (x+1)%mod, temp_ans = 0;
            
            for(long long j=1;j<=x;j++){
                
                temp_ans=(temp_ans%mod + (ans*d)%mod)%mod;
                d--;
            }
            
            ans = (temp_ans%mod + ans%mod)%mod;
            x+=2;
       }
        return (int)ans;
    }
};