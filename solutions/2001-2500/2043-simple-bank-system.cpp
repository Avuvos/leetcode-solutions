class Bank {
public:
    vector<long long> bal;
    int n;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }

    bool valid_acc(int x) {
        return x >= 1 && x <= n;
    }
    
    bool transfer(int a1, int a2, long long money) {
        if (!valid_acc(a1) || !valid_acc(a2) || bal[a1 - 1] < money) return false;
        bal[a1 - 1] -= money;
        bal[a2 - 1] += money;
        return true;
    }
    
    bool deposit(int a, long long money) {
        if (!valid_acc(a)) return false;
        bal[a - 1] += money;
        return true;
    }
    
    bool withdraw(int a, long long money) {
        if (!valid_acc(a) || bal[a - 1] < money) return false;
        bal[a - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
