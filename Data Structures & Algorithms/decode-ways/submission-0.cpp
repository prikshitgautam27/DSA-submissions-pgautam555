class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        int n= s.length();
        vector<int>dp(n+1,0);

        dp[0]=1;
        dp[1]=1; // if only 1 letter is there in string

        for(int i=2;i<=n ;i++){
            if(s[i-1] !='0'){
                dp[i]+=dp[i-1];
            }
            int two= stoi(s.substr(i-2,2));
            if(two>=10 && two <=26){
                dp[i] +=dp[i-2];
            }



        }
return dp[n];
    }
};
