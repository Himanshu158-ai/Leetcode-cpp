class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // row -> bitmask of reserved seats
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Seat s ko mask me mark karo
            mp[row] |= (1 << s);
        }

        // Rows without any reservation
        long long ans = 2LL * (n - mp.size());

        for (auto &[row, mask] : mp) {

            // Seats 2,3,4,5
            bool left = true;
            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << s)) {
                    left = false;
                    break;
                }
            }

            // Seats 6,7,8,9
            bool right = true;
            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << s)) {
                    right = false;
                    break;
                }
            }

            // Seats 4,5,6,7
            bool middle = true;
            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << s)) {
                    middle = false;
                    break;
                }
            }

            if (left && right) {
                // Dono groups ek saath possible
                ans += 2;
            }
            else if (left || right || middle) {
                // At least one group possible
                ans += 1;
            }
        }

        return ans;
    }
};