class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n=nums.size();
        vector<int>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=nums[i]+pref[i-1];
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i+1>=f)
            {
                int curr=0;
                if(i+1==f)
                {
                   curr=pref[i];
                }
                else
                {
                    curr=pref[i]-pref[i-f];
                }
                for(int j=i+1;j<n;j++)
                {
                    if(j-s>=i)
                    {
                        int now=pref[j]-pref[j-s];
                    ans=max(ans,now+curr);
                    }
                }
            }
        }

                for(int i=0;i<n;i++)
        {
            if(i+1>=s)
            {
                int curr=0;
                if(i+1==s)
                {
                   curr=pref[i];
                }
                else
                {
                    curr=pref[i]-pref[i-s];
                }
                for(int j=i+1;j<n;j++)
                {
                    if(j-f>=i)
                    {
                        int now=pref[j]-pref[j-f];
                    ans=max(ans,now+curr);
                    }
                }
            }
        }

        return ans;
    }
};