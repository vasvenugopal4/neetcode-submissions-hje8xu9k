class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> charMap;
        vector<int> charCount(26, 0);
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            std::string key;
            for (char c : strs[i])
                charCount[c - 'a']++;

            for (int i : charCount)
                key += std::to_string(i) + "-";

            if (charMap.contains(key))
                charMap[key].push_back(strs[i]);
            else
                charMap[key] = {strs[i]};

            std::fill(charCount.begin(), charCount.end(), 0);
        }

        for (auto const& [key, val] : charMap)
            ans.push_back(val);

        return ans;
    }
};
