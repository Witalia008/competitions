import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        String s = in.next();
        SegmentTree root = buildTree(s, 0, n - 1);
        for (int _t = 0; _t < m; _t++) {
            int type = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            if (type == 1) {
                root.replace(a - 1, b);
            } else {
                out.println(root.get(a - 1, b - 1)[0].subseg);
            }
        }
    }

    private SegmentTree buildTree(String s, int from, int to) {
        if (from == to) {
            return new SegmentTree(s.charAt(from) - '0', from);
        }
        int mid = (from + to) >> 1;
        return new SegmentTree(
                buildTree(s, from, mid),
                buildTree(s, mid + 1, to)
        );
    }
}

class SegmentTree {
    public void replace(int pos, int newVal) {
        if (from == to) {
            values = init();
            values[newVal % 3].set();
            return;
        }
        int mid = (from + to) >> 1;
        if (pos <= mid) {
            leftSon.replace(pos, newVal);
        } else {
            rightSon.replace(pos, newVal);
        }
        update();
    }

    public ValueType[] get(int from, int to) {
        if (from == this.from && to == this.to) {
            return values;
        }
        int mid = (this.from + this.to) >> 1;
        if (to <= mid) {
            return leftSon.get(from, to);
        } else if (from > mid) {
            return rightSon.get(from, to);
        }
        return merge(
                leftSon.get(from, mid),
                rightSon.get(mid + 1, to)
        );
    }

    static class ValueType {
        long prefix, suffix, subseg, entire;

        void set() {
            prefix = suffix = subseg = entire = 1;
        }

        void clear() {
            prefix = suffix = subseg = entire = 0;
        }
    }

    int from, to;
    ValueType[] values;
    SegmentTree leftSon, rightSon;

    SegmentTree(int value, int pos) {
        values = init();
        from = to = pos;
        values[value % 3].set();
    }

    SegmentTree(SegmentTree left, SegmentTree right) {
        from = left.from;
        to = right.to;
        leftSon = left;
        rightSon = right;
        update();
    }

    private void update() {
        values = merge(leftSon.values, rightSon.values);
    }

    private static ValueType[] init() {
        ValueType[] values = new ValueType[3];
        for (int i = 0; i < values.length; i++) {
            values[i] = new ValueType();
            values[i].clear();
        }
        return values;
    }

    private static ValueType[] merge(ValueType[] left, ValueType[] right) {
        ValueType[] values = init();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int k = (i + j) % 3;
                values[k].subseg += left[i].suffix * right[j].prefix;
                values[k].prefix += left[i].entire * right[j].prefix;
                values[k].suffix += left[i].suffix * right[j].entire;
                values[k].entire += left[i].entire * right[j].entire;
            }
        }
        for (int k = 0; k < 3; k++) {
            values[k].subseg += left[k].subseg + right[k].subseg;
            values[k].prefix += left[k].prefix;
            values[k].suffix += right[k].suffix;
        }
        return values;
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
