class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        int maxFreq = 0, cnt = 0;

        for (auto &p : freq) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                cnt = 1;
            } else if (p.second == maxFreq) {
                cnt++;
            }
        }
        return maxFreq * cnt;
    }
};