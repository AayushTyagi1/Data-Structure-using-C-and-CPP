class Foo {
    private Object lock1;
    private Object lock2;
    private boolean oneDone;
    private boolean twoDone;
    
    public Foo() {
        lock1 = new Object();
        lock2 = new Object();
        oneDone = false;
        twoDone = false;
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (lock1) {
            printFirst.run();
            oneDone = true;
            lock1.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (lock1) {
            synchronized (lock2) {
                while (!oneDone) {
                    lock1.wait();
                }
                printSecond.run();
                twoDone = true;
                lock2.notifyAll();
            }
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (lock2) {
            while (!twoDone) {
                lock2.wait();
            }
            printThird.run();
        }
    }
}