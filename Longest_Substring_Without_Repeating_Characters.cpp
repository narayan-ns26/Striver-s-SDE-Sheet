#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) 
{ 
        // Brute force approach
        /*
        int cnt;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            unordered_set<char>str;
            cnt = 0;
            for(int j=i;j<s.length();j++)
            {
                if(str.find(s[j])==str.end())
                {
                    cnt++;
                    str.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
        */
        
        // sliding window
        int left = 0;
        int ans = 0;
        unordered_set<char>my_set;
        for(int right=0;right<s.length();right++)
        {
            if(my_set.find(s[right])==my_set.end())
            {
                my_set.insert(s[right]);
            }
            else
            {
                // Till the current character is present in the set, remove everything
                while(my_set.find(s[right]) != my_set.end())
                {
                    my_set.erase(s[left]);
                    left++;
                }
                my_set.insert(s[right]);
            }
            ans = max(ans, (right-left)+1);
        }
        return ans;
}