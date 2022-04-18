#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>   // 1.ADIM) gerekli kütüphaneleri tanýmladýk


#define boyut 10  // 2.ADIM) boyut adýnda bir deðiþken tanýmladýk
char dizi[boyut];   // 4.ADIM) ana elemanlarýmýzý ekleyelim
char stack[boyut];   //    ""
int ustnokta;

void push(char data){   // 5.ADIM) stack dolu mu boþ mu onu kontrol ediyoruz
	
	if(ustnokta +1 == boyut){ // ustnokta elemaný bir büyüðü boyuta eþitse stack dolu 
		puts("Stack içi doludur.");
	}else{
		stack[++ustnokta] = data;  // deðilse stack tepe elemanýný 1 artaracak ve boþ kýsma datayý eklicek
	}

}
                    // 6.ADIM) Fonksiyonlarýmýzý belirliyoruz
                    
                    
                    
char peek(){         // peek fonksiyonu en ustnoktadaki elemaný döndürecek
	return stack[ustnokta];
}

char pop(){          // ustnoktadaki elemaný çýkaracak
	return stack[--ustnokta];
}
                    // stack boþ mu dolu mu onu kontrol ediyoruz
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
	for(j=0;j <ustnokta;j++){      // tanýmladýðýmýz j ustnoktaya kadar dönmesi için j<ustnokta ifadesini kullanýyoruz
		printf("Stack : %c",stack[j]);
		
	}
	
}
                    
                    
                    
bool dogruMu(){   // ana fonksiyonumuzu yazýyoruz.yani stacke eleman ekleyecek , kýyaslayacak fonksiyon
	int i;
	while(dizi[i] != '\0'){  // ilk baþta kullanýcýnýn girdiði input kadar döngü oluþturmamýz lazým
		char d = dizi[i];
		printf("\ndata: %c",d);
		
		if(d=='(' || d=='{'|| d== '['){  // ( , { , [ karakterleri yakaladýðýmýzda stackýmýzý push edeceðiz
			push(d);
			printf("\npush edildi. %c",d);
		}
			
		else if (d==')' || d=='}' || d== ']'){   
		    char peekd = peek();
		    printf("Peed edildi: %c",peekd);
		    if(bosmu() == true){
			    puts("Stack boþtur ..!");
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


int main(int argc ,char *argv[]){    // 3.ADIM) koda baþlarken ilk olarak kullanýcýdan bir input aldýk adý dizi olsun
	
	setlocale(LC_ALL,"Turkish"); // türkçe karakter yazmasý için 
	
	puts("deðerlerini giriniz");
	fgets(dizi,sizeof(dizi),stdin);
	
if(dogruMu () == true){  
    puts("\ndoðru");
}else{
    puts("\nyanlýþ");
}
	return 0;
	
}







