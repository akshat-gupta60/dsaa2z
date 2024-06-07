class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxRow = 0;

            // Find the maximum element in the middle column
            for (int i = 0; i < n; i++) {
                if (v[i][mid] > v[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Compare the maximum element with its neighbors
            bool leftIsBig = (mid - 1 >= 0 && v[maxRow][mid - 1] > v[maxRow][mid]);
            bool rightIsBig = (mid + 1 < m && v[maxRow][mid + 1] > v[maxRow][mid]);

            // If the middle element is greater than its neighbors, it is a peak
            if (!leftIsBig && !rightIsBig) {
                return {maxRow, mid};
            } else if (leftIsBig) {
                high = mid - 1; // Move to the left half
            } else {
                low = mid + 1; // Move to the right half
            }
        }
        return {};
    }
};
