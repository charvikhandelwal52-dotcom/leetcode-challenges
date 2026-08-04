class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int mini= nums[0];
        int maxi= nums[n-1];
        for(int i=mini; i<=maxi ; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(nums[j]==i) cnt++;
            }
            if(cnt==0){
                ans.push_back(i);
                continue;
            }
        }
        return ans;
    }
};