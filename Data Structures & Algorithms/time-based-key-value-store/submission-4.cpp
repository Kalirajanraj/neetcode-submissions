class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        auto &v = mp[key];

        int left = 0;
        int right = v.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                // This timestamp is valid.
                // Try to find a larger valid timestamp.
                ans = v[mid].second;
                left = mid + 1;
            }
            else {
                // Timestamp is too large, search left.
                right = mid - 1;
            }
        }

        return ans;
    }
};
