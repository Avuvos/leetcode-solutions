#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

class Router {
public:
    int limit;
    int packets = 0;
    int uid = 0;
    map<int, queue<pair<int, int>>> mp; // ts to relevant pairs
    set<tuple<int, int, int>> seen; // triplets of ts, src, dest
    map<int, indexed_set> router_timestamps; // dest to sorted list of timestamps

    Router(int memoryLimit) {
        limit = memoryLimit;
        mp.clear();
        seen.clear();
        router_timestamps.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (seen.contains({timestamp, source, destination})) {
            return false;
        }
        if (packets == limit) {
            forwardPacket();
        }
        router_timestamps[destination].insert({timestamp, uid});
        uid++;
        mp[timestamp].push({source, destination});
        seen.insert({timestamp, source, destination});
        packets++;
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets == 0) return {};
        auto it = mp.begin();
        auto [src, dest] = it->second.front();
        it->second.pop();
        int ts = it->first;
        if (it->second.empty()) {
            mp.erase(ts);
        }
        packets--;
        seen.erase({ts, src, dest});
        router_timestamps[dest].erase(router_timestamps[dest].lower_bound({ts, -1}));
        return {src, dest, ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &st = router_timestamps[destination];
        return st.order_of_key({endTime + 1, -1}) - st.order_of_key({startTime, -1});
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
