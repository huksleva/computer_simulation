#pragma once
#include <vector>

void Gauss();
void Gauss2();
void swap_cols(std::vector<std::vector<double>> &a, int i, int j);
void swap_vars(std::vector<int> &indexes, int i, int j);
void Gauss3_1();
void swap_lines(std::vector<std::vector<double>> &a, std::vector<double> &b, int i, int j);
void Gauss3_2();
void swap_max_elem(std::vector<std::vector<double>> &a, std::vector<double> &b, int i, int j, int new_i, int new_j);
void Gauss3_3();