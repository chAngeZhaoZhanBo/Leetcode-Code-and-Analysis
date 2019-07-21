# ZigZag Conversion



<https://leetcode.com/problems/zigzag-conversion/>

```cpp
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
```



典型的找规律题，难度较低。

一个ZigZag图形由若干个“Z”图形（可能不完整）组成，相邻的“Z”图形有共用的边。

Zigzag形成的图形有明显的周期性，因此寻求Zigzag图形每一行的全部字符在原字符串中的下标所符合的数学规律是解题的关键。

对于第一行和最后一行，每行的字符在一个完整的“Z”图形中出现两次，而其余行的字符则出现三次。在下文中，rowIndex表示所讨论的行的标号（从0开始）。

由于每个“Z”图形的大小固定，容易看出第一次出现与最后一次出现的两个字符的下标之差是一个定值，为$ len=2*numRows-2$。类似地，容易归纳出规律：第一次与第二次出现的字符下标之差为$cur1=len-2*rowIndex$ ，第二次与第三次出现地字符下标之差为$cur2=2*rowIndex$ (对于第一行和最后一行，cur2和cur1分别为0，可视为特例)

掌握该规律后，题目便迎刃而解。每一行的第一个字符的下标即为rowIndex，之后轮流使下标增加cur1与cur2即得到该行所有的字符下标（对于第一行和最后一行，cur1或cur2为0的情况下，要注意不能将同一个字符计算两次，13行的if判断便是为了处理这种情况）

实际上就是把原字符串的每个字符都过了一遍，找到下一个字符是常数时间复杂度的，因此整个算法的时间复杂度是O(n)的。至于空间复杂度，如果不考虑最终作为返回值的字符串，是O(1)的。

