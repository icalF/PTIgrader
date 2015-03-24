#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

vector<char> cs;
char cc;

int main() {
	freopen("output", "r", stdin);
	while ((cc = getchar_unlocked()) != EOF) {
		if (isdigit(cc) || cc == ' ' 
		|| cc == '\n' || cc == '\t')
			cs.push_back(cc);
	}
	fclose(stdin);
	freopen("output", "w", stdout);
	for (char& c : cs)
		putchar_unlocked(c);
	fclose(stdout);
}
