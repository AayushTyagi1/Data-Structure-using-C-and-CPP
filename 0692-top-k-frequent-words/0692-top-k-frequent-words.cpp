class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        vector<pair<int, string>> h;
        vector<string> res;
        for (string& word : words) cnt[word]++;
        for (auto& p : cnt) h.push_back({-p.second, p.first});

        make_heap(h.begin(), h.end(), greater<pair<int, string>>());
        for (int i = 0; i < k; i++) {
            pop_heap(h.begin(), h.end(), greater<pair<int, string>>());
            res.push_back(h.back().second);
            h.pop_back();
        }
        return res;
    }
};