#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<stack>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())


typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x) {
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	IDcache[x] = Setcache.size() - 1;
	return IDcache[x];
}

int main() {
	int n;
	stack<int> s;
	
	cin >> n;
	for (int i=0; i<n; i++) {
		string op;
		cin >> op;
		
		
		if (op=="push") {
			
			s.push(ID(Set()));
		} else if (op=="dup") {
			s.push(s.top());
		} else {
			Set s1 = Setcache[s.top()]; s.pop();
			Set s2 = Setcache[s.top()]; s.pop();
			Set x;
			if (op=="union") {
				set_union(ALL(s1), ALL(s2), INS(x));
			} else if (op=="intersect") {
				set_intersection(ALL(s1), ALL(s2), INS(x));
			} else {
				x = s2;
				x.insert(ID(s1));
			}
			
			s.push(ID(x));
		}
		
		cout << Setcache[s.top()].size() << endl;
	}
	
	return 0;
}
