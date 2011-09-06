#include <iostream>
#include <map> 
#include <vector>
using namespace std;
map<int, int> memory;

int do_something(vector <int> &input){
   int size = input.size()-1;
   int i = size, best = 1;
   memory[i] = 1;
   while(i > 0){
      i--;
      int curr_best = 1;
      int i2 = i+1, curr_missile = input[i];
      while(i2 <= size){
         int check_missile = input[i2];
         if(curr_missile >= check_missile){
            if(curr_best < memory[i2]+1){
               curr_best = memory[i2]+1;
            }
         }
         i2++;
      }
      memory[i] = curr_best;
      if(curr_best > best){
         best = curr_best;
      }
   }
   return best;

}

int main(void){
   int intercept, best, test =1;
   vector<int> input;
   while(cin >> intercept){
      if(intercept != -1){
         input.push_back(intercept);	
      }
      else{
         if(input.size() != 0){
            best = do_something(input);
            input.clear();
            if(test > 1){
               cout << "\n\n";
            }
            cout << "Test #" << test << ":" << endl;
            cout << "  maximum possible interceptions: " << best ;
            test++;
         }
      }
   }
   cout << endl;
   return 0;
}
