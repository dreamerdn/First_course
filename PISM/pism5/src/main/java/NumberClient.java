import NumberModule.*;
import org.omg.CosNaming.*;
import org.omg.CORBA.*;

public class NumberClient {
    public static void main(String args[]) {
        try {
            ORB orb = ORB.init(args, null);
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
            NumberService numberService = NumberServiceHelper.narrow(ncRef.resolve_str("NumberService"));
            String numbers = numberService.getNumbers();
            String[] nums = numbers.split(",");
            for (String num : nums) {
                System.out.println(num);
            }
        } catch (Exception e) {
            System.err.println("ERROR: " + e);
            e.printStackTrace(System.out);
        }
    }
}
