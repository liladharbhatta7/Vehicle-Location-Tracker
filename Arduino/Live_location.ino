#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// WiFi credentials
const char* ssid = "sulakshya_5";
const char* password = "CLB27F9396";

// Firebase configuration
FirebaseData firebaseData; // Firebase data object
FirebaseConfig firebaseConfig; // Firebase configuration object
FirebaseAuth firebaseAuth; // Firebase authentication object

void setup() {
  Serial.begin(115200); // Debugging console

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // Firebase configuration
  firebaseConfig.host = ""; // Firebase URL
  firebaseConfig.api_key = ""; // Replace with your API key from Firebase Console

  // Sign in anonymously
  if (Firebase.signUp(&firebaseConfig, &firebaseAuth, "", "")) {
    Serial.println("Firebase authentication succeeded.");
  } else {
    Serial.printf("Firebase authentication failed: %s\n", firebaseConfig.signer.signupError.message.c_str());
  }

  // Initialize Firebase
  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Serial.println("Firebase initialized!");
}

void loop() {
  // Predefined values for testing
  float testLatitude = 50.700769;  // Replace with actual latitude
  float testLongitude = 45.300140; // Replace with actual longitude

  // Send latitude and longitude to Firebase
  if (Firebase.RTDB.setFloat(&firebaseData, "/gps/latitude", testLatitude)) {
    Serial.println("Latitude sent successfully.");
  } else {
    Serial.printf("Failed to send latitude: %s\n", firebaseData.errorReason().c_str());
  }

  if (Firebase.RTDB.setFloat(&firebaseData, "/gps/longitude", testLongitude)) {
    Serial.println("Longitude sent successfully.");
  } else {
    Serial.printf("Failed to send longitude: %s\n", firebaseData.errorReason().c_str());
  }

  // Add a delay to prevent flooding Firebase with requests
  delay(5000); // Send updates every 5 seconds
}
