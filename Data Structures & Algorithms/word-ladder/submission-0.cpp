class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string e =endWord;
        unordered_set<string>st(wordList.begin(), wordList.end());
        int res=0;queue<string>q;

        string s=beginWord;
        int m= s.length();
q.push(s);

while(!q.empty()){
    res++;
    int len=q.size();

for(int i=0;i<len;i++){
    string word=q.front();
    q.pop();
    for(int j=0;j<m;j++){
        char ch=word[j];

        for(char c='a';c<='z';c++){
            word[j]=c;
            if(st.find(word)==st.end()){
continue;
            }
            if(word==e){
               return res+1;
            }
            st.erase(word);
            q.push(word);
        }
        word[j]=ch;
    }
}

}
return 0;

    }
};
