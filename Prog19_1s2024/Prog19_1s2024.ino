/* 
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP. 
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd1(0x20,16,2);
LiquidCrystal_I2C lcd2(0x21,16,2);
LiquidCrystal_I2C lcd3(0x22,16,2);

int contador1 = 0, contador2 = 0, contador3 = 0;

void setup() {
  
   lcd1.init();
   lcd2.init();
   lcd3.init();
  
   lcd1.clear();  
   lcd2.clear();  
   lcd3.clear();
  
   lcd1.setBacklight(1);
   lcd2.setBacklight(1);
   lcd3.setBacklight(1);
  
   lcd1.setCursor(0,0);
   lcd1.print("#   Display    #");
   lcd1.setCursor(0,1);   
   lcd1.print("#    LCD 1     #");

   delay(1000);

   lcd2.setCursor(0,0);
   lcd2.print("#   Display    #");
   lcd2.setCursor(0,1);   
   lcd2.print("#    LCD 2     #");

   delay(1000);  

   lcd3.setCursor(0,0);
   lcd3.print("#   Display    #");
   lcd3.setCursor(0,1);   
   lcd3.print("#    LCD 3     #");
    
   delay(2000);
  
   lcd1.clear();  
   lcd2.clear();  
   lcd3.clear();  
   
}

void loop() {
  
   contador1 = contador1 + 1;
   contador2 = contador2 + 1;
   contador3 = contador3 + 1;
         
   lcd1.setCursor(0,0);
   lcd1.print("Contador LCD 1: ");
   lcd1.setCursor(0,1);         
   lcd1.print(contador1);   

   lcd2.setCursor(0,0);
   lcd2.print("Contador LCD 2: ");
   lcd2.setCursor(0,1);         
   lcd2.print(contador2);  
  
   lcd3.setCursor(0,0);
   lcd3.print("Contador LCD 3: ");
   lcd3.setCursor(0,1);         
   lcd3.print(contador3);  
          
}