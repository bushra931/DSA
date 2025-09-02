
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = (int)points.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int ax = points[i][0], ay = points[i][1];
            for (int j = 0; j < n; ++j) if (i != j) {
                int bx = points[j][0], by = points[j][1];

                // A is upper-left of B (allow equal x or equal y)
                if (!(ax <= bx && ay >= by)) continue;

                bool emptyRect = true;
                for (int k = 0; k < n; ++k) if (k != i && k != j) {
                    int cx = points[k][0], cy = points[k][1];
                    // Closed rectangle [Ax..Bx] × [By..Ay], border included
                    if (cx >= ax && cx <= bx && cy >= by && cy <= ay) {
                        emptyRect = false;    // a third point lies inside/on border
                        break;
                    }
                }
                if (emptyRect) ans++; // count ordered pairs (A,B)
            }
        }
        return ans;
    }
};
