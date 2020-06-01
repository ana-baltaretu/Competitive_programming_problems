import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer tests = in.nextInt();
        while (tests-- > 0) {
            int n = in.nextInt();
            int x = in.nextInt();
            int odd = 0, even = 0;
            for (int i = 0; i < n; i++) {
                int current = in.nextInt();
                if (current % 2 == 0)
                    even++;
                else odd++;
            }
            if (x % 2 == 1 && x <= odd)
                System.out.println("Yes");
            else {
                x = x - Math.min(Math.max(0, x - 2), Math.max(0, even - 1));
                even = Math.min(even, 1);
                if (odd == 0)
                    System.out.println("No");
                else if(x % 2 == 1 && odd >= x) {
                    System.out.println("Yes");
                } else {
                    if (x % 2 == 0 && x <= odd + 1 && even == 1)
                        System.out.println("Yes");
                    else {
                        System.out.println("No");
                    }
                }
            }
        }
    }
}
