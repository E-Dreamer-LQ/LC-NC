#include <iostream>
#include <vector>
#include<stack>
#include <algorithm>
using namespace std; 


int maxRecFromBottom(vector<int>& heights) {
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
int maxRecSize(vector<vector<int>>& map) {
	if (map.size() == 0 || map[0].size() == 0) {
		return 0; 
	}
	int maxArea = 0; 
	vector<int> height(map[0].size()); 
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			height[j] = map[i][j] == 0 ? 0 : height[j] + 1; 
		}
		maxArea = max(maxArea, maxRecFromBottom(height));
		//maxArea = max(maxArea, largetRectangleArea(height));
	}
	return maxArea; 
}


int main() {
	vector<vector<int>> map{ {1, 0, 1, 1 }, {1, 1, 1 ,1} ,{1, 1, 1, 0} }; 
	int maxArea = maxRecSize(map); 

	cout << maxArea << endl; 

}

