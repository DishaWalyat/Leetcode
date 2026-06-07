class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Vector ko hi stack ki tarah use kar rahe hain

        for (int ast : asteroids) {
            bool destroyed = false;

            // Takkar tabhi hogi jab stack ke top par '+' ho aur incoming '-' ho
            while (!st.empty() && st.back() > 0 && ast < 0) {
                
                // Case 1: Stack ka '+' chota hai, toh wo phoot jayega
                if (st.back() < abs(ast)) {
                    st.pop_back();
                    continue; // While loop dobara chalega agale asteroid se ladne
                }
                // Case 2: Dono barabar hain, toh dono phootenge
                else if (st.back() == abs(ast)) {
                    st.pop_back();
                    destroyed = true; // Incoming bhi khatam
                    break;
                }
                // Case 3: Stack ka '+' bada hai, toh incoming phoot gaya
                else {
                    destroyed = true;
                    break;
                }
            }

            // Agar incoming asteroid bach gaya (kisi se nahi takraya ya sabko phod diya)
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        return st;
    }
};
