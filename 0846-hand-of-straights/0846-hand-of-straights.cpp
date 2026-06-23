class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        //agar grps mein bant hi nhi skte to directly false ret 
        if(n%groupSize){
            return false;
        }
        //now we will make a ordered map so that seq mrin hi inc fasion mein simulation kar pae 
        map<int, int> mp; // number and the freq
        for(int &num: hand){
            mp[num]++;
        }// in order to store the freq of each element 
        while(!mp.empty()){
            int curr= mp.begin()->first;// sec would be the freq 
            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0){
                    //i zero hoga to curr ko hi point krega..to hum ek grp ke sare element nikal denge
                    return false;
                }
                //else.. vo hai to use krke freq minus minus
                mp[curr+i]--;
                if(mp[curr+i]<1){
                    //means vo khtm hogya..to htadenge
                    mp.erase(curr+i);
                }
            }

        }
        return true;

    }
};