import java.util.Scanner;

public class G {
    public static void main(String[] args) {
        Scanner inf = new Scanner(System.in);
        int n = inf.nextInt();
        inf.nextLine();
        String[] students = inf.nextLine().split(" ");
        int q = inf.nextInt();
        while (q-- > 0) {
            int p = inf.nextInt() - 1;
            if (students[p].equals("?") == false) {
                System.out.println(students[p]);
            } else {
                int l = p, r = p;
                while ((l < 0 || students[l].equals("?")) && (r >= n || students[r].equals("?"))) {
                    --l; ++r;
                }
                if (l < 0 || students[l].equals("?")) {
                    for (int i = 0; i < p - l; ++i)
                        System.out.print("left of ");
                    System.out.println(students[r]);
                } else if (r >= n || students[r].equals("?")) {
                    for (int i = 0; i < r - p; ++i)
                        System.out.print("right of ");
                    System.out.println(students[l]);
                } else
                    System.out.println("middle of " + students[l] + " and " + students[r]);

            }
        }
    }
}
