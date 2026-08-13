class Solution {
public:
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int maxi= INT_MIN;
        for(int i=0; i<n ; i++){
            maxi= max(maxi, weights[i]);
        }
        int sum=0;
        for(int i=0; i<n; i++){
            sum += weights[i];
        }
        int low=maxi, high= sum;
        while(low <= high){
            int mid= (low+high)/2;
            int daysReq= func(weights, mid);
            if(daysReq<= days){
                high= mid-1;
            }
            else low= mid+1;
        }
        
        return low;
    }

    int func(vector<int>& weights, int cap){
        int day=1, load=0;
        int n= weights.size();
        for(int i=0; i<n; i++){
            if(load+ weights[i] > cap){
                day++;
                load= weights[i];
            }
            else load += weights[i];
        }
        return day;
    }
};