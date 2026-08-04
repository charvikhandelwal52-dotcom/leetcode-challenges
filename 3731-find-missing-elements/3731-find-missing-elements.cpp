class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        int mini = nums[0];
        int maxi= nums[0];
        for(int i=1; i<n; i++){
            if(mini > nums[i]){
                mini = nums[i];
            }
        }
        for(int i=1; i<n; i++){
            if(maxi< nums[i]){
                maxi= nums[i];
            }
        }
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