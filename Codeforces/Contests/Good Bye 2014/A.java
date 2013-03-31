import java.util.Scanner;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        boolean[] fl = new boolean[n];
        fl[0] = true;
        for (int i = 0; i + 1 < n; ++i) {
            int a = sc.nextInt();
            fl[i + a] |= fl[i];
        }
        System.out.println(fl[t - 1] ? "YES" : "NO");
    }
}
