package exercicios;

public class contadorTempo {
    private int tick;

    public contadorTempo(int tick) {
        this.tick = tick;
    }

    public contadorTempo() {
        this.tick = 0;
    }

    public int getTick() {
        return tick;
    }

    public void setTick(int tick) {
        this.tick = tick;
    }

    public void nextTick() {
        this.setTick(this.getTick() + 1);
    }
}
