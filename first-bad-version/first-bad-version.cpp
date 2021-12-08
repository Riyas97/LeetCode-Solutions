// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long int findfirst(long int s, long int e) {
        long int ans = -1;
        while (s <= e) {
            long int num = s + e;
            long int mid = int (num / 2);
            bool c = isBadVersion(mid);
            if (c) {
                // true, find first
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
    
    int firstBadVersion(int n) {
        long int s = 1;
        long int e = n;
        long int ans = findfirst(s, e);
        return ans;
    }
};