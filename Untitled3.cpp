#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>   // 1.ADIM) gerekli k�t�phaneleri tan�mlad�k


#define boyut 10  // 2.ADIM) boyut ad�nda bir de�i�ken tan�mlad�k
char dizi[boyut];   // 4.ADIM) ana elemanlar�m�z� ekleyelim
char stack[boyut];   //    ""
int ustnokta;

void push(char data){   // 5.ADIM) stack dolu mu bo� mu onu kontrol ediyoruz
	
	if(ustnokta +1 == boyut){ // ustnokta eleman� bir b�y��� boyuta e�itse stack dolu 
		puts("Stack i�i doludur.");
	}else{
		stack[++ustnokta] = data;  // de�ilse stack tepe eleman�n� 1 artaracak ve bo� k�sma datay� eklicek
	}

}
                    // 6.ADIM) Fonksiyonlar�m�z� belirliyoruz
                    
                    
                    
char peek(){         // peek fonksiyonu en ustnoktadaki eleman� d�nd�recek
	return stack[ustnokta];
}

char pop(){          // ustnoktadaki eleman� ��karacak
	return stack[--ustnokta];
}
                    // stack bo� mu dolu mu onu kontrol ediyoruz
bool bosmu(){
	if(ustnokta == 0){
		return true;
	}else{
		return false;
	}
	
}

                                     //  7.ADIM) yazdir fonksiyonuyla
void yazdir(){     
	int j;
	for(j=0;j <ustnokta;j++){      // tan�mlad���m�z j ustnoktaya kadar d�nmesi i�in j<ustnokta ifadesini kullan�yoruz
		printf("Stack : %c",stack[j]);
		
	}
	
}
                    
                    
                    
bool dogruMu(){   // ana fonksiyonumuzu yaz�yoruz.yani stacke eleman ekleyecek , k�yaslayacak fonksiyon
	int i;
	while(dizi[i] != '\0'){  // ilk ba�ta kullan�c�n�n girdi�i input kadar d�ng� olu�turmam�z laz�m
		char d = dizi[i];
		printf("\ndata: %c",d);
		
		if(d=='(' || d=='{'|| d== '['){  // ( , { , [ karakterleri yakalad���m�zda stack�m�z� push edece�iz
			push(d);
			printf("\npush edildi. %c",d);
		}
			
		else if (d==')' || d=='}' || d== ']'){   
		    char peekd = peek();
		    printf("Peed edildi: %c",peekd);
		    if(bosmu() == true){
			    puts("Stack bo�tur ..!");
		       	return false;
	     	}
		
	    
		
		if(d ==')' && peekd=='('){
			pop();
		}
		    if(d == '}' && peekd=='{'){
		    pop();
		}
		
		    if(d ==']' && peekd=='['){
		    pop();
		}else{
		    return false;
			}
	}
	i+=1;
}
  return bosmu();
}


int main(int argc ,char *argv[]){    // 3.ADIM) koda ba�larken ilk olarak kullan�c�dan bir input ald�k ad� dizi olsun
	
	setlocale(LC_ALL,"Turkish"); // t�rk�e karakter yazmas� i�in 
	
	puts("de�erlerini giriniz");
	fgets(dizi,sizeof(dizi),stdin);
	
if(dogruMu () == true){  
    puts("\ndo�ru");
}else{
    puts("\nyanl��");
}
	return 0;
	
}







