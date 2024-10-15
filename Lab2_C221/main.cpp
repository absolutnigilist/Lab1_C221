#include "Header.h"
#include "Point.h"
#include "Book.h"
#include "Library.h"
#include "Calculator.h"

#include <tuple>
#include <string_view>


int main() {
	//1. std::tuple<>, std::tuple_size<>::value,
	//	���������� ������� ������ ������ tuple, ��������:
	std::tuple t1{ 1, 2.2, "abc"};
	std::cout << t1;
	printTuple(t1);

	std::tuple t2{ std::string("abc"), 1, 2.2, Point(1,2) };
	printTuple(t2);

	book b1("A","B",123);
	std::cout << b1;

    // �������� ���������� � �������
    book my_favorite_book{ "Willims", "Parallel C++", 2014 };
    library l = { {"Straustrup", "C++", 2000}, my_favorite_book };

    // ���������� ����
    l.add({ {"Straustrup", "C++", 2000}, {"Straustrup", "C++", 2010}, {"Golovic", "Advanced", 2008} });

    // ����� ���� �� ������
    std::cout << "Books by author:" << std::endl;
    l.ByAuthor();

    // ����� ���� �� ��������
    std::cout << "Books by title:" << std::endl;
    l.ByTitle();

    // ����� ���� �� ����
    std::cout << "Books by year:" << std::endl;
    l.ByYear();

    // �������� �����
    l.remove({ "Straustrup", "C++", 2000 });

    //Call to calculator
    Calc();

    // ���������� std::function ��� �������� ������-�������
    std::function<int(int)> sum_natural;

    // ���������� ����������� ������-������� ��� ���������� ����� ������������ ����
    sum_natural = [&sum_natural](int x) {
        if (x<=1)
        {
            return x;// ������� ������: ���� x <= 1, ���������� x
        }
        return x + sum_natural(x - 1); // ����������� ������
        };
    // ������: ��������� ����� ���� ��� ����� 5
    int n = 5;
    std::cout << "Sum of natural numbers up to " << n << " is: " << sum_natural(n) << std::endl;


    bool res1=InRange(10, 20, 1, 15, 30);             // --> false 
    bool res2=InRange(10, 20, 11, 12, 13);            // --> true
    bool res3=InRange(5.0, 5.5, 5.1, 5.2, 5.3);       // --> true

	return 0;
}