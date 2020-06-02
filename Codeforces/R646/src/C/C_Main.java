package C;

import java.util.Scanner;
import java.util.Vector;


public class C_Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            int N = in.nextInt();
            Vector<Integer>[] neighbours = new Vector[N + 1];
            for (int i = 1; i <= N; i++) {
                neighbours[i] = new Vector<>();
            }
            int root = in.nextInt();
            for (int i = 1; i < N; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                neighbours[a].add(b);
                neighbours[b].add(a);
            }

            if (neighbours[root].size() <= 1) {
                System.out.println("Ayush");
            } else if (N % 2 == 0) {
                System.out.println("Ayush");
            } else System.out.println("Ashish");
        }
    }
}
