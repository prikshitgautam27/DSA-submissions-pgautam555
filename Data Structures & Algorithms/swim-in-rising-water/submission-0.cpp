class Solution {
public:

bool pathreachable(int r,int c,int t,vector<vector<int>>& grid,vector<vector<bool>>&vis){
int n=grid.size();
    if(r>=n || r<0 || c<0 || c>=n || grid[r][c]>t || vis[r][c]==true){
        return false;
    }
    vis[r][c]=true;
    int delr[4]={-1,0,1,0};
    int delc[4]={0,1,0,-1};

if(r==n-1 && c==n-1){
    return true;
}


    for(int i=0;i<4;i++){
        int nr=r+delr[i];
        int nc=c+delc[i];

        if(pathreachable(nr,nc,t,grid,vis)== true){
            return true;
        }
    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        int l=0;
        int r=n*n-1;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(pathreachable(0,0,mid,grid,vis)){
                    res=mid;
                    r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return res;
    }
};
