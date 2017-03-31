import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by witalia on 06.10.2014.
 */

public class Main {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int p = sc.nextInt() - 1;
        sc.nextLine();
        String s = sc.nextLine();

        int answer = 0;
        int left = s.length(), right = -1;
        for (int i = 0; i * 2 < s.length(); i++) {
            int d = Math.abs(s.charAt(i) - s.charAt(s.length() - 1 - i));
            answer += Math.min(d, Math.abs(26 - d));
            if (d != 0) {
                left = Math.min(left, i);
                right = i;
            }
        }
        if (p >= s.length() / 2) {
            p = s.length() - 1 - p;
        }
        if (right != -1) {
            if (p >= left && p <= right) {
                answer += Math.min(p + right - 2 * left, 2 * right - p - left);
            } else if (p < left) {
                answer += right - p;
            } else {
                answer += p - left;
            }
        }
        System.out.println(answer);
    }
}
