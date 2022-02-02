package threads;

public class Thread1 {
    static class Runner extends Thread {
        public void run() {
            for (int i = 0; i < 5; i++) {
                System.out.printf("Hello %d - Thread: %s\n", i, java.lang.Thread.currentThread().getName());
                try {
                    sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Runner runner1 = new Runner();
        Runner runner2 = new Runner();

        runner1.start();
        runner2.start();
    }
}
