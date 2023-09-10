package repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public enum ConnectionManager {
    INSTANCE;

    private Connection connection;

    private final static String DATABASE_SERVICE = "localhost";
    private final static String DATABASE = "car_rental";

//  private final static String USER = "student";
//  private final static String PASSWORD = "student";
    private final static String USER = "root";
    //private final static String PASSWORD = "root";

     private final static String PASSWORD = "new_password";

    ConnectionManager()
    {
        try {
            DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
            String url = "jdbc:mysql://"+ DATABASE_SERVICE + ":3306/" + DATABASE + "?serverTimezone=Europe/Minsk";

            connection = DriverManager.getConnection(url, USER, PASSWORD);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    //соединение с базой данных для всех классов
    public Connection getConnection()
    {
        return connection;
    }
}
