/*
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

void menu() {

   Serial.println("      Portas Analogicas      ");
   Serial.println("-----------------------------");
   Serial.println("0. Porta Analogica A0.");  
   Serial.println("1. Porta Analogica A1.");
   Serial.println("2. Porta Analogica A2.");
   Serial.println("3. Porta Analogica A3.");
   Serial.println("-----------------------------");
   Serial.println("Sua escolha: ??");
   Serial.println("");
   Serial.println("");
   Serial.println("");
  
}

void setup() {

   Serial.begin(9600);
   menu();
}

void loop() {

   while (Serial.available() > 0) {

     int opcao = Serial.parseInt();

     Serial.println("-------------------------------------------");
     switch(opcao) {
       case 0:
       	     Serial.print("A0 = ");
       	     Serial.print(analogRead(A0));
             Serial.println("");        
             break;       
       case 1:
       	     Serial.print("A1 = ");
       	     Serial.print(analogRead(A1));
             Serial.println(""); 
             break; 
       case 2:
       	     Serial.print("A2 = ");
       	     Serial.print(analogRead(A2));
             Serial.println(""); 
             break; 
       case 3:
       	     Serial.print("A3 = ");
       	     Serial.print(analogRead(A3));
             Serial.println("");        
             break;                     
       default:
             Serial.println("Voce escolheu uma opcao nao disponivel.");
    }
    Serial.println("-------------------------------------------");
    delay(3000);
    Serial.println("");
    Serial.println("");
    Serial.println("");
    menu();

  }
}