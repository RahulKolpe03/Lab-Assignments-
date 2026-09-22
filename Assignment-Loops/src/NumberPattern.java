
public class NumberPattern {

    public static void main(String[] args) {

        int num = 1;

        for (int temp = 1; temp <= 4; temp++) {

            for (int temp1 = 1; temp1 <= temp; temp1++) {

                System.out.print(num + " ");
                num++;
            }

            System.out.println();
        }
    }
}
