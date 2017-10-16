/*When the alcohol molecules in the air meet the electrode that is between alumina and tin dioxide,
ethanol burns into acetic acid then more current is produced. So the more alcohol molecules there are, 
the more current we will get. Because of this current change, we get the different values from the sensor.*/

/* Weakness in the design of the sensor include that moisture in breath can cause a reading by acting as a buffer between the cathode and anode. The sensor also needs a warmup period, tentatively 20 seconds
 *  after this period an initial reading is taken and compared against new readings every 3 seconds. If the reading does not change(no one breathes in) then the return should be a BAC of 0.00%. Sensitivity can be altered by the screw on the sensor.
 *  The sensor has a heater next to the measuring electrode which provides "necessary conditions" for work of the components. 

*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define BACKLIGHT_PIN  3 
#define En_pin  2 
#define Rw_pin  1 
#define Rs_pin  0 
#define D4_pin  4 
#define D5_pin  5 
#define D6_pin  6 
#define D7_pin  7 



LiquidCrystal_I2C lcd1(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

const int switchP=2;               //button
float original;
float result;
bool state = false;

void setup() {

  Serial.begin(9600);  
  pinMode(switchP, INPUT_PULLUP);                               //configure button for input
  pinMode(5, INPUT);
  pinMode(A0, INPUT);                                      //sets the pin as an input to the arduino
  lcd1.begin(16,2);                                        // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd1.clear();
  lcd1.setCursor(0,0);                                     //print welcome message
  lcd1.print("BAC Measure");
  delay(2000);

  int start=millis();
  int count=millis();
  
  lcd1.clear();
  lcd1.print("Warming Up ");
  lcd1.setCursor(0,1);
  lcd1.print("Sensor...");
  
  while((count-start)<20000){             //this is used as a warmup period while the heater adjusts to get a more accurate reading.                
  count=millis();
  }
  original=analogRead(0);                //original will hold the baseline reading (0.00%BAC) against which all other readings in loop will be compared.
}  



void loop() {

 lcd1.clear();
lcd1.print(original);                                 //prints original reading and new value, used for testing
lcd1.setCursor(0,1);
lcd1.print(analogRead(0));
delay(2000);
lcd1.clear();
 //int limit= digitalRead(0);                          //reads the digital value from the alcohol sensor's DOUT pin, can be used to read when there is a high reading
//
//
//
// state= digitalRead(switchP);
//
//  if(state==false){                                    //press the button to get a BAC reading
//    float sensorReading = analogRead(0);
//    result =abs(original-sensorReading);
//
//
//     if(result<75){
//      result=.01;
//     }
//     else if(result<150){
//      result=.02;
//     }
//     else if(result<250){
//      result=.03;
//     }
//     else if(result<325){
//      result=.04;
//     }
//     else if(result<450){
//      result=.05;
//     }
//     else if(result<525){
//      result=.06;
//     }
//     else if(result<600){
//      result=.07;
//     }
//     else if(result<700){
//      result=.08;
//     }
//     else if(result<800){
//      result=.09;
//     }
//     else{
//      result=1;
//     }
//
//          if(result==1){
//           lcd1.print("You're waaay too drunk");
//          }
//            else
//             {
//                          
//              lcd1.print(result); 
//              lcd1.print(" %");
//              delay(3000);
//             }
// }
 
  
}
