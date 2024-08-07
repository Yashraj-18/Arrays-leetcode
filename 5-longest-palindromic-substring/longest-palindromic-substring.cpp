class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;
        
        int max_len = 1;
        int st = 0, end = 0;

        for (int i = 0; i < n - 1; i++) {
            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            int len = r - l - 1;
            if (len > max_len) {
                max_len = len;
                st = l + 1;
                end = r - 1;
            }
            
            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            len = r - l - 1;
            if (len > max_len) {
                max_len = len;
                st = l + 1;
                end = r - 1;
            }
        }

        return s.substr(st, max_len);
    }
};
