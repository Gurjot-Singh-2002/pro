#include<iostream>
using namespace std;

void merge(int a[],int start, int mid, int end){
	int p=start;
	int q=mid+1;
	int arr[end-start+1],k=0;
	for(int i=start;i<=end;i++){
		if(p>mid)
		arr[k++]=a[q++];
		else if(q>end)
		arr[k++]=a[p++];
		else if(a[p]<a[q])
		arr[k++]=a[p++];
		else
		arr[k++]=a[q++];		
	}
	for(int p=0;p<k;p++)
	a[start++]=arr[p];
}

void mergesort(int a[],int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

int main(){
	int a[]={1,7,3,8,2,0,3,9};
	int n=sizeof(a)/sizeof(a[0])-1;
	cout<<"Before sort:"<<endl;
	for(int i=0;i<=n;i++)
	cout<<a[i]<<" ";
	mergesort(a,0,n);
	cout<<endl<<"After sort:"<<endl;
	for(int i=0;i<=n;i++)
	cout<<a[i]<<" ";
	}
