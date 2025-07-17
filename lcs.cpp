#include<iostream>
#include<string>
using namespace std;

int main(){
string s1="abc",s2="afcd";
int m=s1.length(),n=s2.length();
int c[m+1][n+1];

for(int i=0;i<=m;i++){
	for(int j=0;j<=n;j++){
		if(i==0||j==0)
			c[i][j]=0;
		else if(s1[i-1]==s2[j-1])
			c[i][j]=1+c[i-1][j-1];
		else
			c[i][j]=max(c[i][j-1],c[i-1][j]);
	}
}

int i=m,j=n;
string lcs="";
while(i>0&&j>0){
	if(s1[i-1]==s2[j-1]){
		lcs=s1[i-1]+lcs;
		i--;
        j--;
    }
    else if(c[i-1][j]>c[i][j-1])
        i--;
    else
        j--;
    }
cout<<"LCS string: "<<lcs<<endl;
cout<<"LCS length: "<<lcs.length()<<endl;

return 0;
}
