#include <iostream>
#include <string>
using namespace std;

int n,m;
int sgt[500000];
int ty[500000]; // 1- OR | 0 - XOR
int arr[500000];

void build(int node,int l,int r){
	if(l==r){
		sgt[node]=arr[l];
		ty[node]=1;
		return;
	}
	build(2*node,l,(r+l)/2);
	build(2*node+1,(r+l)/2+1,r);
	ty[node]=1-ty[2*node];
	if(ty[node]==0){
		sgt[node]=sgt[2*node] | sgt[2*node+1];
	} else {
		sgt[node]=sgt[2*node] ^ sgt[2*node+1];
	}
}
void update(int node,int l,int r,int ind){
	if(l==r){
		sgt[node]=arr[l];
		ty[node]=1;
		return;
	}
	if(ind<=(r+l)/2){
		update(2*node,l,(r+l)/2,ind);
	} else {
		update(2*node+1,(r+l)/2+1,r,ind);
	}
	ty[node]=1-ty[2*node];
	if(ty[node]==0){
		sgt[node]=sgt[2*node] | sgt[2*node+1];
	} else {
		sgt[node]=sgt[2*node] ^ sgt[2*node+1];
	}
}
int p2=1;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		p2*=2;
	}
	for(int i=0;i<p2;i++){
		cin>>arr[i];
	}
	build(1,0,p2-1);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a-1]=b;
		update(1,0,p2-1,a-1);
		cout<<sgt[1]<<endl;
	}
}