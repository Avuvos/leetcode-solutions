class Solution {
public:

    pair<string, vector<pair<string, string>>> enumerate_path(string s) {
        pair<string, vector<pair<string, string>>> res; //pair is (content, number.txt)
        int index = 0;
        while (index < s.size() && s[index] != ' ') {
            index++;
        }
        vector<pair<string, string>> files;
        res.first = s.substr(0, index);
        while (index < s.size()) {
            string current;
            string num_current;
            if (s[index] == ' ') index++;
            while (index < s.size() && s[index] != '(') {
                num_current += s[index];
                index++;
            }
            index++;
            while (index < s.size() && s[index] != ')') {
                current += s[index];
                index++;
            }
            index++;
            files.emplace_back(current, num_current);
        }
        res.second = files;
        return res;
    }



    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> data_to_path;
        vector<vector<string>> res;

        for (auto& path: paths) {
            pair<string, vector<pair<string, string>>>split_path = enumerate_path(path);
            for (int index = 0; index < split_path.second.size(); ++index) {
                string path_name = split_path.first + "/" + split_path.second[index].second;
                data_to_path[split_path.second[index].first].push_back(path_name);
            }
        }

        for (auto& [key, value]: data_to_path) {
            if (value.size() <= 1) continue;
            res.push_back(value);
        }
        return res;
    }
};
