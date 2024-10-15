#include "Shape.h"
#include "Split.h"
#include "Find.h"
#include "Person.h"
#include "Animal.h"

#include <algorithm>
#include <compare>



int main() {
    
    // ������� ������ ���������������
    std::vector<Rect> rectangles = {
        Rect(0, 10, 0, 5, Red),
        Rect(0, 3, 0, 3, Green),
        Rect(0, 8, 0, 4, Blue),
        Rect(0, 5, 0, 5, Red)
    };
    std::sort(rectangles.begin(), rectangles.end(), [](const Rect& a, const Rect& b) {return a.area() < b.area(); });
    
    // ������� ��������������� ��������������
    std::cout << "Rectangles sorted by area:\n";
    for (const auto& a : rectangles) {
        a.print();
    }

    const char* str[]{ "123", "abc", "qwerty" };
    char ar[] = "dog";
    char* p = new char[4] {"cat"};
    std::string s("great");

    std::vector<std::string_view> views = { str[0],str[1], str[2],ar,p,s };
    std::sort(views.begin(), views.end());
    for (const auto& a : views) {
        std::cout << a<<" ";
    }
    std::cout << std::endl;

    const char* split_str = "abc 12345 cat dog bird";

    // ����� ������� split_string
    std::vector<std::string_view> words = split_string(split_str);

    // ����� �����������
    std::cout << "Split words:" << std::endl;
    for (const auto& word : words) {
        std::cout << word<<" ";
    }
    std::cout << std::endl;

    std::vector<int> vec = { 10, -20, 30, -40, 50 };  // �������� ������
    int value_to_find = 20;  // ����� ��� ������ �� ������

    // ����� �������
    std::optional<int> index = find_by_modulo(vec, value_to_find);

    if (index) {
        std::cout << "Element found at index: " << *index << std::endl;
    }
    else {
        std::cout << "No matching element found." << std::endl;
    }

    // ������� ������ �����
    std::vector<Person> people = {
        Person("Alice", 25, "Ali"),
        Person("Bob", 30),
        Person("Charlie", 22, "Chuck"),
        Person("Dave", 35),
        Person("Eve", 28, "Evie") };
	
    // ���������� �� ����� (��������)
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {return a.m_name < b.m_name; });
   
    // ����� ���������������� ������
    std::cout << "Sorted by name:" << std::endl;
    for (const auto& person : people) {
        person.print();
    }

    std::vector<Animal> animals = {
        Cat("Musya"),
        Dog("Sharik"),
        Cat("Murka"),
        Dog("Bobik"),
        Dog("Layka")
    };

    int count_cat = 0;
    int count_dog = 0;

    for (const auto& animal : animals) {
        tell_about_animal(animal, count_cat, count_dog);
    }

    std::cout << "Cats: " << count_cat << std::endl;
    std::cout << "Dogs: " << count_dog << std::endl;
    return 0;
}