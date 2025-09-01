struct ClassInfo {
    int passCount;
    int totalCount;

    // Calculate the gain if we add one extra student
    long double gain() const {
        return (long double)(passCount + 1) / (totalCount + 1)
             - (long double)passCount / totalCount;
    }
};

// Comparator for priority_queue (max-heap by gain)
struct Compare {
    bool operator()(const ClassInfo& a, const ClassInfo& b) const {
        return a.gain() < b.gain();
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ClassInfo, vector<ClassInfo>, Compare> pq;

        // Push all classes into heap
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        // Assign extra students one by one
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top.passCount++;
            top.totalCount++;
            pq.push(top);
        }

        // Compute final average ratio
        long double total = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            total += (long double)cur.passCount / cur.totalCount;
        }
        return (double)(total / classes.size());
    }
};