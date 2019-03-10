namespace numbers
{
    class complex_stack 
    {
        enum { FIRST_SIZE = 16 };
        size_t capacity;
        complex *stack;
        size_t top;
        void extend(void)
        {
            capacity <<= 1;
            complex *new_stack = new complex[capacity];
            for (size_t i = 0; i < top; i++) {
                new_stack[i] = stack[i];
            }
            delete[] stack;
            stack = new_stack;
        }
    public:
        complex_stack() : capacity(FIRST_SIZE), top(0)
        {
            stack = new complex[FIRST_SIZE];
        }
        complex_stack(const complex_stack &st) 
        {
            capacity = st.capacity;
            stack = new complex[capacity];
            top = st.top;
            for(size_t i = 0; i < top; i++) {
                stack[i] = st.stack[i];
            }
        }
        ~complex_stack() 
        {
            delete[] stack;
        }
        complex_stack operator=(const complex_stack &st)
        {
            capacity = st.capacity;
            top = st.top;
            delete[] stack;
            stack = new complex[capacity];
            for (size_t i = 0; i < top; i++) {
                stack[i] = st.stack[i];
            }
            return *this;
        }
        size_t size(void) const 
        {
            return top;
        }
        complex & operator[](size_t i) const
        {
            return stack[i];
        }
        complex_stack operator<<(const complex &c) const 
        {
            complex_stack tmp = *this;
            if (top >= capacity) {
                tmp.extend();
            }
            tmp.stack[tmp.top++] = c;
            return tmp;
        }
        complex & operator+(void) const
        {
            return stack[top - 1];
        }
        complex_stack operator~(void) const
        {
            complex_stack tmp = *this;
            tmp.top--;
            return tmp;
        }
    };
}
