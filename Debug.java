/*
 * Author: Manash Baul <mximpaid@gmail.com>
 * Simple debug helper for LOCAL development.
 */
public class Debug {
    public static void println(Object... args) {
        if (args.length == 0) {
            System.err.println();
            return;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < args.length; i++) {
            if (i > 0) sb.append(" ");
            sb.append(args[i]);
        }
        System.err.println(sb.toString());
    }

    public static void debug(String name, Object value) {
        System.err.println(name + " == " + value);
    }
}
