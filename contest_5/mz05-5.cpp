#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Factory
{
    static Factory *instance;
    Factory() {}
    Factory(const Factory &x) {}
public:
    static Factory *factory_instance(void)
    {
        if (!instance) {
            return new Factory();
        } 
        return instance;
    }
    Figure *make(char type, const std::string &s)
    {
        if (type == 'R') {
            return Rectangle::make(s);
        }
        if (type == 'S') {
            return Square::make(s);
        }
        if (type == 'C') {
            return Circle::make(s);
        }
        return nullptr;
    }
};

Factory* Factory::instance = nullptr;

bool comp(Figure *f1, Figure *f2)
{
    return (f1->get_square() < f2->get_square());
}

int main(void)
{
    std::vector<Figure*> v;
    std::string input;
    Factory *fact = Factory::factory_instance();
    while (1) {
        std::getline(std::cin, input);
        if (input.begin() == input.end()) {
            break;
        }
        std::istringstream stream(input);
        char type;
        stream >> type;
        int cnt = 1;
        auto it = input.begin();
        while (*it++ != type) {
            cnt++;
        }
        input.erase(0, cnt);
        v.push_back(fact->make(type, input));
    }
    std::stable_sort(v.begin(), v.end(), comp);
    for (Figure *f: v) {
        std::cout << f->to_string() << std::endl;
        if (f) {
            delete f;
        }
    }
    if (fact) {
        delete fact;
    }
    return 0;
}