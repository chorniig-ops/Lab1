#pragma once 
#include <cmath>
class ZavdClass {
    double a, b;
public: ZavdClass() : a(1.0), b(1.0) {}
      void Fn_b(double x, double y, double z)
      {
          double b1 = (x + y) / std::pow(std::abs(z), 0.6);
          double b2 = std::pow(std::sin((x + z - z) / (2 * x + y)), 2);
          double b3 = z * std::exp((x - y) / (x + y));

          b = std::pow(std::abs(b1 + b2), 1.0 / 3.0) - b3;
      }

      double GetA() { return a; }
      double GetB() { return b; }
};