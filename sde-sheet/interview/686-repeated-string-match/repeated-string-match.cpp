class Solution {
private:
    const int base = 256;         // Base value for characters (ASCII)
    const int mod = 1e9 + 7;      // Large prime for modulo hashing

    // Function to compute (a^b) % mod
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    // Rabin-Karp pattern matcher
    bool rabinKarp(const string &text, const string &pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return false;

        long long hash_pat = 0, hash_txt = 0;
        long long h = modPow(base, m - 1); // base^(m-1)

        // Initial hash for pattern and first window
        for (int i = 0; i < m; ++i) {
            hash_pat = (hash_pat * base + pattern[i]) % mod;
            hash_txt = (hash_txt * base + text[i]) % mod;
        }

        // Check the first window
        if (hash_pat == hash_txt && text.substr(0, m) == pattern) return true;

        // Rolling hash
        for (int i = m; i < n; ++i) {
            // Remove leading digit and add trailing one
            hash_txt = (hash_txt - h * text[i - m] % mod + mod) % mod;
            hash_txt = (hash_txt * base + text[i]) % mod;

            if (hash_txt == hash_pat && text.substr(i - m + 1, m) == pattern)
                return true;
        }

        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        int repeatCount = (b.size() + a.size() - 1) / a.size(); // minimum repeats

        string repeated = "";
        for (int i = 0; i < repeatCount; i++) repeated += a;

        // Check with Rabin-Karp
        if (rabinKarp(repeated, b)) return repeatCount;

        repeated += a;
        if (rabinKarp(repeated, b)) return repeatCount + 1;

        repeated += a;
        if (rabinKarp(repeated, b)) return repeatCount + 2;

        return -1;
    }
};
