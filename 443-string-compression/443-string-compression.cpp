class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) {
            return 1;
        }
        char prev = chars[0];
        int count = 0;
        int index = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == prev) {
                count++;
            } else {
                if (count == 1) {
                    chars[index] = prev;
                    index++;
                } else {
                    chars[index] = prev;
                    index++;
                    
                    string val = "";
                    
                    while (count > 0) {
                        int digit = count % 10;
                        val += digit + '0';
                        count /= 10;
                    }
                    
                    for (int i = val.length() - 1; i >= 0; 
                         i--) {
                        chars[index] = val[i];
                        index++;
                    }
                }
                    
                prev = chars[i];
                count = 1;
                
            }
        }
        
        if (count == 1) {
            chars[index] = prev;
            index++;
        } else {
            chars[index] = prev;
            index++;
            string val = "";
                    
            while (count > 0) {
                int digit = count % 10;
                val += digit + '0';
                count /= 10;
            }

            for (int i = val.length() - 1; i >= 0; 
                 i--) {
                chars[index] = val[i];
                index++;
            }
        }
        
        return index;
    }
};