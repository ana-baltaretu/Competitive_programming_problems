package B;

import java.util.Scanner;

public class Main {

    static boolean isSorted(int n, int[] a) {
        for (int i = 1; i < n; i++)
            if (a[i] < a[i - 1])
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer tests = in.nextInt();
        while (tests-- > 0) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            int type1 = 0, type0 = 0;
            for (int i = 0; i < n; i++) {
                b[i] = in.nextInt();
                if (b[i] == 1)
                    type1++;
                else type0++;
            }
            if (isSorted(n, a) == true)
                System.out.println("Yes");
            else {
                if (type0 > 0 && type1 > 0)
                    System.out.println("Yes");
                else System.out.println("No");
            }
        }
    }
}
