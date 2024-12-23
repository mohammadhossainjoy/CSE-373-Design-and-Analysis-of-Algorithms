#include <stdio.h>
#include <math.h>
int main(){
char T[50];
int a, b, k, p, n, i;
float logResult;
printf("Enter T(n)(enter '!' to end the line): ");
for(i=0;i<50;i++){
scanf("%c",&T[i]);
if(T[i]=='!')
break;
}

a = T[0]-48;
b = T[5]-48;
logResult = log(a)/log(b);

if(T[8]=='n' & T[11]=='l')
    {
if(T[9]=='^')
k = T[10]-48;
if(T[14]=='^')
p = T[15]-48;
else
p = 1;
}

else if(T[8]=='n' && T[9]=='l'){
k = 1;
if(T[12]=='^')

p = T[13]-48;
else
p = 1;
}
else if(T[8]=='l'){
k=0;
if(T[11]=='^')
p = T[12]-48;
else
p = 1;
}
else if(T[8]=='n')
    {
p=0;
if(T[9]=='^')
k = T[10]-48;

else
k=1;
}

if(logResult>k){ //case 1 check
printf("\nAccording to case 1: logb(a)>k\n");
if(logResult>1 || logResult<0)
printf("T(n) = O(n^log%d(%d))",b,a);
else if(logResult==0)
printf("T(n) = O(1)");

else if(logResult==1)
printf("T(n) = O(n)");
}
else if(logResult<k){ //case 3 check
printf("\nAccording to case 3: logb(a)<k and ");
if(p>=0){
printf("p>=0\n");
if(k>1 || k<0){
if(p==0)
printf("T(n) = O(n^%d)",k);
else if(p==1)
printf("T(n) = 0((n^%d)(log(n)))",k);
else if(p>1)
printf("T(n) = O((n^%d)(log^%d(n)))",k,p);
}
if(k==0){
if(p==0)
printf("T(n) = O(1)");
else if(p==1)
printf("T(n) = 0(log(n))");
else if(p>1)
printf("T(n) = O(log^%d(n))",k);
}
if(k==1){
if(p==0)
printf("T(n) = O(n)");
else if(p==1)
printf("T(n) = 0(nlog(n))");
else if(p>1)
printf("T(n) = O(nlog^%d(n))",k);
}
}
else{
printf("p<0\n");
if(k>1 || k<0)
printf("T(n) = O(n^%d)",k);
else if(k=0)
printf("T(n) = O(1)");
else if(k=1)
printf("T(n) = O(n)");

}
}
else{
printf("\nAccording to case 2: logb(a)=k and ");
if(p>-1){
printf("p>-1\n");
if(p+1==1){
if(k==1)
printf("T(n) = O(nlogn)");
else if(k>1 || k<0)
printf("T(n) = O((n^%d)logn)",k);
else if(k==0)
printf("T(n) = O(logn)");
}
else if(p+1==0){
if(k==1)
printf("T(n) = O(n)");
else if(k>1 || k<0)
printf("T(n) = O(n^%d)",k);

else if(k==0)
printf("T(n) = O(1)");
}
else if((p+1)>1 || (p+1)<0){
if(k==1)
printf("T(n) = O(nlog^%d(n))",(p+1));
else if(k>1 || k<0)
printf("T(n) = O((n^%d)log^%d(n))",k,(p+1));
else if(k==0)
printf("T(n) = O(log^%d(n))",(p+1));
}
}
}
return 0;
}

