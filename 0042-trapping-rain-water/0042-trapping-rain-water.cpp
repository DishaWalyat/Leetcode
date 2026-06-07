class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // Indices store karega (Decreasing Order me)
        int total_water = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            // Jab bhi koi badi building mile jo stack ke top se unchi ho
            while (!st.empty() && height[i] > height[st.top()]) {
                
                int bottom_idx = st.top(); // Gaddhe ka floor
                st.pop(); 

                // Agar left me koi building hi nahi bachi, toh paani ruk nahi sakta
                if (st.empty()) break;

                int left_idx = st.top(); // Left deewar
                
                // Horizontal calculations
                int width = i - left_idx - 1;
                int bounded_height = min(height[left_idx], height[i]) - height[bottom_idx];

                total_water += width * bounded_height;
            }
            
            // Agar building choti ya barabar hai, toh bas chupchaap index push karo
            st.push(i);
        }
        return total_water;
    }
};