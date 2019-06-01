#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
   double alpha=0.75;
   int period=20;
   double refresh=0.0;   
void setup(void)
{
   pinMode(A0,INPUT);
   lcd.begin(16,2);
   lcd.clear();
   lcd.setCursor(0,0);
}
void loop(void)
{
   static double oldValue=0;
   static double oldrefresh=0; 
   int beat=analogRead(A0);  
   double value=alpha*oldValue+(0-alpha)*beat;
   refresh=value-oldValue;     
   lcd.setCursor(0,0);
   lcd.print(" Heart Monitor "); 
   lcd.setCursor(0,1);
   lcd.print("          ");
   lcd.setCursor(0,1); 
   lcd.print(beat/10);
   oldValue=value;
   oldrefresh=refresh;
   delay(period*10);  
}
