class Solution {
public:
    int nthUglyNumber(int n) {
        
        if (n == 1) {
            return 1;
        }
        
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        
        pq.push(2);
        pq.push(3);
        pq.push(5);
        
        long long a = 0;
        
        for (int i = 2; i <= n; i++) {
            while (a == pq.top()) {
                pq.pop();
            }
            
            a = pq.top();
            pq.pop();
            pq.push(a * 2);
            pq.push(a * 3);
            pq.push(a * 5);
            cout << a;
            
            
        }
        return a;
    }
};