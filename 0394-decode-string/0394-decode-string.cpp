class Solution {
public:
    string decodeString(string s) {

        stack<pair<int, string>> st;

        int num = 0;
        string curr = "";

        for(char c : s) {

            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            else if(c == '[') {
                st.push({num, curr});
                num = 0;
                curr = "";
            }

            else if(c == ']') {

                auto [repeat, prev] = st.top();
                st.pop();

                while(repeat--) {
                    prev += curr;
                }

                curr = prev;
            }

            else {
                curr += c;
            }
        }

        return curr;
    }
};