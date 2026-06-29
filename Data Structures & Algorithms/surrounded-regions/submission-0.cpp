class Solution {
    void dfs(int n,int m,int r, int c,vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[r][c]=1;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if((nr>=0  && nc>=0 && nr<n && nc<m) && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(n,m,nr,nc,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n= board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && !vis[i][j]){
                    dfs(n,m,i,j,board,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
