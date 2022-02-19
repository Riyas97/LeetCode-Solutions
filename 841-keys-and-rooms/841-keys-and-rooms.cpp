class Solution {
public:
    void dfs(int rno, int& numv, vector<vector<int>>& rooms, 
            vector<bool>& visited) {
        if (visited[rno]) {
            return; 
        }
        numv++;
        visited[rno] = true;
        vector<int> rnokeys = rooms[rno];
        for (int i = 0; i < rnokeys.size(); i++) {
            //cout << rnokeys[i] << "\n";
            dfs(rnokeys[i], numv, rooms, visited);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numv = 0;
        //cout << rooms.size();
        vector<bool> visited(rooms.size(), false);
        dfs(0, numv, rooms, visited);
        if (numv == rooms.size()) {
            return true;
        }
        return false;
    }
};