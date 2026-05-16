class StockSpanner {
public:

    // {price, span}
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {

        int span = 1;

        // Merge previous smaller/equal prices
        while (!st.empty() && st.top().first <= price) {

            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};