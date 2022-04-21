package socketstcp;

import java.io.Serializable;

public class Vetores implements Serializable {
    private final int[] vetor1;
    private final int[] vetor2;

    public Vetores() {
        vetor1 = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        vetor2 = new int[]{20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    }

    public int[] getVetor1() {
        return vetor1;
    }

    public int[] getVetor2() {
        return vetor2;
    }

}
