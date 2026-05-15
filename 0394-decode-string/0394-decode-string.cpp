class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> stringstack;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.length() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numstack.push(num);
                i--;
            }
            else if(s[i] == ']'){
                string temp = "";
                while(!stringstack.empty() && stringstack.top() != "["){
                    temp = stringstack.top() + temp;
                    stringstack.pop();
                }

                stringstack.pop();

                int repeat = numstack.top();
                numstack.pop();

                string repeated = "";
                while(repeat--){
                    repeated += temp;
                }
                stringstack.push(repeated);
            }
            else{
                stringstack.push(string(1,s[i]));
            }
        }

        string result = "";
        while(!stringstack.empty()){
            result = stringstack.top() + result;
            stringstack.pop();
        }
        return result;
    }
};