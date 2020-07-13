/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：答案中不可以包含重复的四元组。
示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
[-1, 0, 0, 1],
[-2, -1, 1, 2],
[-2, 0, 0, 2]]

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-3;i++) // 这里可以直接 nums.size() 约束
        {
            if(nums[i]>target&&target>0) break; // 优化 
            if(i>0 && nums[i]==nums[i-1])
                continue;    // 去重
            for(int j=i+1;j<nums.size()-2;j++)   // 这里可以直接 nums.size() 约束
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;  // 去重
                int l=j+1;  
                int r=nums.size()-1;
                while(l<r)   // 二分法
                {
                    if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                        l++;
                    else if(nums[i]+nums[j]+nums[l]+nums[r]>target)
                        r--;
                    else
                    {
                        vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                        res.push_back(temp);
                        l++;
                        r--;
                        while  (l < nums.size() && nums[l] == nums[l-1]){
                            l++;  // 去重
                        }
                        while (r > l && nums[r] == nums[r+1]) {
                            r--; // 去重
                        }
                    }
                }
            }
        }
        return res;
    }
};

