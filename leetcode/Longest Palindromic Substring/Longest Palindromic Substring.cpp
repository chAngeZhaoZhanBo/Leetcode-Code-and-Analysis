class Solution {
public:
    string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        vector<int> radius(t.size(),0);
        int index = 0, maxRight = 0;
        int maxIndex = 0, maxRadius = 0;
        for (int i = 1; i < t.size(); ++i) {
            radius[i] = (maxRight > i) ? min(radius[2 * index - i], maxRight - i) : 1;
            while (t[i + radius[i]] == t[i - radius[i]]) 
              ++radius[i];
            if (maxRight < i + radius[i]) {
                maxRight = i + radius[i];
                index = i;
            }
            if (maxRadius < radius[i]) {
                maxRadius = radius[i];
                maxIndex = i;
            }
        }
        return s.substr((maxIndex - maxRadius) / 2, maxRadius - 1);
    }
};
