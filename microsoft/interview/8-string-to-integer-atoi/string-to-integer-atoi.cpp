class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        while(s[i]==' ' && i<n) i++;
        if(i==n ) return 0;
        int sign=1;
        if(s[i]=='-'|| s[i]=='+') {
            if(s[i]=='-') sign=-1;
            i++;
            }
        // while(s[i]=='0'&& i<n) i++;
        long long  result=0;
        while(isdigit(s[i]) && i<n){
            result=result*10+(s[i]-'0');
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            i++;
        }

         return static_cast<int>(sign * result);



    }
};