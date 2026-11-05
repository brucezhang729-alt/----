https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/  // 定长子串中元音的最大数目

class Solution {
public:
    int maxVowels(string s, int k) {
    int ret = 0,count = 0;
    int left = 0;
    for(int right = 0;right<s.size();right++)
    {
        char in = s[right];
        if(in=='a'||in=='e'||in=='i'||in=='o'||in=='u')
        {
            count++;
        }
        while(right-left+1>k)
        {
            char out = s[left];
            if(out=='a'||out=='e'||out=='o'||out=='i'||out=='u')
            {
                count--;
            }
            left++;
        }
        ret = max(ret,count);
    }
    return ret;
    }
};