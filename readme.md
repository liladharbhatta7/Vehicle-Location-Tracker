**EcoNova Smart Waste Collection System**

A comprehensive IoT-enabled solution for real-time waste vehicle tracking and smart waste bin monitoring. Powered by Arduino, Firebase Realtime Database, and the Google Maps JavaScript API, this project enables municipalities and waste management companies to optimize collection routes, monitor bin fill levels, and analyze historical data.

---

## 🚀 Features

* **Live Vehicle Tracking**: Display real-time GPS location of waste collection vehicles on a Google Map.
* **Historical Routes**: View past trajectories and collection history for performance analysis.
* **Dustbin Fill Monitoring**: Detect and list bins that have reached full capacity.
* **Responsive Web Interface**: Mobile-friendly UI styled with modern neumorphic design elements.
* **Arduino Integration**: Collect GPS coordinates and ultrasonic sensor readings via an Arduino microcontroller.

---

## 🖥️ Web Interface

### Home Dashboard (`index.html`)

The main landing page built with HTML, CSS, and Font Awesome icons. It provides quick access to core features:

```html
<div class="container">
  <div class="logo">EcoNova</div>
  <h1>Smart Waste Collection</h1>
  <p>Track Waste Vehicle</p>
  <div class="buttons">
    <button class="button"><i class="fas fa-history"></i> Show History</button>
    <a href="index.html"><button class="button secondary"><i class="fas fa-map-marker-alt"></i> Track Location</button></a>
    <a href="dustbin_filled.html"><button class="button"><i class="fas fa-trash-alt"></i> Show Filled Dustbin</button></a>
  </div>
</div>
```

* **Neumorphic Design**: Soft shadows, pastel gradients, and rounded elements.
* **Responsive Layout**: Adapts gracefully to desktop and mobile viewports.

### Live Location Map (`map.html`)

Embeds a full-screen Google Map and updates vehicle position in real time via Firebase:

```html
<script src="https://maps.googleapis.com/maps/api/js?key=YOUR_API_KEY&callback=initMap" async defer></script>
<div id="map"></div>
<script type="module">
  import { initializeApp } from "https://www.gstatic.com/firebasejs/11.2.0/firebase-app.js";
  import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/11.2.0/firebase-database.js";
  
  // Firebase configuration
  const firebaseConfig = { /* your credentials */ };
  const app = initializeApp(firebaseConfig);
  const db = getDatabase(app);

  function initMap(lat = 27.7172, lng = 85.3240) {
    // initialize Google Map and marker
  }

  // Listen for updates and reposition marker
  onValue(ref(db, "location"), snapshot => { /* ... */ });
</script>
```

---

## 📁 Project Structure

```text
project-root/
├── web/
│   ├── index.html          # Dashboard UI
│   ├── map.html            # Live location map
│   ├── dustbin_filled.html # Filled bins list
│   ├── css/                # Custom stylesheets
│   └── js/                 # Frontend scripts
│
├── arduino/
│   ├── GPS_Ultrasonic.ino  # Arduino sketch for GPS + sensor data
│   └── libraries/          # Required Arduino libraries
│
├── firebase/
│   └── rules.json         # Security rules for Realtime Database
│
└── README.md               # Project overview & setup guide
```

---

## 🔧 Hardware Setup

| Component         | Model / Spec       | Purpose                            |
| ----------------- | ------------------ | ---------------------------------- |
| Arduino UNO       | Rev3               | Main microcontroller               |
| GPS Module        | NEO-6M             | Provides latitude & longitude      |
| Ultrasonic Sensor | HC-SR04            | Measures dustbin fill level        |
| Wi-Fi Module      | ESP8266 (optional) | Sends data to Firebase             |
| Power Supply      | 5V / 9V adapter    | Powers the Arduino and peripherals |

1. **Connect GPS**: UART TX/RX pins to Arduino.
2. **Mount Ultrasonic**: Trigger & Echo pins to digital I/O.
3. **Network**: (Optional) Use ESP8266 to post sensor data.
4. **Upload Sketch**: Configure Wi-Fi and Firebase credentials in `GPS_Ultrasonic.ino`.

---

## ⚙️ Arduino Sketch Configuration

Open `arduino/GPS_Ultrasonic.ino` and update the following constants:

```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* db_url   = "https://your-app.firebaseio.com/";
```

Then, upload the sketch to your Arduino board.

---

## 🔐 Firebase Realtime Database

1. Create a project on the [Firebase Console](https://console.firebase.google.com/).
2. Enable Realtime Database and set region to Asia Southeast.
3. Copy your project credentials into `map.html` and `GPS_Ultrasonic.ino`.
4. Use the provided `firebase/rules.json` to enforce basic read/write security.

---

## 🚀 Usage

1. **Launch Web Server**: Serve the `web` directory using any static server (e.g., `npx serve web`).
2. **Monitor Vehicle**: Navigate to `localhost:5000/map.html` to view the live position.
3. **View History**: Click **Show History** on the dashboard to browse past routes.
4. **Check Bins**: Click **Show Filled Dustbin** to list bins needing service.

---

## 🤝 Contributing

Contributions are welcome! Feel free to open issues and submit pull requests for:

* Improved UI/UX
* Additional sensor integrations
* Data analytics dashboards

---

## 📝 License

This project is licensed under the MIT License.

---

<p align="center">Made with ❤️ by EcoNova</p>
