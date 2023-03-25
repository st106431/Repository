#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x, y, r, a;
	cin >> x >> y >> r;
	double pi = acos(-1.0);
	a = sqrt(pi) * r;
	cout << fixed << setprecision(12);
	cout << x - a / 2 << " " << y - a / 2 << endl;
	cout << x - a / 2 << " " << y + a / 2 << endl;
	cout << x + a / 2 << " " << y + a / 2 << endl;
	cout << x + a / 2 << " " << y - a / 2 << endl;
}
