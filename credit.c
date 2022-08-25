#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for input
   long number = get_long("Number:\n");

   long first, second;

   int counter = 0, verify = 0,  result = 0;

   //sum of numbers

   while (number > 0)
   {
       if (counter % 2 == 0)
       {
           result = result + (number % 10);
       }
       else
       {
           //odd multiples
           verify = (number % 10) * 2;

           //if more than 10 add together
           if (verify % 10 != 0 || verify % 10 == 0)
           {
               verify = (verify % 10) + (verify / 10);
           }
           //sum of multiples
           result = result + verify;

       }

       //saving numbers to check
       second = first;
       first = number;
       counter ++;
       number = number / 10;
   }

   if (result % 10 == 0 && (first == 4 || first == 3 || first == 5))
   {
       //amex start with 34 or 37
       if ((second == 34 || second == 37) && counter == 15)
       {
           printf("AMEX\n");
       }
       else
       //mastercard start with 51, 52, 53, 54, 55
       if ((second == 51 || second == 52 || second == 53 || second == 54 || second == 55) && counter == 16)
       {
           printf("MASTERCARD\n");
       }
       else
       //visa numbers start with 4
       if ((first == 4) && (counter == 13 || counter == 16))
       {
           printf("VISA\n");
       }
       else
       {
           printf("INVALID\n");
       }
   }
   else
   {
       //all other invalid input
       printf("INVALID\n");
   }


}