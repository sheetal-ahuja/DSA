class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for(auto it: s){
            if(it == '('){
                st.push(it);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }
        return st.size()+count;
    }
};


// SC-> O(1) TC-> O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0; int add = 0;

        for(auto it: s){
            if(it =='('){
                balance++;
            }
            else{
                if(balance>0) balance--;
                else add++;
            }
        }
        return add+balance;
    }
};
