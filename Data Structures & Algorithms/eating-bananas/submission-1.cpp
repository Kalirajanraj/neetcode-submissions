class Solution {
public:
    int helper(int low, int high, vector<int>& piles, int h) {
        if (low == high)
            return low;

        int mid = low + (high - low) / 2;

        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }

        if (hours <= h) {
            // mid is a valid speed
            // Try to find a smaller speed
            return helper(low, mid, piles, h);
        } 
        else {
            // mid is too slow
            // Need a higher speed
            return helper(mid + 1, high, piles, h);
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = *max_element(piles.begin(), piles.end());

        return helper(1, maxRate, piles, h);
    }
};
