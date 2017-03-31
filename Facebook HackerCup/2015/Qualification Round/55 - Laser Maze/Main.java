import javafx.util.Pair;

import java.awt.*;
import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        InputReader in = new InputReader(System.in);
//        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        InputReader in = new InputReader(new FileInputStream(new File("input.txt")));
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    private static final String states = "<^>v";
    private static final Point[] moves = {
            new Point(0, 1),
            new Point(1, 0),
            new Point(0, -1),
            new Point(-1, 0)};
    private char[][] field;

    private boolean inside(Point pos) {
        return pos.x >= 0 && pos.y >= 0
                && pos.x < field.length
                && pos.y < field[0].length;
    }

    private char rotate(char ch, int step) {
        int idx = states.indexOf(ch);
        if (idx != -1) {
            idx = (idx + step) % states.length();
            ch = states.charAt(idx);
        }
        return ch;
    }

    private boolean canGoHere(Point pos, int step) {
        if (field[pos.x][pos.y] != '.') {
            return false;
        }
        for (int k = 0; k < moves.length; k++) {
            Point cur = (Point) pos.clone();
            while (inside(cur) && field[cur.x][cur.y] == '.') {
                cur.translate(moves[k].x, moves[k].y);
            }
            if (inside(cur) && states.charAt(k)
                    == rotate(field[cur.x][cur.y], step)) {
                return false;
            }
        }
        return true;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int n = in.nextInt();
            int m = in.nextInt();
            field = new char[n][];
            Point start = null;
            Point finish = null;
            for (int i = 0; i < n; i++) {
                String s = in.next();
                if (s.indexOf('S') != -1) {
                    start = new Point(i, s.indexOf('S'));
                }
                if (s.indexOf('G') != -1) {
                    finish = new Point(i, s.indexOf('G'));
                }
                s = s.replaceAll("[GS]", ".");
                field[i] = s.toCharArray();
            }
            int ans = Integer.MAX_VALUE;

            // Initialize variables
            Queue<Pair<Point, Integer>> queue = new LinkedList<>();
            int[][][] func = new int[n][m][4];
            // Initial values
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    Arrays.fill(func[i][j], Integer.MAX_VALUE);
                }
            }
            func[start.x][start.y][0] = 0;
            queue.add(new Pair<>(start, 0));
            // Algorithm
            while (!queue.isEmpty()) {
                Point pos = queue.element().getKey();
                int step = queue.element().getValue();
                int nextStep = (step + 1) % func[0][0].length;
                queue.remove();

                for (int k = 0; k < moves.length; k++) {
                    Point cur = (Point) pos.clone();
                    cur.translate(moves[k].x, moves[k].y);
                    if (inside(cur)
                            && func[cur.x][cur.y][nextStep] == Integer.MAX_VALUE
                            && canGoHere(cur, nextStep)) {
                        func[cur.x][cur.y][nextStep] = func[pos.x][pos.y][step] + 1;
                        queue.add(new Pair<>(cur, nextStep));
                    }
                }
            }
            // Get the answer
            for (int k = 0; k < func[0][0].length; k++) {
                ans = Math.min(ans, func[finish.x][finish.y][k]);
            }

            out.println(ans == Integer.MAX_VALUE ? "impossible" : ans);
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}
