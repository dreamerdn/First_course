package L1_11;

public class VisitorsQueue {
    int cnt;
    boolean busy;
    public VisitorsQueue (boolean busy,int cnt){
        this.busy=busy;
        this.cnt=cnt;
    }
    public boolean getBusy(){return busy;}
    public void setBusy(boolean busy){this.busy=busy;}
    public int getCnt(){
        return cnt;
    }
    public void setCnt(int cnt){
        this.cnt=cnt;
    }
}
