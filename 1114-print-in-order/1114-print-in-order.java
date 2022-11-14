class Foo {
    private Semaphore secondSemaphore;
    private Semaphore thirdSemaphore;
    
    public Foo() {
        secondSemaphore = new Semaphore(0);
        thirdSemaphore = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        secondSemaphore.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        secondSemaphore.acquire();
        printSecond.run();
        thirdSemaphore.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        thirdSemaphore.acquire();
        printThird.run();
    }
}