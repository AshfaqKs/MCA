class prime implements Runnable{
    public void run(){
        int n = 15,j;
        try {
            for(int i=2;i<n;i++){
                for(j=2;j<=i/2;j++){
                    if(i%j == 0){
                        break;
                    }
                    else{
                        System.out.println("Prime No. : "+i);
                        Thread.sleep(500);
                        break;
                    }
                }
                if(j>i/2){
                    System.out.println("Prime No. : "+i);
                    Thread.sleep(500);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class even implements Runnable{
    public void run(){
        int n = 15;
        try {
            for(int i=1;i<n;i++){
                    if(i%2 == 0){
                        System.out.println("\tEven No. : "+i);
                        Thread.sleep(500);
                    }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class fibo implements Runnable{
    public void run(){
        int n = 7,pn=0,cn=0,nn=1;
        try {
            for(int i=0;i<n;i++){
                System.out.println("\t\tFibonacci No. : "+cn);
                pn=cn;
                cn=nn;
                nn=cn+pn;
                Thread.sleep(500);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class threadb {
    public static void main(String[] args) {
        prime p = new prime();
        even e = new even();
        fibo f = new fibo();

        Thread pt = new Thread(p);
        Thread et = new Thread(e);
        Thread ft = new Thread(f);

        pt.start();
        et.start();
        ft.start();

        try {
            pt.join();
            et.join();
            ft.join();
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }

        System.out.println("All Threads Finished....");
    }
}
