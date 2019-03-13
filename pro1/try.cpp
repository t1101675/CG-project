#include <iostream>
#include <list>

int main() {
	std::list<int> L;
	for (int i = 0; i < 100; i++) {
		L.push_back(i);
	}
	std::list<int>::iterator it = L.begin();
	for (; it != L.end(); it++) {
		if ((*it) % 10 == 0) {
			L.erase(it);
		}
	}
	for (it = L.begin(); it != L.end(); it++) {
		std::cout << *it << " ";
	}
				
	return 0;
}
