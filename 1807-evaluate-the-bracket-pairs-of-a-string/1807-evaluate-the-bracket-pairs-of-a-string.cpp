class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == '(') {
                i++; // skip '('

                string key;

                // Read the key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Skip ')'
                i++;

                // Replace key with value, or '?'
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            } 
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};