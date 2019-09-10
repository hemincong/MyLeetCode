mutex mtx;
condition_variable cv;

class FooBar {
private:
    int n;
    bool ready = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lck, [this]() {return ready==false;});
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            this->ready = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
             cv.wait(lck, [this]() {return ready==true;});

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            this->ready = false;
            cv.notify_all();
        }
    }
};
