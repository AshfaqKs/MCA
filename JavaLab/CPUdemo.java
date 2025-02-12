
class CPU{
    int Price;
    public CPU(int p)
    {
        this.Price=p;
    }
    public void disp()
    {
        System.out.println("Price : "+this.Price);
    }

    class Processor
    {
        int noc;
        String manu;
        public Processor(int n, String m)
        {
            this.noc=n;
            this.manu=m;
        }
        public void disp()
        {
            System.out.println("No. of cores : "+noc+"\nManufacturer : "+manu);
        }
    }
    static class RAM
    {
        String ma,me;
        public RAM(String me, String ma)
        {
            this.me=me;
            this.ma=ma;
        }
        public void disp()
        {
            System.out.println("RAM Memory : "+this.me+"\nManufacturer : "+this.ma);
        }
    }
}

public class CPUdemo
{
    public static void main(String[] args)
    {
        CPU c = new CPU(2000);
        CPU.Processor p = c.new Processor(5,"INTEL");
        CPU.RAM r= new CPU.RAM("4GB RAM","ADATA");
        c.disp();
        p.disp();
        r.disp();
    }
}