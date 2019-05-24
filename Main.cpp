#include"grammar.h"

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Grammar gar;
	gar.run();
	gar.showCode();
	return 0;
}