/*
*   numconv2.c
*   Converts Roman numerals to Arabic, and vice versa
*   Jamie Schlessinger
*   August 13, 2012
*/

#include <stdio.h>

void arabtoroman(void);
void romantoarab(void);

int main(void)
{
   char entry;
   char cc;
   
   system("clear");
   printf("\n******************************\n");
   printf("Welcome to Numeral Conversion!\n");

   do
   {
      printf("Please make a selection from the following:\n");
      printf("1) Convert Roman numerals to Arabic numerals\n");
      printf("2) Convert Arabic numerals to Roman numerals\n");
      printf("X) Exit the program\n");
      printf("Your selection: ");
      
      switch (entry = getchar())
      {
	 case '1':
	    while (1)
	    {
	       cc = getchar();
	       if (cc == '\n')
	          break;
	    }
	    romantoarab();
	    break;
         case '2':
	    while (1)
	    {
	       cc = getchar();
	       if (cc == '\n')
	          break;
	    }
	    arabtoroman();
	    break;
	 case 'X':
	    getchar();
	    printf("Goodbye!\n");
	    return 0;
	 case 'x':
	    getchar();
	    printf("Goodbye!\n");
	    return 0;
	 default:
	    while (1)
	    {
	       cc = getchar();
	       if (cc == '\n')
	          break;
	    }
	    printf("Invalid menu choice.  Please enter 1, 2, or X.\n");
	    system("sleep 1");
      }
   } while (entry != 'X');

   return 0;
}

/* arabtoroman.c -- converts Arabic numerals to Roman numerals */

void arabtoroman(void)
{
   int xx, ii;
   printf("Enter a positive integer no greater than 10000: ");
   scanf("%d", &xx);
   printf("\n");

   if (xx > 10000)
   {
      printf("Error: number too large!\n");
      getchar();
      system("sleep 1");
      return;
   }

   system("sleep 0.5");
   printf("Your number in Roman numerals is: ");

   while (xx >= 1000)
   {
      printf("M");
      xx -= 1000;
   }

   if (xx >= 900)
   {
      printf("CM");
      xx -= 900;
   }

   if (xx >= 500)
   {
      printf("D");
      xx -= 500;
   }

   if (xx >= 400)
   {
      printf("CD");
      xx -= 400;
   }

   while (xx >= 100)
   {
      printf("C");
      xx -= 100;
   }

   if (xx >= 90)
   {
      printf("XC");
      xx -= 90;
   }

   if (xx >= 50)
   {
      printf("L");
      xx -= 50;
   }

   if (xx >= 40)
   {
      printf("XL");
      xx -= 40;
   }

   while (xx >= 10)
   {
      printf("X");
      xx -= 10;
   }

   if (xx >= 9)
   {
      printf("IX");
      xx -= 9;
   }

   if (xx >= 5)
   {
      printf("V");
      xx -= 5;
   }

   if (xx >= 4)
   {
      printf("IV");
      xx -= 4;
   }

   while (xx > 0)
   {
      printf("I");
      xx -= 1;
   }

   getchar();
   printf("\n\n");
   system("sleep 0.5");
}

/* romantoarab.c -- converts Roman numerals to Arabic */

#include <stdio.h>

void romantoarab(void)
{
   char roman[40];
   char *proman;
   int ii;
   int count = 0;
   proman = roman;

   printf("Enter a number in Roman numerals: ");
   scanf("%s", roman);

   for (; *proman; proman++)
   {
      *proman = toupper(*proman);
      if (*proman != 'M' && *proman != 'D' && *proman != 'C' &&
	  *proman != 'L' && *proman != 'X' && *proman != 'V' &&
	  *proman != 'I')
      {
	 printf("Error: entry was not a valid Roman numeral!\n");
	 printf("Entry must consist of M, D, C, L, X, V, and I only.\n");
	 return;
      }
   }


   for (proman = roman; *proman; proman++)
   {
      if (*proman == 'M')
      {
	 count += 1000;
      }
      else if (*proman == 'D')
      {
	 count += 500;
      }
      else if (*proman == 'C')
      {
	 if (*(proman+1) == 'M')
	 {
	    count += 900;
	    proman++;
	 }
	 else if (*(proman+1) == 'D')
	 {
	    count += 400;
	    proman++;
	 }
	 else
	 {
	    count += 100;
	 }
      }
      else if (*proman == 'L')
      {
	 count += 50;
      }
      else if (*proman == 'X')
      {
	 if (*(proman+1) == 'C')
	 {
	    count += 90;
	    proman++;
	 }
	 else if (*(proman+1) == 'L')
	 {
	    count += 40;
	    proman++;
	 }
	 else
	 {
	    count += 10;
	 }
      }
      else if (*proman == 'V')
      {
	 count += 5;
      }
      else
      {
	 if (*(proman+1) == 'X')
	 {
	    count += 9;
	    proman++;  
	 }
	 else if (*(proman+1) == 'V')
	 {
	    count += 4;
	    proman++;
	 }
	 else
	 {
	    count += 1;
	 }
      }
   }  

   getchar();
   printf("\n");
   system("sleep 0.5");
   printf("Your entry, converted to Arabic numerals, is %d.\n\n", count);
   system("sleep 0.5");
}
