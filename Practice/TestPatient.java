public class TestPatient {
    public static void main (String [] args) {
        Patient ob1 =  new Patient();
        Patient ob2 = new Patient(2, 5, 59);
        
        System.out.println("Patient 1 details");
        System.out.printf("Id : %d\n age : %d\n blood Data : %d\n", ob1.getId(), ob1.getAge(), ob1.getBloodData());
        System.out.printf("Id : %d\n age : %d\n blood Data : %d\n", ob2.getId(), ob2.getAge(), ob2.getBloodData());
   }
}
