//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char word[99];
//	int wordsite[26] = { 0, };
//
//	gets_s(word);
//
//	for (int j = 0; j < strlen(word); j++)
//	{
//		for (int k = 0; k < 26; k++)
//		{
//			if (word[j] == k + 65 || word[j] == k + 97)
//			{
//				if (wordsite[k] == 0)
//					wordsite[k] = j + 1;
//			}
//		}
//	}
//
//
//	for (int i = 0; i < 26; i++)
//	{
//		printf("%d ", wordsite[i]);
//	}
//
//	return 0;
//}