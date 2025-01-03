#include <iostream>
#include <bits/stdc++.h>
#include "Queue.h"
#include "Queue.cpp" using
namespace std;
void BFS(int **AdjMat,char vertex[],int u){
int i,j;
char color[u];
char prev[u]; int
d[u];
for(i=1; i<u; i++){ //root = AdjMat[0]
color[i] = 'W'; //White = W
prev[i] = 'N'; //NULL = N d[i] =
5000; //Inf = 5000
} color[0]
= 'G'; d[0] =
0; prev[0] =
'N';
Queue<char> Q(u);
Q.Enqueue(vertex[0]);
while(!Q.IsEmpty()){
char p;
Q.Dequeue(p);
int k = 0;
while(vertex[k]!=p){
k++;
}
for(j=0; j<u; j++){
if(AdjMat[k][j]==1 && color[j]=='W'){
color[j] = 'G';
d[j] = d[k]+1;
prev[j] = p;
Q.Enqueue(vertex[j]);
} } color[k] = 'B';
//Black = B
}
cout<<"The result is : "<<endl;
cout<<endl; cout<<"Vertex: ";
for(i=0; i<u; i++){
cout<<vertex[i]<<" ";
}
cout<<endl;
cout<<"Color: ";
for(i=0; i<u; i++){
cout<<color[i]<<" ";
}
cout<<endl;
cout<<"d: ";
for(i=0; i<u; i++){
cout<<d[i]<<" ";
}
cout<<endl;
cout<<"Prev: ";
for(i=0; i<u; i++){
cout<<prev[i]<<" ";
}
}

int main()
{ int
a,b; int
i,j;
cout<<"Enter the total number of vertices and edges: "; cin>>a>>b;
char vertices[a];
cout<<"Enter the vertex: ";

for(i=0; i<a; i++){
cin>>vertices[i]; } int
**AdjMatrix;
AdjMatrix = new int*[a];
for(i=0; i<a; i++){
AdjMatrix[i] = new int[a];
} for(i=0; i<a; i++) {
for(j=0; j<a; j++) {
AdjMatrix[i][j] = 0;
}
}
for (i=0; i<b; i++) {
char x,y; int
m=0,n=0;
cout<<"Enter edges: ";
cin>>x>>y;
while(vertices[m]!=x){
m++;
}
while(vertices[n]!=y){
n++;
}
AdjMatrix[m][n] = 1;
AdjMatrix[n][m] = 1;
}
cout<<endl;
BFS(AdjMatrix,vertices,a);
return 0;
}
