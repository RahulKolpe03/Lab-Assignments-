public class Date {

    private int day;
    private int month;
    private int year;

    // Set Date
    public void setDate(int dd, int mm, int yyyy) {

        year = yyyy;

        // Month Validation
        if (mm < 1 || mm > 12) {
            month = 1;
        } else {
            month = mm;
        }

        // 31 Days Month
        if (month == 1 || month == 3 || month == 5 ||
            month == 7 || month == 8 || month == 10 ||
            month == 12) {

            if (dd < 1 || dd > 31) {
                day = 1;
            } else {
                day = dd;
            }
        }

        // 30 Days Month
        else if (month == 4 || month == 6 ||
                 month == 9 || month == 11) {

            if (dd < 1 || dd > 30) {
                day = 1;
            } else {
                day = dd;
            }
        }

        // February
        else if (month == 2) {

            // Leap Year
            if (year % 4 == 0) {

                if (dd < 1 || dd > 29) {
                    day = 1;
                } else {
                    day = dd;
                }

            }

            // Non-Leap Year
            else {

                if (dd < 1 || dd > 28) {
                    day = 1;
                } else {
                    day = dd;
                }
            }
        }
    }

    // Add Days
    public void setDays(int ad) {

        int totalDays = ad + day;

        // 31 Days Month
        if (month == 1 || month == 3 || month == 5 ||
            month == 7 || month == 8 || month == 10 ||
            month == 12) {

            while (totalDays > 31) {

                totalDays = totalDays - 31;
                month++;

                if (month > 12) {
                    month = 1;
                    year++;
                }
            }

            day = totalDays;
        }

        // 30 Days Month
        else if (month == 4 || month == 6 ||
                 month == 9 || month == 11) {

            while (totalDays > 30) {

                totalDays = totalDays - 30;
                month++;

                if (month > 12) {
                    month = 1;
                    year++;
                }
            }

            day = totalDays;
        }

        // February
        else if (month == 2) {

            // Leap Year
            if (year % 4 == 0) {

                while (totalDays > 29) {

                    totalDays = totalDays - 29;
                    month++;

                    if (month > 12) {
                        month = 1;
                        year++;
                    }
                }

                day = totalDays;
            }

            // Non-Leap Year
            else {

                while (totalDays > 28) {

                    totalDays = totalDays - 28;
                    month++;

                    if (month > 12) {
                        month = 1;
                        year++;
                    }
                }

                day = totalDays;
            }
        }
    }

    // Add Months
    public void setMonth(int admm) {

        int totalMonths = month + admm;

        if (totalMonths > 12) {

            month = totalMonths - 12;
            year++;

        } else {

            month = totalMonths;
        }
    }

    // Add Years
    public void setYear(int adyyyy) {

        year = year + adyyyy;
    }

    // Get Day
    public int getDay() {
        return day;
    }

    // Get Month
    public int getMonth() {
        return month;
    }

    // Get Year
    public int getYear() {
        return year;
    }
}