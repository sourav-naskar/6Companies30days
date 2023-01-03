class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = -1;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                l = i;
                break;
            }    
        }
        for(int i = n - 1; i >= 1; i--) {
            if(arr[i] < arr[i - 1]) {
                r = i;
                break;
            }
        }
        if(l == -1) return 0; // this means array is already sorted.
        int mini = arr[l], maxi = arr[l];
        for(int i = l; i <=r; i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        l = upper_bound(arr.begin(), arr.begin() + l, mini) - arr.begin();
        r = lower_bound(arr.begin() + r + 1, arr.end(), maxi) - arr.begin();
        return r - l;
    }
};