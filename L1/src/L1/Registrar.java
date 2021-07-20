package L1;

public class Registrar {
    boolean occupied;
    int number;
    long minutes;

    public Registrar(boolean occupied, int number, long minutes) {
        this.number = number;
        this.occupied = occupied;
        this.minutes = minutes;
    }
    public int getNumber(){
        return number;
    }

    public void setOccupied(boolean occupied){
        this.occupied = occupied;
    }
    public long getMinutes(){
        return minutes;
    }


}
