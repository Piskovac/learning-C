#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void arraydegistirici(int* a);
int function1();
int function2(int a,int b);
void binaryoutput(unsigned int value);
void reverse(char* sptr);



enum exits{EXITED_SUC = 0,EXITED_UNSUC = 1};
enum color{red = 10, blue, green,violet,black};
struct {
	unsigned int widthValidated;
	unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct {
	unsigned int widthValidated : 1;
	int : 0;
	unsigned int heightValidated : 1;
} status2;

struct isim
{
	char *name;
	int age;
	int kilo;
}*amfptr;
typedef struct isim Employee;


int main()
{
	int a = 12;
	int* b;
	b = &a;
	if(a++ == 12)
	printf("b nin degeri %21.p\nb nin adresi %21.p\nb nin isaret ettigi deger %8.d\na nin degeri %21.d\n",b,&b,*b,a);
	int arra[5] = {12,1324,23,12,2};
	puts("");
	printf("array pointer %p\nilk arrayin adresi %p\n", arra,&arra[0]);
	printf("%d\n", arra[1]);
	arraydegistirici(arra);
	printf("%d\n", arra[1]);

	puts("");
	char cha = 'a';
	char string[] = "akdfsfkak";
	
	printf("sizeof a %d\nsizeof arra %d\nstring = %s\nsizeof string %d\nsizeof cha %d\nsizeof size_t %d\nsizeof b %d\n",sizeof(a),sizeof(arra),string,sizeof(string),sizeof(cha),sizeof(size_t),sizeof(b));
	
	puts("");
	char* arrayofpointers[] = { "Hearts", "Diamonds", "Clubs","Spades"};
	printf("Array of pointers first value = %s\nSizeof array of pointers %d\nSizeof array of pointers first value = %d\n", *arrayofpointers, sizeof(arrayofpointers), sizeof(*arrayofpointers));
	puts("");

	printf("Pointers to functions, function1 %p\n",function1);
	int(*functions[2])(int, int) = {function1 , function2};
	(*functions[0])(11,20);
	(*functions[1])(9,22);
	

	puts("\n");
	
	struct isim amf = {"ahmet",21,122};
	amfptr = &amf;
	
	printf("Structs \namf name %s\namf yas %d\namf kilo %d\n",amf.name, amf.age,amf.kilo);
	printf("amf name %s\namf yas %d\namf kilo %d\n", amfptr->name,amfptr->age, amfptr->kilo);

	
	
	Employee an = { "armagan" ,20, 73};
	
	printf("an name %s\nan yas %d\nan kilo %d\n", an.name, an.age, an.kilo);
	unsigned int x = 126;
	unsigned int y = x;
	unsigned int z = 5;
	int test = 0;
	char name[] = { "x" };
	system("color a");
	printf("\n\n\nBit manupulation\n");

	y = x << 1;
	printf("x ------->  ");
	binaryoutput(x);
	printf("z ------->  ");
	binaryoutput(z);

	printf("x << 1 -->  ");

	binaryoutput(y);

	y = x >> 1;
	printf("x >> 1 -->  ");
	binaryoutput(y);

	y = ~x;
	printf("~x ------>  ");
	binaryoutput(y);

	test = z & x;
	printf("z & x --->  ");
	binaryoutput(test);

	test = z | x;
	printf("z | x --->  ");
	binaryoutput(test);
	test = z ^ x;
	printf("z ^ x --->  ");
	binaryoutput(test);

	printf("\n\nBit fields\n");
	
	printf("Memory size occupied by status1 : %d\n", sizeof(status1));
	printf("Memory size occupied by status2 : %d\n", sizeof(status2));

	printf("\n\nEnums\n");
	
	for (enum color colora = red; colora <= black; colora++) { printf("%d ", colora);  }
	puts("\n\nStdlib.h functions\n");

	const char strin[] = { "hepsinin toplami 31.32" };
	char* stringptr = &strin;
	printf("stringptr = %p \n",stringptr);
	printf("stringptr+5 = %p \n", stringptr+5);

	double dob = strtod(strin,&stringptr);
	printf("after strtod stringptr = %p \n", stringptr);
	printf("dob = %.2lf\n",dob);
	printf("&dob = %p\n", &dob);
	printf("strin = %s\n",strin);

	const char strin2[] = { "3132 hepsinin toplami " };
	char* remainderptr = "0";
	long sx = strtol(strin2,&remainderptr,0);
	printf("sx = %ldfa\n", sx);


	puts("\n\nStdio.h functions\n");

	char sentence[16];
	char senten[16];
	printf("Enter a string: ");
	fgets(sentence,16,stdin);
	reverse(sentence);
	puts("");
	int sayi = 17;
	float sayi2 = 12.15;

	//sprintf(senten,"sayilar %d %.2f",sayi,sayi2);

	//puts(senten);
	puts("\n\string.h functions\n");


	char s1[]= "a zoo,with,zebras";
	char* s2= "0000000000a33333333333";
	char chr = 'z';
	printf("%c\n",*strpbrk(s1, s2));


	printf("%s\n", strrchr(s1, chr));


	printf("%s",s1);
	
	printf(" --------> %s\n",(char*) memmove(s1, s2 + 8, 10));

	printf("%s\n", strerror(0));
	printf("%s\n\n", strerror(1));
	

	puts("\n\nMemory allocations\n");

	int* ptr,*ptr2;
	int n = 5, i;



	// Dynamically allocate memory using malloc()
	ptr = (int*)malloc(n * sizeof(int));
	ptr2 = (int*)calloc(n,sizeof(int));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using malloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d ", ptr[i]);
		}
	}

	puts("\n");

	if (ptr2 == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using calloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr2[i] = i + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d ", ptr2[i]);
		}
	}
	puts("\n");
	free(ptr);
	

	printf("ptr artik NULL ptr[2] = %d\n", ptr[2]);
	ptr2 = realloc(ptr2,n * sizeof(int));
	printf("ptr2 realloctan sonra ptr2[2] = %d\n", ptr2[2]);


	puts("\n\File\n");
	char st[30];
	char* stptr;
	long h=0, sum = 0;
	FILE* file = fopen("test.txt","r");
	
	if (file == NULL)
	{
		puts("File cant be created\n");
	}
	else
	{ 
		while(!feof(file))
		{

			fscanf(file,"%d",&h);
			sum += h;

		}
		printf("Toplam %d\n", sum);
		fclose(file);
	}
	
	int arr[4][2] = { {5},{15},{25} };
	int brr[4][2] = { 1,2,3 };
	for (int di = 0; di <= 3; di++)
		for (int dj = 1; dj <= 1; dj++)
		{
			printf(" %d", arr[di][dj]);
			printf(" %d", brr[di][dj]);
		}
	puts("");
	system("pause");
	return EXITED_SUC;

}









void arraydegistirici(int *a)
{ 
	int arra[5];
	for (int i = 0; i < 5; i++)
	{
		*(arra + i) = *(a + 4 - i);
	}
	for (int i = 0; i < 5; i++)
	{
		*(a + i) = *(arra + i);
	}
}
int function1()
{
	int aba = 12;
	printf("function1 calisiyor\n");
	return aba*2;
}
int function2(int a, int b)
{
	printf("function2 calisiyor\n");

	return a + b;
}
void binaryoutput(unsigned int value)
{
	unsigned int displaymask = 1 << 31;

	for (unsigned int c = 1 ; c <= 32; c++)
	{
		putchar(value & displaymask? '1' : '0');
		value <<= 1;
		if (c % 4 == 0) { putchar(' '); }
	}
	
	printf("\n");
}
void reverse(char *sptr)
{
	if('\0' == *sptr)
	{
		return;
	}
	else
	{
		reverse(sptr+1);
		putchar(*sptr);
	}
}
