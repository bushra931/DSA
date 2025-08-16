class Solution {
public:
    int maximum69Number (int num) {
        string number=to_string(num);
        for(auto &i :number){
            if(i=='6'){
                i='9';
                break;
            }

        }
        return stoi(number);
        
    }
};