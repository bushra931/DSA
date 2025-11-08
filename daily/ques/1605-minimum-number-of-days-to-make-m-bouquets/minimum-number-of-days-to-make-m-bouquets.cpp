class Solution {
public:
   bool canMake(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) return true;
        }
        return false;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (totalNeeded > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMake(bloomDay, m, k, mid)) {
            answer = mid;
            high = mid - 1;  // try smaller day
        } else {
            low = mid + 1;   // need more days
        }
    }
    return answer;   
    }
};