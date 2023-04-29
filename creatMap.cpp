#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <fstream>

using namespace std;

// Funtion For Displaying the map
void disList(map<string, list<string>> myMap) {
  for (auto pair : myMap) {
    cout << pair.first << ":- ";
    for (auto stsn : pair.second) {
      cout << stsn << ",";
    }
    cout << endl;
  }
}

// Shortest Path
void shortestPath(map<string, list<string>> &myMap, vector<string> &path,
                  string src, string dst) {
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
  vector<string> ans;
  vector<string> res;
  map<string, bool> dvisited;
  vector<string> path;

  // Red Line List
  list<string> jntuh{"KPHB Colony"};
  list<string> kpgbc{"JNTU College", "Kukatpally"};
  list<string> kktp{"KPHB Colony", "Balanagar"};
  list<string> blngr{"Kukatpally", "Moosapet"};
  list<string> mopt{"Balanagar", "Bharat Nagar"};
  list<string> bhrt{"Moosapet", "Erragadda"};
  list<string> ergd{"Bharat Nagar", "ESI Hospital"};
  list<string> esih{"Erragadda", "S.R Nagar"};
  list<string> srn{"ESI Hospital", "Ameerpet"};
  list<string> ampt{"BGMPT", "Punjagutta", "MDHN", "S.R Nagar"};
  list<string> pjgt{"Ameerpet", "Irrum Manzil"};
  list<string> irmn{"Punjagutta", "Khairatbad"};
  list<string> khbd{"Irrum Manzil", "Lakdi-ka-pul"};
  list<string> lkp{"Khairatbad", "Assembly"};
  list<string> asbly{"Lakdi-ka-pul", "Nampally"};
  list<string> nmply{"Assembly", "Gandhi Bhavan"};
  list<string> gbhn{"Nampally", "Osmania Medical College"};
  list<string> osmclg{"Gandhi Bhavan", "MG Bus Stand"};
  list<string> mgbs{"Osmania Medical College", "Sultan Bazar",
                    "Malakpet"}; // intersection of Green Line Is here
  list<string> mkpt{"MG Bus Stand", "New Market"};
  list<string> nmkt{"Malakpet", "Musarambagh"};
  list<string> msbg{"New Market", "Dilsuknagar"};
  list<string> dsng{"Musarambagh", "Chitanyapuri"};
  list<string> chpr{"Dilsuknagar", "Victoria Memorial"};
  list<string> vtmr{"Chitanyapuri", "LB Nagar"};
  list<string> lbnr{"Victoria Memorial"};

  // Green Line
  list<string> sulb{"MG Bus Stand", "Narayanguda"};
  list<string> nrgd{"Chikkadpally", "Sultan Bazar"};
  list<string> chpl{"Narayanguda", "RTC X Road"};
  list<string> rtcr{"Chikkadpally", "Musheerabad"};
  list<string> musbd{"RTC X Road", "Gandhi Hospital"};
  list<string> gdhi{"Musheerabad", "Secundrabad West"};
  list<string> secw{"Gandhi Hospital", "Parade Ground"};
  list<string> pgrd{"Secundrabad West", "JSB", "SCE",
                    "BGMPT"}; // Blue Line Intersection Here
  list<string> jbs{"Parade Ground"};

  // Blue Line
  list<string> mdhn{"Ameerpet"};
  list<string> bgmpt{"Ameerpet", "Parade Ground"};
  list<string> sce{"Parade Ground"};

  // -----------------------------MAP-----------------------------
  // Red Line Insertion
  myMap.insert(pair<string, list<string>>("JNTU College", jntuh));
  myMap.insert(pair<string, list<string>>("KPHB Colony", kpgbc));
  myMap.insert(pair<string, list<string>>("Kukatpally", kktp));
  myMap.insert(pair<string, list<string>>("Balanagar", blngr));
  myMap.insert(pair<string, list<string>>("Moosapet", mopt));
  myMap.insert(pair<string, list<string>>("Bharat Nagar", bhrt));
  myMap.insert(pair<string, list<string>>("Erragadda", ergd));
  myMap.insert(pair<string, list<string>>("ESI Hospital", esih));
  myMap.insert(pair<string, list<string>>("S.R Nagar", srn));
  myMap.insert(pair<string, list<string>>("Ameerpet", ampt));
  myMap.insert(pair<string, list<string>>("Punjagutta", pjgt));
  myMap.insert(pair<string, list<string>>("Irrum Manzil", irmn));
  myMap.insert(pair<string, list<string>>("Lakdi-ka-pul", lkp));
  myMap.insert(pair<string, list<string>>("Assembly", asbly));
  myMap.insert(pair<string, list<string>>("Nampally", nmply));
  myMap.insert(pair<string, list<string>>("Gandhi Bhavan", gbhn));
  myMap.insert(pair<string, list<string>>("Osmania Medical College", osmclg));
  myMap.insert(pair<string, list<string>>("MG Bus Stand", mgbs));
  myMap.insert(pair<string, list<string>>("Malakpet", mkpt));
  myMap.insert(pair<string, list<string>>("New Market", nmkt));
  myMap.insert(pair<string, list<string>>("Dilsuknagar", dsng));
  myMap.insert(pair<string, list<string>>("Victoria Memorial", vtmr));
  myMap.insert(pair<string, list<string>>("LB Nagar", lbnr));

  // Inserting Green line to Map

  myMap.insert(pair<string, list<string>>("Sultan Bazar", sulb));
  myMap.insert(pair<string, list<string>>("Narayanguda", nrgd));
  myMap.insert(pair<string, list<string>>("RTC X Road", rtcr));
  myMap.insert(pair<string, list<string>>("Musheerabad", musbd));
  myMap.insert(pair<string, list<string>>("Gandhi Hospital", gdhi));
  myMap.insert(pair<string, list<string>>("Secundrabad West", secw));
  myMap.insert(pair<string, list<string>>("Parade Ground", pgrd));
  myMap.insert(pair<string, list<string>>("JBS", jbs));

  myMap.insert(pair<string, list<string>>("MDHN", mdhn));
  myMap.insert(pair<string, list<string>>("BGMPT", bgmpt));
  myMap.insert(pair<string, list<string>>("SCE", sce));

//Saves The Map Into .txt File

ofstream outFile("myMap.txt");
for (auto& entry : myMap) {
    outFile << entry.first << " : ";
    for (auto& value : entry.second) {
        outFile << value << ", ";
    }
    outFile << std::endl;
}
outFile.close();

  // disList(myMap);
  // shortestPath(myMap, path, "BGMPT", "Narayanguda");
  // for (auto it : path) {
  //   cout << it << " ->";
  // }
  return 0;
}

