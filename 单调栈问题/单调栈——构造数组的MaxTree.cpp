#include <iostream>
#include <vector>
#include <stack>
using manamespace std;
/*
给定一个无重复元素的数组A和它的大小n，请返回一个数组，
其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，
若为根则值为-1。
测试样例：
[3,1,4,2],4
返回：[2,0,-1,2]
*/
vector<int> buildMaxTree(vector<int> arr, int n) {
        if (n <= 0) {
               return vector<int>();
        }
        vector<int> res;  // 数组元素在树中父亲节点的编号
        stack<int> s;     // 栈 以递减方式存放元素值的位置index
        for (int i = 0; i < n; ++i) {
               int pos = -1; // 根编号为-1
               // 当前访问的元素比栈顶大 栈中元素需要出栈
               while (!s.empty() && arr[i] > arr[s.top()]) {
                       int tmp = s.top(); // 需要弹出的数
                       s.pop();
                       if (res[tmp] == -1 || arr[i] < arr[res[tmp]]) {
                              res[tmp] = i;  // 当前就是父节点
                       }
               }
               // 找到了最近的比A[i]大的数
               if (!s.empty()) {
                       pos = s.top();
               }
               s.push(i);
               res.push_back(pos);
        }
        return res;
}