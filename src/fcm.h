#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::ifstream;
using std::ofstream;
using std::isnan;
using std::abs;

array<double, 100> fcm(array<double, 100> concept, array<double, 500> dmns, int num_concepts, int num_output_class, int horizon);