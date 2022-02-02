package threads;

public class Thread2Runnable {
    static class RunnerRunnable implements Runnable {
        public void run() {
            for (int i = 0; i < 5; i++) {
                System.out.printf("Hello %d - Thread: %s\n", i, Thread.currentThread().getName());
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Thread thread1 = new Thread(new RunnerRunnable());
        Thread thread2 = new Thread(new RunnerRunnable());

        thread1.start();
        thread2.start();
    }
}
