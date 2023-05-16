class StockSpanner {
public:
    vector<pair<int, int>> stk;
    StockSpanner() {}
        
    int next(int price) {
        int curPrice = price;
        int span = 1;
        
        while( stk.size() && stk.back().first <= price ){
            auto [prevPrice, prevSpan] = stk.back();
            stk.pop_back();
            span += prevSpan;
        }
        stk.push_back( pair<int, int>{curPrice, span} );
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */