#include <bits/stdc++.h>
using namespace std;

struct D {
	int num;
	int p;
	int f;
	int s;
	int v;
	int c;
};

int N, mp, mf, ms, mv;
int minCost = 15500;
vector<D> v, curVector, ans;

bool check(vector<D>& curVector) {

	int cp = 0, cf = 0, cs = 0, cv = 0, cc = 0;
	for (int i = 0; i < curVector.size(); i++) {
		cp += curVector[i].p;
		cf += curVector[i].f;
		cs += curVector[i].s;
		cv += curVector[i].v;
		cc += curVector[i].c;
	}

	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv && minCost > cc) {
		minCost = cc;
		return true;
	}
	return false;

}

void go(vector<D>& curVector, int st) {

	if(check(curVector)) {
		ans = curVector;
		return;
	}

	for (int i = st+1; i < N; i++) {
		curVector.push_back(v[i]);
		go(curVector, i);
		curVector.pop_back();
	}


}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++) {
		D d;
		cin >> d.p >> d.f >> d.s >> d.v >> d.c;
		d.num = i + 1;
		v.push_back(d);
	}

	go(curVector, -1);

	if (minCost == 15500) {
		cout << "-1";
	}
	else {
		cout << minCost << "\n";
		for (D d : ans) cout << d.num << " ";
	}
}