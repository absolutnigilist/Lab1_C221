#pragma once

#include <iostream>
#include <array>
#include <stdexcept>

// ��������� ������� ��� ��������� �������� �� ������� �� std::array
template <typename T, std::size_t N>
T getElement(const std::array<T, N>& arr, std::size_t index) {
    // ���������, ��� ������ ����������
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    // ���������� ������� � �������� ��������
    return arr[index];
}
