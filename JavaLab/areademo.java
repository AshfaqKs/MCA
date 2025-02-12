
class Area{
    public void rarea(int l,int b)
    {
        System.out.println("Area : "+l*b);
    }
    public void rarea(double l,double b)
    {
        System.out.println("Area : "+l*b);
    }

    public void sarea(int a)
    {
        System.out.println("Area : "+ a*a);
    }
    public void sarea(double a)
    {
        System.out.println("Area : "+ a*a);
    }

    public void carea(double r)
    {
        System.out.println("Area : "+ Math.PI*r*r);
    }

    public void tarea(double b,double h)
    {
        System.out.println("Area : "+ 0.5*b*h);
    }
}
public class areademo 
{
    public static void main(String [] args)
    {
        Area r = new Area();
        Area sq = new Area();
        Area c = new Area();
        Area t = new Area();
        r.rarea(2,5);
        sq.sarea(5);
        c.carea(3);
        t.tarea(3,5);
    }
}
