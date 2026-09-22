
public class ConsoleInput {

    public static int readInt() {

        int num = 0;

        try {
            int ch;

            do {
                ch = System.in.read();
            } while (ch == '\n' || ch == '\r' || ch == ' ');

            while (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
                ch = System.in.read();
            }

        } catch (Exception e) {
            System.out.println("Invalid input");
        }

        return num;
    }
}