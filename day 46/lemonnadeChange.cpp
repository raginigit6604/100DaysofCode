#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five >0){ // check 5 is available or not
                ten++;
                five--;
                }
              else{
                return false;
               }
            }
            else if(five > 0 && ten > 0){ // for 20 dollar bill
               five--;
               ten--;
            }
            else if(five >= 3){ //for case 5 5 5 available 
                five -= 3;
            }
            else{
                return false;
            }
        }
        return true;      
    }
};
int main(){
    vector<int> arr = {5,5,5,10,20};
    Solution s;
    int ans = s.lemonadeChange(arr);
    if(ans == true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}