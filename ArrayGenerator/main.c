#include <stdio.h>
#include <time.h>

unsigned int tempinpt[12], OldArray[12], NewArray[12];
int FindMaxFromArray(int* Array);
int CheckItemDuplication(int* Array, int element);

int main(int argc, char** argv) 
{
	unsigned int input = 0, previouchar = 0, MaxNumber = 0, ArrCounter = 0; 
	
	char F_FirstInput = 0, F_numberRepeat = 0;
	
	unsigned long diffInTime = 0, counter = 0;
	
#if 1	
	time_t StartTime, LiveTime;
    time(&StartTime);
    
    printf("WARNING: Enter Number between 0 to 100 and should be odd, exceeding invalid inputs will lead to error and input will not be considered..!!\n");
    printf("WARNING: Duplicate Inputs will not be considered ..!!\n");
    printf("WARNING: Every 5 secs, input should be put till then program will asked to input until you didn't insert..!!\n\n");
    
	while(1) 
	{
        time(&LiveTime);
        diffInTime = difftime(LiveTime, StartTime);
        
        if(diffInTime % 5 == 0)
        {
        	printf("Enter Input number %u: ", counter+1);
        	scanf("%u",&input);
        	
        	if(input >=0 && input <= 100) 
			{
				if(input%2 != 0) /*if no is odd*/
				{
					if(F_FirstInput == 0)
					{
						ArrCounter = 0;
						tempinpt[ArrCounter] = input;
						previouchar = input;
						F_FirstInput = 1;
						ArrCounter++;				
					}
					else if(CheckItemDuplication(tempinpt, input))
					{
						printf("Input alreay given..!\n");
					}
				 	else 
				 	{
				 	 	tempinpt[ArrCounter] = input;
						previouchar = input;
		 				ArrCounter++;
			 		}
				}
				else
				{
					printf("Invalid input, number is not odd!\n");
				}
			} 
			else
			{
				printf("Number is out of bound!\n");
			}
			
        	counter++;
        	if(counter >= 12)
        	{
				break;
			}
		}
	}
	
	/*Print Receive Array*/	
	MaxNumber = FindMaxFromArray(tempinpt); /*Get Maximum Number from input array*/	
	ArrCounter = 0;	
	printf("\nHere it is input array = {");
	while(MaxNumber)
	{
		if(MaxNumber==1)
		{
			printf("%u};", tempinpt[ArrCounter]);
		}
		else
		{
			printf("%u, ", tempinpt[ArrCounter]);
		}
		MaxNumber--;
		ArrCounter++;
	}
	
	printf("\nHere it is maximum value from input array: %u", FindMaxFromArray(tempinpt));
	
	/*Print OLD Array*/
	MaxNumber = FindMaxFromArray(tempinpt) + 1; /*Get Maximum Number from input array*/	
	printf("\nHere it is OLD array = {");
	while(MaxNumber)
	{
		if(MaxNumber==1)
		{
			printf("0};");
		}
		else
		{
			printf("0, ");
		}
		MaxNumber--;
	}
		
	/*Print New Array*/	
	MaxNumber = FindMaxFromArray(tempinpt) + 1; /*Get Maximum Number from input array*/	
	ArrCounter = 0, counter = 0;	
	printf("\nHere it is NEW array = {");
	
	while(MaxNumber)
	{
		if(MaxNumber==1)
		{
			if(ArrCounter == tempinpt[counter])
			{
				printf("1};");
				counter++;
			}
			else
			{
			 	printf("0};");
			}
		}
		else
		{	
			if(ArrCounter == tempinpt[counter])
			{
				printf("1, ");
				counter++;
			}
			else
			{
				printf("0, ");
			}
		}
		ArrCounter++;
		MaxNumber--;
	}	
		
	printf("\nApplication Terminated Successfully.....");
#endif	

	return 0;
}

int FindMaxFromArray(int* Array)
{
	char a = 0;
	int Max = 0;
	for(a=0; a<sizeof(Array); a++)
	{
		if(Array[a] < Array[a+1])
		{
		 	Max = Array[a+1];	
		}
		else if(Array[a]> Array[a+1])
		{
			Max = Array[a];
			
	    }	 		
	}
	return Max;
}

int CheckItemDuplication(int* Array, int element)
{
	char a = 0;
	int result = 0;
	for(a=0; a<sizeof(Array); a++)
	{
		if(element == Array[a] && element > 0)
		{
		 	result++;	
		}
	}
	return result;
}


