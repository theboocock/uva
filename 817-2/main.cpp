#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

string make_string(string &nums, vector<char> &ops){
   char c = nums.at(0);
   char prev_op = 'f';
   int lhs = c - '0';
   int rhs = 0;
   int prev_num = 0;
   bool prev_zero = false;
   bool illegal = false;
   bool mult = false;
   if(lhs == 0){
      prev_zero = true;
   }
   for(unsigned int i = 1; i < nums.size() && !illegal; i++){
      char op = ops[i-1];
      switch(op){
      case '0':
         if(prev_zero){
            illegal = true;
            break;
         }
         c = nums.at(i);
         if(mult){
            rhs *= 10;
            rhs += (c-'0');
         } else {
            lhs *= 10;
            lhs += (c-'0');
         }
         break;
      case '*':
         prev_zero = false;
         c = nums.at(i);
         if(mult){
            lhs *= rhs;
         }
         rhs = (c-'0');
         mult = true;
         if(rhs == 0){
            prev_zero = true;
         }
         break;
      case '-':
         c = nums.at(i);
         prev_zero = false;
         if(mult){
            lhs *= rhs;
         }
         if(prev_op == '+'){
            prev_num += lhs;
         } else if(prev_op == '-'){
            prev_num -= lhs;
         } else {
            prev_num = lhs;
         }
         prev_op = '-';
         lhs = (c-'0');
         if(lhs == 0){
            prev_zero = true;
         }
         mult = false;
         break;
      case '+':
         c = nums.at(i);
         prev_zero = false;
         if(mult){
            lhs *= rhs;
         }
         if(prev_op == '+'){
            prev_num += lhs;
         } else if(prev_op == '-'){
            prev_num -= lhs;
         } else {
            prev_num = lhs;
         }
         prev_op = '+';
         lhs = (c-'0');
         mult = false;
         if(lhs == 0){
            prev_zero = true;
         }
         break;         
      }
   }
   if(!illegal){
      if(mult){
         lhs *= rhs;
      }
      if(prev_op == '+'){
         prev_num += lhs;
      } else if(prev_op == '-'){
         prev_num -= lhs;
      } else {
         prev_num = lhs;
      }
      if(prev_num == 2000){
         stringstream result;
         for(unsigned int i = 0; i < nums.size(); i++){
            result << nums[i];
            if(i < ops.size()){
               if(ops[i] != '0'){
                  result << ops[i];
               }
            }
         }
         return result.str();
      }
   }
   return "";
}

int main(void){
   string input;
   int prob = 1;
   vector<string> answers;
   while(cin >> input){
      answers.clear();
      if(input.compare("=") != 0){
         cout << "Problem " << prob << endl;
         input.erase(input.size()-1);
         if(input.size() >= 4 && input.size() <= 9){
            vector<char> ops(input.size()-1);
            for(int i = 1;i < (int)(pow(4,(input.size()-1))); i++){
               int temp = i;
               for(int j = ops.size()-1; j >= 0; j--){
                  int coeff = (int)(temp/(pow(4,j)));
                  temp = temp % (int)(pow(4,j));
                  if(coeff == 0){
                     ops[j] = '0';
                  } else if(coeff == 1){
                     ops[j] = '*';
                  } else if(coeff == 2){
                     ops[j] = '-';
                  } else if(coeff == 3){
                     ops[j] = '+';
                  } 
               }
               string result = make_string(input, ops);
               if(result.compare("") != 0){
                  answers.push_back(result);
               }
            }
         }
      }else{
         break;
      }
      if(answers.size() == 0){
         cout << "  IMPOSSIBLE" << endl;
      } else {
         sort(answers.begin(), answers.end());
         for(unsigned int i = 0; i < answers.size(); i++){
            cout << "  " << answers[i] << "=" <<  endl;
         }
      }
      prob++;
   }
   return 0;
}
