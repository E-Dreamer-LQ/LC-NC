// 使用单调队列的滑动窗口
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
           while (!data.empty() && data.back() < n) {
                   data.pop_back();
           }
           data.push_back(n);
    }
    int max() {
           return data.front();
    }
    void pop(int n) {
           if (!data.empty() && data.front() == n) {
                   data.pop_front();
           }
    }
};
class Solution {
public:
    // 使用单调队列
    vector<int> maxWindowSlide(vector<int>& nums, int k) {
           vector<int> res;
           MonotonicQueue window;
           for (int i = 0; i < nums.size(); i++) {
                   if (i < k - 1) {
                          window.push(nums[i]);
                   }
                   else {
                          window.push(nums[i]);
                          res.push_back(window.max());
                          window.pop(nums[i-k+1]);
                   }
           }
           return res;
    }
}

// 使用双端队列的滑动窗口
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for (unsigned int i = 0; i < num.size(); ++i) {
            while (s.size() && num[s.back()] <= num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
                s.pop_back();
            while (s.size() && i - s.front() + 1 > size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
                s.pop_front();
            s.push_back(i);//把每次滑动的num下标加入队列
            if (size && i + 1 >= size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back(num[s.front()]);
        }
        return res;
    }
};
