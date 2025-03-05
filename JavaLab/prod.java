import java.util.*;

class pr{
    String n;
    int p;
    public pr(String na,int pr){
        n=na;
        p=pr;
    }
    @Override
    public String toString() {
        return "Product{Name='" + n + "', Price=" + p + "}";
    }
}

public class prod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList <pr> prods = new ArrayList<>();
        System.out.println("____MENU____\n\n1. Add \n2.Sort \n3. Display \n4.Exit");
        while (true) {
            System.out.println("\nEnter your choice : ");
            int c = sc.nextInt();
            sc.nextLine();
            switch (c) {
                case 1:
                  System.out.println("\nEnter Product Name and Price : ");
                  String a = sc.nextLine();
                  int p = sc.nextInt();
                  sc.nextLine();
                  prods.add(new pr(a,p));
                  break;
                case 2:
                  // Collections.sort(prods,Comparator.comparing(pr product)->product.n);
                  break;
                case 3:
                  System.out.println(prods);
                  break;
                case 4:
                  System.out.println("......Exiting......");
                  System.exit(0);
                  break;
                default:
                  System.out.println("Invalid choice");
            }
        }
    }
}
