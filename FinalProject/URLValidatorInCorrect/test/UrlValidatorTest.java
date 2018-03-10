

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {
	//This is an array of URLs that should return a true
	public static String[] trueArray = {
			"http://", 
			"http://",
			//"ftp://",
			"http://www.google.com",
			
	};
	
	//This is an array of URLs that should return false
	public static String[] falseArray = {
			"3ht://",
			"http:/",
	};

	//The soft assert will return true or false and not crash the program
	public boolean softAssert(boolean value) {
		if (value) {
			return true;
		} else {
			return false;
		}
	}

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //Begin Initial Validation 
	   System.out.println("Beginning testIsValid()");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   String nulString = null;
	   assertFalse(urlVal.isValid(nulString));
	   assertFalse(urlVal.isValid("3ht://"));
	
	   System.out.println("Passed Initial Validation\n");
	   //End Initial Validation
	   
	   //Test an array of values that should return true
	   System.out.println("Number of Positive Tests: " + trueArray.length);
	   for (int index = 0; index < trueArray.length; index++) {
		   
		   System.out.printf("Testing Index: %d \t String: %s \n", index, trueArray[index]);
		   //assertTrue(urlVal.isValid(trueArray[index]));
		   try {
			   //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
			    if (softAssert(urlVal.isValid(trueArray[index]))) {
			   		System.out.println("Test Passed, was expecting true and received true");
			    } else { 
				   	System.out.println("Test Failed, was expecting false and received true");
			    }
		   } catch (Exception e){
			   System.out.println("isValid failed with Exception " + e);
		   }
		   
        }
	   
	   System.out.println("\n");
	   
	   //Test an array of values that should return false
	   System.out.println("Number of Negative Tests: " + falseArray.length);
	   for (int index = 0; index < falseArray.length; index++) {
		   System.out.printf("Testing Index: %d \t String: %s \n", index, falseArray[index]);
		   try {
			   if (softAssert(urlVal.isValid(falseArray[index]))) {
			   		System.out.println("Test Failed, was expecting false and received true"); 
			   } else {
				   	System.out.println("Test Passed, was expecting false and received false");
			   }
		   } catch (Exception e) {
			   System.out.println("isValid failed with Exception " + e);
		   }
		   
		   
	   }
   }
   
   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   fct.testIsValid();
   }
}
