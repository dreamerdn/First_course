package LS;

public class firstTaxi {
    static int clientsOfFirst = 0;
    public static synchronized int firstTaxi() {
        clientsOfFirst++;
        return clientsOfFirst;
    }
}