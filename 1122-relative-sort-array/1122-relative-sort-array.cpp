class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <int, int> um;
        unordered_set <int> us;
        set <int> so;
        for (int i = 0; i < arr2.size(); i++) {
            us.insert(arr2[i]);
        }
        for (int i = 0; i < arr1.size(); i++) {
            um[arr1[i]]++;
            if (us.find(arr1[i]) == us.end()) {
                so.insert(arr1[i]);
            }
        }
        vector <int> vect;
        for (int i = 0; i < arr2.size(); i++) {
            int num = um[arr2[i]];
            while (num--) {
                vect.push_back(arr2[i]);
            }
        }
        
        for (auto it = so.begin(); it != so.end(); it++) {
            int num = um[*it];
            while (num--) {
                vect.push_back(*it);
            }
            
        }
        return vect;
    }
};