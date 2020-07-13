#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
        // 建立大根堆
        void heapInsert(vector<int>& array, int index) {
               while (array[index] > array[(index - 1) / 2]) {
                       swap(array[index], array[(index - 1) / 2]);// (index - 1) / 2 是 根节点， index是儿子
                       index = (index - 1) / 2;
               }
        }
        //大跟堆中有值发生变化，调整成依旧是大根堆
        void heapify(vector<int>& arr, int index, int heapsize) {
               int left = index * 2 + 1;//左孩子节点
               while (left < heapsize) {
                       int largest;
                       if (left + 1 < heapsize && arr[left + 1] > arr[left])
                              largest = left + 1;  // 较大的子树
                       else
                              largest = left;
                       if (arr[largest] < arr[index]) {
                              largest = index;
                       }
                       if (largest == index)// 已经在堆顶了
                              break;
                       swap(arr[largest], arr[index]);
                       //  交换根节点 与 最大儿子 的值，某个孩子比我大，那个孩子的位置就是largest
                       index = largest;
                       left = index * 2 + 1;
               }
        }
        void heapSort(vector<int>& arr)
        {
               if (arr.empty() == true || arr.size() < 2) {
                       return;
               }
               for (int i = 0; i < arr.size(); i++) {
                       heapInsert(arr, i);//变成大根堆
               }
               int heaplength = arr.size();
               swap(arr[0], arr[--heaplength]);
               while (heaplength > 0) {
                       heapify(arr, 0, heaplength);
                       swap(arr[0], arr[--heaplength]);
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