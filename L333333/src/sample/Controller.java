package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.net.*;
import java.util.ResourceBundle;

public class Controller {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button sendInfoButton;

    @FXML
    private TextArea resultField;

    @FXML
    private TextField f1;

    @FXML
    private TextField f2;

    @FXML
    private TextField f3;

    public Controller() throws SocketException {
    }

    @FXML
    void initialize() {
        sendInfoButton.setOnAction(new EventHandler<ActionEvent>() { // выполнить действие по нажатию кнопки
            @Override
            public void handle(ActionEvent event) {

            DatagramSocket clientSocket = null;
            try {
                clientSocket = new DatagramSocket();
            } catch (SocketException e) {
                e.printStackTrace();
            }

                try {
                    resultField.clear();
                    InetAddress IPAddress = InetAddress.getByName("localhost");
                    byte[] receivedData = new byte[100];
                    byte[] sentData = new byte[100];
                    String numbers = "";
                    numbers += f1.getText() + " ";
                    numbers += f2.getText() + " ";
                    numbers += f3.getText() + " ";
                    f1.clear();
                    f2.clear();
                    f3.clear();
                    sentData = numbers.getBytes();
                    DatagramPacket sendPacket = new DatagramPacket(sentData, sentData.length, IPAddress, 1028);
                    clientSocket.send(sendPacket);
                    DatagramPacket receivedPacket = new DatagramPacket(receivedData, receivedData.length);
                    clientSocket.receive(receivedPacket);
                    String receivedInfo = new String(receivedPacket.getData());
                    resultField.appendText(receivedInfo);

                } catch (Exception ex) {
                    ex.printStackTrace();
                } finally {
                    clientSocket.close();
                }

            }
                                   }
        );
    }
}

