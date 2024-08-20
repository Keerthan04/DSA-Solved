class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if (nn == 0) {
            return 1;
        }
        if (nn < 0) {
            //for negative
            x = 1 / x;
            nn = -nn;//so in the next step we can do correct calculations
        }
        //using divide and conquer so to reduce tc to logn
        double half = myPow(x, nn / 2);
        if (nn % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
