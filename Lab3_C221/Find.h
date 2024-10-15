#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <cmath>  // ��� ������� std::abs

// ������� ��� ������ ������� �������� �� ������
std::optional<int> find_by_modulo(const std::vector<int>& vec, int value);