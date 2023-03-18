class BrowserHistory {
public:
    vector<string> browser;
    int page = 0;
    BrowserHistory(string homepage) {
        browser.push_back(homepage);
        page = 0;
    }
    void visit(string url) {
        int to_pop = browser.size() - page - 1;
        while (to_pop) {
            browser.pop_back();
            to_pop--;
        }
        browser.push_back(url);
        page = browser.size() - 1;
    }
    
    string back(int steps) {
        page = max(0, page - steps);
        return browser[page];
    }
    
    string forward(int steps) {
        page = min((int)(browser.size() - 1), page + steps);
        return browser[page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
