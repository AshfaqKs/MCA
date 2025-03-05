import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class list {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        ArrayList <String> names = new ArrayList<String>();
        System.out.println("____MENU____\n\n1. Add \n2. Remove \n3.Search \n4.Sort \n5. Display \n6.Exit");
        while (true) {
            System.out.println("\nEnter your choice : ");
            int c = sc.nextInt();
            sc.nextLine();
            switch (c) {
                case 1:
                  System.out.println("\nEnter Name : ");
                  String a = sc.nextLine();
                  names.add(a);
                  break;
                case 2:
                  System.out.println("\nEnter Index : ");
                  int in = sc.nextInt();
                  sc.nextLine();
                  names.remove(in);
                  break;
                case 3:
                  System.out.println("\nEnter Name : ");
                  a = sc.nextLine();
                  if(names.contains(a)){
                    System.out.println("Name is in the list");
                  }
                  break;
                case 4:
                  Collections.sort(names);
                  break;
                case 5:
                  System.out.println(names);
                  break;
                case 6:
                  System.out.println("......Exiting......");
                  System.exit(0);
                  break;
                default:
                  System.out.println("Invalid choice");
            }
        }
    }
}
