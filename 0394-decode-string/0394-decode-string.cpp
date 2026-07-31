class Solution {
public:
    string decodeString(string s) {

        stack<string> strStack;
        stack<int> numStack;

        string currString = "";
        int currNum = 0;

        for(char c : s) {

            if(c == '[') {

                strStack.push(currString);
                numStack.push(currNum);

                currString = "";
                currNum = 0;
            }

            else if(c == ']') {

                int num = numStack.top();
                numStack.pop();

                string prevString = strStack.top();
                strStack.pop();

                while(num--) {
                    prevString += currString;
                }

                currString = prevString;
            }

            else if(isdigit(c)) {

                currNum = currNum * 10 + (c - '0');
            }

            else {

                currString += c;
            }
        }

        return currString;
    }
};