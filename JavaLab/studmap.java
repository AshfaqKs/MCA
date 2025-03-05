
// System to Store Student Information Using Hashmap

import java.util.HashMap;
import java.util.Scanner;


public class studmap {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap<Integer, String> map = new HashMap<>();
        System.out.println("____Menu____\n");
        System.out.println("1.Add Student \n2.Display Student \n3.Exit");
        while(true){
            System.out.println("\nEnter your choice:");
            int ch = sc.nextInt();
            switch(ch){
                case 1:
                  System.out.println("Enter Student ID:");
                  int id = sc.nextInt();
                  sc.nextLine();
                  System.out.println("Enter Student Name:");
                  String name = sc.nextLine();
                  add(id,name,map);
                  break;
                case 2:
                  System.out.println("Enter Student ID:");
                  int id1 = sc.nextInt();
                  sc.nextLine();
                  disp(id1, map);
                  break;
                case 3:
                  System.out.println("....Exiting Program....");
                  System.exit(0);
                  break;
                default:
                  System.out.println("Invalid Choice !");
            }
        }
    }
    private static void add(int i,String n,HashMap <Integer, String> map){
        map.put(i,n);
    }

    private static void disp(int i,HashMap <Integer, String> map){
        if(map.containsKey(i)){
            System.out.println("\nStudent ID : "+i+"\nStudent Name : "+map.get(i));
        }
        else{
            System.out.println("No Student Found with ID "+i);
        }        
    }
}
