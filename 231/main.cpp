#include <iostream>
#include <map> 
#include <vector>
using namespace std;
map<int, int> memory;

void do_something(vector <int> &input){
	int i = 1, curr_best = 1;
	int size = input.size();
	memory[1] = 1;
	while(i <= size){
		i++;
		curr_best = 1;
		int index2 = i, curr_missile = input[size-1];
		while(curr_best < index2){
			if(curr_missile > input[index2-1] && 
				curr_best < memory[index2-1]+1){
				curr_best = memory[index2-1]+1;
			}
			index2--;
		}
	}
	cout << "current best: " << curr_best;

}

int main(void){
	int intercept;
	vector<int> input;
	while(cin >> intercept){
		cout << intercept;
		if(intercept != -1){
			input.push_back(intercept);	
		}
		else{
			do_something(input);
			input.clear();
		}

	}
	return 0;
}
