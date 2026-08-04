class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int maxi= nums[n-1];
        int mini= nums[0];
        int gap= maxi- mini + 1;
        vector<int> ans;
        vector<int> hash(gap,0);
        for(int i=0; i<n; i++){
            hash[nums[i]-mini]++;
        }
        for(int i=mini; i<= maxi; i++){
            if(hash[i-mini]== 0){
                ans.push_back(i);
                continue;
            }
        }
        return ans;

    }
};