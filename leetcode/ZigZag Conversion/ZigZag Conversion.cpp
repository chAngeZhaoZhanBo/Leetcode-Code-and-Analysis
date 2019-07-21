class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string str;
        const int len=2*numRows-2;
        int cur,inc;
        for(int i=0;i<numRows;++i){
            cur=i;
            inc=len-2*i;
            while(cur<s.size()){
                if(inc){
                    str+=s[cur];
                }
                cur+=inc;
                inc=len-inc;
            }
        }
        return str;
    }
};
