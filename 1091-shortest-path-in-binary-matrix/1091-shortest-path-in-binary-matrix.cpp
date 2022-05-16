class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> qu;
        if (grid.size() == 1) {
            return 1;
        }
        if (grid[0][0] != 0) {
            return -1;
        }
        qu.push(make_tuple(0,0,1));
        grid[0][0] = 2;
        int ans = -1;
        while (!qu.empty()) {
            tuple<int,int,int> tu = qu.front();
            qu.pop();
            int x = get<0>(tu);
            int y = get<1>(tu);
            int dist = get<2>(tu);
            bool exit = false;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x + i < 0 || y + j < 0 || 
                        x + i >= grid.size() || 
                        y + j >= grid.size() || 
                        grid[x+i][y+j] != 0) {
                        continue;
                    }
                    //cout << x+i << " " << y+j << "\n";
                    if (x+i == grid.size()-1 && 
                        y+j == grid.size()-1) {
                        //cout << "here";
                        ans = dist + 1;
                        exit = true;
                        break;
                    }
                    qu.push(make_tuple(x+i,y+j,dist+1));
                    grid[x+i][y+j] = 2;
                }
                if (exit) {
                    break;
                }
            }
            if (exit) {
                break;
            }
        }
        return ans;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};