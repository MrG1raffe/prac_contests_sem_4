#include <iostream>
#include <vector>

struct Tractor 
{
    int x, y, mv;
    bool is_returned;
    Tractor(int a = 0, int b = 0, int c = 0) : x(a), y(b), mv(c), is_returned(false) {}
};

void move_ret(Tractor &t) 
{
    switch(t.mv) 
    {
    case 1:
        ++t.x;
        break;
    case 2:
        --t.x;
        break;
    case 3:
        --t.y;
        break;
    case 4:
        ++t.y;
        break;
    }
    t.is_returned = true;
}

void move(Tractor &t) 
{
    switch(t.mv) 
    {
    case 1:
        --t.x;
        break;
    case 2:
        ++t.x;
        break;
    case 3:
        ++t.y;
        break;
    case 4:
        --t.y;
        break;
    }
    if (t.x == 0 && t.y != 0) {
        move_ret(t);
    }
}

void check(std::vector<Tractor> &v, int i, int n)
{
    for (int j = 0; j < n; j++) {
        if (j != i && v[j].x == v[i].x && v[j].y == v[i].y) {
            move_ret(v[j]);
            check(v, j, n);
            break;
        }
    }
}

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Tractor> v;
    for (int i = 0; i < n; i++) {
        Tractor t;
        std::cin >> t.x >> t.y >> t.mv; 
        v.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        move(v[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].x == v[j].x && v[i].y == v[j].y) {
                if (!v[i].is_returned) {
                    move_ret(v[i]);
                }
                if (!v[j].is_returned) {
                    move_ret(v[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && v[i].x == v[j].x && v[i].y == v[j].y) {
                if (!v[i].is_returned) {
                    move_ret(v[i]);
                    check(v, i, n);
                }
                if (!v[j].is_returned) {
                    move_ret(v[j]);
                    check(v, j, n);
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << v[i].x << ' ' << v[i].y << std::endl;
    }
    return 0;
}