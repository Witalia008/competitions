import java.util.Scanner;

/**
 * Created by Kozhukhivskyi on 06.10.2014.
 */

public class Main {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long res = n / 2;
        if (n % 2 != 0)
            res -= n;
        System.out.println(res);
    }
}
