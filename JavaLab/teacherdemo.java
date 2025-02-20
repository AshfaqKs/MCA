import java.util.Scanner;

class Person{
    String name,gender,address;
    int age;
    
    public Person(String n,String g,String a,int age){
        name=n;
        gender=g;
        address=a;
        this.age=age;
    }
    
    public void disp(){
        System.out.println("\nName : "+name+"\nAge : "+age+"\nGender : "+gender+"\nAddress : "+address);
    }
}

class Employee extends Person{
    String Company_name,Qualification;
    int Empid,Salary;
    
    public Employee(String n,String g,String a,int age,int eid,String cn,String q,int sal){
        super(n,g,a,age);
        Empid=eid;
        Company_name=cn;
        Qualification=q;
        Salary=sal;
    }
    
    public void disp(){
        super.disp();
        System.out.println("Employee Id : "+Empid+"\nCompany Name : "+Company_name+"\nQualification : "+Qualification+"\nSalary : "+Salary);
    }
}

class Teacher extends Employee{
    String Subject,Dept;
    int Teacherid;
    
    public Teacher(String n,String g,String a,int age,int eid,String cn,String q,int sal,int tid,String sub,String dep){
        super(n,g,a,age,eid,cn,q,sal);
        Teacherid=tid;
        Subject=sub;
        Dept=dep;
    }
    
    public void disp(){
        super.disp();
        System.out.println("Teacher Id : "+Teacherid+"\nSubject : "+Subject+"\nDepartment : \n"+Dept);
    }
}

public class teacherdemo {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter N : ");
        int N = sc.nextInt();
        sc.nextLine();
        Person[] p = new Person[10];
        for(int i=0;i<N;i++)
        {
            System.out.println("\nEnter Name : ");
            String n = sc.nextLine();
            System.out.println("Enter Gender : ");
            String g = sc.nextLine();
            System.out.println("Enter Address : ");
            String a = sc.nextLine();
            System.out.println("Enter Age : ");
            int age = sc.nextInt();
            System.out.println("Enter Employment Id : ");
            int eid = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter Company Name : ");
            String cn = sc.nextLine();
            System.out.println("Enter Qualification : ");
            String q = sc.nextLine();
            System.out.println("Enter Salary : ");
            int sal = sc.nextInt();
            System.out.println("Enter Teacher Id : ");
            int tid = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter Subject : ");
            String sub = sc.nextLine();
            System.out.println("Enter Department : ");
            String dep = sc.nextLine();
            p[i] = new Teacher(n, g, a, age, eid, cn, q, sal, tid, sub, dep);
        }
        for(int i=0;i<N;i++)
        {
            System.out.println("\n_____NO."+i+"_____");
            p[i].disp();
        }
        sc.close();
    }
}
