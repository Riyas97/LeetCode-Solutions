class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        stack <int> sandw;
        queue <int> ppl;
        
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            sandw.push(sandwiches[i]);
        }
        
        for (int i = 0; i < students.size(); i++) {
            ppl.push(students[i]);
        }
        
        while (!ppl.empty() && count <= ppl.size()) {
            int s = sandw.top();
            int p = ppl.front();
            sandw.pop();
            ppl.pop();
            
            if (p == s) {
                count = 0;
            } else {
                sandw.push(s);
                ppl.push(p);
                count++;
            }
        }
        
        if (ppl.empty()) {
            return 0;
        }
        return ppl.size();
        
    }
};