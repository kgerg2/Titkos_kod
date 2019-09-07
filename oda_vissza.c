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

int main(){//Átlag: 4,839.
	int i, j, k, l, tipp[4], jo=0, kap[4], ki=0, lepesszam=0, kev_kod[4], hova[4], megf_kod=0, ad[4], kod[4], max, sok=10000, osszlepes=0, osszlep[8], maxlepes=0, maxdb=0, minlepes=10, mindb=0;
	srand((unsigned int) time(NULL));
	for(i=0;i<8;i++){
		osszlep[i] = 0;
	}
	
	
	for(l=0;l<sok;l++){
	jo = 0;
	ki = 0;
	lepesszam = 0;
	megf_kod = 0;
	for(i=0;i<10;i++){
		tabla[i][4] = 0;
		tabla[i][5] = 0;
	}
	
	
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
	for(i=0;i<4;i++){
		//printf("%d\n", kod[i]);
	}
	while(ki==0 && lepesszam<10){
		//printf("\n%d. ", lepesszam+1);
		if(lepesszam==0){//Első lépés
			jo = 0;
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
		} else if(tabla[lepesszam-1][4]+tabla[lepesszam-1][5]==0){//Csak 0-t kaptunk
			//printf("Csak 0-t kaptam.\n");
			
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
					//printf("\n\t0-3 vél. számok: %d %d %d", hova[0], hova[1], hova[2]);
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
				//printf("%d - megf\n", megf_kod);
				//scanf("%d", &semmi);
			}
			//printf("%d %d %d %d ", tipp[0], tipp[1], tipp[2], tipp[3]);
		} else if(tabla[lepesszam-1][4]+tabla[lepesszam-1][5]==4){
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
					//printf("\n\t0-3 vél. számok: %d %d %d", hova[0], hova[1], hova[2]);
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
		} else{
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
		
		//printf("%d %d %d %d  - ", tipp[0], tipp[1], tipp[2], tipp[3]);
		for(i=0;i<4;i++){
			tabla[lepesszam][i] = tipp[i];
		}
		
		//Beolvasás
		
		if(tipp[0]==kod[0] && tipp[1]==kod[1] && tipp[2]==kod[2] && tipp[3]==kod[3]){
			kap[0] = 2;
			kap[1] = 2;
			kap[2] = 2;
			kap[3] = 2;
		} else{
			for(i=0;i<4;i++){
				ad[i] = 0;
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
			for(j=0;j<4;j++){
				max = 0;
				for(k=0;k<4;k++){
					if(ad[k]>ad[max]){
						max = k;
					}
				}
				kap[j] = ad[max];
				//printf("%d ", ad[max]);
				ad[max] = 0;
			}
		}
		//scanf("%d %d %d %d", &kap[0], &kap[1], &kap[2], &kap[3]);
		for(i=0;i<4;i++){
			if(kap[i]==1){
				tabla[lepesszam][4]++;
			} else if(kap[i]==2){
				tabla[lepesszam][5]++;
			}
		}
		if(tabla[lepesszam][5]==4){
			//printf("A kód: %d %d %d %d. (%d lépés)\n", tipp[0], tipp[1], tipp[2], tipp[3], lepesszam+1);
			ki = 1;
			osszlepes = osszlepes+lepesszam+1;
			if(maxlepes<lepesszam){
				maxlepes = lepesszam;
				maxdb = 1;
			} else if(maxlepes==lepesszam){
				maxdb++;
			}
			if(minlepes>lepesszam){
				minlepes = lepesszam;
				mindb = 1;
			} else if(minlepes==lepesszam){
				mindb++;
			}
			for(i=1;i<8;i++){
				if(lepesszam==i){
					osszlep[i-1]++;
				}
			}
		}
		lepesszam++;
	}
	}
	printf("\n%d játékból:\n\nÖsszes lépés: %d\n\nÁtlagos lépésszám: %f\n\nMaximális lépésszám: %d (%d db)\n\nMinimális lépésszám: %d (%d db)\n", sok, osszlepes, (double)osszlepes/(double)sok, maxlepes, maxdb, minlepes, mindb);
	
	return 0;
}
