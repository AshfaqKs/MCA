class multi extends Thread{
    public void run(){
        try {
            for (int i=1;i<=10;i++){
                System.out.println("\t\t\t\t"+i+" * 5 = "+(i*5));
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class fact extends Thread{
    public void run(){
        int n=36;
        try {
            for (int i=1;i<=n;i++){
                if( n%i == 0  ){
                    System.out.println("Factor("+n+") : "+i);
                }
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class threada {
    public static void main(String[] args) {
        multi m = new multi();
        fact f = new fact();
        m.start();
        f.start();
        try {
            m.join();
            f.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Both Threads Finished....");
    }
}