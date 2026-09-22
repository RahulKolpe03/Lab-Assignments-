
public class SortArray {

    public static void main(String[] args) {

        System.out.print("Enter size of array: ");
        int size = ConsoleInput.readInt();

        int[] arr = new int[size];

        // Taking array elements
        for (int temp = 0; temp < size; temp++) {
            System.out.print("Enter element " + (temp + 1) + ": ");
            arr[temp] = ConsoleInput.readInt();
        }

        // Sorting array
        for (int temp = 0; temp < size - 1; temp++) {

            for (int temp1 = 0; temp1 < size - 1 - temp; temp1++) {

                if (arr[temp1] > arr[temp1 + 1]) {

                    int swap = arr[temp1];
                    arr[temp1] = arr[temp1 + 1];
                    arr[temp1 + 1] = swap;
                }
            }
        }

        // Display sorted array
        System.out.println("Sorted Array:");

        for (int temp = 0; temp < size; temp++) {
            System.out.print(arr[temp] + " ");
        }
    }
}