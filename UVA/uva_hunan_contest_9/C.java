import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner inf = new Scanner(System.in);
        int n = inf.nextInt();
        String[] s = new String[5];
        inf.nextLine();
        for (int i = 0; i < 5; ++i)
            s[i] = inf.nextLine();
        for (int i = 0; i < 4 * n; i += 4) {
            if (s[2].charAt(i) == '*') {
                if (s[3].charAt(i) == '*')
                    System.out.print(2);
                else
                    System.out.print(3);
            } else
                System.out.print(1);
        }
        System.out.println();
    }
}
