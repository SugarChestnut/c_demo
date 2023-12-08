#include <cmath>
#include <iostream>

#include "round.h"

Round::Round(){};
Round::Round(double r) { this->r = r; };
double Round::area() { return M_PI * r * r; }
