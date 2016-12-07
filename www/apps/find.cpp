#include <iostream>

using namespace std;

int main ( int argc, char *argv[] )
{

	for (int i=0; argv[i]; ++i) {
        cout << "Argument[" << i << "]: " << argv[i] << '\n';
    }

	return 0;
}

