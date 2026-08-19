class Solution {
public:

    bool bS(vector<int>& matrix, int target, int m){
        int low=0, high= m-1;
        while(low<= high){
            int mid= (low+high)/2;
            if(matrix[mid] == target){
                return true;
            }
            else if(matrix[mid]< target){
                low= mid+1;
            }
            else high= mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m= matrix[0].size();
        for(int i=0; i<n; i++){
            bool idx= bS(matrix[i], target,m);
            if(idx){
                return true;
            }
        }
        return false;
    }
};