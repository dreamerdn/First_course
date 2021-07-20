import java.awt.*;
import java.net.*;
import java.sql.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.table.*;
import javax.swing.event.*;


public class DBClass extends JFrame{
    JTable table1;JScrollPane sp;
    static String nazv, cena, naim;
    static int massa;
    Statement sq;
    ListSelectionModel lsm;
    DefaultTableModel dtm;
    String vibor_naim;
    Connection db;
    String colheads[]={"Наименование", "Название", "Цена","Масса"};


    static Object dataConditer[][];


    JTextField tf1,tf2,tf3,tf4;
    void showData(){
        try{

            String  sq_str="SELECT * FROM Assortiment";
            ResultSet rs= sq.executeQuery(sq_str);

            while(rs.next()){
                nazv=rs.getString("Nazvanie");
                cena=rs.getString("Cena");
                naim=rs.getString("Naimenovanie");
                massa=rs.getShort("Massa");
                Object addingData[]= {naim,nazv,cena,massa};
                dtm.addRow(addingData);
                System.out.println(naim+nazv+massa+cena);

            }
        }
        catch(Exception e){}
    }

    public DBClass(String Title){
        super(Title);
        setLayout(null);
        dtm	=new DefaultTableModel(dataConditer,colheads);
        table1=new JTable(dtm);
        JScrollPane sp=new JScrollPane(table1,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        sp.setBounds(50,5,350,250);
        add(sp);
        JButton btn1=new JButton("Добавить");

        btn1.setBounds(100,370,100,30);

        add(btn1);
        btn1.addActionListener(new ActionListenerClass1());
        tf1=new JTextField("0");
        tf1.setBounds(55,280,80,30);
        add(tf1);
        tf2=new JTextField("0");
        tf2.setBounds(140,280,80,30);
        add(tf2);
        tf3=new JTextField("0");
        tf3.setBounds(225,280,80,30 );
        add(tf3);
        tf4=new JTextField("0");
        tf4.setBounds(310,280,80,30 );
        add(tf4);
        lsm=table1.getSelectionModel();
        lsm.addListSelectionListener(new SelectionListenerClass());
        this.setSize(500,450);
        this.setVisible(true);
        try{
            Class.forName("com.mysql.jdbc.Driver");//получение класса драйвера
            db=DriverManager.getConnection("jdbc:mysql://localhost:3306/conditer", "root", "");
            sq=db.createStatement();



            String  sq_str="SELECT * FROM Assortiment";
            ResultSet rs= sq.executeQuery(sq_str);



            while(rs.next()){
                nazv=rs.getString("Nazvanie");
                cena=rs.getString("Cena");
                naim=rs.getString("Naimenovanie");
                massa=rs.getShort("Massa");
                Object addingData[]= {naim,nazv,cena,massa};
                dtm.addRow(addingData);


            }


        }
        catch(Exception e){}



    }
    class SelectionListenerClass implements ListSelectionListener{
        public void valueChanged(ListSelectionEvent lse){
            Object obj=table1.getValueAt(table1.getSelectedRow(),table1.getSelectedColumn());
            tf1.setText(table1.getValueAt(table1.getSelectedRow(),0).toString());
            tf2.setText(table1.getValueAt(table1.getSelectedRow(),1).toString());
            tf3.setText(table1.getValueAt(table1.getSelectedRow(),2).toString());
            tf4.setText(table1.getValueAt(table1.getSelectedRow(),3).toString());
            vibor_naim=tf1.getText();

        }
    }
    class ActionListenerClass1 implements ActionListener{//кнопка Добавить
        public void actionPerformed(ActionEvent ae)
        {
            try{
                naim=tf1.getText();
                nazv=tf2.getText();
                cena=tf3.getText();
                massa=Integer.parseInt(tf4.getText());

                String	sq_str_insert="INSERT INTO Assortiment  VALUES ('"+naim+"','"+nazv+"','"+
                        cena+"',"+massa+")";
                int rs_update2= sq.executeUpdate(sq_str_insert);
                Object addingData[]={naim,nazv,massa,cena};
                dtm.addRow(addingData);
            }
            catch(Exception e){}
        }

    }

    public static void main(String args[]){
        // объявление переменных
        DBClass classObj=new DBClass("Frame");

    }
}
