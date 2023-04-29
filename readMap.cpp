#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

// Shortest Path
void shortestPath(map<string, list<string>> &myMap, vector<string> &path,string src, string dst) {
  
  map<string, bool> visited;
  map<string, string> parent;
  queue<string> q;

  q.push(src);
  visited[src] = 1;
  parent[src] = -1;

  while (!q.empty()) {
    string frontNode = q.front();
    q.pop();
    for (auto it : myMap[frontNode]) {
      if (!visited[it]) {
        visited[it] = 1;
        parent[it] = frontNode;
        q.push(it);
      }
    }
  }

  string currentNode = dst;
  path.push_back(dst);

  while (currentNode != src) {
    currentNode = parent[currentNode];
    path.push_back(currentNode);
  }

  reverse(path.begin(), path.end());
}


int main() {
  map<string, list<string>> myMap;
  ifstream file("myMap.txt");
  vector<string> path;
  string line;
  while (getline(file, line)) {
    size_t pos = line.find(":");
    string key = line.substr(0, pos);
    string val = line.substr(pos + 1);
    size_t start_pos = 0, end_pos = 0;
    list<string> values;
    while ((end_pos = val.find(',', start_pos)) != string::npos) {
      values.push_back(val.substr(start_pos, end_pos - start_pos));
      start_pos = end_pos + 1;
    }
    values.push_back(val.substr(start_pos));
    myMap[key] = values;
  }

//   for (auto it = myMap.begin(); it != myMap.end(); it++) {
//     cout << it->first << " : ";
//     for (auto value_it = it->second.begin(); value_it != it->second.end();
//          value_it++) {
//       cout << *value_it << ", ";
//     }
//     cout << endl;
//   }


shortestPath(myMap, path, "JNTU College", "Ameerpet");
    for (auto it : path) {
    cout << it << " ->";
  }
  return 0;
}
