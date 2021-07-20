public class Ship {
    boolean busy;
    int numb;
    long min;
    int k;

    public Ship( boolean busy,int numb, long min, int k){
        this.busy=busy;
        this.numb=numb;
        this.min=min;
        this.k=k;
    }

    public int getNumb(){ return numb; }
    public long getMin(){ return min; }
    public int getK() {return k;}
    public void setBusy(boolean busy){
        this.busy = busy;
    }
}
