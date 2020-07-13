
/*
求一个数组中  两个数之和 等于 target 的数， 返回他们的下标位置， 如果不存在就返回-1. 
*/

// 方法一： hashmap 返回位置

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                res.push_back(hashmap[target - nums[i]]);
                res.push_back(i); // 注意这里添加的顺序
                return res;
            }
            hashmap[nums[i]] = i;  // 一边遍历一边存储
        }
        return { -1,-1 };
    }
};

/*python 版本 ,更加直观
class Solution:
    def twoSum(self, nums, target):
        result = []
        for i in range(len(nums)):
            sub = target - nums[i]
            for j in range(i+1,len(nums)):
                if sub == nums[j]:
                    result.append(i)
                    result.append(j)
            
        return result
*/
