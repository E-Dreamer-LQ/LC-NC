#include<iostream>
#include <vector>
using namespace std; 
class Solution {
public:
        void mergeSort(vector<int> &arr) {
               if (arr.size() == 0 || arr.size() < 2) return;
               SortProcess(arr, 0, arr.size()-1);
        }
        //归并排序主体过程
        void SortProcess(vector<int> &arr, int l, int r) {
               if (r == l) return; // 递归停止
               int mid = l + (r - l)/2;
               SortProcess(arr, l, mid);
               SortProcess(arr, mid + 1, r);
               merge(arr, l, mid, r);
        }
        // 合并过程
        void merge(vector<int> &arr, int l, int mid, int r) {
               vector<int> helper(r - l + 1); // 辅助数组用来存放排序后的数组
               int i = 0;
               // 两个指针
               int p1 = l;
               int p2 = mid + 1;
               while (p1 <= mid && p2 <= r) {
                       if (arr[p1] < arr[p2]) {
                              helper[i++] = arr[p1++];
                       }
                       else {
                              helper[i++] = arr[p2++];
                       }
               }
               while (p1 <= mid) {// 注意这里可以等于
                       helper[i++] = arr[p1++];
               }
               while (p2 <= r) {
                       helper[i++] = arr[p2++];
               }
               // 将辅助数组元素位置拷贝会arr
               for (int i = 0; i < helper.size(); i++) {
                       arr[l + i] = helper[i];
               }
        }
        vector<int> generateRandomArr(int maxsize, int minsize, int length) {
               vector<int> arr(length);
               for (int i = 0; i < length; i++) {
                       arr[i] = rand() % (maxsize - minsize) + minsize + 1;
               }
               return arr;
        }
};