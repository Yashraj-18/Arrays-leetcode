class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0 , n = s.size();
        while(i < n){
            s = s.substr(1) + s[0];
            if(s == goal) return true;
            i++;
        }
        return false;
    }
};