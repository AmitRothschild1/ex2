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
			int faceSize; //size of face integer
			char mouth , nose , eyes; //chars representing the eyes nose and mouth
			printf("Enter symbols for the eyes, nose, and mouth:\n"); //ask used to input
			scanf(" %c %c %c",&eyes,&nose,&mouth); //users input
			printf("Enter face size:\n"); //asks user to input
			scanf("%d", &faceSize); //users input
			while (faceSize <= 0 || faceSize % 2 == 0) //loop keeps running if facesize is even or its equals to zero or negative
			{
				printf("The face's size must be an odd and positive number, please try again:\n"); //ask users input again
				scanf("%d", &faceSize); //input
			}
			//face building
			printf("%c", eyes); //prints one eye
			for (int i =0; i < faceSize; i++)
			{
				printf(" "); //prints space - facesize number of times
			}
			printf("%c\n", eyes); //prints second eye
			for (int i =0; i < (faceSize+1)/2; i++)
			{
				printf(" "); //prints space - facesize number minus 1 times
			}
			printf("%c\n", nose); //prints nose
			printf("\\"); //prints start of mouth
			for (int i =0; i < faceSize; i++)
			{
				printf("%c", mouth); //prints middle mouth - facesize number amount
			}
			printf("/\n"); //prints end of mouth
			break; //stops the program - back to menu

			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
		case 2:
			int numberTask2; //Integer variable
			printf("Enter a number:\n"); //asks user to input number
			scanf("%d", &numberTask2); //input
			//loop makes sure the input is positive
			while (numberTask2 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &numberTask2);
			}
			int checkNumTask2 = numberTask2; //variable that checks how much digits the number has
			int countDigTask2=0; // digits counter
			//loop keeps running if the count is not done
			while (checkNumTask2 != 0)
			{
				checkNumTask2 = checkNumTask2/10; //take right digit off
				countDigTask2++; //adding 1 to the sum
			}
			int sum1Task2 = 0; //sum of the number's right part
			int sum2Task2 = 0; //sum of the number's left part
			int tensCounter = 1; //divides the number for substracting the relevant number
			int numDigSupply = numberTask2; //using input number for substraction
			//loop keeps runnin until we checked all right side
			for (int i =0; i < countDigTask2/2; i++)
			{
				numDigSupply = numDigSupply/10;
				numDigSupply = numDigSupply*10; //makes sure our right digit is 0
				sum1Task2 = sum1Task2 + ((numberTask2/tensCounter)-(numDigSupply)); //substraction for getting the right digit and add to the sum
				numDigSupply = numDigSupply/10; //take right digit off
				tensCounter = tensCounter*10; //grow to divide our number in the next round
			}
			//if number of digits is odd - get rid of the right digit
			if (countDigTask2%2 == 1)
			{
				numDigSupply = numDigSupply/10;
				tensCounter = tensCounter*10;
			}
			//loop keeps runnin until we checked all left side
			for (int i =0; i < countDigTask2/2; i++)
			{
				numDigSupply = numDigSupply/10;
				numDigSupply = numDigSupply*10; //makes sure our right digit is 0
				sum2Task2 = sum2Task2 + ((numberTask2/tensCounter)-(numDigSupply)); //substraction for getting the right digit and add to the sum
				numDigSupply = numDigSupply/10; //take right digit off
				tensCounter = tensCounter*10; //grow to divide our number in the next round
			}
			//if sum of right side equals to left side - prints massage to user
			if(sum1Task2==sum2Task2)
				printf("This number is balanced and brings harmony!\n");
			else //if not - print other massage
				printf("This number isn't balanced and destroys harmony.\n");
			break; //stops the program - back to menu


			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
		case 3:
			int numberTask3; //Integer variable
			printf("Enter a number:\n"); //ask user input
			scanf("%d", &numberTask3); //input
			//makes sure input number is positive
			while (numberTask3 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &numberTask3);
			}
			int multiplyCheckerTask3 = 2; //checks if value divides number
			int multiplySaverTask3 = 2; //save check number
			int multiplySumTask3 = 1; //count how many times the number divides
			//loop ends when result bigger than our number - counts if number divides on every number
			while (multiplyCheckerTask3<numberTask3)
			{ //makes sure the number dividing
				while (multiplyCheckerTask3 < numberTask3)
				{
					multiplyCheckerTask3 += multiplySaverTask3; //add divider to sum
				}
				//summing every number that divides the input number
				if (multiplyCheckerTask3==numberTask3)
					multiplySumTask3 = multiplySumTask3 + multiplySaverTask3;
				multiplySaverTask3++;
				multiplyCheckerTask3 = multiplySaverTask3;
			}
			//if sum is bigger than input - print positive text
			if (multiplySumTask3>numberTask3)
				printf("This number is generous!\n");
			else //if not-negative text
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
                int numberTask4; //Integer variable
            printf("Enter a number:\n"); //ask user input
            scanf("%d", &numberTask4); //input
			//makes sure input number is positive
            while (numberTask4 <= 0)
            {
                printf("Only positive number is allowed, please try again:\n"); //ask user input
                scanf("%d", &numberTask4); //input
            }
            //count digits
            int checkNumTask4 = numberTask4; //for duplicating input number
            int countDigTask4=0; //digits sum starts from 0
            while (checkNumTask4 != 0) //keep running until no number left
            {
                checkNumTask4 = checkNumTask4/10; //get rid of right digit
                countDigTask4++; //add 1 to sum
            }
            int numSaverTask4 = numberTask4; //saving input number
            int reverseNumTask4 = 0; //storing reversed number
            int tensCounterTask4 = 1; //tens counter for turning number to reversed number
			//tens calculator
            for (int i =1; i < countDigTask4; i++) //keeps running number of digits times
            {
                tensCounterTask4 = tensCounterTask4*10; //add 0 to the tens counter
            }
			//reverse creation
            while (numSaverTask4 > 0) //keeps running until input number has no digits left
            {
                int subFromTask4 = numSaverTask4; //duplicates input number
                numSaverTask4 = numSaverTask4/10;
                numSaverTask4 = numSaverTask4*10; //change right digit to 0
                reverseNumTask4 = reverseNumTask4 + ((subFromTask4 - numSaverTask4) * tensCounterTask4); //take the right digit of original number and miltiplies him in tens counter for the reverse process
                tensCounterTask4 = tensCounterTask4/10; //get rid of right 0
                numSaverTask4 = numSaverTask4/10; //get rid of right digit
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
            while (multiplyCheckerTask4<numberTask4) //process keeps going if no result found and check number smaller than original
            {
                while (multiplyCheckerTask4 < numberTask4) //keeps runnin if results smaller than input number
                {
                    multiplyCheckerTask4 += multiplySaverTask4; //add to sum the current number
                }
                if (multiplyCheckerTask4==numberTask4) //if the number divides - means that it is not prime
                {
                    primeCheckerTask4++;
                    printf("The circle remains incomplete.\n"); //prints massage to user
                    break; //get out of the loop
                }
                multiplySaverTask4++; //add 1 to the current divider check
                multiplyCheckerTask4 = multiplySaverTask4; //saving the value for the condition result
            }
			//reversed number prime check
            if (primeCheckerTask4==0) //if original number is prime - keeps on checking the reversed number
            {
                multiplyCheckerTask4 = 2; //
                multiplySaverTask4 = 2;
                while (multiplyCheckerTask4<reverseNumTask4) //process keeps going if no result found and check number smaller than original
                {
                    while (multiplyCheckerTask4 < reverseNumTask4) //process keeps going if no result found and check number smaller than original
                    {
                        multiplyCheckerTask4 += multiplySaverTask4; //add to sum the current number
                    }
                    if (multiplyCheckerTask4==reverseNumTask4) //if the number divides - means that it is not prime
                    {
                        primeCheckerTask4++;
                        printf("The circle remains incomplete.\n"); //prints massage to user
                        break; //get out of the loop
                    }
                    multiplySaverTask4++; //add 1 to the current divider check
                    multiplyCheckerTask4 = multiplySaverTask4; //saving the value for the condition result
                }

                if (primeCheckerTask4==0) //if counter equals to 0 - means that both original and reversed numbers are prime
                    printf("This number completes the circle of joy!\n"); //when both original and reversed numbers are prime - print text
            }
            break; //stops the program - back to menu



			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
		case 5:
			int numberTask5; //Integer variable
			printf("Enter a number:\n"); //ask user input
			scanf("%d", &numberTask5); //input
			//makes sure input is a positive number
			while (numberTask5 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &numberTask5);
			}
			printf("Between 1 and %d only these numbers bring happiness: ", numberTask5); //prints the start of the finish massage
			int numSaverTask5 = 0; //use for storing happy number values
			//loop makes process on every number between 1 and input number
			for (int i = 1; i <= numberTask5; i++)
			{
				numSaverTask5 = i; //check happy test on number=i
				//loop keeps running if: number is happy for sure OR number is not happy for sure
				while (numSaverTask5 != 1 && numSaverTask5 != 4 && numSaverTask5 != 7)
				{
					int sumTask5 = 0; //make sure the happy calculator is 0 in the start of the process
					//loop summings the digits power - until no digits left
					while (numSaverTask5 > 0)
					{
						int numSubTask5 = numSaverTask5/10; //the number that sub the saved one
						numSubTask5 = numSubTask5*10; //make sure the right digit is 0
						sumTask5 = sumTask5 + (numSaverTask5 - numSubTask5)*(numSaverTask5-numSubTask5); //add digit power to sum
						numSaverTask5 = numSaverTask5/10; //get rid of the right digit
					}
					//printf("%d",sum);
					numSaverTask5 = sumTask5; //make sure the rest of the process is on the sum we calculated
				}
				//if result is happy - print the number
				if (numSaverTask5 == 1 || numSaverTask5 == 7)
					printf("%d ",i);
			}
			printf("\n"); //one row down
			break; //stop case to the options menu

			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 6:
            int smileTask6 , cheerTask6; //smile + cheer variables
            printf("Enter a smile and cheer number:\n"); //ask user input
            scanf("%*[^\n]"); //cleans input buffer
            scanf("%*[\n]"); //cleans rest of new lines from buffer
            scanf("smile: %d, cheer: %d",&smileTask6,&cheerTask6);
			//loop keeps running until all inputs are positive and diffrent from each other
            while (smileTask6 <= 0 || cheerTask6 <= 0 || smileTask6 == cheerTask6)
            {
                printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n"); //error input print
                scanf("%*[^\n]"); //cleans input buffer
                scanf("%*[\n]"); //cleans rest of new lines from buffer
                scanf("smile: %d, cheer: %d",&smileTask6,&cheerTask6); //input
            }
            //max input
            int maxNumTask6; //max number value vriable
            printf("Enter maximum number for the festival:\n"); //ask user input
            scanf("%*[^\n]"); //cleans input buffer
            scanf("%*[\n]"); //cleans rest of new lines from buffer
            scanf("%d", &maxNumTask6); //input
            while (maxNumTask6 <= 0) //keeps running if max number is not positive
            {
                printf("Only positive maximum number is allowed, please try again:\n"); //ask user input
                scanf("%*[^\n]"); //cleans input buffer
                scanf("%*[\n]"); //cleans rest of new lines from buffer
                scanf("%d", &maxNumTask6); //input
            }
            int smileMathNumTask6 = 0; //storing sum of smile value
            int cheerMathNumTask6 = 0; //storing sum of cheer value
            for (int i = 1; i < maxNumTask6+1; i++) //makes process on every number between 1 and input number
            {
                cheerMathNumTask6 = cheerTask6; //sum value starts equal to cheer value
                smileMathNumTask6 = smileTask6; //sum value starts equal to smile value
                while (smileMathNumTask6 < i) //loop keeps running if sum smaller than current number
                {
                    smileMathNumTask6 += smileTask6; //smile sum calculation
                }
                while (cheerMathNumTask6 < i) //loop keeps running if sum smaller than current number
                {
                    cheerMathNumTask6 += cheerTask6; //cheer sum calculation
                }
                if (smileMathNumTask6==i && cheerMathNumTask6==i)
                    printf("Festival!\n"); //if smile and cheer are dividing in the current number (i) - Print "festival"
                else
                if (smileMathNumTask6 == i && cheerMathNumTask6 != i)
                    printf("Smile!\n"); //if smile divides in i and cheer does not - Print "smile"
                else
                if (smileMathNumTask6!=i && cheerMathNumTask6==i)
                    printf("Cheer!\n"); //if cheer divides in i and smile does not - Print "cheer"
                else
                if (smileMathNumTask6!=i && cheerMathNumTask6!=i)
                    printf("%d\n",i); //if any of the numbers does not divide - Print current number value
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
