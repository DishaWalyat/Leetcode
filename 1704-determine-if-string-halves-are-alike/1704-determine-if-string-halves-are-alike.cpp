class Solution {
public:
    bool halvesAreAlike(string s) {
        
        string first;
        string second;

        for( int i=0; i<s.size()/2; i++){
            first.push_back(s[i]);
        }

        for( int i=s.size()/2; i<s.size(); i++){
            second.push_back(s[i]);
        }
        int count1=0;
        int count2=0;

        for( int i=0; i<first.size(); i++){
            if(first[i]=='a'|| first[i]=='e'|| first[i]=='i'|| first[i]=='o'|| first[i]=='u'|| first[i]=='A'|| first[i]=='E'|| first[i]=='I'||first[i]== 'O'|| first[i]=='U' ){
                count1++;
            }
        }

        for( int i=0; i<second.size(); i++){
            if(second[i]=='a'|| second[i]=='e'|| second[i]=='i'|| second[i]=='o'|| second[i]=='u'|| second[i]=='A'|| second[i]=='E'|| second[i]=='I'||second[i]== 'O'|| second[i]=='U' ){
                count2++;
            }
        }

        return(count1==count2);


    }
};