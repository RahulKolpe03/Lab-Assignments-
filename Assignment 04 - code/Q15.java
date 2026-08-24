public class Q15 {
    public static void main(String[] args) {
        StringBuilder sb;
        for (int i = 1; i <= 5; i++) {
            sb = new StringBuilder();
            for (int j = 1; j <= i; j++) {
                sb.append(i);
                if (j < i) sb.append("*");
            }
            System.out.println(sb);
        }
        for (int i = 5; i >= 2; i--) {
            sb = new StringBuilder();
            for (int j = 1; j <= i; j++) {
                sb.append(i);
                if (j < i) sb.append("*");
            }
            System.out.println(sb);
        }
    }
}