class Solution {
public:
    vector<int> ans;
    vector<int> pancakeSort(vector<int>& arr) {
        cakeSort(arr,arr.size());
        return ans;
    }
    void cakeSort(vector<int>& arr,int n){
        if (n == 1){
            return;
        }
        int maxIndex = 0,maxValue = 0;
        for (int i=0;i<n;i++){
            if (maxValue < arr[i]){
                maxIndex = i;
                maxValue = arr[i];
            }
        }
        reverse(arr.begin(),arr.begin()+maxIndex+1);
        ans.push_back(maxIndex+1);
        reverse(arr.begin(),arr.begin()+n);
        ans.push_back(n);

        cakeSort(arr,n-1);
    }
};