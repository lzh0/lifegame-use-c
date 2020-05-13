#include<stdio.h>
int he(int q);

int main(){
int d,l;
int i,j,x,y,index;
int	word[10][10]={0};
for(i=0;i<10;i++){
	for(j=0;j<10;j++){
		word[i][j]=he(j);
		printf("% d ",word[i][j]);
	}
	printf("\n");
}

for(;;){

for(i=0;i<10;i++){
	for(j=0;j<10;j++){
		word[i][j]=he(j);
		printf("% d ",word[i][j]);
	}
	printf("\n");
}







/*
	for(i=1;i<9;i++){
		for(j=1;j<9;j++){
			if(word[i][j]==0){printf("% d ",word[i][j]);}
					else{
						for(x=-1;x<2;x++){
							for(y=-1;y<2;y++){
								if(word[i+x][j+y]==1)d++;}
							}
							if (d>6)word[i][j]=0;
							printf(" %d ",word[i][j]);
						}
					}
						
	printf("\n");
		}*/
system("cls");	
}
return 0;
}	

int he(int q){
	if(rand(q)%11>5)return 1;
	else return 0;
}
