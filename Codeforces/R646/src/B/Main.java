package B;

import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {
            int oneCounter = 0, zeroCounter = 0;
            int lMostOne = -1, rMostOne = -1, lMostZero = -1, rMostZero = -1;
            int zerosAfterFirstOne = 0, zerosBeforeLastOne = 0, onesAfterFirstZero = 0, onesBeforeLastZero = 0;
            String current = in.nextLine();

            for (int i = 0; i < current.length(); i++) {
                if (current.charAt(i) == '0') {
                    if (lMostZero == -1)
                        lMostZero = i;
                    rMostZero = i;
                    zeroCounter++;
                } else {
                    if (lMostOne == -1)
                        lMostOne = i;
                    rMostOne = i;
                    oneCounter++;
                }
            }

            for (int i = 0; i < current.length(); i++) {
                if (current.charAt(i) == '0') {
                    if (i > lMostOne)
                        zerosAfterFirstOne++;
                    if (i < rMostOne)
                        zerosBeforeLastOne++;
                } else {
                    if (i > lMostZero)
                        onesAfterFirstZero++;
                    if (i < rMostZero)
                        onesBeforeLastZero++;
                }
            }
            char leftEdge = current.charAt(0), rightEdge = current.charAt(current.length() - 1);
            if (lMostOne == -1 || lMostZero == -1 || rMostOne < lMostZero || rMostZero < lMostOne)
                System.out.println(0);
            else {
                int mn1 = Math.min(zeroCounter, oneCounter);
                int mn2 = Math.min(zerosAfterFirstOne, zerosBeforeLastOne);
                int mn3 = Math.min(onesAfterFirstZero, onesBeforeLastZero);
                System.out.println(Math.min(Math.min(mn1, mn2), mn3));
            }

                /// 00011110
                /// ^  ^  ^^
                /// l  l  rr
                /// 101
                /// llr
                /// 001100
                /// ^ ^^ ^
        }
    }
}
