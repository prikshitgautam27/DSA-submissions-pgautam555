class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Min-heap: {distance, {row, col}}
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>> > pq;

        // Step 1: push all treasure chests (0) into heap
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    pq.push({0, {i, j}});
                }
            }
        }

        // Step 2: direction arrays
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // Step 3: Dijkstra traversal
        while(!pq.empty()) {
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            // If current distance is already larger, skip
            if(dist > grid[r][c]) continue;

            for(int k = 0; k < 4; k++) {
                int nr = r + delrow[k];
                int nc = c + delcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1) {
                    if(grid[nr][nc] > dist + 1) {
                        grid[nr][nc] = dist + 1;
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
        }
    }
};
