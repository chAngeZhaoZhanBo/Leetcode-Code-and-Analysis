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
