package A;

import java.util.Scanner;

public class Main {

    static long mnDigit;
    static long mxDigit;

    static void updateMinMax(long N) {
        while (N > 0) {
            mnDigit = Math.min(mnDigit, N % 10);
            mxDigit = Math.max(mxDigit, N % 10);
            N /= 10;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            long N = in.nextLong();
            long K = in.nextLong();
            mnDigit = 9;
            while (K-- > 1 && mnDigit > 0) {
                mnDigit = 9;
                mxDigit = 0;
                updateMinMax(N);
                N = N + mnDigit * mxDigit;
            }
            System.out.println(N);
        }
    }
}
