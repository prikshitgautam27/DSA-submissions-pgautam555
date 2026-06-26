class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
          vector<int>v;
        stack<int>s;
        int n=temperatures.size();
        for(int i=n-1 ; i>=0; i--){
            while(!s.empty() && temperatures[s.top()]<= temperatures[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(0);
                
            }
            else{
                v.push_back(s.top()-i);
            }
            s.push(i);
        }
        reverse(v.begin(),v.end());
        
        return v;
    }
};
