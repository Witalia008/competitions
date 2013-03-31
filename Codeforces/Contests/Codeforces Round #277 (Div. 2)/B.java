import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Kozhukhivskyi on 06.10.2014.
 */

public class Main {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] B = new int[n][];
        int[][] A = new int[n][];

        for (int i = 0; i < n; i++) {
            B[i] = new int[m];
            for (int j = 0; j < m; j++) {
                B[i][j] = sc.nextInt();
            }
            A[i] = new int[m];
            Arrays.fill(A[i], 1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (B[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        A[k][j] = 0;
                    }
                    for (int k = 0; k < m; k++) {
                        A[i][k] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (B[i][j] == 1) {
                    boolean flag = false;
                    for (int k = 0; k < n; k++) {
                        flag |= A[k][j] != 0;
                    }
                    for (int k = 0; k < m; k++) {
                        flag |= A[i][k] != 0;
                    }
                    if (!flag) {
                        System.out.println("NO");
                        System.exit(0);
                    }
                }
            }
        }
        System.out.println("YES");
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }
}
