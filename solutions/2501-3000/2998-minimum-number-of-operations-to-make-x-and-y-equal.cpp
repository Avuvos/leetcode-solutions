class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        const int lim = 1e5;
        queue<int> q;
        vector<int> dist(lim, -1);
        dist[x] = 0;
        q.push(x);
        while (!q.empty()) {
            int z = q.front(); q.pop();
            if (z == y) break;
            if (z + 1 < lim && dist[z + 1] == -1) {
                dist[z + 1] = dist[z] + 1;
                q.push(z + 1);
            }
            if (z - 1 > 0 && dist[z - 1] == -1) {
                dist[z - 1] = dist[z] + 1;
                q.push(z - 1);
            }
            if (z % 5 == 0 && dist[z / 5] == -1) {
                dist[z / 5] = dist[z] + 1;
                q.push(z / 5);
            }
            if (z % 11 == 0 && dist[z / 11] == -1) {
                dist[z / 11] = dist[z] + 1;
                q.push(z / 11);
            }
            if (dist[y] != -1) break;
        }
        return dist[y];
    }
};
