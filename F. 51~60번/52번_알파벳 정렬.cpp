//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char word[20];
//	char temp, ch1, ch2;
//
//	scanf("%s", word);
//
//	for (int i = 0; i < strlen(word)-1; i++)
//	{
//		for (int j = i + 1; j < strlen(word); j++)
//		{
//			if (word[i] <= 90)
//				ch1 = word[i] + 32;
//			else
//				ch1 = word[i];
//
//			if (word[j] <= 90)
//				ch2 = word[j] + 32;
//			else
//				ch2 = word[j];
//
//			if (ch1 > ch2)
//			{
//				temp=word[i];
//				word[i]= word[j];
//				word[j]= temp;
//			}
//			else if (ch1 == ch2)
//			{
//				if (word[i] > word[j])
//				{
//					temp = word[i];
//					word[i] = word[j];
//					word[j] = temp;
//				}
//			}
//		}
//	}
//
//	printf("%s", word);
//
//	return 0;
//}