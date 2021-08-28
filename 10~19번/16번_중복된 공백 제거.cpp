//#include<stdio.h>
//
//int main()
//{
//	char data[20];
//
//	gets_s(data);
//
//	for (int i = 0; i < 20; i++)
//	{
//		if (data[i] == ' ')
//		{
//			//printf("k1\n");
//			while (data[i + 1] == ' ')
//			{
//				//printf("k2\n");
//				for (int c = i; c < 20; c++)
//				{
//					//printf("k3\n");
//					if (data[c + 2] != '\0')
//						data[c + 1] = data[c + 2];
//					else
//						data[c + 1] = '\0';
//				}
//			}
//		}
//	}
//	//printf("k\n");
//
//	for (int i = 0; i < 20; i++)
//	{
//		if (data[i] != '\0')
//			printf("%c", data[i]);
//		else
//			break;
//	}
//
//	return 0;
//}