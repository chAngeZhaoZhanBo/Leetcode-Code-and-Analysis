# String to Integer (atoi)

这类问题都是判断给定的字符串是否满足某些特征（可能顺带求值），通常而言正则表达式就可以满足需要。

当然，出于锻炼码力的目的，我们可以尝试自己实现算法而不是简单地使用正则表达式。

如果你懂得一点点编译相关的词法分析知识，就应该知道可以构造一个DFA来实现正则表达式的功能。如果完全不懂，也不要担心。简单来讲，DFA由以下的部分组成

* 一个非空有限的状态集合，表示DFA的不同状态
* 一个非空有限的字符集合，表示DFA可以接受的输入字符
* 一个转移函数，指明了DFA在某一状态下接收到某一字符时，得到的新状态
* 一个开始状态，表示DFA起始时的状态
* 若干个接受状态，到达接收状态时表示得到了符合要求的字符串



对于本题，相应的DFA的构造比较显然，无需进一步的词法分析知识，本题的DFA构造如下

1. 字符集合，我们对DFA可以接受的字符做如下分类
   * space：表示空白，在本题中只有空格被视为空白
   * sign：表示正负号，即'-'或'+'
   * num：表示数字，即'0'~'9'
   * others：表示其余的所有字符
2. 状态集合及转移函数
   * start：DFA的开始状态。在接受到空白时转移到start本身，接收到sign时转移到pre状态，接收到num时转移到number状态，接收到others时转移到fail状态
   * pre：表示已经接受了正负号，等待进入number状态的状态。此时只有接收到num才进入number状态，接收到其余字符全部进入fail状态
   * number：表示此时已经开始对字符串中的整数进行翻译。接收到num时仍进入number状态，接收到其余字符全部进入accept状态
   * accept：表示对整数的翻译已经中止，可以结束，是接收状态。
   * fail：表示还未对整数开始翻译就已识别到不合法的字符，结束，是接收状态。
3. 状态转移时的额外操作
   * 当进入pre状态时，记录整数的正负性（如果未经pre状态直接进入number状态，默认为正）
   * 当进入number状态时，将用于记录当前整数的result乘10，再加上新输入的字符对应的数字。判断是否溢出，若已达到INT_MAX或INT_MIN，中止
   * 进入fail状态时，直接返回0
   * 进入accept状态时，返回result



代码如下



```cpp
class Solution {
public:
    enum stateType{start,pre,number,accept,fail};
    enum charType{space,sign,num,others};
    charType getCharType(char c){
        if(c=='+'||c=='-')
            return sign;
        else if(c==' ')
            return space;
        else if(c-'0'>=0&&c-'0'<=9)
            return num;
        else
            return others;
    }
    void updateResult(int& result,char c,bool isPositive){
        int tmp=(c-'0');
        if(result>INT_MAX/10||(result==INT_MAX/10&&tmp>INT_MAX%10)){
            result=INT_MAX;
        }
        else if(result<INT_MIN/10||(result==INT_MIN/10&&tmp>-(INT_MIN%10))){
            result=INT_MIN;
        }
        else{
            tmp=isPositive?tmp:(-tmp);
            result=result*10+tmp;            
        }
    }
    int myAtoi(string str) {
        stateType transTable[3][4]={
            {start,pre,number,fail},
            {fail,fail,number,fail},
            {accept,accept,number,accept}
        };
        int result=0;
        bool isPositive=true;
        stateType curState=start;
        charType curChar;

        for(char c:str){
            curChar=getCharType(c);
            curState=transTable[curState][curChar];
            if(curState==number){
                updateResult(result,c,isPositive);
                if(result==INT_MAX||result==INT_MIN)
                    break;
            }
            else if(curState==pre&&c=='-')
                isPositive=false;
            else if(curState==fail)
                return 0;
            else if(curState==accept)
                break;
        }
        return result;     
    }
};
```





