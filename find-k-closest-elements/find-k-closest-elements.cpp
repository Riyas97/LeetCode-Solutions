class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <int> result;
        priority_queue <pair<int, int>> pq;
        
        for (int i = 0; i < arr.size(); i++) {
            pq.push(pair(abs(arr[i] - x), arr[i]));
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            result.push_back(get<1>(pq.top()));
            pq.pop();
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};