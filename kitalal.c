#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabla[10][6];

int lehet_e(int kerd[4], int hol){
	int i, j, kett=0, egy=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(kerd[i]==tabla[hol][j] && i==j){
				kett++;
			} else if(kerd[i]==tabla[hol][j]){
				egy++;
			}
		}
	}
	if(egy==tabla[hol][4] && kett==tabla[hol][5]){
		return 1;
	} else{
		return 0;
	}
}

int main(){
	int i, j, k, tipp[4], jo=0, kap[4], ki=0, lepesszam=0, kev_kod[4], hova[4], megf_kod=0, jatek_vege=0, jatek_sorszam=0, jatek_tipus, max, hiba, kod[4], ad[4];
	srand((unsigned int) time(NULL));
	for(i=0;i<10;i++){
		tabla[i][4] = 0;
		tabla[i][5] = 0;
	}
while(jatek_vege==0){
	jatek_sorszam++;
	if(jatek_sorszam==1){
		printf("\n\232dv\224z\224llek a j\240t\202kban!\n\nMindig 4, sz\242k\224zzel elv\240lasztott sz\240mot \241rj\240l be!\n\ts\243g\242: 9 9 9 9\n\nA g\202p tal\240lja ki a Te k\242dodat (1), vagy Te tal\240lod ki az \224v\202t (2)?\nTe \241rd be azt az egy sz\240mot: ");
		scanf("%d", &jatek_tipus);
	} else{
		printf("\n\nA g\202p tal\240lja ki a Te k\242dodat (1), vagy Te tal\240lod ki az \224v\202t (2), vagy nem akarsz m\240r j\240tszani (0)?\nTe \241rd be azt az egy sz\240mot: ");
		scanf("%d", &jatek_tipus);
	}
	if(jatek_tipus==0){
		jatek_vege = 1;
		printf("\nSzia, rem\202lem j\242t j\240tszott\240l!\n\n");
	} else if(jatek_tipus!=0 && jatek_tipus!=1 && jatek_tipus!=2){
		printf("A 0, 1, 2 sz\240mok valamelyik\202t add meg: ");
		scanf("%d", &jatek_tipus);
		jatek_sorszam--;
	} else if(jatek_tipus==1){
		printf("%d. j\240t\202k:\n\tGondolj egy k\242dra, a g\202p kital\240lja!\n", jatek_sorszam);
	ki = 0;
	lepesszam = 0;
	for(i=0;i<10;i++){
		for(j=0;j<6;j++){
			tabla[i][j] = 0;
		}
	}
	while(ki==0 && lepesszam<10){
		printf("%d. ", lepesszam+1);
		if(lepesszam==0){//Első lépés
			while(jo==0){
				jo = 1;
				for(i=0;i<4;i++){
					tipp[i] = rand()%8;
				}
				for(i=0;i<4;i++){
					for(j=0;j<i;j++){
						if(tipp[i]==tipp[j]){
							jo = 0;
						}
					}
				}
			}
			for(i=0;i<4;i++){
				tabla[0][i] = tipp[i];
			}
			//printf("%d %d %d %d  ", tipp[0], tipp[1], tipp[2], tipp[3]);
		} else if(tabla[lepesszam-1][4]+tabla[lepesszam-1][5]==0){ //Csak 0-t kaptunk
			
			//Kód számainak megállapítása
			
			hova[0] = 0;
			for(i=0;i<8;i++){
				jo = 0;
				for(j=0;j<4;j++){
					if(i==tabla[lepesszam-1][j]){
						//printf("%d ", i);
						jo = 1;
					}
				}
				if(jo==0){
					//printf("\nKód keverve: %d", i);
					kev_kod[hova[0]] = i;
					//printf("(kev_kod[%d]=%d)", hova[0], i);
					hova[0]++;
				}
			}
			if(hova[0]!=4){printf("HIBA 75\n");}
			
			megf_kod = 0;
			while(megf_kod==0){
				
				//0-3 véletlen számok generálása
				
				jo = 0;
				hova[0] = rand()%4;
				while(jo==0){
					hova[1] = rand()%4;
					hova[2] = rand()%4;
					//printf("\n\t0-3 v\202l. számok: %d %d %d", hova[0], hova[1], hova[2]);
					if(hova[0]!=hova[1] && hova[2]!=hova[1] && hova[0]!=hova[2]){
						jo = 1;
					}
				}
				for(i=0;i<4;i++){
					jo = 0;
					for(j=0;j<3;j++){
						if(hova[j]==i){
							jo = 1;
						}
					}
					if(jo==0){
						hova[3] = i;
						//printf(" %d\n", hova[3]);
					}
				}
				
				//Kód megállapítása, ellenőrzése
				
				for(i=0;i<4;i++){
					//printf("\t%d\n", kev_kod[i]);
					tipp[hova[i]] = kev_kod[i];
					//printf("\ttipp[%d]:%d\n", hova[i], tipp[hova[i]]);
				}
				megf_kod = 1;
				for(i=0;i<lepesszam;i++){
					megf_kod = megf_kod*lehet_e(tipp, i);
				}
			}
			//printf("%d %d %d %d ", tipp[0], tipp[1], tipp[2], tipp[3]);
		} else if(tabla[lepesszam-1][4]+tabla[lepesszam-1][5]==4){ //Minden szám jó
			for(i=0;i<4;i++){
				kev_kod[i] = tabla[lepesszam-1][i];
			}
			megf_kod = 0;
			while(megf_kod==0){
				megf_kod = 1;
				
				//0-3 véletlen számok generálása
				
				jo = 0;
				hova[0] = rand()%4;
				while(jo==0){
					hova[1] = rand()%4;
					hova[2] = rand()%4;
					//printf("\n\t0-3 v\202l. számok: %d %d %d", hova[0], hova[1], hova[2]);
					if(hova[0]!=hova[1] && hova[2]!=hova[1] && hova[0]!=hova[2]){
						jo = 1;
					}
				}
				for(i=0;i<4;i++){
					jo = 0;
					for(j=0;j<3;j++){
						if(hova[j]==i){
							jo = 1;
						}
					}
					if(jo==0){
						hova[3] = i;
						//printf(" %d\n", hova[3]);
					}
				}
				
				//Kód megállapítása, ellenőrzése
				
				for(i=0;i<4;i++){
					//printf("\t%d\n", kev_kod[i]);
					tipp[hova[i]] = kev_kod[i];
					//printf("\ttipp[%d]:%d\n", hova[i], tipp[hova[i]]);
				}
				for(i=0;i<lepesszam;i++){
					megf_kod = megf_kod*lehet_e(tipp, i);
				}
			}
			//printf("%d %d %d %d ", tipp[0], tipp[1], tipp[2], tipp[3]);
		} else{ //A kapott értékek alapján nem állapítható meg a kód
			megf_kod = 0;
			while(megf_kod==0){
				megf_kod = 1;
				tipp[0]=rand()%8;
				jo = 0;
				while(jo==0){
					tipp[1] = rand()%8;
					tipp[2] = rand()%8;
					tipp[3] = rand()%8;
					jo = 1;
					for(i=0;i<4;i++){
						for(j=0;j<i;j++){
							if(tipp[i]==tipp[j]){
								jo = 0;
							}
						}
					}
				}
				//printf("%d %d %d %d \n", tipp[0], tipp[1], tipp[2], tipp[3]);
				for(i=0;i<lepesszam;i++){
					megf_kod = megf_kod*lehet_e(tipp, i);
				}
			}
		}
		
		//Végleges tipp kiírása, rögzítése
		
		printf("%d %d %d %d  - ", tipp[0], tipp[1], tipp[2], tipp[3]);
		for(i=0;i<4;i++){
			tabla[lepesszam][i] = tipp[i];
		}
		
		//Beolvasás
		
		scanf("%d %d %d %d", &kap[0], &kap[1], &kap[2], &kap[3]);
		if(kap[0]==9 && kap[1]==9 && kap[2]==9 && kap[3]==9){
			printf("\n\tS\243g\242:\n\tMindig 4 sz\242k\224zzel elv\240lasztott sz\240mot \241rj be!\n\tAz \202rt\202kel\202s a 0-2 sz\240mok k\224z\201l ker\201ljenek ki!\n\tA sz\240mok jelent\202se:\n\t\ta 0-s nem szerepl\223 sz\240mot,\n\t\taz 1-es megfelel\223 sz\240mot, de rossz helyen,\n\t\t2-es megfelel\223 sz\240mot j\242 helyen jelent.\n\tA tipp sorrendje fontos.\n");
			printf("%d. %d %d %d %d  - ", lepesszam+1, tipp[0], tipp[1], tipp[2], tipp[3]);
			scanf("%d %d %d %d", &kap[0], &kap[1], &kap[2], &kap[3]);
		} else if(kap[0]>2 || kap[1]>2 || kap[2]>2 || kap[3]>2){
			printf("Hib\240s \202rt\202kel\202s!\n");
			printf("%d. %d %d %d %d  - ", lepesszam+1, tipp[0], tipp[1], tipp[2], tipp[3]);
			scanf("%d %d %d %d", &kap[0], &kap[1], &kap[2], &kap[3]);
		}
		for(i=0;i<4;i++){
			if(kap[i]==1){
				tabla[lepesszam][4]++;
			} else if(kap[i]==2){
				tabla[lepesszam][5]++;
			}
		}
		if(tabla[lepesszam][5]==4){
			printf("\nA k\242d: %d %d %d %d. (%d l\202p\202s)\n", tipp[0], tipp[1], tipp[2], tipp[3], lepesszam+1);
			ki = 1;
		}
		lepesszam++;
	}
	} else if(jatek_tipus==2){
	jo = 0;
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
				if(tipp[j]<0 || tipp[j]==tipp[k] || tipp[j]>7){
					hiba = 1;
				}
			}
		}
		if(tipp[0]==9 && tipp[1]==9 && tipp[2]==9 && tipp[3]==9){
			printf("\n\tS\243g\242\n\tMindig 4 sz\242k\224zzel elv\240lasztott sz\240mot \241rj be!\n\tA tippjeid a 0-7 sz\240mok k\224z\201l ker\201ljenek ki!\n\tA ki\241rt\n\t\t0-s sz\240m hib\240s sz\240mot,\n\t\t1-es megfelel\223 sz\240mot, de rossz helyen,\n\t\t2-es megfelel\223 sz\240mot j\242 helyen jelent.\n\tAz eredm\202ny cs\224kken\223 sorrendben van ki\241rva.\n");
			i--;
		} else if(hiba==1){
			printf("Hib\240s k\242d!\n");
			i--;
		} else{
		
			//Értékelés
		
			if(tipp[0]==kod[0] && tipp[1]==kod[1] && tipp[2]==kod[2] && tipp[3]==kod[3]){
				jo = 1;
			}
			
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
		printf("Nem baj, majd legk\224zelebb.\n");
	} else if(i<5){
		printf("Nagyon \201gyes vagy!\n");
	} else if(i<10){
		printf("J\242l kital\240ltad!\n");
	}
	}
}
	return 0;
}
