class Solution {
public:
    bool isValidSerialization(string preorder) {
        /*
        Idea: 
        
        If a node is NOT NULL, it should have 1 incoming edge and
        2 outgoing edge. If a node is NULL, it should have just 1
        incoming edge. 
        
        Have a variable that increments & decrements according to
        that and if it is valid, at the end, it must be 0.
        */
        int diff = 1;
        stringstream ss(preorder);
        string element;
        while(getline(ss, element, ',')) {
            diff--;
            if (diff < 0) {
                // can never be negative
                return false;
            }
            if (element != "#") {
                diff += 2;
            }
        }
        return diff == 0;
        
    }
};