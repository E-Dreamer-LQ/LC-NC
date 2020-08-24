/*
问题描述：
输入N表示N节课，接下来输入N行每行输入课程的开始时间和结束时间，求最多的时候有几节课时间重了。
输入示例 ：
4
1 4
1 2
2 3
3 4
输出：2
*/ 

// 解法一； 考虑一个时间段同时有几节课在上，在所有开始和结束的时间中遍历，如果开始一节课则同时上的课数目+1，结束一节课，则同时上的课数目-1

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    int a, b;
    for(int i=0;i<n;i++)
    {
        cin >>a>>b;
        start[i] = a;
        end[i] = b;
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0, j=0, k=0, res=0;
    while(i<n)
    {
        if (start[i]<end[j])
        {
            // 说明该在start[i]这个时段有课开了
            k += 1;
            i +=1;
            res = max(k, res);
        }
        else
        {
            j+=1;
            k-=1;
        }
    }
    cout << res << endl;
    return 0;
}

// 解法二： 

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>>range(n);
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        range[i].first = a;
        range[i].second = b;
    }
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    sort(range.begin(),range.end());
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(range[0].second);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        while (q.top() <= range[i].first)
            q.pop();
        q.push(range[i].second);           // q 存储的就是在同一个区间能容下的最大重叠区间数
        ans = max(ans, (int)q.size());
    }
    cout << ans << endl;
    return 0;
}

