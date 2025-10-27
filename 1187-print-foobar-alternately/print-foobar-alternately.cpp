class FooBar {
private:
    int n;

public:
    int t;
    condition_variable cv;
    mutex m;
    FooBar(int n) {
        this->n = n;
        t = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);    
        for (int i = 0; i < n; i++) {
            while(t&1){cv.wait(lock);}
        	printFoo();
            t++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(!(t&1)){cv.wait(lock);}
        	printBar();
            t++;
            cv.notify_all();
        }
    }
};