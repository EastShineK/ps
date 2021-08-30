//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char word[10][20];
//	char temp[20];
//
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%s", word[i]);
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (strlen(word[i]) > strlen(word[j]))
//			{
//				strcpy_s(temp, word[i]);
//				strcpy_s(word[i], word[j]);
//				strcpy_s(word[j], temp);
//			}
//			else if (strlen(word[i]) == strlen(word[j]))
//			{
//				if (strcmp(word[i], word[j]) > 0)
//				{
//					strcpy_s(temp, word[i]);
//					strcpy_s(word[i], word[j]);
//					strcpy_s(word[j], temp);
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%s\n", word[i]);
//	}
//
//	return 0;
//}