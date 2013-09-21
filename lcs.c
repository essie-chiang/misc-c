#include<stdio.h>
#define MAX 50
#define CSIZE(x) (sizeof(x)/sizeof(char)-1)
#define UP 1
#define LEFT 0
#define LEFTUP -1
void printlcs(int arr[][MAX],int pre[][MAX], char *s1, char *s2, int j, int i);
//sizeof a is not as an array in passing value
int length(char* a){
	int len = 0;
	len = sizeof(*a)/sizeof(char);	//a is not an array, just a pointer
	return len;
}
//just tell you the different betweent two kinds announcement
int sizearray(){
	char s1[] = "ABCABCBA"; //the size inlude '\0'
	char s[] = {'A','B','C','A','B','C','B','A'};  // size without '\0'
	printf("size of b is %d\n", CSIZE(s1));
	printf("size of b is %d\n", CSIZE(s));
	printf("s1 : %s", s1); //print to own '\0'
	printf("s : %s", s);	//print until find '\0' belongs to others

}
int max(int a, int b){
	return a > b ? a : b;
}
void lcs(char s1[], char s2[], int s1size, int s2size){
	int arr[MAX][MAX];
	int pre[MAX][MAX];
	//test if the s1[i] s2[j] is same
	for(int i = 0; i <= s2size; i ++){
		for(int j = 0; j <= s1size; j ++){
			if(0 == i || 0 == j){
				arr[j][i] = 0;
				pre[j][i] = -100;
			}else{
				if(s1[j-1] == s2[i-1]){
					arr[j][i] = arr[j-1][i-1] + 1;
					pre[j][i] = LEFTUP;
	//				printf("s1[%d]:%c==s2[%d]:%c,arr[%d][%d]=%d\t",j-1,s1[j-1],i-1,s2[i-1],j,i, arr[j][i] );
				}else if(arr[j-1][i] > arr[j][i-1]){
					arr[j][i] = arr[j-1][i];
					pre[j][i] = UP;
				}else{
					arr[j][i] = arr[j][i-1];
					pre[j][i] = LEFT;
				}
			}
		}
	}
	printlcs(arr, pre, s1, s2, s1size, s2size);
	printf("add in lcs of arr = %p", arr);
	printf("add in lcs of pre = %p", pre);
	printf("the lcs[%d][%d] is %d\n", s1size, s2size,arr[s1size][s2size]);
}

void printlcs(int arr[][MAX],int pre[][MAX], char *s1, char *s2, int j, int i){
	printf("add of arr = %p", arr);
	int line = arr[j][i];
	printf("line = arr[%d][%d] is %d\n",j,i, line);
	char des[1+line];
	int count = line - 1;
	while(i > 0 && j > 0){
		printf("des[%d] = s1[%d]= %c\n", count,j-1, s1[j-1]);
		if(pre[j][i] == LEFTUP){
			des[count--] = s1[j-1];
			j --;
			i --;
		}
		else if(pre[j][i] == UP)
			j --;
		else if(pre[j][i] == LEFT)
			i --;
		else
			printf("pre[%d][%d] = %d\n", j, i, pre[j][i]);
	}
	des[line] = '\0';
	printf("des is %s\n" , des);
	
}
int main(){
	char s1[] = "ABCABCBA"; //the size inlude '\0'
	char s2[] = "CBABCABCC";
	lcs(s1, s2, CSIZE(s1), CSIZE(s2));
	return 0;
}
