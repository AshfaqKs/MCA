
class Cuboid{
    public void vol(double l,double b,double h)
    {
        System.out.println("Cuboid Volume : "+l*b);
    }
}
class Cube{
    public void vol(double a)
    {
        System.out.println("Cube Volume : "+ a*a*a);
    }
}
class Sphere{
    public void vol(double r)
    {
        System.out.println("Sphere Volume : "+ (4/3)*Math.PI*r*r*r);
    }
}
class Cylinder{
    public void vol(double r,double h)
    {
        System.out.println("Cylinder Volume : "+ Math.PI*r*r*h);
    }
}
class Cone{
    public void vol(double r,double h)
    {
        System.out.println("Cone Volume : "+ (1/3)*Math.PI*r*r);
    }
}
public class voldemo 
{
    public static void main(String [] args)
    {
        Cuboid r = new Cuboid();
        Cube sq = new Cube();
        Sphere sp = new Sphere();
        Cylinder c = new Cylinder();
        Cone t = new Cone();
        r.vol(2,3,4);
        sq.vol(5);
        sp.vol(3);
        c.vol(3,4);
        t.vol(3,5);
    }
}
