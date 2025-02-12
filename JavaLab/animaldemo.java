class animal{
    private String species;
    int age;
    float weight;
    protected String color;
    
    public animal(String sp,int age,float w, String clr){
        species=sp;
        this.age=age;
        weight=w;
        color=clr;
    }

    public void disp( ){
        System.out.println("Species : "+species+" Age : "+age+" Weight : "+weight+" Color : "+color);
    }
}

class dog extends animal{
    String name,owner;

    public dog(String sp,int age,float w, String clr,String n,String o){
            super(sp, age, w, clr);
        name=n;
        owner=o; 
    }

    public void disp(){
        super.disp();
        System.out.println("Name : "+name+" Owner : "+owner);
    }
}

class cat extends animal{
    String name,owner;

    public cat(String sp,int age,float w, String clr,String n,String o){
            super(sp, age, w, clr);
        name=n;
        owner=o; 
    }

    public void disp(){
        super.disp();
        System.out.println("Name : "+name+" Owner : "+owner);
    }
}

public class animaldemo {
    public static void main(String args[])
    {
        dog d = new dog("Mammal", 3, (float) 6.3, "Black", "Rocky", "Jack");
        d.disp();
        cat c = new cat("Mammal", 2, (float) 3.5, "Brown", "Kitty", "Richard");
        c.disp();
    }    
}
