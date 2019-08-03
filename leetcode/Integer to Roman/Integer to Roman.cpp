class Solution {
public:
    string intToRoman(int num) {
        string str;
        int div;
        
        div=num/1000;
        str+=string(div,'M');
        num=num%1000;
        
        div=num/100;
        if(div<5){
            if(div==4)
                str+="CD";
            else
                str+=string(div,'C');
        }
        else{
            if(div==9)
                str+="CM";
            else{
                str+='D';
                str+=string(div-5,'C');
            }
        }
        num=num%100;
        
        div=num/10;
        if(div<5){
            if(div==4)
                str+="XL";
            else
                str+=string(div,'X');
        }
        else{
            if(div==9)
                str+="XC";
            else{
                str+='L';
                str+=string(div-5,'X');
            }
        }
        num=num%10;
        
        div=num;
        if(div<5){
            if(div==4)
                str+="IV";
            else
                str+=string(div,'I');
        }
        else{
            if(div==9)
                str+="IX";
            else{
                str+='V';
                str+=string(div-5,'I');
            }
        }
        return str;
    }
};
