import java.awt.Color;
import java.net.*;
import java.sql.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.table.*;

public class Client extends JFrame{
    Socket sock;
    InputStream is;
    OutputStream os;
    String message;
    int a=0;
    JTable table1;JScrollPane sp;
    static String name, type, firma,price,date;
    Statement sq;
    DefaultTableModel DTM;
    String vibor_naim;
    Connection db;
    String colheads[]={"Наименование", "Тип", "Фирма","Цена","Дата"};
    static Object dataConditer[][];
    byte clientMessage[]=new byte[5000];
    byte bytemessage[] = new byte[5000];
    byte bytemessage2[] = new byte[100];
    JTextField tf1,tf2,tf3,tf4,tf5;

    public Client(String Title){
        super(Title);
        setLayout(null);
        DTM=new DefaultTableModel(dataConditer,colheads);
        table1=new JTable(DTM);
        RowSorter<TableModel> sorter=new TableRowSorter<TableModel>(DTM);
        table1.setRowSorter(sorter);
        table1.setBackground(Color.getHSBColor(159, 216, 234));
        JScrollPane sp=new JScrollPane(table1,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        sp.setBounds(50,5,350,250);
        add(sp);
        JButton btn1=new JButton("Добавить");
        JButton btn2=new JButton("Отключить");
        btn1.setBounds(84,320,125,30);
        add(btn1);
        btn1.addActionListener(new ActionListenerClass1());
        btn2.setBounds(239,320,125,30);
        btn1.setBackground(Color.getHSBColor(72,150,180));
        btn2.setBackground(Color.getHSBColor(72,150,180));
        add(btn2);
        btn2.addActionListener(new ActionListenerClass2());
        tf1=new JTextField("0");
        tf1.setBounds(50,280,68,25);
        add(tf1);
        tf2=new JTextField("0");
        tf2.setBounds(120,280,68,25);
        add(tf2);
        tf3=new JTextField("0");
        tf3.setBounds(190,280,68,25 );
        add(tf3);
        tf4=new JTextField("0");
        tf4.setBounds(260,280,68,25 );
        add(tf4);
        tf5=new JTextField("0");
        tf5.setBounds(330,280,68,25 );
        add(tf5);
        this.setSize(500,450);
        this.setVisible(true);
        addWindowListener(new WindowClose());
        try{
            sock=new Socket(InetAddress.getByName("localhost"),1024);
            is=sock.getInputStream();
            os=sock.getOutputStream();
            is.read(clientMessage);
            String tempString=new String(clientMessage,0,clientMessage.length);
            for (int i=0; i<tempString.length(); i++)
            {
                if (tempString.charAt(i) == '/')
                    a++;
            }
            String arrStr[] = tempString.split("/");
            for (int r=0; r<=a;r=r+5)
            {
                Object addingData[]= {arrStr[r],arrStr[r+1],arrStr[r+2],arrStr[r+3],arrStr[r+4]};
                DTM.addRow(addingData);
            }
        }
        catch(Exception e){}
    }
    class ActionListenerClass1 implements ActionListener{
        public void actionPerformed(ActionEvent ae)
        {
            try{
                name=tf1.getText();
                type=tf2.getText();
                firma=tf3.getText();
                price=tf4.getText();
                date=tf5.getText();
                Object addingData[]={name,type,firma,price,date};
                DTM.addRow(addingData);
                message = (name+ "/" + type +"/" +firma+"/"+ price + "/" +date+ "/");
                bytemessage=message.getBytes();
                os.write(bytemessage);
            }
            catch(Exception e){}
        }
    }

    class ActionListenerClass2 implements ActionListener{
        public void actionPerformed(ActionEvent ae)
        {
            try{
                String h ="End";
                bytemessage2=h.getBytes();
                os.write(bytemessage2);
            }
            catch(Exception e){}
        }
    }

    public static void main(String args[]){
        Client classObj=new Client("Client");
    }
    class WindowClose extends WindowAdapter {
        public void windowClosing(WindowEvent we) {
            try{
                String h ="End";
                bytemessage2=h.getBytes();
                os.write(bytemessage2);
            }
            catch(Exception e){}
            System.exit(0);
        }
    }
}

