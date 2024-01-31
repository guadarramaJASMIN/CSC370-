/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package bui_hw;
import java.util.Scanner;
/**
 *
 * @author jas
 */
public class Bui_hw 
{

    /**
     * @param args the command line arguments
     */
    
    //-----------------------------------------------------------
    //MAIN CLASS
    
    public static void main(String[] args) 
    {
        //placing the scannner to read the users input
        Scanner scanner = new Scanner (System.in);
       
        //asking the user to enter a string
        System.out.println("Please enter a string: ");
        
        //reading the string input 
        String input = scanner.nextLine();
        
        //making sure input is from 0-50 characters
        if(isVALIDin(input))
        {
        
           //calling runlengthencode class and using the
        //encode method for the input and gives us encoded output
        String enSTRING = RunLengthEncode.encode(input);
        
        //printing the encded string/OUTPUT
        System.out.println("Output (encoded) string:"  + enSTRING );
            
            
        }
        
        
        else
          //GIVING error message to user about range error
        {
            System.out.println("ERROR!INVALID INPUT!");
        
        }
        
    }  
     
   //----------------------------------------------------------- 
    
    
    //Run length encode class
    public class RunLengthEncode 
    {
    
    

    //Method encode; which accepts a string argument
    public static String encode(String x)
    {
      //builds the string
    StringBuilder output = new StringBuilder();
    
   
    //variable for number
    int v =1; 
    
    
    //loops over the charcters of the input
    for(int a = 1; a < x.length(); a++)
    {
       //checks to see if current character = previous character
        if(x.charAt(a)== x.charAt(a-1))
        {
            //basically telling us the character repeats
            v++;
        
        }
        
        
        
        else
        {
            //means it wasn't a repititon and we can encode it
            //calling the encoding method; run, to encoe the input 
            
            output.append(Run(x.charAt(a-1),v));
            //basically a reset button//new encode process
            v =1;
        
        }
    
    
    }
    
    //making sure it was actually runs correctly all the way to the end 
        output.append(Run(x.charAt(x.length()-1),v));
        
       //string output returned
        return output.toString();
    
    
    
    }
    
    //---------------------------------------------------------------
    
    //end of runlengthencode class
    
    }
  //------------------------------------------------------  
    
    
  //FORMATTING method that accepts char  and number for the number of times its gonna be repeated  
  private static String Run(char c, int NUMBER)
  {
      
  //-------------------------------------------------
     
      //making sure that the inouts are for 0 to 9 
      //number bigger than 1 and less than 
      if(NUMBER>1 && NUMBER<=4)
      {
      
      //returns a string "c" that repates the number of times the number is 
      return String.valueOf(c).repeat(NUMBER);
      
      
      }
      
   //----------------------------------------------------   
      
      
     
      //if it is greater than four then we apply the format
      //two digit rep.
      
      else if(NUMBER > 4)
      {
          
          return "/" + String.format("%02d", NUMBER) +  c;
      
      }
       
      
   //----------------------------------------------------   
      else
      {
          
       //if number is 1 then don't repat nothing 
       //returns the string
      return String.valueOf(c);
      
      }   
  
  }
  
  
  //----------------------------------------------------------------
  ////----------------------------------------------------   
  //method
  //for special characters
  private static boolean isSPECIAL(char c)
  {
  
      String specialCHAR = "{}[]():;'+=.,";
      
      return specialCHAR.indexOf(c) >=0;
  
  
  }
  //----------------------------------------------------   
  //------------------------------------------------------------------
  
  
  
       
     
    //safety nets
  private static boolean isVALIDin(String in)
  {
      ////making sure the length of the input is from 0- 50
        if(in.length()> 50)
        {
  
            return false;
  
        }
  
  
  //making sure to only accept uppercase and lowercase alphabet symbols      
  for(char ch : in.toCharArray())
  {
  
      
   if(!islow(ch)&& !isup(ch)&& !number(ch)&& ch!= ' ' &&!isSPECIAL(ch))   
      
   {
       return false;
   
   }
      
  }
  
    return true;
  
  }
  
  
 //------------------------------------------------- 
  // checks for lower case 
 private static boolean islow(char c)
 {
 
 return (c >= 'a' && c <='z');
 
 }
 
 //------------------------------------------------
 private static boolean isup(char c)
 {
     return (c >= 'A' && c <='Z');
 
 }
         
 //-----------------------------------------

private static boolean number(char c) 
{
    return (c >= '0' && c <='9');

}
}



       

    

    

