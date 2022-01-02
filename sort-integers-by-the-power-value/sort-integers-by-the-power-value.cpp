class Solution {
public:
    int dp(int num, unordered_map <int, int>& power) {
        if (power.find(num) != power.end()) {
            return power[num];
        }
        if (num == 1) {
            return 0;
        }
        if (num % 2 == 0) {
            int num1 = num / 2;
            power[num] = dp(num1, power) + 1;
        } else {
            int num1 = 3 * num + 1;
            power[num] = dp(num1, power) + 1;
        }
        return power[num];
    }
    
    bool sortfunc(const tuple<int, int>& a, 
               const tuple<int, int>& b)
    {
        if (get<0>(a) == get<0>(b)) {
            return (get<1>(a) < get<1>(b));
        } 
        return (get<0>(a) < get<0>(b));
    
    }
    
    
    int getKth(int lo, int hi, int k) {
        unordered_map <int, int> power;
        vector <tuple<int, int>> v1;
        
        for (int i = lo; i <= hi; i++) {
            int powNum = dp(i, power);
            //cout << powNum;
            v1.push_back(make_tuple(powNum, i));
        }
        
        sort(v1.begin(), v1.end());
        
        return get<1>(v1[k-1]);
    }
};