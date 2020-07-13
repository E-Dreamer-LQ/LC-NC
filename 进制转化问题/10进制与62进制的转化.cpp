#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
//将任意字符转换为十进制，其中a-z代表10-35，A-Z代表36-61，用对应的ASCII码调整就好
char int2char(int n)
{
        if (n >= 0 && n <= 9)return '0' + n;
        if (n >= 10 && n <= 35)return 'a' + (n - 10);
        else return 'A' + (n - 36);
}
string radix10To62(int n)
{
        char buf[1024] = { 0 };
        int index = 0;
        while (n > 0)
        {
               int m = n % 62;
               n -= m;
               n /= 62;
               buf[index++] = int2char(m);
        }
        string str = buf;
        string str2 = string(str.rbegin(), str.rend());
        return str2;
}

// 62 进制转 10进制
long radix62To10(string num) {
        int length = num.length();
        long out = 0;
        for (int i = 0; i < length; i++) {
               char c = num[i];
               int charNum;
               if (c >= '0' && c <= '9') {
                       charNum = c - '0';
               }
               else if (c >= 'a' && c <= 'z') {
                       charNum = c - 'a' + 10;
               }
               else if (c >= 'A' && c <= 'Z') {
                       charNum = c - 'A' + 10 + 26;
               }
               else {
                       printf("invalid radix62 char: " + c);
               }
               out = out * 62 + charNum;
        }
        return out;
}



