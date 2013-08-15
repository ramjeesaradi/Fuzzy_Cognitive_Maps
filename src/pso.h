#pragma once

#include "error.h"
#include "fcm.h"

array<double, 500> pso(double lower_bound ,double upper_bound ,double epsilon, double omega, double phyp, double phyg , int horizon ,int num_concepts, int num_output_class);