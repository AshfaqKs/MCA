
import java.util.*;
class NegException extends Exception(message){
    public void NegException(String message){
        super.message();}
    }
public class calculator extends NegException{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int count=0;
        int sum=0;
        int n,i;
        System.out.println("enter the limit:");
        n=sc.nextInt();
        try{
            for(i=0;i<=n;i++){
                System.out.println("enter number"+i+1+":");
                int num=sc.nextInt();
                if(num<0){
                    throw NegException("entered number is negetive");
                }
                sum+=i;
                count++;
                double average=(double) sum/count;
            }
        }
        catch{
             NegException(Exception e){
                System.out.println(e.getMessage());
            }
        }
        finally{
            sc.close();
        }
    }
}