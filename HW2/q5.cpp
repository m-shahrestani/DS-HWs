#include<bits/stdc++.h>
using namespace std;

deque<int> q1, q2;
int32_t main(){
	bool finish = false;  
    while(!finish) {
      string str;
      cin >> str;
    if(str == "push") {
		int x; 
		cin >> x;
      	q1.push_front(x);
      	if(q1.size() > q2.size()) {
      	  q2.push_front(q1.back());
      	  q1.pop_back();
    	}
    }
    if(str == "pop") {
    	if(q2.empty()) {
        	continue;
        }
      	if(q1.size()) {
        	q1.pop_front();
        }
      	else{
       		q2.pop_front();
       	}
     	if(q1.size() + 1 < q2.size()) {
        	q1.push_back(q2.front());
       		q2.pop_front();
      	}
    }
    if(str == "print") {
      	for(auto x : q1) {
        	cout << x << ' ';
    	}
      	for(auto x : q2){
        	cout << x << ' ';
        }
      	cout << '\n';
    }
    if(str == "findMiddle") {
    	if(q2.empty()){
        	cout << "-1\n";
		}
    	else {
        	cout << q2.front() << '\n';
        }
    }
    if(str == "removeMiddle") {
    	if(q2.empty()) {
        	continue;
        }
    	if(q1.size() == q2.size()) {
        	q2.pop_front();
        	q2.push_front(q1.back());
        	q1.pop_back();
      	}
    	else{
        	q2.pop_front();
        }
    }
    if(str == "finish") {
      finish = true;
    }
  }
}
