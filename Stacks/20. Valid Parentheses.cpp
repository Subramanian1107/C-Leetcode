class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        if(s.size() == 1)
            return false;
        for(char c:s){
            if(c == '(' || c == '[' || c == '{')
                stk.push(c);
            else
            {   
                if(!stk.empty())
                {
                    char top = stk.top();
                    if(c == ')' && top == '(' || c == ']' && top == '[' || c == '}' && top == '{' )
                        stk.pop();
                    else
                        return false;

                }
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};