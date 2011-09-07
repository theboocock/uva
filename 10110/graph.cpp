// Core file we will use for the comp.
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

#define DEBUG 0

using namespace std;

void debug(string print){
   if(DEBUG){
      cout << print << endl;
   }
}


void search_this_beatch(int origin, int dest, vector<vector <bool> > &roads, string origin_string, string dest_string){
	queue<pair <int, int> > fringe;
	int count = 0;
	pair <int, int > expanding;
	bool found = false;
	fringe.push(make_pair(origin, count));
	while(!fringe.empty() && !found){
		expanding = fringe.front();
		fringe.pop();
		for(int i = 0;i < roads.size(); i ++){
			if(roads[expanding.first][i] == true){
				if(i == dest){
					cout << "Number of roads needed from " << origin_string << " to " << dest_string << " is " << (expanding.second + 1) << endl;
					found = true;
					break;
				} else {
					fringe.push(make_pair(i, expanding.second + 1));
				}
			}
		}
	}
}

int main(void){
	int num_cities;
	int num_roads;
	int num_cases;
	while(true){
		cin >> num_cities;
		if(num_cities == 0){
			break;
		}
		map<string,int> map_of_cities;
		vector<vector<bool> > roads (num_cities, vector<bool> (num_cities));
		for(int i = 0; i < num_cities; i ++){
			string input;
			cin >> input;
			map_of_cities[input] = i;
			for(int j = 0; j < num_cities; j++){
				roads[i][j] = false;
			}
		}
		vector<string> road_line;
		cin >> num_roads;
		cout << "NUM_ROADS : " << num_roads << endl;
		for(int i = 0; i < num_roads; i++){
			string input;
			cin >> input;
			getline(cin,input);
			cout << input << endl;
			stringstream line(input);
			cout << line.str() << endl;
			string first;
			line >> first;
			road_line.push_back(first);
			int distance;
			while(line >> distance){
				string r;
				line >> r;
				road_line.push_back(r);
			
			}
			for(int x = 0; x < road_line.size(); x++){
				for(int j = x + 1; j < road_line.size();j++){
					int index_x, index_j;
					index_x = map_of_cities.find(road_line[x])->second;
					index_j = map_of_cities.find(road_line[j])->second;
					roads[index_x][index_j] = true;
					roads[index_j][index_x] = true;
				}
			}
			road_line.clear();	
		}
		int queries;
		cin >> queries;
		cout << "queries: " << queries << endl;
		for(int i = 0;i < queries; i++){
			string origin;
			cin >> origin;
			string dest;
			cin >> dest;
			int index_origin, index_dest;
			index_origin = map_of_cities.find(origin)->second;
			index_dest = map_of_cities.find(dest)->second;
			search_this_beatch(index_origin,index_dest,roads,origin,dest);
		}	

	}
	
   	return 0;
}
