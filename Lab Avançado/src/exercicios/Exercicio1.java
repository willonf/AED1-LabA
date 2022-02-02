package exercicios;

public class Exercicio1 {

    static class contadorTempo {
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

    static class Relogio extends Thread {
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
                System.out.println(this.contTempo.tick);
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                this.getContTempo().nextTick();
            }
        }
    }

    public static void main(String[] args) {
        Relogio relogio1 = new Relogio();
        Relogio relogio2 = new Relogio(5, 1);
        Relogio relogio3 = new Relogio(10);
        relogio1.start();
        relogio2.start();
        relogio3.start();
    }
}

