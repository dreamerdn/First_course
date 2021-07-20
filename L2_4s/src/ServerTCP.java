
import java.net.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ServerTCP {
    static int countClients=0;

    public static void main(String[] args) throws IOException {
        ServerSocket sock = null;
        InputStream is;
        OutputStream os;

        try{
            sock = new ServerSocket(1024); //Сокет сервера, работающего локально на порту 1024
            while (true) {
                Socket client = sock.accept(); //Подключение клиента
                countClients++;
                System.out.println("\nClient "+countClients+" connected");

                is = client.getInputStream();
                os = client.getOutputStream();

                byte[] buff = new byte[512];
                while (is.read(buff) > 0) {
                    String str = new String(buff, "UTF-8");
                    str = str.substring(0, str.lastIndexOf(" "));

                    // if (str.equals("... !!!")) break;

                    System.out.println("Data received: " + str);
                    String[] words = str.split(" "); //Разбиваем строку на два слова
                    System.out.println("First word: " + words[0] + "\nSecond word: " + words[1]);
                    String resT = "The words ARE the same", resF = "The words AREN'T the same";
                    //Индивидуальное задание
                    if (words[0].equalsIgnoreCase(words[1])) {
                        System.out.println(resT);
                        byte[] bytes = resT.getBytes(StandardCharsets.UTF_8);
                        os.write(bytes);
                    } else {
                        System.out.println(resF);
                        byte[] bytes = resF.getBytes(StandardCharsets.UTF_8);
                        os.write(bytes);
                    }
                }

                is.close();
                os.close();
                client.close();
                System.out.println("Client " + countClients + " disconnected");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e);
        } finally {
            sock.close();
        }
    }
}
