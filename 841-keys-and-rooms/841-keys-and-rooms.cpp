class Solution {
public:
    /*
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
    
    */
    
    bool dfs(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        while(!st.empty()) {
            int r = st.top();
            st.pop();
            //visited[room] = true;
            //cout << r;
            for (int i = 0; i < rooms[r].size(); i++) {
                if (!visited[rooms[r][i]]) {
                    //cout << rooms[r][i] << "l ";
                    visited[rooms[r][i]] = true;
                    st.push(rooms[r][i]);
                }
            }
        }
        
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                cout << i;
                return false;
            }
        }
        return true;
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /* Approach 1
        int numv = 0;
        //cout << rooms.size();
        vector<bool> visited(rooms.size(), false);
        dfs(0, numv, rooms, visited);
        if (numv == rooms.size()) {
            return true;
        }
        return false;
        */
        
        // Approach 2 (using stack)
        return dfs(rooms);
    }
};