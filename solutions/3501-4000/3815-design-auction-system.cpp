class AuctionSystem {
public:
    // (item, user) -> amount
    // item -> set of (amount, uid)
    map<pair<int, int>, int> user_item_to_amt;
    unordered_map<int, set<pair<int, int>>> item_to_bids;
    
    AuctionSystem() {
        user_item_to_amt.clear();
        item_to_bids.clear();
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (user_item_to_amt.contains({itemId, userId})) {
            updateBid(userId, itemId, bidAmount);
            return;
        }
        user_item_to_amt[{itemId, userId}] = bidAmount;
        item_to_bids[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = user_item_to_amt[{itemId, userId}];
        user_item_to_amt[{itemId, userId}] = newAmount;
        item_to_bids[itemId].erase({oldAmount, userId});
        item_to_bids[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int amt = user_item_to_amt[{itemId, userId}];
        user_item_to_amt.erase({itemId, userId});
        item_to_bids[itemId].erase({amt, userId});
    }
    
    int getHighestBidder(int itemId) {
        auto &st = item_to_bids[itemId];
        if (st.empty()) {
            return -1;
        }
        return st.rbegin() -> second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
