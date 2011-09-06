#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int calc_vectors(vector<int> &nums, vector<char> &ops){
   int i = 0;
   while(ops[i] != '*' && i < ops.size()){
      i++;
   }
   if(i != ops.size()){
      int temp = nums[i] * nums[i+1];
      nums.erase(nums.begin()+i);
      nums.erase(nums.begin()+i);
      ops.erase(ops.begin()+i);
      nums.insert(nums.begin()+i, temp);
      return calc_vectors(nums, ops);
   } else {
      int i = 0;
      while(ops.size() > 0){
         int temp;
         if(ops[i] == '+'){
            temp = nums[i] + nums[i+1];
            nums.erase(nums.begin()+i);
            nums.erase(nums.begin()+i);
            ops.erase(ops.begin()+i);
            nums.insert(nums.begin()+i, temp);
         } else {
            temp = nums[i] - nums[i+1];
            nums.erase(nums.begin()+i);
            nums.erase(nums.begin()+i);
            ops.erase(ops.begin()+i);
            nums.insert(nums.begin()+i, temp);
         }
      }
      return nums[0];
   }
}

int make_vectors(string input){
   vector<int> nums;
   vector<char> ops;
   string lhs;
   int temp;
   for(int i = 0; i < input.size(); i++){
      switch(input[i]){
      case '*':
         temp = atoi(lhs.c_str());
         nums.push_back(temp);
         ops.push_back('*');
         lhs.clear();
         break;
      case '-':
         temp = atoi(lhs.c_str());
         nums.push_back(temp);
         ops.push_back('-');
         lhs.clear();
         break;
      case '+':
         temp = atoi(lhs.c_str());
         nums.push_back(temp);
         ops.push_back('+');
         lhs.clear();
         break;
      default:
         lhs += input[i];
      }
   }
   temp = atoi(lhs.c_str());
   nums.push_back(temp);
   if(ops.size() > 0){
      return calc_vectors(nums, ops);
   } else {
      return nums[0];
   }
}

string make_string(vector<int> &nums, vector<char> &ops){
   int lhs = nums[0];
   stringstream result;
   bool prev_zero = false;
   bool illegal = false; 
   if(nums[0] == 0){
      prev_zero = true;
   }
   result << lhs;
   for(int i = 1; i < nums.size() && !illegal; i++){
      char op = ops[i-1];
      switch(op){
      case '0':
         if(prev_zero){
            illegal = true;
         }
         result << nums[i];
         break;
      case '*':
         prev_zero = false;
         result << "*";
         result << nums[i];
         if(nums[i] == 0){
            prev_zero = true;
         }
         break;
      case '-':
         prev_zero = false;
         result << "-";
         result << nums[i];
         if(nums[i] == 0){
            prev_zero = true;
         }
         break;
      case '+':
         prev_zero = false;
         result << "+";
         result << nums[i];
         if(nums[i] == 0){
            prev_zero = true;
         }
         break;         
      }
   }
   if(!illegal){
   int answer = make_vectors(result.str());
   if(answer == 2000){
      return result.str();
   } else {
      return "";
   }
   }
   return "";
   //cout << "result: " << result.str() << " = " << answer << endl;
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
         if(input.size() >= 4){
            vector<int> numbers;       
            for(int i = 0; i < input.size(); i++){
               char temp = input.at(i); 
               numbers.push_back(atoi(&temp));
            }
            vector<char> ops(numbers.size()-1);
            for(int i = 0;i < (int)(pow(4,(numbers.size()-1))); i++){
               int temp = i;
               for(int j = ops.size()-1; j >= 0; j--){
                  //int temp = i / (int)(pow(4,j));
                  int coeff = (int)(temp/(pow(4,j)));
                  temp = temp % (int)(pow(4,j));
                  //temp = temp % 4;
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
               //cout << result << endl;
                string result = make_string(numbers, ops);
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
         //for(int i = 0; i < answers.size(); i++){
         //   cout << "  " << answers[i] << endl;
         //}
         sort(answers.begin(), answers.end());
         //cout << "  sorted:" << endl;
         for(int i = 0; i < answers.size(); i++){
            cout << "  " << answers[i] << "=" <<  endl;
         }
      }
      prob++;
   }
   return 0;
}
