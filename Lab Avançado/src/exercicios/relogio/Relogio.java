package exercicios.relogio;

public class Relogio implements Runnable {
    private contadorTempo contTempo;
    private int ticks;
    private int initialTick;

    public Relogio(int ticks, int initialTick) {
        this.setInitialTick(initialTick);
        this.setTicks(ticks);
        this.setContTempo(new contadorTempo(this.getInitialTick()));
    }

    public Relogio(int ticks) {
        this.setInitialTick(0);
        this.setTicks(ticks);
        this.setContTempo(new contadorTempo(this.getInitialTick()));
    }

    public Relogio() {
        this.setInitialTick(0);
        this.setTicks(0);
        this.setContTempo(new contadorTempo());
    }

    public int getTicks() {
        return ticks;
    }

    public void setTicks(int ticks) {
        this.ticks = ticks;
    }

    public int getInitialTick() {
        return initialTick;
    }

    public void setInitialTick(int initialTick) {
        this.initialTick = initialTick;
    }

    public contadorTempo getContTempo() {
        return contTempo;
    }

    public void setContTempo(contadorTempo contTempo) {
        this.contTempo = contTempo;
    }

    public void run() {
        for (int i = 0; i <= this.getTicks(); i++) {
            System.out.println(this.contTempo.getTick());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            this.getContTempo().nextTick();
        }
    }
}
