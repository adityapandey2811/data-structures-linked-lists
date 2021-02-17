#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
int findLeader(int n, int k){
	if(n==0){
		return 0;
	}
	return (findLeader(n-1,k) + k)%n;
}
void main(){
	int i,k;
	//N people in circle
	printf("Enter n: ");
	scanf("%d",&i);	
	//Eliminate Kth person
	printf("Enter k: ");
	scanf("%d",&k);	
	i = findLeader(i,k);
	printf("%dth element lasted\n",++i);
}
