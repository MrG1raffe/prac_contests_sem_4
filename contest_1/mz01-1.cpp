class Sum 
{
    int x;
public:
    Sum(int a, int b) : x(a + b) {}
    Sum(const Sum &a, int b) : x(a.x + b) {}
    int get() const 
    {
        return x;
    }
};
