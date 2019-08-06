class Solution {
   public:
    bool isValid(string s) {
        stack<char> bracketStack;
        unordered_map<char, char> bracketMap{
            {')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (bracketMap.find(c) != bracketMap.end()) {
                if (bracketStack.empty() ||
                    bracketStack.top() != bracketMap[c]) {
                    return false;
                } else {
                    bracketStack.pop();
                }
            } else {
                bracketStack.push(c);
            }
        }
        return bracketStack.empty();
    }
};
