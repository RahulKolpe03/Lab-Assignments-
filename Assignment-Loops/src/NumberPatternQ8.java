public class NumberPatternQ8 {

    public static void main(String[] args) {

        for (int temp = 6; temp >= 1; temp--) {

            for (int temp1 = 1; temp1 <= temp; temp1++) {

                System.out.print(temp1 + " ");
            }

            System.out.println();
        }
    }
}