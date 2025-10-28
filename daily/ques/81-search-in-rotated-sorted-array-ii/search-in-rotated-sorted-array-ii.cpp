#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target)
                return true;

            // Handle duplicates: skip edges that are equal
            if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
                l++;
                h--;
                continue;
            }

            // Left half is sorted
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid])
                    h = mid - 1;   // target in left half
                else
                    l = mid + 1;   // target in right half
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[h])
                    l = mid + 1;   // target in right half
                else
                    h = mid - 1;   // target in left half
            }
        }
        return false;
    }
};
