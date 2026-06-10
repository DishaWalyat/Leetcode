class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;  // string as stack — cleaner
        
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // still have removals left — chop from end
        if (k > 0)
            st = st.substr(0, st.size() - k);

        // strip leading zeros
        int start = st.find_first_not_of('0');
        st = (start == string::npos) ? "0" : st.substr(start);

        return st.empty() ? "0" : st;
    }
};