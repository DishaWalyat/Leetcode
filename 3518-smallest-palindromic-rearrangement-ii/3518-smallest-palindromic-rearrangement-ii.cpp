class Solution {
public:
    using ll = long long;

   
    ll comb(int n, int r, ll limit) {
        if (r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= limit) return limit;
        }

        return ans;
    }


    ll countWays(vector<int>& cnt, ll limit) {
        int total = 0;
        for (int x : cnt) total += x;

        ll ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;

            ll cur = comb(rem, x, limit);

            if (ans > limit / cur)
                return limit;

            ans *= cur;

            if (ans >= limit)
                return limit;

            rem -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, long long k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);

        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid = char('a' + i);
        }

        ll totalWays = countWays(half, k);

        if (totalWays < k)
            return "";

        int len = 0;

        for (int x : half)
            len += x;

        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (half[ch] == 0)
                    continue;

                half[ch]--;

                ll ways = countWays(half, k);

                if (ways >= k) {
                    left += char('a' + ch);
                    break;
                }

                k -= ways;
                half[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};