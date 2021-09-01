#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<array<gg, 2>> data(1e5 + 5);
// v2->v1
vector<gg> reverseInsert(vector<gg>& v1, vector<gg>& v2){
	reverse(v2.begin(), v2.end());
	vector<gg> v;
	for (gg i = 0; i < v1.size(); ++i){
		v.push_back(v1[i]);
		if (i % 2 == 1 and i / 2 < v2.size())
		   v.push_back(v2[i / 2]);
	}
	return v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	gg start1, start2, n;
	cin >> start1 >> start2 >> n;
	for (gg i = 0; i < n; ++i){
		gg addr, val, next;
		cin >> addr >> val >> next;
		data[addr] = {val, next};
	}
	vector<gg> lst1, lst2, lst;
	while (start1 != -1){
		lst1.push_back(start1);
		start1 = data[start1][1];
	}
	while (start2 != -1){
		lst2.push_back(start2);
		start2 = data[start2][1];
	}
	if (lst1.size() > lst2.size())
        lst = reverseInsert(lst1, lst2);
	else
		lst = reverseInsert(lst2, lst1);
	cout << setfill('0');
	for (gg i = 0; i < lst.size() - 1; ++i)
		cout << setw(5) << lst[i] << " " << data[lst[i]][0] << " " << setw(5) << lst[i + 1] << "\n";
	cout << setw(5) << lst.back() << " " << data[lst.back()][0] << " -1\n"; 
	return 0;
}
