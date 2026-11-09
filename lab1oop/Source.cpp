#include <iostream>
#include <cmath>
#include "ZavdClass.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ukr");

	double x, y, z;

	cout << "Vvedit x: ";
	cin >> x;

	cout << "Vvedit y: ";
	cin >> y;

	cout << "Vvedit z: ";
	cin >> z;

	ZavdClass obj;
	obj.Fn_b(x, y, z);

	cout << "a = " << obj.GetA() << endl;
	cout << "b = " << obj.GetB() << endl;

	system("pause");
	return 0;
}