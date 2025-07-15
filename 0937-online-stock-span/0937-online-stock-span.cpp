class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = 0;

    StockSpanner() {}

    int next(int price) {
        while (!st.empty() && st.top().second <= price) {
            st.pop();//so we need to have the previous greater element and its index then current - that index is the span so we do decreasing monotonic stack order
        }

        int span;
        if (st.empty()) {
            span = index + 1;//if we removed all the elements then currentindex+1 is answer
        } else {
            span = index - st.top().first;//else the current index - top ka index 
        }

        st.push({index, price});
        index++;
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */