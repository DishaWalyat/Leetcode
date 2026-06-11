class StockSpanner {
public:
    // pair of {price, span} -> Monotonic Decreasing Stack
    stack<pair<int, int>> st; 

    StockSpanner() {
        // Constructor khali chhod sakte hain
    }
    
    int next(int price) {
        int span = 1; // Shuruat me har element ka khud ka span 1 hota hai

        // Jab tak piche choti ya barabar prices hain, unka cumulative span chura lo
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Current price aur uska total calculated span stack me push karo
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */