class Solution {
public:
    long long oddcnt(int n){
        //even
        if(n%2==0) return (long long)n/2;
        else return (long long)(n/2)+1;
    }
    long long evencnt(int n){
        return (long long)n/2;
    }
    long long flowerGame(int n, int m) {
        long long odd_n=oddcnt(n);
        long long even_n=evencnt(n);
        long long odd_m=oddcnt(m);
        long long even_m=evencnt(m);
        return (odd_n*even_m)+(odd_m*even_n);

        
    }
};