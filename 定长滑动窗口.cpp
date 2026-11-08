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

https://leetcode.cn/problems/maximum-average-subarray-i/  //  子数组最大平均数

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = INT_MIN,sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
            int left = i-k+1;

            if(left<0) continue;
            
            ret = max(ret,sum);

            sum-=nums[left++];
        
        }
        return(double)ret/k;
    }
};

https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/  // 大于等于阈值的子数组数目

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0,sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=arr[i];
            int left = i-k+1;
            if(left<0) continue;

            if(sum>=threshold*k) count++;
            
            sum-=arr[left];
            
        }
        return count;
    }
};

http://leetcode.cn/problems/k-radius-subarray-averages/description/ //  K 半径子数组的平均值

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long sum = 0;
        vector<int>args(nums.size(),-1);
        for(int right = 0;right<nums.size();right++)
        {
            sum+=nums[right];
            if(right<2*k) continue;
            args[right-k]=sum/(2*k+1);
            sum-=nums[right-2*k];
        }
        return args;
    }
};

https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/descript  // ion/  // 得到 K 个黑块的最少涂色次数

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0,ret = INT_MAX/2;
        for(int right = 0;right<blocks.size();right++)
        {
            if(blocks[right]=='W') count++;
            int left = right-k+1;
            if(left<0) continue;
            ret = min(ret,count);
            if(blocks[left++]=='W') count--;
        }   
        return ret;
    }
};

