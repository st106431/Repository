#include <iostream>
using namespace std;

int main()
{
	double a, b, x, y, s, o;
	cin >> a >> b >> x >> y;
	s = (a * x + b * y) / (sqrt(a * a + b * b) * sqrt(x * x + y * y));
	o = acos(s);
	cout << o;
}