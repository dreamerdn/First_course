package L1_11_;

public class Workers {
    boolean busy;
    int numb;
    long min;

    public Workers( boolean busy,int numb, long min){
        this.busy=busy;
        this.numb=numb;
        this.min=min;
    }

    public int getNumb(){ return numb; }
    public long getMin(){ return min; }
    //public boolean getBusy(){ return busy; }
    public void setBusy(boolean busy){
        this.busy = busy;
    }
}
