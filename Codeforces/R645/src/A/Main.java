package A;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            int N = in.nextInt();
            int M = in.nextInt();
            if (N % 2 == 0) {
                System.out.println(N / 2 * M);
            } else if (M % 2 == 0) {
                System.out.println(M / 2 * N);
            } else System.out.println(N / 2 * M + M / 2 + 1);
        }
    }
}
