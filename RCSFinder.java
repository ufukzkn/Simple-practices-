import java.util.Scanner;

public class RCSFinder {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int rcs = 0;
        boolean writtenBefore=false;

        System.out.println("Enter the plain text: ");
        String str = input.nextLine();
        str = str.toLowerCase()+" ";

        System.out.println("The RCSs found are: \n");
        for (int a1 = 0; a1 < str.length()-2; a1++) {
            int n = 1;
            char temp;
            int checker;

            char a2 = str.charAt(a1);

            if (Character.isLetter(a2)) {
                if (a2 == 'a' || a2 == 'e' || a2 == 'ı' || a2 == 'i' || a2 == 'o' || a2 == 'ö' || a2 == 'u' || a2 == 'ü')
                    checker = 0; // sesli icin 0
                else checker = 1; // sessiz icin 1
            }
            else continue;

            while (checker == 0) {
                if (n >= 3) {
                    System.out.println(str.substring(a1, a1 + n));
                    rcs++;
                }
                temp = str.charAt(a1 + n);
                if (Character.isDigit(temp))
                    break;
                if (Character.isLetter(temp) &&
                        !(temp == 'a' || temp == 'e' || temp == 'ı' || temp == 'i' || temp == 'o' || temp == 'ö' || temp == 'u' || temp == 'ü')) {
                    n++;
                    checker = 1;
                    writtenBefore=true;
                } else break;

                while (checker == 1) {
                    if (n >= 3) {
                        System.out.println(str.substring(a1, a1 + n));
                        rcs++;
                    }
                    temp = str.charAt(a1 + n);
                    if (Character.isDigit(temp))
                        break;
                    if (Character.isLetter(temp) &&
                            (temp == 'a' || temp == 'e' || temp == 'ı' || temp == 'i' || temp == 'o' || temp == 'ö' || temp == 'u' || temp == 'ü')) {
                        n++;
                        checker = 0;
                    } else break;
                }
            }

            while (checker == 1) {
                if (n >= 3 && !writtenBefore) {
                    System.out.println(str.substring(a1, a1 + n));
                    rcs++;
                }
                writtenBefore=false;
                temp = str.charAt(a1 + n);
                if (Character.isDigit(temp))
                    break;
                if (Character.isLetter(temp) &&
                        (temp == 'a' || temp == 'e' || temp == 'ı' || temp == 'i' || temp == 'o' || temp == 'ö' || temp == 'u' || temp == 'ü')) {
                    n++;
                    checker = 0;
                } else break;

                while (checker == 0) {
                    if (n >= 3) {
                        System.out.println(str.substring(a1, a1 + n));
                        rcs++;
                    }
                    temp = str.charAt(a1 + n);
                    if (Character.isDigit(temp))
                        break;
                    if (Character.isLetter(temp) &&
                            !(temp == 'a' || temp == 'e' || temp == 'ı' || temp == 'i' || temp == 'o' || temp == 'ö' || temp == 'u' || temp == 'ü')) {
                        n++;
                        checker = 1;
                    } else break;
                }
            }
        }

        System.out.println("\nrcs count=" + rcs);
    }
}
