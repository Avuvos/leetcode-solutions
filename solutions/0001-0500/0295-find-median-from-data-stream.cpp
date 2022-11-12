class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<>> min_pq;
    
    //in the mean heap there will be all the big elements
    //in the max heap there will be all the small elements
    //so for example:
    //[2, 3, 4] we have [2, 3] in maxH and [4] in minH
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (!min_pq.empty() && num >= min_pq.top() && min_pq.size() >= max_pq.size()) {
            int x = min_pq.top(); min_pq.pop();
            min_pq.push(num);
            max_pq.push(x);
        } else if (!max_pq.empty() && num <= max_pq.top() && min_pq.size() <= max_pq.size()) {
            int x = max_pq.top(); max_pq.pop();
            max_pq.push(num);
            min_pq.push(x);
        } 
        else if (max_pq.size() < min_pq.size()) {
            max_pq.push(num);
        } else {
            min_pq.push(num);
        }
    }
    
    double findMedian() {
        int n = max_pq.size(), m = min_pq.size();
        double res = 0;
        if ((n + m) % 2 == 0) {
            res = (min_pq.top() + max_pq.top()) / 2.0;
            //cout << min_pq.top() << " : " <<  max_pq.top() << endl;
        } else {
            if (min_pq.size() > max_pq.size()) res = min_pq.top();
            else res = max_pq.top();
            //cout << res << endl;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
