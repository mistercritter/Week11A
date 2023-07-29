#include <iostream>

using namespace std;

char character(char start, int offset);

class invalidCharacterException {};
class invalidRangeException {};

int main() {

		cout << character('a', 1) << endl; 
		cout << character('a', -1) << endl; 
		cout << character('Z', -1) << endl;
		cout << character('?', 5) << endl;
		cout << character('v', 15) << endl;
		cout << character('V', -15) << endl;
		cout << character('A', 32) << endl;

	return 0;
}

char character(char begin, int offset) {
	int start = static_cast<int> (begin);
	int result = start + offset;

	try {
		if ((start < 65 || start > 90) && ((start < 97) || (start > 122))) {
			throw invalidCharacterException();
		}
		
		if ((result < 65 || result > 90) && ((result < 97) || (result > 122))) {
			throw invalidRangeException();
		}

		if ((result >= 65 && result <= 90 && start >= 95 && start <= 122) || (result >= 95 && result <= 122 && start >= 65 && start <= 90)) {
			throw invalidRangeException();
		}
	}

	catch (invalidCharacterException) {
		cout << "Invalid Character Exception." << endl;
		return ' ';
	}

	catch (invalidRangeException) {
		cout << "Invalid Range Exception." << endl;
		return ' ';
	}

	char finalRes = static_cast<char>(result);

	return char(finalRes);
}