import java.util.Scanner;

interface showable{
    public void show();
}

class Person implements showable{
    
    String n,g,ph;
    
    public Person(String na,String ge,String p){
        n=na;
        g=ge;
        ph=p;
    }

    public void show(){
        System.out.println("\nName : "+n+"\nGender : "+g+"\nPhone Number : "+ph);
    }
}

class Stud extends Person{
    
    String c;
    int sc;

    public Stud(String na,String ge,String p,String co,int s){
        super(na,ge,p);
        c=co;
        sc=s;
    }

    public void show(){
        super.show();
        System.out.println("Course : "+c+"\nScore : "+sc);
    }
}

class PGstud extends Stud{
    
    String r,gu;

    public PGstud(String na,String ge,String p,String co,int s,String re,String gui){
        super(na,ge,p,co,s);
        r=re;
        gu=gui;
    }
    public void show(){
        super.show();
        System.out.println("Research Area : "+r+"\nGuide : "+gu);
    }
}

public class studdemo {
    public static void main(String[] a){
        Scanner sc = new Scanner(System.in);
        PGstud[] p = new PGstud[10];
        System.out.println("Enter the number of students : ");
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            System.out.println("\n\n____Student "+(i+1)+"____");
            System.out.println("\nEnter Name : ");
            String na = sc.nextLine();
            System.out.println("Enter Gender : ");
            String ge = sc.nextLine();
            System.out.println("Enter Phone Number : ");
            String ph = sc.nextLine();
            System.out.println("Enter Course : ");
            String co = sc.nextLine();
            System.out.println("Enter Score : ");
            int s = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter Research Area : ");
            String re = sc.nextLine();
            System.out.println("Enter Guide : ");
            String gui = sc.nextLine(); 
            p[i] = new PGstud(na, ge, ph, co, s, re, gui);
        }
        System.out.println("\n\n____Student Details Based on Score____");
        for(int i=0;i<n;i++){
            System.out.println("\nRank "+(i+1)+" : ");
            
        }
        sc.close();
    }
}