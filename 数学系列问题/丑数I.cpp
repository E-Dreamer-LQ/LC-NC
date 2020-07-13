/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
*/ 
class Solution {
public:
    // 三指针法
    int GetUglyNumber_Solution(int index) {
        if (index < 7)return index;  // 必须加这句，不然就错了
        int i2=0,i3=0,i5=0;
        vector<int> nums(index);
        nums[0] = 1;
        for (int i=1;i< index;i++){
            nums[i] = min(2*nums[i2],min(3*nums[i3],5*nums[i5]));
            if (nums[i] == 2*nums[i2]){
                i2++;
            }
            if (nums[i] == 3*nums[i3]){
                i3++;
            }
            if (nums[i] == 5*nums[i5]){
                i5++;
            }
        }
        return nums[index-1];
    }
};