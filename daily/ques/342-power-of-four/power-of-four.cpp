class Solution {
public:
    bool check(int a){
        if(a==1) return true;
        if(a <= 0 || a%4!=0) return false;
        if(a%4==0){
            a=a/4;
        }
        return check(a);
    }
    bool isPowerOfFour(int n) {
        return check(n);       
    }
};