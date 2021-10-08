import java.util.Arrays;
import java.util.EmptyStackException;

public class Employee {
	String name;
	String eCode;
	String dob, doa;
	static int _count;

	public Employee (String name, String eCode, String dob, String doa) {
		this.name = name;
		this.eCode = eCode;
		this.dob = dob;
		this.doa = doa;
		_count = 0;
		try {
			validate ();
			++_count;
		} catch (EmployeeCodeException | AppointmentException e) {
			System.out.println (e.getMessage());
		}
	}

    // getters
    public String getName () { return this.name; }
    public String getEcode () { return this.eCode; }
    public String getDoa () { return this.doa; }
    public String getDob () { return this.dob; }

    // validators
	private void validate () throws EmployeeCodeException, AppointmentException {
		try {
            validateEcode();
            validateDOA();

	 	} catch (EmptyStackException | AppointmentException e) {
             throw e;
         }

	}
    private boolean isNumber (String s) {
        try {
            Integer.parseInt(s);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

	private void validateEcode () throws EmployeeCodeException {
        String [] split = eCode.split("-");
        EmployeeCodeException error = new EmployeeCodeException("Ecode not proper formatted");
        try {
            if (split[0].length() != 2 && !isNumber(split[0])) 
                throw error;
            if (split[1].length() != 1 && !Character.isLetter(split[0].charAt(0)))
                throw error;
            if (split[2].length() != 3 && !isNumber(split[2]))
                throw error;

        } catch (EmployeeCodeException ee) {
            throw ee;
        }
	}

	private void validateDOA () throws AppointmentException {
        String [] dobSplit = dob.split("-");
        String [] doaSplit = doa.split("-");

        AppointmentException error = new AppointmentException("Appointment date is before date of birth");
        try {
            for ( int i = 2; i >= 0; --i) {
                int a = Integer.parseInt(dobSplit[i]);
                int b = Integer.parseInt(doaSplit[i]);
                if (b < a) throw error;
                else if (b > a) break;
            }
        } catch (AppointmentException ae) {
            throw ae;
        }
	}
}


class EmployeeCodeException extends Exception {
	public EmployeeCodeException (String s) {
		super (s);
	}
}

class AppointmentException extends Exception {
	public AppointmentException (String s) {
		super (s);
	}
}	
	