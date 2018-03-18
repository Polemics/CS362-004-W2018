

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {
    //This is an array of URLs that should return a true
    public static String[] trueArray = {
    "http://www.google.com/test1:80",
    "http://www.google.com/test1:-000080", //this should be invalid
    //"ftp://", //crashes
    //"h3t://", //crashes
    };
    
    //This is an array of URLs that should return false
    public static String[] falseArray = {
    ":65636",
    "?action=view",
    "/test1",
    "3ht://",
    "http:/",
    "http:",
    "http/",
    
    };
    
    public static String[] trueSchemeArray = {
    "http://",
    "h3t://",
    "ftp://",
    "",
    
    };
    
    public static String[] falseSchemeArray = {
    "3ht://",
    "http:/",
    "http:",
    "http/",
    "://",
    };
    
    public static String[] trueAuthorityArray = {
    //ALL TRUE AUTHORITY VALUES CAUSE AN EXCEPTION DURING RUNTIME
    //"www.google.com",
    //"go.com",
    //"go.au",
    //"0.0.0.0",
    //"255.255.255.255",
    //"255.com",
    };
    
    public static String[] falseAuthorityArray = {
    //ALL FALSE AUTHORITY VALUES CAUSE AN EXCEPTION DURING RUNTIME
    //"256.256.256.256",
    //"1.2.3.4.5",
    //"1.2.3.4.",
    //"1.2.3",
    //".1.2.3.4",
    //"go.a",
    //"go.a1a",
    //"go.1aa",
    //"aaa.",
    //".aaa",
    //"aaa",
    //"",
    
    };
    
    public static String[] trueFragmentArray = {
    ":80",
    ":65535",
    ":0",
    "",
    
    };
    
    public static String[] falseFragmentArray = {
    ":-1",
    ":65636",
    ":65a",
    };
    
    public static String[] truePathArray = {
    "/test1",
    "/t123",
    "/$23",
    "/test1/",
    "",
    "/test1/file",
    
    };
    
    public static String[] falsePathArray = {
    "/..",
    "/../",
    "/..//file",
    "/test1//file",
    };
    
    public static String[] trueQueryArray = {
    "?action=view",
    "?action=edit&mode=up",
    "",
    };
    
    public static String[] falseQueryArray = {
    };
    
    
    
    
    //The soft assert will return true or false and not crash the program
    public boolean softAssert(boolean value) {
        //System.out.println(value);
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
        System.out.println("Hello World");
        System.out.print("Running manual tests on isValid()\n");
        UrlValidator urlVal = new UrlValidator(null, null,  UrlValidator.ALLOW_ALL_SCHEMES);
        String[] arrayOfManualTests = {"http://ww.go6ogle.com",
            "http://eecs.oregonstate.edu/online-cs-students",
            //                                      "https://www.wellsfargo.com/",
            "ftp:/3sfs",
            "http://www.google.com"};
        boolean result;
        for (int i=0; i<arrayOfManualTests.length; i++)
        {
            //               System.out.printf("i = %d, arrayOfManualTests[i] = %s\n", i, arrayOfManualTests[i]);
            result = urlVal.isValid(arrayOfManualTests[i]);
            if (result)
            {
                System.out.printf("%s is a valid url\n", arrayOfManualTests[i]);
            }
            else
            {
                System.out.printf("%s is NOT a valid url\n", arrayOfManualTests[i]);
            }
        }
        System.out.print("Finished manual tests.\n\n");
    }
    
    // Partitions:
    //
    // 1. Input has invalid URL scheme. All other elements valid.
    //      - returns false at line 313
    //      URL: 3ht://www.google.com:80/test1?action=view
    //      URL: ://255.255.255.255/$23
    // 2. Input has all valid elements. Scheme is "file:" and authority contains a ":" character.
    //      - returns false at line 321
    //      URL: file://www.google.com:80
    //      URL: file://go.com:0
    // 3. Input has invalid URL authority. All other elements valid. Scheme is not "file:".
    //      - returns false at line 328
    //      URL: http://1.2.3.4.5:80/test1?action=view
    //      URL: ftp://go.a:0/t123
    // 4. Input has invalid URL path. All other elements valid.
    //      - returns false at line 333
    //      URL: http://www.google.com/../test1?action=view
    //      URL: ftp://0.0.0.0:0/test1//file
    // 5. Input has invalid URL query. All other elements valid.
    //      - returns false at line 337
    //      URL: http://www.google.com:80/test1?actionview
    //      URL: ftp://go.com/t123?modeup
    // 6. Input has all valid elements in correct order.
    //      - returns true
    //      URL: http://www.google.com:80/test1?action=view
    //      URL: ftp://go.com:0/t123?action=edit&mode=up
    
    public void testPartitions()
    {
        System.out.printf("\nRunning partition tests on isValid()\n\n");
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        String[] partition1 = {"TEST: Invalid URL Scheme", "3ht://www.google.com:80/test1?action=view", "://255.255.255.255/$23"};
        String[] partition2 = {"TEST: Scheme is \'file:\' and authority contains \':\' character.", "file://www.google.com:80", "file://go.com:0"};
        String[] partition3 = {"TEST: Invalid URL Authority", "http://1.2.3.4.5:80/test1?action=view", "ftp://go.a:0/t123"};
        String[] partition4 = {"TEST: Invalid URL Path", "http://www.google.com/../test1?action=view", "ftp://0.0.0.0:0/test1//file"};
        String[] partition5 = {"TEST: Invalid URL Query", "http://www.google.com:80/test1?actionview", "ftp://go.com/t123?modeup"};
        String[] partition6 = {"TEST: All Valid Elements in Correct Order", "http://www.google.com:80/test1?action=view", "ftp://go.com:0/t123?action=edit&mode=up"};
        
        
        String[][] partitions = {partition1, partition2, partition3, partition4, partition5, partition6};
        
        boolean isValid;
        for (int i = 0; i < partitions.length; i++)
        {
            System.out.printf("\n%s\n", partitions[i][0]);
            for (int j = 1; j < partitions[i].length; j++)
            {
                try
                {
                    isValid = urlVal.isValid(partitions[i][j]);
                    if (isValid)
                        System.out.printf("%s is a valid url\n", partitions[i][j]);
                    else
                        System.out.printf("%s is NOT a valid url\n", partitions[i][j]);
                }
                catch (Throwable e)
                {
                    System.out.printf("%s: ", partitions[i][j]);
                    System.out.println("isValid failed with Exception " + e);
                }
            }
        }
        System.out.printf("\nFinished partition tests.\n\n");
    }
    
    
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
        
        //***BEGIN GENERAL isValid TESTING
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + trueArray.length);
        for (int index = 0; index < trueArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, trueArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValid(trueArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting true and received false");
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
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValid failed with Exception " + e);
            }
        }
        
        //***BEGIN SCHEME TESTING
        System.out.println("\nBEGIN SCHEME TESTING\n");
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + trueSchemeArray.length);
        for (int index = 0; index < trueSchemeArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, trueSchemeArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValidScheme(trueSchemeArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting true and received false");
                }
            } catch (Exception e){
                System.out.println("isValidScheme failed with Exception " + e);
            }
            
        }
        
        System.out.println("\n");
        
        //Test an array of values that should return false
        System.out.println("Number of Negative Tests: " + falseSchemeArray.length);
        for (int index = 0; index < falseSchemeArray.length; index++) {
            System.out.printf("Testing Index: %d \t String: %s \n", index, falseSchemeArray[index]);
            try {
                if (softAssert(urlVal.isValidScheme(falseSchemeArray[index]))) {
                    System.out.println("Test Failed, was expecting false and received true");
                } else {
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValidScheme failed with Exception " + e);
            }
        }
        
        //***BEGIN AUTHORITY TESTING
        System.out.println("\nBEGIN AUTHORITY TESTING\n");
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + trueAuthorityArray.length);
        for (int index = 0; index < trueAuthorityArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, trueAuthorityArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValidAuthority(trueAuthorityArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting true and received false");
                }
            } catch (Exception e){
                System.out.println("isValidAuthority failed with Exception " + e);
            }
            
        }
        
        System.out.println("\n");
        
        //Test an array of values that should return false
        System.out.println("Number of Negative Tests: " + falseAuthorityArray.length);
        for (int index = 0; index < falseAuthorityArray.length; index++) {
            System.out.printf("Testing Index: %d \t String: %s \n", index, falseAuthorityArray[index]);
            try {
                if (softAssert(urlVal.isValidAuthority(falseAuthorityArray[index]))) {
                    System.out.println("Test Failed, was expecting false and received true");
                } else {
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValidAuthority failed with Exception " + e);
            }
        }
        
        
        //***BEGIN FRAGMENT TESTING (FRAGMENTS INCLUDE PORTS)
        System.out.println("\nBEGIN FRAGMENT (PORT) TESTING\n");
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + trueFragmentArray.length);
        for (int index = 0; index < trueFragmentArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, trueFragmentArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValidFragment(trueFragmentArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting true and received false");
                }
            } catch (Exception e){
                System.out.println("isValidFragment failed with Exception " + e);
            }
            
        }
        
        System.out.println("\n");
        
        //Test an array of values that should return false
        System.out.println("Number of Negative Tests: " + falseFragmentArray.length);
        for (int index = 0; index < falseFragmentArray.length; index++) {
            System.out.printf("Testing Index: %d \t String: %s \n", index, falseFragmentArray[index]);
            try {
                if (softAssert(urlVal.isValidFragment(falseFragmentArray[index]))) {
                    System.out.println("Test Failed, was expecting false and received true");
                } else {
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValidFragment failed with Exception " + e);
            }
        }
        
        //***BEGIN PATH TESTING
        System.out.println("\nBEGIN PATH TESTING\n");
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + truePathArray.length);
        for (int index = 0; index < truePathArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, truePathArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValidPath(truePathArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting true and received false");
                }
            } catch (Exception e){
                System.out.println("isValidPath failed with Exception " + e);
            }
            
        }
        
        System.out.println("\n");
        
        //Test an array of values that should return false
        System.out.println("Number of Negative Tests: " + falsePathArray.length);
        for (int index = 0; index < falsePathArray.length; index++) {
            System.out.printf("Testing Index: %d \t String: %s \n", index, falsePathArray[index]);
            try {
                if (softAssert(urlVal.isValidPath(falsePathArray[index]))) {
                    System.out.println("Test Failed, was expecting false and received true");
                } else {
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValidPath failed with Exception " + e);
            }
        }
        
        //***BEGIN QUERY TESTING
        System.out.println("\nBEGIN QUERY TESTING\n");
        //Test an array of values that should return true
        System.out.println("Number of Positive Tests: " + trueQueryArray.length);
        for (int index = 0; index < trueQueryArray.length; index++) {
            
            System.out.printf("Testing Index: %d \t String: %s \n", index, trueQueryArray[index]);
            //assertTrue(urlVal.isValid(trueArray[index]));
            try {
                //System.out.println("Return Value From isValid: " + urlVal.isValid(trueArray[index]));
                if (softAssert(urlVal.isValidQuery(trueQueryArray[index]))) {
                    //System.out.println("Test Passed, was expecting true and received true");
                } else {
                    System.out.println("Test Failed, was expecting false and received true");
                }
            } catch (Exception e){
                System.out.println("isValid failed with Exception " + e);
            }
            
        }
        
        System.out.println("\n");
        
        //Test an array of values that should return false
        System.out.println("Number of Negative Tests: " + falseQueryArray.length);
        for (int index = 0; index < falseQueryArray.length; index++) {
            System.out.printf("Testing Index: %d \t String: %s \n", index, falseQueryArray[index]);
            try {
                if (softAssert(urlVal.isValidQuery(falseQueryArray[index]))) {
                    System.out.println("Test Failed, was expecting false and received true");
                } else {
                    //System.out.println("Test Passed, was expecting false and received false");
                }
            } catch (Exception e) {
                System.out.println("isValid failed with Exception " + e);
            }
        }
    }
    
    public static void main(String[] argv) {
        UrlValidatorTest fct = new UrlValidatorTest("url test");
        fct.testManualTest();
        fct.testPartitions();
        fct.testIsValid();
    }
}

