#include <Wire.h>

#define DEBUG 1
#define I2C_ADDRESS 24
#define MASTERSEQMAX 2
byte SW_LED_SEQ [MASTERSEQMAX]={};
byte SW_I2C_MASTER [2] = {};

static int deciSeconds = 0;
static unsigned long timer = 0;

int messageSize = 0;
int i2c_action = 0;

void setup() {
  
  Serial.begin(115200);           // start serial for output

  Wire.begin(I2C_ADDRESS);                // join i2c bus with address #8
  Wire.setWireTimeout(5000, true); //concider wire transmission as timeout if communication is longer thant 5s
  Wire.clearWireTimeoutFlag();
  Wire.onReceive(receiveEvent); // register event

  Serial.println(F("Ecto-1 Extension System Started"));
  Serial.print(F("I2C device Listening at address "));
  /* prety output to get the Hexadecimal value of the slave component*/
  if (I2C_ADDRESS < 16)
  {
    Serial.print(F("0x0"));
  }
  else
  {
    Serial.print(F("0x"));
  }
  Serial.println(I2C_ADDRESS, HEX);
  Serial.println(F("Waiting Communication from Master..."));
  

}

void loop() {

  getI2CMessage();
  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  int i=0;
  while(0 < Wire.available())       
  {
    SW_I2C_MASTER[i] = Wire.read();//get message sent from master       
    i++; 
  }
  
  messageSize=howMany;
}

int getI2CMessage()
{
  int i2c_received = 0;
  
  if(messageSize)//check if message as been sent
  {
    #ifdef DEBUG
      Serial.print(F("I2C Master Action : "));
      for(int i=0;i<messageSize;i++)
      {      
        Serial.print(SW_I2C_MASTER[i]);
        if(i<messageSize-1)
          Serial.print(","); //get infos sent from master
      }
      Serial.println();
    #endif
    i2c_received=(int)SW_I2C_MASTER[0];
    i2c_action = (int)SW_I2C_MASTER[1];
    messageSize=0;
  }

  return i2c_received;
}
