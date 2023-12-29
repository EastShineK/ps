//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char sentence[100], word[100];
//	int i, check = 0;
//
//	gets_s(sentence); 
//	gets_s(word);
//
//	for (i = 0; i < strlen(sentence); i++)
//	{
//		if (sentence[i] == word[0])
//		{
//			//printf("hi\n");
//			for (int j = 0; j < strlen(word); j++)
//			{
//				//printf("hi1\n");
//				if (word[j] != sentence[i+j])
//				{
//					//printf("hi2\n");
//					check = 1;
//					break;
//				}
//				if (j == strlen(word) - 1 /*&& check == 1*/)
//				{
//					//printf("hi3\n");
//					check = 2;
//				}
//			}
//		}
//		if (check == 2)
//			break;
//		if (i == strlen(sentence) - 1 && check != 2)
//		{
//			printf("No\n");
//			return 0;
//		}
//
//	}
//	printf("%d", i + 1);
//
//	return 0;
//}