#include<bits/stdc++.h>
#define mod 10000007
using namespace std;
int main(){
	int k;
	cout<<"Enter kth prime number you need"<<endl;
	cin>>k;
	vector<int> isprime(mod, 1);
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i*i <= mod; i++){
		if(isprime[i] == 1){
		for(int j =i*i; j<=mod; j += i)
                        isprime[j] = 0;
		}
	}
	vector<int> v;
	for(int i = 2; i<=mod; i++){
		if(isprime[i] == 1)
			v.push_back(i);
	}
        cout<<v[k-1]<<endl;
	return 0;
}
	
		
