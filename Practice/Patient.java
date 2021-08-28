import java.util.*;

public class Patient {
    int id, age;
    int bloodData;

    public Patient () {
        this.id = 0;
        this.age = 0;
        this.bloodData = 0;
    }

    public Patient (int id, int age, int bloodData) {
        this.id = id;
        this.age = age;
        this.bloodData = bloodData;
    }

    // getters
    public Integer getId () { return this.id; }
    public Integer getAge () {return this.age; }
    public Integer getBloodData () { return this.bloodData; }
}
