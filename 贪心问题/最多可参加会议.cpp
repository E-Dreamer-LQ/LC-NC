/*
题目描述： 

给你一个数组 events，其中 events[i] = [startDayi, endDayi] ，表示会议 i 开始于 startDayi ，结束于 endDayi 。

你可以在满足 startDayi <= d <= endDayi 中的任意一天 d 参加会议 i 。注意，一天只能参加一个会议。

请你返回你可以参加的 最大 会议数目。

*/ 

// 方法一：排序： 结束时间升序排序即可，然后用个set，对区间从前往后遍历，如果这个点上没安排会议就添加进去

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& e1, const vector<int>& e2) {
           return e1[1] < e2[1];
        });
        unordered_set<int> res;
        for(vector<int> e: events) {
            for(int d = e[0]; d <= e[1]; d++) {
                if(res.find(d) == res.end()) {
                    res.insert(d);
                    break;
                }
            }
        }
        return res.size();
    }
};


/*
方法二： 
按照会议start对 events 升序排序
按日期time进行扫描
将time时开始的会议都加入到优先队列（队列存储的是会议结束end时间）
优先队列（小顶堆）把结束日期早的先出队，参加该会议
time++，新的一天，先把优先队列里已经过期的会议删除
*/ 

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int,vector<int>, greater<int>> q;//小顶堆，结束时间早的，先出队
        int count = 0, i = 0, time = 0;
        while(i < events.size() || !q.empty())
        {
            time++;
            while(!q.empty() && q.top() < time)//结束时间过去了，该会议删除
                q.pop();
            while(i < events.size() && events[i][0] == time)
            {
                q.push(events[i][1]);//time时间，会议i开始了，把他的结束时间push进去
                i++;
            }
            if(!q.empty())
            {
                count++;
                q.pop();//最早结束的先参加
            }
        }
        return count;
    }
};

