#include<stdio.h>
#include<string.h>
#define MAX 50
void reverse(char* sentence, int head, int end){
	char temp;
	while(head < end){
		temp = sentence[end];
		sentence[end] = sentence[head];
		sentence[head] = temp;
		head++;
		end--;
	}
	printf("head = %d, end = %d, sentence is  %s\n",head, end, sentence);
}

int main(){
	printf("input a sentence\n");
	char sen[50];
	int i = 0;
	int j = 0; 
	int record = 0;
	char ch;
	while((ch = getchar()) != '\n'){
		sen[i] = ch;
		i++;
	}
	sen[i] = '\0';
	printf("sentence is  %s\n", sen);
	do{
		//printf("sen[%d] = %c\n",j, sen[j]);
		if(sen[j] == ' ' || sen[j] == '\0'){
			//printf("before input, head = %d, end = %d ", record, j-1);
			reverse(sen, record, j-1);
			//printf("sen is %s, head = %d, end = %d, sen[head] = %c, sen[end] = %c\n", sen, record, j-1, sen[record], sen[j-1]);
			record = j+1;
		}
		j;
	}while(sen[j++] != '\0' ); 
	j--;	//minus the one more plus in last while
	printf("j = %d, senlen = %d, sen[j-1] = %c", j, strlen(sen), sen[j-1]);
	reverse(sen, 0, j-1);
	printf("output sentence is %s\n", sen);
	return 0;
}
