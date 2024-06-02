class Solution {
public:
    int check(vector<int>& arr, int a) {
        int n = arr.size();
        int start = 0, end = n - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < a) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        // Number of elements in the array that are less than `a`
        return a - (start + 1);
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int start = 1, end = 1e4;
        int res = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missingCount = check(arr, mid);
            
            if (missingCount < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        // The k-th missing number
        return start-1;
    }
};
