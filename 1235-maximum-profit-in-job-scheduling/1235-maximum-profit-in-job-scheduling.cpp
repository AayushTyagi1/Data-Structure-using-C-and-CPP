class Solution {
public:

bool static comp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0] && a[1]==b[1]){
        return a[2]<b[2];
    }
    
    else if(a[1]==b[1]){
        return a[0]<b[0];
    }
    
    else{
        return a[1]<b[1];
    }
}


int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    int n=startTime.size();
    
    vector<vector<int>>vec(n);
    
    for(int i=0;i<n;i++){
        
        int a=startTime[i];
        int b=endTime[i];
        int c=profit[i];
        
        vec[i]={a,b,c};
        
    }
    
    sort(vec.begin(),vec.end(),comp);
    
    vector<int>dp(n,0);
    
    dp[0]=vec[0][2];
    
    for(int i=1;i<n;i++){
        
        int inc=-1,ans=vec[i][2];
        
        int low=0,high=i-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(vec[mid][1]<=vec[i][0]){
                inc=mid;
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
            
        }
        
        if(inc!=-1){
            ans+=dp[inc];
        }
        
        dp[i]=max(ans,dp[i-1]);
    }
    
    return dp[n-1];
    
}
};