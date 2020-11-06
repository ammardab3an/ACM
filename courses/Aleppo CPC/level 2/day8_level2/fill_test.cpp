// C++ program to demonstrate working of fill()
#include <bits/stdc++.h>
#include <array>
using namespace std;

int main ()
{
array<int,8> vect;

// calling fill to initialize values in the
// range to 4
vect.fill(4);

for (int i=0; i<8; i++)
	cout << vect[i] << " ";

return 0;
}

