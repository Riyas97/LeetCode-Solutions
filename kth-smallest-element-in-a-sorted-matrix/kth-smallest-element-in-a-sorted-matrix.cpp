class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>,
           vector<tuple<int, int, int> >,
           greater<tuple<int, int, int> > >
           g;
        
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            g.push(std::tuple(matrix[0][i], 0, i));
        }
        
        for (int i = 0; i < k; i++) {
            tuple<int, int, int> tup = g.top();
            int a = get<0>(tup);
            int b = get<1>(tup);
            int c = get<2>(tup);
            
            if (i == k-1) {
                return a;
            }
            
            g.pop();
            
            if (b < n - 1) {
                g.push(std::tuple(matrix[b+1][c], b+1, c));
            }
        }
        return 0;        
    }
};