/**
 *本文件中包含了空间复杂度为O(n)的动态规划算法实现
 *以及Manacher算法的实现
 */



//以下为动态规划算法实现
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size(), left = 0, len = 1;
        bool dp[n];
        for(int j = 0; j < n; ++j){
            dp[j]=true;
            for(int i = 0; i < j; ++i){
                dp[i] = dp[i+1] && (s[i] == s[j]);
                if(dp[i] && len < j - i + 1){
                    len = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, len);
    }
};


//以下为Manacher算法实现
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
