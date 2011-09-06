#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h> 

using namespace std;
vector <string> fibs;

void calc_fibs(){
   fibs.push_back("1");
   fibs.push_back("2");
   //cout << "start: " << fibs[1] << endl;
   int fib_index = 2;
   while(fibs[fib_index- 1].size() < 101){
      int i = fibs[fib_index- 2].size()- 1;
      int j = fibs[fib_index - 1].size()- 1;
      int carry = 0;
      stringstream result;
      while (i >= 0){
         char one = fibs[fib_index - 1].at(j), two = fibs[fib_index - 2].at(i);
         int ans = 0;
         ans = one - '0';
         ans += (two - '0');
         if(carry == 1){
            ans++;
            carry = 0;
         }
         if(ans >= 10){
            carry = 1;
            ans = ans % 10;
         }	
         result << ans;
         i--;
         j--;
      }
      while(j >= 0){
         char one = fibs[fib_index - 1][j];
         int ans = 0;
         ans = one - '0';
         ans += carry;
         carry = 0;
         if(ans == 10){
            carry = 1;
            ans = 0; 
         }
         result << ans;
         j--;
      }
      if(carry == 1){
         result << 1;
      }
      string answer = result.str();
      reverse(answer.begin() ,answer.end());
      //cout << "answer : "   << answer << endl;
      fibs.push_back(answer);
      fib_index++;	
   }	
} 


int check_fib(const string &low, const string &high){
   unsigned int count = 0;
   unsigned int j;
   unsigned int low_length = low.size();
   unsigned int high_length = high.size();
   bool low_passed = true, high_passed = true;
   // cout << "low_length : " << low_length << " high_length: " << high_length << endl;
   for(int i = 0; i < fibs.size(); i++){
      low_passed = false, high_passed = false;
      //cout << " fibs length" << fibs[i].size() << endl;
      if(low_length <= fibs[i].size() && high_length >= fibs[i].size()){
         if(low_length == fibs[i].size()){
            for(j = 0; j < low_length; j++){
               if(fibs[i][j] > low[j]){
                  low_passed = true;
                  break;
               }
               if(fibs[i][j] < low[j]){
                  break;
               }
               if(j == low_length-1){
                  low_passed = true;
               }
            }
         } else {
            low_passed = true;
         }
         if(high_length== fibs[i].size()){
            for(j = 0; j < high_length ; j++){
               if(fibs[i][j] < high[j]){
                  high_passed = true;
                  break;
               }
               if(fibs[i][j] > high[j]){
                  break;
               }
               if(j == high_length-1){
                  high_passed = true;
               }
            }
         } else {
            high_passed = true;
         }
         if(low_passed && high_passed){
            count++;
         }
      }
   }
   return count;
}

int main(void){
   string low, high;
   calc_fibs();
   while(true){
      cin >> low >> high;
      //cout << "low : " << low << " high: " << high << endl;
      if(low[0] == '0' && high[0] == '0'){
         break;
      }
      cout << check_fib(low,high) << endl;
   }
   return 0;
}
