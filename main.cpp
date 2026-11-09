#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Клас згідно з вимогами лабораторної роботи (варіант 8)
class ZavdClass
{
private:
    double a;
    double b;

public:
    // Конструктор за замовчуванням
    ZavdClass()
    {
        a = 1.0;
        b = 1.0;
    }

    // Обчислення факторіалу
    double Faktr(int n)
    {
        double f = 1.0;
        if (n > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                f *= i;
            }
        }
        return f;
    }

    // Обчислення функції b(x, y, z) для Варіанту 8
    void Fn_b(double x, double y, double z)
    {
        double term1 = 1.0;
        double term2 = (x * x + y * y + std::pow(z, 3)) / (Faktr(1) + Faktr(2) + Faktr(3));
        double term3 = 1.0 - std::sin(z) + (z / std::cos(x));

        b = term1 + term2 + term3;
    }

    // Обчислення функції a(x, y, z, b) для Варіанту 8
    void Fn_a(double x, double y, double z)
    {
        double num = std::pow(std::abs(x), 1.34) + (y * y) + std::pow(z, 3);
        double den = 1.34 + (1.0 / y);

        a = num / den;
    }

    // Геттери для інкапсульованих полів
    double geta() { return a; }
    double getb() { return b; }
};

int main()
{
    // Налаштування української локалі для консолі
    setlocale(LC_ALL, "Ukrainian");

    int N = 8; // Номер варіанту

    // Вхідні дані за методичкою для Варіанту 8
    double x_base = 0.48 * N;
    double y_base = 0.47 * N;
    double z_base = -1.32 * N;

    ZavdClass Zavd;

    cout << "=== ЗАВДАННЯ 1 (Розрахунок для Варіанту 8) ===\n";
    cout << "Вхідні дані: x = " << x_base << ", y = " << y_base << ", z = " << z_base << "\n";

    Zavd.Fn_b(x_base, y_base, z_base);
    Zavd.Fn_a(x_base, y_base, z_base);

    cout << "Результат a = " << Zavd.geta() << "\n";
    cout << "Результат b = " << Zavd.getb() << "\n\n";

    cout << "=== ЗАВДАННЯ 2 (Табулювання за x від -1 до 1) ===\n";
    cout << "---------------------------------------------------\n";
    cout << "     x          b(x, y, z)          a(x, y, z, b)\n";
    cout << "---------------------------------------------------\n";

    // Табулювання за x від -1 до 1 з кроком 0.2
    for (double x = -1.0; x <= 1.0001; x += 0.2)
    {
        Zavd.Fn_b(x, y_base, z_base);
        Zavd.Fn_a(x, y_base, z_base);

        cout << setw(7) << fixed << setprecision(1) << x << "   "
            << setw(15) << setprecision(6) << Zavd.getb() << "   "
            << setw(15) << setprecision(6) << Zavd.geta() << "\n";
    }

    cout << "\nНатисніть Enter для виходу...";
    cin.get();
    return 0;
}
