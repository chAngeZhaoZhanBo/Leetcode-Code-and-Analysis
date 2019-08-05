class Solution {
public:
    //unordered_map<char,string> phoneTable={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> phoneTable={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> vectorConnect(char digit,vector<string> strs){
        vector<string> result;
        //string letters=phoneTable[digit];
        string letters=phoneTable[digit-'0'-2];
        for(char letter:letters){
            for(string str:strs){
                result.push_back(move(letter+str));
            }
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return vector<string>{};
        else if(digits.size()==1){
            return vectorConnect(digits[0],vector<string>{""});
        }
        return vectorConnect(digits[0],letterCombinations(digits.substr(1)));
    }
};
