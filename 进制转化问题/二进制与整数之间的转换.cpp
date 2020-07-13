#include<iostream>
#include<list>
#include <bitset>
#include <vector>
using namespace std;

// n进制问题
string convertobase2(int num) {
        string res = "";
        if (num == 0) return "0";
        int val = num;
        num = abs(num);
        while (num) {
               res.insert(0, to_string(num % 2));
               num /= 2;
        }
        if (val < 0) res.insert(0, "-");
        return res;
}

// 递归输出二进制函数
void BinaryRecursion(int n) {
        int a;
        a = n % 2;
        n = n >> 1;
        if (n == 0)
               return;
        else
               BinaryRecursion(n);
        cout << a;
}
// 使用容器转换二进制
void BinartVector(int n) {
        int temp;
        temp = n;
        vector<int>  L;
        while (temp !=0) {
               L.push_back(temp % 2);
               temp = temp >> 1;
        }
}
// 一般方法，32位，逐步与1做与运算。
void Binarycout(int n) {
        for (int = 31; i >= 0; i--) {
               cout << (n >> i) & 1;
        }
        cout << endl;
}
// 使用bitset 转换二进制
void Binarybitset(int n) {
        cout << bitset<sizeof(int) * 8>(n) << endl;
}
int main()
{
        int a = 1045, b = 2;
        int c;
        c = a + b;
        cout〈〈"BinaryRecursion(c)：";
        BinaryRecursion(c);
        cout〈 BinaryVector(c);
        cout〈〈"Binarycout(c):";
        Binarycout(c);
        cout〈〈"BinaryBitset(c):";
        Binarybitset(c);
        cout〈〈"BinaryChar(c):";
        BinaryChar(c);
        //cout〈 return 0;
}


