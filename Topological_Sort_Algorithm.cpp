#include <bits/stdc++.h>
using namespace std;
int main(){
int n,e;
int count=0;
cout <<"Please Enter the input n & e: "<<endl; cin>>n>>e;
vector<vector<int>>adjacency(n);
vector<int> indegree(n,0);
for(int i=0;i<e;i++){
int u,v;
cin>>u>>v;
adjacency[u].push_back(v);
indegree[v]++;
}
queue<int>pri_que; for(int
i=0;i<e;i++){
if(indegree[i]==0){
pri_que.push(i);
}
}
cout<<"Sorted order: ";
while(!pri_que.empty()){
count++; int
x=pri_que.front();
pri_que.pop();
cout<<x<<" "; for(auto it
: adjacency[x]){
indegree[it]--;
if(indegree[it]==0)
pri_que.push(it);
}
}
}
