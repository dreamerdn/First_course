package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class Main extends Application {

    @Override //переопределение
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml")); //получение FXML файла
        primaryStage.setTitle("CLIENT"); //задание заголовка
        primaryStage.setScene(new Scene(root, 700, 600)); //Размеры экрана
        primaryStage.show();// показать окно приложения


    }

    public static void main(String[] args) {
        launch(args);
    }
}
