#pragma once

#include "Shape.h"

#include <iostream>
#include <variant>
#include <vector>
#include <string>

// ������� ��� �������������� �������� ����� � ������

std::string colorToString(Color c);

// ��������������� ��������� overload ��� ������������� � std::visit
template<typename... Functors>
struct overload : Functors... {
    using Functors::operator()...;
};
// ������������� ������ ������� �������� � �������������� std::visit
void printVariants(const std::vector<std::variant<int, double, Color>>& values);