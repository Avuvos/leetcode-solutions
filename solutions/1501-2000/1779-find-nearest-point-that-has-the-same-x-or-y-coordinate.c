
int man_dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int min_dist = INT_MAX;
    int res = -1;
    for (int i = 0; i < pointsSize; i++) {
        if (!(x == points[i][0] || y == points[i][1])) continue;
        
        int curr_dist = man_dist(x, y, points[i][0], points[i][1]);
        if (curr_dist < min_dist) {
            min_dist = curr_dist;
            res = i;
        }
    }
    return res;
}
