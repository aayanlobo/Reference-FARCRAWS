#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
  int q;
  cin >> q;
  pair<int,long long>p;
  vector< pair<int,long long> >v;
  vector<long long>tube;
  set<int>exclude;
 

  for(int i =0;i<q;i++){
    cin >> p.first;
    cin >> p.second;
    v.push_back(make_pair(p.first,p.second));    
  }
   
  for(int i =0;i<q;i++){
      int rem = 0;
    if(v[i].first == 1){
              tube.push_back(v[i].second);
    }
    else if(v[i].first == 2){
               int max_count = 0;
         long long e = 0;
         for(int j =0;j<tube.size();j++){
           int curr_count = 0;
           for(int k =j;k<tube.size();k++){
             if(tube[j]==tube[k]){
               curr_count++;

                          if(curr_count >= max_count){
                  max_count = curr_count;
                  e = tube[k];
                 rem = k;
                 }
             }
           }
         }
           exclude.insert(e);

           tube.erase(tube.begin()+rem);
    }
  }
  set<int>::iterator itr;

  for(itr = exclude.begin();itr != exclude.end();itr++){
    cout << *itr << " ";
  }
}
