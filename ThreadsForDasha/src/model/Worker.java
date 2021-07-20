package model;

public class Worker {
    private boolean busy;
    private int numb;
    private long executionTime;

    public Worker(boolean busy, int numb, long velocity) {
        this.busy = busy;
        this.numb = numb;
        this.executionTime = velocity;
    }

    public boolean isBusy() {
        return busy;
    }

    public void setBusy(boolean busy) {
        this.busy = busy;
    }

    public int getNumb() {
        return numb;
    }

    public void setNumb(int numb) {
        this.numb = numb;
    }

    public long getExecutionTime() {
        return executionTime;
    }

    public void setExecutionTime(long executionTime) {
        this.executionTime = executionTime;
    }
}
