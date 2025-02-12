import java.util.Scanner;

interface Ar{
    public void Area();
    public void Perimeter();
}

class circle implements Ar{
    float r;

    public circle(float ra){
        r=ra;
    }
    @Override
    public void Area() {
        System.out.println("Circle Area : "+Math.PI*r*r);
    }

    public void Perimeter() {
        System.out.println("Circle Perimeter : "+2*Math.PI*r);
    }
}

class rect implements Ar{
    int l,b;

    public rect(int le,int br){
        l=le;
        b=br;
    }
    @Override
    public void Area() {
        System.out.println("Rectangle Area : "+l*b);
    }

    public void Perimeter() {
        System.out.println("Rectangle Perimeter : "+2*(l+b));
    }
}

public class interfacedemo {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("______MENU_______"+"\n\n"+"1.Circle Area \n"+"2.Circle Perimeter\n"+"3.Rectangle Area\n"+"4.Rectangle Perimeter"+"\n5.Exit\n");
        while (true) {
            System.out.println("\nEnter Your Choice : ");
            int c = sc.nextInt();
            sc.nextLine();
            switch (c) {
                case 1:
                System.out.println("\nEnter Radius : ");
                float r1 = sc.nextFloat();
                circle c1 = new circle(r1);
                c1.Area();
                break;
                case 2:
                System.out.println("\nEnter Radius : ");
                float r2 = sc.nextFloat();
                circle c2 = new circle(r2);
                c2.Perimeter();
                break;
                case 3:
                System.out.println("\nEnter Length and Breadth : ");
                int l1 = sc.nextInt();
                int b1 = sc.nextInt();
                rect re1 = new rect(l1, b1);
                re1.Area();
                break;
                case 4:
                System.out.println("\nEnter Length and Breadth : ");
                int l2 = sc.nextInt();
                int b2 = sc.nextInt();
                rect re2 = new rect(l2, b2);
                re2.Perimeter();
                break;
                case 5:
                System.out.println("\n\n.......Exiting........\n\n");
                System.exit(0);
                break;
                default:
                System.out.println("\nInvalid Choice");
            }
        }
    }
}