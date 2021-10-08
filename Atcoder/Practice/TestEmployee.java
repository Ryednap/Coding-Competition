public class TestEmployee {
    public static void main (String [] args) {
        Employee emp1 = new Employee("Ujjwal", "82-M-183", "15-08-2001", "23-10-2013");
        Employee emp2 = new Employee("Sayan", "4M-M-183","15-08-2001", "23-10-2013");
        Employee emp3 = new Employee("Samarh", "82-M-183", "4-02-2005", "1-01-2001");

        System.out.println ("Total employee " + Employee._count);
       /*  System.out.println (emp1.getName());
        System.out.println (emp1.getEcode());
        System.out.println (emp1.getDob()); */
    }
}
