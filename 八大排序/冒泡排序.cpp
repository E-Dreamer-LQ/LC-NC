#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
        void BubbleSort(vector<int>& arr) { //优化版的的冒泡
               for (int i = 0; i < arr.size(); i++) {
                       bool swap_flag = false;
                       for (int j = arr.size()-1; j > i; j--) {
                              if (arr[j-1] > arr[j]) {
                                      swap(arr[j], arr[j -1]);
                                      swap_flag = true;
                              }
                       }
                       if (!swap_flag) {
                              return;
                       }
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

//也可以这样, 大数往后面提
class Solution2 {
public:
        void BubbleSort(vector<int>& arr) { 
               for (int i = 0; i < arr.size(); i++) {
                       for (int j = 0; j < arr.size()-i-1; j++) {
                              if (arr[j] > arr[j+1]) {
                                      swap(arr[j], arr[j +1 ]);
                              }
                       }
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

