class Solution {
public:
    string removeDuplicates(string s) {
        // we can maintain a stack
        //traverse through every char, if it is not equal to the top, then push it, if equal to the top, pop and next char, at the end, reverse the stack and return 
        stack<char>st;
        string ans;
        for(int i=0; i<s.length(); i++){
            if(st.size()<1){
                st.push(s[i]);
            }
            else if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};