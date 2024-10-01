#pragma once
#include<vector>
#include<iostream>
#include<type_traits>
#include <algorithm>
#include <functional>

template<typename T> void fV(std::vector<T>& v) {
	for (auto& x : v) {
		++x; }
}
// �������� ��������� ������� insertunique
template<typename T, typename... Args>
void insertunique(std::vector<T>& v, Args&&... args) {};

// ��������������� ������� ��� ������� ������ ��������
template<typename T, typename U>
void insert_single_unique(std::vector<T>& v, U&& value) {
    // ��������: ����� �� �������� U � T
    if constexpr (std::is_convertible_v<std::decay_t<U>, T>) {
        // �������� �������� � ���������, ���� �� ��� ��� � �������
        T converted_value = static_cast<T>(value);
        if (std::find(v.begin(), v.end(), converted_value) == v.end()) {
            v.push_back(converted_value); // ���������, ���� ��� ��� ���
        }
    }
}

// ����������� ����������� ������� ��� ������� ���������� ��������
template<typename T, typename First, typename... Rest>
void insertunique(std::vector<T>& v, First&& first, Rest&&... rest) {
    insert_single_unique(v, std::forward<First>(first));  // ������������ ������ ��������
    insertunique(v, std::forward<Rest>(rest)...);         // ���������� ������������ ���������
}

// ������� ������ ��� �������� (����� ��� ����������)
template<typename T>
void insertunique(std::vector<T>&) {
    // ������� ������ ������ �� ������
}


// ������� ������: ����� ��� ������ ������� ��� ����������
template<typename T>
void apply_actions(T& value) {
    // ������� ������ ������ �� ������
}

// ����������� ������� ��� ���������� ������������������ callable-�������� � ��������
template<typename T, typename Callable, typename... Callables>
void apply_actions(T& value, Callable&& action, Callables&&... actions) {
// ��������� ������� ��������
    std::forward<Callable>(action)(value);

// ���������� �������� ���������� ��������
    apply_actions(value, std::forward<Callables>(actions)...);
}
// �������, ������������ fold expressions ��� ���������� ��������
template<typename T, typename... Callables>
void apply_actions(T& value, Callables&&... actions) {
    // ���������� fold expression ��� ���������� ������� callable � ��������
    (..., std::forward<Callables>(actions)(value));
}