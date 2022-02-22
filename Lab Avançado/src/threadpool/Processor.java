package threadpool;

public class Processor implements Runnable {

    private int id;

    public Processor(int id) {
        this.id = id;
    }

    @Override
    public void run() {
        System.out.println("Starting: " + id);
        try {
            Thread.sleep(2000);
        } catch (InterruptedException ignored) {
        }
        System.out.println("Completed: " + id);
    }
}
