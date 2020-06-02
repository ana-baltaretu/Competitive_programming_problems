package B;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            int N = in.nextInt();
            int[] a = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int total = 1, i = 0;
            while (i < N) {
                while (i < N && total >= a[i]) {
                    i++;
                    total++;
                }
                if (i < N) {
                    int current = 0;
                    int j = i;
                    boolean ok = false;
                    while (j < N) {
                        current++;
                        if (total + current - 1 >= a[j]) {
                            ok = true;
                            break;
                        }
                        j++;
                    }
                    if (ok == true) {
                        total += current;
                        i = j + 1;
                    } else break;
                }
            }
            System.out.println(total);
        }
    }
}
