class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;

        int required = t.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            if (freq[s[right++]]-- > 0)
                required--;

            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                if (++freq[s[left++]] > 0)
                    required++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
