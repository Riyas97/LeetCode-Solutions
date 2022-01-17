class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int num = 0;
        
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == students[i]) {
                continue;
            }
            num += abs(seats[i] - students[i]);
        }
        return num;
    }
};