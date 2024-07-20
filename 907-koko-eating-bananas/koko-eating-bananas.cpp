class Solution {
public:

    int findMax(vector<int> &piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int hourly) {
        long long totalHrs = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            // Using integer arithmetic to avoid precision issues
            totalHrs += (piles[i] + hourly - 1) / hourly;
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int> piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHrs = calculateTotalHours(piles, mid);
            if(totalHrs <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; // low will represent the min value of eating banana/hr 
    }

};
