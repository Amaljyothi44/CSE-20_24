public class Value {

    private int value;

    public Value() {
    }

    public Value(int i) {
        this.value = i;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {

        System.out.println("Value#setValue: " + value);

        synchronized (this) {
            System.out.println("Before: " + value);
            this.value = value;
            System.out.println("After: " + value);
        }

    }
}
