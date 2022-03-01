public class Test {

    public static void main(String[] args) {

        Value value = new Value();

        for (int i = 0; i < 10; i++) {

            int finalI = i;

            new Thread(
                    () -> value.setValue(finalI)
            ).start();

        }

    }
}
