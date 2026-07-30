class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        int i=0;
        while(i<chars.size()){
            char current_char= chars[i];
            int count=0;
            while(i< chars.size() && chars[i]== current_char){
                count++;
                i++;
            }

            chars[idx]= current_char;
            idx++;

            if(count>1){
                string count_str= to_string(count);
                for(char &ch: count_str){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};