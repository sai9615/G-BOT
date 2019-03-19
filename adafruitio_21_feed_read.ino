
/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

// the Adafruit IO username of whomever owns the feed
#define FEED_OWNER "Poojyak"



#define ENB D5      //ENB
#define MOTORB_1 D6 //IN3
#define MOTORB_2 D7 //IN4
#define MOTORA_1 D9 //IN1
#define MOTORA_2 D8 //IN2
#define ENA D4      //ENA

// set up the `sharedFeed`
AdafruitIO_Feed *sharedFeed = io.feed("voice-commands", FEED_OWNER);

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);

  // disable both motors
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'sharedFeed' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  sharedFeed->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  sharedFeed->get();

  

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

}

// this function is called whenever an 'sharedFeed' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

//  Serial.print("received <-  ");
//  Serial.println(data->toInt());
  String commandStr = data->toString();
  Serial.print("received <- ");
  Serial.println(commandStr);

 String cmd;
  int angle;

  // separate text and number ingredients
  for (int i = 0; i < commandStr.length(); i++) {
    if (commandStr.substring(i, i+1) == ":") {
      cmd = commandStr.substring(0, i);
      angle = commandStr.substring(i+1).toInt();
      break;
    }
  }

   // print command
  Serial.println(cmd);
  Serial.println(angle);

  // perform movements
  // LEFT
  if (cmd.equalsIgnoreCase("left")){    
    Serial.println("Turning left");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);  
     } 
  // RIGHT
  if (cmd.equalsIgnoreCase("right")){    
    Serial.println("Turning right");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW); 
  }
  // FORWARD
  if (cmd.equalsIgnoreCase("forward")){    
    Serial.println("Moving forward");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW); 
  }
  // Stop
  if (cmd.equalsIgnoreCase("stop")){    
    Serial.println("stopping");
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW); 
  }
  
}
