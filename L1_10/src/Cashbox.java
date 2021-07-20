public class Cashbox {

        boolean busy;
        int numb;
        long min;

        public Cashbox( boolean busy,int numb, long min){
            this.busy=busy;
            this.numb=numb;
            this.min=min;
        }

        public int getNumb(){ return numb; }
        public long getMin(){ return min; }
        public void setBusy(boolean busy){
            this.busy = busy;
        }
}


