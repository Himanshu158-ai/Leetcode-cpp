class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;

        int l = 0;
        int r = l + k - 1;

        int sum = 0;

        // Calculate the sum of the first window
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }

        while (r < n) {
            // Check if average >= threshold
            if (sum >= k * threshold) {
                count++;
            }

            // Remove the leftmost element
            sum -= arr[l];
            l++;
            r++;

            // Add the new element entering the window
            if (r < n) {
                sum += arr[r];
            }
        }

        return count;
    }
};
