typedef long long ll;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetings_held(n, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> busy; //{end time, room number}
        priority_queue<int, vector<int>, greater<int>> open_rooms; //room number
        for (int room = 0; room < n; ++room)
            open_rooms.push(room);

        sort(meetings.begin(), meetings.end());
        for (auto &meeting : meetings) {
            ll start = meeting[0], end = meeting[1];
            //free rooms that their meetings ended
            while (!busy.empty() && busy.top().first <= start) {
                open_rooms.push(busy.top().second);
                busy.pop();
            }
            //delay the meeting
            if (open_rooms.empty()) {
                pair<ll, int> p = busy.top(); busy.pop();
                open_rooms.push(p.second);
                end = p.first + (end - start);
            }
            //assign a room
            int room = open_rooms.top(); open_rooms.pop();
            meetings_held[room]++;
            busy.push({end, room});
        }
        return max_element(begin(meetings_held), end(meetings_held)) - begin((meetings_held));
    }
};
