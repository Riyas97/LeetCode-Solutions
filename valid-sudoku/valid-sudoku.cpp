class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        //vector <unordered_set <char>> v;
        unordered_map<int, unordered_set<char>> v;
        
        unordered_map<int, unordered_set<char>> v1;
        
        for (int i = 0; i < m; i++) {
            unordered_set <char> s1;    
            for (int j = 0; j < n; j++) {
                char num = board[i][j];
                
                if (num != '.') {
                    if (s1.find(num) == s1.end()) {
                        s1.insert(num);
                    } else {
                        cout << i << j;
                        return false;
                    }
                    
                    if (i == 0) {
                        unordered_set <char> u;
                        u.insert(num);
                        v[j] = u;
                    } else {
                        unordered_set <char> u = v[j];
                        
                        if (u.find(num) == u.end()) {
                            u.insert(num);
                            v[j] = u;
                        } else {
                            return false;
                        }
                        
                    }
                    
                    int a = i / 3;
                    int b = j / 3;
                    int c = (a * 3) + b;
                    
                    if (v1.find(c) == v1.end()) {
                        unordered_set <char> u;
                        u.insert(num);
                        v1[c] = u;
                    } else {
                        unordered_set <char> u = v1[c];
                        
                        if (u.find(num) == u.end()) {
                            u.insert(num);
                            v1[c] = u;
                        } else {
                            return false;
                        }
                    }
                    

                    
                }
                
            }
        }
        return true;
    }
};