https://leetcode.cn/problems/longest-substring-without-repeating-characters/  // 无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> Countmap;
        int left=0,len=0,ret=0;
        for(int right=0;right<n;right++)
        {
            char in=s[right];
            Countmap[s[right]]++;
            while(Countmap[s[right]]>1)
            {
                char out=s[left];
                if(--Countmap[s[left]]==0) Countmap.erase(s[left]);
                left++;
            }
            len=right-left+1;
            ret=max(ret,len);
        }
        return ret;
    }
};

https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/ // 出现两次的最长子串

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left = 0,len = 0;
        unordered_map<char,int>CountMap;
        for(int right = 0;right<n;right++)
        {
            CountMap[s[right]]++;
            while(CountMap[s[right]]>2)
            {
                if(--CountMap[s[left]]==0) CountMap.erase(s[left]);
                left++;
            }
            len = max(len,right-left+1);
        }
        return len;
    }
};

https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/  // 删掉一个元素后全为1的最长子数组

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 思路：维护一个窗口，窗口内0出现次数大于1，出窗口
        int n = nums.size();
        int left = 0, len = 0;
        unordered_map<int,int> Countmap;
        for(int right = 0; right < n; right++)
        {
            Countmap[nums[right]]++;
            while(Countmap[0] > 1)
            {
                // 自增操作分离
                if(--Countmap[nums[left]] == 0) Countmap.erase(nums[left]);
                left++;
            }
            len = max(right - left + 1, len);
        }
        return len - 1;
    }
};

https://leetcode.cn/problems/minimum-removals-to-balance-array/description/  // 使数组平衡的最小移动数目

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0,left = 0,n = nums.size();
        for(int right = 0;right<n;right++)
        {
            //正难则反：直接去寻找应该删除最大值还是最小值，来寻找最小的移除数目比较困难
            //反向思考，找到最大的合法窗口，用数组长度减去窗口大小即为答案
            while(right<n&&(long long)nums[left]*k<nums[right])
            {
                left++;
            }
            count = max(count,right-left+1);
        }
        return n-count;
    }
};