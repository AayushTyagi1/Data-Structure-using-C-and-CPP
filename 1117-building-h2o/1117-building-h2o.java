import java.util.concurrent.*;
class H2O {
    
    Semaphore H, O;
    public H2O() {
        H = new Semaphore(2, true);
        O = new Semaphore(0, true);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		H.acquire();
        releaseHydrogen.run();
        O.release();
        
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        O.acquire(2);
		releaseOxygen.run();
        H.release(2);
    }
}