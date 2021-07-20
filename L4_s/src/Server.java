import java.awt.Color;
import java.net.*;
import java.sql.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.table.*;

public class Server extends JFrame{

    ServerSocket sock;
    InputStream is;
    OutputStream os;
    String st;
    String stroka;
    JTable table1;JScrollPane sp;
    static String name, newname,type ,newtype,firma , newfirma ,price,newprice,date,newdate ;

    Statement sq;
    DefaultTableModel DTM;
    String vibor_naim;
    Connection db;
    String colheads[]={"Наименование", "Тип", "Фирма","Цена","Дата"};
    static Object dataConditer[][];
    byte bytemessage[] = new byte[10000];


    public Server(String Title){
        super(Title);
        setLayout(null);
        DTM=new DefaultTableModel(dataConditer,colheads);
        table1=new JTable(DTM);
        table1.setBackground(Color.getHSBColor(159, 216, 234));
        JScrollPane sp=new JScrollPane(table1,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        sp.setBounds(50,5,350,250);
        add(sp);
        this.setSize(500,450);
        this.setVisible(true);
        addWindowListener(new WindowClose());
        try{
            Class.forName("com.mysql.jdbc.Driver");//получение класса драйвера
            db=DriverManager.getConnection("jdbc:mysql://localhost:3306/dogovor", "root", "");
            sq=db.createStatement();
            StringBuffer x = new StringBuffer();
            String  sq_str="SELECT * FROM dogovor";
            ResultSet rs= sq.executeQuery(sq_str);
            while(rs.next()){

                name=rs.getString("Name");
                type=rs.getString("Type");
                firma=rs.getString("Firma");
                price=rs.getString("Price");
                date=rs.getString("Date");


                Object addingData[]= {name,type,firma,price,date};
                DTM.addRow(addingData);
                st = (name+ "/" + type +"/" +firma+"/"+ price +"/" +date+"/");


                x.append(st);
            }
            stroka=x.toString();
            sock=new ServerSocket(1024);
            while(true)
            {
                Socket client=sock.accept();
                is=client.getInputStream();
                os=client.getOutputStream();
                bytemessage=stroka.getBytes();
                os.write(bytemessage);
                boolean flag = true;
                while(flag==true)
                {
                    byte readmessage[] = new byte[10000];
                    is.read(readmessage);
                    String tempString=new String(readmessage,0,readmessage.length);
                    if(tempString.trim().compareTo("End")==0) {
                        flag = false;
                    }
                    else
                    {
                        stroka=  stroka+tempString;
                        String arrStr[] = tempString.split("/");
                        newname=arrStr[0];
                        newtype=arrStr[1];
                        newfirma=arrStr[2];
                        newprice=arrStr[3];
                        newdate=arrStr[4];
                        Object addingData[]={newname,newtype,newfirma,newprice,newdate};
                        DTM.addRow(addingData);
                        String sq_str_insert="INSERT INTO dogovor  VALUES ('"+newname+"','"+newtype+"','"+
                                newfirma+"','"+newprice+"','"+newdate+"')";
                        int rs_update2= sq.executeUpdate(sq_str_insert);
                    }}
                is.close();
                os.close();
                client.close();
            }
        }
        catch(Exception e){}
    }

    public static void main(String args[]){
        Server classObj=new Server("Server");
    }


    class WindowClose extends WindowAdapter {
        public void windowClosing(WindowEvent we) {
            System.exit(0);
        }
    }
}
