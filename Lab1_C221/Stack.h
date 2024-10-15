#pragma once
#include "Point.h"

template<typename T>
class MyStack {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        template<typename N>
        Node(N&& value) :data(std::forward<N>(value)), next(nullptr) {};
    };

    std::unique_ptr<Node> head;

public:
    MyStack() = default;

    // ����������� ��� ���������� ��������
    template<typename... Args>
    MyStack(Args&&... args) {
        push(std::forward<Args>(args)...);
    }

    // ������� ��� ���������� ������ �������� (lvalue � rvalue)
    template<typename U>
    void push(U&& value) {
        auto new_node = std::make_unique<Node>(std::forward<U>(value));
        new_node->next = std::move(head);
        head = std::move(new_node);
        std::cout << (std::is_lvalue_reference<U>::value ? "push lvalue" : "push rvalue") << std::endl;
    }

    // ����������� ������� ��� ���������� ��������
    template<typename First, typename... Rest>
    void push(First&& first, Rest&&... rest) {
        push(std::forward<First>(first));  // ������������ ������ �������
        if constexpr (sizeof...(rest) > 0) {  // ������� ��� ����������� ��������
            push(std::forward<Rest>(rest)...);  // ���������� ��������� ���������
            std::cout << "multiple" << std::endl;
        }
    }

    // �������� �������� �� �����
    template<typename... Args>
    void push_emplace(Args&&... args) {
        auto new_node = std::make_unique<Node>(T(std::forward<Args>(args)...));
        new_node->next = std::move(head);
        head = std::move(new_node);
        std::cout << "emplace" << std::endl;
    }
};
