import java.util.*;
class Student{
    int StudentID;
    String Name;
    int marks1;
    int marks2;
    double average=0;
    public Student(int StudentID,String Name,int marks1,int marks2){
        this.StudentID=StudentID;
        this.Name=Name;
        this.marks1=marks1;
        this.marks2=marks2;
    }
    public void Average(){
             average=(double)(marks1+marks2)/2;
    }
    public void display(){
        System.out.println("Student ID:"+StudentID+ "    Student Name:"+Name+ "     Marsk1:"+marks1+ "    Marks2:"+marks2+ "     average:"+average+"\n");
    }
}
public class studentDemo {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no of students");
        int n=sc.nextInt();
        Student students[]=new Student[n];
        for(int i=0;i<n;i++){
            System.out.println("enter the student ID:");
            int ID=sc.nextInt();
            System.out.println("enter the student Name:");
            sc.nextLine();
            String name=sc.nextLine();
            System.out.println("enter marks1:");
            int marks1=sc.nextInt();
            System.out.println("enter marks2:");
            int marks2=sc.nextInt();
            students[i]=new Student(ID,name,marks1,marks2);
            students[i].Average();
        }
        Arrays.sort(students,Comparator.comparing (s->s.average));
        for(Student x:students){
            x.display();
        } sc.close();
    }
}
