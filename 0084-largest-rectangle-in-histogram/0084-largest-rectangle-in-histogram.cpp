class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Indices store karega (Increasing Stack)
        int max_area = 0;

        // Loop 'n' tak chalega taaki aakhiri me stack ko empty karne ke liye ek dummy '0' height ka use ho sake
        for (int i = 0; i <= n; i++) {
            // Agar loop khatam ho gaya toh height 0 maan lo taaki bache hue saare elements pop ho sakein
            int current_height = (i == n) ? 0 : heights[i];

            // Jab tak current height stack ke top se choti hai, purane logon ka area calculate karo
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()]; // Jis building ka area nikalna hai
                st.pop();

                // Width calculation
                // Pop hone ke baad agar stack khali hai, matlab left me koi chota hai hi nahi (Width shuruat se chalegi)
                int width = st.empty() ? i : (i - st.top() - 1);

                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
};