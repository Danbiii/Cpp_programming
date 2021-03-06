// �عּ� // 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned long long > v;

void hamming_vector();
bool srt(const unsigned long long &a, const unsigned long long &b);

int main() {
	int t, n;
	cin >> t;
	hamming_vector();
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << v[n - 1] << endl;
	}
	return 0;
}

void hamming_vector() {
	unsigned long long i, j, k;
	for (i = 1; i < 1e9; i *= 5) {
		for (j = 1; j < 1e9; j *= 3) {
			for (k = 1; k < 1e9; k *= 2) {
				v.push_back(i*j*k);
			}
		}
	}
	sort(v.begin(), v.end(), srt);
}

bool srt(const unsigned long long &a, const unsigned long long &b) {
	return a < b;
}
