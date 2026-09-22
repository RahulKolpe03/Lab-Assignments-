

public class ConsoleInput {

    // To take String input
    public static String getString() {

        try {

            byte arrInput[] = new byte[100];

            int length = System.in.read(arrInput);

            byte[] arrFinal = new byte[length - 2];

            System.arraycopy(
                arrInput,
                0,
                arrFinal,
                0,
                length - 2
            );

            String objString = new String(arrFinal);

            return objString;

        } catch (Exception e) {

            e.printStackTrace();
        }

        return null;
    }


    // To take integer input
    public static int getInt() {

        return Integer.parseInt(getString());
    }


    // To take float input
    public static float getFloat() {

        String objString = getString();

        float data = Float.parseFloat(objString);

        return data;
    }
}

