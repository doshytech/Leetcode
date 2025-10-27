class Foo {
public:
    int ct;
    mutex m;
    condition_variable cv;
    Foo() {
        ct = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ct = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(ct!=1){
            cv.wait(lock);
        }
        printSecond();
        ct = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove t
         unique_lock<mutex> lock(m);
        while(ct!=2){
            cv.wait(lock);
        }
        printThird();
        ct = 3;
        cv.notify_all();
    }
};