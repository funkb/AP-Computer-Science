import java.util.ArrayList;

public class Digits {
    private ArrayList < Integer > digitList; //Given

    public Digits(int num) //Given
    {
        digitList = new ArrayList < Integer > (); //Initialize the ArrayList
        /*  STRING METHOD
        String num1 = String.valueOf(num);    //Convert num to a string
        for (int i = 0; i < num1.length(); i++) {
        	digitList.add(Integer.parseInt(num1.substring(i, i+1)));   //Add every digit to the ArrayList
        }
        */
        //Number Method
        while (num > 0) {
            digitList.add(0, (num - ((int)(num / 10) * 10)); // ArrayList.add (index, value)
                num = (int)(num / 10); //Delete value at the end of our number.
            }
            System.out.println(isStrictlyIncreasing()); //Print out the result of our method.
        }
        

        public boolean isStrictlyIncreasing() //Given
        {
            int previous = Integer.MIN_VALUE; //Compare to the smallest number possible. 
            for (int i: digitList) { //Loop For every int in the ArrayList
                if (i > previous) { //If I is increasing, continue
                    previous = i;
                } else { //If not, stop the program and return false
                    return false;
                }
                
            }


            return true;
        }


    }
