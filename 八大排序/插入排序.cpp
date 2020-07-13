#include<iostream> 
using namespace std; 

class Solution {
public:
        void insertSort(vector<int>& arr) {
               if (arr.size() == 0) {
                       return;
               }
               for (int i = 1; i < arr.size(); i++) {
                       for (int j = i - 1; j >= 0; j--) {
                              if (arr[j] > arr[j + 1]) {
                                      swap(arr[j], arr[j + 1]);
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

