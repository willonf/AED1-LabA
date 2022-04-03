package deadlock;

import java.util.concurrent.locks.Lock;

public class AcquireLocks {
    public static void acquire(Lock firstLock, Lock secondLock) throws InterruptedException {
        while (true) {
            boolean gotFirstLock = false;
            boolean gotSecondLock = false;
            try {
                gotFirstLock = firstLock.tryLock();
                gotSecondLock = secondLock.tryLock();
            } finally {
                if (gotFirstLock && gotSecondLock) return;
                else if (gotFirstLock) firstLock.unlock();
                else if (gotSecondLock) secondLock.unlock();
            }
            Thread.sleep(1);
        }
    }
}