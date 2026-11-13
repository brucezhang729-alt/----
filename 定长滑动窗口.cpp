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

https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/ //  几乎唯一子数组的最大和Q

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long sum=0,ret=0;
        unordered_map<int,int> Countmap;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            Countmap[nums[i]]++;
            int left = i-k+1;
            
            if(left<0) continue;
            
            if(Countmap.size()>=m) ret=max(ret,sum);
            
            int out=nums[left];
            sum-=out;
            if(--Countmap[out]==0) Countmap.erase(out);
            
        }
        return ret;
    }
};

https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/  // 长度为 K 的最大不同子数组和

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0,ret = 0;
        unordered_map<int,int>CountMap;
        
        for(int right = 0;right<n;right++)
        {
            sum+=nums[right];
            CountMap[nums[right]]++;

            int left = right-k+1;
            if(left<0) continue;

            if(CountMap.size()==k) ret = max(ret,sum);

            sum-=nums[left];
            if(--CountMap[nums[left]]==0) CountMap.erase(nums[left]);
        }

        return ret;
       
        
    }
};

https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/  //  从卡牌中获得的最大点数

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int AllSum = 0;
    for(auto&e:cardPoints)
    {
        AllSum+=e;
    }
    if(k==cardPoints.size()) return AllSum;
    long long sum = 0,ret = INT_MAX;
    for(int right = 0;right<cardPoints.size();right++)
    {
        sum+=cardPoints[right];
        int left = right-(cardPoints.size()-k)+1;
        if(left<0) continue;  
        ret = min(sum,ret);
        sum-=cardPoints[left];
    }
    return AllSum-ret;
}
};

https://leetcode.cn/problems/grumpy-bookstore-owner/  // 生气的书店老板

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int OriginSum = 0;
        for(int i = 0;i<customers.size();i++)
        {
            if(grumpy[i]==0) OriginSum+=customers[i];
        }
      
        long NewSum = 0,ret = 0;
        for(int right = 0;right<customers.size();right++)
        {
            if(grumpy[right]==1) NewSum+=customers[right];

            int left = right-minutes+1;
            if(left<0) continue;
            if(NewSum>ret) ret = max(ret,NewSum);
            

            if(grumpy[left]==1) NewSum-=customers[left];

        }
        return OriginSum+ret;
    }
};

https://leetcode.cn/problems/minimum-discards-to-balance-inventory/   // 平衡库存的最少丢弃次数

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> cnt;
        int ret = 0;
        int n = arrivals.size();

        vector<int> keep(n, 0); // keep[i] = 1 表示这个位置的物品被保留

        for (int i = 0; i < n; i++) {
            int x = arrivals[i];

            // 如果当前窗口中 x 已经有 m 个，就丢弃当前物品
            if (cnt[x] == m) {
                ret++;
            } else {
                cnt[x]++;
                keep[i] = 1;
            }

            // 维护窗口大小，移除 i-w+1 这个位置
            int left = i - w + 1;
            if (left >= 0 && keep[left]) {
                cnt[arrivals[left]]--;
            }
        }

        return ret;
    }
};