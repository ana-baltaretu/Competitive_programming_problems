package Reducing_Dishes_1402;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        String[] num = input.substring(1, input.length() - 1).split(",");
        int[] numbers = new int[num.length];
        for (int i = 0; i < num.length; i++)
            numbers[i] = Integer.valueOf(num[i]);
        Solution solution = new Solution();
        System.out.println(solution.maxSatisfaction(numbers));
    }
}
