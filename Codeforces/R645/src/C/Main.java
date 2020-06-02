package C;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            long x1 = in.nextInt();
            long y1 = in.nextInt();
            long x2 = in.nextInt();
            long y2 = in.nextInt();
            System.out.println((x2 - x1) * (y2 - y1) + 1);
        }
    }
}
