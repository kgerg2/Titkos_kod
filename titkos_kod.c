#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, j, k, kod[4], tipp[4], jo=0, ad[4], max, hiba;
	srand((unsigned int) time(NULL));
	kod[0]=rand()%8;
	while(jo==0){
		kod[1] = rand()%8;
		kod[2] = rand()%8;
		kod[3] = rand()%8;
		jo = 1;
		for(i=0;i<4;i++){
			for(j=0;j<i;j++){
				if(kod[i]==kod[j]){
					jo = 0;
				}
			}
		}
	}
	/*for(i=0;i<4;i++){
		printf("%d\n", kod[i]);
	}*/
	i = 0;
	jo = 0;
	while(jo==0 && i<10){
		i++;
		printf("%d. ", i);
		scanf("%d %d %d %d", &tipp[0], &tipp[1], &tipp[2], &tipp[3]);
		
		//Kapott érték ellenőrzése
		
		hiba = 0;
		for(j=0;j<4;j++){
			for(k=0;k<j;k++){
				if(tipp[j]<0 || tipp[j]>7 || tipp[j]==tipp[k]){
					hiba = 1;
				}
			}
		}
		if(hiba==1){
			printf("Hibás kód!\n");
			i--;
		} else{
		
			//Értékelés
		
			if(tipp[0]==kod[0] && tipp[1]==kod[1] && tipp[2]==kod[2] && tipp[3]==kod[3]){
				jo = 1;
			}
			/*if(tipp[0]==9){printf("1: %d ", kod[0]);}
			if(tipp[1]==9){printf("2: %d ", kod[1]);}
			if(tipp[2]==9){printf("3: %d ", kod[2]);}
			if(tipp[3]==9){printf("4: %d ", kod[3]);}*/
			for(j=0;j<4;j++){
				ad[j] = 0;
			}
			for(j=0;j<4;j++){
				if(tipp[j]==kod[j]){
					ad[j] = 2;
				} else{
					for(k=0;k<4;k++){
						if(tipp[j]==kod[k] && j!=k){
							ad[j] = 1;
						}
					}
				}
			}
			printf("           ");
			for(j=0;j<4;j++){
				max = 0;
				for(k=0;k<4;k++){
					if(ad[k]>ad[max]){
						max = k;
					}
				}
				printf("%d ", ad[max]);
				ad[max] = 0;
			}
			printf("\n");
		}
	}
	if(i==10){
		printf("Nem baj, majd legközelebb.\n");
	} else if(i<5){
		printf("Nagyon ügyes vagy!\n");
	} else if(i<10){
		printf("Jól kitaláltad!\n");
	}
	return 0;
}
