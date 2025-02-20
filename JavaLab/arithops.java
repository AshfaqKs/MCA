import java.util.Scanner;
import arithmetic.*;
public class arithops {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2 values : ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        add ad = new add(a, b);
        sub s = new sub(a,b);
        mul m = new mul(a,b);
        div d = new div(a,b);
        System.out.println("Addition : "+ad.calculate()+"\nSubtraction : "+s.calculate()+"\nMultiplication : "+m.calculate()+"\nDivision : "+d.calculate());
        sc.close();
    }
}
