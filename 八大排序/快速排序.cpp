#include <iostream>
#include <vector>
using namespace std; 

class QuickSort {
public:
        vector<int> partition(vector<int>& arr1, int l, int r) {
               int less = l - 1;// 向左扩 开始的位置
               int more = r;
               int s;
               while (l < more) {
                       if (arr1[l] < arr1[r]) {
                              //该元素小于arr[r]，将之放置在小于区域
                              //放置方法：将该元素与小于区域的右边界的下一个元素（l+1）交换，
                              //然后将l指针与less指针后移 （当前数与小于区域后一个数交换
                              ++less;
                              s = arr1[less];  
                              arr1[less] = arr1[l];
                              arr1[l] = s;
                              l++;
                       }
                       else if (arr1[l] > arr1[r]) {
                              //该元素大于arr[r]，将之放置在大于区域
                              //放置方法：将该元素与大于区域的左边界的下一个元素（more-1）交换，
                              //more指针前进，这便完成了大于区域的扩大
                              --more;
                              s = arr1[more];
                              arr1[more] = arr1[l];
                              arr1[l] = s;
                       }
                       else {
                              l++;  //   如果相等就直接 将当前值跳到下一个
                       }
               }
               swap(arr1[more], arr1[r]);
               vector<int> p(2);
               p[0] = less + 1;
               p[1] = more;
               return p;
        }
        void SortProcess(vector<int>& arr1, int l, int r)
        {
               if (l < r) {
                       swap(arr1[l + rand() % (r - l)], arr1[r]); // 随机快排
                       vector<int> p = partition(arr1, l, r);//返回的是位置，小于值得右边和大于值得左边
                       //cout<< p.size()<<endl;
                       SortProcess(arr1, l, p[0] - 1);
                       SortProcess(arr1, p[1] + 1, r);
               }
        }
        void quickSort(vector<int>& arr1) {
               if (arr1.empty() == true || arr1.size() < 2)
               {
                       return;
               }
               SortProcess(arr1, 0, arr1.size() - 1);
        }
        vector<int> generateRandomArr(int maxsize, int minsize, int length) {
               vector<int> arr(length);
               for (int i = 0; i < length; i++) {
                       arr[i] = rand() % (maxsize - minsize) + minsize + 1;
               }
               return arr;
        }
};