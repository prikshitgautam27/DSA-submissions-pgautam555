class Solution {
public:
    int countSubstrings(string s) {
        
        int total_c=0;
        int n= s.size();

        auto expand= [&](int left, int right){
            int count =0;
            while(left>=0 && right <n && (s[left] == s[right])){
                
                count++;
                left--;
                right++;
            }
            return count;
        };

        
        for(int i=0;i<n; i++){
           total_c += expand(i , i);
           total_c += expand( i, i+1);
        }
        return total_c;
    }
};
