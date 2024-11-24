/******************
Name:Amit Rothschild
ID:322317637
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
	int optionTask1 = 1;
	while (optionTask1 != 7)
	{
		printf("Choose an option:\n    1. Happy Face\n    2. Balanced Number\n    3. Generous Number\n    4. Circle Of Joy\n    5. Happy Numbers\n    6. Festival Of Laughter\n    7. Exit\n");
		scanf("%d", &optionTask1);
		switch (optionTask1)
		{
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
		case 1:

			int faceSize;
			char mouth , nose , eyes;
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c %c %c",&eyes,&nose,&mouth);
			printf("Enter face size:\n");
			scanf("%d", &faceSize);
			while (faceSize <= 0 || faceSize % 2 == 0)
			{
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d", &faceSize);
			}
			printf("%c", eyes);
			for (int i =0; i < faceSize; i++)
			{
				printf(" ");
			}
			printf("%c\n", eyes);
			for (int i =0; i < (faceSize+1)/2; i++)
			{
				printf(" ");
			}
			printf("%c\n", nose);
			printf("\\");
			for (int i =0; i < faceSize; i++)
			{
				printf("%c", mouth);
			}
			printf("/\n");
			break;

			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
		case 2:
			int numberTask2; //
			printf("Enter a number:\n");
			scanf("%d", &numberTask2);
			while (numberTask2 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &numberTask2);
			}
			int checkNumTask2 = numberTask2;
			int countDigTask2=0;
			while (checkNumTask2 != 0)
			{
				checkNumTask2 = checkNumTask2/10;
				countDigTask2++;
			}
			int sum1Task2 = 0;
			int sum2Task2 = 0;
			int tensCounter = 1;
			int numDigSupply = numberTask2;
			for (int i =0; i < countDigTask2/2; i++)
			{
				numDigSupply = numDigSupply/10;
				numDigSupply = numDigSupply*10;
				sum1Task2 = sum1Task2 + ((numberTask2/tensCounter)-(numDigSupply));
				numDigSupply = numDigSupply/10;
				tensCounter = tensCounter*10;
			}
			if (countDigTask2%2 == 1)
			{
				numDigSupply = numDigSupply/10;
				tensCounter = tensCounter*10;
			}
			for (int i =0; i < countDigTask2/2; i++)
			{
				numDigSupply = numDigSupply/10;
				numDigSupply = numDigSupply*10;
				sum2Task2 = sum2Task2 + ((numberTask2/tensCounter)-(numDigSupply));
				numDigSupply = numDigSupply/10;
				tensCounter = tensCounter*10;
			}
			if(sum1Task2==sum2Task2)
				printf("This number is balanced and brings harmony!\n");
			else
				printf("This number isn't balanced and destroys harmony.\n");
			break;


			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
		case 3:
			int numberTask3;
			printf("Enter a number:\n");
			scanf("%d", &numberTask3);
			while (numberTask3 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &numberTask3);
			}
			int multiplyCheckerTask3 = 2;
			int multiplySaverTask3 = 2;
			int multiplySumTask3 = 1;
			while (multiplyCheckerTask3<numberTask3)
			{
				while (multiplyCheckerTask3 < numberTask3)
				{
					multiplyCheckerTask3 += multiplySaverTask3;
				}
				if (multiplyCheckerTask3==numberTask3)
					multiplySumTask3 = multiplySumTask3 + multiplySaverTask3;
				multiplySaverTask3++;
				multiplyCheckerTask3 = multiplySaverTask3;
			}
			if (multiplySumTask3>numberTask3)
				printf("This number is generous!\n");
			else
				printf("This number does not share.\n");
			break;


			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/


			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/

			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			return 0;



		case 7:
			printf("Thank you for your journey through Numeria!\n");
			break;
		default:
			printf("This option is not available, please try again.\n");
			break;
		}
	}
}
