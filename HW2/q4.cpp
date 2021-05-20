#include<bits/stdc++.h>
using namespace std;

#define int long long
int a[1000000+1], b[1000000+1], n = 0;
int32_t main(){
	string s;
 	getline(cin, s);
  	s += ' ';
  	for(int i = 0; i < s.length(); i++) {
    	int j = i;
    	while(s[j] != ' ')
      		j ++;
    	if(j == i)
      		continue;
    	int t = j - 1, p = 1;
    	n ++;
    	while(t >= i) {
      		a[n] += (s[t] - '0') * p;
      		p *= 10;
      		t--;
    	}
    	i = j;
  	}
	for(int i = 1; i <= n/2; i++) {
	    b[2*i] = i;
	}
	for(int i = 1; i <= (n+1)/2; i++) {
    	b[2*i-1] = n - i + 1;
	}
    for(int i = 1; i <= n; i ++){
   		cout << a[b[i]]<<' ';
   	}
    return 0;
}
