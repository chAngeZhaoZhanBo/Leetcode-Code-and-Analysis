class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int y=x;
        queue<int> q;
        do{
            q.push(x%10);
            x/=10;
        }while(x!=0);
        while(!q.empty()){
            if(x>INT_MAX/10||(x==INT_MAX/10&&q.front()>7))
                return false;
            x=x*10+q.front();
            q.pop();
        }
        return x==y;    
    }
};
