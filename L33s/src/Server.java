import java.io.*;
import java.net.*;

public  class Server {

    public static void main(String[] args) {
        DatagramSocket serverSocket = null ; // ServerSocketдля приема входящих сетевых соединений, DatagramSocket- для отправки и получения дейтаграмм по некоторому протоколу
        byte[] receivedData = new byte[100]; //байтовый массив полученных данных
        byte[] sentData = new byte[100];        ////байтовый массив отправленных данных

        try {
            serverSocket = new DatagramSocket(1028);        //cоздаем сокет,работающий на порту 1028
            while(true) {
                DatagramPacket receivedPacket = new DatagramPacket(receivedData, receivedData.length); //Этот класс представляет пакет дейтаграммы.
                serverSocket.receive(receivedPacket);   //метод приема данных
                InetAddress IPAddress = receivedPacket.getAddress();    //получение адресса
                int port = receivedPacket.getPort();    //получение порта
                String receivedInfo = new String(receivedPacket.getData()); //получение обзей информации
                System.out.println(receivedInfo);   //вывод
                String[] info = receivedInfo.split(" "); //разделение методом сплит по пустой строке
                int a, b, c; //переменные
                a = Integer.parseInt(info[0]); //parseInt() принимает строку в качестве аргумента и возвращает целое число
                b = Integer.parseInt(info[1]);
                c = Integer.parseInt(info[2]);
                double sum1 = 0, sum2 = 0;

                for (double i = a; i < b; i += 1){
                    sum1 += ((3*i)/(2*i+1));
                }

                for (double i = b; i < c; i +=1){
                    sum2 += (i*i + 4*i + 1);
                }

                double sum = sum1 + sum2;
                String sendInfo = String.valueOf(sum); //возвращает соответствующий числовой объект, содержащий значение переданного аргумента
                sentData = sendInfo.getBytes(); //получение байтовых данных
                DatagramPacket sendPacket = new DatagramPacket(sentData, sentData.length, IPAddress, port); //конфигурация запроса
                serverSocket.send(sendPacket); // //отправление по заданным параметрам
            }
        } catch (Exception e) { //кэтч отлов ошибки
            System.out.println("Error " + e.toString());
        } finally {     //выполнение кода в независимости от кода
            serverSocket.close(); //закрытие сокета
        }


    }
}