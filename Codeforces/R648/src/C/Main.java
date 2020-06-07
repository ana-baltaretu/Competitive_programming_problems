package C;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] pozA = new int[n + 1];
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            pozA[a[i]] = i;
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
            int dif;
            if (i < pozA[b[i]]) {
                dif = pozA[b[i]] - i;
            } else {
                dif = pozA[b[i]] - i + n;
            }
            Integer val = 0;
            if (mp.containsKey(dif)) {
                val = mp.remove(dif);
            }
            val++;
            if (val > mx)
                mx = val;
            mp.put(dif, val);
        }
        System.out.println(mx);
    }
}
