// =====================================================
// SMART TRUCK SYSTEM
// 4 Ultrasonic Sensors + 4 LEDs + Bluetooth Alerts
// Stable Version
// =====================================================

#include <SoftwareSerial.h>

// =====================================================
// BLUETOOTH PINS
// A2 = RX
// A3 = TX
// =====================================================

SoftwareSerial BT(A2, A3);

// =====================================================
// SENSOR PINS
// =====================================================

// FRONT SENSOR
#define trigF 2
#define echoF 3

// REAR SENSOR
#define trigR 4
#define echoR 5

// LEFT SENSOR
#define trigL 6
#define echoL 7

// RIGHT SENSOR
#define trigRt 8
#define echoRt 9

// =====================================================
// LED PINS
// =====================================================

#define ledFront A4
#define ledLeft  A5
#define ledRight A0
#define ledRear  A1

// =====================================================
// SAFE DISTANCE FUNCTION
// =====================================================

long getDistance(int trig, int echo) {

  // Clear Trigger
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Send Trigger Pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read Echo with shorter timeout
  long duration = pulseIn(echo, HIGH, 10000);

  // No Echo Received
  if(duration <= 0)
    return 400;

  // Convert to Distance
  long distance = duration * 0.034 / 2;

  // Ignore fake tiny readings
  if(distance < 2)
    return 400;

  return distance;
}

// =====================================================
// SETUP
// =====================================================

void setup() {

  // Serial Monitor
  Serial.begin(9600);

  // Bluetooth
  BT.begin(9600);

  // FRONT SENSOR
  pinMode(trigF, OUTPUT);
  pinMode(echoF, INPUT);

  // REAR SENSOR
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);

  // LEFT SENSOR
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);

  // RIGHT SENSOR
  pinMode(trigRt, OUTPUT);
  pinMode(echoRt, INPUT);

  // LED PINS
  pinMode(ledFront, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledRear, OUTPUT);

  Serial.println("SMART TRUCK SYSTEM STARTED");

  BT.println("SMART TRUCK SYSTEM CONNECTED");
}

// =====================================================
// LOOP
// =====================================================

void loop() {

  // =====================================================
  // READ SENSOR VALUES
  // =====================================================

  long dF = getDistance(trigF, echoF);
  delay(60);

  long dR = getDistance(trigR, echoR);
  delay(60);

  long dL = getDistance(trigL, echoL);
  delay(60);

  long dRt = getDistance(trigRt, echoRt);
  delay(60);

  // =====================================================
  // LED CONTROL
  // =====================================================

  digitalWrite(ledFront, dF < 40 ? HIGH : LOW);

  digitalWrite(ledRear, dR < 40 ? HIGH : LOW);

  digitalWrite(ledLeft, dL < 40 ? HIGH : LOW);

  digitalWrite(ledRight, dRt < 40 ? HIGH : LOW);

  // =====================================================
  // SERIAL MONITOR OUTPUT
  // =====================================================

  Serial.print("Front:");
  Serial.print(dF);

  Serial.print(" Rear:");
  Serial.print(dR);

  Serial.print(" Left:");
  Serial.print(dL);

  Serial.print(" Right:");
  Serial.println(dRt);

  // =====================================================
  // BLUETOOTH DISTANCE OUTPUT
  // =====================================================

  BT.print("Front:");
  BT.print(dF);

  BT.print(" Rear:");
  BT.print(dR);

  BT.print(" Left:");
  BT.print(dL);

  BT.print(" Right:");
  BT.println(dRt);

  // =====================================================
  // BLUETOOTH ALERTS
  // =====================================================

  if(dF < 40) {
    BT.println("ALERT: FRONT OBSTACLE");
  }

  if(dR < 40) {
    BT.println("ALERT: REAR OBSTACLE");
  }

  if(dL < 40) {
    BT.println("ALERT: LEFT OBSTACLE");
  }

  if(dRt < 40) {
    BT.println("ALERT: RIGHT OBSTACLE");
  }

  BT.println("--------------------------");

  delay(100);
}