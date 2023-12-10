#include <iostream>

int main() {
	std::string t;
	char *a = "abcd";
	t.append(a, 1, 2);
	std::cout << t << "\n";
}