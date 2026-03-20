#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        // 1st approach
        /*
        if (nums.size() == 0)
        return 0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int cnt;
        int ans = 1;
        for (auto x : s)
        {
            cnt = 1;
            int search = x+1;
            while(s.find(search) != s.end())
            {
                cnt++;
                search++;
            }
            ans = max(ans, cnt);
        }
        return ans;
        */
        // Optimal
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s) {
            if(s.find(num - 1) == s.end()) { // start of sequence
                int current = num;
                int streak = 1;

                while(s.find(current + 1) != s.end()) {
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
}