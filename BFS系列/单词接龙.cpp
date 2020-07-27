/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> hashmap;
		for (auto str : wordList) {
			hashmap[str]++;
		}
		if (hashmap[endWord] == 0) {
			return 0;
		}
		queue<string> que;
		que.push(beginWord);
		int step=0;
		int len = beginWord.size();
		while (!que.empty()) {
			step++; //BFS，遍历完一层step++
			int size = que.size();
			while (size--) {
				string cur = que.front();
				que.pop();
				for (int i = 0; i < len; i++) {
					char c = cur[i]; // 缓存，下面要改变
					for (int j = 'a'; j <= 'z'; j++) {
						if (j == c) continue; // 跳过本身
						cur[i] = j;
						// 如果已经转换到了
						if (cur == endWord)  return step + 1;
						if (!hashmap.count(cur)) continue;
						hashmap.erase(cur);// 访问完就删除，转换的过程中访问过的
						que.push(cur); // 将符合条件的单词节点加入队列
					}
					cur[i] = c;// 可能一个单词可以转换多个单词 ？？，还原原来改变的单词
				}
			}
		}
		return 0; 
    }
};

