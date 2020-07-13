/*
高：就是柱子A的高；
右边界：正好是i（根据单调栈的性质，第i个柱子就是右边第一个矮于A的柱子）；
左边界：单调栈中紧邻A的柱子，如果A已经出栈，那么左边界就是A出栈后的栈顶，
如果A出栈后单调栈为空，那就说明左边没有比A矮的柱子，此时左边界为0。
*/
// 递增栈
class Solution {
public:
        int largetRectangleArea(vector<int> heights) {
               if (heights.size() == 0) return 0;
               int res = 0;
               stack<int> sta;
               heights.push_back(0); // 让最后一个柱子能被处理
               for (int i = 0; i < heights.size(); i++) {
                       while (!sta.empty() && heights[i] < heights[sta.top()]) {
                              int curheight = heights[sta.top()];
                              sta.pop();
                              int width = sta.empty() ? i : i - sta.top() - 1;
                              res = max(res, width * curheight);
                       }
                       sta.push(i);
               }
               return res;
        }
};

// 递减栈
class Solution2 {
public:
        int largestRectangleArea(vector<int>& heights) {
               stack<int> sta;
               int maxarea = 0;
               int i = 0;
               for (i = 0; i < heights.size();)
               {
                       if (sta.empty() || heights[sta.top()] < heights[i])
                       {
                              sta.push(i++);
                       }
                       else
                       {
                              int top = sta.top();
                              sta.pop();
                              int area = heights[top] * (sta.empty() ? i : i - sta.top() -  1);
                              if (maxarea < area)
                              {
                                      maxarea = area;
                              }
                       }
               }
               while (!sta.empty())
               {
                       int top = sta.top();
                       sta.pop();
                       int area = heights[top] * (sta.empty() ? i : i - sta.top() - 1);
                       if (maxarea < area)
                       {
                              maxarea = area;
                       }
               }
               return maxarea;
        }
};