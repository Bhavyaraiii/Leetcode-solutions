class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // cnt[g] = numbers divisible by g
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                cnt[g] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        // Inclusion-Exclusion
        for (int g = mx; g >= 1; g--) {
            long long pairs = cnt[g] * (cnt[g] - 1) / 2;
            for (int j = 2 * g; j <= mx; j += g)
                pairs -= exact[j];
            exact[g] = pairs;
        }

        vector<long long> pref(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (pref[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};