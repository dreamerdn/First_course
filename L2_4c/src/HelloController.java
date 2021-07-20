import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.charset.StandardCharsets;

public class HelloController {
    @FXML
    private Button connect;
    @FXML
    private Button check;
    @FXML
    private Button disconnect;
    @FXML
    private TextField ip;
    @FXML
    private TextField port;
    @FXML
    private TextField word1;
    @FXML
    private TextField word2;
    @FXML
    private TextArea result;
    @FXML
    private Label info;

    Socket sock=null;
    InputStream is=null;
    OutputStream os=null;

    @FXML
    public void connection (){
        if(!ip.getText().equals("") && !port.getText().equals("")){
            try{
                sock = new Socket(InetAddress.getByName(ip.getText()), Integer.parseInt(port.getText()));
            } catch (NumberFormatException e) {
            } catch (UnknownHostException e) {
            } catch (IOException e) {
            }
            info.setText("You are connected!");
            connect.setDisable(true);
            disconnect.setVisible(true);
        }
        else {
            info.setText("Enter data!");
        }
    }

    public void disconnection (){
//        String str="... !!! ";
        try{
//                os.write(str.getBytes(StandardCharsets.UTF_8));
            is.close();
            os.close();
            sock.close();
        } catch (IOException e) {}
        connect.setDisable(false);
        disconnect.setVisible(false);
        info.setText("You are disconnected!");
    }

    @FXML
    public void individualTask(){
        if (sock == null){
            info.setText("Get connected first!");
            return;
        }
        try{
            is=sock.getInputStream();
            os=sock.getOutputStream();
            String str="";
            if (!word1.getText().equals("") && !word2.getText().equals("")) {
                str += word1.getText() + " ";
                word1.setText("");
                str += word2.getText() + " ";
                word2.setText("");
                os.write(str.getBytes(StandardCharsets.UTF_8));
                info.setText("Data sent to the Server!");
                byte[] buff = new byte[512];
                is.read(buff);
                str = new String(buff, "UTF-8");
                result.setText(str);
                check.setMnemonicParsing(false);
            }
            else {
                info.setText("Enter two words!");
            }
        } catch (IOException e) {
        }
    }

//    @FXML
//    public void WindowClosing(WindowEvent we) {
//        if (sock != null && !sock.isClosed()){
//            try{
//                sock.close();
//            } catch (IOException e) {}
//        }
//        System.out.println("You are disconnected!");
//        we.consume();
//    }
}