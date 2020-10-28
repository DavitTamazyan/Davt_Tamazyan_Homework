// Runtime: 4 ms, faster than 13.04% of C++ online submissions for Pow(x, n).
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
       if(x == 1){
           return 1;
       }
        
        if(x == -1){
           return (n % 2)? -1 : 1;
       }
        
       if (n == 0){
           return 1;
       }  else if(n > 0) {
           double result = x;
           for (int  i = 0;  i < n - 1; ++i){
               result *= x;
               if (!result)
                   return 0;
           }
           return result;
       } else{
           double result = 1 / x;
           for (int  i = 0;  i < -(n + 1); ++i){
               //cout << result << endl;
               result *= 1 / x;
               if (!result)
                   return 0;
           }
           
           return result;
       }
    }
};
