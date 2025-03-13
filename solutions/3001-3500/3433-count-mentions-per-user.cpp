class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers, 0);
        vector<int> next_online(numberOfUsers, 0);
        sort(events.begin(), events.end(), [&](const vector<string> &v1, const vector<string> &v2) {
           if (stoi(v1[1]) != stoi(v2[1])) return stoi(v1[1]) < stoi(v2[1]);
           if (v1[0] == "OFFLINE") return true;
           return false;
        });
        int all = 0;
        for (auto &e: events) {
            string type = e[0], mentions = e[2];
            int ts = stoi(e[1]);
            if (type == "OFFLINE") {
                next_online[stoi(mentions)] = ts + 60;
            } else {
                if (mentions == "ALL") {
                    all++;
                } else if (mentions == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (next_online[i] <= ts) {
                            ans[i]++;
                        }
                    }
                } else {
                    vector<string> users;
                    istringstream iss(mentions);
                    string user;
                    while (iss >> user) {
                        users.push_back(user);
                    }
                    for (auto& user: users) {
                        ans[stoi(user.substr(2))]++;
                    }
                }
            }
        }
        for (int i = 0; i < numberOfUsers; i++) {
            ans[i] += all;
        }
        return ans;
    }
};
