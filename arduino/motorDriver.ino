#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
//
// Connections to make:
//   Arduino TX->1  ->  Sabertooth S1
//   Arduino GND    ->  Sabertooth 0V
//   Arduino VIN    ->  Sabertooth 5V
//
SoftwareSerial mySerial(13, 12); // RX, TX
SabertoothSimplified ST;
char cmd = 'n';
int pw = 0;
int cnt = 0;
String str;

void setup() {
//  Serial.begin(9600); // ハードウェアシリアルを準備
  SabertoothTXPinSerial.begin(9600);
  // This is the baud rate you chose with the DIP switches.
  ST.drive(0); // The Sabertooth won't act on mixed mode until
  ST.turn(0);  // it has received power levels for BOTH throttle and turning, since it
  // mixes the two together to get diff-drive power levels for both motors.
  // So, we set both to zero initially.

  //  Serial.println("Ready");
  mySerial.begin(115200); // ソフトウェアシリアルの初期化
//  mySerial.println("#V:");
}

void loop() {
  if (mySerial.available()) {
    cmd = mySerial.read();
    //    Serial.write(cmd);
    if (cmd == 'F' ) {
      //      Serial.write("Forward");
      ST.drive(pw);  // Go forward at full power.
      delay(20);         // Wait 20 mili-seconds.
      ST.turn(0);    // Stop.

    } else if ( cmd == 'B' ) {
      //      Serial.write("Back");
      ST.drive(-pw); // Reverse at full power.
      delay(20);         // Wait 20 mili-seconds.
      ST.turn(0);    // Stop.

    } else if ( cmd == 'S' ) {
      //      Serial.write("Stop!");
      cnt = 0;
      pw = 0;

      ST.turn(0);    // Stop.
      ST.drive(0);         // Wait 20 mili-seconds.

    } else if ( cmd == 'G' ) {
      //      Serial.write("Stop!");
      cnt = cnt + 1;
      if (cnt == 5 ) {
        cnt = 4;
      }
//      str = String("#"+String(cnt)+":");
//      mySerial.println(str);
      pw = 32 * cnt - 1;

      ST.drive(0);
      ST.turn(0);    // Stop.

    } else if ( cmd == 'R' ) {
      //      Serial.write("Right");
      ST.drive(0);
      ST.turn(pw);

    } else if ( cmd == 'L' ) {
      //     Serial.write("Left");
      ST.drive(0);
      ST.turn(-pw);

    } else {
      //
    }
  }
  //  if (Serial.available()) {
  //    mySerial.write("#Hello!:");
  //  }
}
