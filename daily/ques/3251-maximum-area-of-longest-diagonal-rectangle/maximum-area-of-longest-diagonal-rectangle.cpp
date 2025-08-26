class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestDiagSq = -1;   // store squared length of diagonal
        long long bestArea   = 0;

        for (const auto& rect : dimensions) {
            long long w = rect[0], h = rect[1];
            long long diagSq = w * w + h * h;
            long long area   = w * h;

            if (diagSq > bestDiagSq || (diagSq == bestDiagSq && area > bestArea)) {
                bestDiagSq = diagSq;
                bestArea   = area;
            }
        }
        return (int)bestArea;
    }
};
