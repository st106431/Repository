#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long double x_1, y_1, x_2, y_2, x_3, y_3, s;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	x_2 -= x_1;
	x_3 -= x_1;
	y_2 -= y_1;
	y_3 -= y_1;
	x_1 = 0;
	y_1 = 0;
	s = abs(x_2 * y_3 - x_3 * y_2);
	cout << fixed << setprecision(9) << s / 2;
}