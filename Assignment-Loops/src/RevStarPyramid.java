public class RevStarPyramid {

    public static void main(String[] args) {

        for (int temp = 5; temp >= 1; temp--) {

            for (int temp1 = 1; temp1 <= temp; temp1++) {

                System.out.print("*");
            }

            System.out.println();
        }
    }
}