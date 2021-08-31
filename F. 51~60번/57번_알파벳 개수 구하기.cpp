//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char word[200];
//	int wordcount[30] = { 0, };
//
//	gets_s(word);
//
//	for (int i = 0; i < strlen(word); i++)
//	{
//		//printf("hi\n");
//		for (int j = 0; j < 26; j++)
//		{
//			if (word[i] == j + 65 || word[i] == j + 97)
//			{
//				//printf("hi2\n");
//				wordcount[j]++;
//				break;
//			}
//		}
//	}
//	
//	for (int j = 0; j < 26; j++)
//	{
//		if (wordcount[j] > 0)
//		{
//			//printf("hi3\n");
//			printf("%c : %d\n", j + 65, wordcount[j]);
//		}
//	}
//
//
//	return 0;
//}