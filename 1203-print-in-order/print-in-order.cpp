#include <latch>

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        a_done.count_down();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        a_done.wait();
        printSecond();
        b_done.count_down();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        b_done.wait();
        printThird();
    }

private:
    std::latch a_done{1};
    std::latch b_done{1};
};