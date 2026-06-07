class Solution {
public:
    // Pichle question ka ekdum same code (Histogram Master)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Yeh hamare histogram ki heights ko track karega
        vector<int> heights(cols, 0);
        int max_total_rectangle = 0;

        // Row-by-Row niche ghumenge
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Agar '1' mila toh deewar unchi karo, agar '0' mila toh deewar khadbadayi (0 karo)
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Is row ka jo histogram bana, uska area nikal lo aur update karo
            int current_row_area = largestRectangleArea(heights);
            max_total_rectangle = max(max_total_rectangle, current_row_area);
        }

        return max_total_rectangle;
    }
};