class Solution {
public:
    string check(vector<vector<char>>& moves) {
        string ans = "";
        if (moves[0][0] == moves[0][1] && 
            moves[0][1] == moves[0][2] && moves[0][0] != 'X') {
            ans.push_back(moves[0][0]);
            return ans;
        }
        if (moves[1][0] == moves[1][1] && 
            moves[1][1] == moves[1][2] && moves[1][0] != 'X') {
            ans.push_back(moves[1][0]);
            return ans;
        }
        if (moves[2][0] == moves[2][1] && 
            moves[2][1] == moves[2][2] && moves[2][0] != 'X') {
            ans.push_back(moves[2][0]);
            return ans;
        }
        if (moves[0][0] == moves[1][0] && 
            moves[1][0] == moves[2][0] && moves[0][0] != 'X') {
            ans.push_back(moves[0][0]);
            return ans;
        }
        if (moves[0][1] == moves[1][1] && 
            moves[1][1] == moves[2][1] && moves[0][1] != 'X') {
            ans.push_back(moves[0][1]);
            return ans;
        }
        if (moves[0][2] == moves[1][2] && 
            moves[1][2] == moves[2][2] && moves[0][2] != 'X') {
            ans.push_back(moves[0][2]);
            return ans;
        }
        if (moves[0][0] == moves[1][1] && 
            moves[1][1] == moves[2][2] && moves[0][0] != 'X') {
            ans.push_back(moves[0][0]);
            return ans;
        }
        if (moves[0][2] == moves[1][1] && 
            moves[1][1] == moves[2][0] && moves[0][2] != 'X') {
            ans.push_back(moves[0][2]);
            return ans;
        }
        return ans;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<char> v1(3, 'X');
        vector<vector<char>> v(3, v1);
        bool alt = true;
        int num = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (alt) {
                v[moves[i][0]][moves[i][1]] = 'A';
            } else {
                v[moves[i][0]][moves[i][1]] = 'B';
            }
            num++;
            alt = !alt;        
        }
        
        string ans = check(v);
        if (ans != "") {
            return ans;
        } else if (num != 9) {
            return "Pending";
        }
        return "Draw";
    }
};