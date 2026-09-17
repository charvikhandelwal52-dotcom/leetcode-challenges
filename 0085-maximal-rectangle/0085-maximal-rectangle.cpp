class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n= heights.size();
        int maxArea=0;
        int ele=0;
        int nse, pse;
        for(int i=0; i<n; i++){
            while( !st.empty() && heights[st.top()] > heights[i]){
                ele = st.top();
                st.pop();
                nse=i;
                pse= st.empty() ? -1 : st.top();
                maxArea= max( maxArea, (heights[ele] * (nse-pse-1)));
            }
            st.push(i);
        }
        while( !st.empty()){
            nse=n;
            ele = st.top();
            st.pop();
            pse= st.empty() ? -1 : st.top();
            maxArea= max(maxArea, (nse-pse-1) * heights[ele]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int maxArea=0;
        vector<vector<int>> pSum(n , vector<int>(m));
        for(int j=0; j<m; j++){
            int sum=0;
            for(int i=0; i<n; i++){
                
                if(matrix[i][j]== '1'){
                    sum++;
                }
                else sum=0;
                pSum[i][j]= sum;
            }
        }
        for(int i=0; i<n; i++){
            maxArea= max(maxArea, largestRectangleArea(pSum[i]));
        }
        return maxArea;
    }
};