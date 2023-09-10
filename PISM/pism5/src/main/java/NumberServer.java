import NumberModule.NumberServicePOA;
import org.omg.CORBA.ORB;
import org.omg.CosNaming.NameComponent;
import org.omg.CosNaming.NamingContextExt;
import org.omg.CosNaming.NamingContextExtHelper;
import org.omg.PortableServer.POA;
import org.omg.PortableServer.POAHelper;
import java.util.Scanner;
import java.util.TreeSet;

public class NumberServer extends NumberServicePOA {
    private TreeSet<Double> numbers;

    public NumberServer() {
        numbers = new TreeSet<Double>();
    }

    public void addNumber(double num) {
        if (num >= 100.0 && num <= 200.0) {
            numbers.add(num);
        } else {
            System.err.println("Input number must be between 100 and 200.");
        }
    }

    public String getNumbers() {
        StringBuilder sb = new StringBuilder();
        for (Double num : numbers) {
            sb.append(Integer.toString(num.intValue()));
            sb.append(",");
        }
        return sb.toString();
    }

    public static void main(String args[]) {
        try {
            ORB orb = ORB.init(args, null);
            POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();
            NumberServer server = new NumberServer();
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(server);
            NumberModule.NumberService href = NumberModule.NumberServiceHelper.narrow(ref);
            NamingContextExt ncRef = NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));
            NameComponent path[] = ncRef.to_name("NumberService");
            ncRef.rebind(path, href);
            System.out.println("NumberServer ready and waiting...");

            // Read numbers from console and add to the TreeSet
            Scanner scanner = new Scanner(System.in);
            while (true) {
                System.out.println("Enter a number to add (q to quit): ");
                String input = scanner.nextLine();
                if (input.equalsIgnoreCase("q")) {
                    break;
                }
                try {
                    double num = Double.parseDouble(input);
                    server.addNumber(num);
                } catch (NumberFormatException e) {
                    System.err.println("Invalid input. Please enter a valid number.");
                }
            }

            orb.run();
        } catch (Exception e) {
            System.err.println("ERROR: " + e);
            e.printStackTrace(System.out);
        }
    }
}
