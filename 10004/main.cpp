// Core file we will use for the comp.
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>

#define DEBUG 0

using namespace std;

void debug(string print){
   if(DEBUG){
      cout << print << endl;
   }
}

int main(void){
   int n, m;
   while(true){
      cin >> n;
      if(n == 0){
         break;
      } else{
         bool illegal = false;
         cin >> m;
         vector< vector<bool> > graph(n,vector<bool>(n));
         for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
               graph[i][j] = false;
            }
         }
         for( int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            graph[x][y] = true;
            graph[y][x] = true;
         }
         vector<int> visited(n);
         for(int i = 0; i < n; i++){
            // 0 = unvisted, 1= white, 2 = red
            visited[i] = 0;
         }
         stack<int> fringe;
         fringe.push(0);
         //0= unvisited, 1= red, 2= white
         visited[0] = 1;
         while(!fringe.empty() && !illegal){
            int curr = fringe.top();
            fringe.pop();
            int colour = visited[curr];
            for(int i = 0; i < n; i++){
               if(graph[curr][i]){
                  if(visited[i] == 0){
                     if(colour == 1){
                        visited[i] = 2;
                     } else{
                        visited[i] = 1;
                     }
                     fringe.push(i);
                  } else if(visited[i] == colour){
                     illegal = true;
                     break;
                  }
               }
            }
         }
         if(illegal){
            cout << "NOT BICOLORABLE." << endl;
         } else{
            cout << "BICOLORABLE." << endl;
         }
      }
   }
   return 0;
}
