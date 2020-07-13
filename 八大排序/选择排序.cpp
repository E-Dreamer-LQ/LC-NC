#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
	void SelectionSort(vector<int>& arr) {
		
		for (int i = 0; i < arr.size()-1; i++) {
			int min_index = i; 
			for (int j = i + 1; j < arr.size(); j++) {
				if ( arr[j] < arr[min_index] ) {
					min_index = arr[j] < arr[min_index] ? j : min_index; 
				}
				swap(arr[j], arr[min_index]);
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
void main() {
        Solution S;
        vector<int> arr = S.generateRandomArr(100, 1, 20);
        for (auto s : arr) {
               cout << s;
               cout << " ";
        }
        cout << endl;
        S.SelectionSort(arr);
        for (auto s : arr) {
               cout << s;
               cout << " ";
        }
}

