/******************
Name:Amit Rothschild
ID:322317637
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
	int optionTask1 = 1; //Integer variable used for users option selection
	while (optionTask1 != 7) //If user chose 7 - program keeps running. Else - the program will stop.
	{
		printf("Choose an option:\n    1. Happy Face\n    2. Balanced Number\n    3. Generous Number\n    4. Circle Of Joy\n    5. Happy Numbers\n    6. Festival Of Laughter\n    7. Exit\n"); //Prints users options
		scanf("%d", &optionTask1); //option input
		switch (optionTask1) //Aiming for the selected option
		{
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
		case 1: //In case users chose  option 1
			//variables inputs
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
			//face building
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
			break; //stops the program - back to menu

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
			break; //stops the program - back to menu


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
			break; //stops the program - back to menu


			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			        case 4:
            //input number
                int numberTask4;
            printf("Enter a number:\n");
            scanf("%d", &numberTask4);
            while (numberTask4 <= 0)
            {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d", &numberTask4);
            }
            //count digits
            int checkNumTask4 = numberTask4;
            int countDigTask4=0;
            while (checkNumTask4 != 0)
            {
                checkNumTask4 = checkNumTask4/10;
                countDigTask4++;
            }
            int numSaverTask4 = numberTask4;
            int reverseNumTask4 = 0;
            int tensCounterTask4 = 1;
			//tens calculator
            for (int i =1; i < countDigTask4; i++)
            {
                tensCounterTask4 = tensCounterTask4*10;
            }
			//reverse creation
            while (numSaverTask4 > 0)
            {
                int subFromTask4 = numSaverTask4;
                numSaverTask4 = numSaverTask4/10;
                numSaverTask4 = numSaverTask4*10;
                reverseNumTask4 = reverseNumTask4 + ((subFromTask4 - numSaverTask4) * tensCounterTask4);
                tensCounterTask4 = tensCounterTask4/10;
                subFromTask4 = subFromTask4/10;
                numSaverTask4 = numSaverTask4/10;
            }
            if (numberTask4 == 1)
            {
                printf("The circle remains incomplete.\n"); //if users chose 1 - prints  the "incomplete" massage
                break; //Back to menu
            }
            //regular number prime check
            int multiplyCheckerTask4 = 2;
            int multiplySaverTask4 = 2;
            int primeCheckerTask4 = 0;
            while (multiplyCheckerTask4<numberTask4)
            {
                while (multiplyCheckerTask4 < numberTask4)
                {
                    multiplyCheckerTask4 += multiplySaverTask4;
                }
                if (multiplyCheckerTask4==numberTask4)
                {
                    primeCheckerTask4++;
                    printf("The circle remains incomplete.\n");
                    break;
                }
                multiplySaverTask4++;
                multiplyCheckerTask4 = multiplySaverTask4;
            }
			//reversed number prime check
            if (primeCheckerTask4==0) //if original number is prime - keeps on checking the reversed number
            {
                multiplyCheckerTask4 = 2;
                multiplySaverTask4 = 2;
                while (multiplyCheckerTask4<reverseNumTask4)
                {
                    while (multiplyCheckerTask4 < reverseNumTask4)
                    {
                        multiplyCheckerTask4 += multiplySaverTask4;
                    }
                    if (multiplyCheckerTask4==reverseNumTask4)
                    {
                        primeCheckerTask4++;
                        printf("The circle remains incomplete.\n");
                        break;
                    }
                    multiplySaverTask4++;
                    multiplyCheckerTask4 = multiplySaverTask4;
                }

                if (primeCheckerTask4==0)
                    printf("This number completes the circle of joy!\n");
            }
            break; //stops the program - back to menu



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
			case 6:
            //smile + cheer input
            int smileTask6 , cheerTask6;
            printf("Enter a smile and cheer number:\n");
            scanf("%*[^\n]");
            scanf("%*[\n]");
            scanf("smile: %d, cheer: %d",&smileTask6,&cheerTask6);
            while (smileTask6 <= 0 || cheerTask6 <= 0 || smileTask6 == cheerTask6)
            {
                printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                scanf("%*[^\n]");
                scanf("%*[\n]");
                scanf("smile: %d, cheer: %d",&smileTask6,&cheerTask6);
            }
            //max input
            int maxNumTask6;
            printf("Enter maximum number for the festival:\n");
            scanf("%*[^\n]");
            scanf("%*[\n]");
            scanf("%d", &maxNumTask6);
            while (maxNumTask6 <= 0)
            {
                printf("Only positive maximum number is allowed, please try again:\n");
                scanf("%*[^\n]");
                scanf("%*[\n]");
                scanf("%d", &maxNumTask6);
            }
            int smileMathNumTask6 = 0;
            int cheerMathNumTask6 = 0;
            for (int i = 1; i < maxNumTask6+1; i++)
            {
                cheerMathNumTask6 = cheerTask6;
                smileMathNumTask6 = smileTask6;
                while (smileMathNumTask6 < i)
                {
                    smileMathNumTask6 += smileTask6;
                }
                while (cheerMathNumTask6 < i)
                {
                    cheerMathNumTask6 += cheerTask6;
                }
                if (smileMathNumTask6==i && cheerMathNumTask6==i)
                    printf("Festival!\n");
                else
                if (smileMathNumTask6 == i && cheerMathNumTask6 != i)
                    printf("Smile!\n");
                else
                if (smileMathNumTask6!=i && cheerMathNumTask6==i)
                    printf("Cheer!\n");
                else
                if (smileMathNumTask6!=i && cheerMathNumTask6!=i)
                    printf("%d\n",i);
            }
            break;
			return 0;



		case 7: //In case users chose option 7
			printf("Thank you for your journey through Numeria!\n"); //Prints goodbye massage
			break; //Stops the program (back to menu + loop condition is false)
		default: //In case users chose number that is not on the menu
			printf("This option is not available, please try again.\n"); //Prints error
			break; //Back to options
		}
	}
}
