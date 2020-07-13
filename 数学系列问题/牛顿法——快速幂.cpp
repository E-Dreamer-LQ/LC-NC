class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0 ;
        if ( n == 0) return 1.0;
        long pos = n > 0 ? 1 : -1 ;
        long long temp = n;
        temp = temp >= 0 ? temp : -temp; // 注意1.0  -2....8 那个例子
        while(temp > 0){
            if (temp&1){
                res = res*x;
            }
            temp >>= 1;
            x = x*x;
        }
        return pos>0 ? res: 1.0/res;
        
    }
};