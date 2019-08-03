class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap{{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        int pre = INT_MAX, res = 0;
        int tmp;
        for (char c : s) {
            tmp = romanMap[c];
            res += tmp;
            if (tmp > pre) {
                res -= 2 * pre;
            }
            pre = tmp;
        }
        return res;
    }
};
