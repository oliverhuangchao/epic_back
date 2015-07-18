#include <vector>
#include <string>
#include <iostream>
#include <set>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> IntVecVector;

IntVecVector powerset(const IntVector &V)
{
	IntVecVector S;
	int i;
	
	S.push_back(IntVector());

	for (i = 0; i < V.size(); ++i) {
		IntVecVector s = S;
		int j, n = s.size();
		for (j = 0; j < n; ++j) {
			s[j].push_back(V[i]);
		}
		S.insert(S.end(), s.begin(), s.end());
	}

	return S;
}

bool colorful(const IntVecVector &S)
{
	std::set<int> mults;
	int i;

	for (i = 0; i < S.size(); ++i) {
		int j, n = S[i].size();
		int m = 1;
		for (j = 0; j < n; ++j) {
			m *= S[i][j];
		}

		std::pair<std::set<int>::iterator, bool> x = mults.insert(m);
		if (x.second == false) return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	std::string word = argv[1];
	int i, n = word.length();

	IntVector V;
	V.reserve(n);

	for (i = 0; i < n; ++i) {
		int d = (int)(word[i] - '0');
		V.push_back(d);
	}

	const IntVecVector S = powerset(V);

	bool r = colorful(S);

	if (r) {
		std::cout << "Colorful\n";
	}
	else {
		std::cout << "Not colorful\n";
	}

	return 0;
}