#include<iostream>
using namespace std;

int binary(int a[],int low,int high,int key){
	while(low<=high){
		int mid=(low+high)/2;
		if(key==a[mid])
		return mid;
		else if(key<a[mid])
		high=mid-1;
		else
		low=mid+1;	
	}
	return -1;
}
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                // Swap
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main(){
	int a[]={1,7,3,9,4,2};
	int key=2,low=0,n=sizeof(a)/sizeof(a[0]),high=n-1;
	bubbleSort(a, n);

	int res=binary(a,low,high,key);
	if(res==-1)
	cout<<"Not found";
	else
	cout<<"Found at index "<<res;
	return 0;
}
