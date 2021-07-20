public class Worker {
    boolean isWorking;
    int number;
    int minutesOfWork;

    public Worker(boolean isWorking, int number, int minutesOfWork) {
        this.number = number;
        this.isWorking = isWorking;
        this.minutesOfWork = minutesOfWork;
    }
    public int getNumber(){
        return number;
    }
    public void setWorking(boolean isWorking){
        this.isWorking = isWorking;
    }
    public long getMinutesOfWork() {
        return minutesOfWork;
    }
}
