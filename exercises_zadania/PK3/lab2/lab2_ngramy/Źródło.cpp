#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
	auto gen_ngram = [](string slowo, int n) {
		vector<string> ngram;
		int i = 0;
		for (string s : ngram)
		{
			ngram.push_back(slowo.substr(i, n));
			i++;
		}
		return ngram;
	};

	auto v = gen_ngram("ciag wyrazow", 3);
	string wynik;
	copy(v.begin(), v.end(), wynik);
	cout << wynik;

}