class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        unordered_map<char,int> charMap;
        int mmax=0;
        for(int left=0,right=0;right<size;++right){
            if(charMap.find(s[right])!=charMap.end()){
                left=std::max(left,charMap[s[right]])+1;
            }
            mmax=std::max(mmax,right-left+1);
            charMap[s[right]]=right;
        }
        return mmax;
    }
};
