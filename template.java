/*
 * Author: Manash Baul <mximpaid@gmail.com>
 * @param: The deeper you go, the more still you become.
 */

import java.io.*;
import java.util.*;

public class gtest {
    static final boolean LOCAL = true;

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer st;

    static void _read() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        st = new StringTokenizer("");
    }

    static String next() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(in.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    static int nextInt() { return Integer.parseInt(next()); }
    static long nextLong() { return Long.parseLong(next()); }
    static double nextDouble() { return Double.parseDouble(next()); }

    public static void main(String[] args) {
        _read();

    }
}
