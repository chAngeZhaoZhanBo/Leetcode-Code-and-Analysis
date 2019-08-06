class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, "", n, res);
        return res;
    }
    void generate(int left, int right, string s, int n, vector<string>& res) {
        if (right == n) {
            res.push_back(s);
        } else {
            if (left < n) {
                generate(left + 1, right, s + "(", n, res);
            }
            if (right < left) {
                generate(left, right + 1, s + ")", n, res);
            }
        }
    }
};
