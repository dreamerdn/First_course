import java.io.*;
import java.net.*;

public class Servermain {
    public static void main(String[] args) throws IOException, InterruptedException {
        new Servermain();
    }

    double sum1 = 0, sum2 = 0;
    DatagramSocket st;
    byte[] buf = new byte[100];
    DatagramPacket dp = new DatagramPacket(buf, 100);

    Servermain() throws IOException, InterruptedException {
        st = new DatagramSocket(12345);
        listen();
    }

    private void listen() throws IOException, InterruptedException {
        int a, b, c;
        st.receive(dp);
        String str = new String(dp.getData());
        str = str.substring(0, str.indexOf('\n'));
        System.out.println("number " + str + " recieved as a");
        a = Integer.parseInt(str);
        st.receive(dp);
        str = new String(dp.getData());
        str = str.substring(0, str.indexOf('\n'));
        System.out.println("number " + str + " recieved as b");
        b = Integer.parseInt(str);
        st.receive(dp);
        str = new String(dp.getData());
        str = str.substring(0, str.indexOf('\n'));
        System.out.println("number " + str + " recieved as c");
        c = Integer.parseInt(str);
        Thread t1 = new Thread(new Runnable() {
            public void run() {
                for (int i = a; i < b; i++) {
                    sum1 += (i - 1) * (i - 1);
                }
            }
        }), t2 = new Thread(new Runnable() {
            public void run() {
                for (int i = b; i < c; i++) {
                    sum1 += 2 * i / (7 * i + 1);
                }
            }
        });
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        sendBack();
    }

    private void sendBack() throws IOException {
        String str = String.valueOf(sum1 - sum2);
        byte[] send = str.getBytes();
        dp = new DatagramPacket(send, send.length, InetAddress.getByName("localhost"), 12346);
        st.send(dp);
        st.close();
    }
}
