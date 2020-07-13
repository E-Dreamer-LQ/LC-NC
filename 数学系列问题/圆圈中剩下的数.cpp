/*
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

 

示例 1：

输入: n = 5, m = 3
输出: 3


示例 2：

输入: n = 10, m = 17
输出: 2
*/ 

// 超时题解，直观
class Solution {
public:
        int findLastNumber(int n, int m) {
               if (n < 1 || m < 1) return -1;
               vector<int> array(n);
               int i = -1, step = 0, count = n;
               while (count > 0) {//跳出循环时将最后一个元素也设置为了-1
                       i++;           //指向上一个被删除对象的下一个元素
                       if (i >= n) i = 0;   //模拟环。
                       if (array[i] == -1) continue;  //跳过被删除的对象。
                       step++;                     //记录已走过的。
                       if (step == m) {             //找到待删除的对象
                              array[i] = -1;
                              step = 0;   // 删除当前后，需要重新计数
                              count--;    // 人数变少
                       }
               }
               return i; //返回跳出循环时的i,即最后一个被设置为-1的元素
        }
};


// 正确题解
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        // 最后一轮剩下2个人，所以从2开始反推
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
}

