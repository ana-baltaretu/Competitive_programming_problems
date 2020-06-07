import java.util.Scanner;

public class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static boolean interior(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    static boolean checkBad(char[][] a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') {
                    for (int d = 0; d < 4; d++) {
                        int ii = i + dx[d];
                        int jj = j + dy[d];
                        if (interior(ii, jj, n, m) == true && a[ii][jj] == 'G')
                            return false;
                        if (interior(ii, jj, n, m) == true && a[ii][jj] == '.')
                            a[ii][jj] = '#';
                    }
                }
            }
        }
        return true;
    }

    static void lee(char[][] a, int n, int m, int i, int j, int[][] viz) {
        if (a[i][j] == 'G')
            a[i][j] = '.';
        viz[i][j] = 1;
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (interior(ii, jj, n, m) == true && a[ii][jj] != '#' && viz[ii][jj] == 0)
                lee(a, n, m, ii, jj, viz);
        }
    }

    static boolean checkGood(char[][] a, int n, int m) {
        int[][] viz = new int[n][m];
        if (a[n - 1][m - 1] != 'B' && a[n - 1][m - 1] != '#')
            lee(a, n, m, n - 1, m - 1, viz);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'G')
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer tests = in.nextInt();
        while (tests-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = new char[n][m];
            for (int i = 0; i < n; i++) {
                String s = in.next();
                a[i] = s.toCharArray();
            }
            if (checkBad(a, n, m) == false) {
                System.out.println("No");
            } else {
                if (checkGood(a, n, m) == false)
                    System.out.println("No");
                else System.out.println("Yes");
            }
        }
    }
}
