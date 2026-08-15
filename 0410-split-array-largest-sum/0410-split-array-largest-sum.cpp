class Solution {
public:

    int countStu(vector<int> &nums, int pages){
        int stu=1;
        long long pagesStu= 0;
        for(int i=0; i<nums.size() ; i++){
            if(pagesStu + nums[i] <= pages){
                pagesStu += nums[i];
            }
            else {
                stu ++;
                pagesStu = nums[i];
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        if(n<k) return -1;
        int low= *max_element(nums.begin(), nums.end());
        int high= accumulate( nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid= (low+high)/ 2;
            int stu= countStu(nums, mid);
            if(stu>k) low= mid+1;
            else high= mid-1;
        }
        return low;
    }
};