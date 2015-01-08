#include <iostream>

using namespace std;

int main(){
	uint16_t ii;
	uint8_t i = 243;
	ii = i << 8;
	cout << hex << ii;
	return 0;
}