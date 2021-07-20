public class Kassa {
    boolean ocupied;
    int number;
    long minutes;
    public Kassa(boolean ocupied, int number, long minutes) {
        this.number=number;
        this.ocupied = ocupied;
        this.minutes=minutes;
    }
    public int getNumber() {
        return number;
    }
    public boolean isOcupied() {
        return ocupied;
    }
    public void setOcupied(boolean ocupied) {
        this.ocupied = ocupied;
    }
    public long getMinutes() {
        return minutes;
    }
    public void setMinutes(long minutes) {
        this.minutes = minutes;
    }
}
