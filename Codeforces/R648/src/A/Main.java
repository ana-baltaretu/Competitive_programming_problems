package A;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer tests = in.nextInt();
        while (tests-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[n][m];
            int[] row = new int[n], col = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = in.nextInt();
                    if (a[i][j] == 1) {
                        col[j] = 1;
                        row[i] = 1;
                    }
                }
            }
            int freeRow = 0, freeCol = 0;
            for (int i = 0; i < n; i++) {
                if (row[i] == 0)
                    freeRow++;
            }
            for (int j = 0; j < m; j++) {
                if (col[j] == 0)
                    freeCol++;
            }
            int counter = 0;
            while (freeRow > 0 && freeCol > 0) {
                counter++;
                freeRow--;
                freeCol--;
            }
            if (counter % 2 == 0) {
                System.out.println("Vivek");
            } else System.out.println("Ashish");

        }
    }
}
