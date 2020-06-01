package B;

import java.util.Scanner;

public class NewMain {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        in.nextLine();
        while (tests-- > 0) {

            String current = in.nextLine();

            int[] leftZeros = new int[current.length() + 1];
            int[] leftOnes = new int[current.length() + 1];
            if (current.charAt(0) == '0')
                leftOnes[0] = 1;
            else leftZeros[0] = 1;
            for (int i = 1; i < current.length(); i++) {
                if (current.charAt(i) == '0')
                    leftZeros[i] = leftZeros[i - 1];
                else leftZeros[i] = leftZeros[i - 1] + 1;
                if (current.charAt(i) == '1')
                    leftOnes[i] = leftOnes[i - 1];
                else leftOnes[i] = leftOnes[i - 1] + 1;
            }

            int[] rightZeros = new int[current.length() + 1];
            int[] rightOnes = new int[current.length() + 1];
            if (current.charAt(current.length() - 1) == '0')
                rightOnes[current.length() - 1] = 1;
            else rightZeros[current.length() - 1] = 1;
            for (int i = current.length() - 2; i >= 0; i--) {
                if (current.charAt(i) == '0')
                    rightZeros[i] = rightZeros[i + 1];
                else rightZeros[i] = rightZeros[i + 1] + 1;
                if (current.charAt(i) == '1')
                    rightOnes[i] = rightOnes[i + 1];
                else rightOnes[i] = rightOnes[i + 1] + 1;
            }

            int mn = Integer.MAX_VALUE;
            for (int i = 0; i < current.length(); i++) {
                //System.out.println(leftZeros[i] +" " + leftOnes[i] + " " + rightZeros[i] + " " + rightOnes[i]);
                int mn1 = Math.min(leftZeros[i] + rightOnes[i + 1], leftZeros[i] + rightZeros[i + 1]);
                int mn2 = Math.min(leftOnes[i] + rightOnes[i + 1], leftOnes[i] + rightZeros[i + 1]);
                mn = Math.min(mn, Math.min(mn1, mn2));
            }
            System.out.println(mn);
        }
    }
}
